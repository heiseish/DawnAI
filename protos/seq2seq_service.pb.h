// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: seq2seq_service.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_seq2seq_5fservice_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_seq2seq_5fservice_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3010000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3010000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_seq2seq_5fservice_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_seq2seq_5fservice_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_seq2seq_5fservice_2eproto;
namespace Seq2SeqGRPC {
class ConversationInput;
class ConversationInputDefaultTypeInternal;
extern ConversationInputDefaultTypeInternal _ConversationInput_default_instance_;
class ConversationResponse;
class ConversationResponseDefaultTypeInternal;
extern ConversationResponseDefaultTypeInternal _ConversationResponse_default_instance_;
}  // namespace Seq2SeqGRPC
PROTOBUF_NAMESPACE_OPEN
template<> ::Seq2SeqGRPC::ConversationInput* Arena::CreateMaybeMessage<::Seq2SeqGRPC::ConversationInput>(Arena*);
template<> ::Seq2SeqGRPC::ConversationResponse* Arena::CreateMaybeMessage<::Seq2SeqGRPC::ConversationResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Seq2SeqGRPC {

enum ConversationResponse_State : int {
  ConversationResponse_State_SUCCESS = 0,
  ConversationResponse_State_MODEL_ERR = 1,
  ConversationResponse_State_UNKNOWN = 2,
  ConversationResponse_State_ConversationResponse_State_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  ConversationResponse_State_ConversationResponse_State_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool ConversationResponse_State_IsValid(int value);
constexpr ConversationResponse_State ConversationResponse_State_State_MIN = ConversationResponse_State_SUCCESS;
constexpr ConversationResponse_State ConversationResponse_State_State_MAX = ConversationResponse_State_UNKNOWN;
constexpr int ConversationResponse_State_State_ARRAYSIZE = ConversationResponse_State_State_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ConversationResponse_State_descriptor();
template<typename T>
inline const std::string& ConversationResponse_State_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ConversationResponse_State>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ConversationResponse_State_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ConversationResponse_State_descriptor(), enum_t_value);
}
inline bool ConversationResponse_State_Parse(
    const std::string& name, ConversationResponse_State* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ConversationResponse_State>(
    ConversationResponse_State_descriptor(), name, value);
}
// ===================================================================

class ConversationInput :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Seq2SeqGRPC.ConversationInput) */ {
 public:
  ConversationInput();
  virtual ~ConversationInput();

  ConversationInput(const ConversationInput& from);
  ConversationInput(ConversationInput&& from) noexcept
    : ConversationInput() {
    *this = ::std::move(from);
  }

  inline ConversationInput& operator=(const ConversationInput& from) {
    CopyFrom(from);
    return *this;
  }
  inline ConversationInput& operator=(ConversationInput&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ConversationInput& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConversationInput* internal_default_instance() {
    return reinterpret_cast<const ConversationInput*>(
               &_ConversationInput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ConversationInput& a, ConversationInput& b) {
    a.Swap(&b);
  }
  inline void Swap(ConversationInput* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ConversationInput* New() const final {
    return CreateMaybeMessage<ConversationInput>(nullptr);
  }

  ConversationInput* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ConversationInput>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ConversationInput& from);
  void MergeFrom(const ConversationInput& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConversationInput* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Seq2SeqGRPC.ConversationInput";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_seq2seq_5fservice_2eproto);
    return ::descriptor_table_seq2seq_5fservice_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTransIdFieldNumber = 1,
    kTextFieldNumber = 2,
  };
  // string trans_id = 1;
  void clear_trans_id();
  const std::string& trans_id() const;
  void set_trans_id(const std::string& value);
  void set_trans_id(std::string&& value);
  void set_trans_id(const char* value);
  void set_trans_id(const char* value, size_t size);
  std::string* mutable_trans_id();
  std::string* release_trans_id();
  void set_allocated_trans_id(std::string* trans_id);
  private:
  const std::string& _internal_trans_id() const;
  void _internal_set_trans_id(const std::string& value);
  std::string* _internal_mutable_trans_id();
  public:

  // string text = 2;
  void clear_text();
  const std::string& text() const;
  void set_text(const std::string& value);
  void set_text(std::string&& value);
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  std::string* mutable_text();
  std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // @@protoc_insertion_point(class_scope:Seq2SeqGRPC.ConversationInput)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr trans_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_seq2seq_5fservice_2eproto;
};
// -------------------------------------------------------------------

class ConversationResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Seq2SeqGRPC.ConversationResponse) */ {
 public:
  ConversationResponse();
  virtual ~ConversationResponse();

