// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0002c4f0..0x00034400 (kind game, layer game, confidence high), dominant class CActorManager
// (tree_prelude.h: not needed)


// 0x0002e910 Closure3<CActorManager,void,const_char_*,float,bool>::vfunc_2 (30 B): equivalent/0x0002e910.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_2e910@fn_0002e910@@QAEXPAX00@Z @bf9aeccd3fbc @w141fb9b1df1c @vbe4b4fe01f6f
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002e910
#include "gen/global.h"
#include "game/script_bind.h"

struct CActorManager_2e910 { void FUN_00000000(const char *, float, bool); };
struct Arguments { const char *name; float value; bool flag; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CActorManager, void, const char *, float, bool>::vfunc_2`.
namespace fn_0002e910 {
struct Closure3_2e910 : hulk_script::FunctionGenView {
    void (::CActorManager::*f_1c)(const char *, float, bool);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_2e910::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CActorManager_2e910 * *)&this->f_20)->*(*(void (CActorManager_2e910::**)(const char *, float, bool))&this->f_1c))(args->name, args->value, args->flag);
}
} // namespace fn_0002e910

