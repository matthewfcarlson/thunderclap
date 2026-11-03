#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_000c7920();
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" void __stdcall Init(void*, int, int, const float*);
void owners::Obj_2c7240::FUN_002c7240(int index) {
    if (entries[index] == 0) {
        int n = count;
        void* p = Alloc(n * 8);
        if (p)
            Init(p, 8, n, (const float*)((hulk_intptr)(void (__cdecl*)())&FUN_000c7920));
        else
            p = 0;
        entries[index] = p;
        flags |= 1 << index;
    }
}