  ConversationResponse(const ConversationResponse& from);
  ConversationResponse(ConversationResponse&& from) noexcept
    : ConversationResponse() {
    *this = ::std::move(from);
  }

  inline ConversationResponse& operator=(const ConversationResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline ConversationResponse& operator=(ConversationResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ConversationResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ConversationResponse* internal_default_instance() {
    return reinterpret_cast<const ConversationResponse*>(
               &_ConversationResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ConversationResponse& a, ConversationResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(ConversationResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ConversationResponse* New() const final {
    return CreateMaybeMessage<ConversationResponse>(nullptr);
  }

  ConversationResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ConversationResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ConversationResponse& from);
  void MergeFrom(const ConversationResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ConversationResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Seq2SeqGRPC.ConversationResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_seq2seq_5fservice_2eproto);
    return ::descriptor_table_seq2seq_5fservice_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef ConversationResponse_State State;
  static constexpr State SUCCESS =
    ConversationResponse_State_SUCCESS;
  static constexpr State MODEL_ERR =
    ConversationResponse_State_MODEL_ERR;
  static constexpr State UNKNOWN =
    ConversationResponse_State_UNKNOWN;
  static inline bool State_IsValid(int value) {
    return ConversationResponse_State_IsValid(value);
  }
  static constexpr State State_MIN =
    ConversationResponse_State_State_MIN;
  static constexpr State State_MAX =
    ConversationResponse_State_State_MAX;
  static constexpr int State_ARRAYSIZE =
    ConversationResponse_State_State_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  State_descriptor() {
    return ConversationResponse_State_descriptor();
  }
  template<typename T>
  static inline const std::string& State_Name(T enum_t_value) {
    static_assert(::std::is_same<T, State>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function State_Name.");
    return ConversationResponse_State_Name(enum_t_value);
  }
  static inline bool State_Parse(const std::string& name,
      State* value) {
    return ConversationResponse_State_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kTransIdFieldNumber = 1,
    kTextFieldNumber = 3,
    kStateFieldNumber = 2,
  };
  // string trans_id = 1;
  void clear_trans_id();
  const std::string& trans_id() const;
  void set_trans_id(const std::string& value);
  void set_trans_id(std::string&& value);
  void set_trans_id(const char* value);
  void set_trans_id(const char* value, size_t size);
  std::string* mutable_trans_id();
  std::string* release_trans_id();
  void set_allocated_trans_id(std::string* trans_id);
  private:
  const std::string& _internal_trans_id() const;
  void _internal_set_trans_id(const std::string& value);
  std::string* _internal_mutable_trans_id();
  public:

  // string text = 3;
  void clear_text();
  const std::string& text() const;
  void set_text(const std::string& value);
  void set_text(std::string&& value);
  void set_text(const char* value);
  void set_text(const char* value, size_t size);
  std::string* mutable_text();
  std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // .Seq2SeqGRPC.ConversationResponse.State state = 2;
  void clear_state();
  ::Seq2SeqGRPC::ConversationResponse_State state() const;
  void set_state(::Seq2SeqGRPC::ConversationResponse_State value);
  private:
  ::Seq2SeqGRPC::ConversationResponse_State _internal_state() const;
  void _internal_set_state(::Seq2SeqGRPC::ConversationResponse_State value);
  public:

  // @@protoc_insertion_point(class_scope:Seq2SeqGRPC.ConversationResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr trans_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
  int state_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_seq2seq_5fservice_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ConversationInput

// string trans_id = 1;
inline void ConversationInput::clear_trans_id() {
  trans_id_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ConversationInput::trans_id() const {
  // @@protoc_insertion_point(field_get:Seq2SeqGRPC.ConversationInput.trans_id)
  return _internal_trans_id();
}
inline void ConversationInput::set_trans_id(const std::string& value) {
  _internal_set_trans_id(value);
  // @@protoc_insertion_point(field_set:Seq2SeqGRPC.ConversationInput.trans_id)
}
inline std::string* ConversationInput::mutable_trans_id() {
  // @@protoc_insertion_point(field_mutable:Seq2SeqGRPC.ConversationInput.trans_id)
  return _internal_mutable_trans_id();
}
inline const std::string& ConversationInput::_internal_trans_id() const {
  return trans_id_.GetNoArena();
}
inline void ConversationInput::_internal_set_trans_id(const std::string& value) {
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ConversationInput::set_trans_id(std::string&& value) {
  
  trans_id_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Seq2SeqGRPC.ConversationInput.trans_id)
}
inline void ConversationInput::set_trans_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Seq2SeqGRPC.ConversationInput.trans_id)
}
inline void ConversationInput::set_trans_id(const char* value, size_t size) {
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Seq2SeqGRPC.ConversationInput.trans_id)
}
inline std::string* ConversationInput::_internal_mutable_trans_id() {
  
  return trans_id_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ConversationInput::release_trans_id() {
  // @@protoc_insertion_point(field_release:Seq2SeqGRPC.ConversationInput.trans_id)
  
  return trans_id_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ConversationInput::set_allocated_trans_id(std::string* trans_id) {
  if (trans_id != nullptr) {
    
  } else {
    
  }
  trans_id_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), trans_id);
  // @@protoc_insertion_point(field_set_allocated:Seq2SeqGRPC.ConversationInput.trans_id)
}

// string text = 2;
inline void ConversationInput::clear_text() {
  text_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ConversationInput::text() const {
  // @@protoc_insertion_point(field_get:Seq2SeqGRPC.ConversationInput.text)
  return _internal_text();
}
inline void ConversationInput::set_text(const std::string& value) {
  _internal_set_text(value);
  // @@protoc_insertion_point(field_set:Seq2SeqGRPC.ConversationInput.text)
}
inline std::string* ConversationInput::mutable_text() {
  // @@protoc_insertion_point(field_mutable:Seq2SeqGRPC.ConversationInput.text)
  return _internal_mutable_text();
}
inline const std::string& ConversationInput::_internal_text() const {
  return text_.GetNoArena();
}
inline void ConversationInput::_internal_set_text(const std::string& value) {
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ConversationInput::set_text(std::string&& value) {
  
  text_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Seq2SeqGRPC.ConversationInput.text)
}
inline void ConversationInput::set_text(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Seq2SeqGRPC.ConversationInput.text)
}
inline void ConversationInput::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Seq2SeqGRPC.ConversationInput.text)
}
inline std::string* ConversationInput::_internal_mutable_text() {
  
  return text_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ConversationInput::release_text() {
  // @@protoc_insertion_point(field_release:Seq2SeqGRPC.ConversationInput.text)
  
  return text_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ConversationInput::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:Seq2SeqGRPC.ConversationInput.text)
}

// -------------------------------------------------------------------

// ConversationResponse

// string trans_id = 1;
inline void ConversationResponse::clear_trans_id() {
  trans_id_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ConversationResponse::trans_id() const {
  // @@protoc_insertion_point(field_get:Seq2SeqGRPC.ConversationResponse.trans_id)
  return _internal_trans_id();
}
inline void ConversationResponse::set_trans_id(const std::string& value) {
  _internal_set_trans_id(value);
  // @@protoc_insertion_point(field_set:Seq2SeqGRPC.ConversationResponse.trans_id)
}
inline std::string* ConversationResponse::mutable_trans_id() {
  // @@protoc_insertion_point(field_mutable:Seq2SeqGRPC.ConversationResponse.trans_id)
  return _internal_mutable_trans_id();
}
inline const std::string& ConversationResponse::_internal_trans_id() const {
  return trans_id_.GetNoArena();
}
inline void ConversationResponse::_internal_set_trans_id(const std::string& value) {
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ConversationResponse::set_trans_id(std::string&& value) {
  
  trans_id_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Seq2SeqGRPC.ConversationResponse.trans_id)
}
inline void ConversationResponse::set_trans_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Seq2SeqGRPC.ConversationResponse.trans_id)
}
inline void ConversationResponse::set_trans_id(const char* value, size_t size) {
  
  trans_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Seq2SeqGRPC.ConversationResponse.trans_id)
}
inline std::string* ConversationResponse::_internal_mutable_trans_id() {
  
  return trans_id_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ConversationResponse::release_trans_id() {
  // @@protoc_insertion_point(field_release:Seq2SeqGRPC.ConversationResponse.trans_id)
  
  return trans_id_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ConversationResponse::set_allocated_trans_id(std::string* trans_id) {
  if (trans_id != nullptr) {
    
  } else {
    
  }
  trans_id_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), trans_id);
  // @@protoc_insertion_point(field_set_allocated:Seq2SeqGRPC.ConversationResponse.trans_id)
}

// .Seq2SeqGRPC.ConversationResponse.State state = 2;
inline void ConversationResponse::clear_state() {
  state_ = 0;
}
inline ::Seq2SeqGRPC::ConversationResponse_State ConversationResponse::_internal_state() const {
  return static_cast< ::Seq2SeqGRPC::ConversationResponse_State >(state_);
}
inline ::Seq2SeqGRPC::ConversationResponse_State ConversationResponse::state() const {
  // @@protoc_insertion_point(field_get:Seq2SeqGRPC.ConversationResponse.state)
  return _internal_state();
}
inline void ConversationResponse::_internal_set_state(::Seq2SeqGRPC::ConversationResponse_State value) {
  
  state_ = value;
}
inline void ConversationResponse::set_state(::Seq2SeqGRPC::ConversationResponse_State value) {
  _internal_set_state(value);
  // @@protoc_insertion_point(field_set:Seq2SeqGRPC.ConversationResponse.state)
}

// string text = 3;
inline void ConversationResponse::clear_text() {
  text_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ConversationResponse::text() const {
  // @@protoc_insertion_point(field_get:Seq2SeqGRPC.ConversationResponse.text)
  return _internal_text();
}
inline void ConversationResponse::set_text(const std::string& value) {
  _internal_set_text(value);
  // @@protoc_insertion_point(field_set:Seq2SeqGRPC.ConversationResponse.text)
}
inline std::string* ConversationResponse::mutable_text() {
  // @@protoc_insertion_point(field_mutable:Seq2SeqGRPC.ConversationResponse.text)
  return _internal_mutable_text();
}
inline const std::string& ConversationResponse::_internal_text() const {
  return text_.GetNoArena();
}
inline void ConversationResponse::_internal_set_text(const std::string& value) {
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ConversationResponse::set_text(std::string&& value) {
  
  text_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Seq2SeqGRPC.ConversationResponse.text)
}
inline void ConversationResponse::set_text(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Seq2SeqGRPC.ConversationResponse.text)
}
inline void ConversationResponse::set_text(const char* value, size_t size) {
  
  text_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Seq2SeqGRPC.ConversationResponse.text)
}
inline std::string* ConversationResponse::_internal_mutable_text() {
  
  return text_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ConversationResponse::release_text() {
  // @@protoc_insertion_point(field_release:Seq2SeqGRPC.ConversationResponse.text)
  
  return text_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ConversationResponse::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  text_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), text);
  // @@protoc_insertion_point(field_set_allocated:Seq2SeqGRPC.ConversationResponse.text)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Seq2SeqGRPC

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Seq2SeqGRPC::ConversationResponse_State> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Seq2SeqGRPC::ConversationResponse_State>() {
  return ::Seq2SeqGRPC::ConversationResponse_State_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_seq2seq_5fservice_2eproto
