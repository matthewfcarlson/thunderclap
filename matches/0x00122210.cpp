// Same code shape as 0x001131c0 (propagated; names are from that function)
typedef unsigned int u32_122210;
extern int TypeA_122210;
extern int TypeB_122210;
struct Result_122210 {
    u32_122210 Init(void*, void*);
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
    virtual u32_122210 vfunc_10(u32_122210 a, u32_122210 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_122210* Alloc(int);
u32_122210 TokenSupressTrack::vfunc_10(u32_122210 a, u32_122210 b, void* p) {
    if (Check(p, 0, &TypeA_122210, &TypeB_122210, 0)) {
        Result_122210* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}