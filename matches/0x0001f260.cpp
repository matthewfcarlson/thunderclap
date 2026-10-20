// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1f260 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class CBase_1f260 {
  public:
    virtual void VFunc();
    CBase_1f260();
};

class CAction : public CBase_1f260 {
  public:
    char m_pad[0x18];
    IRef_1f260* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1f260* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSmartPropThrowAction_1f260 : public CAction {
  public:
    virtual void ProcessDrift();
    CSmartPropThrowAction_1f260(int a, IRef_1f260* p);
};

CSmartPropThrowAction_1f260::CSmartPropThrowAction_1f260(int a, IRef_1f260* p) : CAction(a, p) {}