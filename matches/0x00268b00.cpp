namespace core {
class ControllerXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void* vfunc_6();
    char pad[0x444];
};
void* ControllerXBox::vfunc_6() {
    return (char*)this + 0x448;
}
} // namespace core