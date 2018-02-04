//
// Created by insan on 2/4/2018.
//

#ifndef TUGAS3_MODEL_H
#define TUGAS3_MODEL_H

using namespace std;

class Model {

public:
    Model();

    void ambil();

    unsigned char grafKamus[256*256];

private:
    bool tersedia(const char string[12]);

    int getPanjangGrafKamus();


};


#endif //TUGAS3_MODEL_H
