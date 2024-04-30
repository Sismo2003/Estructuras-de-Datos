cmake_minimum_required(VERSION 3.26)
project(Estructuras_de_Datos)

set(CMAKE_CXX_STANDARD 20)

include_directories("Polizas Objets")

add_executable(Estructuras_de_Datos
        "Polizas Objets/automovile.h"
        "Polizas Objets/house.h"
        "Polizas Objets/life.h"
        "Polizas Objets/main.cpp"
        "Polizas Objets/user.h"
        "arreglo Lista/arreglo.cpp"
        "Tarea 4/arreglo.cpp"
        "Tarea 4/arreglo_lista.cpp"
        "Tarea 5/pila.h"
        node/node.cpp
        node/node.h
        test/directory.cpp
)
