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
int main() {
  auto app = vsomeip::runtime::get()->create_application("World");
  app->init();
  app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
  app->start();
  return 0;
}