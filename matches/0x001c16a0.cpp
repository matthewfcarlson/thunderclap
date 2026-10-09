class Target {
    char pad[0xbc];
    int value;

  public:
    void f(void*);
};
class Other {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(void*, int);
};
void Target::f(void* p) {
    if (p)
        ((Other*)p)->j((void*)value, 0);
}