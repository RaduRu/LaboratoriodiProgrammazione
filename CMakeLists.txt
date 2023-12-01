cmake_minimum_required(VERSION 3.21)
project(LaboratoriodiProgrammazione)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES Observer.h Subject.h  ShoppingList.cpp ShoppingList.h ShoppingItem.cpp ShoppingItem.h User.cpp User.h Date.cpp Date.h)

add_executable(LaboratoriodiProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratoriodiProgrammazione core)


