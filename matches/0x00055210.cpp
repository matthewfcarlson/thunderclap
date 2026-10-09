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
class ParamValueStringList : public ParamValue {
  public:
    int f1();
};
int ParamValueStringList::f1() {
    return 4;
}