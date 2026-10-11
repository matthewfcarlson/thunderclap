class Base {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class WaypointCondition : public Base {
  public:
    void Init(int);
    char pad[8];
    int m0;
    int m1;
};
extern char VT[];
extern void* __cdecl Allocate(unsigned int);
class ConditionFactoryTemplate : public Base {
  public:
    virtual void A2();
    virtual void B2();
    virtual void C2();
    virtual void D2();
    virtual void E2();
    virtual WaypointCondition* Make();
};
WaypointCondition* ConditionFactoryTemplate::Make() {
    WaypointCondition* p = (WaypointCondition*)Allocate(0x14);
    if (p) {
        p->Init(0);
        *(void**)p = VT;
        p->m0 = 0;
        p->m1 = -1;
        return p;
    }
    return 0;
}