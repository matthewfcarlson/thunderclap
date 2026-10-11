extern void* g_a[];
extern void* g_b[];
struct Sub {
    void Fin();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x14];
    Sub sub;
    void f();
};
void Obj::f() {
    vptr = g_a;
    sub.Fin();
    vptr = g_b;
    Fin();
}
