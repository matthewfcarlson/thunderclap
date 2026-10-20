// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00170de0 @ 0x00170de0
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);

struct TextHolder {
    char pad[0x10];
    char *text;
    bool FUN_00170de0(const char *value);
};

bool TextHolder::FUN_00170de0(const char *value)
{
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int length = 0;
    while (value[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *dest = text;
    do {
        *dest++ = *value;
    } while (*value++);
    return true;
}