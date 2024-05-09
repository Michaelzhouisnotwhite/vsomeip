project(subscribe-notify)
add_executable(service-notify ./service.cpp)
add_executable(client-subscribe ./client.cpp)
target_link_libraries(service-notify vsomeip3 ${Boost_LIBRARIES})
target_link_libraries(client-subscribe vsomeip3 ${Boost_LIBRARIES})

add_dependencies(my-vsomeip-proj service-notify client-subscribe )  