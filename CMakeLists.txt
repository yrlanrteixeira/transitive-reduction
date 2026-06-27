cmake_minimum_required(VERSION 3.16)

project(TransitiveReduction LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

add_library(common OBJECT
    src/caminhamento.cpp
    src/gerador_dag.cpp
    src/grafo.cpp
    src/grafo_io.cpp
    src/reducao_transitiva.cpp
    src/verificador.cpp
)

target_include_directories(common PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(reducao_transitiva
    apps/reducao_main.cpp
)

target_link_libraries(reducao_transitiva
    PRIVATE common
)

add_executable(gerador
    apps/gerador_main.cpp
)

target_link_libraries(gerador
    PRIVATE common
)

add_executable(verificador
    apps/verificador_main.cpp
)

target_link_libraries(verificador
    PRIVATE common
)
