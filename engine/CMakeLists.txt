file(GLOB_RECURSE ENGINE_SOURCES "src/*.c" "src/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "include/*.h" "include/*.hpp")

set(GLAD_SOURCES
    ${CMAKE_SOURCE_DIR}/external/glad/src/glad.c
)
set(GLAD_INCLUDE
    ${CMAKE_SOURCE_DIR}/external/glad/include
)

add_library(lance STATIC
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
    ${GLAD_SOURCES}
)

target_include_directories(lance PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${GLAD_INCLUDE}
    ${CMAKE_SOURCE_DIR}/external/glm
    ${CMAKE_SOURCE_DIR}/external/glfw/include
)

target_link_libraries(lance PUBLIC glfw)
