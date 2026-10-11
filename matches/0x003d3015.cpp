extern void* g_a[];
extern void* g_b[];
extern void* g_c[];
struct Sub {
    void Fin() throw();
};
class A {
  public:
    void* vptr0;
    void* vptr4;
    char pad[4];
    Sub sub;
    ~A() throw();
};
A::~A() throw() {
    vptr0 = g_a;
    vptr4 = g_b;
    sub.Fin();
    vptr4 = g_c;
}
