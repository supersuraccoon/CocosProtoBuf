# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: GameEnum.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='GameEnum.proto',
  package='game.enumeration',
  serialized_pb='\n\x0eGameEnum.proto\x12\x10game.enumeration*1\n\x08RoleType\x12\x0b\n\x07\x46IGHTER\x10\x01\x12\n\n\x06\x42OWMAN\x10\x02\x12\x0c\n\x08MAGICIAN\x10\x03\x42&\n\x14\x63om.game.enumerationB\x0eGameEnumProtos')

_ROLETYPE = _descriptor.EnumDescriptor(
  name='RoleType',
  full_name='game.enumeration.RoleType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='FIGHTER', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='BOWMAN', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MAGICIAN', index=2, number=3,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=36,
  serialized_end=85,
)

RoleType = enum_type_wrapper.EnumTypeWrapper(_ROLETYPE)
FIGHTER = 1
BOWMAN = 2
MAGICIAN = 3




DESCRIPTOR.has_options = True
DESCRIPTOR._options = _descriptor._ParseOptions(descriptor_pb2.FileOptions(), '\n\024com.game.enumerationB\016GameEnumProtos')
# @@protoc_insertion_point(module_scope)
