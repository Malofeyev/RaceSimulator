add_library(game SHARED Game.cpp)

set_target_properties(transport PROPERTIES 
    POSITION_INDEPENDENT_CODE True
)

target_compile_definitions(game PRIVATE "EXPORTING_GAME")

target_link_libraries(game PRIVATE transport)

target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR})

