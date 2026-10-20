struct Base_262c40 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9();
};
struct HalRadicalAdpcmDecodeStream {
    char pad[4];
    Base_262c40* mStream;
    int vfunc_9();
};
int HalRadicalAdpcmDecodeStream::vfunc_9() {
    return mStream->f9();
}