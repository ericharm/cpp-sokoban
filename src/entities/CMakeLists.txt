set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  entities
  Boulder.h
  Boulder.cpp
  Exit.h
  Pit.h
  Player.h
  Player.cpp
  Wall.h
)

target_include_directories(
  entities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/entities"
)
