// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 9/10, incomplete)
// CGrappleFightNodeParentCondition::vfunc_7 @ 0x000523c0
#include "compat/ptr.h"
#include "gen/global.h"

struct Actor { char pad[0x330]; char *alternate; char *primary; char *fallback; }; struct Context_523c0 { Actor * FUN_00059a30(); }; struct Input { Context_523c0 * FUN_000592a0(); };  
hulk_intptr CGrappleFightNodeParentCondition::vfunc_7(void* __p0) { Input * input = (Input *)__p0;
 if (!input) return (int)(0); Actor *actor = input->FUN_000592a0()->FUN_00059a30(); char *result = actor->primary; if (!result) result = actor->alternate; if (!result) result = actor->fallback; return (hulk_intptr)(result ? result + 0xdc : 0); }
