// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CWorldStreamManager,int,int,int>::vfunc_2 @ 0x00205eb0
#include "gen/global.h"

struct CWorldStreamManager_205eb0 { int method(int, int); };
struct Arguments { int first; int second; };

template <> void Closure2<CWorldStreamManager, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; Arguments * arguments = (Arguments *)__p1; int * result = (int *)__p2;

    int value = ((*(CWorldStreamManager_205eb0 * *)&this->f_20)->*(*(int (CWorldStreamManager_205eb0::**)(int, int))&this->f_1c))(arguments->first, arguments->second);
    if (result) *result = value;
}
