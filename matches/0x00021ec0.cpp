extern void* g_vftSpawnAction[];
extern void* g_vftCAction[];

struct IRef_21ec0 {
    virtual void vfunc_0();
    virtual void Release();
};

void DestroyAction(void* p);

class CSmartPropSpawnAction {
  public:
    void* volatile m_vftable;
    char m_pad0[0x18];
    IRef_21ec0* volatile m_pField1C;
    char m_pad4[0x4];
    IRef_21ec0* volatile m_pField24;
    char m_pad8[0x40];

    CSmartPropSpawnAction* vfunc_2(unsigned char flags);
    void CleanUp();
};

CSmartPropSpawnAction* CSmartPropSpawnAction::vfunc_2(unsigned char flags) {
    IRef_21ec0* p;

    m_vftable = (void*)g_vftSpawnAction;
    p = m_pField24;
    if (p != 0) {
        p->Release();
        m_pField24 = 0;
    }
    m_vftable = (void*)g_vftCAction;
    p = m_pField1C;
    if (p != 0) {
        p->Release();
        m_pField1C = 0;
    }
    CleanUp();
    if (flags & 1) {
        DestroyAction(this);
    }
    return this;
}
