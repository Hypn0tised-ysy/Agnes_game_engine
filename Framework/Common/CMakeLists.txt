file(GLOB COMMON_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(Common ${COMMON_SOURCES})

target_link_libraries(Common PUBLIC agnes_warnings)

