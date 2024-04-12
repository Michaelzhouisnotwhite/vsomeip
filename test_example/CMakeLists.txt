cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g")
project(test-example)
find_package(vsomeip3 3.4.10 REQUIRED)
find_package(Boost 1.55 COMPONENTS system thread log REQUIRED)

add_executable(service-example ./src/service-example.cpp)
target_link_libraries(service-example vsomeip3 ${Boost_LIBRARIES})

target_include_directories(service-example PRIVATE
    ${Boost_INCLUDE_DIR}

    # ${VSOMEIP_INCLUDE_DIRS}
)
