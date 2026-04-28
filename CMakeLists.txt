cmake_minimum_required(VERSION 3.10)

project(libmath)

add_library(math SHARED
	src/libmath.cpp
)

target_include_directories(math
	PUBLIC
	    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS math
	LIBRARY DESTINATION /usr/local/lib
)

install(FILES include/libmath.h
	DESTINATION /usr/local/include
)

option(ENABLE_CLANG_FORMAT "Enable clang-format" OFF)
if(ENABLE_CLANG_FORMAT)
	find_program(CLANG_FORMAT_PATH NAMES clang-format-19 clang-format REQUIRED)
	message (STATUS "Found clang-format: ${CLANG_FORMAT_PATH}")

	file(GLOB_RECURSE CLANG_FORMAT_SRC CONFIGURE_DEPENDS
		include/*.h
		src/*.cpp
	)

	add_custom_target(clang-format-target
	    COMMAND
		${CLANG_FORMAT_PATH} -style=file -i ${CLANG_FORMAT_SRC}
	    WORKING_DIRECTORY
	    	${CMAKE_SOURCE_DIR}
	    COMMENT
	    	"Formatting with ${CLANG_FORMAT_PATH} ..."
	)

	add_dependencies(math clang-format-target)
endif()

