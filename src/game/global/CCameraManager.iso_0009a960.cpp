// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0009a960 Method3<CCameraManager,void,float,float,bool>::vfunc_2 (37 B): matches/0x0009a960.cpp [isolated: conflict: Args; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Method3_9a960@fn_0009a960@@QAEXPAX00@Z
#include "gen/global.h"
#include "game/script_bind.h"

class CCameraManager_9a960 {
  public:
    void Do(float, float, bool);
};
struct Args {
    float a, b;
    bool c;
};
class Function_9a960 {
  public:
    virtual void F0();
    virtual void F1();
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method3<CCameraManager, void, float, float, bool>::vfunc_2`.
namespace fn_0009a960 {
struct Method3_9a960 : hulk_script::FunctionGenView {
    void (::CCameraManager::*f_1c)(float, float, bool);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method3_9a960::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9a960 * obj = (CCameraManager_9a960 *)__p0; Args * args = (Args *)__p1; hulk_intptr unused = (hulk_intptr)__p2;

    Args* p = args;
    *(volatile float*)&args = p->a;
    (obj->*(*(void (CCameraManager_9a960::**)(float, float, bool))&this->f_1c))(*(float*)&args, p->b, p->c);
}
} // namespace fn_0009a960
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Method3<CCameraManager, void, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_0009a960::Method3_9a960*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

