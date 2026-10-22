extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2d3ab0[];
extern void* g_base_2d3ab0[];
void operator delete(void*);
class Ref_2d3ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ParticleGenerator_2d3ab0 {
  public:
    void* vptr;
    void Fin();
};
class ParticlePlaneGenerator_2d3ab0 : public ParticleGenerator_2d3ab0 {
  public:
    char pad[0x18];
    unsigned m1c;
    char pad2[0x08];
    Ref_2d3ab0* m28;
    Ref_2d3ab0** m2c;
    ~ParticlePlaneGenerator_2d3ab0();
};
ParticlePlaneGenerator_2d3ab0::~ParticlePlaneGenerator_2d3ab0() {
    vptr = g_vftable_2d3ab0;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    for (unsigned i = 0; i < m1c; i++) {
        Ref_2d3ab0** p = &m2c[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (m2c)
        operator delete(m2c);
    vptr = g_base_2d3ab0;
    Fin();
}
