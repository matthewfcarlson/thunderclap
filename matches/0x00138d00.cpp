struct FlyingBrakeTrack {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(int, int, int);
};
struct Maker_138d00 {
    int Init(FlyingBrakeTrack*, int);
};
extern int TypeA_138d00;
extern int TypeB_138d00;
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);
int FlyingBrakeTrack::vfunc_10(int a, int b, int c) {
    if (IsType((void*)c, 0, &TypeA_138d00, &TypeB_138d00, 0)) {
        Maker_138d00* p = (Maker_138d00*)Alloc(0x40);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}