cmake_minimum_required(VERSION 3.10)
project(cpp_ai_agent)

set(CMAKE_CXX_STANDARD 17)

# Add llama.cpp
include_directories(${PROJECT_SOURCE_DIR}/external/llama.cpp/include)
include_directories(${PROJECT_SOURCE_DIR}/external/llama.cpp)
add_subdirectory(external/llama.cpp)

# Add your source files
add_library(cpp_ai_agent STATIC
    src/AIClient.cpp
    src/VectorDB.cpp
    src/Agent.cpp
)

# Link with llama.cpp
target_link_libraries(cpp_ai_agent PRIVATE llama)
