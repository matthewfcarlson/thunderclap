extern "C" char DAT_00414130[];
class Sub {
  public:
    void InitSub();
};
class CollisionSourceNodeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char p4[8];
    int fieldC;
    Sub* unused;
    char p14[8];
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
CollisionSourceNodeCondition* FactoryVfunc5() {
    CollisionSourceNodeCondition* p = (CollisionSourceNodeCondition*)Alloc(0x20);
    if (p) {
        p->Init(0);
        *(unsigned long*)p = ((int)DAT_00414130);
        p->fieldC = 0;
        ((Sub*)((char*)p + 0x10))->InitSub();
        *((char*)p + 0x1c) = 0;
        return p;
    }
    return 0;
}