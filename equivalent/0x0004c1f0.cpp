// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackVelocityCondition::vfunc_7 @ 0x0004c1f0
struct Obj_4c1f0 {
    char pad00[0x28];
    float vx, vy, vz;               // 0x28
};

struct Params {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Obj_4c1f0 *GetObject();       // slot 3
};

bool FUN_00018960(float a, float b, float eps);
extern "C" double sqrt(double);

class CCollisionPushbackVelocityCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Params *params);
    char pad04[8];
    unsigned int op;                // 0x0c
    float threshold;                // 0x10
};

bool CCollisionPushbackVelocityCondition::vfunc_7(Params *params)
{
    Obj_4c1f0 *obj = params->GetObject();
    if (!obj)
        return false;
    float speed = (float)sqrt(obj->vx * obj->vx + obj->vy * obj->vy + obj->vz * obj->vz);
    switch (op) {
    case 0:
        return speed < threshold;
    case 1:
        return speed <= threshold;
    case 2:
        return FUN_00018960(speed, threshold, 1.0e-5f);
    case 3:
        return !FUN_00018960(speed, threshold, 1.0e-5f);
    case 4:
        return speed >= threshold;
    case 5:
        return speed > threshold;
    }
    return false;
}
