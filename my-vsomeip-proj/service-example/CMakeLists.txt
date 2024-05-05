project(service-example)
add_executable(service-example ./service-example.cpp)
target_link_libraries(service-example vsomeip3 ${Boost_LIBRARIES})