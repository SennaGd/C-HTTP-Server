cmake_minimum_required(VERSION 4.4)

project(
	HttpServer 

	VERSION		1.0 
	DESCRIPTION	"A simple html/css language server" 
	LANGUAGES	C
)

# main file
add_executable(
	HttpServer	# name
	src/main.c  # main file
)

# cmake configs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# include libraries & files
add_library(server src/server/server.c)
add_library(parser src/parser/parser.c)

target_include_directories(server PUBLIC include)
target_include_directories(parser PUBLIC include)

# linker 
target_link_libraries(
	HttpServer 
	PRIVATE

	server	
)
