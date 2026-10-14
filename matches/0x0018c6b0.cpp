extern "C" char DAT_0041920c[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Sub_18c6b0 {
  public:
    void Init();
};
class PropStateByNameCondition {
  public:
    void Init(int);
    char vptr[4];
    char pad04[8];
    int x;
    int y;
    char pad14[4];
    Sub_18c6b0 sub;
};
class FactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual PropStateByNameCondition* F();
};
PropStateByNameCondition* FactoryTemplate::F() {
    PropStateByNameCondition* p = (PropStateByNameCondition*)FUN_0008d690(0x20);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041920c);
        p->x = -1;
        p->y = 0;
        p->sub.Init();
        return p;
    }
    return 0;
}