// Same code shape as 0x0006fb50 (propagated; names are from that function)
#include "gen/Render.h"
extern int g_vftable_1c7dc0;

struct Store_1c7dc0 {
    void* m_vptr;
    void base2_dtor();
    void* scalar_dtor(unsigned char param_2);
};

void thunk_delete(void*);

void* Store_1c7dc0::scalar_dtor(unsigned char param_2) {
    m_vptr = (void*)&g_vftable_1c7dc0;
    ((Render::StoreBase *)this)->FUN_001c7720();
    base2_dtor();
    if (param_2 & 1)
        thunk_delete(this);
    return this;
}
