// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00093600..0x000964d0 (kind game, layer game, confidence high), dominant class CUnlockablesManager
// (tree_prelude.h: not needed)


// 0x00094a10 Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 (28 B): equivalent/0x00094a10.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_94a10@fn_00094a10@@QAEXPAX00@Z @737c210bc5da @w346cf641fccb @v97bacfab7c6e
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094a10
#include "gen/global.h"
#include "game/script_bind.h"

struct CUnlockablesManager_94a10 { void callbackPlaceholder(); };
struct Arguments { int value; const char *first; const char *second; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CUnlockablesManager, void, int, const char *, const char *>::vfunc_2`.
namespace fn_00094a10 {
struct Closure3_94a10 : hulk_script::FunctionGenView {
    void (::CUnlockablesManager::*f_1c)(int, const char *, const char *);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_94a10::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CUnlockablesManager_94a10 * *)&this->f_20)->*(*(void (CUnlockablesManager_94a10::**)(int, const char *, const char *))&this->f_1c))(args->value, args->first, args->second);
}
} // namespace fn_00094a10
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure3<CUnlockablesManager, void, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_00094a10::Closure3_94a10*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

