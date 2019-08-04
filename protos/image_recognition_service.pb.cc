// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: image_recognition_service.proto

#include "image_recognition_service.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace ImageRecognitionServiceRPC {
class ImageRequestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ImageRequest> _instance;
} _ImageRequest_default_instance_;
class ImageResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ImageResponse> _instance;
} _ImageResponse_default_instance_;
}  // namespace ImageRecognitionServiceRPC
static void InitDefaultsImageRequest_image_5frecognition_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::ImageRecognitionServiceRPC::_ImageRequest_default_instance_;
    new (ptr) ::ImageRecognitionServiceRPC::ImageRequest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ImageRecognitionServiceRPC::ImageRequest::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ImageRequest_image_5frecognition_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsImageRequest_image_5frecognition_5fservice_2eproto}, {}};

static void InitDefaultsImageResponse_image_5frecognition_5fservice_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::ImageRecognitionServiceRPC::_ImageResponse_default_instance_;
    new (ptr) ::ImageRecognitionServiceRPC::ImageResponse();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ImageRecognitionServiceRPC::ImageResponse::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ImageResponse_image_5frecognition_5fservice_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsImageResponse_image_5frecognition_5fservice_2eproto}, {}};

void InitDefaults_image_5frecognition_5fservice_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_ImageRequest_image_5frecognition_5fservice_2eproto.base);
  ::google::protobuf::internal::InitSCC(&scc_info_ImageResponse_image_5frecognition_5fservice_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_image_5frecognition_5fservice_2eproto[2];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_image_5frecognition_5fservice_2eproto[1];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_image_5frecognition_5fservice_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_image_5frecognition_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageRequest, trans_id_),
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageRequest, image_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageResponse, trans_id_),
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageResponse, state_),
  PROTOBUF_FIELD_OFFSET(::ImageRecognitionServiceRPC::ImageResponse, text_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ImageRecognitionServiceRPC::ImageRequest)},
  { 7, -1, sizeof(::ImageRecognitionServiceRPC::ImageResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::ImageRecognitionServiceRPC::_ImageRequest_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::ImageRecognitionServiceRPC::_ImageResponse_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_image_5frecognition_5fservice_2eproto = {
  {}, AddDescriptors_image_5frecognition_5fservice_2eproto, "image_recognition_service.proto", schemas,
  file_default_instances, TableStruct_image_5frecognition_5fservice_2eproto::offsets,
  file_level_metadata_image_5frecognition_5fservice_2eproto, 2, file_level_enum_descriptors_image_5frecognition_5fservice_2eproto, file_level_service_descriptors_image_5frecognition_5fservice_2eproto,
};

const char descriptor_table_protodef_image_5frecognition_5fservice_2eproto[] =
  "\n\037image_recognition_service.proto\022\032Image"
  "RecognitionServiceRPC\"/\n\014ImageRequest\022\020\n"
  "\010trans_id\030\001 \001(\t\022\r\n\005image\030\002 \001(\t\"\241\001\n\rImage"
  "Response\022\020\n\010trans_id\030\001 \001(\t\022>\n\005state\030\002 \001("
  "\0162/.ImageRecognitionServiceRPC.ImageResp"
  "onse.State\022\014\n\004text\030\003 \001(\t\"0\n\005State\022\013\n\007SUC"
  "CESS\020\000\022\r\n\tMODEL_ERR\020\001\022\013\n\007UNKNOWN\020\0022\200\001\n\027I"
  "mageRecognitionService\022e\n\016RecognizeImage"
  "\022(.ImageRecognitionServiceRPC.ImageReque"
  "st\032).ImageRecognitionServiceRPC.ImageRes"
  "ponseB\006\242\002\003RTGb\006proto3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_image_5frecognition_5fservice_2eproto = {
  false, InitDefaults_image_5frecognition_5fservice_2eproto, 
  descriptor_table_protodef_image_5frecognition_5fservice_2eproto,
  "image_recognition_service.proto", &assign_descriptors_table_image_5frecognition_5fservice_2eproto, 421,
};

void AddDescriptors_image_5frecognition_5fservice_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_image_5frecognition_5fservice_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_image_5frecognition_5fservice_2eproto = []() { AddDescriptors_image_5frecognition_5fservice_2eproto(); return true; }();
namespace ImageRecognitionServiceRPC {
const ::google::protobuf::EnumDescriptor* ImageResponse_State_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_image_5frecognition_5fservice_2eproto);
  return file_level_enum_descriptors_image_5frecognition_5fservice_2eproto[0];
}
bool ImageResponse_State_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const ImageResponse_State ImageResponse::SUCCESS;
const ImageResponse_State ImageResponse::MODEL_ERR;
const ImageResponse_State ImageResponse::UNKNOWN;
const ImageResponse_State ImageResponse::State_MIN;
const ImageResponse_State ImageResponse::State_MAX;
const int ImageResponse::State_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void ImageRequest::InitAsDefaultInstance() {
}
class ImageRequest::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ImageRequest::kTransIdFieldNumber;
const int ImageRequest::kImageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ImageRequest::ImageRequest()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ImageRecognitionServiceRPC.ImageRequest)
}
ImageRequest::ImageRequest(const ImageRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  trans_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.trans_id().size() > 0) {
    trans_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.trans_id_);
  }
  image_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.image().size() > 0) {
    image_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.image_);
  }
  // @@protoc_insertion_point(copy_constructor:ImageRecognitionServiceRPC.ImageRequest)
}

