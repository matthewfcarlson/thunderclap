struct Obj {
    char pad[0x158];
    int mVal;
};
struct Target {
    void A(int, int);
    void B();
    void C();
    void D(int);
};
struct Holder {
    int pad;
    Target* mT;
    int Handle(int, int*);
};
extern char t1[], t2[];
void* Cast(int);
Obj* Conv(void*, int, char*, char*, int);
int Holder::Handle(int a, int* p) {
    if (mT && a == 1) {
        int x = *p;
        Obj* o = Conv(Cast(x), 0, t1, t2, 0);
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