# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: GameInfo.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import GameEnum_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='GameInfo.proto',
  package='game.info',
  serialized_pb='\n\x0eGameInfo.proto\x12\tgame.info\x1a\x0eGameEnum.proto\"B\n\x08RoleInfo\x12\x0c\n\x04name\x18\x01 \x02(\t\x12(\n\x04type\x18\x02 \x02(\x0e\x32\x1a.game.enumeration.RoleType\"\'\n\x08ItemInfo\x12\x0c\n\x04name\x18\x01 \x02(\t\x12\r\n\x05price\x18\x02 \x01(\x05\"X\n\x08GameInfo\x12%\n\x08roleInfo\x18\x01 \x03(\x0b\x32\x13.game.info.RoleInfo\x12%\n\x08itemInfo\x18\x02 \x03(\x0b\x32\x13.game.info.ItemInfoB\x1f\n\rcom.game.infoB\x0eGameInfoProtos')




_ROLEINFO = _descriptor.Descriptor(
  name='RoleInfo',
  full_name='game.info.RoleInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='game.info.RoleInfo.name', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='type', full_name='game.info.RoleInfo.type', index=1,
      number=2, type=14, cpp_type=8, label=2,
      has_default_value=False, default_value=1,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=45,
  serialized_end=111,
)


_ITEMINFO = _descriptor.Descriptor(
  name='ItemInfo',
  full_name='game.info.ItemInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='game.info.ItemInfo.name', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='price', full_name='game.info.ItemInfo.price', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=113,
  serialized_end=152,
)


_GAMEINFO = _descriptor.Descriptor(
  name='GameInfo',
  full_name='game.info.GameInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='roleInfo', full_name='game.info.GameInfo.roleInfo', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='itemInfo', full_name='game.info.GameInfo.itemInfo', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=154,
  serialized_end=242,
)

_ROLEINFO.fields_by_name['type'].enum_type = GameEnum_pb2._ROLETYPE
_GAMEINFO.fields_by_name['roleInfo'].message_type = _ROLEINFO
_GAMEINFO.fields_by_name['itemInfo'].message_type = _ITEMINFO
DESCRIPTOR.message_types_by_name['RoleInfo'] = _ROLEINFO
DESCRIPTOR.message_types_by_name['ItemInfo'] = _ITEMINFO
DESCRIPTOR.message_types_by_name['GameInfo'] = _GAMEINFO

class RoleInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _ROLEINFO

  # @@protoc_insertion_point(class_scope:game.info.RoleInfo)

class ItemInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _ITEMINFO

  # @@protoc_insertion_point(class_scope:game.info.ItemInfo)

class GameInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _GAMEINFO

  # @@protoc_insertion_point(class_scope:game.info.GameInfo)


DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), '\n\rcom.game.infoB\016GameInfoProtos')
# @@protoc_insertion_point(module_scope)
