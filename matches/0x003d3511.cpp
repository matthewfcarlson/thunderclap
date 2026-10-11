// cl-flags: /O1
extern void* g_a[];
extern void* g_b[];
extern void* g_c[];
void __stdcall Free(void*) throw();
void __stdcall Free2(void*) throw();
struct Rec {
    char p[0x10];
    void* r;
    char q[0x1c];
};
struct Sub {
    void Fin() throw();
};
class A {
  public:
    void* vptr0;
    void* vptr4;
    char pad[4];
    Sub sub;
    char pad2[0x1c - 0x10];
    unsigned m1c;
    char pad3[0x40 - 0x20];
    Rec* m40;
    ~A() throw();
};
void __stdcall Pre(A* a) throw();
A::~A() throw() {
    vptr0 = g_a;
    vptr4 = g_b;
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
    vptr4 = g_c;
}
