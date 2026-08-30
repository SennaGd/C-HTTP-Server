cmake_minimum_required(VERSION 4.4)

project(
	HttpServer 

	VERSION		1.0 
	DESCRIPTION	"A simple html/css language server" 
	LANGUAGES	C
)

# cmake configs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)


# main file
add_executable(
	HttpServer	# name
	src/main.c  # main file
)


# include libraries & files
add_library(server src/server/server.c)
target_include_directories(server PUBLIC include)

add_library(parser src/parser/parser.c)
target_include_directories(parser PUBLIC include)


# include html directory
target_include_directories(HttpServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/html)


# linker 
target_link_libraries(
	HttpServer 
	PRIVATE

	server	
	parser
)
