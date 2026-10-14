// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 59/68, incomplete)
// FUN_002f15a0 @ 0x002f15a0
union Bits_2f15a0 {
    float f;
    unsigned int u;
};

struct V3_2f15a0 {
    float x, y, z;
    void FUN_000110d0(V3_2f15a0 *v);
    void FUN_00011160(unsigned int t, void *arg);
};

struct Obj_2f15a0;

struct Q_2f15a0 {
    char pad00[0x6c];
    int f6c;
};

struct Parent_2f15a0 {
    char pad00[0x18];
    Q_2f15a0 *q;                       // 0x18
    char pad1c[4];
    Obj_2f15a0 *root;                  // 0x20
};

struct List_2f15a0 {
    Obj_2f15a0 **begin;
    Obj_2f15a0 **end;
};

struct Obj_2f15a0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2f15a0 *getCenter();
    virtual void s5();
    virtual int kind();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void v10();
    char pad04[0xc];
    Parent_2f15a0 *parent;             // 0x10
    List_2f15a0 *children;             // 0x14
    char enabled;               // 0x18
    char flag19;                // 0x19
    char pad1a[0xe];
    V3_2f15a0 ext;                     // 0x28
    float radius;               // 0x34
    char pad38[0xc];
    V3_2f15a0 box44;                   // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
    char b58;                   // 0x58
};

union Arg5 {
    Obj_2f15a0 *obj;
    unsigned char top;
    Bits_2f15a0 t;
};

struct Hit_2f15a0 {
    int mode;                   // 0x00
    Bits_2f15a0 f4;                    // 0x04
    Obj_2f15a0 *obj;                   // 0x08
    V3_2f15a0 pos;                     // 0x0c
    char b18;                   // 0x18
};

bool FUN_002f0080(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *s);
bool FUN_002f04c0(V3_2f15a0 *q, V3_2f15a0 *dir, int a4, float rad, float *t);
bool FUN_002f0730(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *a3, V3_2f15a0 *s, float *t);
bool FUN_002f0e80(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *a3, unsigned int f4, Obj_2f15a0 *obj, float *t);
bool FUN_002f08d0(V3_2f15a0 *q, V3_2f15a0 *r, V3_2f15a0 *box, float a, float b, V3_2f15a0 *out);

bool FUN_002f15a0(V3_2f15a0 *p, V3_2f15a0 *dir, V3_2f15a0 *a3, int a4, Arg5 a5, Hit_2f15a0 *st)
{
    struct Frame {
        Bits_2f15a0 t10;
        V3_2f15a0 q;
        V3_2f15a0 r;
        V3_2f15a0 s;
        char gap[0x14];
    } fr;
    Obj_2f15a0 *obj = a5.obj;

    if (!obj->enabled)
        return false;
    bool top = (obj->parent->root == obj);
    a5.top = top;
    fr.q = *p;
    V3_2f15a0 *c = obj->getCenter();
    fr.q.x = fr.q.x - c->x;
    fr.q.y = fr.q.y - c->y;
    fr.q.z = fr.q.z - c->z;
    if (top || obj->kind() != 1) {
        double n = -(fr.q.y * dir->y + fr.q.z * dir->z + fr.q.x * dir->x);
        double px = n * dir->x + fr.q.x;
        double py = n * dir->y + fr.q.y;
        double pz = n * dir->z + fr.q.z;
        double rr = obj->radius + st->f4.f;
        if (rr * rr < pz * pz + py * py + px * px)
            return false;
    }

    Obj_2f15a0 *root = obj->parent->root;
    if (!root->flag19) {
        if (st->mode == 2 || !st->b18 || !top || obj->parent->q->f6c == 1)
            obj->v10();
    }

    fr.r.x = fr.q.x + a3->x;
    fr.r.y = fr.q.y + a3->y;
    fr.r.z = fr.q.z + a3->z;
    fr.s.y = st->f4.f;
    fr.s.z = st->f4.f;
    if (st->mode == 0 && obj->radius > 0.0f) {
        float w = st->f4.f + obj->radius;
        fr.s.x = w;
        fr.s.y = w;
        fr.s.z = w;
    } else {
        fr.s.x = st->f4.f + obj->ext.x;
        fr.s.y = fr.s.y + obj->ext.y;
        fr.s.z = fr.s.z + obj->ext.z;
    }
    if (FUN_002f0080(&fr.q, &fr.r, &fr.s))
        return false;

    bool hit;
    if (obj->kind() == 1) {
        if (st->mode == 0 && top) {
            hit = FUN_002f04c0(&fr.q, dir, a4, obj->radius + st->f4.f, &fr.t10.f);
            a5.top = hit;
            if (st->b18) {
                if (!hit)
                    return false;
                st->obj = obj;
                st->pos = *p;
                st->pos.FUN_00011160(fr.t10.u, dir);
                return hit;
            }
        } else {
            hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &fr.t10.f);
            a5.top = hit;
            if (st->b18 && st->mode == 1) {
                if (!hit)
                    return hit;
                st->obj = obj;
                st->pos = *p;
                st->pos.FUN_00011160(fr.t10.u, a3);
                return hit;
            }
        }
        if (!hit)
            return false;
        unsigned int i = 0;
        while (i < (unsigned int)(obj->children->end - obj->children->begin)) {
            Obj_2f15a0 *child = obj->children->begin[i];
            Arg5 c;
            c.obj = child;
            if (FUN_002f15a0(p, dir, a3, a4, c, st))
                return true;
            i++;
        }
        return false;
    }
    if (obj->kind() == 5 && st->mode == 2) {
        if (!FUN_002f0e80(&fr.q, &fr.r, a3, st->f4.u, obj, &a5.t.f))
            return false;
        st->obj = obj;
        st->pos = *p;
        st->pos.FUN_00011160(a5.t.u, a3);
        return true;
    }
    if (obj->kind() == 2 && st->mode == 2) {
        float v = obj->f50;
        if (!obj->b58)
            v = v + obj->f54;
        if (!FUN_002f08d0(&fr.q, &fr.r, &obj->box44, v + st->f4.f, obj->f54 + st->f4.f, &st->pos))
            return false;
        st->obj = obj;
        st->pos.FUN_000110d0(obj->getCenter());
        return true;
    }
    if (obj->kind() != 7 && st->mode != 0) {
        hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &a5.t.f);
        if (!hit)
            return false;
        st->obj = obj;
        st->pos = *p;
        st->pos.FUN_00011160(a5.t.u, a3);
        return true;
    }
    hit = FUN_002f04c0(&fr.q, dir, a4, obj->radius + st->f4.f, &a5.t.f);
    if (!hit)
        return false;
    st->obj = obj;
    st->pos = *p;
    st->pos.FUN_00011160(a5.t.u, dir);
    return true;
}
