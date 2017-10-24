#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "aktor.h"
#include "film.h"
#include "relasi.h"
#include <iostream>
#define next_r(P) P->next_r
#define prev_r(P) P->prev_r
#define first_r(L) L.first_r
#define last_r(L) L.last_r
#define Aktor(P) P->Aktor
#define Film(P) P->Film

using namespace std;

typedef struct elmlist_r *address_r;

struct elmlist_r{
    address_r next_r;
    address_r prev_r;
    address_a Aktor;
    address_f Film;
};

struct list_r{
    address_r first_r;
    address_r last_r;
};

void createList_r(list_r &L);
address_r alokasi_r(address_a P, address_f Q);
void dealokasi_r(address_r);
void insertFirst_r(list_r &L, address_r P);
void deleteFirst_r(list_r &L, address_r &P);
void deleteLast_r(list_r &L, address_r &P);
void deleteAfter_rA(list_r &L, address_a &P);
void deleteAfter_rF(list_r &L, address_f &P);
void showAktor(list_r L, int x);
void showFilm(list_r L, int x);
bool findRelasi_a(list_r L, int x);
void printInfo_r(list_r L);
#endif // RELASI_H_INCLUDED
