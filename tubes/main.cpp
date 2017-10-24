#include <iostream>
#include <conio.h>
#include <windows.h>
#include "aktor.h"
#include "film.h"
#include "relasi.h"

using namespace std;

address_a inputA(){
    address_a P;
    infotype_a x;

    cout<<"Masukkan nama aktor/aktris: ";
    cin>>x.nama;
    cout<<"Masukkan id aktor/aktris(Integer): ";
    cin>>x.id;
    P=alokasi_a(x);

    return P;
}

address_f inputF(){
    address_f P;
    infotype_f x;
    cout<<"Masukkan nama film: ";
    cin>>x.nama;
    cout<<"Masukkan kode film(Integer): ";
    cin>>x.kode;
    P=alokasi_f(x);
    return P;
}

void showMostAktor(list_r LR, list_a LA){
    address_a P;
    address_r Q;
    address_a imax;
    int Count, Max, x;
    Count=0;
    Max=0;

    P=first_a(LA);
    if(first_r(LR)!=NULL){
        if(first_a(LA)!=NULL){
            while(P!=NULL){
                Q=first_r(LR);
                while(Q!=NULL){
                    if(info_a(Aktor(Q)).id == info_a(P).id){
                        Count=Count+1;
                    }
                    Q=next_r(Q);
                }
                if(Count>=Max){
                    Max=Count;
                    imax=P;
                }
                P=next_a(P);
            }
            cout<<"Aktor/aktris dengan film terbanyak"<<endl;
            cout<<info_a(imax).nama<<" dengan jumlah film yang diperankan : "<<Max<<endl;
            cout<<"Film yang dia perankan adalah"<<endl;
            x=info_a(imax).id;
            showAktor(LR, x);
        } else {
            cout<<"Tidak ada aktor/aktris di dalam List"<<endl;
        }
    } else {
        cout<<"Belum ada relasi antar film dan aktor/aktris"<<endl;
    }
}

void showLessAktor(list_r LR, list_a LA){
    address_a P;
    address_r Q;
    address_a imin;
    int Count, Min, x;
    Count=0;

    P=first_a(LA);
    if(first_r(LR)!=NULL){
        if(first_a(LA)!=NULL){
            Q=first_r(LR);

            //Pengambilan Nilai Minimal Pertama
            while(Q!=NULL){
                    if(info_a(Aktor(Q)).id == info_a(P).id){
                        Count=Count+1;
                    }
                    Q=next_r(Q);
            }
            Min=Count;
            imin=P;

            //Pengecekan Aktor dengan Film Paling Sedikit/Minimal
            while(P!=NULL){
                Q=first_r(LR);
                while(Q!=NULL){
                    if(info_a(Aktor(Q)).id == info_a(P).id){
                        Count=Count+1;
                    }
                    Q=next_r(Q);
                }
                if(Count<=Min){
                    Min=Count;
                    imin=P;
                }
                P=next_a(P);
            }
            cout<<"Aktor/aktris dengan film paling sedikit"<<endl;
            cout<<info_a(imin).nama<<" dengan jumlah film yang diperankan : "<<Min<<endl;
            cout<<"Film yang dia perankan adalah"<<endl;
            x=info_a(imin).id;
            showAktor(LR, x);
        } else {
            cout<<"Tidak ada aktor/aktris di dalam List"<<endl;
        }
    } else {
        cout<<"Belum ada relasi antar film dan aktor/aktris"<<endl;
    }
}

