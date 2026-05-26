cmake_minimum_required(VERSION 3.28)
project(Pong_Engine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#[[include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

FetchContent_MakeAvailable(SFML)
]]

# If you have a local SFML installation under the repository (e.g. <repo>/external/SFML),
# prefer that when searching for the package. Users can override SFML_ROOT or
# CMAKE_PREFIX_PATH to point to a different SFML installation.
add_subdirectory(external/SFML)


add_executable(main)
target_sources(main 
    PRIVATE
        "src/main.cpp"
        "src/entity.cpp"
        "src/game.cpp"
        "src/shape.cpp"

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS 
            include
        FILES
            include/entity.h
            include/game.h
            include/shape.h
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
