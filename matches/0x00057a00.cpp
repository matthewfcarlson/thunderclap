extern "C" char DAT_003f6fec[];
class CCollisionPushbackDirectionCondition {
  public:
    int pad0;
    int pad4;
    int pad8;
    int mA;
    int mB;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class fight_ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5();
    void* vfunc_5();
};
void* fight_ConditionFactoryTemplate::vfunc_5() {
    CCollisionPushbackDirectionCondition* p = (CCollisionPushbackDirectionCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_003f6fec);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0x3fc90fdb;
        return p;
    }
    return (void*)0;
}
