cmake_minimum_required(VERSION 3.10)

# Name of your project
project(weather-cli)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

# Add source files
add_executable(weather-cli src/main.cpp)

target_link_libraries(weather-cli
    PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
)