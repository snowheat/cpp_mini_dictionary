//
// Created by insan on 2/3/2018.
//

#ifndef TUGAS3_KAMUS_H
#define TUGAS3_KAMUS_H


#include "Model.h"
#include "operasi/PenambahKata.h"
#include "operasi/PenerjemahKalimat.h"
#include "operasi/PengubahKata.h"
#include "operasi/PenghapusKata.h"
#include "operasi/PenampilStruktur.h"

class Kamus {
public:
    Kamus();
    void buka();

private:
    Model model;
    PenerjemahKalimat penerjemahKalimat;
    PenambahKata penambahKata;
    PengubahKata pengubahKata;
    PenghapusKata penghapusKata;
    PenampilStruktur penampilStruktur;

    int nomorMenu;

    void tampilkanMenu();
    void eksekusiMenu(int nomorMenu);


};


#endif //TUGAS3_KAMUS_H
