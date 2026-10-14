extern "C" char DAT_0041c5d0[];
class Base_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern void* __cdecl alloc(unsigned int);
class Obj_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init(int);
};
class Sub_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init();
};
class Factory_1aabf0 : public Base_1aabf0 {
  public:
    void* vfunc_5();
};
void* Factory_1aabf0::vfunc_5() {
    Obj_1aabf0* p = (Obj_1aabf0*)alloc(0x18);
    if (p) {
        p->init(0);
        *((int*)p) = ((int)DAT_0041c5d0);
        ((Sub_1aabf0*)((char*)p + 0x10))->init();
        return p;
    }
    return 0;
}