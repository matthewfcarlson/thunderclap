class ChildA {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
};
class ChildB {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int);
};
class FEContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void vfunc_13(int);
    char pad[0x4c - 4];
    ChildA* a[0x80];
    char pad2[0x44c - 0x4c - 0x200];
    ChildB* b[0x80];
};
void FEContainer::vfunc_13(int x) {
    int i = 0;
    for (; i < 0x80; ++i) {
        if (!a[i])
            break;
        a[i]->f4(x);
    }
    i = 0;
    for (; i < 0x80; ++i) {
        if (!b[i])
            break;
        b[i]->f7(x);
    }
}