// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0010c8d0 @ 0x0010c8d0
#include "compat/ptr.h"
int __cdecl FUN_0008d340(void *p);
void * __cdecl FUN_0008d6d0(unsigned int size);
struct Owner { char pad[0x10]; char *text; hulk_intptr FUN_0010c8d0(const char *source); };
hulk_intptr Owner::FUN_0010c8d0(const char *source) {
    int freed = FUN_0008d340(text);
    if (!source) { text = 0; return (freed & ~255) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = destination;
    char *current = destination;
    do { *current++ = *source; } while (*source++);
    return ((hulk_intptr)destination & ~255) | 1;
}