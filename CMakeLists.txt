cmake_minimum_required(VERSION 3.20)

project(hello_erpc LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(erpc REQUIRED)

add_executable(hello_erpc
	src/main.cc
	src/c_erpc_matrix_multiply_client.cpp
	src/erpc_matrix_multiply_client.cpp
	# src/erpc_matrix_multiply_common.cpp
	src/erpc_matrix_multiply_interface.cpp
)

target_link_libraries(hello_erpc PUBLIC
	erpc
)
target_include_directories(hello_erpc PUBLIC
	$<BUILD_INTERFACE:${ERPC_INCLUDE_DIR}>
)
target_include_directories(hello_erpc PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)