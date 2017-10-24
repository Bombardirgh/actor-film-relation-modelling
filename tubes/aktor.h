#ifndef AKTOR_H_INCLUDED
#define AKTOR_H_INCLUDED
#include <iostream>
#include <string>
#define next_a(P) (P)->next_a
#define info_a(P) (P)->info_a
#define prev_a(P) (P)->prev_a
#define first_a(L) (L).first_a
#define last_a(L) (L).last_a


using namespace std;

struct aktor{
    string nama;
    int id;
};

typedef aktor infotype_a;
typedef struct elmlist_a *address_a;

struct elmlist_a{
    infotype_a info_a;
    address_a next_a;
    address_a prev_a;
};

struct list_a{
    address_a first_a;
    address_a last_a;
};

void createList_a(list_a &L);
address_a alokasi_a(infotype_a x);
void dealokasi_a(address_a P);
void insertFirst_a(list_a &L, address_a P);
void insertLast_a(list_a &L, address_a P);
void deleteFirst_a(list_a &L, address_a &P);
void deleteLast_a(list_a &L, address_a &P);
void deleteAfter_a(list_a &L, address_a prec, address_a &P);
address_a findElm_a(list_a L, int x);
void printInfo_a(list_a L);

#endif // AKTOR_H_INCLUDED
