extern "C" char DAT_0041b3f4[];
extern "C" char DAT_004e2210[];
class H {
  public:
    void Fn(int);
};
class ProjectileEffect {
  public:
    virtual void A();
    virtual void B();
    virtual ProjectileEffect* vfunc_2(unsigned char);
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad0[0x14];
    int m18;
    int m1c;
    char pad20[4];
    class Obj {
      public:
        virtual void A();
        virtual void B();
    };
    Obj* m24;
    void Cleanup();
};
class Global_19b350 {
  public:
    void Free(void*, int);
};
extern H* __cdecl FUN_0027f250();
extern Global_19b350* g_19b350;
ProjectileEffect* ProjectileEffect::vfunc_2(unsigned char flags) {
    *(int*)this = ((int)DAT_0041b3f4);
    if (m1c) {
        H* h = FUN_0027f250();
        h->Fn(m1c);
    }
    if (m24) {
        m24->B();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Cleanup();
    if (flags & 1)
        ((Global_19b350*)((int)DAT_004e2210))->Free(this, 0x50);
    return this;
}