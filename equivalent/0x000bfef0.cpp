// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 @ 0x000bfef0
#include "gen/global.h"

struct CFEManager_bfef0 { void FUN_000bfef0(const char *,const char *,const char *,const char *,int,int); };

template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const int * args = (const int *)__p1; void * unused2 = (void *)__p2;

    ((*(CFEManager_bfef0 * *)&this->f_20)->*(*(void (CFEManager_bfef0::**)(const char *, const char *, const char *, const char *, int, int))&this->f_1c))((const char *)args[0], (const char *)args[1], (const char *)args[2], (const char *)args[3], args[4], args[5]);
}
