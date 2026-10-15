class Receiver {
  public:
    void notify(int);
};
class ImageSelector {
  public:
    virtual void changed();
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
    virtual void vfunc_22(int);
    virtual void f23();
    char pad[0x14c];
    void* images[0x51];
    int rows;
    int cols;
    char pad2[0xc];
    int selected;
    Receiver* receiver;
};
void ImageSelector::vfunc_22(int n) {
    if (n >= 0 && n < rows * cols && images[n % cols + (n / cols) * 8]) {
        selected = n;
        if (receiver)
            receiver->notify(n);
        changed();
    }
}