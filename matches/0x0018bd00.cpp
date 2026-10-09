extern "C" void* __cdecl alloc(unsigned int);
extern int vt;
class Obj {
  public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual void* f();
    char x[8];
    char flag;
    void init(int);
};
class Factory {
  public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual Obj* vfunc_5();
};
Obj* Factory::vfunc_5() {
    Obj* p = (Obj*)alloc(16);
    if (p) {
        p->init(0);
        *(int*)p = (int)&vt;
        p->flag = 1;
        return p;
    }
    return 0;
}