extern "C" void _ReadWriteBarrier();
extern void* g_vftable_b3c90[];
class Controller_b3c90 {
  public:
    virtual void Init();
};
class Arg_b3c90 {
  public:
    int Get(int);
};
void* operator new(unsigned int);
struct Impl_b3c90 {
    Controller_b3c90* Build(int);
};
class Mgr_b3c90 {
  public:
    void* vptr;
    Controller_b3c90* controller;
    unsigned char flag;
    Mgr_b3c90* ctor(Arg_b3c90* a);
};
Mgr_b3c90* Mgr_b3c90::ctor(Arg_b3c90* a) {
    vptr = g_vftable_b3c90;
    flag = 1;
    void* p = operator new(0x224);
    Controller_b3c90* c;
    if (p) {
        c = ((Impl_b3c90*)p)->Build(a->Get(0));
    } else
        c = 0;
    controller = c;
    c->Init();
    return this;
}
