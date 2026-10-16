#include "gen/pure3d.h"

struct Chunk_2bceb0 {
    int Id();
};
extern int g_vt_2bceb0;
struct BO {
    void InitBase(int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void Init();
    int a;
    int b;
    int c;
    char pad[0x48];
    float f;
};
struct Helper_2bceb0 {
    void Fill(BO*, Chunk_2bceb0*, int);
};
void* operator new(unsigned);

void pure3d::BillboardObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int x) { BO ** out = (BO **)__p0; int * info = (int *)__p1; Chunk_2bceb0 * c = (Chunk_2bceb0 *)__p2;

    if (c->Id() == 0x17006) {
        BO* o = (BO*)operator new(0x60);
        if (o) {
            o->InitBase(1);
            *(int**)o = &g_vt_2bceb0;
            o->f = 1.0f;
        } else {
            o = 0;
        }
        (*(Helper_2bceb0 * *)&this->f_14)->Fill(o, c, x);
        o->Init();
        *out = o;
        info[0] = o->b;
        info[1] = o->c;
    }
}
