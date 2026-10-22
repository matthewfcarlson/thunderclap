extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b56e0[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_2b56e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ShadowMeshImpl_2b56e0 {
  public:
    void* vptr;
    void Fin();
};
class ShadowSkinImpl_2b56e0 : public ShadowMeshImpl_2b56e0 {
  public:
    char pad[0x40 - 4];
    Ref_2b56e0* m40;
    Ref_2b56e0* m44;
    Ref_2b56e0* m48;
    char pad2[0x70 - 0x4c];
    Ref_2b56e0* m70;
    void* m74;
    Ref_2b56e0* m78;
    Ref_2b56e0* m7c;
    ~ShadowSkinImpl_2b56e0();
};
ShadowSkinImpl_2b56e0::~ShadowSkinImpl_2b56e0() {
    vptr = g_vftable_2b56e0;
    _ReadWriteBarrier();
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    if (m78) {
        m78->Release();
        m78 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    operator delete(m74);
    *(void* volatile*)&vptr = g_vftable2;
    Ref_2b56e0* t = *(Ref_2b56e0* volatile*)&m40;
    if (t) {
        t->Release();
        m40 = 0;
    }
    if (m44) {
        m44->Release();
        m44 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    Fin();
}
