class RefObj_237470 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Base_237470 {
  public:
    Base_237470();
    virtual void f0();
    char pad[0x18];
};

class OpportunityAction : public Base_237470 {
  public:
    OpportunityAction(RefObj_237470* a, int b, int c, int d, RefObj_237470* e, int f, int g, int h, RefObj_237470* i);
    virtual void f0();
    RefObj_237470* m1c;
    int m20;
    int m24;
    int m28;
    RefObj_237470* m2c;
    int m30;
    int m34;
    int m38;
    RefObj_237470* m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
};

OpportunityAction::OpportunityAction(RefObj_237470* a, int b, int c, int d, RefObj_237470* e, int f, int g, int h,
                                     RefObj_237470* i) {
    m24 = c;
    m28 = d;
    m1c = 0;
    m20 = 0;
    m2c = 0;
    m30 = f;
    m34 = g;
    m38 = h;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    if (a)
        a->AddRef();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = b;
    if (e)
        e->AddRef();
    if (m2c)
        m2c->Release();
    m2c = e;
    if (i)
        i->AddRef();
    if (m3c)
        m3c->Release();
    m3c = i;
}
