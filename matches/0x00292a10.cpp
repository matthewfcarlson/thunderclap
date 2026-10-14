class Inner_292a10 {
  public:
    void work(int, void*);
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
    virtual void f15(void*);
    virtual void f16();
    virtual void f17(int);
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    char pad[0xcc - 4];
    unsigned char flag;
};
void Camera::f17(int arg) {
    char t[12];
    if (!flag)
        f26();
    ((Inner_292a10*)((char*)this + 0x4c))->work(arg, t);
    f15(t);
}