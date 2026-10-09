class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
class GroundCondition {
  public:
    void Init(int);
};
extern "C" void* Alloc(unsigned int);
void* ConditionFactoryTemplate::V5() {
    GroundCondition* p = (GroundCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = 0x3f6f5c;
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}