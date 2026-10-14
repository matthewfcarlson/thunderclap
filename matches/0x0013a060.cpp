extern void* g_vftable_13a060[];
struct Sub_13a060 {
    void Fin();
};
class Base_13a060 {
  public:
    void* vptr;
    void Fin();
};
class Obj_13a060 : public Base_13a060 {
  public:
    char pad[0xc];
    Sub_13a060 sub;
    void f();
};
void Obj_13a060::f() {
    vptr = g_vftable_13a060;
    sub.Fin();
    Fin();
}
