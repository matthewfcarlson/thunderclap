// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002e5700 @ 0x002e5700
#include "compat/ptr.h"
struct Buffer { void* begin; void* end; bool FUN_002e5700(unsigned int count, void* source); }; 
void* __cdecl FUN_0008d6d0(hulk_uintptr);
void __cdecl FUN_002e5450(void*, unsigned int, void*);
bool Buffer::FUN_002e5700(unsigned int count, void* source) {
    if (begin) return false;
    if (count) {
        unsigned int bytes = count * 12;
        void* memory = FUN_0008d6d0(bytes);
        begin = memory;
        if (memory) {
            end = (char*)memory + bytes;
            FUN_002e5450(memory, count, source);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}