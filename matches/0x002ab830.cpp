extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2ab830[];
extern void* g_base_vftable[];
class Ref_2ab830 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class OldParticleSystemLoader_2ab830 {
  public:
    void* vptr;
    char p[0x10];
    Ref_2ab830* m14;
    Ref_2ab830* m18;
    OldParticleSystemLoader_2ab830* f2(unsigned char flags);
};
void operator delete(void*);
OldParticleSystemLoader_2ab830* OldParticleSystemLoader_2ab830::f2(unsigned char flags) {
    vptr = g_vftable_2ab830;
    _ReadWriteBarrier();
    if (m14) {
        m14->f1();
        m14 = 0;
    }
    if (m18) {
        m18->f1();
        m18 = 0;
    }
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
