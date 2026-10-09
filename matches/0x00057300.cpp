void* __cdecl Alloc(unsigned int);
class CButtonPressCondition {
  public:
    CButtonPressCondition();
};
class ConditionFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CButtonPressCondition* V5();
};
CButtonPressCondition* ConditionFactoryTemplate::V5() {
    CButtonPressCondition* p = (CButtonPressCondition*)Alloc(0x20);
    if (p) {
        p->CButtonPressCondition::CButtonPressCondition();
        *(int*)p = 0x3f9230;
        return p;
    }
    return 0;
}