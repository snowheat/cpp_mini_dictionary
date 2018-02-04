cmake_minimum_required(VERSION 3.9)
project(tugas3)

set(CMAKE_CXX_STANDARD 11)

add_executable(tugas3 main.cpp Kamus.cpp Kamus.h Model.cpp Model.h operasi/PenambahKata.cpp operasi/PenambahKata.h operasi/PengubahKata.cpp operasi/PengubahKata.h operasi/PenerjemahKalimat.cpp operasi/PenerjemahKalimat.h operasi/PenampilStruktur.cpp operasi/PenampilStruktur.h operasi/PenghapusKata.cpp operasi/PenghapusKata.h)