class GrappleHealthCondition {
  public:
    GrappleHealthCondition();
    void Init(int x);
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
};

GrappleHealthCondition::GrappleHealthCondition() {
    m12 = 0;
    m16 = 0;
    m20 = 0;
}

void* Alloc(unsigned int);

class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual GrappleHealthCondition* v5();
};

GrappleHealthCondition* ConditionFactoryTemplate::v5() {
    GrappleHealthCondition* p = (GrappleHealthCondition*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->GrappleHealthCondition::GrappleHealthCondition();
        return p;
    }
    return 0;
}
