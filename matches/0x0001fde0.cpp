class IRef_1fde0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1fde0 {
  public:
    virtual void VFunc();
    Action_1fde0();
};

class CAction : public Action_1fde0 {
  public:
    char m_pad[0x18];
    IRef_1fde0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1fde0* p) {
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
    CDriftAction(int a, IRef_1fde0* p);
};

CDriftAction::CDriftAction(int a, IRef_1fde0* p) : CAction(a, p) {}