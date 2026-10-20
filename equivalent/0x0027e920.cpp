// STATUS: equivalent (tools/equiv.py level 3: 1907 inputs, branch coverage 65/66, incomplete)
// pure3d::prop::StateProp::vfunc_6 @ 0x0027e920
struct V3_27e920 {
    float x, y, z;
};
struct Mat16 {
    float m[16];
};

struct Seg_27e920 {
    char type;
    char pad1[3];
    int f4;
    float f8;
};
struct SubInfo {
    char pad0[8];
    int f8;
    int fc;
    float f10;
    V3_27e920 a;
    V3_27e920 b;
    char pad2c[4];
};
struct State_27e920 {
    char pad0[0x10];
    Seg_27e920 *seg;
    char pad14[0x2c - 0x14];
    int subCount;
    SubInfo *subs;
};
struct StateList {
    char pad0[0x1c];
    State_27e920 **states;
};

struct Pair_27e920 {
    int a;
    int b;
};
struct Info74 {
    char pad[8];
    int a;
    int b;
};
struct MatSource_27e920 {
    char pad[0x74];
    Info74 *info;
};
struct Table_27e920 {
    char pad[0x3c];
    int *rows;
    unsigned char FUN_00298960(Pair_27e920 *p);
};

struct Sink84 {
    void FUN_00284820(int r);
};
class Obj18_27e920 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float dt, int flag);
};

struct Entry_27e920 {
    char pad0[0x10];
    MatSource_27e920 *obj;
    char pad14[4];
    void FUN_002fc580(float t, int flag);
    Mat16 *FUN_002fc6f0();
};

class MatOwner {
  public:
    virtual void m0();
    char pad[0x18];
    Mat16 *mats;
};

class Ctl88 : public Obj18_27e920 {
  public:
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
    virtual char v22();
    char FUN_00284ae0();
};

struct Slot48 {
    char pad0[8];
    unsigned char count;
    char pad9[0x18 - 9];
    unsigned char *order;
    char pad1c[0x24 - 0x1c];
    Ctl88 **objs;
    void FUN_00299230(int idx);
};

struct Ctl9cB;
class Ctl9c : public Obj18_27e920 {
  public:
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Sink84 *v11();
    char pad[0x44 - 4];
    Table_27e920 *table;
    Slot48 *slot48;
};
class Ctl9cB : public Obj18_27e920 {
  public:
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual MatOwner *v11();
};

struct ListEntry {
    void *obj;
    int f4;
    unsigned char flags;
    char pad[3];
};

struct Frame_27e920 {
    float oldT;
    union {
        int cnt;
        Pair_27e920 pair;
    };
    State_27e920 *s;
    V3_27e920 b;
    V3_27e920 a;
};

union Arg2_27e920 {
    int v;
    char b;
};

class StateProp {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float dt, Arg2_27e920 a2);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int v15();
    virtual void v16(int a, int b);
    char pad04[0x40 - 4];
    int state;
    float t;
    char pad48[0x88 - 0x48];
    Ctl88 *p88;
    char b8c;
    char pad8d[0x98 - 0x8d];
    StateList *states;
    Ctl9c *p9c;
    Entry_27e920 *pa0;
    Entry_27e920 *pa4;
    char pada8[0xb4 - 0xa8];
    int entryCount;
    ListEntry entries[1];

    void FUN_0027e780(void *obj, int f4);
    void FUN_0027d780();
    void FUN_0027dca0();
    void FUN_0027cc60(State_27e920 *s, float a, float b);
    void FUN_0027dd30(State_27e920 *s, float a, float b);
    void FUN_0027db30(Entry_27e920 *e, int f8, int fc, V3_27e920 a, V3_27e920 b);
};

