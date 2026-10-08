// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef {
public:
    virtual void AddRef();
    virtual void Release();
};

class CBase {
public:
    virtual void VFunc();
    CBase();
};

class CAction : public CBase {
public:
    char m_pad[0x18];
    IRef* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef* p) {
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
    CDriftAction(int a, IRef* p);
};

CDriftAction::CDriftAction(int a, IRef* p) : CAction(a, p) {
}