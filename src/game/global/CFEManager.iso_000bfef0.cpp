// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000bfef0 Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 (58 B): equivalent/0x000bfef0.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure6@VCFEManager@@XPBDPBDPBDPBDHH@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 @ 0x000bfef0
#include "gen/global.h"

struct CFEManager_bfef0 { void FUN_000bfef0(const char *,const char *,const char *,const char *,int,int); };

template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const int * args = (const int *)__p1; void * unused2 = (void *)__p2;

    ((*(CFEManager_bfef0 * *)&this->f_20)->*(*(void (CFEManager_bfef0::**)(const char *, const char *, const char *, const char *, int, int))&this->f_1c))((const char *)args[0], (const char *)args[1], (const char *)args[2], (const char *)args[3], args[4], args[5]);
}

