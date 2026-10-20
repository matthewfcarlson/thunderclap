// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ec80 @ 0x0012ec80
#include "compat/ptr.h"
int __cdecl FUN_0008d340(void *);
void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Item {
    char pad[0x1c];
    char *text;
    hulk_intptr FUN_0012ec80(const char *source);
};
hulk_intptr Item::FUN_0012ec80(const char *source) {
    int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255) | 1;
    }
    const char *end = source;
    do { ++end; } while (end[-1]);
    char *dest = (char *)FUN_0008d6d0((unsigned int)(end - source));
    text = dest;
    char *allocated = dest;
    do { *dest++ = *source++; } while (source[-1]);
    return (((hulk_intptr)allocated) & ~255) | 1;
}