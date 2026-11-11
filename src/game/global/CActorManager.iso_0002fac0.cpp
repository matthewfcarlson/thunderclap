// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002fac0 Closure3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 (28 B): equivalent/0x0002fac0.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCActorManager@@XPBDPBDM@@UAEXPAX00@Z @737c210bc5da @wf50a7952058b
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x0002fac0
#include "gen/global.h"

struct CActorManager_2fac0 { void FUN_0002fac0(const char *, const char *, float); };  
template <> void Closure3<CActorManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** args = (const char **)__p1;
 struct Args { const char *first; const char *second; float third; }; Args *a = (Args *)args; ((*(CActorManager_2fac0 * *)&this->f_20)->*(*(void (CActorManager_2fac0::**)(const char *, const char *, float))&this->f_1c))(a->first, a->second, a->third); }

