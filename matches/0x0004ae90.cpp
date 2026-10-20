// Same code shape as 0x00049cc0 (propagated; names are from that function)
class Obj_4ae90 {
  public:
    Obj_4ae90* a();
    Obj_4ae90* b();
    int c();
};
int __stdcall vfunc_7(Obj_4ae90* p) {
    p = p->a();
    p = p->b();
    return p->c();
}
