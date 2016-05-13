# -*- coding: utf-8 -*- 
import os
import sys
import xlrd
import inspect
import shutil
from google.protobuf import text_format
from google.protobuf.descriptor import FieldDescriptor

# dir
PB_DIR = './PROTO'
PB_PY_DIR = './PYTHON'
XLS_DIR = './XLS'
BIN_DIR = './BIN'

# 

### helper function
def class_from_string(class_name):
	try:
		instance = getattr(sys.modules[__name__], class_name)()
		return instance
	except:
		return None

def make_descriptor_name(class_name):
	return '_' + class_name.upper()

'''
TYPE_DOUBLE = 1 	TYPE_FLOAT = 2 		TYPE_INT64 = 3
TYPE_UINT64 = 4		TYPE_INT32 = 5		TYPE_FIXED64 = 6
TYPE_FIXED32 = 7	TYPE_BOOL = 8 		TYPE_STRING = 9
TYPE_GROUP = 10 	TYPE_MESSAGE = 11 	TYPE_BYTES = 12
TYPE_UINT32 = 13 	TYPE_ENUM = 14 		TYPE_SFIXED32 = 15
TYPE_SFIXED64 = 16 	TYPE_SINT32 = 17 	TYPE_SINT64 = 18
'''
def convert_pb_type(value, type):
	try:
		if type in [FieldDescriptor.TYPE_INT64, 
					FieldDescriptor.TYPE_UINT64, 
					FieldDescriptor.TYPE_INT32, 
					FieldDescriptor.TYPE_ENUM]:
			return int(value)
		elif type in [FieldDescriptor.TYPE_DOUBLE, 
					  FieldDescriptor.TYPE_FLOAT]:
			return float(value)
		elif type in [FieldDescriptor.TYPE_STRING]:
			if isinstance(value, basestring):
				return value
			elif isinstance(value, float):
				return str(int(value))
			else:
				return str(value)
		else:
			return None
	except:
		return None

def list_fields(class_name):
	fields = []
	for field in getattr(sys.modules[__name__], class_name).fields:
		fields.append([field.name, field.type, field.index])
	return fields

def compile_protobuf(src, dst, proto_file, language):
	if language == 'cpp':
		out_language = 'cpp_out'
	elif language == 'python':
		out_language = 'python_out'
	elif language == 'java':
		out_language = 'java_out'
	else:
		out_language = 'python_out'
	# os.system('protoc -I=%s --%s=%s %s' % (src, out_language, dst, src + '/' + proto_file))
	os.system('/Users/supersuraccoon/Desktop/work_collection/programming/pb/pb/protobuf/bin/protoc -I=%s --%s=%s %s' % (src, out_language, dst, src + '/' + proto_file))

# excel
def parse_excel(xls_file):
	workbook_dict = {}
	# workbook
	workbook = xlrd.open_workbook(xls_file)
	# work sheets
	worksheets = workbook.sheet_names()
	for worksheet_name in worksheets:
		worksheet = workbook.sheet_by_name(worksheet_name)
		workbook_dict[worksheet_name] = []
		for ri in range(worksheet.nrows):
			row_list = []
			for ci in range(worksheet.ncols):
				cell_type = worksheet.cell_type(ri, ci)
				cell_value = worksheet.cell_value(ri, ci)
				row_list.append([cell_type, cell_value, ci])
			workbook_dict[worksheet_name].append(row_list)
	return workbook_dict

def get_value_index(header, cell):
	for col in header:
		if col[1] == cell:
			return col[2]
	return -1

def get_attr_value(fields, header, row, attr):
	for field in fields:
		if field[0] == attr:
			value_index = get_value_index(header, field[0])
			return row[value_index][1]
	return None

# tool function
def list_protos():
	pb_list = []
	for (dirpath, dirnames, filenames) in os.walk(PB_DIR):
		for filename in filenames:
			if os.path.splitext(filename)[1] == '.proto':
				pb_list.append(filename)
	return pb_list

def list_xls_files():
	xls_list = []
	for (dirpath, dirnames, filenames) in os.walk(XLS_DIR):
		for filename in filenames:
			if os.path.splitext(filename)[1] == '.xls':
				xls_list.append(filename)
	return xls_list

