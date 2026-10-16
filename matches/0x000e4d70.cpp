class Child {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int);
};
class FEContainer {
  public:
    virtual void f0();
    virtual char vfunc_1(int a, int b);
    char pad[0x44];
    Child* child;
    char pad2[0x808];
    int id;
};
char FEContainer::vfunc_1(int a, int b) {
    if ((id == -1 || id == b) && child)
        return child->f5(a, b);
    return 0;
}