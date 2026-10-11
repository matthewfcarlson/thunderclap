extern void* g_vt[];
extern void* g_vt2[];
struct Sub {
    void Init(int a) throw();
};
class A {
  public:
    void* vptr;
    char pad[4];
    Sub sub;
    A(int a) throw();
};
A::A(int a) throw() {
    vptr = g_vt;
    sub.Init(a);
    vptr = g_vt2;
}
