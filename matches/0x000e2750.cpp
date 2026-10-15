// Same code shape as 0x000e21b0 (propagated; names are from that function)
class FELayout {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class VScroll : public FELayout {
  public:
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual float vfunc_17(int);
    virtual void g18();
    virtual void g19();
    char pad[0x34];
    float value;
};
float VScroll::vfunc_17(int) {
    return value;
}