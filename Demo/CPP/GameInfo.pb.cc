// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameInfo.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "GameInfo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace game {
namespace info {

namespace {

const ::google::protobuf::Descriptor* RoleInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RoleInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* ItemInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ItemInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* GameInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_GameInfo_2eproto() {
  protobuf_AddDesc_GameInfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "GameInfo.proto");
  GOOGLE_CHECK(file != NULL);
  RoleInfo_descriptor_ = file->message_type(0);
  static const int RoleInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoleInfo, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoleInfo, type_),
  };
  RoleInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RoleInfo_descriptor_,
      RoleInfo::default_instance_,
      RoleInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoleInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoleInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RoleInfo));
  ItemInfo_descriptor_ = file->message_type(1);
  static const int ItemInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ItemInfo, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ItemInfo, price_),
  };
  ItemInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ItemInfo_descriptor_,
      ItemInfo::default_instance_,
      ItemInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ItemInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ItemInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ItemInfo));
  GameInfo_descriptor_ = file->message_type(2);
  static const int GameInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameInfo, roleinfo_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameInfo, iteminfo_),
  };
  GameInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameInfo_descriptor_,
      GameInfo::default_instance_,
      GameInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_GameInfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RoleInfo_descriptor_, &RoleInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ItemInfo_descriptor_, &ItemInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameInfo_descriptor_, &GameInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_GameInfo_2eproto() {
  delete RoleInfo::default_instance_;
  delete RoleInfo_reflection_;
  delete ItemInfo::default_instance_;
  delete ItemInfo_reflection_;
  delete GameInfo::default_instance_;
  delete GameInfo_reflection_;
}

void protobuf_AddDesc_GameInfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::game::enumeration::protobuf_AddDesc_GameEnum_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016GameInfo.proto\022\tgame.info\032\016GameEnum.pr"
    "oto\"B\n\010RoleInfo\022\014\n\004name\030\001 \002(\t\022(\n\004type\030\002 "
    "\002(\0162\032.game.enumeration.RoleType\"\'\n\010ItemI"
    "nfo\022\014\n\004name\030\001 \002(\t\022\r\n\005price\030\002 \001(\005\"X\n\010Game"
    "Info\022%\n\010roleInfo\030\001 \003(\0132\023.game.info.RoleI"
    "nfo\022%\n\010itemInfo\030\002 \003(\0132\023.game.info.ItemIn"
    "foB\037\n\rcom.game.infoB\016GameInfoProtos", 275);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "GameInfo.proto", &protobuf_RegisterTypes);
  RoleInfo::default_instance_ = new RoleInfo();
  ItemInfo::default_instance_ = new ItemInfo();
  GameInfo::default_instance_ = new GameInfo();
  RoleInfo::default_instance_->InitAsDefaultInstance();
  ItemInfo::default_instance_->InitAsDefaultInstance();
  GameInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_GameInfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_GameInfo_2eproto {
  StaticDescriptorInitializer_GameInfo_2eproto() {
    protobuf_AddDesc_GameInfo_2eproto();
  }
} static_descriptor_initializer_GameInfo_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int RoleInfo::kNameFieldNumber;
const int RoleInfo::kTypeFieldNumber;
#endif  // !_MSC_VER

RoleInfo::RoleInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void RoleInfo::InitAsDefaultInstance() {
}

RoleInfo::RoleInfo(const RoleInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void RoleInfo::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  type_ = 1;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RoleInfo::~RoleInfo() {
  SharedDtor();
}

void RoleInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void RoleInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RoleInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RoleInfo_descriptor_;
}

const RoleInfo& RoleInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GameInfo_2eproto();
  return *default_instance_;
}

RoleInfo* RoleInfo::default_instance_ = NULL;

RoleInfo* RoleInfo::New() const {
  return new RoleInfo;
}

void RoleInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    type_ = 1;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RoleInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // required .game.enumeration.RoleType type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::game::enumeration::RoleType_IsValid(value)) {
            set_type(static_cast< ::game::enumeration::RoleType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void RoleInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->name(), output);
  }

  // required .game.enumeration.RoleType type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* RoleInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // required .game.enumeration.RoleType type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int RoleInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required .game.enumeration.RoleType type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RoleInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RoleInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RoleInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RoleInfo::MergeFrom(const RoleInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RoleInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RoleInfo::CopyFrom(const RoleInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RoleInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void RoleInfo::Swap(RoleInfo* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RoleInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RoleInfo_descriptor_;
  metadata.reflection = RoleInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ItemInfo::kNameFieldNumber;
