typedef unsigned int u32_1891f0;
struct Track {
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
    virtual u32_1891f0 v10(u32_1891f0 a, u32_1891f0 b, u32_1891f0 c);
};
struct BallAndChainReturnTrack : Track {
    virtual u32_1891f0 v10(u32_1891f0 a, u32_1891f0 b, u32_1891f0 c);
};
struct Obj_1891f0 {
    u32_1891f0 Init(BallAndChainReturnTrack*, u32_1891f0);
};
extern int IsType(void*, int, int, int, int);
extern void* Alloc(unsigned int);
extern int typeA_1891f0, typeB;
u32_1891f0 BallAndChainReturnTrack::v10(u32_1891f0 a, u32_1891f0 b, u32_1891f0 c) {
    if (IsType((void*)c, 0, (int)&typeB, (int)&typeA_1891f0, 0)) {
        Obj_1891f0* p = (Obj_1891f0*)Alloc(0x48);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}