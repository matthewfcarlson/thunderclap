class Object {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Device : public Object {
  public:
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual int vfunc_7(int);
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
};
class Helper {
  public:
    int f(int);
};
extern "C" int __cdecl FUN_0008d690(int);
int Device::vfunc_7(int arg) {
    int result = FUN_0008d690(0x49c);
    if (result)
        return ((Helper*)result)->f(*(int*)((char*)this + 0x10));
    return 0;
}