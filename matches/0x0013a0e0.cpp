extern void* g_vt_13a0e0[];
struct Sub_13a0e0 {
    void Fin() throw();
};
class Base_13a0e0 {
  public:
    void* vptr;
    ~Base_13a0e0() throw();
};
class A_13a0e0 : public Base_13a0e0 {
  public:
    char pad[0x10 - 4];
    Sub_13a0e0 sub;
    ~A_13a0e0() throw();
};
A_13a0e0::~A_13a0e0() throw() {
    vptr = g_vt_13a0e0;
    sub.Fin();
}
