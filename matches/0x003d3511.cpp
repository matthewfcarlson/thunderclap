// cl-flags: /O1
extern void* g_a_3d3511[];
extern void* g_b_3d3511[];
extern void* g_c_3d3511[];
void __stdcall Free(void*) throw();
void __stdcall Free2(void*) throw();
struct Rec_3d3511 {
    char p[0x10];
    void* r;
    char q[0x1c];
};
struct Sub_3d3511 {
    void Fin() throw();
};
class A_3d3511 {
  public:
    void* vptr0;
    void* vptr4;
    char pad[4];
    Sub_3d3511 sub;
    char pad2[0x1c - 0x10];
    unsigned m1c;
    char pad3[0x40 - 0x20];
    Rec_3d3511* m40;
    ~A_3d3511() throw();
};
void __stdcall Pre(A_3d3511* a) throw();
A_3d3511::~A_3d3511() throw() {
    vptr0 = g_a_3d3511;
    vptr4 = g_b_3d3511;
    Pre(this);
    if (m40) {
        for (unsigned i = 0; i < m1c; i++) {
            void* r = m40[i].r;
            if (r)
                Free2(r);
        }
        if (m40) {
            Free(m40);
            m40 = 0;
        }
    }
    sub.Fin();
    vptr4 = g_c_3d3511;
}
