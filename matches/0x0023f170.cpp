extern void* g_vftable_23f170[];
struct Sub_23f170 {
    void Fin();
};
class Base_23f170 {
  public:
    void* vptr;
    void Fin();
};
class Obj_23f170 : public Base_23f170 {
  public:
    char pad[0xc];
    Sub_23f170 sub;
    void f();
};
void Obj_23f170::f() {
    vptr = g_vftable_23f170;
    sub.Fin();
    Fin();
}
