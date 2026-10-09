class Base {
  public:
    void init();
};
class Sub {
  public:
    void init2();
};
struct Obj {
    int vf;
    int a;
    int b;
    int c;
};
extern int breakpoint_vftable;
extern "C" void* __cdecl alloc(unsigned int);

class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    Obj* make();
};

Obj* Factory::make() {
    Obj* p = (Obj*)alloc(0x14);
    if (p) {
        ((Base*)p)->init();
        p->vf = (int)&breakpoint_vftable;
        p->c = 0;
        ((Sub*)((char*)p + 0x10))->init2();
        p->b = 1;
        return p;
    }
    return 0;
}
