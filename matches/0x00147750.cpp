extern void* g_vt_147750[];
struct Sub_147750 {
    void Fin() throw();
};
class Base_147750 {
  public:
    void* vptr;
    ~Base_147750() throw();
};
class A_147750 : public Base_147750 {
  public:
    char pad[0x20 - 4];
    Sub_147750 sub;
    ~A_147750() throw();
};
A_147750::~A_147750() throw() {
    vptr = g_vt_147750;
    sub.Fin();
}
