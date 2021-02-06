cmake_minimum_required(VERSION 3.17)
project(c_linux_sockets_exp C)

set(CMAKE_C_STANDARD 99)

#add_executable(c_linux_sockets_exp list_adapters.c main.c)
add_executable(c_linux_sockets_exp utils/list_adapters.c)