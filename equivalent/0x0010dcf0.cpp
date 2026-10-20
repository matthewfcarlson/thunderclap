// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 30/30)
// hulkfight::ai::TokenCondition::vfunc_6 @ 0x0010dcf0
#include "decls/data/game/global.h"

struct V3_10dcf0 {
    float x, y, z;
};

struct Actor_10dcf0 {
    char pad0000[0x1b84];
    char flag1b84;
    char pad1b85[0x1cee - 0x1b85];
    unsigned char byte1cee;
};

struct Singleton_10dcf0 {
    Actor_10dcf0* FUN_00066390(V3_10dcf0* v);
    int FUN_00065c50();
    char FUN_00065ab0();
};
Singleton_10dcf0* FUN_000678d0();

struct Handle_10dcf0 {
    Actor_10dcf0* FUN_00059a30();
};

namespace fight {
class Params {
public:
    virtual void p0();
};
}

class CFightParams : public fight::Params {
public:
    Handle_10dcf0* FUN_000592a0();
};

struct Info_10dcf0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Entity {
    char pad00[0x80];
    Info_10dcf0 info;
};

struct World {
    Entity* FUN_00086310();
};

struct Obj10_10dcf0 {
    char FUN_00059a50(V3_10dcf0* out);
};
struct Obj124_10dcf0 {
    char pad00[0x10];
    Obj10_10dcf0* p10;
};
struct Player_10dcf0 {
    char pad00[0x124];
    Obj124_10dcf0* p124;
};

struct Game_10dcf0 {
    char pad00[0x20];
    Player_10dcf0* player;
    char pad24[0x54 - 0x24];
    World* world;
};
extern Game_10dcf0* DAT_004dd700;

namespace hulkfight {
namespace ai {
class TokenCondition {
public:
    char pad00[0xc];
    char needsA;
    char needsB;
    bool vfunc_6(int arg0, fight::Params* params, int arg2);
};

bool TokenCondition::vfunc_6(int arg0, fight::Params* params, int arg2)
{
    if (!dynamic_cast<CFightParams*>(params))
        return false;
    Actor_10dcf0* actor = ((CFightParams*)params)->FUN_000592a0()->FUN_00059a30();
    if (!actor)
        return false;
    Entity* e = DAT_004dd700->world->FUN_00086310();
    if (e) {
        Info_10dcf0* info = &e->info;
        int a = info->FUN_00088fa0();
        int b = info->FUN_00088fb0();
        if (a == 7 && b == 2)
            return true;
    }
    if ((float)(int)actor->byte1cee == (*(float*)&DAT_003f32e0))
        return true;
    V3_10dcf0 pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    DAT_004dd700->player->p124->p10->FUN_00059a50(&pos);
    if (actor == FUN_000678d0()->FUN_00066390(&pos)) {
        if (!FUN_000678d0()->FUN_00065ab0())
            return true;
    }
    bool blocked = false;
    if (needsA) {
        if (FUN_000678d0()->FUN_00065c50() == 0) {
            if (!FUN_000678d0()->FUN_00065ab0())
                blocked = true;
        }
    }
    char f = actor->flag1b84;
    if (needsB) {
        if (f)
            return true;
    } else {
        if (!f)
            return true;
    }
    return blocked;
}
}
}
