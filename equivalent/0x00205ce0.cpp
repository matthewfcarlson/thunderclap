// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<CWorldStreamManager,bool,float,float,float>::vfunc_2 @ 0x00205ce0
#include "gen/global.h"

struct CWorldStreamManager_205ce0;
typedef bool (__fastcall *StreamCallback)(CWorldStreamManager_205ce0 *, unsigned, float, float, float);

template <> void Closure3<CWorldStreamManager, bool, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; float * arguments = (float *)__p1; bool * result = (bool *)__p2;

    bool value = (*(StreamCallback *)&this->f_1c)((*(CWorldStreamManager_205ce0 * *)&this->f_20), 0, arguments[0], arguments[1], arguments[2]);
    if (result) *result = value;
}
