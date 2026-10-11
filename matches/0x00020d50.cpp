class Other {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    Base();
    virtual void X();
    char pad[0x18];
};
class CAction : public Base {
  public:
    virtual void A();
    Other* m1c;
    int m20;
    CAction(int a, Other* o) : m1c(0) {
        if (o)
            o->AddRef();
        if (m1c)
            m1c->Release();
        m1c = o;
        m20 = a;
    }
};
class CWallSlideAction : public CAction {
  public:
    virtual void A();
    int m24;
    CWallSlideAction(int, Other*);
};
CWallSlideAction::CWallSlideAction(int a, Other* o) : CAction(a, o) {
    m24 = 0;
}
