cmake_minimum_required (VERSION 3.5)

project (CodeGUI)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-Wall -g")

add_executable (CodeGUI sdlMain.cpp
	sdl/SDLWindowManager.cpp
	sdl/TextField.cpp
)

include (FindPkgConfig)

PKG_SEARCH_MODULE (SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE (SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE (SDL2TTF required SDL2_ttf>=2.0.0)

include_directories (${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
include_directories (sdl)
target_link_libraries (${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
