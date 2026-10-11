extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Controller {
  public:
    virtual void Init();
};
class Arg {
  public:
    int Get(int);
};
void* operator new(unsigned int);
struct Impl {
    Controller* Build(int);
};
class Mgr {
  public:
    void* vptr;
    Controller* controller;
    unsigned char flag;
    Mgr* ctor(Arg* a);
};
Mgr* Mgr::ctor(Arg* a) {
    vptr = g_vftable;
    flag = 1;
    void* p = operator new(0x224);
    Controller* c;
    if (p) {
        c = ((Impl*)p)->Build(a->Get(0));
    } else
        c = 0;
    controller = c;
    c->Init();
    return this;
}
