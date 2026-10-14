extern void* g_vftable_14db20[];
struct Sub_14db20 {
    void Fin();
};
class Base_14db20 {
  public:
    void* vptr;
    void Fin();
};
class Obj_14db20 : public Base_14db20 {
  public:
    char pad[0xc];
    Sub_14db20 sub;
    void f();
};
void Obj_14db20::f() {
    vptr = g_vftable_14db20;
    sub.Fin();
    Fin();
}
