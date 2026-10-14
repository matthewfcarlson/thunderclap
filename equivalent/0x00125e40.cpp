// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 18/18)
// hulkfight::ai::TargetVelocityXZCondition::vfunc_6 @ 0x00125e40
extern "C" double sqrt(double);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float epsilon);

struct Vec3_125e40 {
    float x, y, z;
};

struct Body_125e40 {
    char pad0[0x328];
    char *pad328;
};

struct Velocity_125e40 {
    char pad0[0x50];
    Vec3_125e40 value;
};

struct Actor_125e40 {
    char pad0[0x328];
    Velocity_125e40 *target;
};

struct Chain_125e40 {
    Actor_125e40 *FUN_00059a30();
};

struct Owner_125e40 {
    Chain_125e40 *FUN_000592a0();
};

class TargetVelocityXZCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_125e40 *owner, int unused3);
    char pad4[8];
    int mode;
    float threshold;
};

char TargetVelocityXZCondition::vfunc_6(int unused1, Owner_125e40 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Velocity_125e40 *v = owner->FUN_000592a0()->FUN_00059a30()->target;
    if (!v)
        return 0;

    float x = v->value.x;
    float z = v->value.z;
    float speed = (float)sqrt((double)(x * x + z * z));
    switch (mode) {
    case 0:
        return speed < threshold;
    case 1:
        return speed <= threshold;
    case 2:
        return FUN_00018960(speed, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(speed, threshold, 1e-5f);
    case 4:
        return speed >= threshold;
    case 5:
        return speed > threshold;
    }
    return 0;
}
