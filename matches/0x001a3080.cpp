extern void* g_vftable_1a3080[];
struct Sub_1a3080 {
    void Fin();
};
class Base_1a3080 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1a3080 : public Base_1a3080 {
  public:
    char pad[0xc];
    Sub_1a3080 sub;
    void f();
};
void Obj_1a3080::f() {
    vptr = g_vftable_1a3080;
    sub.Fin();
    Fin();
}
