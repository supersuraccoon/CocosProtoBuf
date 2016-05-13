// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GameInfo.proto

#ifndef PROTOBUF_GameInfo_2eproto__INCLUDED
#define PROTOBUF_GameInfo_2eproto__INCLUDED

#include <string>

#include "google/protobuf/stubs/common.h"

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "GameEnum.pb.h"
// @@protoc_insertion_point(includes)

namespace game {
namespace info {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_GameInfo_2eproto();
void protobuf_AssignDesc_GameInfo_2eproto();
void protobuf_ShutdownFile_GameInfo_2eproto();

class GameInfo;
class ItemInfo;
class RoleInfo;

// ===================================================================

class RoleInfo : public ::google::protobuf::Message {
 public:
  RoleInfo();
  virtual ~RoleInfo();

  RoleInfo(const RoleInfo& from);

  inline RoleInfo& operator=(const RoleInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RoleInfo& default_instance();

  void Swap(RoleInfo* other);

  // implements Message ----------------------------------------------

  inline RoleInfo* New() const { return New(NULL); }

  RoleInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RoleInfo& from);
  void MergeFrom(const RoleInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(RoleInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional .game.enumeration.RoleType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::game::enumeration::RoleType type() const;
  void set_type(::game::enumeration::RoleType value);

  // @@protoc_insertion_point(class_scope:game.info.RoleInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  int type_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GameInfo_2eproto();
  friend void protobuf_AssignDesc_GameInfo_2eproto();
  friend void protobuf_ShutdownFile_GameInfo_2eproto();

  void InitAsDefaultInstance();
  static RoleInfo* default_instance_;
};
// -------------------------------------------------------------------

class ItemInfo : public ::google::protobuf::Message {
 public:
  ItemInfo();
  virtual ~ItemInfo();

  ItemInfo(const ItemInfo& from);

  inline ItemInfo& operator=(const ItemInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ItemInfo& default_instance();

  void Swap(ItemInfo* other);

  // implements Message ----------------------------------------------

  inline ItemInfo* New() const { return New(NULL); }

  ItemInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ItemInfo& from);
  void MergeFrom(const ItemInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ItemInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional int32 price = 2;
  void clear_price();
  static const int kPriceFieldNumber = 2;
  ::google::protobuf::int32 price() const;
  void set_price(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:game.info.ItemInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 price_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GameInfo_2eproto();
  friend void protobuf_AssignDesc_GameInfo_2eproto();
  friend void protobuf_ShutdownFile_GameInfo_2eproto();

  void InitAsDefaultInstance();
  static ItemInfo* default_instance_;
};
// -------------------------------------------------------------------

class GameInfo : public ::google::protobuf::Message {
 public:
  GameInfo();
  virtual ~GameInfo();

  GameInfo(const GameInfo& from);

  inline GameInfo& operator=(const GameInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GameInfo& default_instance();

  void Swap(GameInfo* other);

  // implements Message ----------------------------------------------

  inline GameInfo* New() const { return New(NULL); }

  GameInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GameInfo& from);
  void MergeFrom(const GameInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GameInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .game.info.RoleInfo roleInfo = 1;
  int roleinfo_size() const;
  void clear_roleinfo();
  static const int kRoleInfoFieldNumber = 1;
  const ::game::info::RoleInfo& roleinfo(int index) const;
  ::game::info::RoleInfo* mutable_roleinfo(int index);
  ::game::info::RoleInfo* add_roleinfo();
  ::google::protobuf::RepeatedPtrField< ::game::info::RoleInfo >*
      mutable_roleinfo();
  const ::google::protobuf::RepeatedPtrField< ::game::info::RoleInfo >&
      roleinfo() const;

  // repeated .game.info.ItemInfo itemInfo = 2;
  int iteminfo_size() const;
  void clear_iteminfo();
  static const int kItemInfoFieldNumber = 2;
  const ::game::info::ItemInfo& iteminfo(int index) const;
  ::game::info::ItemInfo* mutable_iteminfo(int index);
  ::game::info::ItemInfo* add_iteminfo();
  ::google::protobuf::RepeatedPtrField< ::game::info::ItemInfo >*
      mutable_iteminfo();
  const ::google::protobuf::RepeatedPtrField< ::game::info::ItemInfo >&
      iteminfo() const;

  // @@protoc_insertion_point(class_scope:game.info.GameInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::game::info::RoleInfo > roleinfo_;
  ::google::protobuf::RepeatedPtrField< ::game::info::ItemInfo > iteminfo_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_GameInfo_2eproto();
  friend void protobuf_AssignDesc_GameInfo_2eproto();
  friend void protobuf_ShutdownFile_GameInfo_2eproto();

  void InitAsDefaultInstance();
  static GameInfo* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// RoleInfo

// optional string name = 1;
inline void RoleInfo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RoleInfo::name() const {
  // @@protoc_insertion_point(field_get:game.info.RoleInfo.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoleInfo::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:game.info.RoleInfo.name)
}
inline void RoleInfo::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:game.info.RoleInfo.name)
}
inline void RoleInfo::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:game.info.RoleInfo.name)
}
inline ::std::string* RoleInfo::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:game.info.RoleInfo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RoleInfo::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RoleInfo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:game.info.RoleInfo.name)
}

// optional .game.enumeration.RoleType type = 2;
inline void RoleInfo::clear_type() {
  type_ = 0;
}
inline ::game::enumeration::RoleType RoleInfo::type() const {
  // @@protoc_insertion_point(field_get:game.info.RoleInfo.type)
  return static_cast< ::game::enumeration::RoleType >(type_);
}
inline void RoleInfo::set_type(::game::enumeration::RoleType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:game.info.RoleInfo.type)
}

// -------------------------------------------------------------------

// ItemInfo

// optional string name = 1;
inline void ItemInfo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ItemInfo::name() const {
  // @@protoc_insertion_point(field_get:game.info.ItemInfo.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ItemInfo::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:game.info.ItemInfo.name)
}
inline void ItemInfo::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:game.info.ItemInfo.name)
}
inline void ItemInfo::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:game.info.ItemInfo.name)
}
inline ::std::string* ItemInfo::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:game.info.ItemInfo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ItemInfo::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ItemInfo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:game.info.ItemInfo.name)
}

