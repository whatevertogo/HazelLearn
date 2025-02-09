project(Hazel)

# Define source files for Hazel
file(GLOB_RECURSE HAZEL_SOURCES
        "src/*.cpp"
        "src/*.h"
)

# Create shared library (DLL)
add_library(Hazel SHARED ${HAZEL_SOURCES})

# Define HAZEL_BUILD_DLL when building the DLL
target_compile_definitions(Hazel PRIVATE
        HAZEL_BUILD_DLL
        $<$<CONFIG:Debug>:HAZEL_DEBUG>
        $<$<CONFIG:Release>:HAZEL_RELEASE>
)

# Set include directories
target_include_directories(Hazel PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor
)

# Ensure DLL goes to the bin directory
set_target_properties(Hazel PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
)