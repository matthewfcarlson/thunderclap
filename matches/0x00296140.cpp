class Scenegraph {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool vfunc_7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x3c];
    Scenegraph* child;
};
bool Scenegraph::vfunc_7() {
    if (child)
        return child->vfunc_7();
    return true;
}