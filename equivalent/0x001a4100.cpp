// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4100 @ 0x001a4100
#include "compat/ptr.h"
extern "C" unsigned int __cdecl thunk_FUN_0008d340(void *); extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char padding[0x10c]; char *text; unsigned int FUN_001a4100(const char *source); };
unsigned int Object::FUN_001a4100(const char *source) {
    unsigned int result = thunk_FUN_0008d340(text);
    if (!source) { text = 0; return (result & 0xffffff00U) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = allocated;
    char *destination = allocated;
    do { *destination++ = *source; } while (*source++);
    return (((hulk_uintptr)allocated) & 0xffffff00U) | 1;
}