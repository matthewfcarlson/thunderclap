class Child {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k(unsigned int);
};
class Owner {
  public:
    char pad[0xC];
    Child* child;
    char pad2[0x120];
    unsigned char flag;
    unsigned int value;
    void target();
};
void Owner::target() {
    if (flag && child) {
        child->k(value);
        flag = 0;
    }
}