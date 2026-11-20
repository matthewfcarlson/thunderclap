// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)


// 0x000cfe20 Closure2<HUDOverlay,int,int,const_char_*>::vfunc_2 (36 B): equivalent/0x000cfe20.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure2_cfe20@fn_000cfe20@@QAEXPAX00@Z @5f2db1ebe681 @w450eaf8a6c9b @v466f937fe327
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<HUDOverlay,int,int,const_char_*>::vfunc_2 @ 0x000cfe20
#include "gen/global.h"
#include "game/script_bind.h"

struct HUDOverlay_cfe20 {
    int FUN_000cfe20(int value, const char *text);
};
struct Arguments {
    int value;
    const char *text;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure2<HUDOverlay, int, int, const char *>::vfunc_2`.
namespace fn_000cfe20 {
struct Closure2_cfe20 : hulk_script::FunctionGenView {
    int (::HUDOverlay::*f_1c)(int, const char *);
    void* f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure2_cfe20::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * arguments = (Arguments *)__p1; int * result = (int *)__p2;

    int value = ((*(HUDOverlay_cfe20 * *)&this->f_20)->*(*(int (HUDOverlay_cfe20::**)(int, const char *))&this->f_1c))(arguments->value, arguments->text);
    if (result)
        *result = value;
}
} // namespace fn_000cfe20

