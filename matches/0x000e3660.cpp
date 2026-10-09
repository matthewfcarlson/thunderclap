class FEControl {
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
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
};
class FEObject {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
};
class IValueChangedReceiver {
  public:
    virtual void h0();
};
class IValueChangedSender {
  public:
    virtual void i0();
};
class TextSelector : public FEControl,
                     public FEObject,
                     public IValueChangedReceiver,
                     public IValueChangedSender {
  public:
    char pad[0x1d50];
    float value;
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float vfunc_9();
};
float TextSelector::vfunc_9() {
    return value;
}