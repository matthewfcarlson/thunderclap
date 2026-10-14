struct Block_292ba0 {
    int x[16];
};
class Receiver_292ba0 {
  public:
    void call();
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void vfunc_26();
    char pad[0xc8];
    unsigned char flag;
};
void Camera::vfunc_26() {
    Block_292ba0* dst = (Block_292ba0*)((char*)this + 0x4c);
    flag = 1;
    *dst = *(Block_292ba0*)((char*)this + 0x8c);
    ((Receiver_292ba0*)dst)->call();
}