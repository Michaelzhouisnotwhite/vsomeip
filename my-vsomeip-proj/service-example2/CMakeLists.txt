project(service-example2)
add_executable(service-example2 ./service-example.cpp)
target_link_libraries(service-example2 vsomeip3 ${Boost_LIBRARIES})

add_dependencies(my-vsomeip-proj ${PROJECT_NAME})