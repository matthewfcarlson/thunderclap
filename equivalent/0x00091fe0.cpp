// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 8/8)
// FUN_00091fe0 @ 0x00091fe0
#include "gen/owners.h"
extern "C" void __cdecl FUN_0008d340(void *); extern "C" void * __cdecl FUN_0008d6d0(unsigned int);  void owners::Object_91fe0::FUN_00091fe0(const char *value) { if (text) { FUN_0008d340(text); text = 0; } if (value) { const char *end = value; while (*end) ++end; char *dest = (char *)FUN_0008d6d0((unsigned int)(end - value + 1)); text = dest; do { *dest++ = *value; } while (*value++); } }