cmake_minimum_required(VERSION 3.21)
project(LaboratoriodiProgrammazione)

set(CMAKE_CXX_STANDARD 20)

add_executable(LaboratoriodiProgrammazione main.cpp Subject.cpp Subject.h Observer.cpp Observer.h ShoppingList.cpp ShoppingList.h ShoppingItem.cpp ShoppingItem.h User.cpp User.h)
