// Same code shape as 0x001131c0 (propagated; names are from that function)
typedef unsigned int u32_122160;
extern int TypeA_122160;
extern int TypeB_122160;
struct Result_122160 {
    u32_122160 Init(void*, void*);
};
struct TokenSupressTrack {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual u32_122160 vfunc_10(u32_122160 a, u32_122160 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_122160* Alloc(int);
u32_122160 TokenSupressTrack::vfunc_10(u32_122160 a, u32_122160 b, void* p) {
    if (Check(p, 0, &TypeA_122160, &TypeB_122160, 0)) {
        Result_122160* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}