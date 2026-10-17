// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 2/2)
// FEParticleAnimation::vfunc_3 @ 0x000e15b0
#include "decls/data/engine/pure3d/prop.h"

struct RenderInterface {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(int); virtual void vfunc_16(int); virtual void vfunc_17(int, void*);
};
struct Particle {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(int, int);
};
struct Holder {
    RenderInterface* renderer;
    void FUN_00293da0(int, int, int);
};
class FEParticleAnimation {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    char pad04[0x10];
    char pose[0x40];
    int particleValue;
    char pad58[0xc];
    Particle* particle;
};
void FEParticleAnimation::vfunc_3() {
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_15(0);
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_17(0, pose);
    int value = particleValue;
    (*(Holder**)&DAT_0052c2ac)->FUN_00293da0(value, value, value);
    if (particle) particle->vfunc_8(0, 0);
    (*(Holder**)&DAT_0052c2ac)->renderer->vfunc_16(0);
}