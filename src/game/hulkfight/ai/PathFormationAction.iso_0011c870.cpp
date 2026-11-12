// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011c310..0x0011d860 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathFormationAction
#include "tree_prelude.h"
#include "compat/ptr.h"


// 0x0011c870 FUN_0011c870 (82 B): matches/0x0011c870.cpp [isolated: conflict: strlen; on include/gen/ and not mergeable]
// sym: ?FUN_0011c870@Obj_11c870@owners@@QAEDPBD@Z
#include "gen/owners.h"
/* size_t: tree_prelude.h */
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" size_t __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

char owners::Obj_11c870::FUN_0011c870(const char* s) {
    FUN_0008d340(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}

