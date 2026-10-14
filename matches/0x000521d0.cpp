// Same code shape as 0x00052010 (propagated; names are from that function)
class CFightNodeCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int vfunc_7(void*);
};
class Helper_521d0 {
  public:
    int first();
    int second();
};
int CFightNodeCondition::vfunc_7(void* arg) {
    int x = ((Helper_521d0*)arg)->first();
    return ((Helper_521d0*)x)->second() + 0xdc;
}