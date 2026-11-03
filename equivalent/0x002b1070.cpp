// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002b1070 @ 0x002b1070
#include "gen/owners.h"
void* __cdecl FUN_0008d6d0(unsigned size);
extern "C" void __cdecl FUN_002b0e40(void* data, unsigned count, int value);
bool owners::Buffer_2b1070::FUN_002b1070(unsigned count, hulk_intptr value) {
    if (begin) return false;
    if (count) {
        void* p = FUN_0008d6d0(count * 24);
        begin = p;
        if (p) {
            end = (char*)p + count * 24;
            FUN_002b0e40(p, count, ((int)value));
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}