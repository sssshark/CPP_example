#include <grpcpp/grpcpp.h>
// #include "proto/helloworld.pb.h"
#include "proto/helloworld.grpc.pb.h"
// #include <grpcpp/ext/proto_server_reflection_plugin.h>

using grpc::Server;
using grpc_example::TestService;

class TestServiceImpl final : public TestService::Service {
    grpc::Status TestFunction(grpc::ServerContext* context, const grpc_example::RequestMsg* request, grpc_example::ResponseMsg* reply) {
        reply->set_reply_content("123");
        reply->set_response_id("ffff");
        return grpc::Status::OK;
    }
};

int main() {
    std::string server_address("0.0.0.0:50051");

    TestServiceImpl service;
    grpc::ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();

    std::cout<<"123"<<std::endl;
    return 0;
}
