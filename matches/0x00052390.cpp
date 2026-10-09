class CGrappleFightNodeParentCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init();
};
extern "C" void* FUN_0008d690(unsigned int);
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CGrappleFightNodeParentCondition* vfunc_5();
};
CGrappleFightNodeParentCondition* Factory::vfunc_5() {
    CGrappleFightNodeParentCondition* p = (CGrappleFightNodeParentCondition*)FUN_0008d690(0x20);
    if (p) {
        p->Init();
        *(int*)p = 0x3f85c4;
        return p;
    }
    return 0;
}