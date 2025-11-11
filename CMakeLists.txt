cmake_minimum_required(VERSION 3.10)
project(CryptoArbitrageDetector)            

set(CMAKE_CXX_STANDARD 23)                  

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(CURL REQUIRED)

target_link_libraries(${PROJECT_NAME} CURL::libcurl)