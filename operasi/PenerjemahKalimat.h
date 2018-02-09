//
// Created by insan on 2/4/2018.
//

#ifndef TUGAS3_PENERJEMAH_H
#define TUGAS3_PENERJEMAH_H

#include "../Model.h"

class PenerjemahKalimat {

public:
    PenerjemahKalimat();

    void tampilkanMenu(Model *pKamus);

    void prosesKalimat(char pModel[50], Model *pModel1);

    void cariKata(char kata[100], Model *pModel);

    void terjemahkanKalimat(char kalimat[10][100], Model *pModel);

    void getKataSunda(char *kata, Model *m);

    void getKataInggris(char string[100], Model *pModel);
};


#endif //TUGAS3_PENERJEMAH_H
