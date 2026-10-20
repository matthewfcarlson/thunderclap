// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 10/10)
// hulkfight::motion::HitFloatAction::vfunc_3 @ 0x0014f980
extern "C" double sqrt(double);

struct Vec3_14f980 {
    float x, y, z;
};

struct Transform_14f980 {
    void FUN_0022be40(const Vec3_14f980 *pos);
    void FUN_00221d20(float v);
};

struct ResourceName_14f980 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class FloatObject_14f980 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_14f980 name;
    int mode;
    Transform_14f980 transform;
    FloatObject_14f980 *FUN_002248f0(int id);
};

struct Target_14f980 {
    char pad0[0x28];
    Vec3_14f980 size;
    char pad34[0x64 - 0x34];
    int field64;
};

struct Scene_14f980 {
    char pad0[0x40];
    Vec3_14f980 origin;
    void FUN_00222890(FloatObject_14f980 *obj, float a, float b, float c, float d, float e, float f);
};

struct HitData_14f980 {
    char pad0[0x14];
    unsigned char useSize;
    char pad15[3];
    float sizeBias;
    float p;
    float q;
    float r;
};

void *__fastcall FUN_000592a0(void *owner);
void *__fastcall FUN_00059a30(void *x);
Scene_14f980 *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);
float __cdecl FUN_00224f10(Vec3_14f980 *v);

class Owner_14f980 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Target_14f980 *vfunc_3();
};

class HitFloatAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    HitData_14f980 *data;
    Owner_14f980 *owner;
    FloatObject_14f980 *floatObj;
    char pad28[4];
    float outLen;
    float outA;
    float outB;
};

bool HitFloatAction::vfunc_3(int a, int b)
{
    if (!owner)
        return false;
    void *h = FUN_000592a0(owner);
    FUN_00059a30(h);
    Scene_14f980 *scene = FUN_00059a40(h);
    if (!scene)
        return false;
    Target_14f980 *target = owner->vfunc_3();
    if (!target)
        return false;

    Vec3_14f980 pos = scene->origin;
    float p = data->p;
    float q = data->q;
    float r = data->r;

    void *mem = FUN_00263ea0(0x70);
    FloatObject_14f980 *obj = 0;
    if (mem)
        obj = ((FloatObject_14f980 *)mem)->FUN_002248f0(0);
    floatObj = obj;
    obj->name.FUN_0027b040("hitFloat");

    int mode = 1;
    if (data->useSize) {
        mode = 3;
        floatObj->transform.FUN_00221d20(FUN_00224f10(&target->size) + data->sizeBias);
    }
    floatObj->mode = mode;
    floatObj->vfunc_0();
    floatObj->transform.FUN_0022be40(&pos);
    scene->FUN_00222890(floatObj, -1.0f, p, 1.0f, q, r, -1.0f);
    outLen = (float)sqrt(target->size.x * target->size.x + target->size.z * target->size.z);
    outA = target->size.y;
    outB = *(float *)&target->field64;
    return true;
}
