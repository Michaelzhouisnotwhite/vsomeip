#include <iomanip>
#include <iostream>
#include <sstream>
#include <vsomeip/vsomeip.hpp>

/**
- You didn't configure a client ID for your application;
therefore a vsomeip feature, the auto-configuration, finds an appropriate client ID.
The first number is 0x0001.

- There is also no configuration for the routing manager;
therefore the routing manager is automatically started with
the first vsomeip application in the system and this is service-example.

- By default is the Service Discovery enabled, no static routing.
This would need some configuration parameters.

- The last init()output is Application(World, 1) is initialized (11, 100).
The two numbers at the end mean that the maximum numbers of dispatchers vsomeip uses is 11 if a
callback blocks for more than 100ms. These parameters can be configured.

- By default two threads are created for receiving SOME/IP messages;
this allows vsomeip to handle long messages in parallel.

- Then you see the current vsomeip version and the SOME/IP routing is ready.
*/

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678
#define SAMPLE_METHOD_ID 0x0421

void OnMessage(const std::shared_ptr<vsomeip_v3::application>& app,
               const std::shared_ptr<vsomeip::message>& _request) {
  std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
  vsomeip::length_t l = its_payload->get_length();

  // Get payload
  std::stringstream ss;
  for (vsomeip::length_t i = 0; i < l; i++) {
    ss << std::setw(2) << std::setfill('0') << std::hex << (int)*(its_payload->get_data() + i)
       << " ";
  }

  std::cout << "SERVICE: Received message with Client/Session [" << std::setw(4)
            << std::setfill('0') << std::hex << _request->get_client() << "/" << std::setw(4)
            << std::setfill('0') << std::hex << _request->get_session() << "] " << ss.str() << '\n';

  // Create response
  std::shared_ptr<vsomeip::message> its_response =
      vsomeip::runtime::get()->create_response(_request);
  its_payload = vsomeip::runtime::get()->create_payload();
  std::vector<vsomeip::byte_t> its_payload_data;
  for (int i = 9; i >= 0; i--) {
    its_payload_data.push_back(i % 256);
  }
  its_payload->set_data(its_payload_data);
  its_response->set_payload(its_payload);
  app->send(its_response);
}
int main() {
  auto app = vsomeip::runtime::get()->create_application("World");
  app->init();
  app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID,
                                [app](auto&& PH1) {
                                  return OnMessage(app, std::forward<decltype(PH1)>(PH1));
                                });
  app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
  app->start();
  return 0;
}