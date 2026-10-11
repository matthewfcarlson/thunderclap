// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 26/28, incomplete)
// hulkfight::ai::TargetAngleYCondition::vfunc_6 @ 0x001265c0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern double __cdecl FUN_000189c0(float v);

struct Vec3 {
    float x, y, z;
};

struct Body {
    char pad00[0x40];
    Vec3 pos;
};

struct Holder {
    char pad00[0x10];
    void *f10;
};

struct Locator;

struct Locator {
    char FUN_00059a50(Vec3 *out);
};

struct Res {
    char pad00[0x10];
    Locator *loc;
    char pad14[0x328 - 0x14];
    Body *body;
};

struct Resolver {
    Res *FUN_00059a30();
};

struct Target {
    Resolver *FUN_000592a0();
};

float __fastcall FUN_0022d110(Vec3 *v);

class TargetAngleYCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, void *obj, int c);
    char pad04[8];
    int op;
    float value;
};

char TargetAngleYCondition::vfunc_6(int a, void *obj, int c)
{
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Res *r = ((Target *)obj)->FUN_000592a0()->FUN_00059a30();
    Body *body = r->body;
    if (!body)
        return 0;
    Vec3 from;
    from.x = 0.0f;
    from.y = 0.0f;
    from.z = 0.0f;
    r->loc->FUN_00059a50(&from);
    Vec3 d;
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
    switch (op) {
    case 0: return ang < value;
    case 1: return ang <= value;
    case 2: return ang == value;
    case 3: return ang != value;
    case 4: return ang >= value;
    case 5: return ang > value;
    }
    return 0;
}
