extern void* g_vA[];
struct SubA_237330 {
    void* v;
    void Fin() throw();
};
struct SubB_237330 {
    void* v;
    void Fin() throw();
};
class Base_237330 {
  public:
    void* vptr;
    void Fin();
};
class Obj_237330 : public Base_237330 {
  public:
    char pad[0x18 - 4];
    SubB_237330 b;
    char pad2[0x28 - 0x1c];
    SubA_237330 a;
    ~Obj_237330() throw();
};
Obj_237330::~Obj_237330() throw() {
    vptr = g_vA;
    a.Fin();
    b.Fin();
    Fin();
}
