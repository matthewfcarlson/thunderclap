// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x00094280
#include "gen/global.h"

struct CUnlockablesManager_94280 { };
struct Arguments { int first; int second; unsigned char third; };

template <> void Method3<CUnlockablesManager, void, int, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CUnlockablesManager_94280 * object = (CUnlockablesManager_94280 *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused = (void *)__p2;

    (object->*(*(void (CUnlockablesManager_94280::**)(int, int, int))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}
