// Same code shape as 0x00016580 (propagated; names are from that function)
#include "gen/global.h"

struct ObjA_17570 {
    ObjA_17570* f();
};
struct ObjB_17570 {
    ObjB_17570* g();
};
struct ObjC_17570 {
    void h(int);
};

bool CUninterruptibleAction::vfunc_6(int ) {
    ObjA_17570* a = (*(ObjA_17570 * *)&this->f_1c)->f();
    ObjB_17570* b = ((ObjB_17570*)a)->g();
    ((ObjC_17570*)b)->h(1);
    return true;
}
