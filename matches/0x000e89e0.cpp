#include "compat/ptr.h"
extern "C" char DAT_0040c3d0[];
class Ref_e89e0 {
  public:
    virtual void f();
    virtual void g();
};
class Mid_e89e0 {
  public:
    void Done();
};
class FEParticleAnimation {
  public:
    virtual void a();
    char pad[0x64 - 4];
    Ref_e89e0* volatile mRef;
    void Cleanup();
};
void FEParticleAnimation::Cleanup() {
    *(int* volatile*)this = (int*)((hulk_intptr)DAT_0040c3d0);
    Ref_e89e0* r = mRef;
    if (r) {
        r->g();
        mRef = 0;
    }
    ((Mid_e89e0*)this)->Done();
}
