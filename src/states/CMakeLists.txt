set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
  states
  Game.h
  Game.cpp
  Instructions.h
  Instructions.cpp
  MainMenu.h
  MainMenu.cpp
  StageSelect.h
  StageSelect.cpp
  Victory.h
  Victory.cpp
)

target_include_directories(
  states PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/states"
)
