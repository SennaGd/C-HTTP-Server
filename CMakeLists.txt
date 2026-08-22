cmake_minimum_required(VERSION 4.4)

project(
	HttpServer 

	VERSION		1.0 
	DESCRIPTION	"A simple html/css language server" 
	LANGUAGES	C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(server src/server.c)
add_library(file_parser src/file_parser.c)

target_include_directories(file_parser PUBLIC include)
target_include_directories(server PUBLIC include)

add_executable(
	HttpServer	

	src/main.c
)

target_link_libraries(
	HttpServer 
	PRIVATE

	server	
	file_parser	
)
