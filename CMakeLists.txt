cmake_minimum_required(VERSION 3.16)

project(MonProjet)

find_package(Geant4 REQUIRED)

include(${Geant4_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

add_executable(MonProjet main.cc ${sources})

target_link_libraries(MonProjet ${Geant4_LIBRARIES})
