// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002909c0 @ 0x002909c0
#include "compat/ptr.h"
#include "gen/owners.h"
void* __cdecl FUN_0008d6d0(unsigned size);
extern "C" void * __cdecl FUN_00290810(void *, int, void *);
bool owners::Buffer_2909c0::FUN_002909c0(unsigned count, hulk_uintptr value) {
    if (begin) return false;
    if (count) {
        void* data = FUN_0008d6d0(count * 16);
        begin = data;
        if (data) {
            end = (char*)data + count * 16;
            FUN_00290810(data, (unsigned)count, (void *)(hulk_uintptr)(unsigned)((unsigned)value));
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}