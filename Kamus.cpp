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
    cout << "PILIH : ";
    cin >> nomorMenu;
    //cout << "Nomor Menu " << nomorMenu << endl;
    eksekusiMenu(nomorMenu);
}

void Kamus::buka() {
    //cout << " - - Panjang graf kamus : " << model.getPanjangGrafKamus() << endl;
    tampilkanMenu();

}

void Kamus::eksekusiMenu(int nomorMenu) {
    switch (nomorMenu) {
        case 1 :
            penerjemahKalimat.tampilkanMenu(&model);
            break;
        case 2 :
            cout << " - - Panjang graf kamus : " << model.getPanjangGrafKamus() << endl;
            penambahKata.ambilInput(&model);
            break;
        case 3 :
            pengubahKata.tampilkanMenu(&model);
            break;
        case 4 :
            penghapusKata.tampilkanMenu(&model);
            break;
        case 5 :
            penampilStruktur.tampilkanMenu(&model);
            break;
        default:
            cout << "Salah kode perintah" << endl;
    }

    tampilkanMenu();
}

