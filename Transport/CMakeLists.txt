set(LAND_TRANSPORT_SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/Consts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/LandTransport.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/AllTerrainBoots.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/Camel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/Centaur.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Land/FastCamel.cpp
)

set(AIR_TRANSPORT_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Air/Consts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Air/AirTransport.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Air/Broom.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Air/Eagle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Air/MagicCarpet.cpp
)

add_library(transport STATIC Transport.cpp ${LAND_TRANSPORT_SRC} ${AIR_TRANSPORT_SRC})

target_include_directories(transport INTERFACE ${CMAKE_SOURCE_DIR})

