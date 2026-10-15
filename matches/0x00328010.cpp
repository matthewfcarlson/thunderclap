class Obj {
  public:
    Obj* Init(int x);
};
Obj* Alloc(int n);
Obj* FUN_00328010(int x) {
    Obj* r = Alloc(0xdc);
    if (r)
        return r->Init(x);
    return 0;
}
