extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f();
    virtual void release();
};
class Obj {
  public:
    void reset();
    void init();
    int pad0;
    Ref* a;
    int pad8;
    Ref* b;
    int c;
    Ref* d;
    Ref* e;
};
void Obj::reset() {
    init();
    if (e) {
        e->release();
        e = 0;
    }
    if (d) {
        d->release();
        d = 0;
    }
    c = 0;
    _ReadWriteBarrier();
    if (b) {
        b->release();
        b = 0;
    }
    if (a) {
        a->release();
        a = 0;
    }
}