void ImageRequest::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_ImageRequest_image_5frecognition_5fservice_2eproto.base);
  trans_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  image_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

ImageRequest::~ImageRequest() {
  // @@protoc_insertion_point(destructor:ImageRecognitionServiceRPC.ImageRequest)
  SharedDtor();
}

void ImageRequest::SharedDtor() {
  trans_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  image_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ImageRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ImageRequest& ImageRequest::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_ImageRequest_image_5frecognition_5fservice_2eproto.base);
  return *internal_default_instance();
}


void ImageRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ImageRecognitionServiceRPC.ImageRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  trans_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ImageRequest::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<ImageRequest*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string trans_id = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("ImageRecognitionServiceRPC.ImageRequest.trans_id");
        object = msg->mutable_trans_id();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // string image = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 18) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("ImageRecognitionServiceRPC.ImageRequest.image");
        object = msg->mutable_image();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool ImageRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ImageRecognitionServiceRPC.ImageRequest)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string trans_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_trans_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->trans_id().data(), static_cast<int>(this->trans_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ImageRecognitionServiceRPC.ImageRequest.trans_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string image = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (18 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_image()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->image().data(), static_cast<int>(this->image().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ImageRecognitionServiceRPC.ImageRequest.image"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ImageRecognitionServiceRPC.ImageRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ImageRecognitionServiceRPC.ImageRequest)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ImageRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ImageRecognitionServiceRPC.ImageRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->trans_id().data(), static_cast<int>(this->trans_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageRequest.trans_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->trans_id(), output);
  }

  // string image = 2;
  if (this->image().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->image().data(), static_cast<int>(this->image().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageRequest.image");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->image(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ImageRecognitionServiceRPC.ImageRequest)
}

::google::protobuf::uint8* ImageRequest::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ImageRecognitionServiceRPC.ImageRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->trans_id().data(), static_cast<int>(this->trans_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageRequest.trans_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->trans_id(), target);
  }

  // string image = 2;
  if (this->image().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->image().data(), static_cast<int>(this->image().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageRequest.image");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->image(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ImageRecognitionServiceRPC.ImageRequest)
  return target;
}

size_t ImageRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ImageRecognitionServiceRPC.ImageRequest)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->trans_id());
  }

  // string image = 2;
  if (this->image().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->image());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ImageRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ImageRecognitionServiceRPC.ImageRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const ImageRequest* source =
      ::google::protobuf::DynamicCastToGenerated<ImageRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ImageRecognitionServiceRPC.ImageRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ImageRecognitionServiceRPC.ImageRequest)
    MergeFrom(*source);
  }
}

void ImageRequest::MergeFrom(const ImageRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ImageRecognitionServiceRPC.ImageRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.trans_id().size() > 0) {

    trans_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.trans_id_);
  }
  if (from.image().size() > 0) {

    image_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.image_);
  }
}

void ImageRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ImageRecognitionServiceRPC.ImageRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ImageRequest::CopyFrom(const ImageRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ImageRecognitionServiceRPC.ImageRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ImageRequest::IsInitialized() const {
  return true;
}

void ImageRequest::Swap(ImageRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ImageRequest::InternalSwap(ImageRequest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  trans_id_.Swap(&other->trans_id_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  image_.Swap(&other->image_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata ImageRequest::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_image_5frecognition_5fservice_2eproto);
  return ::file_level_metadata_image_5frecognition_5fservice_2eproto[kIndexInFileMessages];
}


// ===================================================================

void ImageResponse::InitAsDefaultInstance() {
}
class ImageResponse::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ImageResponse::kTransIdFieldNumber;
const int ImageResponse::kStateFieldNumber;
const int ImageResponse::kTextFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ImageResponse::ImageResponse()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ImageRecognitionServiceRPC.ImageResponse)
}
ImageResponse::ImageResponse(const ImageResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  trans_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.trans_id().size() > 0) {
    trans_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.trans_id_);
  }
  text_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.text().size() > 0) {
    text_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
  state_ = from.state_;
  // @@protoc_insertion_point(copy_constructor:ImageRecognitionServiceRPC.ImageResponse)
}

void ImageResponse::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_ImageResponse_image_5frecognition_5fservice_2eproto.base);
  trans_id_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  text_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  state_ = 0;
}

