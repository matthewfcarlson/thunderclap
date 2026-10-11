class Elem {
  public:
    void Init();
};
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    Elem sub;
};
class SeqEventWait : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventWait* f4(int);
    void Finish();
};
extern void __cdecl FUN_00247550(void*, void*);
extern int g_4e69b0;
SeqEventWait* SeqEventWait::f4(int flags) {
    sub.Init();
    Finish();
    if (flags & 1)
        FUN_00247550(&g_4e69b0, this);
    return this;
}