#include "compat/ptr.h"
extern "C" char DAT_00421dfc[];
struct Item_1cc530 {
    char data[0x28];
    void Init();
};
extern void ReleaseRef(int);
struct CEventManager {
    void* vt;
    int a;
    int b;
    int ref;
    int ref2;
    char pad[0x10];
    Item_1cc530 items[24];
};
void __fastcall FUN_001cc530(CEventManager* self) {
    self->vt = (void*)((hulk_intptr)DAT_00421dfc);
    Item_1cc530* p = self->items + 24;
    int n = 24;
    do {
        --p;
        p->Init();
        --n;
    } while (n != 0);
    self->ref2 = self->ref;
    if (self->ref)
        ReleaseRef(self->ref);
}
