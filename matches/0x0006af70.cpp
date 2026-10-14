extern void* g_vt_6af70[];
extern void* g_vt2[];
struct Sub_6af70 {
    void Fin() throw();
};
class Base_6af70 {
  public:
    void* vptr;
    ~Base_6af70() throw();
};
class A_6af70 : public Base_6af70 {
  public:
    char pad[0x18 - 4];
    Sub_6af70 sub;
    ~A_6af70() throw();
};
A_6af70::~A_6af70() throw() {
    vptr = g_vt_6af70;
    sub.Fin();
    vptr = g_vt2;
}
