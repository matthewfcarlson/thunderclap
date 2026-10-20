// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeCondition::vfunc_7 @ 0x000522b0
#include "gen/global.h"

struct Actor { char pad[0x330]; char *first; char *second; char *third; }; struct Stage { Actor * FUN_00059a30(); }; struct Input { Stage * FUN_000592a0(); };  
int CGrappleFightNodeCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;
 if (!input) return (int)(0); Actor *a = input->FUN_000592a0()->FUN_00059a30(); char *p = a->second; if (!p) p = a->first; if (!p) p = a->third; return (int)(p ? p + 0xdc : 0); }
