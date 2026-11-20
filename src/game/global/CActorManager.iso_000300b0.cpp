// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x000300b0 Closure3<CActorManager,void,int,int,int>::vfunc_2 (28 B): equivalent/0x000300b0.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_300b0@fn_000300b0@@QAEXPAX00@Z @737c210bc5da @w346cf641fccb @v34f9b444e08b
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,int,int,int>::vfunc_2 @ 0x000300b0
#include "gen/global.h"
#include "game/script_bind.h"

struct CActorManager_300b0 { void FUN_000300b0(int, int, int); };
struct Triple { int first; int second; int third; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CActorManager, void, int, int, int>::vfunc_2`.
namespace fn_000300b0 {
struct Closure3_300b0 : hulk_script::FunctionGenView {
    void (::CActorManager::*f_1c)(int, int, int);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_300b0::vfunc_2(void* __p0, void* __p1, void* __p2) { Triple * args = (Triple *)__p1;

    ((*(CActorManager_300b0 * *)&this->f_20)->*(*(void (CActorManager_300b0::**)(int, int, int))&this->f_1c))(args->first, args->second, args->third);
}
} // namespace fn_000300b0
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure3<CActorManager, void, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_000300b0::Closure3_300b0*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

