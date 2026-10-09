class Obj {
  public:
    Obj* a();
    Obj* b();
    void c();
};
void __stdcall vfunc_7(Obj* p) {
    p = p->a();
    p = p->b();
    p->c();
}
