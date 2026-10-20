// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4790 @ 0x001a4790
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x180];
    char *text;
    int FUN_001a4790(const char *source);
};
int Object::FUN_001a4790(const char *source) {
    unsigned int freed = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (freed & 0xffffff00u) | 1;
    }
    unsigned int length = 0;
    while (source[length]) ++length;
    char *allocated = (char *)FUN_0008d6d0(length + 1);
    text = allocated;
    char *destination = allocated;
    do {
        *destination++ = *source;
    } while (*source++);
    return ((hulk_uintptr)allocated & 0xffffff00u) | 1;
}