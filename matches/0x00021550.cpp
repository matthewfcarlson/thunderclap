// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_21550 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_21550 {
  public:
    virtual void VFunc();
    Action_21550();
};

class CAction : public Action_21550 {
  public:
    char m_pad[0x18];
    IRef_21550* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_21550* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CPropActorSetStateAction_21550 : public CAction {
  public:
    virtual void ProcessDrift();
    CPropActorSetStateAction_21550(int a, IRef_21550* p);
};

CPropActorSetStateAction_21550::CPropActorSetStateAction_21550(int a, IRef_21550* p) : CAction(a, p) {}