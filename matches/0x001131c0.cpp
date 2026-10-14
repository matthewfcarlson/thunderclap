typedef unsigned int u32_1131c0;
extern int TypeA_1131c0;
extern int TypeB_1131c0;
struct Result_1131c0 {
    u32_1131c0 Init(void*, void*);
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
    virtual u32_1131c0 vfunc_10(u32_1131c0 a, u32_1131c0 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result_1131c0* Alloc(int);
u32_1131c0 TokenSupressTrack::vfunc_10(u32_1131c0 a, u32_1131c0 b, void* p) {
    if (Check(p, 0, &TypeA_1131c0, &TypeB_1131c0, 0)) {
        Result_1131c0* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}