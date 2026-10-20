// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001fea40
#include "gen/global.h"

struct Vector_1fea40 { float x,y,z; };
struct Parameters { const char *name; Vector_1fea40 position; };
struct CTriggerVolumeManager_1fea40 { bool FUN_001fea40(const char *, Vector_1fea40); };
struct Function_1fea40 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };

template <> void Method2<CTriggerVolumeManager, bool, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fea40 * manager = (CTriggerVolumeManager_1fea40 *)__p0; Parameters * params = (Parameters *)__p1; bool * result = (bool *)__p2;

 bool value = (manager->*(*(bool (CTriggerVolumeManager_1fea40::**)(const char *, Vector_1fea40))&this->f_1c))(params->name, params->position);
 if (result) *result = value;
}
