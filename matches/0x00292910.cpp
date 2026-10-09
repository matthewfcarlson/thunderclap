struct Entity {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
namespace pure3d {
struct Camera {
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
    virtual void* vfunc_13();
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
    virtual void f26();
    char pad[0xcc - 4];
    unsigned char flag;
};
void* Camera::vfunc_13() {
    if (!flag)
        f26();
    return (char*)this + 0x4c;
}
} // namespace pure3d