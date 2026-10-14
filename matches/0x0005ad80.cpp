extern void* g_a_5ad80[];
struct S1_5ad80 {
    void Fin();
};
struct S2_5ad80 {
    void Fin();
};
class Base_5ad80 {
  public:
    void* vptr;
    void Fin();
};
class Obj_5ad80 : public Base_5ad80 {
  public:
    char pad0[0x14];
    S2_5ad80 s2;
    char pad[0x28 - 0x19];
    S1_5ad80 s1;
    void f();
};
void Obj_5ad80::f() {
    vptr = g_a_5ad80;
    s1.Fin();
    s2.Fin();
    Fin();
}
