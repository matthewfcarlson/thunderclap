class SpriteParticleEmitter {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int vfunc_4();
};
class Obj_2d66b0 {
  public:
    int run(SpriteParticleEmitter*);
};
extern "C" Obj_2d66b0* alloc(int);
int SpriteParticleEmitter::vfunc_4() {
    Obj_2d66b0* p = alloc(0x1e0);
    if (p)
        return p->run(this);
    return 0;
}