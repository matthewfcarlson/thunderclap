// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002c71b0 @ 0x002c71b0
#include "compat/ptr.h"
struct Buffer { char pad0[8]; unsigned flags; unsigned count; char pad10[4]; void* data; void FUN_002c71b0(); };
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
extern "C" void __stdcall FUN_00011520(void*, unsigned, unsigned, void (*)());
extern "C" void LAB_00011090();
void Buffer::FUN_002c71b0() {
    if (!data) {
        unsigned n = count;
        void* p = FUN_0008d6d0(n * 12);
        if (p) FUN_00011520(p, 12, n, LAB_00011090);
        data = p;
        flags |= 0x20;
    }
}