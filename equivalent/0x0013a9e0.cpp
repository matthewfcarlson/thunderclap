// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 28/30, incomplete)
// hulkfight::motion::FrameCondition::vfunc_6 @ 0x0013a9e0
class fight_Params_13a9e0 {
public:
    virtual void vfunc_0();
};

class CFightParams : public fight_Params_13a9e0 {
public:
    virtual void vfunc_0();
};

class choreo2_Driver_13a9e0 {
public:
    virtual void vfunc_0();
};

struct DriverInfo_13a9e0 {
    char pad0[8];
    int idLo;
    int idHi;
};

class choreo2_AnimationDriver_13a9e0 : public choreo2_Driver_13a9e0 {
public:
    virtual void vfunc_0();
    char pad04[0x1c];
    DriverInfo_13a9e0 *info;
    char pad24[0x23c - 0x24];
    float value;
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct DriverSet_13a9e0 {
    char pad0[0x68];
    unsigned int count;
    choreo2_Driver_13a9e0 *FUN_00222e20(unsigned int index);
};
DriverSet_13a9e0 *__fastcall FUN_00059a40(Context *ctx);

char __cdecl FUN_00018960(float a, float b, float epsilon);

class FrameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight_Params_13a9e0 *params, int c);
    char pad04[0xc];
    int idLo;
    int idHi;
    unsigned int mode;
    float threshold;
};

char FrameCondition::vfunc_6(int a, fight_Params_13a9e0 *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    DriverSet_13a9e0 *drivers = FUN_00059a40(FUN_000592a0(params));
    if (drivers == 0)
        return 0;

    unsigned int count = drivers->count;
    for (unsigned int i = 0; i < count; i++) {
        choreo2_AnimationDriver_13a9e0 *drv = dynamic_cast<choreo2_AnimationDriver_13a9e0 *>(drivers->FUN_00222e20(i));
        if (drv == 0 || drv->info == 0)
            continue;
        if (drv->info->idLo != idLo || drv->info->idHi != idHi)
            continue;
        float v = drv->value;
        switch (mode) {
        case 0: return v < threshold;
        case 1: return v <= threshold;
        case 2: return FUN_00018960(v, threshold, 1e-5f);
        case 3: return FUN_00018960(v, threshold, 1e-5f) == 0;
        case 4: return v >= threshold;
        case 5: return v > threshold;
        }
        return 0;
    }
    return 0;
}
