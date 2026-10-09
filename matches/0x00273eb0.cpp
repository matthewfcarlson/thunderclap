// Same code shape as 0x0004f880 (propagated; names are from that function)
class ParamValue {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class ParamValueString : public ParamValue {
  public:
    virtual void f0();
    virtual int f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
int ParamValueString::f1() {
    return 3;
}