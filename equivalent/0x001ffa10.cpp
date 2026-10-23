// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001ffa10
#include "gen/global.h"

struct Vector_1ffa10 { float x,y,z; };
struct CTriggerVolumeManager_1ffa10 { char padding[28]; };

template <> void Closure1<CTriggerVolumeManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** input = (const char **)__p1; Vector_1ffa10 * result = (Vector_1ffa10 *)__p2;

    Vector_1ffa10 value = ((*(CTriggerVolumeManager_1ffa10 * *)&this->f_20)->*(*(Vector_1ffa10 (CTriggerVolumeManager_1ffa10::**)(const char *))&this->f_1c))(*input);
    if (result) *result = value;
}
