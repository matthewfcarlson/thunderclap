#include "compat/ptr.h"
#include "decls/data/game/global.h"
// data: vals = DAT_004c602c
#include "gen/owners.h"

class Loader_1dbd50 {
  public:
    void Config(const char*, int, int);
    void Type(const char*, int, int);
};
extern "C" Loader_1dbd50* __cdecl FUN_001d4c90();
void __cdecl FUN_001dbd50() {
    Loader_1dbd50* p = FUN_001d4c90();
    if (p) {
        p->Config("constants", 1, 1);
        p->Type("weaponTypes", 0, 1);
        const int* q = ((const int*)&DAT_004c602c);
        do {
            ((owners::Thing_1d1d50 *)p)->FUN_001d1d50((hulk_uintptr)(*q), (hulk_uintptr)(*q));
            ++q;
        } while ((hulk_intptr)q < ((hulk_intptr)DAT_004c6044));
        ((owners::Obj_1d19d0 *)p)->FUN_001d19d0(2);
    }
}