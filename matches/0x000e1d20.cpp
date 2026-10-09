class FEDoAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[0x10 - 4];
    struct Holder {
        int x;
        void* ptr;
    }* member;
};
class Related {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
};
class FEDoBackScreen : public FEDoAction {
  public:
    char pad2[0x34 - 0x14];
    unsigned char a;
    unsigned char b;
    void vfunc_1();
};
void FEDoBackScreen::vfunc_1() {
    if (a) {
        member->ptr;
        ((Related*)member->ptr)->f23();
        return;
    }
    if (b) {
        ((Related*)member->ptr)->f22();
        return;
    }
    ((Related*)member->ptr)->f21();
}