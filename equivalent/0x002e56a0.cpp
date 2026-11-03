// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e56a0 @ 0x002e56a0
#include "gen/owners.h"
void* __cdecl FUN_0008d6d0(unsigned size);
void __cdecl FUN_002e5410(void* data, unsigned count, int value);
bool owners::Buffer_2e56a0::FUN_002e56a0(unsigned count, hulk_intptr value) {
    if (data) return false;
    if (count) {
        void* memory = FUN_0008d6d0(count * 12);
        data = memory;
        if (memory) {
            end = (char*)memory + count * 12;
            FUN_002e5410(memory, count, ((int)value));
            return true;
        }
    }
    data = 0;
    end = 0;
    return false;
}