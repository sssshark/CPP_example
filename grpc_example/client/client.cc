#include <iostream>
#include <grpcpp/grpcpp.h>
#include "proto/helloworld.grpc.pb.h"


using grpc::ChannelInterface;

class TestClient {
public:
    TestClient(std::shared_ptr<ChannelInterface> channel);

    std::string ClientFunc();
private:
    std::unique_ptr<grpc_example::TestService::Stub> stub_;

};

TestClient::TestClient(const std::shared_ptr<ChannelInterface> channel) : stub_(grpc_example::TestService::NewStub(channel)) {}

std::string TestClient::ClientFunc() {
    grpc_example::RequestMsg request;
    grpc_example::ResponseMsg reply;

    grpc::ClientContext context;

    grpc::Status status = stub_->TestFunction(&context, request, &reply);

    if (status.ok()) {
      return reply.response_id();
    } else {
      return "RPC failed";
    }    

}


int main() {
    std::string target_str = "localhost:50051";
    
    TestClient firstClient(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    // std::string user("world");
    std::string reply = firstClient.ClientFunc();
    std::cout << "firstClient received: " << reply << std::endl;

}