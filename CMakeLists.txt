cmake_minimum_required(VERSION 3.21)
project(LaboratoriodiProgrammazione)

set(CMAKE_CXX_STANDARD 23)
set(SOURCE_FILES Observer.h Subject.h  ShoppingList.cpp ShoppingList.h ShoppingItem.h User.cpp User.h)

add_subdirectory(test)

set(SOURCE_FILES Observer.h ShoppingItem.h ShoppingList.cpp ShoppingList.h User.cpp User.h)
add_executable(LaboratoriodiProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratoriodiProgrammazione core)


