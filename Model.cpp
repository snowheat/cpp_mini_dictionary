//
// Created by insan on 2/4/2018.
//
#include <iostream>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include "Model.h"
#define FIRST_CONTENT_POINTER		10

using namespace std;

Model::Model() {
    cout << "model dibuat" << endl;
}

unsigned char Model::getGrafKamus(int i) {
    return grafKamus[i];
}

void Model::setGrafKamus(int i, int value) {
    grafKamus[i] = value;
}

int Model::getPointerKontenPertama() {
    int contentPointer = 256 * grafKamus[0] + FIRST_CONTENT_POINTER;
    return FIRST_CONTENT_POINTER;
}

int Model::getPointer(){
    return pointer;
}

void Model::setPointer(int value){
    pointer = value;
}

void Model::ambil() {

    FILE * file;

    if(!tersedia("kamus.model")) {
        grafKamus[0] = 0;
        grafKamus[1] = FIRST_CONTENT_POINTER;
        grafKamus[2] = 2;
        grafKamus[3] = 0;
        grafKamus[4] = FIRST_CONTENT_POINTER;
        grafKamus[5] = 2;
        grafKamus[6] = 2;
        grafKamus[7] = 2;
        grafKamus[8] = 2;
        grafKamus[9] = 2;

        int panjangGrafKamus = getPanjangGrafKamus();

        ofstream fileBiner("kamus.model", ios::binary);

        if (fileBiner.is_open()) {
            for(int i = 0; i<panjangGrafKamus; i++) {
                fileBiner.put(grafKamus[i]);
            }

            fileBiner.close();
        }

    }

    ifstream fileBiner("kamus.model", ios::binary);
    if(fileBiner.is_open()) {
        char c;
        int i = 0;
        while (! fileBiner.eof() )
        {
            fileBiner.read(&c,1);
            grafKamus[i] = c;
            // cout << i << " > " << int(grafKamus[i]) << " : " << c << endl;
            i++;
        }
        fileBiner.close();
    }

}

bool Model::tersedia(const char *namaFile) {
    struct stat buffer;
    int exist = stat(namaFile, &buffer);
    if(exist == 0)
        return 1;
    else // -1
        return 0;
}

int Model::getPanjangGrafKamus() {
    int panjangGrafKamus = 0;
    int panjangTotalGrafKamus = sizeof(grafKamus)/ sizeof(grafKamus[0]);
    //cout << "panjang graf kamus : " << sizeof(grafKamus) << " panjang graf kamus[0] = " << sizeof(grafKamus[0]) << endl;

    int i;
    for(i = panjangTotalGrafKamus - 1; i>=0; i--) {
        if (grafKamus[i] != 0) {
            panjangGrafKamus = i + 1;
            break;
        }
    }

    return panjangGrafKamus;
}

int Model::getPointerMulaiMenulis() {
    int pointerMulaiMenulis = (grafKamus[0] * 256) + grafKamus[1];
    return pointerMulaiMenulis;
}

void Model::setPointerMulaiMenulis(int alamat) {
    grafKamus[0] = alamat / 256;
    grafKamus[1] = alamat % 256;
}

int Model::getPointerHurufPertamaPeriksa() {
    return (grafKamus[3] * 256) + grafKamus[4];
}

void Model::setPointerHurufPertamaPeriksa(int alamat) {
    grafKamus[3] = alamat / 256;
    grafKamus[4] = alamat % 256;
}

int Model::getPointerAlamatTujuan(int alamatA, int alamatB) {
    return (grafKamus[alamatA] * 256) + grafKamus[alamatB];
}

void Model::setPointerAlamatTujuan(int alamatA, int alamatB, int alamatTujuan) {
    grafKamus[alamatA] = alamatTujuan / 256;
    grafKamus[alamatB] = alamatTujuan % 256;
}

void Model::tulisGrafKamusKeFile() {

    int panjangGrafKamus = getPanjangGrafKamus();

    ofstream fileBiner("kamus.model", ios::binary);

    if (fileBiner.is_open()) {
        for(int i = 0; i<panjangGrafKamus; i++) {
            fileBiner.put(grafKamus[i]);
        }

        fileBiner.close();
    }

    /*
    printf("PRINT MEMORI \n\n");

    for(i=0; i<grafKamusLength; i++){
        printf("%d : %c (%d)\n", i, grafKamus[i], grafKamus[i]);
    }

    printf("pointer di %d\n", pointer);
    */
}