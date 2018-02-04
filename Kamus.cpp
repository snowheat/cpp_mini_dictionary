//
// Created by insan on 2/3/2018.
//
#include <iostream>
#include <sys/stat.h>
#include <cstdio>
#include "Kamus.h"
#include "Model.h"

using namespace std;

Kamus::Kamus() {
    model.ambil();
    model.grafKamus;
}

void Kamus::tampilkanMenu() {
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|            KAMUS SILIWANGI [SAEUTIK GE MAHI]            |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << "1. Terjemahkan" << endl;
    cout << "2. Tambah kata" << endl;
    cout << "3. Ubah kata" << endl;
    cout << "4. Hapus kata" << endl;
    cout << "5. Tampilkan struktur kamus" << endl;
    cout << "PILIH :" << endl;
    cin >> nomorMenu;
    cout << "Nomor Menu " << nomorMenu << endl;
    eksekusiMenu(nomorMenu);
}

void Kamus::buka() {
    tampilkanMenu();
}

void Kamus::eksekusiMenu(int nomorMenu) {
    switch (nomorMenu) {
        case 1 :

            break;
        case 2 :
            penambahKata.tampilkanMenu();
            break;
        case 3 :

            break;
        case 4 :

            break;
        case 5 :

            break;
        default:
            cout << "Salah kode perintah" << endl;
    }

    tampilkanMenu();
}

