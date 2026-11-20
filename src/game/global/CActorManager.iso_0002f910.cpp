// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002f910 Closure3<CActorManager,bool,const_char_*,float,float>::vfunc_2 (54 B): equivalent/0x0002f910.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_2f910@fn_0002f910@@QAEXPAX00@Z @eec6867036bb @w5f057aab89ca @v8525df0f0416
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CActorManager,bool,const_char_*,float,float>::vfunc_2 @ 0x0002f910
#include "gen/global.h"
#include "game/script_bind.h"

struct CActorManager_2f910 { bool FUN_0002f910(const char *, float, float); };
struct Arguments { const char *name; float first; float second; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CActorManager, bool, const char *, float, float>::vfunc_2`.
namespace fn_0002f910 {
struct Closure3_2f910 : hulk_script::FunctionGenView {
    bool (::CActorManager::*f_1c)(const char *, float, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_2f910::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2f910 * *)&this->f_20)->*(*(bool (CActorManager_2f910::**)(const char *, float, float))&this->f_1c))(args->name, args->first, args->second);
    if (result) *result = value;
}
} // namespace fn_0002f910
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure3<CActorManager, bool, const char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_0002f910::Closure3_2f910*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

