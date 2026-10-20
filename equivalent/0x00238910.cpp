// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00238910 @ 0x00238910
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object {
    char pad[12];
    char *text;
    bool FUN_00238910(const char *value);
};
bool Object::FUN_00238910(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return true;
    }
    unsigned int len = 0;
    while (value[len]) ++len;
    text = (char *)FUN_0008d6d0(len + 1);
    char *out = text;
    do { *out++ = *value; } while (*value++);
    return true;
}