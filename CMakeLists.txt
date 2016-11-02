cmake_minimum_required(VERSION 3.6)
project(password_cracker_gamacy)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -lcrypt -lpthread -lrt")

set(SOURCE_FILES
        main.c
        string.c
        string.h
        thread.c
        thread.h
        threadprivate.h)

add_executable(crack ${SOURCE_FILES})

set(SOURCE_FILES
        hash.c)

add_executable(hash ${SOURCE_FILES})

set(SOURCE_FILES
        stringtest.c
        string.c)

add_executable(stringtest ${SOURCE_FILES})