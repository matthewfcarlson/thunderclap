#include "compat/ptr.h"
struct PropsToSuckCondition {
    void InitBase(int flag);
    char pad[0xc];
    int m_c;
    float m_f;
    unsigned char m_b;
    int m_i;
};

extern void* __cdecl Alloc(hulk_uintptr);
extern int g_PropsToSuckVftable;

void* __cdecl Factory_vfunc_5(void* self) {
    PropsToSuckCondition* p = (PropsToSuckCondition*)Alloc(0x1c);
    if (p != 0) {
        p->InitBase(0);
        *(void**)p = (void*)&g_PropsToSuckVftable;
        p->m_c = 0;
        p->m_f = 10.0f;
        p->m_b = 0;
        p->m_i = -1;
        return p;
    }
    return 0;
}
