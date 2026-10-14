// Same code shape as 0x00138c50 (propagated; names are from that function)
typedef unsigned int u32_157250;
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
    virtual int vfunc_10(u32_157250 a, u32_157250 b, u32_157250 c);
};
struct Created_157250 {
    int init(FallTrack*, u32_157250);
};
extern int __cdecl check(u32_157250, int, const void*, const void*, int);
extern void* __cdecl alloc(unsigned int);
extern const int typeA_157250;
extern const int typeB_157250;
int FallTrack::vfunc_10(u32_157250 a, u32_157250 b, u32_157250 c) {
    if (check(c, 0, &typeA_157250, &typeB_157250, 0)) {
        Created_157250* p = (Created_157250*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}