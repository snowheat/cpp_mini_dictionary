//
// Created by insan on 2/4/2018.
//

#include <iostream>
#include <cstring>
#include "PenambahKata.h"

PenambahKata::PenambahKata() {
}

void PenambahKata::ambilInput(Model *pModel) {

    char kataBahasaIndonesia[50];
    char kataBahasaInggris[50];
    char kataBahasaSunda[50];

    cout << "Masukan kata bahasa Indonesia :" << endl;
    cin >> kataBahasaIndonesia;
    cout << "Masukan terjemahan bahasa Sunda :" << endl;
    cin >> kataBahasaSunda;
    cout << "Masukan terjemahan bahasa Inggris :" << endl;
    cin >> kataBahasaInggris;

    tambahkanKataKeModel(kataBahasaIndonesia, kataBahasaSunda, kataBahasaInggris, pModel);
}

void PenambahKata::tambahkanKataKeModel(char indonesia[50], char sunda[50], char inggris[50], Model *m) {

    m->setPointer(m->getPointerMulaiMenulis());
    int sodaraKananSebelum, sodaraKiriSebelum;

    if(m->getGrafKamus(m->getPointerKontenPertama())!=1) {

        cout << "konten pointer awal konten " << endl; // Kondisi kamus.model kosong
        tulisKataKeKamus(indonesia, 0, sunda, inggris, m); // Tulis data pertama ke kamus

    }else {
        int pointerHurufPertamaPeriksa = m->getPointerHurufPertamaPeriksa();
        cout << "Kondisi model tidak kosong, periksa huruf pertama di memori : " << pointerHurufPertamaPeriksa << endl;

        // Iterasi huruf dari kata bahasa indonesia yang akan diinput
        int i;
        bool berhentiPencarian;
        int cekPointer = pointerHurufPertamaPeriksa;
        int pointerHurufOrangTua[50]; // 50 melambangkan maksimum kemungkinan jumlah huruf dalam satu kata

        for(i=0; i<strlen(indonesia); i++) {
            // cout << i << " : " << indonesia[i];

            if(m->getGrafKamus(cekPointer)==0) {
                // cekPointer menunjuk ke 0, buat referensi baru menurun, artinya jalur turun kosong
                cout << ">>> Huruf " << indonesia[i] << " : F. Huruf input siap ditulis di pointer ini " << m->getPointer() << endl;

                tulisKataKeKamus(indonesia, i, sunda, inggris, m);

                break;
            }else {
                // cekPointer tidak menunjuk ke 0, artinya ada huruf untuk ditinjau
                // Untuk huruf pertama dari kata yang diinput, periksa array huruf pertama pada kamus
                berhentiPencarian = false;
                while(berhentiPencarian==false) {
                    // cout << "cek huruf pertama " << m->getGrafKamus(cekPointer+1) << " , tetangga " << m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) << endl;

                    cout << "bandingin " << m->getGrafKamus(cekPointer+1) << " dengan " << indonesia[i] << endl;

                    if(m->getGrafKamus(cekPointer+1)==indonesia[i]) {
                        // Huruf input = huruf kamus
                        // Pointer maju ke anak dari huruf kamus

                        pointerHurufOrangTua[i] = cekPointer;

                        cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                        berhentiPencarian = true;

                        cout << ">>> Huruf " << indonesia[i] << " : A. Huruf input = huruf kamus. Pointer maju ke " << cekPointer << endl;

                    }else {
                        // Huruf input != huruf kamus

                        // Cek apakah huruf input sebelum, atau sesudah huruf kamus
                        if(indonesia[i] < m->getGrafKamus(cekPointer+1))
                        {
                            // Huruf input ada sebelum huruf kamus
                            // Buat referensi sebelum huruf kamus
                            // Ganti pointer orang tua menjadi ke referensi baru huruf input
                            // Masukan alamat huruf kamus ke alamat sodara kanan huruf input

                            // Set anak pertama orang tua nya
                            if(i == 0)
                            {
                                // Orang tua tertinggi
                                m->setPointerHurufPertamaPeriksa(m->getPointer());
                            }
                            else
                            {
                                // Orang tua bukan orang tua tertinggi
                                m->setPointerAlamatTujuan( pointerHurufOrangTua[i-1]+2, pointerHurufOrangTua[i-1]+3, m->getPointer());
                            }

                            m->setGrafKamus(m->getPointer(), 1);
                            m->setGrafKamus(m->getPointer()+1, indonesia[i]);
                            m->setPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3, m->getPointer()+6);
                            m->setPointerAlamatTujuan(m->getPointer()+4, m->getPointer()+5, cekPointer);

                            m->setPointer(m->getPointer()+6);
                            cekPointer = m->getPointer();

                            berhentiPencarian = true;

                            cout << ">>> Huruf " << indonesia[i] << " : B. Huruf input < huruf kamus. Buat referensi sebelum huruf kamus" << endl;

                        }else {
                            // Huruf input ada sesudah huruf kamus

                            // Cek dulu sodara kanan nya bertahap
                            if(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) == 2)
                            {
                                // Tidak ditemukan referensi sodara kanan nya
                                // Buat referensi baru

                                m->setPointerAlamatTujuan(cekPointer+4, cekPointer+5, m->getPointer());

                                m->setGrafKamus(m->getPointer(), 1);
                                m->setGrafKamus(m->getPointer()+1, indonesia[i]);
                                m->setPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3, m->getPointer()+6);
                                m->setPointerAlamatTujuan(m->getPointer()+4, m->getPointer()+5, 2);

                                m->setPointer(m->getPointer()+6);
                                cekPointer = m->getPointer();

                                berhentiPencarian = true;

                                cout << ">>> Huruf " << indonesia[i] << " : C. Huruf input > huruf kamus. Tidak ditemukan sodara kanan. Buat referensi sesudah huruf kamus" << endl;

                            }else {
                                // Huru f input ada sesudah huruf kamus, kemungkinan :

                                if(indonesia[i] > m->getGrafKamus(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5)+1)) {
                                    // 1. Ada sesudah sodara kanan huruf kamus
                                    // pada iterasi while selanjutnya, pointer maju ke sodara kanan nya
                                    cekPointer = m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5);

                                    cout << ">>> Huruf " << indonesia[i] << " : D. Huruf input > huruf kamus. huruf input > Huruf sodara kanan huruf kamus. Pointer maju ke sodara kanan nya" << endl;

                                } else if(indonesia[i] == m->getGrafKamus(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5)+1)) {
                                    // 3. Sama dengan sodara kanan huruf kamus
                                    cekPointer = m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5);

                                    cout << ">>> Huruf " << indonesia[i] << " : G. Huruf input > huruf kamus. huruf input = Huruf sodara kanan huruf kamus. Pointer maju ke sodara kanan nya" << endl;

                                } else {
                                    // 2. Ada sesudah huruf kamus, sebelum sodara kanan huruf kamus
                                    // Buat referensi baru setelah huruf kamus, sebelum sodara kanan huruf kamus


                                    m->setGrafKamus(m->getPointer(), 1);
                                    m->setGrafKamus(m->getPointer()+1, indonesia[i]);
                                    m->setPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3, m->getPointer()+6); // Alamat anak
                                    m->setPointerAlamatTujuan(m->getPointer()+4, m->getPointer()+5, m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5)); // Alamat tetangga ambil dari sebelumnya

                                    cout << "MY ALAMAT : " << m->getPointer() << endl;
                                    m->setPointerAlamatTujuan(cekPointer+4, cekPointer+5, m->getPointer()); // Alamat huruf baru ini di sodara sebelum

                                    m->setPointer(m->getPointer()+6);
                                    cekPointer = m->getPointer();

                                    berhentiPencarian = true;

                                    cout << ">>> Huruf " << indonesia[i] << " : E. Huruf input > huruf kamus. huruf input < Huruf sodara kanan huruf kamus. Buat referensi sesudah huruf kamus" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    m->tulisGrafKamusKeFile();
}

