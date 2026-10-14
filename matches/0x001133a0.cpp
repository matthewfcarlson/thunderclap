// Same code shape as 0x001131c0 (propagated; names are from that function)
typedef unsigned int u32_1133a0;
extern int TypeA_1133a0;
extern int TypeB_1133a0;
struct Result_1133a0 {
    u32_1133a0 Init(void*, void*);
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
    virtual u32_1133a0 vfunc_10(u32_1133a0 a, u32_1133a0 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1133a0* Alloc(int);
u32_1133a0 TokenSupressTrack::vfunc_10(u32_1133a0 a, u32_1133a0 b, void* p) {
    if (Check(p, 0, &TypeA_1133a0, &TypeB_1133a0, 0)) {
        Result_1133a0* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}