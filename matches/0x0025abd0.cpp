class Target {
  public:
    void Fn(int, int, int, int);
};
class Obj {
  public:
    Target* volatile p;
};
void __cdecl FUN_0025abd0(Obj* o, int v) {
    Target* t = o->p;
    t->Fn(v, 4, 1, 1);
}