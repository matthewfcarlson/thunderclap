// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 14/14)
// FUN_00082db0 @ 0x00082db0
struct V3 { float x, y, z; };

struct Quat {
    float x, y, z, w;
    void FUN_0022b370(struct Xform *m);
    void FUN_0022b120();
    void FUN_0022b650(struct Xform *m);
};

struct Xform {
    char pad0[0x30];
    V3 pos;                 // 0x30
};

struct Body {
    char pad0[0x10];
    V3 *rot;                // 0x10 (x,y,z,w quaternion storage)
    V3 *vec;                // 0x14
    void FUN_00284820(Xform *m);
};

struct Node {
    char pad0[0x50];
    V3 vel;                 // 0x50
    char pad5c[0x6c - 0x5c];
    int link;               // 0x6c
    void FUN_002ef8b0(int a);
};

struct Src;
struct Link {
    char pad0[0x9c];
    Src *src;        // 0x9c
    Node *FUN_001d72e0();
    void FUN_001d7510();
};

struct Src {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual Body *s11();
};

struct Player {
    Link *FUN_001dc0d0(int id);
};

struct Glob {
    char pad0[0xc];
    Player *players;        // 0xc
};

struct Anim {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(float a, int b);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12();
    virtual float v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23();
    virtual void v24(int a, int b, int c);
    void FUN_00288080(Body *b);
};

struct Orient {
    void FUN_0028a8f0(float a, float b, Quat *q);
};

struct Wind {
    char pad0[0x10];
    V3 v;                   // 0x10
};

extern Glob *DAT_004dd700;
extern Wind *DAT_00554c10;
extern void FUN_0022b080(Quat *out, Quat *a, Quat *b);
extern void FUN_00080f60(int a, Orient *o, Xform *x, float f1, float f2, V3 *v);

struct Fx {
    char pad0[0x10];
    int owner;              // 0x10
    int state;              // 0x14
    char pad18[5];
    char skipAnim;          // 0x1d
    char pad1e[0x24 - 0x1e];
    float f24;              // 0x24
    float f28;              // 0x28
    V3 vel;                 // 0x2c
    int link;               // 0x38
    Anim *anim;             // 0x3c
    char pad40[4];
    int kind;               // 0x44
    Orient *orient;         // 0x48
    void FUN_00082db0(float dt, Xform *x);
};

void Fx::FUN_00082db0(float dt, Xform *x)
{
    if (link == 0)
        return;
    Link *lk = DAT_004dd700->players->FUN_001dc0d0(owner);
    Body *body = lk->src->s11();
    if (skipAnim == 0) {
        anim->FUN_00288080(body);
        anim->v24(link, 0, 0);
        lk->FUN_001d72e0()->FUN_002ef8b0(0);
    }
    float f1 = anim->v13();
    anim->v6(dt * 1000.0f, 1);
    float f2 = anim->v13();
    V3 *p = &x->pos;
    V3 v = *p;
    Quat q;
    q.x = 0.0f; q.y = 0.0f; q.z = 0.0f; q.w = 1.0f;
    if (orient != 0)
        orient->FUN_0028a8f0(f1, f2, &q);
    Quat r;
    r.FUN_0022b370(x);
    FUN_0022b080(&r, &r, &q);
    FUN_00080f60(kind, orient, x, f1, f2, &vel);
    r.FUN_0022b120();
    r.FUN_0022b650(x);
    *p = v;
    V3 *rot = (V3 *)body->rot;
    rot->x = 0.0f; rot->y = 0.0f; rot->z = 0.0f;
    ((float *)rot)[3] = 1.0f;
    V3 *bv = (V3 *)((char *)body->vec + 0x30);
    bv->x = 0.0f; bv->y = 0.0f; bv->z = 0.0f;
    body->FUN_00284820(x);
    if (lk->FUN_001d72e0()->link != 0) {
        Node *n = lk->FUN_001d72e0();
        vel.x = n->vel.x;
        vel.y = n->vel.y;
        vel.z = n->vel.z;
        return;
    }
    if (dt > 0.0f) {
        double inv = 1.0f / dt;
        vel.x = (float)(inv * vel.x);
        vel.y = (float)(inv * vel.y);
        vel.z = (float)(inv * vel.z);
    }
    if (f28 > 1.0f) {
        lk->FUN_001d7510();
        state = 7;
        f24 = 0.0f;
    }
    if (f28 > 0.1f) {
        V3 w = DAT_00554c10->v;
        double wy = w.y * 0.01f;
        vel.x = (float)(w.x * dt + vel.x);
        vel.y = (float)(wy * dt + vel.y);
        vel.z = (float)(w.z * dt + vel.z);
    }
    p->x = (float)(dt * vel.x + p->x);
    p->y = (float)(dt * vel.y + p->y);
    p->z = (float)(dt * vel.z + p->z);
}
