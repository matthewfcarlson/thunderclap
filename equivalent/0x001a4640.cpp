// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4640 @ 0x001a4640
#include "compat/ptr.h"
extern unsigned int __cdecl FUN_0008d340(void *);
extern void *__cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x16c];
    char *text;
    unsigned int FUN_001a4640(const char *source);
};
unsigned int Object::FUN_001a4640(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & 0xffffff00) | 1;
    }
    const char *end = source;
    do { ++end; } while (end[-1]);
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source));
    text = allocated;
    char *dest = allocated;
    do { *dest++ = *source; } while (*source++);
    return (((hulk_uintptr)allocated) & 0xffffff00) | 1;
}