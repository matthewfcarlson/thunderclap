// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_002c72e0 @ 0x002c72e0
#include "gen/owners.h"
typedef void (__cdecl *Callback)();
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void __stdcall FUN_00011520(void*, unsigned int, int, Callback);
extern "C" void __cdecl FUN_002c6d30();
void owners::Object_2c72e0::FUN_002c72e0(int index) {
    if (!entries[index]) {
        int n = count;
        int* block = (int*)FUN_0008d6d0(n * 8 + 4);
        void* data = 0;
        if (block) {
            *block = n;
            data = block + 1;
            FUN_00011520(data, 8, n, FUN_002c6d30);
        }
        entries[index] = data;
        flags |= 0x40u << (index & 31);
    }
}