void PenambahKata::tulisKataKeKamus(char indonesia[50], int mulaiIndeksHurufKe, char sunda[50], char inggris[50], Model *m) {
    cout << "tulis kata ke kamus" << endl;

    int i;
    for(i=0; i<strlen(indonesia); i++) {
        if(i>=mulaiIndeksHurufKe) {
            // Tulis kata pencarian
            m->setGrafKamus(m->getPointer(), 1); // Tipe blok memori : huruf kata pencarian
            m->setGrafKamus(m->getPointer()+1, tolower(indonesia[i])); // Char
            m->setPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3, m->getPointer()+6); // Alamat char anak
            m->setPointerAlamatTujuan(m->getPointer()+4, m->getPointer()+5, (2)); // Alamat char sodara (2 artinya tidak ada konten / kosong)

            cout << m->getPointer() << " - " << m->getGrafKamus(m->getPointer()) << " - "
                 << m->getGrafKamus(m->getPointer()+1) << " - " << m->getPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3) << endl;

            m->setPointer(m->getPointer()+6);
        }
    }

    // Tulis kata pencarian stop
    m->setGrafKamus(m->getPointer(), 3); // Tipe blok memori : kata pencarian stop
    m->setGrafKamus(m->getPointer()+1, 2); // Char (2 artinya tidak ada konten / kosong)
    m->setPointerAlamatTujuan(m->getPointer()+2, m->getPointer()+3, (m->getPointer()+6)); // Alamat char anak
    m->setPointerAlamatTujuan(m->getPointer()+4, m->getPointer()+5, (2)); // Alamat char sodara (2 artinya tidak ada konten / kosong)
    m->setPointer(m->getPointer()+6);
    cout << "Beres Tulis kata pencarian stop : pointer " << m->getPointer() << endl;

    /**
	 * Algoritma pengisian terjemahan
	 *
	 */
    m->setGrafKamus(m->getPointer(), 4); // Tipe blok memori : terjemahan sunda dan inggris
    m->setPointer(m->getPointer()+1);
    cout << "Beres Tulis tipe blok memori bagian terjemahan : pointer " << m->getPointer() << endl;

    // Terjemahan bahasa sunda
    m->setGrafKamus(m->getPointer(), strlen(sunda)); // Panjang kata terjemahan bahasa sunda
    m->setPointer(m->getPointer()+1);
    cout << "Beres Tulis panjang kata terjemahan bahasa sunda : pointer " << m->getPointer() << endl;

    for(i=0; i<strlen(sunda); i++){

        // Tulis terjemahan bahasa sunda
        m->setGrafKamus(m->getPointer(), tolower(sunda[i]));
        cout <<i << " - " << m->getPointer() << " - " << m->getGrafKamus(m->getPointer()) << endl;

        m->setPointer(m->getPointer()+1);
    }
    cout << "Beres Tulis karakter terjemahan bahasa sunda : pointer " << m->getPointer() << endl;

    // Terjemahan bahasa inggris
    m->setGrafKamus(m->getPointer(), strlen(inggris)); // Panjang kata terjemahan bahasa inggris
    m->setPointer(m->getPointer()+1);
    cout << "Beres Tulis panjang kata terjemahan bahasa inggris  : pointer " << m->getPointer() << endl;

    for(i=0; i<strlen(inggris); i++){

        // Tulis terjemahan bahasa inggris
        m->setGrafKamus(m->getPointer(), tolower(inggris[i]));
        cout <<i << " - " << m->getPointer() << " - " << m->getGrafKamus(m->getPointer()) << endl;

        m->setPointer(m->getPointer()+1);
    }
    cout << "Beres Tulis karakter terjemahan bahasa inggris : pointer " << m->getPointer() << endl;

    // printf("> (HORE!) Kata '%s', dengan terjemahan '%s', dan '%s', berhasil ditambahkan ke dalam kamus\n", kataBahasaIndonesia, kataBahasaSunda, kataBahasaInggris);

    m->setPointerMulaiMenulis(m->getPointer()); // Update nilai getPointerMulaiMenulis()
}

