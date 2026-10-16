// STATUS: equivalent (tools/equiv.py level 3: 295 inputs, branch coverage 10/10)
// FUN_002b4210 @ 0x002b4210
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
union FI_2b4210 {
    float f;
    int i;
};
struct V3_2b4210 {
    float x, y, z;
    void FUN_0022d180();
};
struct Edge16_2b4210 {
    short a, b;
};
struct Vi {
    int x, y, z;
};
struct Builder {
    char pad00[8];
    FI_2b4210 *pos;
    char pad0c[4];
    int *color;
    void FUN_0008ef00();
};
class Layer_2b4210 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20(unsigned int tag, int color);
};
class Gfx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual Builder *v78(Layer_2b4210 *layer, int b, int c, int d, int e);
    virtual void v7c(Builder *b);
};
struct Holder_2b4210 {
    char pad00[0x10];
    Layer_2b4210 *layer;
};

struct Geom_2b4210 {
    char pad00[0x10];
    V3_2b4210 *verts;
};
class Shadow {
public:
    char pad00[0x48];
    Geom_2b4210 *geom;
    float scale;
    char pad50[4];
    char pointLight;
    char pad55[3];
    V3_2b4210 light;
    void FUN_002b4210();
};

void Shadow::FUN_002b4210()
{
    Builder *b = DAT_0052c2a8->v78((*(Holder_2b4210**)&DAT_00554bb4)->layer, 0, 0x2020, (*(unsigned int*)&DAT_0052cba8) * 6, 0);
    (*(Holder_2b4210**)&DAT_00554bb4)->layer->v20(0x46464944, DAT_004d06dc);
    V3_2b4210 *verts = geom->verts;
    if (!pointLight) {
        V3_2b4210 O;
        float s = scale;
        O.x = s * light.x;
        O.y = s * light.y;
        O.z = s * light.z;
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cba8); i++) {
            V3_2b4210 *A = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].a];
            V3_2b4210 *B = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].b];
            int Az = ((Vi *)A)->z;
            float Ax = A->x;
            float Ay = A->y;
            Vi Bc = *(Vi *)B;
            FI_2b4210 A2[3];
            A2[0].f = O.x + A->x;
            A2[1].f = O.y + A->y;
            A2[2].f = O.z + A->z;
            FI_2b4210 B2[3];
            B2[0].f = O.x + B->x;
            B2[1].f = O.y + B->y;
            B2[2].f = O.z + B->z;
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[2].i = Az;
                p[0].f = Ax;
                p[1].f = Ay;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = B2[0].i;
                p[1].i = B2[1].i;
                p[2].i = B2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
        }
    } else {
        V3_2b4210 L = light;
        for (unsigned short i = 0; i < (*(unsigned int*)&DAT_0052cba8); i++) {
            V3_2b4210 *A = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].a];
            V3_2b4210 *B = &verts[((Edge16_2b4210*)&DAT_00544bb0)[i].b];
            Vi Ac = *(Vi *)A;
            Vi Bc = *(Vi *)B;
            V3_2b4210 D1, D2;
            D1.x = A->x - L.x;
            D1.y = A->y - L.y;
            D1.z = A->z - L.z;
            D2.x = B->x - L.x;
            D2.y = B->y - L.y;
            D2.z = B->z - L.z;
            D1.FUN_0022d180();
            D2.FUN_0022d180();
            D1.x = D1.x * scale;
            D1.y = D1.y * scale;
            D1.z = D1.z * scale;
            D2.x = D2.x * scale;
            D2.y = D2.y * scale;
            D2.z = D2.z * scale;
            FI_2b4210 A2[3];
            A2[0].f = D1.x + A->x;
            A2[1].f = D1.y + A->y;
            A2[2].f = D1.z + A->z;
            FI_2b4210 B2[3];
            B2[0].f = D2.x + B->x;
            B2[1].f = D2.y + B->y;
            B2[2].f = D2.z + B->z;
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Ac.x;
                p[1].i = Ac.y;
                p[2].i = Ac.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = Bc.x;
                p[1].i = Bc.y;
                p[2].i = Bc.z;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = A2[0].i;
                p[1].i = A2[1].i;
                p[2].i = A2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
            {
                FI_2b4210 *p = b->pos;
                int c = DAT_004d06dc;
                p[0].i = B2[0].i;
                p[1].i = B2[1].i;
                p[2].i = B2[2].i;
                *b->color = c;
                b->FUN_0008ef00();
            }
        }
    }
    DAT_0052c2a8->v7c(b);
}
