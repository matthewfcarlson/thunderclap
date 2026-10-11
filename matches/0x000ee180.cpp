class ImageSelector {
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
    virtual void vfunc_19(int, int, int, int, char);
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    char pad[0x2a4 - 4];
    void Update();
};
extern void FUN_000c8710(void*, int);
void ImageSelector::vfunc_19(int p2, int p3, int p4, int p5, char p6) {
    if (p2 && p3 >= 0 && p3 < 8 && p4 >= 0 && p4 < 8) {
        FUN_000c8710((char*)this + 0x150 + (p4 + p3 * 8) * 4, p2);
        *((char*)this + 0x250 + p4 + p3 * 8) = (char)p5;
        if (p6) {
            *(int*)((char*)this + 0x2a4) = *(int*)((char*)this + 0x2a8) =
                *(int*)((char*)this + 0x298) * p3 + p4;
            Update();
        }
        ++*(int*)((char*)this + 0x290);
    }
}