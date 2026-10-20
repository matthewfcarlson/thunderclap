// Same code shape as 0x00267bb0 (propagated; names are from that function)
class ControllerBuffer_270670 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    int mRefCount;
};
void ControllerBuffer_270670::f1() {
    if (--mRefCount == 0)
        f2(1);
}