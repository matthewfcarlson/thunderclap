// STATUS: equivalent (tools/equiv.py level 3: 3085 inputs, branch coverage 53/54, incomplete)
// FUN_002f1160 @ 0x002f1160
union Bits_2f1160 {
    float f;
    unsigned int u;
};

struct V3_2f1160 {
    float x, y, z;
    float FUN_00018990();
};

struct Obj_2f1160;

struct Q_2f1160 {
    char pad00[0x6c];
    int f6c;
};

struct Parent_2f1160 {
    char pad00[0x18];
    Q_2f1160 *q;
    char pad1c[4];
    Obj_2f1160 *root;                  // 0x20
};

struct List_2f1160 {
    Obj_2f1160 **begin;
    Obj_2f1160 **end;
};

struct Obj_2f1160 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2f1160 *getCenter();
    virtual void s5();
    virtual int kind();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void v10();
    char pad04[0xc];
    Parent_2f1160 *parent;             // 0x10
    List_2f1160 *children;             // 0x14
    char enabled;               // 0x18
    char flag19;                // 0x19
    char pad1a[0xe];
    V3_2f1160 ext;                     // 0x28
    float radius;               // 0x34
    char pad38[0xc];
    V3_2f1160 box44;                   // 0x44
    float f50;                  // 0x50
    float f54;                  // 0x54
    char b58;                   // 0x58
};

struct Query_2f1160 {
    Bits_2f1160 t;                     // 0x00
    Bits_2f1160 f4;                    // 0x04
    Obj_2f1160 *obj;                   // 0x08
};

union Slot_2f1160 {
    Query_2f1160 *q;
    Bits_2f1160 t;
};

extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern Bits_2f1160 DAT_00554c18;

bool FUN_002f0080(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *s);
bool FUN_002f04c0(V3_2f1160 *q, V3_2f1160 *dir, Bits_2f1160 a4, float rad, Bits_2f1160 *t);
bool FUN_002f0730(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *a3, V3_2f1160 *s, Bits_2f1160 *t);
bool FUN_002f0e80(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *a3, unsigned int f4, Obj_2f1160 *obj, Bits_2f1160 *t);
bool FUN_002f08d0(V3_2f1160 *q, V3_2f1160 *r, V3_2f1160 *box, float a, float b, V3_2f1160 *out);

bool FUN_002f1160(V3_2f1160 *p, V3_2f1160 *dir, V3_2f1160 *a3, Bits_2f1160 a4, Slot_2f1160 slot)
{
    struct Frame {
        V3_2f1160 q;
        V3_2f1160 r;
        V3_2f1160 s;
    } fr;
    Query_2f1160 *q = slot.q;
    bool hit;

    if (!q->obj->enabled)
        return false;
    if (!q->obj->parent->root->flag19)
        q->obj->v10();
    fr.q = *p;
    V3_2f1160 *c = q->obj->getCenter();
    fr.q.x = fr.q.x - c->x;
    fr.q.y = fr.q.y - c->y;
    fr.q.z = fr.q.z - c->z;
    fr.r = fr.q;
    fr.r.x = fr.r.x + a3->x;
    fr.r.y = fr.r.y + a3->y;
    fr.r.z = fr.r.z + a3->z;
    fr.s.y = DAT_00554c18.f;
    fr.s.z = DAT_00554c18.f;
    Obj_2f1160 *o0 = q->obj;
    if (DAT_004d2a3c == 0 && o0->radius > 0.0f) {
        float w = DAT_00554c18.f + o0->radius;
        fr.s.x = w;
        fr.s.y = w;
        fr.s.z = w;
    } else {
        o0 = q->obj;
        fr.s.x = DAT_00554c18.f + o0->ext.x;
        fr.s.y = fr.s.y + o0->ext.y;
        fr.s.z = fr.s.z + o0->ext.z;
    }
    if (FUN_002f0080(&fr.q, &fr.r, &fr.s))
        return false;

    hit = false;
    if (o0->kind() == 1) {
        if (DAT_004d2a3c == 0 && q->obj->parent->root == q->obj) {
            hit = FUN_002f04c0(&fr.q, dir, a4, q->obj->radius + DAT_00554c18.f, &q->t);
        } else {
            hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &slot.t);
            if (!hit)
                return hit;
            if (DAT_004d2a40)
                q->t.f = slot.t.f * a4.f;
        }
        if (!hit)
            return false;
        if (DAT_004d2a3c != 2 && DAT_004d2a40)
            return hit;

        Obj_2f1160 *self = q->obj;
        q->t.f = 1000000000.0f;
        V3_2f1160 a3c = *a3;
        Query_2f1160 child;
        child.t.u = 0;
        child.f4.u = 0;
        slot.t = a4;
        hit = false;
        unsigned int count = self->children->end - self->children->begin;
        if (count == 0)
            return hit;
        unsigned int i = 0;
        do {
            child.obj = self->children->begin[i];
            Slot_2f1160 cs;
            cs.q = &child;
            if (FUN_002f1160(p, dir, &a3c, slot.t, cs)) {
                if (child.t.f < q->t.f) {
                    q->t = child.t;
                    q->f4 = child.f4;
                    q->obj = child.obj;
                    hit = true;
                    slot.t = child.t;
                    a3c.x = child.t.f * dir->x;
                    a3c.y = child.t.f * dir->y;
                    a3c.z = child.t.f * dir->z;
                }
            }
            i++;
        } while (i < (unsigned int)(self->children->end - self->children->begin));
        return hit;
    }
    if (q->obj->kind() == 5 && DAT_004d2a3c == 2) {
        hit = FUN_002f0e80(&fr.q, &fr.r, a3, DAT_00554c18.u, q->obj, &slot.t);
    } else if (q->obj->kind() == 2 && DAT_004d2a3c == 2) {
        Obj_2f1160 *o = q->obj;
        float v = o->f50;
        if (!o->b58)
            v = v + o->f54;
        if (!FUN_002f08d0(&fr.q, &fr.r, &o->box44, v + DAT_00554c18.f, o->f54 + DAT_00554c18.f, &fr.s))
            return false;
        fr.s.x = fr.s.x - fr.q.x;
        fr.s.y = fr.s.y - fr.q.y;
        fr.s.z = fr.s.z - fr.q.z;
        q->t.f = fr.s.FUN_00018990();
        return true;
    } else {
        int k = q->obj->kind();
        if ((k == 7) ? (DAT_004d2a3c == 2) : (DAT_004d2a3c == 0))
            return FUN_002f04c0(&fr.q, dir, a4, q->obj->radius + DAT_00554c18.f, &q->t);
        hit = FUN_002f0730(&fr.q, &fr.r, a3, &fr.s, &slot.t);
    }
    if (hit) {
        hit = true;
        q->t.f = slot.t.f * a4.f;
    }
    return hit;
}
