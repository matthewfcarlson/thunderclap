class Obj {
  public:
    virtual void Fn();
};
class Worker {
  public:
    void Do(unsigned low, unsigned high, Obj* o);
};
class Owner {
    char pad[12];
    Worker* worker;

  public:
    void Run(Obj* o, int n);
};
extern "C" unsigned __int64 __cdecl Calc(int n, int a, int b);
void Owner::Run(Obj* o, int n) {
    unsigned __int64 v = Calc(n, 0, 0);
    Worker* w = worker;
    o->Fn();
    w->Do((unsigned)v, (unsigned)(v >> 32), o);
}