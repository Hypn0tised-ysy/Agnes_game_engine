cmake_minimum_required(VERSION 3.20)
project(Agnes_game_engine LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(agnes_warnings INTERFACE)

target_compile_options(agnes_warnings INTERFACE
  $<$<CXX_COMPILER_FRONTEND_VARIANT:GNU>:
    -Wall -Wextra
    -Wno-c++98-compat -Wno-c++98-compat-pedantic
    -Wno-padded
  >
  $<$<CXX_COMPILER_FRONTEND_VARIANT:MSVC>:
    /W4
    /wd4820
  >
)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Common")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")
#暂时不考虑windows以外的平台
#所以暂时不加条件编译
include_directories("${PROJECT_SOURCE_DIR}/Platform/Windows")

add_subdirectory(Framework)
add_subdirectory(Platform)
