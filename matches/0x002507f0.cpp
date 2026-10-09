class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(int);
    virtual void f5();
};
class H {
  public:
    void FUN_00262020();
};
class SeqEventWaitBeat : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventWaitBeat* f4(int);
    void FUN_0025fd10();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
extern char g_4e6a68[1];
SeqEventWaitBeat* SeqEventWaitBeat::f4(int x) {
    H* h = (H*)((char*)this + 8);
    h->FUN_00262020();
    FUN_0025fd10();
    if (x & 1)
        FUN_00247550(g_4e6a68, this);
    return this;
}