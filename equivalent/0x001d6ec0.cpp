// STATUS: equivalent (tools/equiv.py level 3: 152 inputs, branch coverage 53/54, incomplete)
// FUN_001d6ec0 @ 0x001d6ec0
#include "decls/address.h"
unsigned __int64 FUN_0027afb0(const char* s) throw();
extern unsigned __int64 DAT_004e25f0;
extern unsigned int DAT_004e25f8;

struct IdBlock {
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
};

struct Stats_1d6ec0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Scene_1d6ec0 {
    char pad0[0x80];
    Stats_1d6ec0 stats;
};

struct Boss {
    bool FUN_00092940(int flag);
};

struct Level_1d6ec0 {
    Scene_1d6ec0* FUN_00086310();
    Boss* FUN_00086340();
};

struct Meter_1d6ec0 {
    int FUN_001d5e80(int mode);
    float FUN_001d4e90();
};

struct Effect_1d6ec0 {
    void FUN_001c4ac0(int* color, float scale);
};

struct Body_1d6ec0 {
    char pad0[0x1b0];
    int kind;
};

struct Fighter_1d6ec0 {
    char pad0[0x11c];
    Body_1d6ec0* body;
};

struct Ref_1d6ec0 {
    char pad0[8];
    Fighter_1d6ec0* fighter;
    int type;
};

struct Roster_1d6ec0 {
    char pad0[0x124];
    Fighter_1d6ec0* player;
    bool FUN_000242d0(Fighter_1d6ec0* f);
};

struct Rules {
    bool FUN_000997a0();
};

struct World {
    char pad0[8];
    Rules* rules;
    char pad0c[0x14];
    Roster_1d6ec0* roster;
    char pad24[0x30];
    Level_1d6ec0* level;
};


struct Hit;

class Receiver_1d6ec0 {
public:
    char pad0[0x40];
    int f40;
    char pad44[0x9c - 0x44];
    IdBlock* tag;
    char padA0[0xec - 0xa0];
    Meter_1d6ec0* meter;
    char padF0[0x108 - 0xf0];
    int health;
    int threshold;
    char pad110[4];
    Ref_1d6ec0* attackerRef;
    char pad118[4];
    Effect_1d6ec0* effect;
    char pad120[0x148 - 0x120];
    int blocked;
    char pad14c[0x194 - 0x14c];
    char immune;
    char pad195[3];
    int kindMatch;
    float kindScale;
    void FUN_001d6e10(Ref_1d6ec0* r);
    bool FUN_001d6ec0(int amount, Ref_1d6ec0* victim, bool forced);
};

bool Receiver_1d6ec0::FUN_001d6ec0(int amount, Ref_1d6ec0* victim, bool forced)
{
    if (!(DAT_004e25f8 & 1)) {
        DAT_004e25f8 |= 1;
        DAT_004e25f0 = FUN_0027afb0("bunker_bunker");
    }
    int dmg;

    IdBlock* tagBlock = tag;
    if (tagBlock) {
        unsigned int lo = tagBlock->idLo;
        unsigned int hi = tagBlock->idHi;
        Scene_1d6ec0* scene = DAT_004dd700->level->FUN_00086310();
        if (scene) {
            int a = scene->stats.FUN_00088fa0();
            int b = scene->stats.FUN_00088fb0();
            if (a == 10 && b == 0x1c && lo == (unsigned int)DAT_004e25f0 && hi == (unsigned int)(DAT_004e25f0 >> 32))
                return false;
        }
    }

    if (immune)
        return false;

    Ref_1d6ec0* att = attackerRef;
    if (att) {
        if (att->type == 1 && DAT_004dd700->roster->FUN_000242d0(att->fighter) && !DAT_004dd700->rules->FUN_000997a0())
            return false;
        bool isMode2 = meter->FUN_001d5e80(f40) == 2;
        if (meter->FUN_001d4e90() > 0.0f) {
            dmg = (int)(meter->FUN_001d4e90() * amount);
            amount = dmg;
        } else if (isMode2) {
            dmg = (int)(amount * 0.05f);
            if (dmg > 1) {
                amount = dmg;
            } else {
                dmg = 1;
                amount = 1;
            }
        } else {
            if (!forced)
                return false;
            dmg = amount;
        }
    } else {
        dmg = amount;
    }

    forced = false;
    if (blocked)
        return false;

    if (victim && victim->type == 1) {
        Fighter_1d6ec0* ft = victim->fighter;
        if (ft->body) {
            if (ft->body->kind == kindMatch)
                dmg = (int)(amount * kindScale);
        }
        World* g = DAT_004dd700;
        if (ft == g->roster->player) {
            if (g->level->FUN_00086340()->FUN_00092940(0x14))
                dmg += dmg;
        }
    }

    if (dmg > threshold) {
        int h = health;
        if (h > 0)
            forced = true;
        health = h - dmg;
        if (forced) {
            amount = (int)0xffc84040;
            effect->FUN_001c4ac0(&amount, 0.4f);
        }
        FUN_001d6e10(victim);
    }
    return forced;
}
