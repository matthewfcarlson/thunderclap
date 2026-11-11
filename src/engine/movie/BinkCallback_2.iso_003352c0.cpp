// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x003352c0 FUN_003352c0 (61 B): matches/0x003352c0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU)); on include/gen/ and not mergeable]
// sym: ?FUN_003352c0@Obj_3352c0@owners@@QAEXPBD@Z
#include "decls/data/engine/movie.h"
// data: gAlloc = DAT_0055dbb0

#include "gen/owners.h"

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strcpy(char*, const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif

class Alloc {
  public:
};
void owners::Obj_3352c0::FUN_003352c0(const char* s) {
    text = ((char *)((owners::Allocator_337d60 *)&((*(Alloc*)&DAT_0055dbb0)))->FUN_00337d60((unsigned int)(strlen(s) + 1), 4));
    strcpy(text, s);
}

