project(client-example)
add_executable(client-example ./client-example.cpp)
target_link_libraries(client-example vsomeip3 ${Boost_LIBRARIES})

add_dependencies(my-vsomeip-proj ${PROJECT_NAME})
