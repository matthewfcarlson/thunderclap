// Same code shape as 0x0011a060 (propagated; names are from that function)
typedef unsigned int u32_121f40;
struct MotionLocatorTrack {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual u32_121f40 vfunc_10(u32_121f40 a, u32_121f40 b, u32_121f40 c);
};
struct Object {
    u32_121f40 init(MotionLocatorTrack*, u32_121f40);
};
extern int MatchType(u32_121f40, int, const void*, const void*, int);
extern Object* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];
u32_121f40 MotionLocatorTrack::vfunc_10(u32_121f40 a, u32_121f40 b, u32_121f40 c) {
    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        Object* p = Alloc(0x30);
        if (p)
            return p->init(this, c);
    }
    return 0;
}