// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ebc0 @ 0x0012ebc0
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object { char pad[16]; char *text; bool FUN_0012ebc0(const char *value); };
bool Object::FUN_0012ebc0(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int length = 0;
    do { ++length; } while (value[length - 1]);
    text = (char *)FUN_0008d6d0(length);
    char *destination = text;
    do { *destination++ = *value; } while (*value++);
    return true;
}