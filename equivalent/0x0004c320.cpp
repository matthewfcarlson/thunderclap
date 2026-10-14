// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackYCondition::vfunc_7 @ 0x0004c320
struct Obj_4c320 {
    char pad00[0x2c];
    float pushbackY;                // 0x2c
};

struct Params {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Obj_4c320 *GetObject();       // slot 3
};

bool FUN_00018960(float a, float b, float eps);

class CCollisionPushbackYCondition {
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

bool CCollisionPushbackYCondition::vfunc_7(Params *params)
{
    Obj_4c320 *obj = params->GetObject();
    if (!obj)
        return false;
    float value = obj->pushbackY;
    switch (op) {
    case 0:
        return value < threshold;
    case 1:
        return value <= threshold;
    case 2:
        return FUN_00018960(value, threshold, 1.0e-5f);
    case 3:
        return !FUN_00018960(value, threshold, 1.0e-5f);
    case 4:
        return value >= threshold;
    case 5:
        return value > threshold;
    }
    return false;
}
