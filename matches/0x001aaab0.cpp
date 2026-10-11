extern char VT[];
extern void* __cdecl FUN_0008d690(int);
class Sub {
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
    Sub sub;
    Event_PropTypeCondition(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event_PropTypeCondition* F();
};
Event_PropTypeCondition* Factory::F() {
    Event_PropTypeCondition* p = (Event_PropTypeCondition*)FUN_0008d690(0x18);
    if (p) {
        p->Event_PropTypeCondition::Event_PropTypeCondition(0);
        *(void**)p = VT;
        p->sub.Init();
        return p;
    }
    return 0;
}
