class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
extern "C" void* __cdecl Alloc(unsigned int);
struct DebugPrintCondition {
    unsigned int vptr;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
void* ConditionFactoryTemplate::V5() {
    DebugPrintCondition* p = (DebugPrintCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = 0x411284;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return 0;
}