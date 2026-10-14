extern "C" char DAT_0041918c[];
class Condition {
  public:
    Condition(int);
};
class PropGrabbableIsThrownCondition : public Condition {
  public:
    PropGrabbableIsThrownCondition(int);
    char pad[12];
    char flag;
};
void* __cdecl Alloc(unsigned int);
class Factory_18b860 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual PropGrabbableIsThrownCondition* Create();
};
PropGrabbableIsThrownCondition* Factory_18b860::Create() {
    PropGrabbableIsThrownCondition* p = (PropGrabbableIsThrownCondition*)Alloc(16);
    if (p) {
        p->PropGrabbableIsThrownCondition::PropGrabbableIsThrownCondition(0);
        *(unsigned int*)p = ((int)DAT_0041918c);
        p->flag = 1;
        return p;
    }
    return 0;
}