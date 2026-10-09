namespace pure3d {
class pddiBaseContext {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual int vfunc_11();
    char pad[0x48 - 4];
};
int pddiBaseContext::vfunc_11() {
    return *(int*)(*(int*)((char*)this + 0x48) + 0xc);
}
} // namespace pure3d