#include "pawang.h"

void Create_list(mll &ListPawang){
    first(ListPawang) = nil;
    last(ListPawang) = nil;
}

void newElm_Pawang(Pawang Info,adrP &Pwg){
    Pwg = new elmPawang;
    info(Pwg) = Info;
    info(Pwg).jmlSinga = 0;
    if (info(Pwg).Pengalaman == "Senior"){
        info(Pwg).maxSinga = 5;
    }else if (info(Pwg).Pengalaman == "Medior"){
        info(Pwg).maxSinga = 3;
    } else {
        info(Pwg).maxSinga = 1;
    }

    nextsinga(Pwg) = nil;
    next(Pwg) = nil;
}

void newElm_Singa(Singa Info , adrS &Sng){
    Sng = new elmSinga;
    info(Sng) = Info;
    next(Sng) = nil;
}

void insertLast_Pawang(mll &ListPawang, adrP Pwg){
    if(first(ListPawang) == nil){
        first(ListPawang) = Pwg;
        last(ListPawang) = Pwg;
    } else {
        next(last(ListPawang)) = Pwg;
        last(ListPawang) = Pwg;
    }
}

void deleteLastPwg(mll &ListPawang, adrP Pwg){
    if (first(ListPawang) != nil){
        Pwg = last(ListPawang);
        adrP beforeLast = first(ListPawang);

        while( next(beforeLast) != Pwg){
            beforeLast = next(beforeLast);
        }

        next(beforeLast) = nil;
        last(ListPawang) = beforeLast;
    }
}

void deleteFirstPwg(mll &ListPawang, adrP Pwg){
    if (first(ListPawang)!= nil){
        adrP Pwg = first(ListPawang);
        if (next(Pwg)==nil){
            first(ListPawang) = nil;
        } else {
            first(ListPawang) = next(Pwg);
            next(Pwg) = nil;
        }

    }
}

void deleteAfterPwg(mll &ListPawang, adrP Pwg){
    adrP prec = first(ListPawang);
    while (next(prec)!=Pwg){
        prec = next(prec);
    }
    next(prec) = next(Pwg);
    next(Pwg) = nil;
}

void insertNew_Singa(mll &ListPawang, adrP Pwg, adrS Sng){
    if (nextsinga(Pwg) == nil){
        nextsinga(Pwg) = Sng;
        info(Pwg).jmlSinga += 1;
    }else {
        adrS p = nextsinga(Pwg);
        while(next(p)!= nil){
            p = next(p);
        }
        info(Pwg).jmlSinga += 1;
        next(p) = Sng;
    }
}

void deleteFirst_Singa(mll &ListPawang, adrP Pwg, adrS &Sng){
    if (nextsinga(Pwg)!= nil){
        if (next(nextsinga(Pwg))== nil){
            Sng = nextsinga(Pwg);
            nextsinga(Pwg) = nil;
        } else {
            Sng = nextsinga(Pwg);
            nextsinga(Pwg)= next(Sng);
            next(Sng) = nil;
        }
    }
}

void deleteLast_Singa(mll &ListPawang, adrP Pwg, adrS &Sng){
    adrS P = nextsinga(Pwg);
    adrS Q = nextsinga(Pwg);

    while (next(P)!= nil){
        Q = P;
        P = next(P);
    }

    Sng = P;
    next(Q) = nil;
}

void deleteAfter_Singa(mll &ListPawang, adrP Pwg,adrS prec, adrS &Sng){
    prec = nextsinga(Pwg);

    while (next(prec)!= Sng){
        prec = next(prec);
    }

    next(prec) = next(Sng);
    next(Sng) = nil;
}

void Delete_Pawang(mll &ListPawang, string nama_pawang){
    if (first(ListPawang) != nil){
        adrP Del = Search_Pawang(ListPawang,nama_pawang);

        if (Del == first(ListPawang)){
            deleteFirstPwg(ListPawang,Del);
        } else if (Del == last(ListPawang)){
            deleteLastPwg(ListPawang,Del);
        } else {
            deleteAfterPwg(ListPawang,Del);
        }

    }
}

void Delete_Singa(mll &ListPawang, string nama_pawang, string nama_singa){
    adrP P = Search_Pawang(ListPawang,nama_pawang);
    adrS Del;

    if (nextsinga(P) != nil) {
        adrS S = nextsinga(P);
        while( (info(S).NamaSinga != nama_singa) && (S != nil) ){
            S = next(S);
        }

        if (S == nextsinga(P)){
            deleteFirst_Singa(ListPawang,P,Del);
        } else if(next(S) == nil){
            deleteLast_Singa(ListPawang,P,Del);
        } else {
            adrS prec;
            deleteAfter_Singa(ListPawang,P,prec,S);
        }
    }
}

