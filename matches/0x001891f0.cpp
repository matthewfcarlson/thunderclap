typedef unsigned int u32;
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
    virtual u32 v10(u32 a, u32 b, u32 c);
};
struct BallAndChainReturnTrack : Track {
    virtual u32 v10(u32 a, u32 b, u32 c);
};
struct Obj {
    u32 Init(BallAndChainReturnTrack*, u32);
};
extern int IsType(void*, int, int, int, int);
extern void* Alloc(unsigned int);
extern int typeA, typeB;
u32 BallAndChainReturnTrack::v10(u32 a, u32 b, u32 c) {
    if (IsType((void*)c, 0, (int)&typeB, (int)&typeA, 0)) {
        Obj* p = (Obj*)Alloc(0x48);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}