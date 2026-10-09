namespace pure3d {
struct Obj {
    virtual void f0();
    virtual void f1();
};
class ParticleEmitter {
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
    virtual void vfunc_23(void*);
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    char pad[0x7c];
    Obj* member;
};
void ParticleEmitter::vfunc_23(void* p) {
    if (p)
        ((Obj*)p)->f0();
    if (member)
        member->f1();
    member = (Obj*)p;
}
} // namespace pure3d