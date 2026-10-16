// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method4<CTriggerVolumeManager,bool,const_char_*,math::Vector,math::Vector,float>::vfunc_2 @ 0x001fed30
#include "gen/global.h"

struct Vec_1fed30 {
    unsigned x, y, z;
};
struct Args_1fed30 {
    const char *name;
    Vec_1fed30 from;
    Vec_1fed30 to;
    unsigned radius;
};
class CTriggerVolumeManager_1fed30 {
  public:
    bool Check(const char *name, Vec_1fed30 from, Vec_1fed30 to, unsigned radius);
};
typedef bool (CTriggerVolumeManager_1fed30::*CheckFn_1fed30)(const char *, Vec_1fed30, Vec_1fed30, unsigned);
class Function_1fed30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method4<CTriggerVolumeManager, bool, const char *,math::Vector,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1fed30 * obj = (CTriggerVolumeManager_1fed30 *)__p0; Args_1fed30 * args = (Args_1fed30 *)__p1; bool * out = (bool *)__p2;

    CheckFn_1fed30 fn = (*(CheckFn_1fed30 *)&this->f_1c);
    bool r = (obj->*fn)(args->name, args->from, args->to, args->radius);
    if (out)
        *out = r;
}