void showAllParentAndChild(mll ListPawang){
    adrP Pwg;
    adrS Sng;

    if (first(ListPawang) == nil){
        cout<<"List Kosong"<<endl;
    } else {
        Pwg = first(ListPawang);
        cout<<"------------------------------------------"<<endl;
        while(Pwg != nil){

            Sng = nextsinga(Pwg);

            cout<<"Nama Pawang: "<<info(Pwg).namaPawang<<endl;
            cout<<"Pengalaman: "<<info(Pwg).Pengalaman<<endl;
            cout<<"Jumlah singa: "<<info(Pwg).jmlSinga<<endl;
            cout<<"Maximal singa: "<<info(Pwg).maxSinga<<endl;
            cout<<endl;

            cout<<"Daftar Singa yang dimiliki pawang "<<info(Pwg).namaPawang<<":"<<endl;

            if(Sng == nil){
                cout<<"Belum ada Singa"<<endl;
            }

            int nomor = 0;
            while(Sng != nil){
                nomor++;
                cout<<"[Singa Ke- "<<nomor<<"]"<<endl;
                cout<<"Nama Singa: "<<info(Sng).NamaSinga<<endl;
                cout<<"Umur singa: "<<info(Sng).UmurSinga<<endl;
                cout<<"Jenis Singa: "<<info(Sng).JenisSinga<<endl;
                cout<<endl;
                Sng = next(Sng);

            }

            cout<<endl;
            cout<<"------------------------------------------"<<endl;
            Pwg = next(Pwg);
        }
    }
}

int countSinga(adrP Pwg){
    int countsinga = 0;
    adrS singa = nextsinga(Pwg);

    while(singa != nil){
        countsinga++;
        singa = next(singa);
    }

    return countsinga;
}

adrP Search_Pawang(mll ListPawang, string nama_pawang){
    adrP P = first(ListPawang);

    while (P != nil) {
        if(info(P).namaPawang == nama_pawang){
            return P;
        }
        P = next(P);
    }

    return nil;
}

adrS Search_Singa(adrP Pwg, string nama_singa){
    if (nextsinga(Pwg) != nil){
        adrS Sng = nextsinga(Pwg);
        while (info(Sng).NamaSinga != nama_singa){
            Sng = next(Sng);
        }
        return Sng;
    }
    return nil;
}

void findAndShowPawang(mll ListPawang, string nama_pawang){
    adrP P = Search_Pawang(ListPawang,nama_pawang);
    cout<<info(P).namaPawang<<endl;
    cout<<info(P).Pengalaman<<endl;
    cout<<info(P).jmlSinga<<endl;
    cout<<info(P).maxSinga<<endl;
    adrS Sng = nextsinga(P);
    int nomor = 0;
    while(Sng != nil){
        nomor++;
        cout<<"[Singa Ke- "<<nomor<<"]"<<endl;
        cout<<"Nama Singa: "<<info(Sng).NamaSinga<<endl;
        cout<<"Umur singa: "<<info(Sng).UmurSinga<<endl;
        cout<<"Jenis Singa: "<<info(Sng).JenisSinga<<endl;
        cout<<endl;
        Sng = next(Sng);
    }

}

void findAndShowSingaOfPawang(adrP Pwg, string nama_singa){
    adrS S = Search_Singa(Pwg,nama_singa);
    cout<<info(S).NamaSinga<<endl;
    cout<<info(S).UmurSinga<<endl;
    cout<<info(S).JenisSinga<<endl;
}

void PawangDenganSingaTerbanyak(mll Listpawang){
    if (first(Listpawang) == nil){
        cout<<"List Kosong tidak ada pawang yang dapat dibandingkan"<<endl;
    } else {
        adrP Pwg = first(Listpawang);
        adrP PwgMax = next(first(Listpawang));

        while(Pwg != nil){
            if (info(Pwg).jmlSinga > info(PwgMax).jmlSinga){
                PwgMax = Pwg;
            }
            Pwg = next(Pwg);
        }
        cout<<"Pawang dengan jumlah singa terbanyak: "<<info(PwgMax).namaPawang<<endl;
    }
}

void PawangDenganSingaPalingSedikit(mll ListPawang){
    if (first(ListPawang) == nil){
        cout<<"List Kosong tidak ada pawang yang dapat dibandingkan"<<endl;
    } else {
        adrP Pwg = first(ListPawang);
        adrP PwgMin = next(first(ListPawang));
        while(Pwg != nil){
            if (info(Pwg).jmlSinga < info(PwgMin).jmlSinga){
                PwgMin = Pwg;
            }
            Pwg = next(Pwg);
        }
        cout<<"Pawang dengan jumlah singa Paling Sedikit: "<<info(PwgMin).namaPawang<<endl;
    }
}
void SingaDenganUmurTertua(mll ListPawang){

    if (first(ListPawang) == nil){
        cout<<"List Kosong"<<endl;
    }else {
        adrP Pwg = first(ListPawang);
        adrS SngTertua = nil;

        while(Pwg != nil){

            if (nextsinga(Pwg) != nil){
                adrS Sng = nextsinga(Pwg);
                adrS Oldest = next(nextsinga(Pwg));

                while(Sng != nil){

                    if (info(Sng).UmurSinga > info(Oldest).UmurSinga){
                        Oldest = Sng;
                    }
                    Sng = next(Sng);
                }

                if (SngTertua == nil) {
                    SngTertua = Oldest;
                }

                if (info(SngTertua).UmurSinga < info(Oldest).UmurSinga){
                    SngTertua = Oldest;
                }
            }

            Pwg = next(Pwg);
        }
        cout<<"Singa tertua adalah: "<<info(SngTertua).NamaSinga<<endl;
    }
}

