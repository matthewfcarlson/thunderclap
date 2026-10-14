extern void* g_a_6acf0[];
extern void* g_b_6acf0[];
struct Sub_6acf0 {
    void Fin();
};
class Base_6acf0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_6acf0 : public Base_6acf0 {
  public:
    char pad[0x14];
    Sub_6acf0 sub;
    void f();
};
void Obj_6acf0::f() {
    vptr = g_a_6acf0;
    sub.Fin();
    vptr = g_b_6acf0;
    Fin();
}
