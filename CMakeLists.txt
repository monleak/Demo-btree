project(Phonebook)

cmake_minimum_required(VERSION 3.10.2)

add_executable(phone-bt phonebook-bt.c)

add_subdirectory(cmake-btree)

target_link_libraries(phone-bt bt)