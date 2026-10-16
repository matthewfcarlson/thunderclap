// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 14/14)
// FUN_002c5260 @ 0x002c5260
// equiv-conv: FUN_002c50c0 ebx stack stack stack stack stack stack
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
extern "C" double sqrt(double);
extern "C" double cos(double);
extern "C" double sin(double);


struct V3_2c5260 {
    float x, y, z;
    void FUN_0022d180();
};

struct Matrix {
    float m[16];
};

class Layer_2c5260 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(int state, Matrix *m);
};

struct VertexBuf_2c5260 {
    char pad0[8];
    V3_2c5260 *cursor;
    char padc[4];
    int *tag;
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
    virtual VertexBuf_2c5260* v30(int a, int b, int c, int n, int z);
    virtual void v31(VertexBuf_2c5260 *b);
};


Matrix *FUN_002c50c0(Matrix *out, V3_2c5260 mid, V3_2c5260 end);

void __cdecl FUN_002c5260(float r1, V3_2c5260 *a, float r2, V3_2c5260 *b, int handle, int tag, float n)
{
    struct Frame {
        volatile float theta;
        volatile float sinv;
        V3_2c5260 d;
        volatile float nh;
        volatile float y;
        volatile float z;
        Matrix m;
    } fr;

    fr.theta = 0.0f;
    fr.d.x = b->x - a->x;
    fr.d.y = b->y - a->y;
    double dzx = b->z - a->z;
    fr.d.z = (float)dzx;
    double len2 = dzx * fr.d.z + fr.d.y * fr.d.y + fr.d.x * fr.d.x;
    volatile float h = (float)(sqrt(len2) * 0.5f);
    fr.d.FUN_0022d180();
    volatile float hz = fr.d.z * h;
    V3_2c5260 mid;
    mid.x = fr.d.x * h + a->x;
    mid.y = fr.d.y * h + a->y;
    mid.z = hz + a->z;
    FUN_002c50c0(&fr.m, mid, *b);
    (*(*(Layer_2c5260***)&DAT_0052c2ac))->v23(0, &fr.m);

    int e1 = (r1 != 0.0f) ? 2 : 0;
    int e2 = (r2 != 0.0f) ? 2 : 0;
    VertexBuf_2c5260 *vb = DAT_0052c2a8->v30(handle, 2, 0x2020, (2 * (int)n + 1) * (e2 + e1 + 2), 0);

    volatile float step;
    if (r1 != 0.0f) {
        fr.theta = 0.0f;
        fr.nh = -h;
        fr.y = (float)(cos(0.0) * r1);
        fr.z = (float)(sin(0.0) * r1);
        step = (*(float*)&DAT_0042ef28) / n;
        double t;
        do {
            float yp = fr.y;
            float zp = fr.z;
            fr.y = (float)(cos((double)fr.theta) * r1);
            fr.z = (float)(sin((double)fr.theta) * r1);
            V3_2c5260 *c = vb->cursor;
            c->x = fr.nh;
            c->y = yp;
            c->z = zp;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = fr.nh;
            c->y = fr.y;
            c->z = fr.z;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            t = step + fr.theta;
            fr.theta = (float)t;
        } while (t <= (*(float*)&DAT_0042ef48));
    }
    if (r2 != 0.0f) {
        fr.y = (float)(cos((double)fr.theta) * r2);
        fr.z = (float)(sin((double)fr.theta) * r2);
        fr.theta = 0.0f;
        step = (*(float*)&DAT_0042ef28) / n;
        double t;
        do {
            float yp = fr.y;
            float zp = fr.z;
            fr.y = (float)(cos((double)fr.theta) * r2);
            fr.z = (float)(sin((double)fr.theta) * r2);
            V3_2c5260 *c = vb->cursor;
            c->x = h;
            c->y = yp;
            c->z = zp;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = h;
            c->y = fr.y;
            c->z = fr.z;
            *vb->tag = tag;
            vb->FUN_0008ef00();
            t = step + fr.theta;
            fr.theta = (float)t;
        } while (t <= (*(float*)&DAT_0042ef48));
    }
    fr.theta = 0.0f;
    fr.nh = -h;
    step = (*(float*)&DAT_0042ef28) / n;
    double t;
    do {
        double cx = cos((double)fr.theta);
        volatile float cf = (float)cx;
        double sx = sin((double)fr.theta);
        fr.sinv = (float)sx;
        V3_2c5260 *c = vb->cursor;
        c->x = fr.nh;
        c->y = (float)(cx * r1);
        c->z = (float)(sx * r1);
        *vb->tag = tag;
        vb->FUN_0008ef00();
        c = vb->cursor;
        c->x = h;
        c->y = cf * r2;
        c->z = fr.sinv * r2;
        *vb->tag = tag;
        vb->FUN_0008ef00();
        t = step + fr.theta;
        fr.theta = (float)t;
    } while (t <= (*(float*)&DAT_0042ef48));
    DAT_0052c2a8->v31(vb);
    (*(*(Layer_2c5260***)&DAT_0052c2ac))->v16(0);
}
