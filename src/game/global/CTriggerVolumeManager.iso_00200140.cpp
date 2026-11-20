// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fc690..0x00201740 (kind game, layer game, confidence high), dominant class CTriggerVolumeManager
// (tree_prelude.h: not needed)


// 0x00200140 Closure3<CTriggerVolumeManager,bool,math::Vector,const_char_*,bool>::vfunc_2 (68 B): matches/0x00200140.cpp [isolated: conflict: Args; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_200140@fn_00200140@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

namespace math {
struct Vector_200140 {
    float x, y, z;
};
} // namespace math
class CTriggerVolumeManager_200140 {
  public:
    bool method(math::Vector_200140, const char*, bool);
};
struct Args {
    math::Vector_200140 v;
    const char* str;
    bool flag;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CTriggerVolumeManager, bool,math::Vector, const char *, bool>::vfunc_2`.
namespace fn_00200140 {
struct Closure3_200140 : hulk_script::FunctionGenView {
    bool (::CTriggerVolumeManager::*f_1c)(math::Vector, const char *, bool);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_200140::vfunc_2(void* __p0, void* __p1, void* __p2) { Args * args = (Args *)__p1; bool * out = (bool *)__p2;

    CTriggerVolumeManager_200140* p = (*(CTriggerVolumeManager_200140 * *)&this->f_20);
    bool (CTriggerVolumeManager_200140::*f)(math::Vector_200140, const char*, bool) = (*(bool (CTriggerVolumeManager_200140::**)(math::Vector_200140, const char *, bool))&this->f_1c);
    Args* a = args;
    bool b = a->flag;
    const char* s = a->str;
    *(volatile bool*)&args = b;
    bool r = (p->*f)(a->v, s, *(bool*)&args);
    if (out)
        *out = r;
}
} // namespace fn_00200140

