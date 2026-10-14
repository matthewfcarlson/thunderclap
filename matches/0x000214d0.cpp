// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_214d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class CBase_214d0 {
  public:
    virtual void VFunc();
    CBase_214d0();
};

class CAction : public CBase_214d0 {
  public:
    char m_pad[0x18];
    IRef_214d0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_214d0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CDriftAction : public CAction {
  public:
    virtual void ProcessDrift();
    CDriftAction(int a, IRef_214d0* p);
};

CDriftAction::CDriftAction(int a, IRef_214d0* p) : CAction(a, p) {}