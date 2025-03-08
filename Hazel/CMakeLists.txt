project(Hazel)

# 添加 UTF-8 编码支持
if(MSVC)
    add_compile_options(/utf-8 /wd4819)
    add_compile_definitions(_UNICODE UNICODE)
endif()

# 定义 Hazel 的源文件
file(GLOB_RECURSE HAZEL_SOURCES
        "src/*.cpp"
        "src/*.h"
)

# 创建共享库 （DLL）
add_library(Hazel SHARED ${HAZEL_SOURCES})


# 在构建 DLL 时定义 HAZEL_BUILD_DLL
target_compile_definitions(Hazel PRIVATE
        HAZEL_BUILD_DLL
        $<$<CONFIG:Debug>:HAZEL_DEBUG>
        $<$<CONFIG:Release>:HAZEL_RELEASE>
)

# 设置 include 目录
target_include_directories(Hazel PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

# 如果启用，则与 spdlog 链接
if(HAZEL_USE_SPDLOG)
    target_link_libraries(Hazel PRIVATE spdlog::spdlog)
endif()

# 确保 DLL 进入 bin 目录
set_target_properties(Hazel PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
)