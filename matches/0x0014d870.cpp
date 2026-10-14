extern void* g_vt_14d870[];
struct Sub_14d870 {
    void Fin() throw();
};
class Base_14d870 {
  public:
    void* vptr;
    ~Base_14d870() throw();
};
class A_14d870 : public Base_14d870 {
  public:
    char pad[0x10 - 4];
    Sub_14d870 sub;
    ~A_14d870() throw();
};
A_14d870::~A_14d870() throw() {
    vptr = g_vt_14d870;
    sub.Fin();
}
