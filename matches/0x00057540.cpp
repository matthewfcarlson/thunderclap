class CCharacterSizeCondition {
  public:
    int x;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern "C" void* FUN_0008d690(unsigned int);
extern int g_vtable_57540[];
class Factory_57540 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* Factory_57540::vfunc_5() {
    CCharacterSizeCondition* p = (CCharacterSizeCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = (int)g_vtable_57540;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}