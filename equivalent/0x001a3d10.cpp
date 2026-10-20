// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3d10 @ 0x001a3d10
#include "compat/ptr.h"
int __cdecl FUN_0008d340(void *p);
void * __cdecl FUN_0008d6d0(hulk_uintptr size);
struct Object {
    char padding[0xc0];
    char *name;
    hulk_intptr FUN_001a3d10(const char *text);
};
hulk_intptr Object::FUN_001a3d10(const char *text) {
    int result = FUN_0008d340(name);
    if (!text) {
        name = 0;
        return (result & ~255) | 1;
    }
    const char *end = text;
    while (*end) ++end;
    char *copy = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    name = copy;
    char *destination = copy;
    do {
        *destination++ = *text;
    } while (*text++);
    return ((hulk_intptr)copy & ~255) | 1;
}