// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094b10
#include "gen/global.h"

struct CUnlockablesManager_94b10 { void FUN_00000000(const char *, int, const char *, const char *, const char *, const char *, int); };

template <> void Closure7<CUnlockablesManager, void, const char *, int, const char *, const char *, const char *, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const unsigned int * args = (const unsigned int *)__p1; void * unused2 = (void *)__p2;

    ((*(CUnlockablesManager_94b10 * *)&this->f_20)->*(*(void (CUnlockablesManager_94b10::**)(const char *, int, const char *, const char *, const char *, const char *, int))&this->f_1c))((const char *)args[0], (int)args[1], (const char *)args[2], (const char *)args[3], (const char *)args[4], (const char *)args[5], (int)args[6]);
}
