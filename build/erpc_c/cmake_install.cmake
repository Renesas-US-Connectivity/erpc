# Install script for directory: /home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpc_c/liberpc.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/erpc" TYPE FILE FILES
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/config/erpc_config.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_arbitrated_client_manager.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_basic_codec.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_client_manager.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_codec.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_crc16.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_common.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_version.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_framed_transport.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_manually_constructed.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_message_buffer.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_message_loggers.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_server.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_static_queue.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_transport_arbitrator.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_transport.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_utils.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_client_server_common.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/infra/erpc_pre_post_action.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/port/erpc_setup_extensions.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/port/erpc_config_internal.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/port/erpc_port.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/port/erpc_threading.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/port/erpc_serial.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/setup/erpc_arbitrated_client_setup.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/setup/erpc_client_setup.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/setup/erpc_mbf_setup.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/setup/erpc_server_setup.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/setup/erpc_transport_setup.h"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/transports/erpc_inter_thread_buffer_transport.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/transports/erpc_serial_transport.hpp"
    "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpc_c/transports/erpc_tcp_transport.hpp"
    )
endif()

