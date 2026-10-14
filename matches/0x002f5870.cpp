extern "C" void _ReadWriteBarrier();
extern const float ZERO_2f5870;
extern const float ONE;
class Elem_2f5870 {
  public:
    void Fn(float);
};
class PhysicsObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7();
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
    char p[0x14];
    int m18;
    char q[0x20];
    float f3c;
    float f40;
    float f44;
    char r[0x94];
};
void PhysicsObject::vfunc_7() {
    if (f3c > ZERO_2f5870) {
        float old = f40;
        ((Elem_2f5870*)((char*)this + 0xdc))
            ->Fn(((f40 = *(float*)((char*)m18 + 0xc) * f3c), (f44 = ONE / f40), f40) / old);
        f39();
        *((char*)this + 0x1c4) = 1;
    } else {
        f40 = 0.0f;
        f44 = 0.0f;
        *((char*)this + 0x1c4) = 1;
    }
}
