// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3ae0 @ 0x001a3ae0
#include "compat/ptr.h"
extern "C" void * __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char pad[0x9c];
    char *text;
    int FUN_001a3ae0(const char *source);
};
int Object::FUN_001a3ae0(const char *source) {
    void *freeResult = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return ((hulk_uintptr)freeResult & ~255u) | 1;
    }
    const char *end = source;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = allocated;
    char *destination = allocated;
    do {
        *destination++ = *source;
    } while (*source++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}