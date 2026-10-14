extern "C" char DAT_003f72e0[];
class AllocObj_57fc0 {
  public:
    void Init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
void* ConditionFactoryTemplate::V5() {
    AllocObj_57fc0* p = (AllocObj_57fc0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((int)DAT_003f72e0);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}