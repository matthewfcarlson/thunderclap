// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002aba80 @ 0x002aba80
#include "compat/ptr.h"
struct Buffer { char* begin; char* end; unsigned char FUN_002aba80(unsigned int count, int extra); };
void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void * __cdecl FUN_002ab640(void *, unsigned int, const void *);
unsigned char Buffer::FUN_002aba80(unsigned int count, int extra) {
    if (begin) return 0;
    if (count) {
        char* memory = (char*)FUN_0008d6d0(count * 64);
        begin = memory;
        if (memory) {
            end = memory + count * 64;
            FUN_002ab640(memory, count, (const void *)(hulk_uintptr)(int)extra);
            return 1;
        }
    }
    begin = 0;
    end = 0;
    return 0;
}