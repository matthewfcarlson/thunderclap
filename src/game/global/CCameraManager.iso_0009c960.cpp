// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0009c960 Closure6<CCameraManager,void,int,int,float,int,int,float>::vfunc_2 (63 B): equivalent/0x0009c960.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure6_9c960@fn_0009c960@@QAEXPAX00@Z @d87f9086673d @w00d10d905daa @v42951b99a518
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CCameraManager,void,int,int,float,int,int,float>::vfunc_2 @ 0x0009c960
#include "gen/global.h"
#include "game/script_bind.h"

struct CCameraManager_9c960 { void FUN_0009c960(int, int, float, int, int, float); };
struct Arguments { int first; int second; float third; int fourth; int fifth; float sixth; };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure6<CCameraManager, void, int, int, float, int, int, float>::vfunc_2`.
namespace fn_0009c960 {
struct Closure6_9c960 : hulk_script::FunctionGenView {
    void (::CCameraManager::*f_1c)(int, int, float, int, int, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure6_9c960::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * arguments = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CCameraManager_9c960 * *)&this->f_20)->*(*(void (CCameraManager_9c960::**)(int, int, float, int, int, float))&this->f_1c))(arguments->first, arguments->second, arguments->third, arguments->fourth, arguments->fifth, arguments->sixth);
}
} // namespace fn_0009c960
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure6<CCameraManager, void, int, int, float, int, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_0009c960::Closure6_9c960*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

