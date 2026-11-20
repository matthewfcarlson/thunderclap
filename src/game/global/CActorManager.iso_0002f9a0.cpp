// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002f9a0 Closure3<CActorManager,void,const_char_*,float,float>::vfunc_2 (28 B): equivalent/0x0002f9a0.cpp [isolated: conflict: Args; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_2f9a0@fn_0002f9a0@@QAEXPAX00@Z @737c210bc5da @w4be225ef0d24 @vb99413d778d5
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,float>::vfunc_2 @ 0x0002f9a0
#include "gen/global.h"
#include "game/script_bind.h"

struct CActorManager_2f9a0 { char placeholder; };
struct Args { const char* name; float first; float second; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CActorManager, void, const char *, float, float>::vfunc_2`.
namespace fn_0002f9a0 {
struct Closure3_2f9a0 : hulk_script::FunctionGenView {
    void (::CActorManager::*f_1c)(const char *, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_2f9a0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Args * args = (Args *)__p1; void * unused2 = (void *)__p2;

    ((*(CActorManager_2f9a0 * *)&this->f_20)->*(*(void (CActorManager_2f9a0::**)(const char *, float, float))&this->f_1c))(args->name, args->first, args->second);
}
} // namespace fn_0002f9a0

