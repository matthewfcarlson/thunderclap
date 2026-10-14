extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
typedef unsigned int u32_10e250;
struct AIHistoryCountTrack {
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
    virtual u32_10e250 vfunc_10(int, int, void*);
};
extern void FUN_00344e74(void*, int, void*, void*, int);
u32_10e250 AIHistoryCountTrack::vfunc_10(int a, int b, void* p) {
    FUN_00344e74(p, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_00494b60), 0);
    return 0;
}