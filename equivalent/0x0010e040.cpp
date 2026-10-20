// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 28/30, incomplete)
// hulkfight::ai::FormationReadyCondition::vfunc_6 @ 0x0010e040
#include "gen/hulkfight.h"

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3_10e040 {
    float x, y, z;
};
struct Pair_10e040 {
    int a, b;
};

struct Body_10e040 {
    char pad0[0x40];
    Vec3_10e040 pos;
};

struct Actor_10e040 {
    char pad0[8];
    int idA;                 // 0x08
    int idB;                 // 0x0c
    char pad10[0x328 - 0x10];
    Body_10e040 *body;              // 0x328
    char pad32c[0x1b38 - 0x32c];
    float value;             // 0x1b38
    char pad1b3c[4];
    int nameLo;              // 0x1b40
    int nameHi;              // 0x1b44
    void FUN_00023d30(const char *name);
};

struct Chain_10e040 {
    Actor_10e040 *FUN_00059a30();
};

struct Owner_10e040 {
    Chain_10e040 *FUN_000592a0();
};

struct Registry_10e040 {
    char pad0[0x150];
    int cur;                 // 0x150
    char pad154[0x2c8 - 0x154];
    int lo;                  // 0x2c8
    int hi;                  // 0x2cc
    void FUN_00065dd0(Pair_10e040 *key);
    void FUN_000671b0(Vec3_10e040 *pos);
};
Registry_10e040 *__cdecl FUN_000678d0();

namespace hulkfight { namespace ai {  }}
bool hulkfight::ai::FormationReadyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; Owner_10e040 * owner = (Owner_10e040 *)__p1; int unused3 = (int)__p2;

    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return (bool)(0);
    Actor_10e040 *actor = owner->FUN_000592a0()->FUN_00059a30();
    if (!actor)
        return (bool)(0);
    Body_10e040 *body = actor->body;
    if (!body)
        return (bool)(0);

    Vec3_10e040 pos = body->pos;
    if ((actor->nameLo | actor->nameHi) == 0)
        actor->FUN_00023d30("default");

    Pair_10e040 key;
    key.a = actor->idA;
    key.b = actor->idB;
    FUN_000678d0()->FUN_00065dd0(&key);
    FUN_000678d0()->FUN_000671b0(&pos);

    int cur = FUN_000678d0()->cur;
    if (cur < FUN_000678d0()->lo)
        return (bool)(0);
    cur = FUN_000678d0()->cur;
    if (cur > FUN_000678d0()->hi)
        return (bool)(0);

    // The original's jump table sends every mode 0..5 to the same test.
    if ((*(unsigned int *)&this->f_0c) > 5)
        return (bool)(0);
    return (bool)(actor->value != 0.0f);
}
