// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
// (tree_prelude.h: not needed)


// 0x00094a10 Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 (28 B): equivalent/0x00094a10.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCUnlockablesManager@@XHPBDPBD@@UAEXPAX00@Z @737c210bc5da @w346cf641fccb
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094a10
#include "gen/global.h"

struct CUnlockablesManager_94a10 { void callbackPlaceholder(); };
struct Arguments { int value; const char *first; const char *second; };

template <> void Closure3<CUnlockablesManager, void, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CUnlockablesManager_94a10 * *)&this->f_20)->*(*(void (CUnlockablesManager_94a10::**)(int, const char *, const char *))&this->f_1c))(args->value, args->first, args->second);
}

