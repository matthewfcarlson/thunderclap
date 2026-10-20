// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094a10
#include "gen/global.h"

struct CUnlockablesManager_94a10 { void callbackPlaceholder(); };
struct Arguments { int value; const char *first; const char *second; };

template <> void Closure3<CUnlockablesManager, void, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CUnlockablesManager_94a10 * *)&this->f_20)->*(*(void (CUnlockablesManager_94a10::**)(int, const char *, const char *))&this->f_1c))(args->value, args->first, args->second);
}
