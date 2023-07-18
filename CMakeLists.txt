cmake_minimum_required(VERSION 3.8)
project(KeyloggerProject)

# Set C++ standard to C++11 or higher (adjust if needed)
set(CMAKE_CXX_STANDARD 11)

# Add the include directory to the project
include_directories(include)

# Add your keylog.cpp source file to the project
add_executable(Keylogger "src/main.cpp" "src/keylogger.cpp" "include/keylogger.h")
