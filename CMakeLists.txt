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

