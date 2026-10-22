extern void* g_vt_2e5a70[];
extern void* g_b_2e5a70[];
void operator delete(void*);
struct S_2e5a70 {
    void Fini() throw();
};
struct E_2e5a70 {
    char pad[4];
    S_2e5a70 s;
    char pad2[7];
};
struct VE {
    E_2e5a70* b;
    E_2e5a70* e;
    E_2e5a70* c;
    void Fini() throw() {
        if (b) {
            E_2e5a70* p = b;
            E_2e5a70* end = e;
            while (p != end) {
                p->s.Fini();
                p++;
            }
            operator delete(b);
        }
    }
};
struct VP {
    void* b;
    char pad[8];
    void Fini() throw() {
        if (b)
            operator delete(b);
    }
};
class VertexAnimKeyFrame_2e5a70 {
  public:
    void* vptr;
    char pad[0x10];
    void* m14;
    char pad2[8];
    void* m20;
    char pad3[0x2c - 0x24];
    VP a[4];
    VE v[2];
    void f();
};
void VertexAnimKeyFrame_2e5a70::f() {
    vptr = g_vt_2e5a70;
    {
        VE* p = v + 2;
        int n = 2;
        do {
            --p;
            p->Fini();
        } while (--n);
    }
    {
        VP* p = a + 4;
        int n = 4;
        do {
            --p;
            p->Fini();
        } while (--n);
    }
    if (m20)
        operator delete(m20);
    if (m14)
        operator delete(m14);
    vptr = g_b_2e5a70;
}
