struct Obj_c2b90 {
    char pad[0x158];
    int mVal;
};
struct Target_c2b90 {
    void A(int, int);
    void B();
    void C();
    void D(int);
};
struct Holder_c2b90 {
    int pad;
    Target_c2b90* mT;
    int Handle(int, int*);
};
extern char t1_c2b90[], t2[];
void* Cast(int);
Obj_c2b90* Conv(void*, int, char*, char*, int);
int Holder_c2b90::Handle(int a, int* p) {
    if (mT && a == 1) {
        int x = *p;
        Obj_c2b90* o = Conv(Cast(x), 0, t1_c2b90, t2, 0);
        if (o) {
            int v = o->mVal;
            mT->A(v, 0);
            mT->B();
            mT->C();
            mT->D(0x266);
            return 0;
        }
    }
    return -1;
}