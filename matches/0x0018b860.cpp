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
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual PropGrabbableIsThrownCondition* Create();
};
PropGrabbableIsThrownCondition* Factory::Create() {
    PropGrabbableIsThrownCondition* p = (PropGrabbableIsThrownCondition*)Alloc(16);
    if (p) {
        p->PropGrabbableIsThrownCondition::PropGrabbableIsThrownCondition(0);
        *(unsigned int*)p = 0x41918c;
        p->flag = 1;
        return p;
    }
    return 0;
}