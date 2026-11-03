// Same code shape as 0x0022d210 (propagated; names are from that function)
#include "gen/owners.h"
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