int Menu(){
    cout<<"1.  Tambah Pawang"<<endl;
    cout<<"2.  Hapus Pawang"<<endl;
    cout<<"3.  Tambah singa ke pawang"<<endl;
    cout<<"4.  Cari dan tampilkan Pawang"<<endl;
    cout<<"5.  Hapus singa dari pawang"<<endl;
    cout<<"6.  Cari dan Tampilkan singa dari pawang"<<endl;
    cout<<"7.  Tampilkan Semua pawang dan singanya"<<endl;
    cout<<"8.  Pawang dengan singa terbanyak"<<endl;
    cout<<"9.  Pawang dengan singa paling sedikit"<<endl;
    cout<<"10. Singa dengan umur tertua"<<endl;
    cout<<"0.  Exit"<<endl;
    cout<<"Select: ";
    int input;
    cin>>input;
    cout<<endl;

    return input;


}

void RunProgram(){
    mll ListPawang;
    adrP Pwg;
    adrS Sng;
    string NamaPawang, Pengalaman;
    string NamaSinga, JenisSinga;
    int UmurSinga;
    Create_list(ListPawang);

    int select = Menu();

    while(select != 0){
        if (select == 1){
            int jml;
            cout<<"Jumlah Pawang Yang ingin ditambahkan: ";
            cin>>jml;
            for(int i = 0; i < jml;i++){

                if (jml == 1){
                    cout<<"[Masukkan Data Pawang]"<<endl;
                } else {
                    cout<<"[Masukkan Data Pawang Ke - "<<i+1<<"]"<<endl;
                }

                cout<<"Masukkan Nama Pawang: ";
                cin>>NamaPawang;
                cout<<"Pengalaman Pawang Senior/Medior/Junior: ";
                cin>>Pengalaman;
                newElm_Pawang({NamaPawang,Pengalaman},Pwg);
                insertLast_Pawang(ListPawang,Pwg);
            }
            cout<<endl;

        } else if(select == 2){

            cout<<"Pawang yang ingin di Hapus: ";
            cin>>NamaPawang;
            Delete_Pawang(ListPawang,NamaPawang);

        } else if(select == 3){
            int jml;
            cout<<"Masukkan nama pawang yang ingin ditambah singa: ";
            cin>>NamaPawang;

            Pwg = Search_Pawang(ListPawang,NamaPawang);
            int hitungSng = countSinga(Pwg);

            cout<<"Jumlah Singa Yang ingin ditambahkan: ";
            cin>>jml;

            if (hitungSng < info(Pwg).maxSinga && jml + info(Pwg).jmlSinga < info(Pwg).maxSinga){

                for(int i = 0; i < jml; i++){
                    cout<<"[Singa Ke-"<<i+1<<"]"<<endl;
                    cout<<"Nama singa yang akan ditambahkan: ";
                    cin>>NamaSinga;
                    cout<<"Umur Singa: ";
                    cin>>UmurSinga;
                    cout<<"Jenis Singa: ";
                    cin>>JenisSinga;

                    if(info(Pwg).jmlSinga < info(Pwg).maxSinga){
                        newElm_Singa({NamaSinga,UmurSinga,JenisSinga},Sng);
                        insertNew_Singa(ListPawang,Pwg,Sng);
                    }
                    cout<<endl;
                }
            }
        } else if(select == 4){
            cout<<"Nama Pawang yang ingin dicari: ";
            cin>>NamaPawang;
            findAndShowPawang(ListPawang,NamaPawang);

        } else if(select == 5){

            cout<<"Pilih pawang yang akan diambil singanya: ";
            cin>>NamaPawang;
            findAndShowPawang(ListPawang,NamaPawang);
            cout<<"Singa yang akan diambil: ";
            cin>>NamaSinga;
            Delete_Singa(ListPawang,NamaPawang,NamaSinga);


        } else if(select == 6){
            cout<<"Nama pawang yang akan dicari singanya: ";
            cin>>NamaPawang;
            Pwg = Search_Pawang(ListPawang,NamaPawang);
            cout<<"Nama singa yang ingin dicari: ";
            cin>>NamaSinga;
            findAndShowSingaOfPawang(Pwg,NamaPawang);

        } else if(select == 7){
            showAllParentAndChild(ListPawang);

        } else if(select == 8){
            PawangDenganSingaTerbanyak(ListPawang);
        } else if(select == 9){
            PawangDenganSingaPalingSedikit(ListPawang);
        }else if(select == 10){
            SingaDenganUmurTertua(ListPawang);
        }
        select = Menu();
    }

}



