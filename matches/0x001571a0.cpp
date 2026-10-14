typedef unsigned int u32_1571a0;
extern int RTTI1_1571a0, RTTI2;
struct HitPushbackTrack {
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
    virtual u32_1571a0 v10(u32_1571a0, u32_1571a0, u32_1571a0);
};
struct Result_1571a0 {
    u32_1571a0 setup(HitPushbackTrack*, u32_1571a0);
};
extern int check(void*, int, int*, int*, int);
extern Result_1571a0* alloc(int);
u32_1571a0 HitPushbackTrack::v10(u32_1571a0 a, u32_1571a0 b, u32_1571a0 c) {
    if (check((void*)c, 0, &RTTI1_1571a0, &RTTI2, 0)) {
        Result_1571a0* p = alloc(0x44);
        if (p)
            return p->setup(this, c);
    }
    return 0;
}