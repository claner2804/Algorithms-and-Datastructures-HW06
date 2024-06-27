cmake_minimum_required(VERSION 3.28)
project(UEZ6)

set(CMAKE_CXX_STANDARD 17)

add_executable(UEZ6 binary_search.cpp
        linear_search.cpp
        bubble_sort.cpp
        insertion_sort.cpp
        recursive_insertion_sort.cpp
        selection_sort.cpp
        heap_sort.cpp
        bucket_sort.cpp
        merge_sort.cpp
        quick_sort.cpp
        shell_sort.cpp
        dynamic_array.cpp
        stack.cpp
        queue.cpp
        binary_tree.cpp
        hash_table.cpp)
