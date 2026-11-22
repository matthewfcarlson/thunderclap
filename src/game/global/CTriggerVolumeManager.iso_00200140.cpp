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
#if defined(HULK_PTR64)
// (nat3) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells, and the
// instantiation's own types (the 32-bit source's propagated (const char*, int) passes them in other registers)
void Closure3_200140::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Vec_ { float x, y, z; };
    struct Args_ { Vec_ a0; const char * a1; bool a2; };
    const Args_* a = (const Args_*)__p1;
    bool r = ((*(Obj_**)&this->f_20)->*(*(bool (Obj_::**)(Vec_, const char *, bool))&this->f_1c))(a->a0, a->a1, a->a2);
    if (__p2) *(bool*)__p2 = r;
}
#else
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
#endif
} // namespace fn_00200140

