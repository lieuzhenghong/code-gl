cmake_minimum_required (VERSION 3.5)

project (CodeGUI)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-Wall -g")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable (CodeGUI sdlMain.cpp
	sdl/SDLWindowManager.cpp
	sdl/TextField.cpp
	vm/Processor.cpp
	vm/MemoryUnit.cpp
	arch/Instruction.cpp
    compiler/Parser.cpp
	components/Screen.cpp
)

include (FindPkgConfig)

PKG_SEARCH_MODULE (SDL2 required sdl2)
PKG_SEARCH_MODULE (SDL2IMAGE required SDL2_image>=2.0.0)
PKG_SEARCH_MODULE (SDL2TTF required SDL2_ttf>=2.0.0)

include_directories (${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
target_link_libraries (${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})

include_directories (
	sdl
	vm
	arch
	compiler
	components
)
