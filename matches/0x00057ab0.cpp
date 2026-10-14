class ConditionFactory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Entity {};
class LoadObject {};
class IRefCount {};
extern int CCollisionPushbackVelocityCondition_vftable;
class CCollisionPushbackVelocityCondition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    int pad[2];
    int a, b, c;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Factory_57ab0 : public ConditionFactory, public Entity, public LoadObject, public IRefCount {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCollisionPushbackVelocityCondition* v5();
};
CCollisionPushbackVelocityCondition* Factory_57ab0::v5() {
    CCollisionPushbackVelocityCondition* p = (CCollisionPushbackVelocityCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        ((int*)p)[0] = (int)&CCollisionPushbackVelocityCondition_vftable;
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}