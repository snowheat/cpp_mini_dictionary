//
// Created by insan on 2/4/2018.
//

#ifndef TUGAS3_PENAMBAHKATA_H
#define TUGAS3_PENAMBAHKATA_H

#include "../Model.h"

class PenambahKata {

public:
    PenambahKata();

    void ambilInput(Model *pModel);

    void ambilInput(char *kataInput, char *kata, char *teks);

    void tambahkanKataKeModel(char indonesia[50], char sunda[50], char inggris[50], Model *m);

private:

    void tulisKataKeKamus(char string1[50], int i, char string2[50], char string3[50], Model *m);
};


#endif //TUGAS3_PENAMBAHKATA_H
