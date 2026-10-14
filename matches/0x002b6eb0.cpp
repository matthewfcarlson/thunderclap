extern "C" char DAT_0042e5b4[];
struct RelObj_2b6eb0 {
    virtual void vfunc_0();
    virtual void Release();
};

void __cdecl operator delete(void* p);

class ShadowMeshImpl {
  public:
    void BaseCleanup();

    void* volatile m_vptr;
    char pad[0x3C];
    RelObj_2b6eb0* volatile m_a;
    RelObj_2b6eb0* volatile m_b;
    RelObj_2b6eb0* volatile m_c;

    ShadowMeshImpl* vfunc_2(unsigned char flags);
};

ShadowMeshImpl* ShadowMeshImpl::vfunc_2(unsigned char flags) {
    m_vptr = (void*)((int)DAT_0042e5b4);
    RelObj_2b6eb0* a = m_a;
    if (a != 0) {
        a->Release();
        m_a = 0;
    }
    RelObj_2b6eb0* b = m_b;
    if (b != 0) {
        b->Release();
        m_b = 0;
    }
    RelObj_2b6eb0* c = m_c;
    if (c != 0) {
        c->Release();
        m_c = 0;
    }
    BaseCleanup();
    if (flags & 1)
        operator delete(this);
    return this;
}
