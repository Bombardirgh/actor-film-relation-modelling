/**  cout<<"List Aktor"<<endl;
    cout<<endl;
    list_a L1;
    infotype_a x;
    address_a P;

    createList_a(L1);

    x.nama = "AAA";
    x.id = 111;
    P = alokasi_a(x);
    insertFirst_a(L1, P);
    printInfo_a(L1);

    x.nama = "BBB";
    x.id = 222;
    P = alokasi_a(x);
    insertFirst_a(L1, P);
    printInfo_a(L1);

    x.nama = "CCC";
    x.id = 333;
    P = alokasi_a(x);
    insertLast_a(L1, P);
    printInfo_a(L1);

    x.nama = "DDD";
    x.id = 444;
    P = alokasi_a(x);
    insertLast_a(L1, P);
    printInfo_a(L1);

    address_a R;
    deleteLast_a(L1, R);
    printInfo_a(L1);

    address_a S;
    deleteFirst_a(L1, S);
    printInfo_a(L1);

    address_a T;
    deleteLast_a(L1, T);
    printInfo_a(L1);

    x.nama = "AAB";
    x.id = 211;
    P = alokasi_a(x);
    insertFirst_a(L1, P);
    printInfo_a(L1);

    x.nama = "AAC";
    x.id = 212;
    P = alokasi_a(x);
    insertLast_a(L1, P);
    printInfo_a(L1);

    cout<<endl;
    cout<<endl;

    cout<<"List Film"<<endl;
    cout<<endl;
    list_f L2;
    infotype_f o;
    address_f Q;

    createList_f(L2);

    o.nama = "ZZZ";
    o.kode = 1111;
    Q = alokasi_f(o);
    insertFirst_f(L2, Q);
    printInfo_f(L2);

    o.nama = "YYY";
    o.kode = 2222;
    Q = alokasi_f(o);
    insertFirst_f(L2, Q);
    printInfo_f(L2);

    o.nama = "XXX";
    o.kode = 3333;
    Q = alokasi_f(o);
    insertLast_f(L2, Q);
    printInfo_f(L2);

    o.nama = "VVV";
    o.kode = 4444;
    Q = alokasi_f(o);
    insertLast_f(L2, Q);
    printInfo_f(L2);

    address_f V;
    deleteLast_f(L2, V);
    printInfo_f(L2);

    address_f W;
    deleteFirst_f(L2, W);
    printInfo_f(L2);

    address_f X;
    deleteLast_f(L2, X);
    printInfo_f(L2);

    o.nama = "ZZY";
    o.kode = 2111;
    Q = alokasi_f(o);
    insertFirst_f(L2, Q);
    printInfo_f(L2);

    o.nama = "ZZX";
    o.kode = 2122;
    Q = alokasi_f(o);
    insertLast_f(L2, Q);
    printInfo_f(L2);

    cout<<endl;
    cout<<endl;

    cout<<"List Relasi"<<endl;
    cout<<endl;

    list_r LR;
    createList_r(LR);
    address_r PR;
    address_a RA;
    address_f RF;

    RA=findElm_a(L1, 111);
    RF=findElm_f(L2, 1111);
    PR=alokasi_r(RA, RF);
    insertFirst_r(LR, PR);
    printInfo_r(LR);

    RA=findElm_a(L1, 111);
    RF=findElm_f(L2, 2111);
    PR=alokasi_r(RA, RF);
    insertFirst_r(LR, PR);
    printInfo_r(LR);

    RA=findElm_a(L1, 211);
    RF=findElm_f(L2, 2111);
    PR=alokasi_r(RA, RF);
    insertFirst_r(LR, PR);
    printInfo_r(LR);

    RA=findElm_a(L1, 212);
    RF=findElm_f(L2, 2122);
    PR=alokasi_r(RA, RF);
    insertFirst_r(LR, PR);
    printInfo_r(LR);

    RA=findElm_a(L1, 212);
    RF=findElm_f(L2, 2111);
    PR=alokasi_r(RA, RF);
    insertFirst_r(LR, PR);
    printInfo_r(LR);

    RF=findElm_f(L2, 1111);
    deleteAfter_rF(LR, RF);
    printInfo_r(LR);

    showMostAktor(LR, L1);
    showLessAktor(LR, L1);
**/
