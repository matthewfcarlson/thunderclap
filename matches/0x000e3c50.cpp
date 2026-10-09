class TextWindow {
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
    virtual void vfunc_14(int);
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    char pad[0x40];
    int value;
    char pad2[0x100];
    int saved;
    char pad3[4];
    TextWindow* other;
};
void TextWindow::vfunc_14(int) {
    int eax = value;
    saved = eax;
    if (other)
        other->value = eax;
}