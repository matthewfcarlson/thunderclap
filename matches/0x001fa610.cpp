struct V {
    virtual void f0();
    virtual void f1();
};
class C_1fa610 {
  public:
    char pad[0x18];
    V* p;
    void target();
};
void cb();
void __stdcall helper(void*, void*);
void C_1fa610::target() {
    helper((void*)cb, this);
    p->f1();
}
