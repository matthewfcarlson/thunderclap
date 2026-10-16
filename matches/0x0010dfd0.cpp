// Same code shape as 0x0010dfa0 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct Context_10dfd0;
struct Inner_10dfd0 {
    Context_10dfd0* Get();
    void* FUN_00059a30();
};
struct Context_10dfd0 {
    Context_10dfd0* FUN_000592a0();
    void* FUN_00059a30();
};

bool hulkfight::ai::TokenAction::vfunc_5(int __p0, int __p1) {
    Context_10dfd0* c = (*(Context_10dfd0 * *)&this->f_20);
    if (!c)
        return false;
    Context_10dfd0* d = c->FUN_000592a0();
    char* p = (char*)d->FUN_00059a30();
    p[0x1b84] = 1;
    return true;
}
