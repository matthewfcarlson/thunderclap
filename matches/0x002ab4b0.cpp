extern "C" void _ReadWriteBarrier();
extern int vt1_2ab4b0, vt2;
class Ref_2ab4b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class OldParticleSystemLoader_2ab4b0 {
  public:
    void* vptr;
    char p[0x10];
    Ref_2ab4b0* a14;
    Ref_2ab4b0* a18;
    ~OldParticleSystemLoader_2ab4b0() throw();
};
OldParticleSystemLoader_2ab4b0::~OldParticleSystemLoader_2ab4b0() throw() {
    vptr = &vt1_2ab4b0;
    _ReadWriteBarrier();
    if (a14) {
        a14->Release();
        a14 = 0;
    }
    if (a18) {
        a18->Release();
        a18 = 0;
    }
    vptr = &vt2;
}
