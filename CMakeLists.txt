cmake_minimum_required(VERSION 3.10)
project(lightaudio LANGUAGES C)

add_library(lightaudio)
add_library(lightaudio::lightaudio ALIAS lightaudio)

# Add source files
target_sources(lightaudio PRIVATE
		src/la_buffer.c
)
# Add headers
target_include_directories(lightaudio PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_compile_features(lightaudio PUBLIC c_std_11)

# Installation rules for system install
install(
	TARGETS lightaudio
	EXPORT lightaudioTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
)
install(
	DIRECTORY include/lightaudio
	DESTINATION include
)
install(
	EXPORT lightaudioTargets
	FILE lightaudioConfig.cmake
	NAMESPACE lightaudio::
	DESTINATION lib/cmake/lightaudio
)

# Export from the build tree
export(
	EXPORT lightaudioTargets
	FILE ${CMAKE_CURRENT_BINARY_DIR}/lightaudioConfig.cmake
	NAMESPACE lightaudio::
)

# Header-only version
add_library(lightaudio_header INTERFACE)
add_library(lightaudio::header_only ALIAS lightaudio_header)

target_include_directories(lightaudio_header INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

# ADD INSTALLATION RULES FOR HEADER-ONLY

