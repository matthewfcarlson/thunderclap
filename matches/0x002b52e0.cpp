class Ref_2b52e0 {
  public:
    virtual void A();
    virtual void B();
};
class Base_2b52e0 {
  public:
    virtual void Q();
    Base_2b52e0();
};
extern Ref_2b52e0* gGlobal_2b52e0;
inline Ref_2b52e0* Acq(Ref_2b52e0* x) {
    if (x)
        x->A();
    return x;
}
class ShadowMeshImpl : public Base_2b52e0 {
  public:
    virtual void V();
    int pad10[3];
    int mValue;
    char pad14[0x2c];
    Ref_2b52e0* m0;
    Ref_2b52e0* m1;
    Ref_2b52e0* m2;
    Ref_2b52e0* m3;
    Ref_2b52e0* m4;
    ShadowMeshImpl(void*);
};
class Input_2b52e0 {
  public:
    char pad[0x44];
    Ref_2b52e0* a;
    Ref_2b52e0* b;
};
ShadowMeshImpl::ShadowMeshImpl(void* arg) {
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    mValue = 2;
    Ref_2b52e0* p = Acq(gGlobal_2b52e0);
    if (m0)
        m0->B();
    m0 = p;
    p = ((Input_2b52e0*)arg)->a;
    if (p)
        p->A();
    if (m1)
        m1->B();
    m1 = p;
    p = ((Input_2b52e0*)arg)->b;
    if (p)
        p->A();
    if (m2)
        m2->B();
    m2 = p;
}
