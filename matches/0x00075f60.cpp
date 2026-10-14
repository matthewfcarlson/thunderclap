// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int g_vftable_75f60;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor();
    void base2_dtor();
    void* scalar_dtor(unsigned char param_2);
};

void thunk_delete(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char param_2) {
    m_vptr = (void*)&g_vftable_75f60;
    base1_dtor();
    base2_dtor();
    if (param_2 & 1)
        thunk_delete(this);
    return this;
}
