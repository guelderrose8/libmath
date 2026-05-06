cmake_minimum_required(VERSION 3.10)

project(libmath LANGUAGES CXX)

add_library(math INTERFACE)

target_include_directories(math
	INTERFACE
	    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

option(ENABLE_CLANG_FORMAT "Enable clang-format" OFF)

if(ENABLE_CLANG_FORMAT)
	find_program(CLANG_FORMAT_PATH NAMES clang-format-19 clang-format REQUIRED)
	message(STATUS "Found clang-format: ${CLANG_FORMAT_PATH}")

	file(GLOB_RECURSE CLANG_FORMAT_SRC CONFIGURE_DEPENDS
		include/*.h
	)

	add_custom_target(libmath-clang-format-target
	    COMMAND
		${CLANG_FORMAT_PATH} -style=file -i ${CLANG_FORMAT_SRC}
	    WORKING_DIRECTORY
	    	${CMAKE_SOURCE_DIR}
	    COMMENT
	    	"Formatting with ${CLANG_FORMAT_PATH} ..."
	)
endif()
