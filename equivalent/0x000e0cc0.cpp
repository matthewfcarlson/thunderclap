// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_000e0cc0 @ 0x000e0cc0
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vertices {
    void FUN_0008ef00();
    char pad0[8];
    float *pos;
    char pad1[4];
    unsigned int *color;
};
struct Surface_e0cc0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6(unsigned int tag, int flag);
};
struct Factory_e0cc0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual Surface_e0cc0 *vfn11(const char *name, int flag);
};
struct Gfx {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Vertices *vfn30(Surface_e0cc0 *s, int a, int b, int c, int d);
    virtual void vfn31(Vertices *v);
};


void FUN_000e0cc0(float w, float h, int unused, unsigned int color, int a4)
{
    if ((*(Surface_e0cc0**)&DAT_004de954) == 0) {
        (*(Surface_e0cc0**)&DAT_004de954) = (*(Factory_e0cc0**)&DAT_0052c2a0)->vfn11("simple", 0);
        (*(Surface_e0cc0**)&DAT_004de954)->vfn0();
        (*(Surface_e0cc0**)&DAT_004de954)->vfn6(0x444d4c42, 1);
    }
    float x0 = w * -0.5f;
    float y1 = h * 0.5f;
    float x1 = w * 0.5f;
    float y0 = h * -0.5f;
    float xs[6];
    float ys[6];
    xs[0] = x0; ys[0] = y0;
    xs[1] = x0; ys[1] = y1;
    xs[2] = x1; ys[2] = y1;
    xs[3] = x0; ys[3] = y0;
    xs[4] = x1; ys[4] = y1;
    xs[5] = x1; ys[5] = y0;
    Vertices *v = DAT_0052c2a8->vfn30((*(Surface_e0cc0**)&DAT_004de954), a4, 0x2020, 6, 0);
    if (v) {
        for (int i = 0; i < 6; i++) {
            float *p = v->pos;
            p[0] = xs[i];
            p[1] = ys[i];
            p[2] = 0.0f;
            unsigned int *c = v->color;
            *c = color;
            v->FUN_0008ef00();
        }
    }
    DAT_0052c2a8->vfn31(v);
}
