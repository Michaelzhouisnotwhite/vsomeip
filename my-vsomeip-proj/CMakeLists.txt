cmake_minimum_required(VERSION 3.22)
project(my-vsome-ip-proj)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-g")

find_package(vsomeip3 3.4.10 REQUIRED)
find_package(Boost 1.55 COMPONENTS system thread log REQUIRED)

set(include_dirs
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(service-example)
add_subdirectory(service-example2)
add_subdirectory(client-example)
add_subdirectory(client-example2)
add_subdirectory(subscribe-notify)
