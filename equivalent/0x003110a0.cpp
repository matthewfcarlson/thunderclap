// STATUS: equivalent (tools/equiv.py level 3: 19796 inputs, branch coverage 12/12)
// physics::ArticulatedPhysicsObject::vfunc_5 @ 0x003110a0
#include "compat/ptr.h"
class Child_3110a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11(float a, float b, float dt);
};

struct Body_3110a0 {
    char pad0[0x5c];
    float spin[3];
    char pad68[0x94 - 0x68];
    unsigned char frozen;
};

namespace physics {
class PhysicsObject {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float dt);
};

class ArticulatedPhysicsObject : public PhysicsObject {
public:
    virtual void vfunc_5(float dt);
    char pad04[0xc];
    Body_3110a0 *body;
    char pad14[0xc0 - 0x14];
    float velocity[3];
    char padcc[0x1f8 - 0xcc];
    Child_3110a0 **children;
    char pad1fc[4];
    int childCount;
    char pad204[0x20c - 0x204];
    float elapsed;
    char pad210[0x224 - 0x210];
    float dt;
    float dampLinear;
    float dampAngular;
    float dampOverall;
};
}

void physics::ArticulatedPhysicsObject::vfunc_5(float dtArg)
{
    dt = dtArg;
    PhysicsObject::vfunc_5(dtArg);
    if (body->frozen != 0)
        return;

    float a = 1.0f - dtArg * dampLinear;
    if (!(0.0f < a))
        a = 0.0f;
    float b = 1.0f - dtArg * dampAngular;
    if (!(0.0f < b))
        b = 0.0f;
    hulk_freg c = 1.0f - dtArg * dampOverall;
    if (!(0.0f < c))
        c = 0.0f;

    velocity[0] = c * velocity[0];
    velocity[1] = c * velocity[1];
    velocity[2] = c * velocity[2];
    float *spin = body->spin;
    spin[0] = c * spin[0];
    spin[1] = c * spin[1];
    spin[2] = c * spin[2];

    for (int i = 0; i < childCount; i++)
        children[i]->vfunc_11(a, b, dtArg);

    elapsed = dt + elapsed;
}
