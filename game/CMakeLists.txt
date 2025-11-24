file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")

add_executable(game ${GAME_SOURCES})

target_include_directories(game PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(game PRIVATE lance)
