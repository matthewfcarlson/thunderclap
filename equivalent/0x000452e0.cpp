// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 66/66)
// FUN_000452e0 @ 0x000452e0
#include "compat/ptr.h"
#include "decls/address.h"
struct Npc {
    char pad0[0x1ca8];
    int v1ca8;
    int v1cac;
    int v1cb0;
    int v1cb4;
    int v1cb8;
    int v1cbc;
    int v1cc0;
    int v1cc4;
    int v1cc8;
    int v1ccc;
    int v1cd0;
    int v1cd4;
    int v1cd8;
    int v1cdc;
    int v1ce0;
    int v1ce4;
    int v1ce8;
    char b1cec, b1ced, b1cee, b1cef;
    int v1cf0;
    char pad1cf4[0x1d40 - 0x1cf4];
    char b1d40;
};

struct ModeB_452e0 {
    Npc *FUN_000259f0(const char *name);
};

struct World {
    char pad0[0x20];
    ModeB_452e0 *modeB;
};

int FUN_00096600(const char *a, const char *b);

hulk_intptr FUN_000452e0(const char *id, const char *name, int value)
{
    int r = 0;
    if (id == 0 || *id == 0) return (hulk_intptr)id;
    if (name == 0 || *name == 0) return (hulk_intptr)id;
    Npc *npc = DAT_004dd700->modeB->FUN_000259f0(id);
    if (npc == 0) return 0;
    if ((r = FUN_00096600(name, "DesiredMinEngage")) == 0) {
        npc->v1ca8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "DesiredMaxEngage")) == 0) {
        npc->v1cac = value;
        return value;
    } else if ((r = FUN_00096600(name, "AbsoluteMinEngage")) == 0) {
        npc->v1cb0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "AbsoluteMaxEngage")) == 0) {
        npc->v1cb4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MaxAttack")) == 0) {
        npc->v1cb8 = value;
        return value;
    } else if ((r = FUN_00096600(name, "HearingRadius")) == 0) {
        npc->v1cbc = value;
        return r;
    } else if ((r = FUN_00096600(name, "Noisiness")) == 0) {
        npc->v1cc0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "SightRadius")) == 0) {
        npc->v1cc4 = value;
        return value;
    } else if ((r = FUN_00096600(name, "SightFOV")) == 0) {
        npc->v1cc8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "DodgingSkill")) == 0) {
        npc->v1ccc = value;
        return r;
    } else if ((r = FUN_00096600(name, "MinAttackPeriod")) == 0) {
        npc->v1cd0 = value;
        return value;
    } else if ((r = FUN_00096600(name, "MinTauntPeriod")) == 0) {
        npc->v1cd4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MinAttackPause")) == 0) {
        npc->v1cd8 = value;
        return r;
    } else if ((r = FUN_00096600(name, "MaxAttackPause")) == 0) {
        npc->v1cdc = value;
        return value;
    } else if ((r = FUN_00096600(name, "TargetPerceptionLag")) == 0) {
        npc->v1ce0 = value;
        return r;
    } else if ((r = FUN_00096600(name, "ChasePersistenceTime")) == 0) {
        npc->v1ce4 = value;
        return r;
    } else if ((r = FUN_00096600(name, "SuspiciousTime")) == 0) {
        npc->v1ce8 = value;
        return value;
    } else if ((r = FUN_00096600(name, "NoGolem")) == 0) {
        npc->b1cec = !(*(float *)&value <= 0.0f);
        return npc->b1cec;
    } else if ((r = FUN_00096600(name, "FightingNPCMode")) == 0) {
        npc->b1d40 = !(*(float *)&value <= 0.0f);
        return npc->b1d40;
    } else if ((r = FUN_00096600(name, "SuckInProp")) == 0) {
        npc->b1ced = !(*(float *)&value <= 0.0f);
        return npc->b1ced;
    } else if ((r = FUN_00096600(name, "GroupManaged")) == 0) {
        npc->b1cee = !(*(float *)&value <= 0.0f);
        return npc->b1cee;
    } else if ((r = FUN_00096600(name, "IgnoreFriendlyFire")) == 0) {
        npc->b1cef = !(*(float *)&value <= 0.0f);
        return npc->b1cef;
    } else if ((r = FUN_00096600(name, "SpeedSleepwalking")) == 0) {
        npc->v1cf0 = value;
        return r;
    }
    return r;
}
