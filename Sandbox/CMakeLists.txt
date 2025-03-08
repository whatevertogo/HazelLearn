project(Sandbox)

# 定义 Sandbox 的源文件
file(GLOB_RECURSE SANDBOX_SOURCES
        "src/*.cpp"
        "src/*.h"
)

# 创建可执行文件
add_executable(Sandbox ${SANDBOX_SOURCES})

#添加必要的定义
target_compile_definitions(Sandbox PRIVATE
        HZ_PLATFORM_WINDOWS
)

# 针对 Hazel DLL 的链接
target_link_libraries(Sandbox PRIVATE Hazel)

# 将输出目录设置为 bin
set_target_properties(Sandbox PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
)

# 将 Hazel 的 include 目录添加到 Sandbox
target_include_directories(Sandbox PRIVATE
        ${CMAKE_SOURCE_DIR}/Hazel/src
)

# 如果需要，添加构建后命令以将 Hazel DLL 复制到 Sandbox 可执行文件旁边
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/bin/$<TARGET_FILE_NAME:Hazel>"
        "${CMAKE_SOURCE_DIR}/bin"
)