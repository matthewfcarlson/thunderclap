// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)


// 0x0009c760 Closure5<CCameraManager,void,bool,bool,bool,bool,float>::vfunc_2 (72 B): matches/0x0009c760.cpp [isolated: conflict: V; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure5_9c760@fn_0009c760@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

class CCameraManager_9c760 {
  public:
    void Set(int, int, int, bool, float);
};
union V {
    bool b;
    int n;
    float f;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure5<CCameraManager, void, bool, bool, bool, bool, float>::vfunc_2`.
namespace fn_0009c760 {
struct Closure5_9c760 : hulk_script::FunctionGenView {
    void (::CCameraManager::*f_1c)(bool, bool, bool, bool, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure5_9c760::vfunc_2(void* __p0, void* __p1, void* __p2) { V * args = (V *)__p1;

    V a, b, c;
    a.b = args->b;
    ++args;
    b.b = args->b;
    ++args;
    c.b = args->b;
    ++args;
    ((*(CCameraManager_9c760 * *)&this->f_20)->*(*(void (CCameraManager_9c760::**)(int, int, int, bool, float))&this->f_1c))(a.n, b.n, c.n, args->b, (args + 1)->f);
}
} // namespace fn_0009c760
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure5<CCameraManager, void, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_0009c760::Closure5_9c760*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

