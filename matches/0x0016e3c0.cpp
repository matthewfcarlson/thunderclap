class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
    void Init(int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
void* ConditionFactoryTemplate::V5() {
    ConditionFactoryTemplate* p = (ConditionFactoryTemplate*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = 0x4169d8;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}