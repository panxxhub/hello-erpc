cmake_minimum_required(VERSION 3.20)

project(hello_erpc LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

find_program(MAKE_EXECUTABLE NAMES make REQUIRED)
# external project add erpc
include(ExternalProject)
ExternalProject_Add(my_erpc
	GIT_REPOSITORY  "https://github.com/EmbeddedRPC/erpc.git"
	GIT_TAG        	"1.13.0"
	SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/my_erpc
	CONFIGURE_COMMAND ""
	BUILD_COMMAND   ${MAKE_EXECUTABLE} -C ${CMAKE_CURRENT_BINARY_DIR}/my_erpc/erpc_c
	INSTALL_COMMAND ${MAKE_EXECUTABLE} -C ${CMAKE_CURRENT_BINARY_DIR}/my_erpc/erpc_c install PREFIX=${CMAKE_CURRENT_BINARY_DIR}/erpc
) 


add_executable(hello_erpc
	src/main.cc
	src/c_erpc_matrix_multiply_client.cpp
	src/erpc_matrix_multiply_client.cpp
	# src/erpc_matrix_multiply_common.cpp
	src/erpc_matrix_multiply_interface.cpp
)
add_dependencies(hello_erpc my_erpc)

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# find_package(erpc REQUIRED)

target_link_libraries(hello_erpc PRIVATE erpc)
target_link_directories(hello_erpc PRIVATE $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/erpc/lib>)
target_include_directories(hello_erpc PUBLIC $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/erpc/include/erpc>)
target_include_directories(hello_erpc PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
