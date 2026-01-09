cmake_minimum_required(VERSION 3.20)
project(Agnes_game_engine LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(agnes_warnings INTERFACE)

# clang / gcc 风格（不是 clang-cl）
target_compile_options(agnes_warnings INTERFACE
  $<$<CXX_COMPILER_ID:Clang,GNU>:
    -Wall -Wextra
    -Wno-c++98-compat -Wno-c++98-compat-pedantic
    -Wno-padded
  >
)

# MSVC / clang-cl 风格
target_compile_options(agnes_warnings INTERFACE
  $<$<BOOL:${MSVC}>:
    /W4
    /wd4820   # padding（如果你想关 MSVC 的 padding 提示）
  >
)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Common")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")

add_subdirectory(Framework)
add_subdirectory(Empty)
#add_subdirectory(Platform)
