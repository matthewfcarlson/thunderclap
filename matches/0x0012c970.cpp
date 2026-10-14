// Same code shape as 0x001131c0 (propagated; names are from that function)
typedef unsigned int u32_12c970;
extern int TypeA_12c970;
extern int TypeB_12c970;
struct Result_12c970 {
    u32_12c970 Init(void*, void*);
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
    virtual u32_12c970 vfunc_10(u32_12c970 a, u32_12c970 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_12c970* Alloc(int);
u32_12c970 TokenSupressTrack::vfunc_10(u32_12c970 a, u32_12c970 b, void* p) {
    if (Check(p, 0, &TypeA_12c970, &TypeB_12c970, 0)) {
        Result_12c970* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}