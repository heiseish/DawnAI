// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: converse_service.proto

#include "converse_service.pb.h"
#include "converse_service.grpc.pb.h"

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
namespace ConverseServiceGRPC {

static const char* ConverseService_method_names[] = {
  "/ConverseServiceGRPC.ConverseService/RespondToText",
};

std::unique_ptr< ConverseService::Stub> ConverseService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ConverseService::Stub> stub(new ConverseService::Stub(channel));
  return stub;
}

ConverseService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_RespondToText_(ConverseService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ConverseService::Stub::RespondToText(::grpc::ClientContext* context, const ::ConverseServiceGRPC::ConversationInput& request, ::ConverseServiceGRPC::ConversationResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_RespondToText_, context, request, response);
}

void ConverseService::Stub::experimental_async::RespondToText(::grpc::ClientContext* context, const ::ConverseServiceGRPC::ConversationInput* request, ::ConverseServiceGRPC::ConversationResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RespondToText_, context, request, response, std::move(f));
}

void ConverseService::Stub::experimental_async::RespondToText(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::ConverseServiceGRPC::ConversationResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_RespondToText_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::ConverseServiceGRPC::ConversationResponse>* ConverseService::Stub::AsyncRespondToTextRaw(::grpc::ClientContext* context, const ::ConverseServiceGRPC::ConversationInput& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ConverseServiceGRPC::ConversationResponse>::Create(channel_.get(), cq, rpcmethod_RespondToText_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::ConverseServiceGRPC::ConversationResponse>* ConverseService::Stub::PrepareAsyncRespondToTextRaw(::grpc::ClientContext* context, const ::ConverseServiceGRPC::ConversationInput& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::ConverseServiceGRPC::ConversationResponse>::Create(channel_.get(), cq, rpcmethod_RespondToText_, context, request, false);
}

ConverseService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ConverseService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ConverseService::Service, ::ConverseServiceGRPC::ConversationInput, ::ConverseServiceGRPC::ConversationResponse>(
          std::mem_fn(&ConverseService::Service::RespondToText), this)));
}

ConverseService::Service::~Service() {
}

::grpc::Status ConverseService::Service::RespondToText(::grpc::ServerContext* context, const ::ConverseServiceGRPC::ConversationInput* request, ::ConverseServiceGRPC::ConversationResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace ConverseServiceGRPC
