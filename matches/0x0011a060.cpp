typedef unsigned int u32_11a060;
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
    virtual u32_11a060 vfunc_10(u32_11a060 a, u32_11a060 b, u32_11a060 c);
};
struct Object {
    u32_11a060 init(MotionLocatorTrack*, u32_11a060);
};
extern int MatchType(u32_11a060, int, const void*, const void*, int);
extern Object* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];
u32_11a060 MotionLocatorTrack::vfunc_10(u32_11a060 a, u32_11a060 b, u32_11a060 c) {
    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        Object* p = Alloc(0x30);
        if (p)
            return p->init(this, c);
    }
    return 0;
}