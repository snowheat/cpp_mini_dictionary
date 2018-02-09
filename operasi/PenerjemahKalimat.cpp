//
// Created by insan on 2/4/2018.
//

#include <iostream>
#include <cstring>
#include "PenerjemahKalimat.h"

PenerjemahKalimat::PenerjemahKalimat() {
}

void PenerjemahKalimat::tampilkanMenu(Model *pModel) {

    char kalimat[100];
    string kalimatString = "";

    cout << "Masukan kata / kalimat : ";
    cin.ignore();
    getline(cin, kalimatString, '\n');
    strcpy(kalimat, kalimatString.c_str());

    prosesKalimat(kalimat, pModel);

    int nomorMenu;
    cout << endl << "(( 1. Kembali ke menu, 2. Kembali terjemahkan kata )) : ";
    cin >> nomorMenu;

    if(nomorMenu == 2) tampilkanMenu(pModel);
}

void PenerjemahKalimat::prosesKalimat(char kalimat[100], Model *m) {
    char arrayKata[10][100];
    char * kata;
    kata = strtok (kalimat, " ,.-");
    int i = 0;
    while(kata != NULL) {

        strcpy(arrayKata[i], kata);
        kata = strtok (NULL, " ,.-");
        i++;
    }

    if(i > 1) {
        terjemahkanKalimat(arrayKata, m);
    } else {
        cariKata(arrayKata[0], m);
    }

}

void PenerjemahKalimat::cariKata(char kata[100], Model *m) {
    cout << "Cari Kata : ";
    int i;
    int cekPointer = m->getPointerHurufPertamaPeriksa();
    bool ditemukan = true;
    bool berhentiPencarian;

    for(i=0; i<strlen(kata); i++) {

        if(ditemukan == false) {
            break;
        }

        berhentiPencarian = false;
        while(berhentiPencarian==false) {
            cout << m->getGrafKamus(cekPointer+1) << "-";
            if(m->getGrafKamus(cekPointer+1)==kata[i]) {

                // Huruf input = huruf kamus
                cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                berhentiPencarian = true;

            }else {

                // Huruf input != huruf kamus
                if(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) != 2) {

                    // Ada sodara sebelah kanan
                    cekPointer = m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5);

                }else {

                    // Tidak ada lagi sodara sebelah kanan
                    ditemukan = false;
                    berhentiPencarian = true;

                }
            }
        }

    }

    // Kata ditemukan, lalu bertemu stop
    if(ditemukan == true && m->getGrafKamus(cekPointer) == 3) {
        cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);

        // Terjemahan bahasa sunda
        int jumlahHuruf;
        if(m->getGrafKamus(cekPointer)==4) {
            jumlahHuruf = m->getGrafKamus(cekPointer+1);
            cekPointer += 2;
        }

        cout << endl << "SUNDA : ";
        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

        cekPointer += jumlahHuruf;

        jumlahHuruf = m->getGrafKamus(cekPointer);
        cekPointer += 1;

        cout << endl << "INGGRIS : ";
        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

    }else {
        cout << "Kata <" << kata << ">tidak ditemukan" << endl;
    }


}

void PenerjemahKalimat::terjemahkanKalimat(char kalimat[10][100], Model *m) {
    int jumlahKata = strlen(reinterpret_cast<const char *>(kalimat));
    //cout << "Banyaknya kata : " << jumlahKata << endl;

    int i;
    for(i=0; i<jumlahKata; i++) {
        cout << kalimat[i] << " ";
    }

    cout << " :\n>> SUNDA : " ;
    for(i=0; i<jumlahKata; i++) {
        getKataSunda(kalimat[i], m);
    }

    cout << "\n>> INGGRIS : " ;
    for(i=0; i<jumlahKata; i++) {
        getKataInggris(kalimat[i], m);
    }
}

void PenerjemahKalimat::getKataInggris(char kata[100], Model *m) {
    int i;
    int cekPointer = m->getPointerHurufPertamaPeriksa();
    bool ditemukan = true;
    bool berhentiPencarian;

    for(i=0; i<strlen(kata); i++) {

        if(ditemukan == false) {
            break;
        }

        berhentiPencarian = false;
        while(berhentiPencarian==false) {
            if(m->getGrafKamus(cekPointer+1)==kata[i]) {

                // Huruf input = huruf kamus
                cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                berhentiPencarian = true;

            }else {

                // Huruf input != huruf kamus
                if(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) != 2) {

                    // Ada sodara sebelah kanan
                    cekPointer = m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5);

                }else {

                    // Tidak ada lagi sodara sebelah kanan
                    ditemukan = false;
                    berhentiPencarian = true;

                }
            }
        }

    }

    // Kata ditemukan, lalu bertemu stop
    if(ditemukan == true && m->getGrafKamus(cekPointer) == 3) {
        cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);

        // Terjemahan bahasa sunda
        int jumlahHuruf;
        if(m->getGrafKamus(cekPointer)==4) {
            jumlahHuruf = m->getGrafKamus(cekPointer+1);
            cekPointer += 2;
        }

        cekPointer += jumlahHuruf;

        jumlahHuruf = m->getGrafKamus(cekPointer);
        cekPointer += 1;

        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

        cout << " ";
    }else {
        cout << kata << " ";
    }
}

void PenerjemahKalimat::getKataSunda(char *kata, Model *m) {
    int i;
    int cekPointer = m->getPointerHurufPertamaPeriksa();
    bool ditemukan = true;
    bool berhentiPencarian;

    for(i=0; i<strlen(kata); i++) {

        if(ditemukan == false) {
            break;
        }

        berhentiPencarian = false;
        while(berhentiPencarian==false) {
            if(m->getGrafKamus(cekPointer+1)==kata[i]) {

                // Huruf input = huruf kamus
                cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                berhentiPencarian = true;

            }else {

                // Huruf input != huruf kamus
                if(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) != 2) {

                    // Ada sodara sebelah kanan
                    cekPointer = m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5);

                }else {

                    // Tidak ada lagi sodara sebelah kanan
                    ditemukan = false;
                    berhentiPencarian = true;

                }
            }
        }

    }

    // Kata ditemukan, lalu bertemu stop
    if(ditemukan == true && m->getGrafKamus(cekPointer) == 3) {
        cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);

        // Terjemahan bahasa sunda
        int jumlahHuruf;
        if(m->getGrafKamus(cekPointer)==4) {
            jumlahHuruf = m->getGrafKamus(cekPointer+1);
            cekPointer += 2;
        }

        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

        cout << " ";
    }else {
        cout << kata << " ";
    }
}
