// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000382c0..0x00044910 (kind game, layer game, confidence medium), dominant class CCharacter
// (tree_prelude.h: not needed)


// 0x0003ea10 FUN_0003ea10 (412 B): matches/0x0003ea10.cpp [isolated: conflict: World; on include/gen/ and not mergeable]
// sym: ?FUN_0003ea10@Controller_3ea10@owners@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 18/18)
// FUN_0003ea10 @ 0x0003ea10
// cl-flags: /GS
#include "decls/address.h"
#include "gen/owners.h"

struct CCharacter_3ea10 {
    char pad0[0x328];
    void *target;            // 0x328
    char pad32c[0x1b48 - 0x32c];
    char active;             // 0x1b48
    void FUN_000393c0();
};

struct Group_3ea10 {
    char pad0[0xc];
    int count;               // 0x0c
    char FUN_000242d0(void *owner);
    CCharacter_3ea10 *FUN_00024190(int index);
};

struct Event_3ea10 {
    char data[0xc0];
};

struct EventSink_3ea10 {
    char FUN_001cbc20(Event_3ea10 *e);
};

struct World {
    char pad0[0x20];
    Group_3ea10 *group;            // 0x20
    char pad24[0x30 - 0x24];
    EventSink_3ea10 *sink;         // 0x30
};

extern "C" void *__cdecl FUN_001b46f0(void *key, int *out);



struct Frame_3ea10 {
    int arg;
    Event_3ea10 ev;
};

void owners::Controller_3ea10::FUN_0003ea10(int newMode)
{
    Frame_3ea10 f;
    if (mode == 0) {
        if (newMode == 1) {
            FUN_0003b1c0(0, newMode);
            EventSink_3ea10 *sink = DAT_004dd700->sink;
            if (sink) {
                f.arg = 0;
                void *res = FUN_001b46f0(key, &f.arg);
                ((Event_3ea10 *)((owners::Obj_1c9920 *)&(f.ev))->FUN_001c9920(*ref10, (hulk_intptr)res, f.arg, flag));
                sink->FUN_001cbc20(&f.ev);
            }
            if (!DAT_004dd700->group->FUN_000242d0(this)) {
                int count = DAT_004dd700->group->count;
                for (int i = 0; i < count; i++) {
                    CCharacter_3ea10 *a = DAT_004dd700->group->FUN_00024190(i);
                    if (a->target && a->target == activeTarget) {
                        if (a->active)
                            a->active = 0;
                        a->FUN_000393c0();
                    }
                }
            }
        }
    }
    mode = newMode;
}

