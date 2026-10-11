extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e974[];
class A {
  public:
    virtual void f();
    virtual void g();
};
class B {
  public:
    virtual void f(int);
};
class C {
  public:
    void run();
};
extern void thunk(void*);
class Sprite {
  public:
    void* vt;
    char pad4[16];
    B* b;
    A* a;
    C* p;
    void target();
};
void Sprite::target() {
    vt = (void*)((int)DAT_0042e974);
    a->g();
    if (b)
        b->f(1);
    C* q = p;
    if (q) {
        q->run();
        thunk(q);
    }
    vt = (void*)((int)DAT_003f6098);
}
