extern void* g_vt[];
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
    char pad[0x20 - 4];
    Sub sub;
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    sub.Fin();
}
