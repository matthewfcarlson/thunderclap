class Obj {
  public:
    virtual void f();
    virtual void g();
};
class ParticleEmitter {
  public:
    virtual void a();
    char pad[0x84];
    Obj* mObj;
    void vfunc_27(Obj*);
};
void ParticleEmitter::vfunc_27(Obj* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}