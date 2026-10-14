typedef unsigned int u32_138c50;
struct FallTrack {
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
    virtual int vfunc_10(u32_138c50 a, u32_138c50 b, u32_138c50 c);
};
struct Created_138c50 {
    int init(FallTrack*, u32_138c50);
};
extern int __cdecl check(u32_138c50, int, const void*, const void*, int);
extern void* __cdecl alloc(unsigned int);
extern const int typeA_138c50;
extern const int typeB_138c50;
int FallTrack::vfunc_10(u32_138c50 a, u32_138c50 b, u32_138c50 c) {
    if (check(c, 0, &typeA_138c50, &typeB_138c50, 0)) {
        Created_138c50* p = (Created_138c50*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}