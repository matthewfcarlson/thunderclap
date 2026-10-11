extern void* g_vt[];
struct SubA {
    void Fin() throw();
};
struct SubB {
    void Fin() throw();
};
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class A : public Base {
  public:
    char pad[0x14 - 4];
    SubB b;
    char pad2[0x24 - 0x14 - 1];
    SubA a;
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    a.Fin();
    b.Fin();
}
