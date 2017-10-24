#include "film.h"

void createList_f(list_f &L){
    first_f(L)=NULL;
    last_f(L)=NULL;
}

address_f alokasi_f(infotype_f x){
    address_f P;

    P = new elmlist_f;
    info_f(P).kode=x.kode;
    info_f(P).nama=x.nama;
    prev_f(P)=NULL;
    next_f(P)=NULL;
    return P;
}

void dealokasi_f(address_f P){
    delete P;
}

void insertFirst_f(list_f &L,address_f P){
    if(first_f(L)!=NULL){
        prev_f(first_f(L))=P;
        next_f(P)=first_f(L);
        first_f(L)=P;
    } else {
        first_f(L)=P;
        last_f(L)=P;
    }
}

void insertLast_f(list_f &L, address_f P){
    if(first_f(L)!=NULL){
        if(next_f(first_f(L))!=NULL){
            next_f(last_f(L))=P;
            prev_f(P)=last_f(L);
            last_f(L)=P;
        } else {
            next_f(last_f(L))=P;
            prev_f(P)=last_f(L);
            last_f(L)=P;
        }
    } else {
        insertFirst_f(L, P);
    }
}

void deleteFirst_f(list_f &L, address_f &P){
    if(first_f(L)!=NULL){
        P=first_f(L);
        if(next_f(P)!=NULL){
            first_f(L)=next_f(P);
            prev_f(P)=NULL;
            prev_f(first_f(L))=NULL;
            next_f(P)=NULL;
            dealokasi_f(P);
        } else {
            dealokasi_f(P);
            P=NULL;
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteLast_f(list_f &L, address_f &P){
    if(first_f(L)!=NULL){
            if(next_f(first_f(L))!=NULL){
                P=last_f(L);
                last_f(L)=prev_f(P);
                next_f(last_f(L))=NULL;
                prev_f(P)=NULL;
                dealokasi_f(P);
            } else {
                P=first_f(L);
                deleteFirst_f(L, P);
            }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

address_f findElm_f(list_f L, int x){
    address_f P = first_f(L);
    if(P!=NULL){
        while((P!=NULL) && (info_f(P).kode!=x)){
            P=next_f(P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
        P=NULL;
    }

    return P;
}

void printInfo_f(list_f L){
    cout<<endl;
    if(first_f(L)!=NULL){
        address_f P=first_f(L);
        cout<<"__________________________________"<<endl;
        while(P!=NULL){
            cout<<"|"<<info_f(P).nama<<" - "<<info_f(P).kode<<endl;
            P=next_f(P);
        }
        cout<<"__________________________________"<<endl;
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}
