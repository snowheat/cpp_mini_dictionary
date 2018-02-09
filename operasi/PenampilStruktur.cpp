//
// Created by insan on 2/4/2018.
//

#include <iostream>
#include <stack>
#include "PenampilStruktur.h"

PenampilStruktur::PenampilStruktur() {
}

void PenampilStruktur::tampilkanMenu(Model *m) {

    cout << "Tampilkan struktur kamus : " << endl;
    tampilkanStrukturKamus(m);
}

void PenampilStruktur::tampilkanStrukturKamus(Model *m) {

    int cekPointer;
    bool berhentiPencarian;

    int i, h, jumlahHuruf, hurufKe;

    stack<unsigned int> tumpukanAlamatNode;
    tumpukanAlamatNode.push(m->getPointerHurufPertamaPeriksa());
    tumpukanAlamatNode.push(0);

    while(!tumpukanAlamatNode.empty()){
        //cout << endl << "Iterasi tumpukanAlamatNode : " << endl;

        hurufKe = tumpukanAlamatNode.top();
        tumpukanAlamatNode.pop();

        cekPointer = tumpukanAlamatNode.top();
        tumpukanAlamatNode.pop();

        for(h=0; h<hurufKe; h++) {
            //cout << "..";
            cout << "  ";
        }

        if(h>0){
            cout << "|" << endl;
        }

        for(h=0; h<hurufKe; h++) {
            //cout << "..";
            cout << "  ";
        }

        // cout << "Huruf ke " << hurufKe << ":";

        berhentiPencarian = false;
        while(berhentiPencarian==false) {
            if(m->getGrafKamus(cekPointer)==1) {

                if(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5)!=2){
                    //cout << "sodara kanan:" << m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5) << " " << m->getGrafKamus(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5)+1) << endl;
                    tumpukanAlamatNode.push(m->getPointerAlamatTujuan(cekPointer+4, cekPointer+5));
                    tumpukanAlamatNode.push(hurufKe);
                }

                cout << m->getGrafKamus(cekPointer+1) << "-";
                cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                hurufKe += 1;
            } else {
                // Jika masuk stop
                if(m->getGrafKamus(cekPointer)==3) {
                    cekPointer = m->getPointerAlamatTujuan(cekPointer+2, cekPointer+3);
                    berhentiPencarian = true;
                }
            }
        }



        // Terjemahan
        if(m->getGrafKamus(cekPointer)==4) {
            jumlahHuruf = m->getGrafKamus(cekPointer+1);
            cekPointer += 2;
        }

        cout << "> ";
        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

        cekPointer += jumlahHuruf;
        jumlahHuruf = m->getGrafKamus(cekPointer);
        cekPointer += 1;

        cout << " -> ";
        for(i=0; i<jumlahHuruf; i++) {
            cout << char(m->getGrafKamus(cekPointer+i));
        }

        cout << endl;

        //cout << endl << "<< Selesai Iterasi tumpukanAlamatNode : >>" << endl;
    }


}
