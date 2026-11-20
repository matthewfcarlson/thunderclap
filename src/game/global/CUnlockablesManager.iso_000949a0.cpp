// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
// (tree_prelude.h: not needed)


// 0x000949a0 Closure3<CUnlockablesManager,void,int,int,bool>::vfunc_2 (30 B): equivalent/0x000949a0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_949a0@fn_000949a0@@QAEXPAX00@Z @bf9aeccd3fbc @w8cf46082fadf @veb279dcdace5
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,int,bool>::vfunc_2 @ 0x000949a0
#include "gen/global.h"
#include "game/script_bind.h"

struct CUnlockablesManager_949a0 { void placeholder(); };
struct Arguments { int first; int second; bool third; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CUnlockablesManager, void, int, int, bool>::vfunc_2`.
namespace fn_000949a0 {
struct Closure3_949a0 : hulk_script::FunctionGenView {
    void (::CUnlockablesManager::*f_1c)(int, int, bool);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_949a0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused1 = (void *)__p0; Arguments * arguments = (Arguments *)__p1; void * unused3 = (void *)__p2;

    ((*(CUnlockablesManager_949a0 * *)&this->f_20)->*(*(void (CUnlockablesManager_949a0::**)(int, int, bool))&this->f_1c))(arguments->first, arguments->second, arguments->third);
}
} // namespace fn_000949a0

