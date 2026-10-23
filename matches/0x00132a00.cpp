#include "compat/ptr.h"
extern void* __cdecl FUN_0008d690(hulk_uintptr);
extern int DAT_004112a4;
struct GameStateCondition_132a00 {
    virtual void f0();
    char pad[8];
    int a, b, c, d;
    void Init(int);
};
void* FactoryVfunc5() {
    GameStateCondition_132a00* p = (GameStateCondition_132a00*)FUN_0008d690(0x1c);
    if (p) {
        p->Init(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        *(hulk_intptr*)p = (hulk_intptr)&DAT_004112a4;
        return p;
    }
    return 0;
}