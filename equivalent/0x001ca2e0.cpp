// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca2e0 @ 0x001ca2e0
#include "gen/owners.h"
 extern "C" int __cdecl FUN_00267760(char *, unsigned int, const char *, ...); owners::Record_1ca2e0 *owners::Record_1ca2e0::FUN_001ca2e0(const char *input, unsigned int valueArg, unsigned int extraArg, unsigned char flagArg) { unsigned int *p = (unsigned int *)this; for (int i = 0; i < 0x17; ++i) p[i] = 0; size = 0x5c; kind = 0x11; FUN_00267760(text, 0x40, "%s", input); flag = flagArg; extra = extraArg; value = valueArg; return this; }