project(Sandbox)

# Define source files for Sandbox
file(GLOB_RECURSE SANDBOX_SOURCES
        "src/*.cpp"
        "src/*.h"
)

# Create executable
add_executable(Sandbox ${SANDBOX_SOURCES})

# Add necessary definitions
target_compile_definitions(Sandbox PRIVATE
        HZ_PLATFORM_WINDOWS
)

# Link against Hazel DLL
target_link_libraries(Sandbox PRIVATE Hazel)

# Set output directory to bin
set_target_properties(Sandbox PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin"
)

# Add Hazel's include directories to Sandbox
target_include_directories(Sandbox PRIVATE
        ${CMAKE_SOURCE_DIR}/Hazel/src
)

# Add post-build command to copy Hazel DLL next to Sandbox executable if needed
add_custom_command(TARGET Sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/bin/$<TARGET_FILE_NAME:Hazel>"
        "${CMAKE_SOURCE_DIR}/bin"
)