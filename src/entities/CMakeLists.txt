set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  entities
  Boulder.h
  Boulder.cpp
  Pit.h
  Pit.cpp
  Player.h
  Player.cpp
  Tile.h
  Wall.h
)

target_include_directories(
  entities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/entities"
)
