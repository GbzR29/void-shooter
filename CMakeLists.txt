cmake_minimum_required(VERSION 4.2.1)

project(void_shooter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# --------------------------------------------------
# SFML selection
# --------------------------------------------------
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/sfml-release")
    set(SFML_STATIC_LIBRARIES ON)
    add_compile_definitions(SFML_STATIC)
else()
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/sfml-debug")
    set(SFML_STATIC_LIBRARIES OFF)
endif()

set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

# --------------------------------------------------
# Find SFML
# --------------------------------------------------
find_package(SFML 3 REQUIRED COMPONENTS
    Graphics Window System Audio Network
)

# --------------------------------------------------
# Executable
# --------------------------------------------------
file(GLOB_RECURSE SRC_FILES src/core/*.cpp)

add_executable(void-shooter ${SRC_FILES})

target_include_directories(void-shooter PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(void-shooter PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# --------------------------------------------------
# Copy DLLs (Debug only)
# --------------------------------------------------
if(WIN32 AND NOT SFML_STATIC_LIBRARIES)
    file(GLOB SFML_DLLS "${SFML_ROOT}/bin/*.dll")

    add_custom_command(TARGET void-shooter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLLS}
        $<TARGET_FILE_DIR:void-shooter>
    )
endif()
