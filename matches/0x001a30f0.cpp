extern void* g_vt_1a30f0[];
struct Sub_1a30f0 {
    void Fin() throw();
};
class Base_1a30f0 {
  public:
    void* vptr;
    ~Base_1a30f0() throw();
};
class A_1a30f0 : public Base_1a30f0 {
  public:
    char pad[0x10 - 4];
    Sub_1a30f0 sub;
    ~A_1a30f0() throw();
};
A_1a30f0::~A_1a30f0() throw() {
    vptr = g_vt_1a30f0;
    sub.Fin();
}
