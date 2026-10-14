class Other_20d50 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_20d50 {
  public:
    Base_20d50();
    virtual void X();
    char pad[0x18];
};
class CAction : public Base_20d50 {
  public:
    virtual void A();
    Other_20d50* m1c;
    int m20;
    CAction(int a, Other_20d50* o) : m1c(0) {
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
    CWallSlideAction(int, Other_20d50*);
};
CWallSlideAction::CWallSlideAction(int a, Other_20d50* o) : CAction(a, o) {
    m24 = 0;
}
