// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3810 @ 0x001a3810
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object { char pad[0x60]; char *text; unsigned char FUN_001a3810(const char *source); };
unsigned char Object::FUN_001a3810(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    unsigned int size = 0;
    while (source[size]) ++size;
    text = (char *)FUN_0008d6d0(size + 1);
    char *destination = text;
    do { *destination++ = *source; } while (*source++);
    return 1;
}