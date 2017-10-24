#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#include <string>
#define next_f(P) (P)->next_f
#define info_f(P) (P)->info_f
#define prev_f(P) (P)->prev_f
#define first_f(L) (L).first_f
#define last_f(L) (L).last_f

using namespace std;

struct film{
    string nama;
    int kode;
};

typedef film infotype_f;
typedef struct elmlist_f *address_f;

struct elmlist_f{
    infotype_f info_f;
    address_f next_f;
    address_f prev_f;
};

struct list_f{
    address_f first_f;
    address_f last_f;
};

void createList_f(list_f &L);
address_f alokasi_f(infotype_f x);
void dealokasi_f(address_f P);
void insertFirst_f(list_f &L, address_f P);
void insertLast_f(list_f &L, address_f P);
void deleteFirst_f(list_f &L, address_f &P);
void deleteLast_f(list_f &L, address_f &P);
address_f findElm_f(list_f L, int x);
void printInfo_f(list_f L);


#endif // FILM_H_INCLUDED
