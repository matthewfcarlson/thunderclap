// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d190 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class CBase_1d190 {
  public:
    virtual void VFunc();
    CBase_1d190();
};

class CAction : public CBase_1d190 {
  public:
    char m_pad[0x18];
    IRef_1d190* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1d190* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CSoundAction_1d190 : public CAction {
  public:
    virtual void ProcessDrift();
    CSoundAction_1d190(int a, IRef_1d190* p);
};

CSoundAction_1d190::CSoundAction_1d190(int a, IRef_1d190* p) : CAction(a, p) {}