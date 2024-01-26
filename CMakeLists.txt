cmake_minimum_required(VERSION 3.26)
project(Estructuras_de_Datos)

set(CMAKE_CXX_STANDARD 14)

include_directories("Polizas Objets")

add_executable(Estructuras_de_Datos
        "Polizas Objets/automovile.h"
        "Polizas Objets/house.h"
        "Polizas Objets/life.h"
        "Polizas Objets/main.cpp"
        "Polizas Objets/user.h")
