extern "C" void _ReadWriteBarrier();
extern void* g_vftable_af310[];
class Controller_af310 {
  public:
    virtual void Init();
};
class Arg_af310 {
  public:
    int Get(int);
};
void* operator new(unsigned int);
struct Impl_af310 {
    Controller_af310* Build(int);
};
class Mgr_af310 {
  public:
    void* vptr;
    Controller_af310* controller;
    unsigned char flag;
    Mgr_af310* ctor(Arg_af310* a);
};
Mgr_af310* Mgr_af310::ctor(Arg_af310* a) {
    vptr = g_vftable_af310;
    void* p = operator new(0xb0);
    Controller_af310* c;
    if (p) {
        c = ((Impl_af310*)p)->Build(a->Get(0));
    } else
        c = 0;
    controller = c;
    c->Init();
    return this;
}
