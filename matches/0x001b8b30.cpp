#include "decls/data/game/global.h"
// data: threshold_1b8b30 = DAT_004203b0

struct Obj_1b8b30 {
    char pad[0x18];
    unsigned char active;
    float value;
    char pad2[0x10];
    unsigned char other;
};
unsigned char __fastcall FUN_001b8b30(Obj_1b8b30* p) {
    if (p->active != 0 && p->value < DAT_004203b0) {
        p->active = 0;
        p->other = 0;
    }
    return p->active;
}