typedef unsigned int u32_194d90;
struct Obj_194d90 {
    char pad[0x20];
    Obj_194d90* HelperA();
    Obj_194d90* HelperB();
    void DoWork(int, u32_194d90, u32_194d90);
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
    Obj_194d90* field1c;
    Obj_194d90* field20;
};
unsigned char MissilePunchAction::vfunc_3(int a, int b) {
    if (!field20)
        return 0;
    Obj_194d90* x = field20->HelperA();
    x = x->HelperB();
    Obj_194d90* y = field1c;
    x->DoWork(1, *(u32_194d90*)((char*)y + 0x14), *(u32_194d90*)((char*)y + 0x18));
    return 1;
}