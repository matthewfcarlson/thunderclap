// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3c30 @ 0x001a3c30
#include "compat/ptr.h"
struct Holder { char pad[0xb0]; char *text; hulk_intptr FUN_001a3c30(const char *source); };
int __cdecl FUN_0008d340(void *);
void * __cdecl FUN_0008d6d0(unsigned int);
hulk_intptr Holder::FUN_001a3c30(const char *source) {
    int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255) | 1;
    }
    const char *end = source;
    while (*end) ++end;
    char *dest = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = dest;
    char *out = dest;
    do { *out++ = *source; } while (*source++);
    return ((hulk_intptr)dest & ~255) | 1;
}