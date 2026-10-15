struct Args {
    int x;
    int y;
};
class Handler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void Run(int, int);
};
class First {
  public:
    void Run(int, int);
};
class Obj {
    char pad[0x70];
    First* a;
    Handler* b;

  public:
    void Run(Args v);
};
void Obj::Run(Args v) {
    if (a)
        a->Run(v.x, v.y);
    if (b)
        b->Run(v.x, v.y);
}