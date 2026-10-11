class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    virtual void Q();
    Base();
};
extern Ref* gGlobal;
inline Ref* Acq(Ref* x) {
    if (x)
        x->A();
    return x;
}
class ShadowMeshImpl : public Base {
  public:
    virtual void V();
    int pad10[3];
    int mValue;
    char pad14[0x2c];
    Ref* m0;
    Ref* m1;
    Ref* m2;
    Ref* m3;
    Ref* m4;
    ShadowMeshImpl(void*);
};
class Input {
  public:
    char pad[0x44];
    Ref* a;
    Ref* b;
};
ShadowMeshImpl::ShadowMeshImpl(void* arg) {
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    mValue = 2;
    Ref* p = Acq(gGlobal);
    if (m0)
        m0->B();
    m0 = p;
    p = ((Input*)arg)->a;
    if (p)
        p->A();
    if (m1)
        m1->B();
    m1 = p;
    p = ((Input*)arg)->b;
    if (p)
        p->A();
    if (m2)
        m2->B();
    m2 = p;
}
