// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure1<CWorldStreamManager,int,int>::vfunc_2 @ 0x00205f50
#include "gen/global.h"

class CWorldStreamManager_205f50 {};

template <> void Closure1<CWorldStreamManager, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; int * argument = (int *)__p1; int * result = (int *)__p2;

    int value = ((*(CWorldStreamManager_205f50 * *)&this->f_20)->*(*(int (CWorldStreamManager_205f50::**)(int))&this->f_1c))(*argument);
    if (result)
        *result = value;
}
