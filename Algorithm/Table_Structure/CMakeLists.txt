cmake_minimum_required(VERSION 3.23)
project(Table_Structure C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(LinearTable/SequenceTable)
add_subdirectory(LinearTable/ChainTable)

add_subdirectory(Special_LinearTable/Queue/ArrayQueue)
add_subdirectory(Special_LinearTable/Queue/LinkedQueue)
add_subdirectory(Special_LinearTable/Stack/ArrayStack)
add_subdirectory(Special_LinearTable/Stack/ListNode)