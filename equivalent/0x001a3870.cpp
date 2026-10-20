// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3870 @ 0x001a3870
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object { char padding[0x6c]; char *text; unsigned char FUN_001a3870(const char *source); };
unsigned char Object::FUN_001a3870(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    const char *end = source;
    while (*end) ++end;
    char *result = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = result;
    do { *result++ = *source; } while (*source++);
    return 1;
}