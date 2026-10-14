// Same code shape as 0x002351a0 (propagated; names are from that function)
class Helper_235250 {
  public:
    void Process(int);
};
class ParamValueBranch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int, int);
    virtual void f4();
    virtual void f5();
    virtual int Query(int);
    virtual void f7();
};
void ParamValueBranch::vfunc_3(int a, int b) {
    int x = Query(a);
    if (x)
        ((Helper_235250*)x)->Process(b);
}