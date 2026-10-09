// Same code shape as 0x00049cc0 (propagated; names are from that function)
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
