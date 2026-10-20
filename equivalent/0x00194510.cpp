// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00194510 @ 0x00194510
#include "compat/ptr.h"
struct Object { char pad[0xdc]; char* text; unsigned char FUN_00194510(const char* value); }; 
void* __cdecl FUN_0008d340(void* p);
void* __cdecl FUN_0008d6d0(hulk_uintptr size);
unsigned char Object::FUN_00194510(const char* value) {
    FUN_0008d340(text);
    if (!value) { text = 0; return 1; }
    unsigned int length = 0;
    while (value[length]) ++length;
    text = (char*)FUN_0008d6d0(length + 1);
    char* dest = text;
    do { *dest++ = *value; } while (*value++);
    return 1;
}