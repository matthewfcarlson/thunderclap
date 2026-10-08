class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Outer { public: char pad[0x10]; Inner* p; };
void __fastcall target(Outer* self) { self->p->f6(); }