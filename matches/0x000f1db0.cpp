extern "C" void _ReadWriteBarrier();
extern "C" void* __cdecl Alloc(unsigned int) throw();
struct ButtonBase {
    ButtonBase(int) throw();
    virtual void g();
    char pad[0x14c];
};
struct TextButton : public ButtonBase {
    TextButton(int a) throw();
    virtual void g();
    int a, b, c;
    void* operator new(unsigned int) throw() { return Alloc(0x160); }
};
TextButton::TextButton(int x) throw() : ButtonBase(x) {
    _ReadWriteBarrier();
    a = -1;
    b = -1;
    c = 0xff000000;
}
class FEThingsBase {
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
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual TextButton* f52(int);
};
TextButton* FEThingsBase::f52(int arg) {
    return new TextButton(arg);
}
