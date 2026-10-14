// STATUS: equivalent (tools/equiv.py level 3: 268 inputs, branch coverage 28/28)
// FUN_000c8850 @ 0x000c8850
extern "C" double atan2(double y, double x);

struct V3 {
    float x, y, z;
    void FUN_0022d260(const struct Mat4_c8850 *m);
    void FUN_0022d180();
};

struct Mat4_c8850 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float angle);
    void FUN_0022cd50(const V3 *v);
};

struct V2 { float x, y; };

struct Cam_c8850 {
    V3 *FUN_001c39c0();
};
Cam_c8850 *FUN_001c3d90();

struct VBuf_c8850 {
    char pad0[8];
    V3 *pos;
    char padc[4];
    unsigned int *color;
    V2 *uv;
    void FUN_0008ef00();
};

struct Gfx_c8850 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual VBuf_c8850 *v30(void *a, int b, int c, int d, int e);
    virtual void v31(VBuf_c8850 *vb);
};
extern Gfx_c8850 *DAT_0052c2a8;

struct Dev_c8850 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
    virtual void v17(int a, Mat4_c8850 *m);
};

struct Render {
    Dev_c8850 *dev;
    void FUN_00293d00(const V3 *v);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293c20(float a);
};
extern Render *DAT_0052c2ac;

struct Handler_c8850 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct Sink_c8850 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(int a, int b);
};

struct SinkHolder_c8850 {
    char pad0[0x10];
    Sink_c8850 *sink;
};

struct Node {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual SinkHolder_c8850 *v7();
};

struct NodeOwner {
    Node *node;
};

struct Item_c8850 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
    char pad4[0x44];
    Node **f48;
};

struct Shot_c8850 {
    int id;                 // 0
    char pad4[0xc];
    float x;                // 0x10
    float y;                // 0x14
    V3 w;                   // 0x18
    char pad24[0x34 - 0x24];
    int a34;
    char pad38[0x3d - 0x38];
    char flag3d;
    char pad3e[2];
};

struct Src_c8850 {
    char pad0[0x10];
    void *f10;
};

extern float DAT_004de600;
extern float DAT_004de604;
extern float DAT_0049fbd8;
extern float DAT_0049fbdc;
extern float DAT_0049fbe0;
extern int DAT_0049fbf4[];

#define EMIT(PV, UU, UV) { V3 *pp_ = vb->pos; *pp_ = (PV); unsigned int *cp_ = vb->color; *cp_ = color; V2 *up_ = vb->uv; up_->x = (UU); up_->y = (UV); vb->FUN_0008ef00(); }

class Marker_c8850 {
public:
    char pad0[0x10];
    void *f10;
    Src_c8850 *f14;
    Handler_c8850 *f18;
    Handler_c8850 *f1c;
    char pad20[0x38 - 0x20];
    float f38;
    float f3c;
    char pad40[0x50 - 0x40];
    float ring[28];
    V3 pts[28];
    float f210;
    float f214;
    char pad218[0x228 - 0x218];
    int f228;
    Item_c8850 *tbl[11];
    Shot_c8850 shots[0x80];

    void FUN_000c8850();
};

struct Frame_c8850 {
    V3 base;                // x0,y0,z0
    V3 p;
    V3 q;
};

