// Same code shape as 0x00048590 (propagated; names are from that function)
class CAxisDownCondition {
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
    virtual bool vfunc_10(int* p, int* out);
};
bool CAxisDownCondition::vfunc_10(int* p, int* out) {
    switch (*p) {
    case 1:
        *out = 0;
        return true;
    case 2:
        *out = p[1];
        return true;
    default:
        return false;
    }
}