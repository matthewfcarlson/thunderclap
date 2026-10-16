#include "gen/global.h"

struct R_13b40 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_13b40* __fastcall FUN_00059a40(void*);

void CJointAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_13b40* b = FUN_00059a40(a);
    if (b)
        b->call((*(void * *)&this->f_24), 0);
}
