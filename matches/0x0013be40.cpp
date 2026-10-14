// Same code shape as 0x001131c0 (propagated; names are from that function)
typedef unsigned int u32_13be40;
extern int TypeA_13be40;
extern int TypeB_13be40;
struct Result_13be40 {
    u32_13be40 Init(void*, void*);
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
    virtual u32_13be40 vfunc_10(u32_13be40 a, u32_13be40 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_13be40* Alloc(int);
u32_13be40 TokenSupressTrack::vfunc_10(u32_13be40 a, u32_13be40 b, void* p) {
    if (Check(p, 0, &TypeA_13be40, &TypeB_13be40, 0)) {
        Result_13be40* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}