class Ref {
  public:
    virtual void Add();
    virtual void Rel();
};
class Base {
  public:
    Base();
    virtual void f0();
    char pad[0x18];
};
class WallExitAction : public Base {
  public:
    WallExitAction(int a, Ref* b);
    virtual void g0();
    int m1c;
    Ref* m20;
    int m24, m28, m2c, m30, m34, m38;
    float m3c;
    int m40, m44, m48;
};
WallExitAction::WallExitAction(int a, Ref* b) {
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = -1.0f;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m1c = a;
    if (b)
        b->Add();
    if (m20)
        m20->Rel();
    m20 = b;
}
