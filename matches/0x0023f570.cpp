class Base_23f570 {
  public:
    void init();
};
class Sub_23f570 {
  public:
    void init2();
};
struct Obj_23f570 {
    int vf;
    int a;
    int b;
    int c;
};
extern int breakpoint_vftable;
extern "C" void* __cdecl alloc(unsigned int);

class Factory_23f570 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    Obj_23f570* make();
};

Obj_23f570* Factory_23f570::make() {
    Obj_23f570* p = (Obj_23f570*)alloc(0x14);
    if (p) {
        ((Base_23f570*)p)->init();
        p->vf = (int)&breakpoint_vftable;
        p->c = 0;
        ((Sub_23f570*)((char*)p + 0x10))->init2();
        p->b = 1;
        return p;
    }
    return 0;
}
