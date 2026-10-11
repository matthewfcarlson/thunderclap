extern "C" char DAT_0040d9a4[];
struct AIFightNodeCondition {
    int v;
};
extern void* __cdecl operator_new(unsigned int);
struct InitObj {
    void InitCondition(int);
};
struct EntityObj {
    void InitEntity();
};
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual AIFightNodeCondition* vfunc_5();
};
AIFightNodeCondition* ConditionFactoryTemplate::vfunc_5() {
    AIFightNodeCondition* p = (AIFightNodeCondition*)operator_new(0x18);
    if (p) {
        ((InitObj*)p)->InitCondition(0);
        *(int*)p = ((int)DAT_0040d9a4);
        ((EntityObj*)((char*)p + 0xc))->InitEntity();
        return p;
    }
    return 0;
}