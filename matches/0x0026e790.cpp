struct Target {
    void f(int*, int);
};
namespace core {
class DebugConsole {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5();
    char pad[0xa0];
    Target* ptr;
};
} // namespace core
void core::DebugConsole::vfunc_5() {
    int a[2];
    a[1] = (int)this;
    a[0] = 3;
    ptr->f(a, 8);
}