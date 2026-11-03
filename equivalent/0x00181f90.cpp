// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::PropAddToMissileCountAction::vfunc_5 @ 0x00181f90
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Slot_181f90 {
    int FUN_001d6c50();
};
struct Player_181f90 {
    char pad[0x128];
    Slot_181f90* slot128;
};
struct Game_181f90 {
    Player_181f90* FUN_00059a30();
};
struct Holder_181f90 {
};
struct Params_181f90 {
    char pad[0x10];
    int index;
    int bonus;
};

bool hulkfight::motion::PropAddToMissileCountAction::vfunc_5(hulk_intptr arg, int unused) {
    if (arg == 0 && (*(Holder_181f90 * *)&this->f_20) != 0) {
        Game_181f90* g = ((Game_181f90 *)((owners::Object_592a0 *)((*(Holder_181f90 * *)&this->f_20)))->FUN_000592a0());
        Player_181f90* p = g->FUN_00059a30();
        int index = (*(Params_181f90 * *)&this->f_1c)->index;
        if (p != 0) {
            Slot_181f90* s;
            if (index < 0) {
                s = p->slot128;
            } else if (index < 8) {
                s = ((Slot_181f90 *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)index));
            } else {
                return (bool)(0);
            }
            if (s != 0) {
                int cur = s->FUN_001d6c50();
                ((owners::C_1d6c60 *)s)->FUN_001d6c60((*(Params_181f90 * *)&this->f_1c)->bonus + cur);
            }
        }
    }
    return (bool)(0);
}
