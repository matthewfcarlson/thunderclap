// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007e100 Closure3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 (30 B): equivalent/0x0007e100.cpp [isolated: conflict: AmbientArgs; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_7e100@fn_0007e100@@QAEXPAX00@Z @bf9aeccd3fbc @w8cf46082fadf @v6e43ca2b87cc
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007e100
#include "gen/global.h"
#include "game/script_bind.h"

struct CAmbientsManager_7e100 {};
struct AmbientArgs { const char* name; int number; bool enabled; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<CAmbientsManager, void, const char *, int, bool>::vfunc_2`.
namespace fn_0007e100 {
struct Closure3_7e100 : hulk_script::FunctionGenView {
    void (::CAmbientsManager::*f_1c)(const char *, int, bool);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_7e100::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const AmbientArgs * arguments = (const AmbientArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CAmbientsManager_7e100 * *)&this->f_20)->*(*(void (CAmbientsManager_7e100::**)(const char *, int, bool))&this->f_1c))(arguments->name, arguments->number, arguments->enabled);
}
} // namespace fn_0007e100
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure3<CAmbientsManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_0007e100::Closure3_7e100*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

