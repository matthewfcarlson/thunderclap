// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001ffb80
#include "gen/global.h"

struct Vector_1ffb80 { float x,y,z,w; };
struct CTriggerVolumeManager_1ffb80 {};

template <> void Closure2<CTriggerVolumeManager, bool, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Vector_1ffb80 * value = (const Vector_1ffb80 *)__p1; bool * result = (bool *)__p2;

    bool answer = ((*(CTriggerVolumeManager_1ffb80 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_1ffb80::**)(Vector_1ffb80))&this->f_1c))(*value);
    if (result) *result = answer;
}
