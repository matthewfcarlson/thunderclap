extern void* g_vftable_1471c0[];
struct Sub_1471c0 {
    void Fin();
};
class Base_1471c0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1471c0 : public Base_1471c0 {
  public:
    char pad[0xc];
    Sub_1471c0 sub;
    void f();
};
void Obj_1471c0::f() {
    vptr = g_vftable_1471c0;
    sub.Fin();
    Fin();
}
