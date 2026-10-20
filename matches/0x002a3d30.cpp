#include "compat/ptr.h"
extern "C" char DAT_0042d88c[];

class Ref_2a3d30 {
  public:
    virtual void vfunc0();
    virtual void Release();
};

extern "C" void __cdecl FUN_00267090(void*);

class ParticleSystem {
  public:
    char pad[0xa4];
    Ref_2a3d30* volatile a;
    Ref_2a3d30* volatile b;
    void Cleanup();
    ParticleSystem* vfunc_2(unsigned char p);
};

ParticleSystem* ParticleSystem::vfunc_2(unsigned char p) {
    volatile int* q = (volatile int*)this;
    *q = (hulk_intptr)DAT_0042d88c;
    Ref_2a3d30* x = a;
    if (x) {
        x->Release();
        a = 0;
    }
    Ref_2a3d30* y = b;
    if (y) {
        y->Release();
        b = 0;
    }
    Cleanup();
    if (p & 1) {
        FUN_00267090(this);
    }
    return this;
}
