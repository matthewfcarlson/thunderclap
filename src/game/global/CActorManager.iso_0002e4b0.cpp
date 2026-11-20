// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002e4b0 Method2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 (58 B): equivalent/0x0002e4b0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Method2_2e4b0@fn_0002e4b0@@QAEXPAX00@Z @5070c124e04e @w8cf067245f4c @vbf92294aae67
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Method2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x0002e4b0
#include "gen/global.h"
#include "game/script_bind.h"

namespace math { struct Vector_2e4b0 { float x,y,z; }; }
class CActorManager_2e4b0 {};
struct Arguments { const char* text; math::Vector_2e4b0 position; };
class Function_2e4b0 { public: virtual void vfunc_0(); virtual void vfunc_1(); };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Method2<CActorManager, bool, const char *,math::Vector>::vfunc_2`.
namespace fn_0002e4b0 {
struct Method2_2e4b0 : hulk_script::FunctionGenView {
    bool (::CActorManager::*f_1c)(const char *, math::Vector);
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Method2_2e4b0::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e4b0 * actor = (CActorManager_2e4b0 *)__p0; const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (actor->*(*(bool (CActorManager_2e4b0::**)(const char *, math::Vector_2e4b0))&this->f_1c))(args->text, args->position);
    if (result) *result = value;
}
} // namespace fn_0002e4b0

