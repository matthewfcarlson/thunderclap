// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 14/14)
// FUN_0033eb90 @ 0x0033eb90
#include "decls/data/engine/unknown.h"

typedef void* (__stdcall *AllocHook)(unsigned int size);
extern "C" void* __cdecl malloc(unsigned int size);

// Allocates a block with 0x40 bytes of header; the returned pointer is
// 32-byte aligned relative to the raw block and records its kind and offset.
void* __stdcall FUN_0033eb90(unsigned int size)
{
    if (size == 0 || size == 0xffffffff)
        return 0;
    unsigned char* raw = 0;
    unsigned char kind = 0;
    AllocHook hook = (*(AllocHook*)&DAT_005660d8);
    if (hook != 0)
        raw = static_cast<unsigned char*>(hook(size + 0x40));
    if (raw != 0) {
        if (raw == reinterpret_cast<unsigned char*>(0xffffffff))
            return 0;
        kind = 3;
    } else {
        raw = static_cast<unsigned char*>(malloc(size + 0x40));
        if (raw == 0)
            return 0;
    }
    unsigned char offset = (unsigned char)(0x40 - ((unsigned char)(unsigned int)raw & 0x1f));
    unsigned char* user = raw + offset;
    user[-1] = offset;
    user[-2] = kind;
    if (kind == 3)
        *reinterpret_cast<unsigned int*>(user - 8) = DAT_005660dc;
    return user;
}
