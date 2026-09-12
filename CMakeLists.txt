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


# include libraries & files
## server
add_library(server src/server/server.c)
target_include_directories(server PUBLIC include)

## file parser
add_library(file_parser src/parser/file_parser.c)
target_include_directories(file_parser PUBLIC include)

## route handler 
add_library(route_handler src/routes/route_handler.c)
target_include_directories(route_handler PUBLIC include)

## defined routes
add_library(routes src/routes/routes.c)
target_include_directories(routes PUBLIC include)

# linking libraries
target_link_libraries(route_handler PRIVATE routes)
target_link_libraries(server PRIVATE routes)

# main file
add_executable(
	HttpServer	# name
	src/main.c  # main file
)


# include html directory
target_include_directories(HttpServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/html)


# linker 
target_link_libraries(
	HttpServer 
	PRIVATE

	server	
	file_parser
	route_handler
	routes
)
