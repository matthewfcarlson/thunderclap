extern void* g_vt_1a2e00[];
struct Sub_1a2e00 {
    void Fin() throw();
};
class Base_1a2e00 {
  public:
    void* vptr;
    ~Base_1a2e00() throw();
};
class A_1a2e00 : public Base_1a2e00 {
  public:
    char pad[0x10 - 4];
    Sub_1a2e00 sub;
    ~A_1a2e00() throw();
};
A_1a2e00::~A_1a2e00() throw() {
    vptr = g_vt_1a2e00;
    sub.Fin();
}
