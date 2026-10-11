extern "C" char DAT_003f742c[];
extern "C" void* __cdecl Alloc(unsigned int);
class CRageModeCondition {
  public:
    void Init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    CRageModeCondition* p = (CRageModeCondition*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_003f742c);
        *((char*)p + 0xc) = 1;
        return p;
    }
    return (void*)0;
}