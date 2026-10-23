// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 26/28, incomplete)
// hulkfight::ai::TargetAngleYCondition::vfunc_6 @ 0x001265c0
#include "gen/hulkfight.h"

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern double __cdecl FUN_000189c0(float v);

struct Vec3_1265c0 {
    float x, y, z;
};

struct Body_1265c0 {
    char pad00[0x40];
    Vec3_1265c0 pos;
};

struct Holder_1265c0 {
    char pad00[0x10];
    void *f10;
};

struct Locator_1265c0;

struct Locator_1265c0 {
    char FUN_00059a50(Vec3_1265c0 *out);
};

struct Res_1265c0 {
    char pad00[0x10];
    Locator_1265c0 *loc;
    char pad14[0x328 - 0x14];
    Body_1265c0 *body;
};

struct Resolver_1265c0 {
    Res_1265c0 *FUN_00059a30();
};

struct Target_1265c0 {
    Resolver_1265c0 *FUN_000592a0();
};

float __fastcall FUN_0022d110(Vec3_1265c0 *v);

bool hulkfight::ai::TargetAngleYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * obj = (void *)__p1; int c = (int)__p2;

    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return (bool)(0);
    Res_1265c0 *r = ((Target_1265c0 *)obj)->FUN_000592a0()->FUN_00059a30();
    Body_1265c0 *body = r->body;
    if (!body)
        return (bool)(0);
    Vec3_1265c0 from;
    from.x = 0.0f;
    from.y = 0.0f;
    from.z = 0.0f;
    r->loc->FUN_00059a50(&from);
    Vec3_1265c0 d;
    d.x = body->pos.x - from.x;
    d.y = body->pos.y - from.y;
    d.z = body->pos.z - from.z;
    FUN_0022d110(&d);
    float y = d.y;
    float s;
    if (y >= -1.0f && y <= 1.0f)
        s = y;
    else if (y > 1.0f)
        s = 1.0f;
    else
        s = -1.0f;
    double ang = FUN_000189c0(s);
    switch (this->f_0c) {
    case 0: return (bool)(ang < this->f_10);
    case 1: return (bool)(ang <= this->f_10);
    case 2: return (bool)(ang == this->f_10);
    case 3: return (bool)(ang != this->f_10);
    case 4: return (bool)(ang >= this->f_10);
    case 5: return (bool)(ang > this->f_10);
    }
    return (bool)(0);
}
