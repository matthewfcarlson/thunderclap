class Obj {
  public:
    void Do(int, int, int, int);
};
Obj* __cdecl Get(int);
void __cdecl Target(int a, int b, int c) {
    Obj* p = Get(a);
    p->Do(b, c, 1, 1);
}