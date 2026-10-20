// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4090 @ 0x001a4090
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Holder { char pad[0x100]; char *text; unsigned int FUN_001a4090(const char *source); };
unsigned int Holder::FUN_001a4090(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & 0xffffff00u) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = destination;
    char *out = destination;
    do { *out++ = *source; } while (*source++);
    return ((hulk_uintptr)destination & 0xffffff00u) | 1;
}