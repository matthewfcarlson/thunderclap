// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 70/74, incomplete)
// hulkfight::ai::PathLocatorTestCondition::vfunc_6 @ 0x0011fa30
#include "decls/address.h"
extern "C" int atexit(void (*)());

struct Key_11fa30 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50();
    void FUN_0027b040(int word);
    char FUN_0027af90(Key_11fa30 *other);
};

struct V3_11fa30 {
    float x, y, z;
    float FUN_00018990();
};

extern Key_11fa30 DAT_004e0ce8;
extern Key_11fa30 DAT_004e0d20;
extern Key_11fa30 DAT_004e0d00;
extern Key_11fa30 DAT_004e0d48;
extern unsigned int DAT_004e0d50;
void FUN_00363f10();

class RefCounted_11fa30 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount_11fa30 {
    char pad0[0x18];
    bool FUN_00059a50(V3_11fa30 *out);
};

struct Target_11fa30 : RefCounted_11fa30 {
    char pad04[0x3c];
    V3_11fa30 pos;
};

struct SpecialSub_11fa30 {
    char pad0[0x48];
    unsigned __int64 id;
    char padA8[0x18];
    float f0c0;
    float f0c4;
};

struct Special_11fa30 {
    char pad0[0x58];
    SpecialSub_11fa30 sub;
};

struct Stats_11fa30 {
    char pad0[0x10];
    Mount_11fa30 *mount;
    char pad14[0x328 - 0x14];
    Target_11fa30 *target;
    char pad32c[0x1ca0 - 0x32c];
    Special_11fa30 *special;
    char pad1ca4[0x1d70 - 0x1ca4];
    unsigned __int64 id1d70;
};

class Locator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3_11fa30 *out);
};

struct Registry_11fa30 {
    const char *FUN_001ff950(V3_11fa30 pos, int a, int b, float lo, float hi);
    Locator *FUN_001fc8c0(unsigned __int64 id);
};

struct World {
    char pad0[0x28];
    Registry_11fa30 *registry;
};


namespace fight {
class Params {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v3();
    virtual void v4();
};

struct Owner_11fa30 { char pad[4]; };
Owner_11fa30 *__fastcall FUN_000592a0(void *x);
Stats_11fa30 *__fastcall FUN_00059a30(Owner_11fa30 *o);
char __cdecl FUN_00018960(float a, float b, float eps);

union ArgSlot_11fa30 {
    fight::Params *p;
    char b;
    float f;
    int i;
};

namespace hulkfight {
namespace ai {
class PathLocatorTestCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a0, ArgSlot_11fa30 a1, int a2);
    char pad04[8];
    int name;
    unsigned int mode;
    float threshold;
    char b18;
    char b19;
    char b1a;
    char b1b;
    char b1c;
    char b1d;
    char b1e;
    char b1f;
    V3_11fa30 vec20;
};

char PathLocatorTestCondition::vfunc_6(int a0, ArgSlot_11fa30 a1, int a2)
{
    struct Frame {
        char pad10[3];
        char eq;
        union {
            Key_11fa30 t;
            V3_11fa30 tp;
            float len;
        } u;
        V3_11fa30 pos;
        V3_11fa30 d;
    } f;

    if ((DAT_004e0d50 & 1) == 0) {
        DAT_004e0d50 |= 1;
        DAT_004e0d48.FUN_0027af00();
        atexit(FUN_00363f10);
    }
    Registry_11fa30 *reg = DAT_004dd700->registry;
    if (reg == 0)
        return false;
    if (dynamic_cast<CFightParams *>(a1.p) == 0)
        return false;
    DAT_004e0d48.FUN_0027b040(name);
    Stats_11fa30 *stats = FUN_00059a30(FUN_000592a0(a1.p));
    if (stats == 0)
        return false;
    f.pos.x = 0.0f;
    f.pos.y = 0.0f;
    f.pos.z = 0.0f;
    stats->mount->FUN_00059a50(&f.pos);
    Target_11fa30 *target = stats->target;

    if (!b18 && !b1e) {
        a1.b = 0;
        const char *pt = 0;
        bool query = false;
        f.u.t.FUN_0027af10(DAT_004e0ce8.lo, DAT_004e0ce8.hi);
        f.eq = DAT_004e0d48.FUN_0027af90(&f.u.t);
        f.u.t.FUN_0027af50();
        if (f.eq) {
            pt = reg->FUN_001ff950(f.pos, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
            query = true;
        } else {
            f.u.t.FUN_0027af10(DAT_004e0d20.lo, DAT_004e0d20.hi);
            f.eq = DAT_004e0d48.FUN_0027af90(&f.u.t);
            f.u.t.FUN_0027af50();
            if (f.eq) {
                if (target != 0) {
                    pt = reg->FUN_001ff950(target->pos, 2, 0, -3.40282347e+38f, 3.40282347e+38f);
                    query = true;
                }
            } else {
                f.u.t.FUN_0027af10(DAT_004e0d00.lo, DAT_004e0d00.hi);
                f.eq = DAT_004e0d48.FUN_0027af90(&f.u.t);
                f.u.t.FUN_0027af50();
                if (f.eq) {
                    pt = reg->FUN_001ff950(target->pos, 2, 2, -3.40282347e+38f, 3.40282347e+38f);
                    query = true;
                }
            }
        }
        if (query && pt != 0) {
            if (reg->FUN_001fc8c0(FUN_0027b020(pt)) != 0) {
                a1.b = 1;
                return a1.b;
            }
        }
        if (!b1f)
            return a1.b;
        for (int i = 0; i < 6; i++) {
            const char *p2 = reg->FUN_001ff950(f.pos, i, 0, -vec20.y, vec20.y);
            if (p2 != 0 && reg->FUN_001fc8c0(FUN_0027b020(p2)) != 0)
                return true;
        }
        return a1.b;
    }

    Special_11fa30 *sp = stats->special;
    Registry_11fa30 *reg2 = DAT_004dd700->registry;
    Locator *loc = 0;
    if (b1b && sp != 0 && &sp->sub != 0)
        loc = reg2->FUN_001fc8c0(sp->sub.id);
    else if (b1c)
        loc = reg2->FUN_001fc8c0(stats->id1d70);
    else if (b1d)
        loc = reg2->FUN_001fc8c0(*(unsigned __int64 *)&DAT_004e0d48);
    if (b1e)
        return loc != 0;
    a1.f = threshold;
    if (b19 && sp != 0 && &sp->sub != 0)
        a1.f = sp->sub.f0c0;
    if (b1a && sp != 0 && &sp->sub != 0)
        a1.f = sp->sub.f0c4;
    if (loc == 0)
        return false;
    loc->v8(&f.u.tp);
    f.d.x = f.u.tp.x - f.pos.x;
    f.d.y = f.u.tp.y - f.pos.y;
    f.d.z = f.u.tp.z - f.pos.z;
    f.u.len = f.d.FUN_00018990();
    unsigned int m = mode;
    if (m > 5)
        return false;
    switch (m) {
    case 0:
        return f.u.len < a1.f;
    case 1:
        return f.u.len <= a1.f;
    case 2:
        return FUN_00018960(f.u.len, a1.f, 0.00001f);
    case 3:
        return !FUN_00018960(f.u.len, a1.f, 0.00001f);
    case 4:
        return f.u.len >= a1.f;
    default:
        return f.u.len > a1.f;
    }
}
}
}
