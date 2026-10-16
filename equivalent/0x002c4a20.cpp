// STATUS: equivalent (tools/equiv.py level 3: 30 inputs, branch coverage 8/8)
// FUN_002c4a20 @ 0x002c4a20
#include "decls/address.h"
struct Vec3_2c4a20 {
    float x, y, z;
};

class Renderer_2c4a20 {
public:
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int arg);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int a, int b);
};

class Mesh_2c4a20 {
public:
    char pad0[8];
    Vec3_2c4a20 *vtx;
    char pad1[4];
    unsigned *color;
    void FUN_0008ef00();
};

class Gfx {
public:
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Mesh_2c4a20 *v30(int a, int b, int c, int d, int e);
    virtual void v31(Mesh_2c4a20 *m);
};

extern Renderer_2c4a20 **DAT_0052c2ac;
void __cdecl FUN_00356bf0(void *a1, float a, float b, float *x, float *y, float *z);

struct Frame_2c4a20 {
    float v10;
    float stepX;
    Vec3_2c4a20 V;
    Vec3_2c4a20 V2;
};

void FUN_002c4a20(void *a1, int a2, int a3, unsigned color, float nx, float ny)
{
    Frame_2c4a20 fr;
    (*DAT_0052c2ac)->v23(0, a2);
    Mesh_2c4a20 *m = DAT_0052c2a8->v30(a3, 2, 0x2020, (int)((nx + 1.0f) * (ny + 1.0f) * 4.0f), 0);
    FUN_00356bf0(a1, 0.0f, 0.0f, &fr.V.x, &fr.V.y, &fr.V.z);
    fr.stepX = 3.14159274f / nx;
    fr.v10 = 0.0f;
    ny = 3.14159274f / ny;
    do {
        float outer = fr.v10;
        nx = 0.0f;
        do {
            fr.V2 = fr.V;
            FUN_00356bf0(a1, outer, nx, &fr.V.x, &fr.V.y, &fr.V.z);
            Vec3_2c4a20 *p = m->vtx;
            p->x = fr.V2.x;
            p->z = fr.V2.z;
            p->y = fr.V2.y;
            *m->color = color;
            m->FUN_0008ef00();
            p = m->vtx;
            p->x = fr.V.x;
            p->y = fr.V.y;
            p->z = fr.V.z;
            *m->color = color;
            m->FUN_0008ef00();
            nx = fr.stepX + nx;
        } while (nx <= 3.14159274f);
        fr.v10 = ny + fr.v10;
    } while (fr.v10 <= 3.14159274f);

    FUN_00356bf0(a1, 0.0f, 0.0f, &fr.V.x, &fr.V.y, &fr.V.z);
    nx = 0.0f;
    do {
        float outer = nx;
        fr.v10 = 0.0f;
        do {
            fr.V2 = fr.V;
            FUN_00356bf0(a1, fr.v10, outer, &fr.V.x, &fr.V.y, &fr.V.z);
            Vec3_2c4a20 *p = m->vtx;
            p->x = fr.V2.x;
            p->z = fr.V2.z;
            p->y = fr.V2.y;
            *m->color = color;
            m->FUN_0008ef00();
            p = m->vtx;
            p->x = fr.V.x;
            p->y = fr.V.y;
            p->z = fr.V.z;
            *m->color = color;
            m->FUN_0008ef00();
            fr.v10 = fr.stepX + fr.v10;
        } while (fr.v10 <= 3.14159274f);
        nx = ny + nx;
    } while (nx <= 3.14159274f);

    DAT_0052c2a8->v31(m);
    (*DAT_0052c2ac)->v16(0);
}
