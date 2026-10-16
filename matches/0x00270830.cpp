namespace core {
void external();
class IControllerBuffer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class IRefCount {
  public:
    virtual void f2();
};
class ControllerBuffer : public IControllerBuffer, public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
ControllerBuffer obj;
void ControllerBuffer::f2() {
    external();
}
} // namespace core