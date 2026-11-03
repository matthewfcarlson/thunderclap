// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_18bd30;

struct ConditionFactoryTemplate_18bd30 {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete(void*);

void* ConditionFactoryTemplate_18bd30::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_18bd30;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}
