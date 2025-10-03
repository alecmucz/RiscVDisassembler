cmake_minimum_required(VERSION 4.0)
project(rvdisasm C)

set(CMAKE_C_STANDARD 23)

add_executable(rvdisasm main.c
inc/registers.h
inc/instructions.h
inc/decode.h
inc/disasm.h

src/decode.c
src/disasm.c
        src/registers.c
)