// optional int32 price = 2;
inline void ItemInfo::clear_price() {
  price_ = 0;
}
inline ::google::protobuf::int32 ItemInfo::price() const {
  // @@protoc_insertion_point(field_get:game.info.ItemInfo.price)
  return price_;
}
inline void ItemInfo::set_price(::google::protobuf::int32 value) {
  
  price_ = value;
  // @@protoc_insertion_point(field_set:game.info.ItemInfo.price)
}

// -------------------------------------------------------------------

// GameInfo

// repeated .game.info.RoleInfo roleInfo = 1;
inline int GameInfo::roleinfo_size() const {
  return roleinfo_.size();
}
inline void GameInfo::clear_roleinfo() {
  roleinfo_.Clear();
}
inline const ::game::info::RoleInfo& GameInfo::roleinfo(int index) const {
  // @@protoc_insertion_point(field_get:game.info.GameInfo.roleInfo)
  return roleinfo_.Get(index);
}
inline ::game::info::RoleInfo* GameInfo::mutable_roleinfo(int index) {
  // @@protoc_insertion_point(field_mutable:game.info.GameInfo.roleInfo)
  return roleinfo_.Mutable(index);
}
inline ::game::info::RoleInfo* GameInfo::add_roleinfo() {
  // @@protoc_insertion_point(field_add:game.info.GameInfo.roleInfo)
  return roleinfo_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::game::info::RoleInfo >*
GameInfo::mutable_roleinfo() {
  // @@protoc_insertion_point(field_mutable_list:game.info.GameInfo.roleInfo)
  return &roleinfo_;
}
inline const ::google::protobuf::RepeatedPtrField< ::game::info::RoleInfo >&
GameInfo::roleinfo() const {
  // @@protoc_insertion_point(field_list:game.info.GameInfo.roleInfo)
  return roleinfo_;
}

// repeated .game.info.ItemInfo itemInfo = 2;
inline int GameInfo::iteminfo_size() const {
  return iteminfo_.size();
}
inline void GameInfo::clear_iteminfo() {
  iteminfo_.Clear();
}
inline const ::game::info::ItemInfo& GameInfo::iteminfo(int index) const {
  // @@protoc_insertion_point(field_get:game.info.GameInfo.itemInfo)
  return iteminfo_.Get(index);
}
inline ::game::info::ItemInfo* GameInfo::mutable_iteminfo(int index) {
  // @@protoc_insertion_point(field_mutable:game.info.GameInfo.itemInfo)
  return iteminfo_.Mutable(index);
}
inline ::game::info::ItemInfo* GameInfo::add_iteminfo() {
  // @@protoc_insertion_point(field_add:game.info.GameInfo.itemInfo)
  return iteminfo_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::game::info::ItemInfo >*
GameInfo::mutable_iteminfo() {
  // @@protoc_insertion_point(field_mutable_list:game.info.GameInfo.itemInfo)
  return &iteminfo_;
}
inline const ::google::protobuf::RepeatedPtrField< ::game::info::ItemInfo >&
GameInfo::iteminfo() const {
  // @@protoc_insertion_point(field_list:game.info.GameInfo.itemInfo)
  return iteminfo_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace info
}  // namespace game

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_GameInfo_2eproto__INCLUDED
