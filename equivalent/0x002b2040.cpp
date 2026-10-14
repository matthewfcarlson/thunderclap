// STATUS: equivalent (tools/equiv.py level 3: 278 inputs, branch coverage 6/6)
// pure3d::MultiController::vfunc_7 @ 0x002b2040
struct Controller_2b2040 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Advance(float dt, int flag);       // slot 6
};

struct Blend_2b2040 {
    float weight;
    float a;
    int mode;
};

float __cdecl FUN_002899e0(Blend_2b2040 *blend, void *target, float c, float d, float e, float f, bool g);

namespace pure3d {
class MultiController {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsFrozen(int time);                 // slot 19

    char pad4[0x14];
    float dt;               // 0x18
    float speed;            // 0x1c
    char pad20[4];
    float phase;            // 0x24
    float rateA;            // 0x28
    float rateB;            // 0x2c
    char pad30[4];
    Blend_2b2040 blend;            // 0x34
    char pad40[0x44 - 0x40];
    unsigned int childCount;    // 0x44
    Controller_2b2040 **children;      // 0x48
};

void MultiController::vfunc_7()
{
    bool active = IsFrozen(blend.mode) == 0;
    phase = FUN_002899e0(&blend, (char *)this + 0x40, phase,
                         (speed * dt) * 0.001f, rateA * speed, rateB * speed, active);
    if (blend.weight > 0.0f) {
        for (unsigned int i = 0; i < childCount; i++)
            children[i]->Advance(dt, 1);
    }
    dt = 0;
}
}
