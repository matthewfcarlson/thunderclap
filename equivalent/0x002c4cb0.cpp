// STATUS: equivalent (tools/equiv.py level 3: 27 inputs, branch coverage 8/8)
// FUN_002c4cb0 @ 0x002c4cb0
extern float DAT_0042ef28;   // pi
extern float DAT_0042ef48;   // 2 * pi

struct V3 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    Matrix() {}
    void FUN_0022b980();
    void FUN_0022be40(const V3 *pos);
};

class Device {
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

struct VertexBuf {
    char pad0[8];
    V3 *cursor;         // 8
    char padc[4];
    int *tag;           // 0x10
    void FUN_0008ef00();
};

class Renderer {
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
    virtual VertexBuf *v30(int a, int b, int c, int n, int z);
    virtual void v31(VertexBuf *b);
};

extern Device **DAT_0052c2ac;
extern Renderer *DAT_0052c2a8;

void __cdecl FUN_00356bf0(float r, float az, float pol, float *x, float *y, float *z);

void __cdecl FUN_002c4cb0(float a1, V3 *a2, int a3, int a4, float a5, float a6)
{
    Matrix m;
    m.FUN_0022b980();
    m.FUN_0022be40(a2);
    (*DAT_0052c2ac)->v23(0, &m);
    Renderer *rend = DAT_0052c2a8;
    VertexBuf *vb = rend->v30(a3, 2, 0x2020, (int)((a6 + a6 + 1.0f) * (a5 + 1.0f) * 4.0f), 0);
    V3 v;
    FUN_00356bf0(a1, 0, 0, &v.x, &v.y, &v.z);
    volatile float dphi = DAT_0042ef28 / a5;
    volatile float outerA = 0;
    volatile float innerB;
    volatile float dtheta = DAT_0042ef28 / a6;
    do {
        float ph = outerA;
        innerB = 0;
        double x;
        do {
            V3 a = v;
            FUN_00356bf0(a1, ph, innerB, &v.x, &v.y, &v.z);
            V3 *c = vb->cursor;
            c->x = a.x;
            c->z = a.z;
            c->y = a.y;
            int *t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = v.x;
            c->y = v.y;
            c->z = v.z;
            t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            x = dphi + innerB;
            innerB = (float)x;
        } while (x <= DAT_0042ef28);
        double y = dtheta + outerA;
        outerA = (float)y;
        if (!(y <= DAT_0042ef48))
            break;
    } while (true);
    FUN_00356bf0(a1, 0, 0, &v.x, &v.y, &v.z);
    innerB = 0;
    do {
        float ph = innerB;
        outerA = 0;
        double x;
        do {
            V3 a = v;
            FUN_00356bf0(a1, outerA, ph, &v.x, &v.y, &v.z);
            V3 *c = vb->cursor;
            c->x = a.x;
            c->z = a.z;
            c->y = a.y;
            int *t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            c = vb->cursor;
            c->x = v.x;
            c->y = v.y;
            c->z = v.z;
            t = vb->tag;
            *t = a4;
            vb->FUN_0008ef00();
            x = dphi + outerA;
            outerA = (float)x;
        } while (x <= DAT_0042ef48);
        double y = dtheta + innerB;
        innerB = (float)y;
        if (!(y <= DAT_0042ef28))
            break;
    } while (true);
    DAT_0052c2a8->v31(vb);
    (*DAT_0052c2ac)->v16(0);
}
