extern "C" char DAT_0042e5b4[];
struct RelObj {
    virtual void vfunc_0();
    virtual void Release();
};

void __cdecl operator delete(void* p);

class ShadowMeshImpl {
  public:
    void BaseCleanup();

    void* volatile m_vptr;
    char pad[0x3C];
    RelObj* volatile m_a;
    RelObj* volatile m_b;
    RelObj* volatile m_c;

    ShadowMeshImpl* vfunc_2(unsigned char flags);
};

ShadowMeshImpl* ShadowMeshImpl::vfunc_2(unsigned char flags) {
    m_vptr = (void*)((int)DAT_0042e5b4);
    RelObj* a = m_a;
    if (a != 0) {
        a->Release();
        m_a = 0;
    }
    RelObj* b = m_b;
    if (b != 0) {
        b->Release();
        m_b = 0;
    }
    RelObj* c = m_c;
    if (c != 0) {
        c->Release();
        m_c = 0;
    }
    BaseCleanup();
    if (flags & 1)
        operator delete(this);
    return this;
}
