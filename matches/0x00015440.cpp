struct C_15440 {
    void run(void*, int, float);
};
struct B_15440 {
    C_15440* getC();
};
struct A_15440 {
    B_15440* get();
};
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
    A_15440* m1c;
    char pad20[4];
    void* m24;
};
void CGrappleLocoStrafe4Action::vfunc_4() {
    if (m24) {
        B_15440* b = m1c->get();
        C_15440* c = b->getC();
        if (c)
            c->run(m24, 0, -1.0f);
    }
}
