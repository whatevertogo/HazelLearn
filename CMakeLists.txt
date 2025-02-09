# 指定所需的 CMake 最低版本
cmake_minimum_required(VERSION 3.14)

# 项目声明：设置项目名称、版本、描述和使用的语言
project(HazelLearn
        VERSION 0.1.0
        DESCRIPTION "Hazel Game Engine Learning Project"
        LANGUAGES CXX
)

# 配置选项：使用 option 命令设置可选功能
option(HAZEL_BUILD_SHARED "构建 Hazel 为动态库" ON)
option(HAZEL_BUILD_TESTS "构建 Hazel 测试" OFF)
option(HAZEL_USE_SPDLOG "使用 spdlog 作为日志系统" ON)

# 全局设置：设置 C++ 标准和相关要求
set(CMAKE_CXX_STANDARD 20)                # 使用 C++20 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)       # 强制要求使用指定的 C++ 标准
set(CMAKE_CXX_EXTENSIONS OFF)             # 禁用编译器特定的扩展

# Windows 平台特定设置
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)  # 导出所有符号
    add_compile_options(/utf-8)               # 启用 UTF-8 编码支持
endif()

# 设置默认输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")  # 可执行文件输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")  # 动态库输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")  # 静态库输出目录

# 为不同的构建类型（Debug/Release等）设置输出目录
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/bin")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/bin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}/bin")
endforeach()

# 确保输出目录存在
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# 处理外部依赖：如果启用了 spdlog
if(HAZEL_USE_SPDLOG)
    include(FetchContent)                     # 包含 FetchContent 模块
    FetchContent_Declare(                     # 声明 spdlog 依赖
            spdlog
            GIT_REPOSITORY https://github.com/gabime/spdlog.git
            GIT_TAG v1.x
    )
    FetchContent_MakeAvailable(spdlog)        # 下载并构建 spdlog
endif()

# 添加子项目：引擎核心和示例程序
add_subdirectory(Hazel)    # 添加 Hazel 引擎子项目
add_subdirectory(Sandbox)  # 添加 Sandbox 示例程序子项目