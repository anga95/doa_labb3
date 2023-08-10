cmake_minimum_required(VERSION 3.25)
project(labb3)

set(CMAKE_CXX_STANDARD 23)

add_executable(labb3
        main.cpp
        generate_primes.cpp
        generate_primes.h
        Timer.cpp
        Timer.h
        binary_search.cpp
        binary_search.h
        binary_search_tree.cpp
        binary_search_tree.h
        HashTable.h
        linear_search.cpp
        linear_search.h
        fileHandling.cpp
        fileHandling.h
        SearchData.h
        HashTable.cpp
        Measurement.cpp
        Measurement.h)
