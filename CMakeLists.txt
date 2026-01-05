cmake_minimum_required(VERSION 4.2.1)

project(void_shooter
    VERSION 0.1.0
    LANGUAGES CXX
)

# --------------------------------------------------
# C++ standard
# --------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------------------------------------------
# Default build type (SAFE for MinGW + SFML)
# --------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# --------------------------------------------------
# SFML (local - MinGW)
# --------------------------------------------------
set(SFML_DIR "${CMAKE_SOURCE_DIR}/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS
    Graphics
    Window
    System
    Audio
    Network
)

# --------------------------------------------------
# Source files
# --------------------------------------------------
file(GLOB_RECURSE PROJECT_SOURCES
    src/core/*.cpp
)

# --------------------------------------------------
# Executable
# --------------------------------------------------
add_executable(void-shooter ${PROJECT_SOURCES})

# --------------------------------------------------
# Includes
# --------------------------------------------------
target_include_directories(void-shooter PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# --------------------------------------------------
# Link libraries (MODERN CMAKE)
# --------------------------------------------------
target_link_libraries(void-shooter PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# --------------------------------------------------
# Windows / MinGW system libs
# --------------------------------------------------
if(WIN32)
    target_link_libraries(void-shooter PRIVATE
        opengl32
        winmm
        gdi32
        ws2_32
    )
endif()

# --------------------------------------------------
# Copy SFML DLLs next to exe
# --------------------------------------------------
if(WIN32)
    file(GLOB SFML_DLLS
        "${CMAKE_SOURCE_DIR}/bin/*.dll"
    )

    add_custom_command(TARGET void-shooter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLLS}
        $<TARGET_FILE_DIR:void-shooter>
    )
endif()

