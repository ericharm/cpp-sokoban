set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  entities
  Boulder.h
  Boulder.cpp
  Exit.h
  Exit.cpp
  Pit.h
  Pit.cpp
  Player.h
  Player.cpp
  Tile.h
  Wall.h
  Wall.cpp
)

target_include_directories(
  entities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/entities"
)
