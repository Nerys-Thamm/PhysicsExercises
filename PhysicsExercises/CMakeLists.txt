cmake_minimum_required(VERSION 3.0.0)
project(PhysicsExercises VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PhysicsExercises PhysicsExercises.cpp CVector.cpp)
LINK_DIRECTORIES(usr/lib)
find_package(SFML COMPONENTS system graphics window)
TARGET_LINK_LIBRARIES(PhysicsExercises sfml-system sfml-audio sfml-graphics sfml-window)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
