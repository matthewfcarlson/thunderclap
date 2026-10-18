class Target {
  public:
    int Fn(int, int, int, int);
};
class Obj {
  public:
    Target* volatile p;
};
int __cdecl FUN_0025abd0(Obj* o, int v) {
    Target* t = o->p;
    return t->Fn(v, 4, 1, 1);
}