#include "aktor.h"

void createList_a(list_a &L){
    first_a(L)=NULL;
    last_a(L)=NULL;
}

address_a alokasi_a(infotype_a x){
    address_a P;

    P = new elmlist_a;
    info_a(P).id=x.id;
    info_a(P).nama=x.nama;
    prev_a(P)=NULL;
    next_a(P)=NULL;
    return P;
}

void dealokasi_a(address_a P){
    delete P;
}

void insertFirst_a(list_a &L,address_a P){
    if(first_a(L)!=NULL){
        prev_a(first_a(L))=P;
        next_a(P)=first_a(L);
        first_a(L)=P;
    } else {
        first_a(L)=P;
        last_a(L)=P;
    }
}

void insertLast_a(list_a &L, address_a P){
    if(first_a(L)!=NULL){
        if(next_a(first_a(L))!=NULL){
            next_a(last_a(L))=P;
            prev_a(P)=last_a(L);
            last_a(L)=P;
        } else {
            next_a(last_a(L))=P;
            prev_a(P)=last_a(L);
            last_a(L)=P;
        }
    } else {
        insertFirst_a(L, P);
    }
}

void deleteFirst_a(list_a &L, address_a &P){
    if(first_a(L)!=NULL){
        P=first_a(L);
        if(next_a(P)!=NULL){
            first_a(L)=next_a(P);
            prev_a(P)=NULL;
            prev_a(first_a(L))=NULL;
            next_a(P)=NULL;
            dealokasi_a(P);
        } else {
            dealokasi_a(P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteLast_a(list_a &L, address_a &P){
    if(first_a(L)!=NULL){
            if(next_a(first_a(L))!=NULL){
                P=last_a(L);
                last_a(L)=prev_a(P);
                next_a(last_a(L))=NULL;
                prev_a(P)=NULL;
                dealokasi_a(P);
            } else {
                P=first_a(L);
                deleteFirst_a(L, P);
            }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteAfter_a(list_a &L, address_a prec, address_a &P){
    if(first_a(L)!=NULL){
        if(first_a(L)==P){
            deleteFirst_a(L, P);
        } else if (last_a(L)==P){
            deleteLast_a(L, P);
        } else {
            prec=prev_a(P);
            prev_a(next_a(P))=prec;
            next_a(prec)=next_a(P);
            next_a(P)=NULL;
            prev_a(P)=NULL;
            dealokasi_a(P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

address_a findElm_a(list_a L, int x){
    address_a P=first_a(L);
    if(P!=NULL){
        while((P!=NULL) && (info_a(P).id!=x)){
            P=next_a(P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
        P=NULL;
    }

    return P;
}

void printInfo_a(list_a L){
    cout<<endl;
    if(first_a(L)!=NULL){
        address_a P=first_a(L);
        cout<<"__________________________________"<<endl;
        while(P!=NULL){
            cout<<"|"<<info_a(P).nama<<" - "<<info_a(P).id<<endl;
            P=next_a(P);
        }
        cout<<"__________________________________"<<endl;
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}
