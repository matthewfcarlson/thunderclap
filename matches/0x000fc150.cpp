class C_fc150 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern C_fc150* g_fc150;
void target() {
    g_fc150->f5();
}