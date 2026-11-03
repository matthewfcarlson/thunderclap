#include "decls/data/game/global.h"
// data: gCurrent = DAT_004e3698

#include "compat/ptr.h"
#include "gen/owners.h"
int CheckThing();
void ApplyThing(int, int, float);
struct Obj_1e9a90 {
    char pad[12];
    int value;
    void Reset(int);
};
void owners::ThisWrap_001e9a90::FUN_001e9a90(hulk_intptr a, unsigned int b) {
    Obj_1e9a90* p = (Obj_1e9a90*)this->GetThing(((int)a));
    if (p && p != (*(Obj_1e9a90**)&DAT_004e3698)) {
        if ((*(Obj_1e9a90**)&DAT_004e3698))
            (*(Obj_1e9a90**)&DAT_004e3698)->Reset(b);
        if (CheckThing()) {
            int y = CheckThing();
            ApplyThing(y, p->value, (float)b);
        }
        (*(Obj_1e9a90**)&DAT_004e3698) = p;
    }
}