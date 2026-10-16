// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 62/68, incomplete)
// hulkfight::ai::PropsToSuckCondition::vfunc_6 @ 0x0010ee40
#include "decls/address.h"
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3_10ee40 {
    float x, y, z;
    float FUN_00018990();
};

class Gauge_10ee40 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual float Value();
};

struct Level1_10ee40 {
    char pad[0x70];
    Gauge_10ee40 *gauge;
};

struct Level2_10ee40 {
    char pad[0x10];
    Level1_10ee40 *next;
};

class Unit_10ee40 {
public:
    char pad0[0xa0];
    Level2_10ee40 *state;
    char pad4[0x1a1 - 0xa4];
    bool ready;

    V3_10ee40 *FUN_001d6b40();
};

struct Roster_10ee40 {
    int FUN_001dcf50();
    Unit_10ee40 *FUN_001dc0b0(int index);
};

struct World {
    char pad0[0xc];
    Roster_10ee40 *roster;
};

struct Ref_10ee40 {
    void FUN_00059a50(V3_10ee40 *out);
};

struct Stats_10ee40 {
    char pad0[0x10];
    Ref_10ee40 *ref;
    int FUN_00035f40();
};

struct Body_10ee40 {
    Stats_10ee40 *FUN_00059a30();
};

class Target_10ee40 {
public:
    Body_10ee40 *FUN_000592a0();
};


namespace hulkfight {
namespace ai {

class PropsToSuckCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void *a1, Target_10ee40 *target, void *a3);

    char pad04[8];
    int op;
    float distance;
    bool byCount;
    char pad15[3];
    int count;
};

}
}

bool hulkfight::ai::PropsToSuckCondition::vfunc_6(void *a1, Target_10ee40 *target, void *a3)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Body_10ee40 *body = target->FUN_000592a0();
    Stats_10ee40 *stats = body->FUN_00059a30();
    if (body == 0 || stats == 0)
        return false;
    V3_10ee40 pos;
    stats->ref->FUN_00059a50(&pos);
    if (byCount) {
        int n = stats->FUN_00035f40();
        switch (op) {
        case 0: return n < count;
        case 1: return n <= count;
        case 2: return n == count;
        case 3: return n != count;
        case 4: return n >= count;
        case 5: return n > count;
        }
        return false;
    }
    int i = 0;
    if (DAT_004dd700->roster->FUN_001dcf50() <= 0)
        return false;
    Unit_10ee40 *u;
    for (;;) {
        u = DAT_004dd700->roster->FUN_001dc0b0(i);
        if (u != 0 && u->state != 0 && u->state->next != 0 && u->state->next->gauge != 0 &&
            u->state->next->gauge->Value() != 0.0f && u->ready)
            break;
        i++;
        if (!(i < DAT_004dd700->roster->FUN_001dcf50()))
            return false;
    }
    V3_10ee40 at = *u->FUN_001d6b40();
    V3_10ee40 d;
    d.x = at.x - pos.x;
    d.y = at.y - pos.y;
    d.z = at.z - pos.z;
    float len = d.FUN_00018990();
    switch (op) {
    case 0: return len < distance;
    case 1: return len <= distance;
    case 2: return len == distance;
    case 3: return len != distance;
    case 4: return len >= distance;
    case 5: return len > distance;
    }
    return false;
}
