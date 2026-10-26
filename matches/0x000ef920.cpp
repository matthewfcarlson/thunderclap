#include "decls/data/game/global.h"
// data: g_ref_ef920 = DAT_004de954

extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ef920[];
extern void* g_vftable2[];
class Ref_ef920 {
  public:
    virtual void F0();
    virtual void Release();
};
class Del_ef920 {
  public:
    virtual void D(int);
};
void Free(void*) throw();
struct A_ef920 {
    void Fin() throw();
};
struct B_ef920 {
    void Fin() throw();
};
class FEThingsBase_ef920 {
  public:
    void* vptr;
    A_ef920* m4;
    B_ef920* m8;
    Del_ef920* a[64];
    char pp20c[256];
    Del_ef920* b[256];
    Del_ef920* c[1024];
    void* d[64];
    char pp17fc[240];
    Ref_ef920* m17fc;
    char pp1818[24];
    Ref_ef920* m1818;
    char pp1854[56];
    Ref_ef920* e[2];
    char pp1a5c[512];
    Ref_ef920* f[2];
    char pp1c64[512];
    Ref_ef920* g[2];
    Ref_ef920* h[2];
    char pp2078[1028];
    void* hvptr;
    char pp2080[4];
    Del_ef920* ii[32];
    ~FEThingsBase_ef920() throw();
};
FEThingsBase_ef920::~FEThingsBase_ef920() throw() {
    vptr = g_vftable_ef920;
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
        A_ef920* t = m4;
        if (t) {
            t->Fin();
            Free(t);
            m4 = 0;
        }
    }
    {
        B_ef920* t = m8;
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
    if ((*(Ref_ef920**)&DAT_004de954)) {
        (*(Ref_ef920**)&DAT_004de954)->Release();
        (*(Ref_ef920**)&DAT_004de954) = 0;
    }
    hvptr = g_vftable2;
    for (int j = 0; j < 32; j++)
        if (ii[j]) {
            ii[j]->D(1);
            ii[j] = 0;
        }
}
