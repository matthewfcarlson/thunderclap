typedef unsigned int u32;
struct Obj {
    char pad[0x20];
    Obj* HelperA();
    Obj* HelperB();
    void DoWork(int, u32, u32);
};
class MissilePunchAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual unsigned char vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    char pad[0x1c - 4];
    Obj* field1c;
    Obj* field20;
};
unsigned char MissilePunchAction::vfunc_3(int a, int b) {
    if (!field20)
        return 0;
    Obj* x = field20->HelperA();
    x = x->HelperB();
    Obj* y = field1c;
    x->DoWork(1, *(u32*)((char*)y + 0x14), *(u32*)((char*)y + 0x18));
    return 1;
}