void StateProp::v6(float dt, Arg2_27e920 a2)
{
    for (int i = 0; i < entryCount; i++) {
        ListEntry *e = &entries[i];
        if (e->flags & 4)
            FUN_0027e780(e->obj, e->f4);
        if (e->flags & 1)
            ((Obj18_27e920 *)e->obj)->v6(dt, a2.v);
    }
    Frame_27e920 fr;
    fr.oldT = t;
    t = dt * 0.03f + t;
    if (state == -1) {
        char flag = a2.b;
        p88->v6(dt, a2.v);
        if (pa0)
            pa0->FUN_002fc580(dt * 0.001f, 0);
        if (p88->FUN_00284ae0() || flag) {
            Ctl9c *p = p9c;
            int r = v15();
            p->v11()->FUN_00284820(r);
        }
        if (flag == 1 && p88->v22() == flag) {
            if (p88) {
                p88->v1();
                p88 = 0;
            }
            state = 0;
            t = 0;
            FUN_0027d780();
            if (b8c == 1)
                FUN_0027dca0();
        }
        return;
    }
    fr.s = states->states[state];
    Seg_27e920 *seg = fr.s->seg;
    while (seg->type == 1 && seg->f8 >= fr.oldT && seg->f8 < t) {
        if (b8c == 1)
            FUN_0027cc60(fr.s, fr.oldT, seg->f8);
        if (state == seg->f4) {
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = seg->f8;
            bits.u &= 0x7fffffff;
            if (bits.f <= 1e-05f)
                break;
        }
        float rem = t - seg->f8;
        v16(seg->f4, 0);
        dt = rem;
        t = dt;
        fr.s = states->states[state];
        seg = fr.s->seg;
        dt = dt * 33.333332f;
        fr.oldT = 0;
    }
    if (b8c == 1)
        FUN_0027cc60(fr.s, fr.oldT, t);
    FUN_0027dd30(fr.s, fr.oldT, t);
    Slot48 *sl = p9c->slot48;
    if (sl->count || a2.b)
        p9c->v6(dt, a2.v);
    unsigned int n = sl->count;
    while (n) {
        n--;
        unsigned char idx = sl->order[(unsigned char)n];
        if (sl->objs[idx]->v22())
            sl->FUN_00299230(sl->order[(unsigned char)n]);
    }
    if (!pa0)
        return;
    State_27e920 *cur = states->states[state];
    fr.cnt = cur->subCount;
    if (fr.cnt > 0) {
        int off1 = 0, off2 = 0;
        a2.v = fr.cnt;
        do {
            Entry_27e920 *e = (Entry_27e920 *)((char *)pa4 + off1);
            SubInfo *f = (SubInfo *)((char *)fr.s->subs + off2);
            if (!e->obj && f->f10 <= t) {
                fr.a = f->a;
                fr.b = f->b;
                FUN_0027db30(e, f->f8, f->fc, fr.a, fr.b);
            }
            off2 += 0x30;
            off1 += 0x18;
            a2.v--;
        } while (a2.v != 0);
    }
    dt = dt * 0.001f;
    pa0->FUN_002fc580(dt, 0);
    if (fr.cnt > 0) {
        int off = 0;
        a2.v = fr.cnt;
        do {
            Entry_27e920 *e = (Entry_27e920 *)((char *)pa4 + off);
            if (e->obj) {
                e->FUN_002fc580(dt, 0);
                fr.pair.a = ((Entry_27e920 *)((char *)pa4 + off))->obj->info->a;
                fr.pair.b = ((Entry_27e920 *)((char *)pa4 + off))->obj->info->b;
                unsigned char row = p9c->table->FUN_00298960(&fr.pair);
                Ctl9c *pp = p9c;
                int dstIndex = pp->table->rows[row * 3 + 1];
                Mat16 *src = ((Entry_27e920 *)((char *)pa4 + off))->FUN_002fc6f0();
                MatOwner *owner = (MatOwner *)pp->v11();
                owner->mats[dstIndex] = *src;
            }
            off += 0x18;
            a2.v--;
        } while (a2.v != 0);
    }
}
