// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012dfe0..0x00132e00 (kind game, layer game, confidence high), dominant class hulkfight::GameStateCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fefa7a64 {
#define TREE_TU_END }
namespace fn_fefa7a64 {} using namespace fn_fefa7a64;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fefa7a64 {
extern "C" int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);
struct Script_12f400 {
    char FUN_001d2ba0(const char* name, int a, int b);
};
extern "C" Script_12f400* __cdecl FUN_001d4c90();
struct Item_12f750 { char pad[0x1c]; int f1c; };
struct Info_12f750 {
    char pad0[0x10];
    int f10;
    const char *name14;
    char pad2[4];
    int f1c;
    const char *name20;
    char flag24;
};
struct Sub_12f750 { const char *FUN_000443b0(); };
struct Player_12f750 {
    char pad0[0x11c];
    Sub_12f750 *sub11c;
    char pad1[0x334 - 0x120];
    Player_12f750 *f334;
    char pad2[0x20b0 - 0x338];
    int f20b0;
    const char *FUN_00036d00();
};
struct Mgr_12f750 { Player_12f750 *FUN_00059a30(); };
struct Obj3_12f750 { char FUN_00092de0(int n); };
struct Holder_12f750 { char pad[8]; int f8; Mgr_12f750 *FUN_000592a0(); };
} // namespace fn_fefa7a64
struct Singleton_4dd6ec { Obj3_12f750 *FUN_00086340(); };
namespace fn_fefa7a64 {
struct Target_12f750 { void FUN_001ecda0(char *a, int b, char *c, int d); };
} // namespace fn_fefa7a64
struct World { char pad[0x34]; Target_12f750 *t34; };
namespace fn_fefa7a64 {
struct Name64 { char c[0x40]; };

} // namespace fn_fefa7a64

// 0x0012f400 hulkfight::GameStateCondition::vfunc_6 (621 B): equivalent/0x0012f400.cpp
// sym: ?vfunc_6@GameStateCondition@hulkfight@@UAE_NPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20043 inputs, branch coverage 45/48, incomplete)
// hulkfight::GameStateCondition::vfunc_6 @ 0x0012f400
bool hulkfight::GameStateCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    bool result = false;

    if ((*(const char * *)&this->f_14) != 0) {
        Script_12f400* script = FUN_001d4c90();
        char buf[0x80];
        for (int i = 0; i < 0x80; i++)
            buf[i] = 0;
        int value;
        if (script->FUN_001d2ba0("game_state_current", 1, 0)) {
            char got = ((char)((owners::Converter_1d2da0 *)script)->FUN_001d2da0((hulk_uintptr)((*(const char * *)&this->f_0c)), &value));
            ((owners::Obj_1d19d0 *)script)->FUN_001d19d0(1);
            if (got && script->FUN_001d2ba0("game_state_list", 1, 0)) {
                char found = script->FUN_001d2ba0((*(const char * *)&this->f_0c), 0, 0);
                if (found)
                    ((owners::Obj_1d19d0 *)script)->FUN_001d19d0(1);
                ((owners::Obj_1d19d0 *)script)->FUN_001d19d0(1);
                if (found) {
                    if (value == 0) {
                        FUN_00267760(buf, 0x80, "unassigned");
                    } else if (value == -1) {
                        FUN_00267760(buf, 0x80, "complete");
                    } else if (value == -999) {
                        FUN_00267760(buf, 0x80, "failed");
                    } else {
                        if (script->FUN_001d2ba0("game_state_list", 1, 0)) {
                            if (script->FUN_001d2ba0((*(const char * *)&this->f_0c), 0, 0)) {
                                ((owners::C_1d2cd0 *)script)->FUN_001d2cd0(value, (hulk_intptr)buf, 0x80);
                                ((owners::Obj_1d19d0 *)script)->FUN_001d19d0(1);
                            }
                            ((owners::Obj_1d19d0 *)script)->FUN_001d19d0(1);
                        }
                    }
                    if (this->compare == 0 || this->compare == 1) {
                        const char* p = buf;
                        const char* q = (*(const char * *)&this->f_14);
                        int cmp;
                        for (;;) {
                            unsigned char pc = *p;
                            unsigned char qc = *q;
                            if (pc != qc) {
                                cmp = 1;
                                break;
                            }
                            if (pc == 0) {
                                cmp = 0;
                                break;
                            }
                            p++;
                            q++;
                        }
                        if (this->compare == 0)
                            result = (cmp == 0);
                        else
                            result = (cmp != 0);
                    }
                }
            }
        }
    }
    return result;
}


// 0x0012f750 hulkfight::DialogueAction::vfunc_3 (444 B): equivalent/0x0012f750.cpp
// sym: ?vfunc_3@DialogueAction@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 18926 inputs, branch coverage 36/36)
// hulkfight::DialogueAction::vfunc_3 @ 0x0012f750
bool hulkfight::DialogueAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if ((*(Holder_12f750 * *)&this->f_20) == 0) {
        return (bool)(0);
    }
    Player_12f750 *pl = 0;
    Mgr_12f750 *mgr = (*(Holder_12f750 * *)&this->f_20)->FUN_000592a0();
    if (mgr)
        pl = mgr->FUN_00059a30();
    Info_12f750 *inf = (*(Info_12f750 * *)&this->f_1c);
    if (inf->flag24) {
        if (pl && pl->f334)
            pl = pl->f334;
    }
    if (pl && pl->f20b0) {
        return (bool)(0);
    }
    char nameB[0x40] = "";
    char nameA[0x40] = "";
    if (inf->name14) {
        const char *s = inf->name14;
        char *d = nameA;
        char c;
        do { c = *s++; *d++ = c; } while (c);
    }
    if (inf->name20) {
        const char *s = inf->name20;
        char *d = nameB;
        char c;
        do { c = *s++; *d++ = c; } while (c);
    }
    if (nameB[0] == 0 && pl) {
        const char *r = pl->FUN_00036d00();
        const char *h = "hulk";
        int k = 0;
        while (k < 5 && r[k] == h[k]) k++;
        if (k == 5) {
            if (DAT_004dd6ec->FUN_00086340()->FUN_00092de0(2) != 0)
                for (int i = 0; i < 5; i++) nameB[i] = h[i];
        } else {
            const char *s = pl->FUN_00036d00();
            char *d = nameB;
            char c;
            do { c = *s++; *d++ = c; } while (c);
            if (nameA[0] == 0) {
                s = pl->sub11c->FUN_000443b0();
                d = nameA;
                do { c = *s++; *d++ = c; } while (c);
            }
        }
    }
    DAT_004dd700->t34->FUN_001ecda0(nameA, (*(Info_12f750 * *)&this->f_1c)->f1c, nameB, (*(Info_12f750 * *)&this->f_1c)->f10);
    return (bool)(1);
}

