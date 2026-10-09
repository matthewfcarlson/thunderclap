struct Base {
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
};
struct HalRadicalAdpcmDecodeStream {
    char pad[4];
    Base* mStream;
    void vfunc_9();
};
void HalRadicalAdpcmDecodeStream::vfunc_9() {
    mStream->f9();
}