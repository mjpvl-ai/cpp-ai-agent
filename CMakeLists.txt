cmake_minimum_required(VERSION 3.10)
project(cpp-ai-agent)

set(CMAKE_CXX_STANDARD 17)

find_package(FAISS REQUIRED)

include_directories(include)

add_library(cpp_ai_agent STATIC src/AIClient.cpp src/VectorDB.cpp src/Agent.cpp)

target_link_libraries(cpp_ai_agent PRIVATE faiss)

add_executable(ai_example examples/main.cpp)
target_link_libraries(ai_example PRIVATE cpp_ai_agent)

