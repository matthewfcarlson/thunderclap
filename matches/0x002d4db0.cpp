class Obj_2d4db0 {
  public:
    virtual void f();
    virtual void g();
};
class ParticleEmitter {
  public:
    virtual void a();
    char pad[0x84];
    Obj_2d4db0* mObj;
    void vfunc_27(Obj_2d4db0*);
};
void ParticleEmitter::vfunc_27(Obj_2d4db0* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}