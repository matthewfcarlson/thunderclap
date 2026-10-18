class Obj {
  public:
    int Fn(int, int, int, int);
};
struct Holder {
    Obj* volatile obj;
};
int __cdecl FUN_0025aad0(Holder* p, int n) {
    Obj* o = p->obj;
    return o->Fn(n, 1, 1, 1);
}