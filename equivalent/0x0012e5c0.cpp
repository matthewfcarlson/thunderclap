// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012e5c0 @ 0x0012e5c0
#include "compat/ptr.h"
struct Object { char pad[12]; char* name; bool FUN_0012e5c0(const char* text); };
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
bool Object::FUN_0012e5c0(const char* text) {
    FUN_0008d340(name);
    if (!text) { name = 0; return true; }
    unsigned int length = 0;
    while (text[length]) ++length;
    name = (char*)FUN_0008d6d0(length + 1);
    char* dest = name;
    do { *dest++ = *text; } while (*text++);
    return true;
}