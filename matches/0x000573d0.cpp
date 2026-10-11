extern "C" char DAT_003f927c[];
class CButtonReleaseCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init();
};
extern void* __cdecl Allocate(unsigned int);
class ConditionFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CButtonReleaseCondition* Create();
};
CButtonReleaseCondition* ConditionFactoryTemplate::Create() {
    CButtonReleaseCondition* p = (CButtonReleaseCondition*)Allocate(0x18);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_003f927c);
        return p;
    }
    return 0;
}