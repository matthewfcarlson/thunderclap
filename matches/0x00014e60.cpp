// Same code shape as 0x00013b40 (propagated; names are from that function)
#include "gen/global.h"

struct R_14e60 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_14e60* __fastcall FUN_00059a40(void*);

void CMoveAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_14e60* b = FUN_00059a40(a);
    if (b)
        b->call((*(void * *)&this->f_24), 0);
}
