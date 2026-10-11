// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// hulkfight::motion::GrappleOrientationCondition::vfunc_6 @ 0x00148390
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

class Ent {
public:
    char pad0[0x10];
    Ent *FUN_00059a30();
    char FUN_00059a50(Vec3 *out);
};

namespace fight {
class Params {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    Ent *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_3();
    virtual void vfunc_4();
};

class Actor {
public:
    char pad0[0x10];
    Ent *ent;
    float FUN_000354c0();
};

Actor *FUN_00048260(fight::Params *p);
float FUN_00224f10(Vec3 *v);
float FUN_00224fc0(float x, float y);

class GrappleOrientationCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a1, fight::Params *params, float a3);

    char pad04[0xc - 4];
    float f0c;
    float f10;
};

char GrappleOrientationCondition::vfunc_6(int a1, fight::Params *params, float a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    Ent *e = params->FUN_000592a0();
    e->FUN_00059a30();
    Actor *actor = FUN_00048260(params);
    if (actor == 0)
        return 0;
    Vec3 a;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    e->FUN_00059a50(&a);
    Vec3 b;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    actor->ent->FUN_00059a50(&b);
    Vec3 v;
    v.x = a.x;
    v.y = a.y;
    v.z = a.z;
    v.x = v.x - b.x;
    v.y = 0;
    v.z = v.z - b.z;
    v.FUN_0022d110();
    float r1 = FUN_00224f10(&v);
    float r2 = actor->FUN_000354c0();
    float r3 = FUN_00224fc0(r2, r1);
    float r4 = FUN_00224fc0(r3, f0c);
    union {
        float f;
        unsigned int u;
    } d;
    d.f = r4;
    d.u &= 0x7fffffff;
    float limit = f10 * 0.5f;
    if (limit > d.f)
        return 1;
    return 0;
}
