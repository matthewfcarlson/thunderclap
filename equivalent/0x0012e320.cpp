// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e320 @ 0x0012e320
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object {
    char padding[0x14];
    char* text;
    unsigned char FUN_0012e320(const char* source);
};
unsigned char Object::FUN_0012e320(const char* source) {
    FUN_0008d340(text);
    if (!source) {
        text = 0;
        return 1;
    }
    const char* end = source;
    while (*end) ++end;
    text = (char*)FUN_0008d6d0((unsigned int)(end - source + 1));
    char* destination = text;
    do {
        *destination++ = *source;
    } while (*source++);
    return 1;
}