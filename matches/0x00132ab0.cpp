#include "compat/ptr.h"
extern "C" char DAT_004112c4[];
extern void* __cdecl FUN_0008d690(hulk_uintptr);
struct GameStateCondition_132ab0 {
    hulk_intptr v0;
    int x04;
    int x08;
    int x0c;
    int x10;
    int x14;
    int x18;
    void InitBase(int);
};
GameStateCondition_132ab0* Factory_vfunc5(void) {
    GameStateCondition_132ab0* p = (GameStateCondition_132ab0*)FUN_0008d690(0x1c);
    if (p) {
        p->InitBase(0);
        p->x10 = -1;
        p->x18 = -1;
        p->v0 = ((hulk_intptr)DAT_004112c4);
        p->x0c = 0;
        p->x14 = 0;
        return p;
    }
    return 0;
}
