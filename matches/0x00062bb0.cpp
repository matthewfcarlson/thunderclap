typedef unsigned int u32;
struct Helper {
    u32 call(u32, u32, u32);
};
struct CSmartPropEventTrack {
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
    virtual void f10();
    virtual void f11();
    virtual u32 vfunc_12(u32);
    virtual void f13();
    char pad[8];
    u32 c;
    u32 pad10;
    u32 d;
};
extern void* __cdecl FUN_0008d690(int);
u32 CSmartPropEventTrack::vfunc_12(u32 arg) {
    void* p = FUN_0008d690(0x28);
    if (p)
        return ((Helper*)p)->call(arg, d, c);
    return 0;
}