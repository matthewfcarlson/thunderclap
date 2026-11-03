// Same code shape as 0x0006fb50 (propagated; names are from that function)
#include "gen/owners.h"
extern int g_vftable_283dc0;

struct EffectQueue_283dc0 {
    void* m_vptr;
    void base2_dtor();
    void* scalar_dtor(unsigned char param_2);
};

void thunk_delete(void*);

void* EffectQueue_283dc0::scalar_dtor(unsigned char param_2) {
    m_vptr = (void*)&g_vftable_283dc0;
    ((owners::Owner_280160 *)this)->FUN_00280160();
    base2_dtor();
    if (param_2 & 1)
        thunk_delete(this);
    return this;
}
