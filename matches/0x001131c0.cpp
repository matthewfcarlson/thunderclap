typedef unsigned int u32;
extern int TypeA;
extern int TypeB;
struct Result {
    u32 Init(void*, void*);
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
    virtual u32 vfunc_10(u32 a, u32 b, void* p);
};
extern int Check(void*, int, int*, int*, int);
extern Result* Alloc(int);
u32 TokenSupressTrack::vfunc_10(u32 a, u32 b, void* p) {
    if (Check(p, 0, &TypeA, &TypeB, 0)) {
        Result* q = Alloc(0x28);
        if (q)
            return q->Init(this, p);
    }
    return 0;
}