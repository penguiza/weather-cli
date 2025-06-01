# Weather CLI

A simple C++ command-line application that fetches weather data using HTTP requests.  
Built with [cpr](https://github.com/libcpr/cpr) for HTTP and [nlohmann_json](https://github.com/nlohmann/json) for JSON parsing.

---

## Features

- Fetches weather info from an API
- Demonstrates modern C++17, CMake, and third-party library integration

---

## Requirements

- C++ compiler (Visual Studio 2017+, GCC, Clang)
- [CMake](https://cmake.org/download/) (version 3.10 or higher)
- [vcpkg](https://github.com/microsoft/vcpkg) (recommended for dependency management)
- Libraries:
  - `cpr`
  - `nlohmann_json`

---

## Setup and Build Instructions

### 1. Install Dependencies with vcpkg (Windows example)

If you don’t have vcpkg installed, follow instructions here: https://github.com/microsoft/vcpkg#quick-start

Then, install dependencies:

```bash
vcpkg install cpr nlohmann-json
