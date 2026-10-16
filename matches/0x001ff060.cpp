#include "gen/global.h"

namespace math {
struct Vector_1ff060 {
    float x, y, z;
};
} // namespace math
class CTriggerVolumeManager_1ff060 {
  public:
    bool Execute(math::Vector_1ff060, const char*, bool);
};
typedef bool (CTriggerVolumeManager_1ff060::*Fn)(math::Vector_1ff060, const char*, bool);
class Function_1ff060 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Params_1ff060 {
    math::Vector_1ff060 v;
    const char* name;
    bool flag;
};

template <> void Method3<CTriggerVolumeManager, bool,math::Vector, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff060 * obj = (CTriggerVolumeManager_1ff060 *)__p0; Params_1ff060 * p = (Params_1ff060 *)__p1; bool * result = (bool *)__p2;

    Fn fn = (*(Fn *)&this->f_1c);
    const char* name = p->name;
    bool flag = p->flag;
    bool r = (obj->*fn)(p->v, name, flag);
    if (result)
        *result = r;
}
