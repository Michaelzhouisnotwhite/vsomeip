project(client-example2)
add_executable(client-example2 ./client-example.cpp)
target_link_libraries(client-example2 vsomeip3 ${Boost_LIBRARIES})

add_dependencies(my-vsomeip-proj client-example2)
