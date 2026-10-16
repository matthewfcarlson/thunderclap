// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 28/28)
// hulkfight::motion::HitThrowAction::vfunc_3 @ 0x00151fd0
#include "decls/address.h"
struct V3_151fd0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Name_151fd0 {
    unsigned int lo, hi;
    void FUN_0027b040(const char *s);
};

struct Xform_151fd0 {
    char data[0x54];
    void FUN_0022be40(const V3_151fd0 *pos);
    void FUN_00221d20(float v);
};

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_151fd0 name;
    char pad10[4];
    int mode;
    Xform_151fd0 xform;
    JointDriver *FUN_002248f0(int a);
};

struct Linked_151fd0 {
    void FUN_0003ee70(int handle);
};

class RefObj_151fd0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Linked_151fd0 *linked;
    int kind;
};

struct TargetInfo {
    char pad0[0x28];
    V3_151fd0 pos;
    char pad34[0x84 - 0x34];
    RefObj_151fd0 *ref;
    int handle;
};

class OwnerObj_151fd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TargetInfo *v3();
};

struct Body_151fd0 {
    void FUN_00222890(JointDriver *d, float a, float b, float c, float e, float f, float g);
};

struct Stats_151fd0 {
    char pad0[0x12c];
    int handle;
};

struct Fighter_151fd0 {
    void FUN_00059a50(V3_151fd0 *out);
};

struct Config_151fd0 {
    char pad0[0x14];
    char flag14;
    char pad15[3];
    float f18;
    char pad1c[4];
    float f20;
    float f24;
    float f28;
};

struct Hook_151fd0 {
    char pad0[0x124];
    int enabled;
    void FUN_00029b50(int a, RefObj_151fd0 *b, int c);
};

struct World {
    char pad0[0x20];
    Hook_151fd0 *hook;
};


void *__cdecl FUN_00263ea0(unsigned int size);
Fighter_151fd0 *__fastcall FUN_000592a0(void *owner);
Stats_151fd0 *__fastcall FUN_00059a30(Fighter_151fd0 *f);
Body_151fd0 *__fastcall FUN_00059a40(Fighter_151fd0 *f);
float __cdecl FUN_00224f10(V3_151fd0 *v);

class HitThrowAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_151fd0 *cfg;
    OwnerObj_151fd0 *owner;
    JointDriver *driver;
    RefObj_151fd0 *ref;
    int handle;
    float length;
    V3_151fd0 dir;
};

bool HitThrowAction::vfunc_3(int a, int b)
{
    if (!owner)
        return false;
    Fighter_151fd0 *fighter = FUN_000592a0(owner);
    Stats_151fd0 *stats = FUN_00059a30(fighter);
    Body_151fd0 *body = FUN_00059a40(fighter);
    if (!body)
        return false;
    TargetInfo *t = owner->v3();
    if (!t)
        return false;

    V3_151fd0 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    fighter->FUN_00059a50(&origin);

    Config_151fd0 *c = cfg;
    float c20 = c->f20;
    float c24 = c->f24;
    float c28 = c->f28;
    void *mem = FUN_00263ea0(0x70);
    JointDriver *d;
    if (mem != 0)
        d = ((JointDriver *)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("hitThrow");
    int mode = 1;
    if (cfg->flag14) {
        mode = 3;
        float r = FUN_00224f10(&t->pos);
        driver->xform.FUN_00221d20(r + cfg->f18);
    }
    driver->mode = mode;
    driver->AddRef();
    driver->xform.FUN_0022be40(&origin);
    body->FUN_00222890(driver, -1.0f, c20, 1.0f, c24, c28, -1.0f);

    handle = t->handle;
    dir = t->pos;
    length = dir.FUN_0022d110();

    RefObj_151fd0 *r = t->ref;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    if (r && r->kind == 1 && r->linked)
        r->linked->FUN_0003ee70(stats->handle);
    if (ref && DAT_004dd700 && DAT_004dd700->hook && DAT_004dd700->hook->enabled)
        DAT_004dd700->hook->FUN_00029b50(stats->handle, ref, handle);
    return true;
}
