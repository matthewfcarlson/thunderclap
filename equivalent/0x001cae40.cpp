// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001cae40 @ 0x001cae40
#include "gen/owners.h"
 struct Pair { unsigned int low, high; }; Pair __cdecl FUN_0027b020(unsigned int value); owners::Result_1cae40* owners::Result_1cae40::FUN_001cae40(hulk_uintptr value) { first=0; second=0; a=0; b=0; c=0; d=0; low=0; high=0; first=0x20; second=0x1b; Pair p=FUN_0027b020(((unsigned int)value)); low=p.low; high=p.high; return this; }