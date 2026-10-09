class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
class ConditionFactoryTemplate : public Factory {
  public:
    virtual void* f5();
};
class Init {
  public:
    void InitFn(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
void* ConditionFactoryTemplate::f5() {
    void* p = FUN_0008d690(0x14);
    if (p) {
        ((Init*)p)->InitFn(0);
        *(unsigned long*)p = 0x3f7250;
        *(unsigned long*)((char*)p + 0xc) = 2;
        *(unsigned long*)((char*)p + 0x10) = 0;
        return p;
    }
    return (void*)0;
}