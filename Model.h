//
// Created by insan on 2/4/2018.
//

#ifndef TUGAS3_MODEL_H
#define TUGAS3_MODEL_H

using namespace std;

class Model {

public:
    Model();

    unsigned char getGrafKamus(int i);
    void setGrafKamus(int i, int value);

    int getPointerKontenPertama();
    int getPointer();
    void setPointer(int value);

    int getPanjangGrafKamus();
    void ambil();

    int getPointerMulaiMenulis();
    void setPointerMulaiMenulis(int alamat);

    int getPointerHurufPertamaPeriksa();
    void setPointerHurufPertamaPeriksa(int alamat);

    int getPointerAlamatTujuan(int alamatA, int alamatB);
    void setPointerAlamatTujuan(int alamatA, int alamatB, int alamatTujuan);

    void tulisGrafKamusKeFile();

private:
    unsigned char grafKamus[256*256] = {};
    int pointer;

    bool tersedia(const char string[12]);

};


#endif //TUGAS3_MODEL_H
