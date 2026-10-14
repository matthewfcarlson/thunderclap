extern char VT_1aaab0[];
extern void* __cdecl FUN_0008d690(int);
class Sub_1aaab0 {
  public:
    void Init();
};
class Event_PropTypeCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[12];
    Sub_1aaab0 sub;
    Event_PropTypeCondition(int);
};
class Factory_1aaab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event_PropTypeCondition* F();
};
Event_PropTypeCondition* Factory_1aaab0::F() {
    Event_PropTypeCondition* p = (Event_PropTypeCondition*)FUN_0008d690(0x18);
    if (p) {
        p->Event_PropTypeCondition::Event_PropTypeCondition(0);
        *(void**)p = VT_1aaab0;
        p->sub.Init();
        return p;
    }
    return 0;
}