int main()
{
    system("cls");
    int no;
    list_a LA;
    createList_a(LA);
    address_a P;

    list_f LF;
    createList_f(LF);
    address_f Q;

    list_r LR;
    createList_r(LR);
    address_r R;

    while(no != 9){
        system("cls");
        cout<<"--------------PROGRAM RELASI AKTOR/AKTRIS DENGAN FILM-----------------"<<endl;
        cout<<endl;
        cout<<"==============================MENU===================================="<<endl;
        cout<<"|1.Tambah Aktor/Aktris Baru                                          |"<<endl;
        cout<<"|2.Tambah Film                                                       |"<<endl;
        cout<<"|3.Memperkerjakan Aktor/Aktris pada Sebuah Film                      |"<<endl;
        cout<<"|4.Memberhentikan Aktor/Aktris                                       |"<<endl;
        cout<<"|5.Menampilkan seluruh Aktor/Aktris beserta Film yang diperankannya  |"<<endl;
        cout<<"|6.Menampilkan Film yang Diperankan Seorang Aktor/Aktris             |"<<endl;
        cout<<"|7.Menampilkan Aktor/Aktris Pemeran Film Terbanyak                   |"<<endl;
        cout<<"|8.Menampilkan Aktor/Aktris Pemeran Film Paling Sedikit              |"<<endl;
        cout<<"|9.Keluar                                                            |"<<endl;
        cout<<"======================================================================"<<endl;
        cout<<endl;
        cout<<"___________________"<<endl;
        cout<<"|Menu : ";cin>>no;
        switch(no){
            case 1:
                system("cls");
                cout<<"Menambahkan Aktor/Aktris Baru"<<endl;
                cout<<endl;
                P=inputA();
                insertFirst_a(LA, P);
                system("cls");
                cout<<"Daftar Aktor/Aktris(Nama - ID)"<<endl;
                printInfo_a(LA);

                cout<<endl;
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;
            case 2:
                system("cls");
                cout<<"Menambahkan Film Baru"<<endl;
                cout<<endl;
                Q=inputF();
                insertFirst_f(LF, Q);
                system("cls");
                cout<<"Daftar Film(Nama - Kode)"<<endl;
                printInfo_f(LF);

                cout<<endl;
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;
            case 3:
                int x,y;
                system("cls");

                if(first_a(LA)==NULL && first_f(LF)==NULL){
                    cout<<"Anda belum mendaftarkan Aktor/Aktris dan Film, silahkan daftar Aktor/Aktris anda pada menu nomor 1 dan Film pada nomor 2"<<endl;
                } else if(first_a(LA)==NULL){
                    cout<<"Anda belum mendaftarkan Aktor/Aktris, silahkan daftar Aktor/Aktris anda pada menu nomor 1"<<endl;
                } else if(first_f(LF)==NULL){
                    cout<<"Anda belum mendaftarkan Film, silahkan daftar Film anda pada menu nomor 2"<<endl;
                } else {
                    P=NULL;
                    while(P==NULL){
                        system("cls");
                        cout<<"Daftar Aktor/Aktris (Nama - ID)"<<endl;
                        printInfo_a(LA); cout<<endl;
                        cout<<"Masukkan ID Aktor/Aktris yang akan memerankan film anda(Integer) : "<<endl;
                        cout<<endl;
                        cin>>x;
                        P=findElm_a(LA, x);

                        if(P==NULL){
                            system("cls");
                            cout<<"ID Aktor tidak ditemukan silahkan masukkan id lain"<<endl;
                            getch();
                        }
                    }
                    system("cls");

                    Q=NULL;
                    while(Q==NULL){
                        system("cls");
                        cout<<"Daftar Film (Nama - kode)"<<endl;
                        printInfo_f(LF); cout<<endl;
                        cout<<"Masukkan kode film yang akan diperankan(Integer) : "<<endl;
                        cout<<endl;
                        cin>>y;
                        Q=findElm_f(LF, y);

                        if(Q==NULL){
                            system("cls");
                            cout<<"Kode film tidak ditemukan silahkan masukkan kode lain"<<endl;
                            getch();
                        }

                    }

                    system("cls");
                    R=alokasi_r(P, Q);
                    insertFirst_r(LR, R);
                    cout<<"Daftar Film Beserta Seluruh Pemerannya"<<endl;
                    cout<<"(Nama Film - Kode Film || Nama Aktor - ID Aktor)"<<endl;
                    cout<<endl;
                    printInfo_r(LR);
                }
                cout<<endl;
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;

            case 4:
                x=0;
                if(first_a(LA) == NULL){
                    system("cls");
                    cout<<"Anda belum mendaftarkan Aktor/Aktris, silahkan daftar Aktor/Aktris anda pada menu nomor 1"<<endl;
                    cout<<endl;
                } else {
                    P=NULL;
                    while(P==NULL){
                        system("cls");
                        cout<<"Daftar Aktor/Aktris(Nama - ID)"<<endl;
                        printInfo_a(LA);
                        cout<<endl;
                        cout<<"Masukkan ID Aktor/Aktris yang akan diberhentikan(Integer) : "; cin>>x;
                        P=findElm_a(LA, x);

                        if(P==NULL){
                        system("cls");
                            cout<<"ID Yang anda masukkan tidak terdapat pada daftar"<<endl;
                            cout<<"Silahkan masukkan ID yang terdaftar"<<endl;
                            getch();
                        }
                    }

                    if(findRelasi_a(LR, x) == true){
                        deleteAfter_rA(LR, P);
                    }

                    if(first_a(LA) == P){
                        deleteFirst_a(LA, P);
                    } else if(last_a(LA) == P){
                        deleteLast_a(LA, P);
                    } else {
                        address_a prec;
                        deleteAfter_a(LA, prec, P);
                    }

                    system("cls");
                    cout<<"Daftar Aktor/Aktris Setelah Salah Satu Aktor/Aktris Diberhentikan"<<endl;
                    printInfo_a(LA);
                    cout<<endl;
                }
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;

            case 5:
                system("cls");
                if(first_r(LR)==NULL){
                    system("cls");
                    printInfo_r(LR);
                } else {
                    cout<<"Daftar Seluruh Film dengan Aktor/Aktris yang Memerankannya"<<endl;
                    cout<<endl;
                    printInfo_r(LR);
                }
                getch();
                break;

            case 6:
                P=NULL;
                if(first_a(LA) == NULL){
                    system("cls");
                    cout<<"Anda belum mendaftarkan Aktor/Aktris, silahkan daftar Aktor/Aktris anda pada menu nomor 1"<<endl;
                    cout<<endl;
                } else {
                    while(P == NULL){
                        system("cls");
                        cout<<"Daftar Aktor/Aktris(Nama - ID)"<<endl;
                        printInfo_a(LA);
                        cout<<endl;
                        cout<<"Pilih ID Aktor/Aktris yang Ingin Ditampilkan: ";
                        cin>>x;
                        P=findElm_a(LA, x);
                        if(P==NULL){
                            system("cls");
                            cout<<"Aktor/Aktris Tidak Ditemukan, Masukkan ID yang Tersedia pada Daftar"<<endl;
                            getch();
                        }
                    }
                    system("cls");
                    cout<<"Film yang Diperankan Aktor "<<info_a(P).nama<<endl;
                    cout<<endl;
                    showAktor(LR, x);
                }
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;

            case 7:
                system("cls");
                if(first_r(LR)==NULL){
                    cout<<"Belum Ada Aktor/Aktris yang Memerankan Film Manapun pada Daftar"<<endl;
                    cout<<"Silahkan Akses Menu Nomor.3 untuk Menghubungkan Aktor/Aktris dengan Film"<<endl;
                    cout<<endl;
                } else {
                    cout<<"Aktor/Aktris dengan Film Terbanyak"<<endl;
                    cout<<endl;
                    showMostAktor(LR, LA);
                    cout<<endl;
                }

                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;

            case 8:
                system("cls");
                if(first_r(LR)==NULL){
                    cout<<"Belum Ada Aktor/Aktris yang Memerankan Film Manapun pada Daftar"<<endl;
                    cout<<"Silahkan Akses Menu Nomor.3 untuk Menghubungkan Aktor/Aktris dengan Film"<<endl;
                    cout<<endl;
                } else {
                    cout<<"Aktor/Aktris dengan Film Paling Sedikit"<<endl;
                    cout<<endl;
                    showLessAktor(LR, LA);
                    cout<<endl;
                }

                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;
            case 9:
                system("cls");
                cout<<"Terima Kasih telah Menggunakan Program Kami."<<endl;
                getch();
                system("cls");
                break;

            default:
                system("cls");
                cout<<"Nomor menu yang anda masukkan salah"<<endl;
                cout<<endl;
                cout<<"Tekan tombol apapun untuk melanjutkan.";
                getch();
                break;
        }
    }

    return 0;
}
