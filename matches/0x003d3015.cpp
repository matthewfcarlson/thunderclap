extern void* g_a_3d3015[];
extern void* g_b_3d3015[];
extern void* g_c_3d3015[];
struct Sub_3d3015 {
    void Fin() throw();
};
class A_3d3015 {
  public:
    void* vptr0;
    void* vptr4;
    char pad[4];
    Sub_3d3015 sub;
    ~A_3d3015() throw();
};
A_3d3015::~A_3d3015() throw() {
    vptr0 = g_a_3d3015;
    vptr4 = g_b_3d3015;
    sub.Fin();
    vptr4 = g_c_3d3015;
}
