// Same code shape as 0x00013b40 (propagated; names are from that function)
#include "gen/global.h"

struct R_17c80 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_17c80* __fastcall FUN_00059a40(void*);

void CSnapToWallAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_17c80* b = FUN_00059a40(a);
    if (b)
        b->call((*(void * *)&this->f_24), 0);
}
