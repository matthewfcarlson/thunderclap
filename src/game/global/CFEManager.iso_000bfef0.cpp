// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be230..0x000c4ec0 (kind game, layer game, confidence high), dominant class CFEManager
// (tree_prelude.h: not needed)


// 0x000bfef0 Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 (58 B): equivalent/0x000bfef0.cpp [isolated: code differs from its standalone build; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure6_bfef0@fn_000bfef0@@QAEXPAX00@Z @d87f9086673d @w1d20f9aaabb3 @v7f427c126dca
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 @ 0x000bfef0
#include "gen/global.h"
#include "game/script_bind.h"

struct CFEManager_bfef0 { void FUN_000bfef0(const char *,const char *,const char *,const char *,int,int); };

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::vfunc_2`.
namespace fn_000bfef0 {
struct Closure6_bfef0 : hulk_script::FunctionGenView {
    void (::CFEManager::*f_1c)(const char *, const char *, const char *, const char *, int, int);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
#if defined(HULK_PTR64)
// (script2, stop 6) natively: the arguments in their natural layout, the dispatcher 0x001d22a0's native cells
void Closure6_bfef0::vfunc_2(void* __p0, void* __p1, void* __p2) {
    struct Obj_ {};
    struct Args_ { const char* a0; const char* a1; const char* a2; const char* a3; int a4; int a5; };
    const Args_* a = (const Args_*)__p1;
    ((*(Obj_**)&this->f_20)->*(*(void (Obj_::**)(const char*, const char*, const char*, const char*, int, int))&this->f_1c))(a->a0, a->a1, a->a2, a->a3, a->a4, a->a5);
}
#else
void Closure6_bfef0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const int * args = (const int *)__p1; void * unused2 = (void *)__p2;

    ((*(CFEManager_bfef0 * *)&this->f_20)->*(*(void (CFEManager_bfef0::**)(const char *, const char *, const char *, const char *, int, int))&this->f_1c))((const char *)args[0], (const char *)args[1], (const char *)args[2], (const char *)args[3], args[4], args[5]);
}
#endif
} // namespace fn_000bfef0
#if defined(HULK_PTR64)
// (script2) natively gen's template still has this vftable slot (its destructor specializations emit the
// vftable): forward it to the record's function
template <> void Closure6<CFEManager, void, const char *, const char *, const char *, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { ((fn_000bfef0::Closure6_bfef0*)this)->vfunc_2(__p0, __p1, __p2); }
#endif