ImageResponse::~ImageResponse() {
  // @@protoc_insertion_point(destructor:ImageRecognitionServiceRPC.ImageResponse)
  SharedDtor();
}

void ImageResponse::SharedDtor() {
  trans_id_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  text_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ImageResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ImageResponse& ImageResponse::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_ImageResponse_image_5frecognition_5fservice_2eproto.base);
  return *internal_default_instance();
}


void ImageResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:ImageRecognitionServiceRPC.ImageResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  trans_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  text_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  state_ = 0;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* ImageResponse::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<ImageResponse*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string trans_id = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("ImageRecognitionServiceRPC.ImageResponse.trans_id");
        object = msg->mutable_trans_id();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // .ImageRecognitionServiceRPC.ImageResponse.State state = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 16) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_state(static_cast<::ImageRecognitionServiceRPC::ImageResponse_State>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // string text = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 26) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("ImageRecognitionServiceRPC.ImageResponse.text");
        object = msg->mutable_text();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool ImageResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ImageRecognitionServiceRPC.ImageResponse)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string trans_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_trans_id()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->trans_id().data(), static_cast<int>(this->trans_id().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ImageRecognitionServiceRPC.ImageResponse.trans_id"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .ImageRecognitionServiceRPC.ImageResponse.State state = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (16 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_state(static_cast< ::ImageRecognitionServiceRPC::ImageResponse_State >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string text = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (26 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->text().data(), static_cast<int>(this->text().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "ImageRecognitionServiceRPC.ImageResponse.text"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ImageRecognitionServiceRPC.ImageResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ImageRecognitionServiceRPC.ImageResponse)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void ImageResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ImageRecognitionServiceRPC.ImageResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->trans_id().data(), static_cast<int>(this->trans_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageResponse.trans_id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->trans_id(), output);
  }

  // .ImageRecognitionServiceRPC.ImageResponse.State state = 2;
  if (this->state() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->state(), output);
  }

  // string text = 3;
  if (this->text().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->text().data(), static_cast<int>(this->text().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageResponse.text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->text(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ImageRecognitionServiceRPC.ImageResponse)
}

::google::protobuf::uint8* ImageResponse::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ImageRecognitionServiceRPC.ImageResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->trans_id().data(), static_cast<int>(this->trans_id().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageResponse.trans_id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->trans_id(), target);
  }

  // .ImageRecognitionServiceRPC.ImageResponse.State state = 2;
  if (this->state() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->state(), target);
  }

  // string text = 3;
  if (this->text().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->text().data(), static_cast<int>(this->text().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "ImageRecognitionServiceRPC.ImageResponse.text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->text(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ImageRecognitionServiceRPC.ImageResponse)
  return target;
}

size_t ImageResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ImageRecognitionServiceRPC.ImageResponse)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string trans_id = 1;
  if (this->trans_id().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->trans_id());
  }

  // string text = 3;
  if (this->text().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->text());
  }

  // .ImageRecognitionServiceRPC.ImageResponse.State state = 2;
  if (this->state() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->state());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ImageResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ImageRecognitionServiceRPC.ImageResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const ImageResponse* source =
      ::google::protobuf::DynamicCastToGenerated<ImageResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ImageRecognitionServiceRPC.ImageResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ImageRecognitionServiceRPC.ImageResponse)
    MergeFrom(*source);
  }
}

void ImageResponse::MergeFrom(const ImageResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ImageRecognitionServiceRPC.ImageResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.trans_id().size() > 0) {

    trans_id_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.trans_id_);
  }
  if (from.text().size() > 0) {

    text_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.text_);
  }
  if (from.state() != 0) {
    set_state(from.state());
  }
}

void ImageResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ImageRecognitionServiceRPC.ImageResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ImageResponse::CopyFrom(const ImageResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ImageRecognitionServiceRPC.ImageResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ImageResponse::IsInitialized() const {
  return true;
}

void ImageResponse::Swap(ImageResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ImageResponse::InternalSwap(ImageResponse* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  trans_id_.Swap(&other->trans_id_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  text_.Swap(&other->text_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(state_, other->state_);
}

::google::protobuf::Metadata ImageResponse::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_image_5frecognition_5fservice_2eproto);
  return ::file_level_metadata_image_5frecognition_5fservice_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ImageRecognitionServiceRPC
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::ImageRecognitionServiceRPC::ImageRequest* Arena::CreateMaybeMessage< ::ImageRecognitionServiceRPC::ImageRequest >(Arena* arena) {
  return Arena::CreateInternal< ::ImageRecognitionServiceRPC::ImageRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::ImageRecognitionServiceRPC::ImageResponse* Arena::CreateMaybeMessage< ::ImageRecognitionServiceRPC::ImageResponse >(Arena* arena) {
  return Arena::CreateInternal< ::ImageRecognitionServiceRPC::ImageResponse >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>