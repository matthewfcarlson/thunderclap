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
struct This_helper {
    void helper(void*, void*);
};
void C_1fa610::target() {
    ((This_helper*)this)->helper((void*)cb, this);
    p->f1();
}
