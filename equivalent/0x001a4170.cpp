// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4170 @ 0x001a4170
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x110]; char *name; unsigned int FUN_001a4170(const char *text); };
unsigned int Object::FUN_001a4170(const char *text) {
    hulk_uintptr result = FUN_0008d340(name);
    if (!text) { name = 0; return (result & 0xffffff00u) | 1; }
    const char *end = text;
    while (*end) ++end;
    name = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    result = (hulk_uintptr)name;
    char *out = name;
    do { *out++ = *text; } while (*text++);
    return (result & 0xffffff00u) | 1;
}