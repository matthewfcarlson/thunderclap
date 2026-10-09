struct Thing { unsigned int a[11]; };
Thing* __fastcall FUN_002f8d70(Thing* p) {
    p->a[0]=0;
    p->a[1]=0;
    p->a[2]=0;
    p->a[3]=0;
    p->a[4]=0xffffffff;
    p->a[5]=0xffffffff;
    p->a[10]=0;
    return p;
}