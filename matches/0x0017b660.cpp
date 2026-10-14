// Same code shape as 0x00138c50 (propagated; names are from that function)
typedef unsigned int u32_17b660;
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
    virtual int vfunc_10(u32_17b660 a, u32_17b660 b, u32_17b660 c);
};
struct Created_17b660 {
    int init(FallTrack*, u32_17b660);
};
extern int __cdecl check(u32_17b660, int, const void*, const void*, int);
extern void* __cdecl alloc(unsigned int);
extern const int typeA_17b660;
extern const int typeB_17b660;
int FallTrack::vfunc_10(u32_17b660 a, u32_17b660 b, u32_17b660 c) {
    if (check(c, 0, &typeA_17b660, &typeB_17b660, 0)) {
        Created_17b660* p = (Created_17b660*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}