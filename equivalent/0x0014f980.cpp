// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 10/10)
// hulkfight::motion::HitFloatAction::vfunc_3 @ 0x0014f980
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
};

struct Transform {
    void FUN_0022be40(const Vec3 *pos);
    void FUN_00221d20(float v);
};

struct ResourceName {
    char data[12];
    void FUN_0027b040(const char *name);
};

class FloatObject {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName name;
    int mode;
    Transform transform;
    FloatObject *FUN_002248f0(int id);
};

struct Target {
    char pad0[0x28];
    Vec3 size;
    char pad34[0x64 - 0x34];
    int field64;
};

struct Scene {
    char pad0[0x40];
    Vec3 origin;
    void FUN_00222890(FloatObject *obj, float a, float b, float c, float d, float e, float f);
};

struct HitData {
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
Scene *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);
float __cdecl FUN_00224f10(Vec3 *v);

class Owner {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Target *vfunc_3();
};

class HitFloatAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    HitData *data;
    Owner *owner;
    FloatObject *floatObj;
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
    Scene *scene = FUN_00059a40(h);
    if (!scene)
        return false;
    Target *target = owner->vfunc_3();
    if (!target)
        return false;

    Vec3 pos = scene->origin;
    float p = data->p;
    float q = data->q;
    float r = data->r;

    void *mem = FUN_00263ea0(0x70);
    FloatObject *obj = 0;
    if (mem)
        obj = ((FloatObject *)mem)->FUN_002248f0(0);
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
