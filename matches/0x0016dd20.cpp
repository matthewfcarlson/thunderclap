extern "C" char DAT_00416878[];
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetCharacterTemplateCondition {
  public:
    void Init(int);
    int a;
    int b;
    int c;
};
void* ConditionFactoryTemplate::vfunc_5() {
    TargetCharacterTemplateCondition* p = (TargetCharacterTemplateCondition*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_00416878);
        *(int*)((char*)p + 0xc) = 0;
        return p;
    }
    return 0;
}