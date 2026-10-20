// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e770 @ 0x0012e770
#include "compat/ptr.h"
struct Object { char pad[0x18]; char* text; int FUN_0012e770(const char* source); };
int __cdecl FUN_0008d340(void*);
char* __cdecl FUN_0008d6d0(unsigned int);
int Object::FUN_0012e770(const char* source) {
    hulk_intptr result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & ~255) | 1; }
    const char* end = source;
    while (*end++) {}
    text = FUN_0008d6d0((unsigned int)(end - source));
    result = (hulk_intptr)text;
    char* dest = text;
    char c;
    do { c = *source++; *dest++ = c; } while (c);
    return (result & ~255) | 1;
}