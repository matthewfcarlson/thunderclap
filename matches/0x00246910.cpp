class Stream {
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
    virtual void f10();
    virtual void f11();
    virtual void f12(int*);
    virtual void f13();
    virtual void f14();
    virtual int GetPos();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual int Good();
};
struct Wrap {
    char pad[0x1c];
    Stream* stream;
};
bool FUN_00246910(Wrap* w, int* result) {
    int pos = w->stream->GetPos();
    int n = 0;
    w->stream->f12(&n);
    *result = pos - n;
    return w->stream->Good() == 0;
}