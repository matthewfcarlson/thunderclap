// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4480 @ 0x001a4480
#include "compat/ptr.h"
extern "C" unsigned int __cdecl thunk_FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object { char pad[0x14c]; char *name; unsigned int FUN_001a4480(const char *text); };
unsigned int Object::FUN_001a4480(const char *text) {
    unsigned int result = thunk_FUN_0008d340(name);
    if (!text) { name = 0; return (result & ~255u) | 1; }
    const char *end = text;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    name = allocated;
    char *dest = allocated;
    do { *dest++ = *text; } while (*text++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}