// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0011c290 @ 0x0011c290
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object { char pad[12]; char *text; int FUN_0011c290(const char *source); };
int Object::FUN_0011c290(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & ~255U) | 1; }
    unsigned int length = 0;
    do { ++length; } while (source[length - 1]);
    char *allocated = (char *)FUN_0008d6d0(length);
    text = allocated;
    char *dest = allocated;
    do { *dest++ = *source; } while (*source++);
    return ((hulk_uintptr)allocated & ~255U) | 1;
}