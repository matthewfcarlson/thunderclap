// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_001c9d20 @ 0x001c9d20
// cl-flags: /GS
#include "gen/owners.h"
struct Properties_1c9d20 {
    void FUN_001d1d10();
};
extern "C" void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Frame_1c9d20 {
    char buffer[32];
};
struct Object {
    char padding[0x18];
    unsigned int idLow, idHigh;
    Properties_1c9d20* FUN_001d4c90();
    bool target();
};
bool Object::target() {
    Frame_1c9d20 fr;
    Properties_1c9d20* properties = FUN_001d4c90();
    if (!properties || !((owners::Obj_1d2e80 *)properties)->FUN_001d2e80()) {
        return false;
    }
    FUN_00096d50(fr.buffer, 32, idLow, idHigh);
    ((owners::Thing_1d1d50 *)properties)->FUN_001d1d50((hulk_uintptr)"civilian", (hulk_uintptr)(fr.buffer));
    properties->FUN_001d1d10();
    return true;
}
