#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Context_10dfa0;
struct Inner_10dfa0 {
    Context_10dfa0* Get();
    void* FUN_00059a30();
};
struct Context_10dfa0 {
    Context_10dfa0* FUN_000592a0();
    void* FUN_00059a30();
};

bool hulkfight::ai::TokenAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    Context_10dfa0* c = (*(Context_10dfa0 * *)&this->f_20);
    if (!c)
        return false;
    Context_10dfa0* d = c->FUN_000592a0();
    char* p = (char*)d->FUN_00059a30();
    p[0x1b84] = 1;
    return true;
}
