extern void* g_vt[];
extern void* g_b[];
void operator delete(void*);
struct S {
    void Fini() throw();
};
struct E {
    char pad[4];
    S s;
    char pad2[7];
};
struct VE {
    E* b;
    E* e;
    E* c;
    void Fini() throw() {
        if (b) {
            E* p = b;
            E* end = e;
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
class Obj {
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
void Obj::f() {
    vptr = g_vt;
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
    vptr = g_b;
}
