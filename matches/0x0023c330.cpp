class Branch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7();
};
namespace fight { class Reference : public Branch {
  public:
    char pad[0x24];
    void vfunc_7();
}; }
struct Helper_23c330 {
    void f(int, int);
};
void fight::Reference::vfunc_7() {
    ((Helper_23c330*)((char*)this + 0x28))->f(0, 0);
    Branch::vfunc_7();
}