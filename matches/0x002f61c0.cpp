class PhysicsObject {
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
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    PhysicsObject(unsigned char);
    void finish();
};
struct A_2f61c0 {
    void a();
};
struct B_2f61c0 {
    void b();
};
struct C_2f61c0 {
    void c();
};
struct D {
    void d();
};
struct E_2f61c0 {
    void e();
};
extern void destroy(PhysicsObject*);
PhysicsObject::PhysicsObject(unsigned char flag) {
    ((A_2f61c0*)((char*)this + 0x168))->a();
    ((B_2f61c0*)((char*)this + 0x114))->b();
    ((C_2f61c0*)((char*)this + 0xf8))->c();
    ((D*)((char*)this + 0xdc))->d();
    ((E_2f61c0*)((char*)this + 0x30))->e();
    finish();
    if (flag & 1)
        destroy(this);
}