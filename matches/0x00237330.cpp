extern void* g_vA[];
struct SubA {
    void* v;
    void Fin() throw();
};
struct SubB {
    void* v;
    void Fin() throw();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x18 - 4];
    SubB b;
    char pad2[0x28 - 0x1c];
    SubA a;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vA;
    a.Fin();
    b.Fin();
    Fin();
}
