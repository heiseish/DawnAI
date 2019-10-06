// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: image_classification_service.proto

#include "image_classification_service.pb.h"
#include "image_classification_service.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace ImageClassificationServiceRPC {

static const char* ImageClassificationService_method_names[] = {
  "/ImageClassificationServiceRPC.ImageClassificationService/RecognizeImage",
};

std::unique_ptr< ImageClassificationService::Stub> ImageClassificationService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ImageClassificationService::Stub> stub(new ImageClassificationService::Stub(channel));
  return stub;
}

ImageClassificationService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_RecognizeImage_(ImageClassificationService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ImageClassificationService::Stub::RecognizeImage(::grpc::ClientContext* context, const ::ImageClassificationServiceRPC::ImageRequest& request, ::ImageClassificationServiceRPC::ImageResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RecognizeImage_, context, request, response);
}

void ImageClassificationService::Stub::experimental_async::RecognizeImage(::grpc::ClientContext* context, const ::ImageClassificationServiceRPC::ImageRequest* request, ::ImageClassificationServiceRPC::ImageResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RecognizeImage_, context, request, response, std::move(f));
}

void ImageClassificationService::Stub::experimental_async::RecognizeImage(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ImageClassificationServiceRPC::ImageResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RecognizeImage_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ImageClassificationServiceRPC::ImageResponse>* ImageClassificationService::Stub::AsyncRecognizeImageRaw(::grpc::ClientContext* context, const ::ImageClassificationServiceRPC::ImageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ImageClassificationServiceRPC::ImageResponse>::Create(channel_.get(), cq, rpcmethod_RecognizeImage_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ImageClassificationServiceRPC::ImageResponse>* ImageClassificationService::Stub::PrepareAsyncRecognizeImageRaw(::grpc::ClientContext* context, const ::ImageClassificationServiceRPC::ImageRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ImageClassificationServiceRPC::ImageResponse>::Create(channel_.get(), cq, rpcmethod_RecognizeImage_, context, request, false);
}

ImageClassificationService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ImageClassificationService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ImageClassificationService::Service, ::ImageClassificationServiceRPC::ImageRequest, ::ImageClassificationServiceRPC::ImageResponse>(
          std::mem_fn(&ImageClassificationService::Service::RecognizeImage), this)));
}

ImageClassificationService::Service::~Service() {
}

::grpc::Status ImageClassificationService::Service::RecognizeImage(::grpc::ServerContext* context, const ::ImageClassificationServiceRPC::ImageRequest* request, ::ImageClassificationServiceRPC::ImageResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ImageClassificationServiceRPC
