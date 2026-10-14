extern "C" void* __cdecl alloc(unsigned int);
extern int vt_18bd00;
class Obj_18bd00 {
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
class Factory_18bd00 {
  public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual Obj_18bd00* vfunc_5();
};
Obj_18bd00* Factory_18bd00::vfunc_5() {
    Obj_18bd00* p = (Obj_18bd00*)alloc(16);
    if (p) {
        p->init(0);
        *(int*)p = (int)&vt_18bd00;
        p->flag = 1;
        return p;
    }
    return 0;
}