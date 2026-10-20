#include "compat/ptr.h"
extern "C" char DAT_0040bfe0[];
class Ref_e8a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEParticleSystem {
  public:
    char pad[0x28];
    Ref_e8a70* volatile mRef;
    void Cleanup();
};
void FEParticleSystem::Cleanup() {
    *(volatile hulk_uintptr*)this = ((hulk_intptr)DAT_0040bfe0);
    Ref_e8a70* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
}