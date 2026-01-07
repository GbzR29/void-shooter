cmake_minimum_required(VERSION 4.2.1)

project(void_shooter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# determines the build type (Debug by default)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Setting up the build for: ${CMAKE_BUILD_TYPE}")

# configures paths based on the Build Type.
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/sfml-release")
    set(SFML_STATIC_LIBRARIES ON)
    add_compile_definitions(SFML_STATIC)
else()
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/sfml-debug")
    set(SFML_STATIC_LIBRARIES OFF) 
endif()

# points to the SFML configuration folder.
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")

# locate the SFML
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio Network)

# executable
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(void-shooter ${SRC_FILES})

target_compile_features(void-shooter PRIVATE cxx_std_23)
set(CMAKE_CXX_EXTENSIONS OFF)

get_property(CXX_STANDARD TARGET void-shooter PROPERTY CXX_STANDARD)
message(STATUS "C++ standard used by void-shooter = C++${CXX_STANDARD}")


target_include_directories(void-shooter PRIVATE ${CMAKE_SOURCE_DIR}/include)

# linking
target_link_libraries(void-shooter PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
    SFML::Network
)

# Copy DLLs (Only if it's not static)
if(WIN32 AND NOT SFML_STATIC_LIBRARIES)
    # find the actual DLL files on the disk.
    file(GLOB SFML_DLL_FILES "${SFML_ROOT}/bin/*.dll")

    # check for anything that could prevent errors in the command.
    if(SFML_DLL_FILES)
        add_custom_command(TARGET void-shooter POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${SFML_DLL_FILES}
            $<TARGET_FILE_DIR:void-shooter>
            COMMENT "Copying DLLs from SFML to the output folder..."
            COMMAND_EXPAND_LISTS
        )
    endif()
endif()