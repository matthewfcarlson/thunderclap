// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 29/36, incomplete)
// hulkfight::motion::FrameReachedCondition::vfunc_6 @ 0x0013ab50
class fight_Params {
public:
    virtual void vfunc_0();
};

class CFightParams : public fight_Params {
public:
    virtual void vfunc_0();
};

class choreo2_Driver {
public:
    virtual void vfunc_0();
};

struct DriverInfo {
    char pad0[8];
    int idLo;
    int idHi;
    char pad10[4];
    float scale;
};

class choreo2_AnimationDriver : public choreo2_Driver {
public:
    virtual void vfunc_0();
    char pad04[0x1c];
    DriverInfo *info;
    char pad24[0x224 - 0x24];
    char wraps;
    char pad225[3];
    float rate;
    float wrapA;
    float wrapB;
    char pad234[8];
    float value;
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct DriverSet {
    char pad0[0x68];
    unsigned int count;
    choreo2_Driver *FUN_00222e20(unsigned int index);
};
DriverSet *__fastcall FUN_00059a40(Context *ctx);

struct Clock {
    float FUN_000860c0();
};
struct World {
    char pad0[0x58];
    Clock *clock;
};
extern World *DAT_004dd700;

class FrameReachedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight_Params *params, int c);
    char pad04[0xc];
    int idLo;
    int idHi;
    float threshold;
};

char FrameReachedCondition::vfunc_6(int a, fight_Params *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    DriverSet *drivers = FUN_00059a40(FUN_000592a0(params));
    if (drivers == 0)
        return 0;
    unsigned int count = drivers->count;
    for (unsigned int i = 0; i < count; i++) {
        choreo2_AnimationDriver *drv = dynamic_cast<choreo2_AnimationDriver *>(drivers->FUN_00222e20(i));
        if (drv == 0 || drv->info == 0)
            continue;
        if (drv->info->idLo != idLo || drv->info->idHi != idHi)
            continue;
        float lo = drv->value;
        float hi = drv->info->scale * drv->rate * DAT_004dd700->clock->FUN_000860c0() + lo;
        if (hi < lo) {
            float t = hi;
            hi = lo;
            lo = t;
        }
        if (lo < threshold && threshold <= hi)
            return 1;
        if (!drv->wraps)
            return 0;
        float wa = drv->wrapA;
        float wb = drv->wrapB;
        if (lo < wb && wb <= hi) {
            return lo + (wa - wb) < threshold && threshold <= hi + (wa - wb);
        }
        if (lo < wa && wa <= hi) {
            return lo + (wb - wa) < threshold && threshold <= hi + (wb - wa);
        }
        return 0;
    }
    return 0;
}
