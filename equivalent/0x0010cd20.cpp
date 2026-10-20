// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0010cd20 @ 0x0010cd20
#include "compat/ptr.h"
extern "C" void __cdecl FUN_0008d340(void*); extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr); struct Obj { char pad[16]; char* text; bool FUN_0010cd20(const char* value); }; bool Obj::FUN_0010cd20(const char* value) { FUN_0008d340(text); if (!value) { text = 0; return true; } unsigned int len = 0; while (value[len]) ++len; text = (char*)FUN_0008d6d0(len + 1); char* dst = text; do { *dst++ = *value; } while (*value++); return true; }