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
#define BLANK_CONTENT_POINTER		10

using namespace std;

Model::Model() {

}

void Model::ambil() {

    FILE * file;

    if(!tersedia("kamus.model")) {
        grafKamus[0] = 0;
        grafKamus[1] = BLANK_CONTENT_POINTER;
        grafKamus[2] = 2;
        grafKamus[3] = 0;
        grafKamus[4] = BLANK_CONTENT_POINTER;
        grafKamus[5] = 2;
        grafKamus[6] = 2;
        grafKamus[7] = 2;
        grafKamus[8] = 2;
        grafKamus[9] = 2;

        int panjangGrafKamus = getPanjangGrafKamus();
        cout << "panjangGrafKamus : " << panjangGrafKamus << endl;

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
            cout << " > " << int(grafKamus[i]) << endl;
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
    int i;
    for(i = panjangTotalGrafKamus - 1; i>=0; i--) {
        if (grafKamus[i] != 0) {
            panjangGrafKamus = i + 1;
            break;
        }
    }

    return panjangGrafKamus;
}
