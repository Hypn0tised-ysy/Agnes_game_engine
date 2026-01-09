add_library(Common
BaseApplication.cpp
main.cpp
GraphicsManager.cpp
Allocator.cpp
MemoryManager.cpp
)

target_link_libraries(Common PUBLIC agnes_warnings)

