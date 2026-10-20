#include "compat/ptr.h"
extern "C" char DAT_0042d604[];
struct LightsChooserCache {
    void* vftable;
    char pad[0x20];
    int value;
    void target();
    void finish();
};
extern void __cdecl thunk_FUN_00267090(int);
void LightsChooserCache::target() {
    int x = value;
    vftable = (void*)((hulk_intptr)DAT_0042d604);
    thunk_FUN_00267090(x);
    finish();
}