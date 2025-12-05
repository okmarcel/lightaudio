cmake_minimum_required(VERSION 3.10)
project(lightaudio LANGUAGES C)

add_library(lightaudio INTERFACE)

target_include_directories(lightaudio INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

install(DIRECTORY include/ DESTINATION include)

install(TARGETS lightaudio EXPORT lightaudioTargets)

install(EXPORT lightaudioTargets
        FILE lightaudioConfig.cmake
        NAMESPACE lightaudio::
        DESTINATION lib/cmake/lightaudio)

# Compile examples
file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.c")

foreach(EXAMPLE_FILE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_FILE} NAME_WE)

    add_executable(${EXAMPLE_NAME} ${EXAMPLE_FILE})

    target_link_libraries(${EXAMPLE_NAME} PRIVATE lightaudio)
    target_include_directories(${EXAMPLE_NAME} PRIVATE include)

    set_target_properties(${EXAMPLE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/examples
    )
endforeach()
