extern void* g_vt[];
extern void* g_vt2[];
struct Sub {
    void Fin() throw();
};
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class A : public Base {
  public:
    char pad[0x18 - 4];
    Sub sub;
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    sub.Fin();
    vptr = g_vt2;
}
