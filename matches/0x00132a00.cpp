#include "compat/ptr.h"
extern void* __cdecl Alloc(unsigned int);
extern int LocationVtable_132a00;
struct GameStateCondition_132a00 {
    virtual void f0();
    char pad[8];
    int a, b, c, d;
    void Init(int);
};
void* FactoryVfunc5() {
    GameStateCondition_132a00* p = (GameStateCondition_132a00*)Alloc(0x1c);
    if (p) {
        p->Init(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        *(hulk_intptr*)p = (hulk_intptr)&LocationVtable_132a00;
        return p;
    }
    return 0;
}