struct Sub_292a50 {
    void h(void*, void*);
};
class Camera {
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
    virtual void f16(void*, void*);
    virtual void f17();
    virtual void vfunc_18(void*, void*);
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    char pad[0x48];
    Sub_292a50 sub;
    char pad2[0x7f];
    unsigned char flag;
};
void Camera::vfunc_18(void* a, void* b) {
    char local[12];
    if (!flag)
        f26();
    sub.h(a, local);
    f16(local, b);
}