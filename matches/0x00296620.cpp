class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int, int);
};
class BranchNode {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void vfunc_8(int, int, int);
    char pad[0x10 - 4];
    unsigned int flags;
    char pad2[4];
    unsigned int count;
    Obj** items;
};
void BranchNode::vfunc_8(int a, int b, int c) {
    if ((flags & 1) == 0) {
        for (unsigned int i = 0; i < count; ++i)
            items[i]->f8(a, b, c);
        flags &= 0xfffffff9;
    }
}