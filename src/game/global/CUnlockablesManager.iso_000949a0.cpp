// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
// (tree_prelude.h: not needed)


// 0x000949a0 Closure3<CUnlockablesManager,void,int,int,bool>::vfunc_2 (30 B): equivalent/0x000949a0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCUnlockablesManager@@XHH_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x000949a0
#include "gen/global.h"

struct CUnlockablesManager_949a0 { void placeholder(); };
struct Arguments { int first; int second; bool third; };

template <> void Closure3<CUnlockablesManager, void, int, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused1 = (void *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused3 = (void *)__p2;

    ((*(CUnlockablesManager_949a0 * *)&this->f_20)->*(*(void (CUnlockablesManager_949a0::**)(int, int, bool))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}