const int ItemInfo::kPriceFieldNumber;
#endif  // !_MSC_VER

ItemInfo::ItemInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ItemInfo::InitAsDefaultInstance() {
}

ItemInfo::ItemInfo(const ItemInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ItemInfo::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  price_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ItemInfo::~ItemInfo() {
  SharedDtor();
}

void ItemInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void ItemInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ItemInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ItemInfo_descriptor_;
}

const ItemInfo& ItemInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GameInfo_2eproto();
  return *default_instance_;
}

ItemInfo* ItemInfo::default_instance_ = NULL;

ItemInfo* ItemInfo::New() const {
  return new ItemInfo;
}

void ItemInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    price_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ItemInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_price;
        break;
      }

      // optional int32 price = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_price:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &price_)));
          set_has_price();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ItemInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->name(), output);
  }

  // optional int32 price = 2;
  if (has_price()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->price(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ItemInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // optional int32 price = 2;
  if (has_price()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->price(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ItemInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional int32 price = 2;
    if (has_price()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->price());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ItemInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ItemInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ItemInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ItemInfo::MergeFrom(const ItemInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_price()) {
      set_price(from.price());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ItemInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ItemInfo::CopyFrom(const ItemInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ItemInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void ItemInfo::Swap(ItemInfo* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(price_, other->price_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ItemInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ItemInfo_descriptor_;
  metadata.reflection = ItemInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int GameInfo::kRoleInfoFieldNumber;
const int GameInfo::kItemInfoFieldNumber;
#endif  // !_MSC_VER

GameInfo::GameInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void GameInfo::InitAsDefaultInstance() {
}

GameInfo::GameInfo(const GameInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void GameInfo::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameInfo::~GameInfo() {
  SharedDtor();
}

void GameInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameInfo_descriptor_;
}

const GameInfo& GameInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_GameInfo_2eproto();
  return *default_instance_;
}

GameInfo* GameInfo::default_instance_ = NULL;

GameInfo* GameInfo::New() const {
  return new GameInfo;
}

void GameInfo::Clear() {
  roleinfo_.Clear();
  iteminfo_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .game.info.RoleInfo roleInfo = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_roleInfo:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_roleinfo()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_roleInfo;
        if (input->ExpectTag(18)) goto parse_itemInfo;
        break;
      }

      // repeated .game.info.ItemInfo itemInfo = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_itemInfo:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_iteminfo()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_itemInfo;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void GameInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .game.info.RoleInfo roleInfo = 1;
  for (int i = 0; i < this->roleinfo_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->roleinfo(i), output);
  }

  // repeated .game.info.ItemInfo itemInfo = 2;
  for (int i = 0; i < this->iteminfo_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->iteminfo(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* GameInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .game.info.RoleInfo roleInfo = 1;
  for (int i = 0; i < this->roleinfo_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->roleinfo(i), target);
  }

  // repeated .game.info.ItemInfo itemInfo = 2;
  for (int i = 0; i < this->iteminfo_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->iteminfo(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int GameInfo::ByteSize() const {
  int total_size = 0;

  // repeated .game.info.RoleInfo roleInfo = 1;
  total_size += 1 * this->roleinfo_size();
  for (int i = 0; i < this->roleinfo_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->roleinfo(i));
  }

  // repeated .game.info.ItemInfo itemInfo = 2;
  total_size += 1 * this->iteminfo_size();
  for (int i = 0; i < this->iteminfo_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->iteminfo(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameInfo::MergeFrom(const GameInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  roleinfo_.MergeFrom(from.roleinfo_);
  iteminfo_.MergeFrom(from.iteminfo_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameInfo::CopyFrom(const GameInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameInfo::IsInitialized() const {

  for (int i = 0; i < roleinfo_size(); i++) {
    if (!this->roleinfo(i).IsInitialized()) return false;
  }
  for (int i = 0; i < iteminfo_size(); i++) {
    if (!this->iteminfo(i).IsInitialized()) return false;
  }
  return true;
}

void GameInfo::Swap(GameInfo* other) {
  if (other != this) {
    roleinfo_.Swap(&other->roleinfo_);
    iteminfo_.Swap(&other->iteminfo_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameInfo_descriptor_;
  metadata.reflection = GameInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace info
}  // namespace game

// @@protoc_insertion_point(global_scope)