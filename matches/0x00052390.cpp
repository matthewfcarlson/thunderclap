extern "C" char DAT_003f85c4[];
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
class Factory_52390 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CGrappleFightNodeParentCondition* vfunc_5();
};
CGrappleFightNodeParentCondition* Factory_52390::vfunc_5() {
    CGrappleFightNodeParentCondition* p = (CGrappleFightNodeParentCondition*)FUN_0008d690(0x20);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003f85c4);
        return p;
    }
    return 0;
}