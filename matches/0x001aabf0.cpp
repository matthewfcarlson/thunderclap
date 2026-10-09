class Base {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern void* __cdecl alloc(unsigned int);
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init(int);
};
class Sub {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init();
};
class Factory : public Base {
  public:
    void* vfunc_5();
};
void* Factory::vfunc_5() {
    Obj* p = (Obj*)alloc(0x18);
    if (p) {
        p->init(0);
        *((int*)p) = 0x41c5d0;
        ((Sub*)((char*)p + 0x10))->init();
        return p;
    }
    return 0;
}