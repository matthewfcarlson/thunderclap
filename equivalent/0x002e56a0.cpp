// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e56a0 @ 0x002e56a0
#include "compat/ptr.h"
struct Buffer { void* data; void* end; bool FUN_002e56a0(unsigned count, int value); }; 
void* __cdecl FUN_0008d6d0(hulk_uintptr size);
void __cdecl FUN_002e5410(void* data, unsigned count, int value);
bool Buffer::FUN_002e56a0(unsigned count, int value) {
    if (data) return false;
    if (count) {
        void* memory = FUN_0008d6d0(count * 12);
        data = memory;
        if (memory) {
            end = (char*)memory + count * 12;
            FUN_002e5410(memory, count, value);
            return true;
        }
    }
    data = 0;
    end = 0;
    return false;
}