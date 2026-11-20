// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b8690..0x001bc0c0 (kind game, layer game, confidence high), dominant class CRenderManager
// (tree_prelude.h: not needed)


// 0x001ba4f0 Closure3<CRenderManager,void,int,int,int>::vfunc_2 (28 B): matches/0x001ba4f0.cpp [isolated: conflict: Args; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_1ba4f0@fn_001ba4f0@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

class CRenderManager_1ba4f0 {
  public:
    void invoke(int, int, int);
};
class Function_1ba4f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Args {
    volatile int a, b, c;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CRenderManager, void, int, int, int>::vfunc_2`.
namespace fn_001ba4f0 {
struct Closure3_1ba4f0 : hulk_script::FunctionGenView {
    void (::CRenderManager::*f_1c)(int, int, int);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_1ba4f0::vfunc_2(void* __p0, void* __p1, void* __p2) { Args * args = (Args *)__p1;

    int a = args->a;
    int c = args->c;
    int b = args->b;
    ((*(CRenderManager_1ba4f0 * *)&this->f_20)->*(*(void (CRenderManager_1ba4f0::**)(int, int, int))&this->f_1c))(a, b, c);
}
} // namespace fn_001ba4f0

