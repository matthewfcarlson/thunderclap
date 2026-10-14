class FELayout {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[0x18];
};
class Helper_e2160 {
  public:
    void call(int);
};
class SingleLayout : public FELayout {
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
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual int vfunc_14(int, int);
};
int SingleLayout::vfunc_14(int a, int b) {
    ((Helper_e2160*)((char*)this + 0x18))->call(a);
    return a;
}