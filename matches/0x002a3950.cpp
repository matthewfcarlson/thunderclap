extern "C" void _ReadWriteBarrier();
extern int vt1_2a3950;
class Ref_2a3950 {
  public:
    virtual void f0();
    virtual void Release();
};
class DrawableContainer_2a3950 {
  public:
    void* vptr;
    ~DrawableContainer_2a3950() throw();
};
class ParticleSystem_2a3950 : public DrawableContainer_2a3950 {
  public:
    char pa4[160];
    Ref_2a3950* aa4;
    Ref_2a3950* aa8;
    ~ParticleSystem_2a3950() throw();
};
ParticleSystem_2a3950::~ParticleSystem_2a3950() throw() {
    vptr = &vt1_2a3950;
    _ReadWriteBarrier();
    if (aa4) {
        aa4->Release();
        aa4 = 0;
    }
    if (aa8) {
        aa8->Release();
        aa8 = 0;
    }
}
