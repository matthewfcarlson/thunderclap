extern "C" void* FUN_0008d690(unsigned int);
class CollisionThrowCondition {
  public:
    int vt;
    int a;
    int b;
    unsigned char flag;
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CollisionThrowCondition* vfunc_5();
};
CollisionThrowCondition* Factory::vfunc_5() {
    CollisionThrowCondition* p = (CollisionThrowCondition*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        p->vt = 0x413fb0;
        p->flag = 1;
        return p;
    }
    return 0;
}