extern void* g_a_237c20[];
struct S1_237c20 {
    void Fin();
};
struct S2_237c20 {
    void Fin();
};
class Base_237c20 {
  public:
    void* vptr;
    void Fin();
};
class Obj_237c20 : public Base_237c20 {
  public:
    char pad0[8];
    S2_237c20 s2;
    char pad[0x1c - 0xd];
    S1_237c20 s1;
    void f();
};
void Obj_237c20::f() {
    vptr = g_a_237c20;
    s1.Fin();
    s2.Fin();
    Fin();
}
