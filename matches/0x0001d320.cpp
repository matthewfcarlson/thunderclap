// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_1d320 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1d320 {
  public:
    virtual void VFunc();
    Action_1d320();
};

class CAction : public Action_1d320 {
  public:
    char m_pad[0x18];
    IRef_1d320* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_1d320* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CMoveAddAction_1d320 : public CAction {
  public:
    virtual void ProcessDrift();
    CMoveAddAction_1d320(int a, IRef_1d320* p);
};

CMoveAddAction_1d320::CMoveAddAction_1d320(int a, IRef_1d320* p) : CAction(a, p) {}