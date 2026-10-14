class Obj_283340 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
class Hlp {
  public:
    void FUN_00280160();
    void FUN_00280800();
};
class Holder_283340 {
  public:
    char p0[0x20];
    Obj_283340* b;
    char p1[8];
    Obj_283340* a;
    char p2[0x24];
    Obj_283340* c;
};
class C_283340 {
  public:
    char p0[0x0c];
    Hlp* x;
    Hlp* y;
    Holder_283340* h;
    Obj_283340* z;
    void run();
};
void C_283340::run() {
    x->FUN_00280160();
    y->FUN_00280800();
    Holder_283340* s = h;
    if (s->a) {
        s->a->f1();
        s->a = 0;
    }
    if (s->b) {
        s->b->f1();
        s->b = 0;
    }
    if (s->c) {
        s->c->f1();
        s->c = 0;
    }
    z->f9();
}