struct C { void run(void*, int, float); };
struct B { C* getC(); };
struct A { B* get(); };
class CGrappleLocoStrafe4Action {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    char pad[0x18];
    A* m1c;
    char pad20[4];
    void* m24;
};
void CGrappleLocoStrafe4Action::vfunc_4() {
    if (m24) {
        B* b = m1c->get();
        C* c = b->getC();
        if (c) c->run(m24, 0, -1.0f);
    }
}
