// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1dcd0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1dcd0 {
  public:
    virtual void VFunc();
    Action_1dcd0();
};

class CAction : public Action_1dcd0 {
  public:
    char m_pad[0x18];
    IRef_1dcd0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1dcd0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CGrappleAttachAction_1dcd0 : public CAction {
  public:
    virtual void ProcessDrift();
    CGrappleAttachAction_1dcd0(int a, IRef_1dcd0* p);
};

CGrappleAttachAction_1dcd0::CGrappleAttachAction_1dcd0(int a, IRef_1dcd0* p) : CAction(a, p) {}