// Same code shape as 0x00138c50 (propagated; names are from that function)
typedef unsigned int u32;
struct FallTrack {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
    virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
    virtual int vfunc_10(u32 a, u32 b, u32 c);
};
struct Created { int init(FallTrack*, u32); };
extern int __cdecl check(u32, int, const void*, const void*, int);
extern void* __cdecl alloc(unsigned int);
extern const int typeA;
extern const int typeB;
int FallTrack::vfunc_10(u32 a, u32 b, u32 c) {
    if (check(c, 0, &typeA, &typeB, 0)) {
        Created* p = (Created*)alloc(0x38);
        if (p) return p->init(this, c);
    }
    return 0;
}