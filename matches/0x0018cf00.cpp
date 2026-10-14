extern void* g_vt_18cf00[];
struct Sub_18cf00 {
    void Fin() throw();
};
class Base_18cf00 {
  public:
    void* vptr;
    ~Base_18cf00() throw();
};
class A_18cf00 : public Base_18cf00 {
  public:
    char pad[0x10 - 4];
    Sub_18cf00 sub;
    ~A_18cf00() throw();
};
A_18cf00::~A_18cf00() throw() {
    vptr = g_vt_18cf00;
    sub.Fin();
}
