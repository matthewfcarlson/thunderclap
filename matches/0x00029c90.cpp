class Obj {
  public:
    void Apply(int);
};
extern "C" __int64 __cdecl Build(int, int, int);
class Owner {
  public:
    Obj* Find(__int64);
    void Run(int, int);
};
void Owner::Run(int a, int b) {
    __int64 v = Build(a, 0, 0);
    Obj* p = Find(v);
    if (p)
        p->Apply(b);
}