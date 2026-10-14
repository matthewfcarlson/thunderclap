extern "C" char DAT_0040fd94[];
extern void* __cdecl Alloc(unsigned int);
class InitObj_12a4c0 {
  public:
    void Init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void* Make();
};
void* ConditionFactoryTemplate::Make() {
    void* p = Alloc(0x14);
    if (p) {
        ((InitObj_12a4c0*)p)->Init(0);
        *(unsigned int*)p = ((int)DAT_0040fd94);
        *(unsigned int*)((char*)p + 0x0c) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}