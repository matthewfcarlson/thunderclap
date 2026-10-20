// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSubtitleManager,void,float,float,float>::vfunc_2 @ 0x001c01b0
#include "gen/global.h"

struct CSubtitleManager_1c01b0 { char padding[4]; };

template <> void Closure3<CSubtitleManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const float * values = (const float *)__p1; void * unused2 = (void *)__p2;

    ((*(CSubtitleManager_1c01b0 * *)&this->f_20)->*(*(void (CSubtitleManager_1c01b0::**)(float, float, float))&this->f_1c))(values[0], values[1], values[2]);
}
