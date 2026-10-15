extern "C" void _ReadWriteBarrier();
class Obj {
  public:
    virtual void f0();
    virtual void f1();
};
class Thing {
    char a[0x20];

  public:
    Obj* p;
    char b[0x4c - 0x24];
    Obj* q;
    char c[0x80 - 0x50];
    unsigned char flag;
};
void thunk();
void __stdcall Run(Thing* s) {
    s->flag = 1;
    _ReadWriteBarrier();
    while (s->p)
        thunk();
    s->flag = 0;
    _ReadWriteBarrier();
    s->q->f1();
    s->q = 0;
}