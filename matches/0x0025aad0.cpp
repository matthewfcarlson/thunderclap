class Obj {
  public:
    void Fn(int, int, int, int);
};
struct Holder {
    Obj* volatile obj;
};
void __cdecl FUN_0025aad0(Holder* p, int n) {
    Obj* o = p->obj;
    o->Fn(n, 1, 1, 1);
}