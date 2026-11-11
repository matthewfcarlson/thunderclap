// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x00230720 FUN_00230720 (48 B): matches/0x00230720.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?F@Obj_230720@fn_f6ac16f7@@QAEXPAU12@@Z
#include "gen/owners.h"
namespace fn_f6ac16f7 {} using namespace fn_f6ac16f7;
namespace fn_f6ac16f7 {
// Same code shape as 0x0022d210 (propagated; names are from that function)
struct Obj_230720 {
    unsigned int x[3];
    void F(Obj_230720*);
};
struct Arg_230720 {
};
void Obj_230720::F(Obj_230720* a) {
    unsigned int t[3];
    ((owners::M_22c3b0 *)(((Arg_230720*)a)))->FUN_0022c3b0((float *)(Obj_230720 *)this, (float *)t);
    x[0] = t[0];
    x[1] = t[1];
    x[2] = t[2];
}
} // namespace fn_f6ac16f7

