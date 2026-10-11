extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Del {
  public:
    virtual void D(int);
};
void Free(void*) throw();
struct A {
    void Fin() throw();
};
struct B {
    void Fin() throw();
};
extern Ref* g_ref;
class Obj {
  public:
    void* vptr;
    A* m4;
    B* m8;
    Del* a[64];
    char pp20c[256];
    Del* b[256];
    Del* c[1024];
    void* d[64];
    char pp17fc[240];
    Ref* m17fc;
    char pp1818[24];
    Ref* m1818;
    char pp1854[56];
    Ref* e[2];
    char pp1a5c[512];
    Ref* f[2];
    char pp1c64[512];
    Ref* g[2];
    Ref* h[2];
    char pp2078[1028];
    void* hvptr;
    char pp2080[4];
    Del* ii[32];
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    for (int i = 0; i < 64; i++)
        if (a[i]) {
            a[i]->D(1);
            a[i] = 0;
        }
    for (int i = 0; i < 256; i++)
        if (b[i]) {
            b[i]->D(1);
            b[i] = 0;
        }
    for (int i = 0; i < 1024; i++)
        if (c[i]) {
            c[i]->D(1);
            c[i] = 0;
        }
    for (int i = 0; i < 64; i++)
        if (d[i]) {
            Free(d[i]);
            d[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (e[i]) {
            e[i]->Release();
            e[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (f[i]) {
            f[i]->Release();
            f[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (g[i]) {
            g[i]->Release();
            g[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (h[i]) {
            h[i]->Release();
            h[i] = 0;
        }
    {
        A* t = m4;
        if (t) {
            t->Fin();
            Free(t);
            m4 = 0;
        }
    }
    {
        B* t = m8;
        if (t) {
            t->Fin();
            Free(t);
            m8 = 0;
        }
    }
    if (m17fc) {
        m17fc->Release();
        m17fc = 0;
    }
    if (m1818) {
        m1818->Release();
        m1818 = 0;
    }
    if (g_ref) {
        g_ref->Release();
        g_ref = 0;
    }
    hvptr = g_vftable2;
    for (int j = 0; j < 32; j++)
        if (ii[j]) {
            ii[j]->D(1);
            ii[j] = 0;
        }
}
