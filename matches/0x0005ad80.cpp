extern void* g_a[];
struct S1 {
    void Fin();
};
struct S2 {
    void Fin();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad0[0x14];
    S2 s2;
    char pad[0x28 - 0x19];
    S1 s1;
    void f();
};
void Obj::f() {
    vptr = g_a;
    s1.Fin();
    s2.Fin();
    Fin();
}
