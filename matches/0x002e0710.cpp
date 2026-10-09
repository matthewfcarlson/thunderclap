class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class PrimGroupSkinnedPC {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    void init(PrimGroupSkinnedPC*);
    char pad[0x64];
    Ref* child;
};
extern void* alloc(unsigned int);
void* PrimGroupSkinnedPC::vfunc_4() {
    PrimGroupSkinnedPC* p = (PrimGroupSkinnedPC*)alloc(0x70);
    if (p) {
        p->init(this);
        *(unsigned int*)p = 0x42fc74;
        *(unsigned int*)((char*)p + 0x68) = 0;
        Ref* r = child;
        if (r)
            r->f0();
        Ref* q = *(Ref**)((char*)p + 0x68);
        if (q)
            q->f1();
        *(Ref**)((char*)p + 0x68) = r;
        return p;
    }
    return 0;
}