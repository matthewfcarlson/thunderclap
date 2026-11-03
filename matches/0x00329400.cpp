#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00329000();
extern "C" void __stdcall FUN_00013420(void*, int, int, const float*);
void owners::Obj_329400::FUN_00329400() {
    char* p = ((char*)this) + 0x3d04;
    for (int i = 0x14; i != 0; --i) {
        p -= 0x30c;
        FUN_00013420((void*)p, 0x18, 0x20, (const float*)((hulk_intptr)(void (__cdecl*)())&FUN_00329000));
    }
}
