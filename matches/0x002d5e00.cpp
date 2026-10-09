class Obj {
  public:
    virtual void a();
    virtual void b();
    char pad[0x14];
    int kind;
};
class SpriteParticleEmitter {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(Obj* p);
    char p0[0xc];
    int enabled;
    char p1[0x94];
    Obj* mObj;
};
void SpriteParticleEmitter::vfunc_8(Obj* p) {
    if (p)
        p->a();
    if (mObj)
        mObj->b();
    mObj = p;
    if (p && (p->kind == 1 || p->kind == 3 || p->kind == 7 || p->kind == 2 || p->kind == 4 || p->kind == 5 ||
              p->kind == 6))
        enabled = 1;
    else
        enabled = 0;
}