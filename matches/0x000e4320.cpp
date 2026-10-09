class ImageSelector {
    char pad0[0x40];
    int a;
    char pad1[0x100];
    int b;

  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(int);
};
void ImageSelector::vfunc_14(int) {
    b = a;
}