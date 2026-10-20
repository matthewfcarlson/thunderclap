#include "compat/ptr.h"
extern "C" char DAT_0040bfe0[];
extern "C" void _ReadWriteBarrier();
class FEParticleSystem {
  public:
    virtual FEParticleSystem* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[0x24];
    struct Ref_f1250* ptr;
};
class Ref_f1250 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void cleanup(FEParticleSystem*);
FEParticleSystem* FEParticleSystem::vfunc_0(unsigned char flags) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040bfe0);
    _ReadWriteBarrier();
    if (ptr) {
        ptr->Release();
        ptr = 0;
    }
    if (flags & 1)
        cleanup(this);
    return this;
}