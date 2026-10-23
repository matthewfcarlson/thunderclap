// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007d500
#include "gen/global.h"

struct CAmbientsManager_7d500 { void FUN_0007d500(const char *, unsigned int, float); };
struct Args { const char *name; unsigned int value; float amount; };

template <> void Method3<CAmbientsManager, void, const char *, unsigned int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CAmbientsManager_7d500 * manager = (CAmbientsManager_7d500 *)__p0; const Args * args = (const Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CAmbientsManager_7d500::**)(const char *, unsigned int, float))&this->f_1c))(args->name, args->value, args->amount);
}
