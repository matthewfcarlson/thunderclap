// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CPatrolPathManager,bool,const_char_*,int,math::Vector>::vfunc_2 @ 0x00106b70
#include "gen/global.h"

struct Vector_106b70 { float x, y, z; };
struct Arguments { const char* name; int value; Vector_106b70 position; };
struct CPatrolPathManager_106b70 {
    bool FUN_00106b70(const char*, int, Vector_106b70);
};
struct Function_106b70 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CPatrolPathManager, bool, const char *, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CPatrolPathManager_106b70 * owner = (CPatrolPathManager_106b70 *)__p0; const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (owner->*(*(bool (CPatrolPathManager_106b70::**)(const char *, int, Vector_106b70))&this->f_1c))(args->name, args->value, args->position);
    if (result) *result = value;
}
