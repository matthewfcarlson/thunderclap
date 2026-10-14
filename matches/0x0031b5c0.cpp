extern int vtD_31b5c0;
extern int vtP;
class D {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual D* f3(unsigned char);
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
    int pad0[3];
    int x10;
    char pad[0x484];
    int x498;
};
void __stdcall D3DDevice_Release();
void __stdcall D3DResource_Release(int);
class Helper_31b5c0 {
  public:
    void Run();
};
void thunk_FUN_00267090(D*);
D* D::f3(unsigned char flag) {
    *(int*)this = (int)&vtD_31b5c0;
    if (x10)
        D3DDevice_Release();
    if (x498)
        D3DResource_Release(x498);
    *(int*)this = (int)&vtP;
    ((Helper_31b5c0*)this)->Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}
