extern "C" char DAT_00414150[];
extern "C" void* __cdecl Alloc(unsigned int);
class CollisionChargeCondition {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    char pad[8];
    int a;
    int b;
    char c;
    void Init(int);
};
class Factory {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual CollisionChargeCondition* V5();
};
CollisionChargeCondition* Factory::V5() {
    CollisionChargeCondition* p = (CollisionChargeCondition*)Alloc(0x18);
    if (p) {
        p->Init(0);
        *(unsigned long*)p = ((int)DAT_00414150);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        return p;
    }
    return 0;
}