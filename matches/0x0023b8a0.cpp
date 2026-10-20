// Same code shape as 0x0023a460 (propagated; names are from that function)
class Delegate_23b8a0 {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual int f24();
};
class DataReader_23b8a0 {
  public:
    char pad[8];
    Delegate_23b8a0* sub;
};
class IFileDataReader_23b8a0 : public DataReader_23b8a0 {
  public:
    int vfunc_3();
};
int IFileDataReader_23b8a0::vfunc_3() {
    return sub->f24();
}