struct WallExitTrack {
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
struct Obj_142280 {
    int Init(WallExitTrack*, int);
};
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);
extern int g1_142280, g2;
int WallExitTrack::vfunc_10(int a, int b, int c) {
    if (IsType((void*)c, 0, &g1_142280, &g2, 0)) {
        Obj_142280* p = (Obj_142280*)Alloc(0x4c);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}