extern "C" char DAT_0042da6c[];
void* __cdecl alloc(unsigned int);
class VertexAnimController;
class Base {
  public:
    void init(VertexAnimController*);
};
class Helper {
  public:
    virtual void release();
    virtual void destroy();
};
class VertexAnimController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual VertexAnimController* vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    char pad[0x3c];
    Helper* member;
};
VertexAnimController* VertexAnimController::vfunc_4() {
    VertexAnimController* p = (VertexAnimController*)alloc(0x48);
    if (p) {
        ((Base*)p)->init(this);
        *(unsigned int*)p = ((int)DAT_0042da6c);
        p->member = 0;
        Helper* old = member;
        if (old)
            old->release();
        Helper* cur = p->member;
        if (cur)
            cur->destroy();
        p->member = old;
        return p;
    }
    return 0;
}