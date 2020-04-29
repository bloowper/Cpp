cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Window.cpp Window.h cmake_modules/main.cpp cmake_modules/main.h cmake_modules/Game.cpp cmake_modules/Game.h)
add_executable(Game ${SOURCE_FILES} Window.cpp Window.h)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
