// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0012ec20 @ 0x0012ec20
#include "gen/owners.h"
extern "C" void __cdecl FUN_0008d340(void*); extern "C" void* __cdecl FUN_0008d6d0(unsigned int);  bool owners::Object_12ec20::FUN_0012ec20(const char* input) { FUN_0008d340(text); if (!input) { text = 0; return true; } unsigned int length = 0; while (input[length]) ++length; text = (char*)FUN_0008d6d0(length + 1); char* dst = text; do { *dst++ = *input; } while (*input++); return true; }