def list_pb_py_files():
	pb_py_list = []
	for (dirpath, dirnames, filenames) in os.walk(PB_PY_DIR):
		for filename in filenames:
			if not filename.startswith('__') and os.path.splitext(filename)[1] == '.py':
				pb_py_list.append(os.path.splitext(filename)[0])
	return pb_py_list


def import_pb_class(pb_attr, class_name):
	attr = getattr(pb_attr, class_name)
	setattr(sys.modules[__name__], class_name, attr)

	descriptor = make_descriptor_name(class_name)
	attr = getattr(pb_attr, descriptor)
	setattr(sys.modules[__name__], descriptor, attr)

def complie_all_pb():
	# compile pb to pb_py	
	for pb in list_protos():
		compile_protobuf(PB_DIR, PB_PY_DIR, pb, 'python')
		# compile_protobuf(PB_DIR, PB_CPP_DIR, pb, 'cpp')
		# compile_protobuf(PB_DIR, PB_JAVA_DIR, pb, 'java')

def check_dir():
	if not os.path.exists(PB_DIR):
		print '%s not exists !' % PB_DIR
		exit(0)
	if not os.path.exists(PB_PY_DIR):
		print '%s not exists !' % PB_PY_DIR
		exit(0)
	if not os.path.exists(XLS_DIR):
		print '%s not exists !' % XLS_DIR
		exit(0)
	if not os.path.exists(BIN_DIR):
		print '%s not exists !' % BIN_DIR
		exit(0)

def copy_res():
	pass

def get_xls_files():
	worksheet_dict = {}
	for xls in list_xls_files():
		workbook_dict = parse_excel(XLS_DIR + '/' + xls)
		for worksheet_name, table in workbook_dict.items():
			worksheet_dict[worksheet_name] = table
	return worksheet_dict

def parse_xls_files():
	for worksheet_name, table in get_xls_files().items():
		message_object = class_from_string(worksheet_name)
		if not message_object:
			continue
		fields = list_fields(make_descriptor_name(worksheet_name))
		parse_table(worksheet_name, table, fields)

def parse_table(worksheet_name, table, fields):
	gameInfo = class_from_string('GameInfo')
	for ri in range(len(table)):
		if ri == 0:
			continue
		row = table[ri]
		message = None
		for field in fields:
			value_index = get_value_index(table[0], field[0])
			if value_index != -1:
				if not row[value_index][0] in [xlrd.XL_CELL_EMPTY, xlrd.XL_CELL_BLANK]:
					value = convert_pb_type(row[value_index][1], field[1])
					if value != None:
						if message == None:
							message = getattr(gameInfo, worksheet_name[0].lower() + worksheet_name[1:]).add()	
						setattr(message, field[0], value)
	try:
		serializedObject = gameInfo.SerializeToString()
		pb_bin_file = "./bin/%s.bin" % worksheet_name
		try:
		    os.remove(pb_bin_file)
		except OSError:
		    pass
		pb_bin = open(pb_bin_file, "wb")
		pb_bin.write(serializedObject)
		pb_bin.close()
		do_check(pb_bin_file)
	except Exception, e:
		print e

def dynamic_import():
	import PYTHON.GameInfo_pb2
	import_py = __import__('PYTHON.GameInfo_pb2')
	pb_attr = getattr(import_py, 'GameInfo_pb2')
	del import_py

	for name, obj in inspect.getmembers(PYTHON.GameInfo_pb2):
		if inspect.isclass(obj):
			import_pb_class(pb_attr, name)

def do_check(binFile):
	gameInfo = class_from_string('GameInfo')
	f = open(binFile, "rb")
	gameInfo.ParseFromString(f.read())
	f.close()
	print text_format.MessageToString(gameInfo, True, False)

if __name__ == '__main__':
	print '------------- xls to bin start  -------------'

	print '\n------------- 1. check_dir      -------------'
	check_dir()

	print '\n------------- 2. complie_all_pb -------------'
	complie_all_pb()

	print '\n------------- 3. copy_res       -------------'
	copy_res()

	print '\n------------- 4. dynamic_import -------------'
	dynamic_import()

	print '\n------------- 5. parse_xls_files -------------'
	parse_xls_files()

	print '\n------------- xls to bin end 	-------------'

