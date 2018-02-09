cmake_minimum_required(VERSION 3.9)
project(tugas3)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(tugas3 main.cpp Kamus.cpp Kamus.h Model.cpp Model.h operasi/PengubahKata.cpp operasi/PengubahKata.h operasi/PenerjemahKalimat.cpp operasi/PenerjemahKalimat.h operasi/PenampilStruktur.cpp operasi/PenampilStruktur.h operasi/PenghapusKata.cpp operasi/PenghapusKata.h operasi/PenambahKata.cpp operasi/PenambahKata.h)