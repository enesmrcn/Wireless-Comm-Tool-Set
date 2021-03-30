cmake_minimum_required(VERSION 3.17)
project(linkBudgetToolSet C)

set(CMAKE_C_STANDARD 99)

add_executable(linkBudgetToolSet main.c linkBudget.h linkBudget.c)