// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002b1070 @ 0x002b1070
#include "compat/ptr.h"
struct Buffer { void* begin; void* end; bool FUN_002b1070(unsigned count, int value); }; 
void* __cdecl FUN_0008d6d0(hulk_uintptr size);
void __cdecl FUN_002b0e40(void* data, unsigned count, int value);
bool Buffer::FUN_002b1070(unsigned count, int value) {
    if (begin) return false;
    if (count) {
        void* p = FUN_0008d6d0(count * 24);
        begin = p;
        if (p) {
            end = (char*)p + count * 24;
            FUN_002b0e40(p, count, value);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}