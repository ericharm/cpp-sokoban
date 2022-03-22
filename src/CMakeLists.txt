set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  src
  CollisionManager.h
  CollisionManager.cpp
  Color.h
  Entity.h
  Entity.cpp
  EntityType.h
  Level.h
  Level.cpp
  MenuOption.h
  Point.h
  Point.cpp
  ScreenPosition.h
  ScreenPosition.cpp
  State.h
  StateStack.h
  StateStack.cpp
  )

target_include_directories(
  src PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
  )
