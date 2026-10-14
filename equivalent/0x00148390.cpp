// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// hulkfight::motion::GrappleOrientationCondition::vfunc_6 @ 0x00148390
struct Vec3_148390 {
    float x, y, z;
    float FUN_0022d110();
};

class Ent_148390 {
public:
    char pad0[0x10];
    Ent_148390 *FUN_00059a30();
    char FUN_00059a50(Vec3_148390 *out);
};

namespace fight {
class Params {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    Ent_148390 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void vfunc_3();
    virtual void vfunc_4();
};

class Actor_148390 {
public:
    char pad0[0x10];
    Ent_148390 *ent;
    float FUN_000354c0();
};

Actor_148390 *FUN_00048260(fight::Params *p);
float FUN_00224f10(Vec3_148390 *v);
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
    Ent_148390 *e = params->FUN_000592a0();
    e->FUN_00059a30();
    Actor_148390 *actor = FUN_00048260(params);
    if (actor == 0)
        return 0;
    Vec3_148390 a;
    a.x = 0;
    a.y = 0;
    a.z = 0;
    e->FUN_00059a50(&a);
    Vec3_148390 b;
    b.x = 0;
    b.y = 0;
    b.z = 0;
    actor->ent->FUN_00059a50(&b);
    Vec3_148390 v;
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
