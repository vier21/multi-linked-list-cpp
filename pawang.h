#ifndef PAWANG_H_INCLUDED
#define PAWANG_H_INCLUDED

#include <iostream>
using namespace std;
#define next(S) (S)->Next
#define info(S) (S)->info
#define nextsinga(S) (S) -> nextSinga
#define first(ListPawang) ((ListPawang).first)
#define last(ListPawang) ((ListPawang).last)
#define nil NULL

struct Pawang {
    string namaPawang;
    string Pengalaman;
    int jmlSinga;
    int maxSinga;
};

struct Singa{
    string NamaSinga;
    int UmurSinga;
    string JenisSinga;
};

typedef struct elmPawang *adrP;
typedef struct elmSinga *adrS;

struct elmPawang{
    Pawang info;
    adrP Next;
    adrS nextSinga;
};

struct elmSinga {
    Singa info;
    adrS Next;
};

struct mll {
    adrP first;
    adrP last;
};

void Create_list(mll &ListPawang);
void newElm_Pawang(Pawang Info,adrP &Pwg);
void newElm_Singa(Singa Info , adrS &Sng);
void insertNew_Singa(mll &ListPawang, adrP Pwg, adrS Sng);
void insertLast_Pawang(mll &ListPawang, adrP Pwg);
void deleteLastPwg(mll &ListPawang, adrP Pwg);
void deleteFirstPwg(mll &ListPawang, adrP Pwg);
void deleteAfterPwg(mll &ListPawang, adrP Pwg);
void deleteFirst_Singa(mll &ListPawang, adrP Pwg, adrS &Sng);
void deleteLast_Singa(mll &ListPawang, adrP Pwg, adrS &Sng);
void deleteAfter_Singa(mll &ListPawang, adrP Pwg,adrS prec, adrS &Sng);
void Delete_Pawang(mll &ListPawang, string nama_pawang);
void Delete_Singa(mll &ListPawang, string nama_pawang, string nama_singa);
void showAllParentAndChild(mll ListPawang);
adrP Search_Pawang(mll ListPawang, string nama_pawang);
adrS Search_Singa(mll ListPawang, string nama_Pawang, string nama_singa);
void findAndShowPawang(mll ListPawang, string nama_pawang);
void findAndShowSingaOfPawang(adrP Pwg, string nama_singa);
int countSinga(adrP Pwg);
void PawangDenganSingaTerbanyak(mll Listpawang);
void PawangDenganSingaPalingSedikit(mll ListPawang);
void SingaDenganUmurTertua(mll ListPawang);
int Menu();
void RunProgram();



#endif // PAWANG_H_INCLUDED
