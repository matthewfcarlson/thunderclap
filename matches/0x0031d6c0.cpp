namespace pure3d {
class pddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiRenderContext : public pddiObject {};
struct Block {
    unsigned long x[16];
};
class pddiBaseContext : public pddiRenderContext {
  public:
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void vfunc_19(const Block*);
    char pad[0x58];
};
void pddiBaseContext::vfunc_19(const Block* p) {
    *(Block*)((char*)this + 0x5c) = *p;
}
} // namespace pure3d