void Marker_c8850::FUN_000c8850()
{
    if (f10 == 0)
        return;
    V3 *dir = FUN_001c3d90()->FUN_001c39c0();
    V3 d0 = *dir;
    float ang = (float)atan2(d0.z, d0.x) + 4.712389f;
    Mat4_c8850 m1;
    m1.FUN_0022b980();
    m1.FUN_0022bab0(ang);
    unsigned int color = ((unsigned int)f228 << 24) | 0xffffff;
    VBuf_c8850 *vb = DAT_0052c2a8->v30(f14->f10, 0, 0x2021, 0x54, 0);

    volatile float tenth = DAT_004de600 * DAT_0049fbd8;
    V3 base;
    volatile float hx = DAT_004de600 * -0.5f;
    volatile float hy = DAT_004de604 * -0.5f;
    base.x = hx + tenth;
    base.y = hy + DAT_004de604 * DAT_0049fbdc;
    base.z = 0.0f;
    V3 p, q;
    p.z = 0.0f;
    q.z = 0.0f;

    int k = 1;
    for (int n = 0x1c; n != 0; n--, k++) {
        int a = (k + 6) % 0x1c;
        int b = (k + 7) % 0x1c;
        int c = k % 0x1c;
        p.x = ring[a] * f210;
        p.y = ring[k - 1] * f210;
        q.x = ring[b] * f210;
        q.y = ring[c] * f210;
        p.z = 0.0f;
        q.z = 0.0f;
        p.FUN_0022d260(&m1);
        q.FUN_0022d260(&m1);
        p.x = p.x + f38;
        p.y = p.y + f3c;
        float pu = p.x;
        float pv = p.y;
        q.x = q.x + f38;
        float qu = q.x;
        q.y = q.y + f3c;
        float qv = q.y;

        const V3 *r = &pts[c];
        float tx = DAT_0049fbe0 * r->x;
        float ty = DAT_0049fbe0 * r->y;
        volatile float tzs = DAT_0049fbe0 * r->z;
        V3 t;
        t.x = tx + base.x;
        t.y = ty + base.y;
        t.z = tzs + base.z;

        const V3 *s = &pts[k - 1];
        float ux = DAT_0049fbe0 * s->x;
        float uy = DAT_0049fbe0 * s->y;
        volatile float uzs = DAT_0049fbe0 * s->z;
        V3 u;
        u.x = ux + base.x;
        u.y = uy + base.y;
        u.z = uzs + base.z;

        EMIT(base, f38, f3c);
        EMIT(t, qu, qv);
        EMIT(u, pu, pv);
    }

    DAT_0052c2a8->v31(vb);
    DAT_0052c2ac->dev->v15(0);
    DAT_0052c2ac->FUN_00293d00(&base);
    DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
    DAT_0052c2ac->FUN_00293da0(DAT_0049fbe0, DAT_0049fbe0, DAT_0049fbe0);
    if (f18 != 0)
        f18->v8(0, 0);
    if (f1c != 0) {
        DAT_0052c2ac->FUN_00293c20(ang);
        f1c->v8(0, 0);
    }
    DAT_0052c2ac->dev->v16(0);

    float rot = 6.2831855f - ang;
    V3 d;
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 0.0f;
    for (const int *kp = DAT_0049fbf4; *kp != -1; kp++) {
        for (int i = 0; i < 0x80; i++) {
            Shot_c8850 *sh = &shots[i];
            if (sh->id != *kp)
                continue;
            float inv = 1.0f / f210;
            d.x = (sh->x - f38) * inv;
            d.y = (sh->y - f3c) * inv;
            if (!(d.y * d.y + d.x * d.x + d.z * d.z >= 1.0f)) {
            } else {
                if (sh->flag3d != 0)
                    continue;
                d.FUN_0022d180();
            }
            Mat4_c8850 m2;
            m2.FUN_0022b980();
            m2.FUN_0022bab0(rot);
            d.FUN_0022d260(&m2);
            float g = f214;
            volatile float gy = g * d.y;
            volatile float gz = d.z * g;
            V3 w;
            float wx = d.x * g * DAT_0049fbe0 + base.x;
            float wy = gy * DAT_0049fbe0 + base.y;
            float wz = gz * DAT_0049fbe0 + base.z;
            w.x = wx;
            w.y = wy;
            w.z = wz;
            Mat4_c8850 m3;
            m3.FUN_0022b980();
            if (sh->id == 0) {
                V3 v = sh->w;
                v.FUN_0022d260(&m2);
                m3.FUN_0022cd50(&v);
            }
            Item_c8850 *it = tbl[sh->id];
            if (it == 0)
                continue;
            DAT_0052c2ac->dev->v15(0);
            DAT_0052c2ac->FUN_00293d00(&w);
            DAT_0052c2ac->dev->v17(0, &m3);
            DAT_0052c2ac->FUN_00293da0(1.5f, 1.5f, 1.5f);
            int val = sh->a34;
            (*tbl[sh->id]->f48)->v7()->sink->v7(0x45444146, val);
            tbl[sh->id]->v8(0, 0);
            DAT_0052c2ac->dev->v16(0);
        }
    }
}
