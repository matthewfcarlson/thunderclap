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
#if defined(HULK_PTR64)
// (nat3) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells, and the
// instantiation's own types (the 32-bit source's propagated (const char*, int) passes them in other registers)
void Closure5_9c760::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { bool a0; bool a1; bool a2; bool a3; float a4; };
    const Args_* a = (const Args_*)__p1;
    ((*(Obj_**)&this->f_20)->*(*(void (Obj_::**)(bool, bool, bool, bool, float))&this->f_1c))(a->a0, a->a1, a->a2, a->a3, a->a4);
}
#else
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
#endif
} // namespace fn_0009c760

