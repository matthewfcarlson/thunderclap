// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e710 @ 0x0012e710
#include "compat/ptr.h"
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
struct Obj { char pad[0x10]; char *text; unsigned int FUN_0012e710(const char *value); };
unsigned int Obj::FUN_0012e710(const char *value) {
    unsigned int result = FUN_0008d340(text);
    if (!value) { text = 0; return (result & ~255u) | 1; }
    unsigned int length = 1;
    const char *p = value;
    while (*p++) ++length;
    char *allocated = (char *)FUN_0008d6d0(length);
    text = allocated;
    char *out = allocated;
    do { *out++ = *value; } while (*value++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}