// Same code shape as 0x00119fb0 (propagated; names are from that function)
typedef unsigned int u32_19ada0;
extern int TypeA_19ada0, TypeB;
struct MotionBoostTrack {
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
    virtual int vfunc_10(u32_19ada0 a, u32_19ada0 b, void* p);
};
struct Params {
    int Init(MotionBoostTrack*, void*);
};
extern int IsKindOf(void*, int, int*, int*, int);
extern void* Alloc(unsigned int);
int MotionBoostTrack::vfunc_10(u32_19ada0 a, u32_19ada0 b, void* p) {
    if (IsKindOf(p, 0, &TypeA_19ada0, &TypeB, 0)) {
        Params* q = (Params*)Alloc(0x34);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}