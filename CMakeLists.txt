cmake_minimum_required(VERSION 3.20)

project(wx_hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(wx_hello src/main.cpp)
target_link_libraries(wx_hello PRIVATE ${wxWidgets_LIBRARIES})

