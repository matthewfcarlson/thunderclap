extern void* g_vftable[];
struct Sub { void Fin(); };
class Base { public: void* vptr; void Fin(); };
class Obj : public Base {
  public:
    char pad[0xc];
    Sub sub;
    void f();
};
void Obj::f() {
    vptr = g_vftable;
    sub.Fin();
    Fin();
}
