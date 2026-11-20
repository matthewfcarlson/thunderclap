// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)


// 0x000cfae0 Closure3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 (46 B): equivalent/0x000cfae0.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Closure3_cfae0@fn_000cfae0@@QAEXPAX00@Z @a42630cfa2e4 @w685e7d91b439 @v2be4ecf4708a
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cfae0
#include "gen/global.h"
#include "game/script_bind.h"

struct HUDOverlay_cfae0 {
    int FUN_000cfae0(const char *, const char *, float);
};
struct Arguments {
    const char *first;
    const char *second;
    float third;
};

// (script2) a plain member of a non-polymorphic record (no stand-in vftable / RTTI natively): was
// `template <> void Closure3<HUDOverlay, int, const char *, const char *, float>::vfunc_2`.
namespace fn_000cfae0 {
struct Closure3_cfae0 : hulk_script::FunctionGenView {
    int (::HUDOverlay::*f_1c)(const char *, const char *, float);
    hulk_intptr f_20;
    void vfunc_2(void* __p0, void* __p1, void* __p2);
};
void Closure3_cfae0::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; int * result = (int *)__p2;

    const char *first = args->first;
    const char *second = args->second;
    float third = args->third;
    int value = ((*(HUDOverlay_cfae0 * *)&this->f_20)->*(*(int (HUDOverlay_cfae0::**)(const char *, const char *, float))&this->f_1c))(first, second, third);
    if (result) *result = value;
}
} // namespace fn_000cfae0

