// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CStatsManager,void,char_*,char_*,int>::vfunc_2 @ 0x00090cd0
#include "gen/global.h"

struct CStatsManager_90cd0 { void FUN_00090cd0(char *, char *, int); };
struct Arguments { char *first; char *second; int third; };

template <> void Method3<CStatsManager, void, char *, char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { CStatsManager_90cd0 * manager = (CStatsManager_90cd0 *)__p0; Arguments * args = (Arguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CStatsManager_90cd0::**)(char *, char *, int))&this->f_1c))(args->first, args->second, args->third);
}
