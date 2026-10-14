// Same code shape as 0x001571a0 (propagated; names are from that function)
typedef unsigned int u32_17bbc0;
extern int RTTI1_17bbc0, RTTI2;
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
    virtual u32_17bbc0 v10(u32_17bbc0, u32_17bbc0, u32_17bbc0);
};
struct Result_17bbc0 {
    u32_17bbc0 setup(HitPushbackTrack*, u32_17bbc0);
};
extern int check(void*, int, int*, int*, int);
extern Result_17bbc0* alloc(int);
u32_17bbc0 HitPushbackTrack::v10(u32_17bbc0 a, u32_17bbc0 b, u32_17bbc0 c) {
    if (check((void*)c, 0, &RTTI1_17bbc0, &RTTI2, 0)) {
        Result_17bbc0* p = alloc(0x44);
        if (p)
            return p->setup(this, c);
    }
    return 0;
}