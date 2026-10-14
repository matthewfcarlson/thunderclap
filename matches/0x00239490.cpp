extern void* g_vt_239490[];
struct SubA_239490 {
    void Fin() throw();
};
struct SubB_239490 {
    void Fin() throw();
};
class Base_239490 {
  public:
    void* vptr;
    ~Base_239490() throw();
};
class A_239490 : public Base_239490 {
  public:
    char pad[0x14 - 4];
    SubB_239490 b;
    char pad2[0x24 - 0x14 - 1];
    SubA_239490 a;
    ~A_239490() throw();
};
A_239490::~A_239490() throw() {
    vptr = g_vt_239490;
    a.Fin();
    b.Fin();
}
