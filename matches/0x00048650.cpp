class Helper_48650 {
  public:
    Helper_48650* first();
    int second();
};
class CAxisCondition {
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
    virtual void f9(int, int);
    char pad[8];
    int index;
    void vfunc_8(int);
};
void CAxisCondition::vfunc_8(int arg) {
    Helper_48650* h = ((Helper_48650*)arg)->first();
    int v = h->second();
    f9(v, v + index * 0x38 + 0x1ff4);
}