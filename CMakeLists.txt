cmake_minimum_required(VERSION 3.20)
project(projeto_apa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(include)

add_executable(projeto_apa.exe src/main.cpp
        src/instancia_problema.cpp
        src/vizinhancas.cpp
        src/guloso.cpp
        src/solucao.cpp
        src/variableNeighborhoodDescent.cpp
        src/ils.cpp
        src/executeAll.cpp)

