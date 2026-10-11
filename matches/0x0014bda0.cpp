extern "C" char DAT_004135d8[];
extern void* __cdecl Allocate(unsigned int);
class CivilianTargetCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    CivilianTargetCondition(int);
    char data[12];
};
class ConditionFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
void* ConditionFactoryTemplate::F() {
    CivilianTargetCondition* p = (CivilianTargetCondition*)Allocate(0x10);
    void* r;
    if (p) {
        p->CivilianTargetCondition::CivilianTargetCondition(0);
        *(unsigned long*)p = ((int)DAT_004135d8);
        p->data[8] = 1;
        r = p;
    } else
        r = 0;
    return r;
}