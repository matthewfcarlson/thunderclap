// Same code shape as 0x0011a060 (propagated; names are from that function)
typedef unsigned int u32;
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
    virtual u32 vfunc_10(u32 a, u32 b, u32 c);
};
struct Object {
    u32 init(MotionLocatorTrack*, u32);
};
extern int MatchType(u32, int, const void*, const void*, int);
extern Object* Alloc(unsigned int);
extern const char ParamDesc[];
extern const char FightParamsDesc[];
u32 MotionLocatorTrack::vfunc_10(u32 a, u32 b, u32 c) {
    if (MatchType(c, 0, ParamDesc, FightParamsDesc, 0)) {
        Object* p = Alloc(0x30);
        if (p)
            return p->init(this, c);
    }
    return 0;
}