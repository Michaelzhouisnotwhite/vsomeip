# Copyright (C) 2015-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(EXAMPLE_CONFIG_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip.json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip-local.json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip-tcp-client.json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip-tcp-service.json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip-udp-client.json"
    "${CMAKE_CURRENT_SOURCE_DIR}/../config/vsomeip-udp-service.json"
)

# Examples
add_executable(request-sample request-sample.cpp ${EXAMPLE_CONFIG_FILES})
target_link_libraries(request-sample ${VSOMEIP_NAME} ${Boost_LIBRARIES} ${DL_LIBRARY})

add_executable(response-sample response-sample.cpp ${EXAMPLE_CONFIG_FILES})
target_link_libraries(response-sample ${VSOMEIP_NAME} ${Boost_LIBRARIES} ${DL_LIBRARY})

add_executable(subscribe-sample subscribe-sample.cpp ${EXAMPLE_CONFIG_FILES})
target_link_libraries(subscribe-sample ${VSOMEIP_NAME} ${Boost_LIBRARIES} ${DL_LIBRARY})

add_executable(notify-sample notify-sample.cpp ${EXAMPLE_CONFIG_FILES})
target_link_libraries(notify-sample ${VSOMEIP_NAME} ${Boost_LIBRARIES} ${DL_LIBRARY})

add_dependencies(examples request-sample response-sample subscribe-sample notify-sample)

install(
    TARGETS request-sample response-sample subscribe-sample notify-sample
    RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
)

# ##################################################################################################
foreach(config_file ${EXAMPLE_CONFIG_FILES})
    make_directory("${CMAKE_BINARY_DIR}/config")
    message("${CMAKE_COMMAND} -E copy_if_different ${config_file} ${CMAKE_BINARY_DIR}/config")
    add_custom_command(TARGET request-sample POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${config_file} ${CMAKE_BINARY_DIR}/config)
endforeach()
