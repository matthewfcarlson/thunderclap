// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3d80 @ 0x001a3d80
#include "compat/ptr.h"
extern "C" void * __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object {
    char pad[0xcc];
    char *text;
    unsigned char FUN_001a3d80(const char *value);
};
unsigned char Object::FUN_001a3d80(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char *end = value;
    while (*end) ++end;
    char *result = (char *)FUN_0008d6d0((unsigned int)(end - value + 1));
    text = result;
    do {
        *result++ = *value;
    } while (*value++);
    return 1;
}