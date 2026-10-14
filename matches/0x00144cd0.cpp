class HitEffectTrack {
  public:
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
    virtual int vfunc_10(int, int, int);
};
class Effect_144cd0 {
  public:
    int init(int, HitEffectTrack*, int);
};
extern int check(void*, int, const void*, const void*, int);
extern void* alloc(unsigned int);
extern const char type1_144cd0[];
extern const char type2_144cd0[];
int HitEffectTrack::vfunc_10(int a, int b, int c) {
    if (check((void*)c, 0, type1_144cd0, type2_144cd0, 0)) {
        Effect_144cd0* p = (Effect_144cd0*)alloc(0x28);
        if (p)
            return p->init(a, this, c);
    }
    return 0;
}