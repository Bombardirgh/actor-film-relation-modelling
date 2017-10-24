#include "relasi.h"

void createList_r(list_r &L){
    first_r(L) = NULL;
    last_r(L) = NULL;
}

address_r alokasi_r(address_a P, address_f Q){
    address_r R = new elmlist_r;
    Aktor(R) = P;
    Film(R) = Q;
    next_r(R) = NULL;
    prev_r(R) = NULL;

    return R;
}

void dealokasi_r(address_r P){
    delete P;
}

void insertFirst_r(list_r &L, address_r P){
    if(first_r(L) != NULL){
        next_r(P)=first_r(L);
        prev_r(first_r(L))=P;
        first_r(L)=P;
    } else {
        first_r(L)=P;
        last_r(L)=P;
    }
}

void deleteFirst_r(list_r &L, address_r &P){
    if(first_r(L) != NULL){
        if(next_r(first_r(L)) != NULL){
            P=first_r(L);
            first_r(L)=next_r(P);
            prev_r(first_r(L))=NULL;
            next_r(P)=NULL;
            prev_r(P)=NULL;
            dealokasi_r(P);
        } else {
            P=first_r(L);
            dealokasi_r(P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteLast_r(list_r &L, address_r &P){
    if(first_r(L) != NULL){
        if(next_r(first_r(L)) != NULL){
            P=last_r(L);
            last_r(L)=prev_r(P);
            next_r(last_r(L))=NULL;
            prev_r(P)=NULL;
            next_r(P)=NULL;
            dealokasi_r(P);
        } else {
            P=first_r(L);
            deleteFirst_r(L, P);
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteAfter_rA(list_r& L, address_a &P){
    if(first_r(L) != NULL){
        address_r Q = first_r(L);
        while(Q != NULL){
            if(Aktor(Q) != P){
                Q=next_r(Q);
            } else {
                address_r prec, del;
                if(first_r(L) == Q ){
                     if(next_r(Q) == NULL){
                        del=Q;
                        Q=NULL;
                        deleteFirst_r(L, del);
                     } else {
                        del=Q;
                        Q=next_r(Q);
                        deleteFirst_r(L, del);
                     }
                } else if(Q == last_r(L)){
                    del=Q;
                    Q=NULL;
                    deleteLast_r(L, del);
                } else {
                    del=Q;
                    prec=prev_r(Q);
                    Q=next_r(Q);
                    next_r(prec)=Q;
                    prev_r(Q)=prec;
                    prev_r(del)=NULL;
                    next_r(del)=NULL;
                    dealokasi_r(del);
                }
             }
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void deleteAfter_rF(list_r &L,address_f &P){
    if(first_r(L) != NULL){
        address_r(Q)=first_r(L);
        while(Q != NULL){
            if(Film(Q) != P){
                Q=next_r(Q);
            } else {
                address_r prec, del;
                if(first_r(L) == Q && next_r(Q) == NULL){
                    del=Q;
                    Q=next_r(Q);
                    deleteFirst_r(L, del);
                } else if(Q == last_r(L)){
                    del=Q;
                    Q=NULL;
                    deleteLast_r(L, del);
                } else {
                    del=Q;
                    prec=prev_r(Q);
                    Q=next_r(Q);
                    next_r(prec)=Q;
                    prev_r(Q)=prec;
                    prev_r(del)=NULL;
                    next_r(del)=NULL;
                    dealokasi_r(del);
                }
            }
        }
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

void showAktor(list_r L, int x){
    if(first_r(L) != NULL){
        cout<<endl;
        address_r P=first_r(L);
        while(P!=NULL){
            if(info_a(Aktor(P)).id == x){
                cout<<info_a(Aktor(P)).nama," - ", info_a(Aktor(P)).id;
                cout<<" || ";
                cout<<info_f(Film(P)).nama, " - ", info_f(Film(P)).kode;
                cout<<endl;
            }
            P=next_r(P);
        }
        cout<<endl;
    } else {
        cout<<"List Kosong"<<endl;
    }
}

void showFilm(list_r L, int x){
    if(first_r(L) != NULL){
        address_r P=first_r(L);
        while(P!=NULL){
            if(info_f(Film(P)).kode == x){
                cout<<info_f(Film(P)).nama<<" - "<< info_f(Film(P)).kode;
                cout<<" || ";
                cout<<info_a(Aktor(P)).nama<<" - "<< info_a(Aktor(P)).id;
            }
            P=next_r(P);
        }
        cout<<endl;
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}

bool findRelasi_a(list_r L, int x){
    bool hasil;
    if(first_r(L) != NULL){
        address_r P=first_r(L);
        while(P != NULL && info_a(Aktor(P)).id != x){
            P=next_r(P);
        }
        if(info_a(Aktor(P)).id == x){
            hasil=true;
        } else {
            hasil=false;
        }
    } else {
        hasil=false;
    }

    return hasil;
}

void printInfo_r(list_r L){
    if(first_r(L) != NULL){
        address_r P=first_r(L);
        cout<<"__________________________________"<<endl;
        while(P!=NULL){
            cout<<"|"<<info_f(Film(P)).nama<<" - "<<info_f(Film(P)).kode;
            cout<<" || ";
            cout<<info_a(Aktor(P)).nama<<" - "<<info_a(Aktor(P)).id<<endl;
            P=next_r(P);
        }
        cout<<"__________________________________"<<endl;
        cout<<endl;
    } else {
        cout<<endl;
        cout<<"List Kosong"<<endl;
    }
}
