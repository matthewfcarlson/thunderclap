#include "compat/ptr.h"
extern "C" char DAT_00431d1c[];
struct Item_3093b0 {
    char pad[0x34];
    void Destroy();
};
extern void __cdecl FreeArray(void*);
struct HairclubPhysicsObject {
    void* vptr;
    char pad[0x1f4];
    Item_3093b0* items;
    void BaseDestroy();
    void Destroy();
};
void HairclubPhysicsObject::Destroy() {
    Item_3093b0* p = items;
    vptr = (void*)((hulk_intptr)DAT_00431d1c);
    if (p) {
        int n = *((int*)p - 1);
        Item_3093b0* q = p + n;
        while (--n >= 0) {
            q--;
            q->Destroy();
        }
        FreeArray((char*)p - 4);
    }
    BaseDestroy();
}
