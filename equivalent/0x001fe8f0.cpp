// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001fe8f0
#include "gen/global.h"

namespace math { struct Vector_1fe8f0 { float x,y,z; }; }
struct CTriggerVolumeManager_1fe8f0 { math::Vector_1fe8f0* FUN_001fe8f0(math::Vector_1fe8f0*, const char*); };
struct Function_1fe8f0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };

template <> void Method1<CTriggerVolumeManager,math::Vector, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fe8f0 * manager = (CTriggerVolumeManager_1fe8f0 *)__p0; const char ** text = (const char **)__p1; math::Vector_1fe8f0 * result = (math::Vector_1fe8f0 *)__p2;

 math::Vector_1fe8f0 temp;
 math::Vector_1fe8f0* source = (manager->*(*(math::Vector_1fe8f0 *(CTriggerVolumeManager_1fe8f0::**)(math::Vector_1fe8f0 *, const char *))&this->f_1c))(&temp, *text);
 temp = *source;
 if(result) *result = temp;
}
