// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 42/42)
// FUN_00195560 @ 0x00195560
struct V3 {
    float x, y, z;
};

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Request {
    char pad0[8];
    V3 target;             // 0x08
    char pad14[4];
    V3 aim;                // 0x18
    char pad24[4];
    V3 pos;                // 0x28
    char pad34[4];
    float xScaled;         // 0x38
    float yScaled;         // 0x3c
    float zScaled;         // 0x40
    char pad44[0x4c - 0x44];
    RefObj *p4c;
    RefObj *p50;
    int r54;
    char pad58[0x78 - 0x58];
    float val;             // 0x78
    int a6;                // 0x7c
    float one;             // 0x80
    RefObj *p84;
    char pad88[8];
    char pad90[8];
    Request *FUN_00059820();
    void FUN_00059300();
};

class Effect : public RefObj {
public:
    char pad04[0xb0 - 4];
    Effect *FUN_000598e0(int id, Request *r);
};

struct Sub {
    char data[0x40];
    char FUN_00231e80(struct Res *r);
};

class Res {
public:
    void FUN_00231ad0(Sub *sub, Effect *e, int v);
};

class Mgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Res *v8(Effect *e, int z);
};

struct Inner {
    char pad0[0x1b0];
    int f1b0;
};

struct Obj {
    char pad0[0x10];
    int *f10;
    char pad14[0xdc - 0x14];
    Sub sub;
    Inner *f11c;
    char pad120[0x12c - 0x120];
    RefObj *f12c;
    char FUN_000360f0();
    void FUN_00043350(float v, RefObj *r, int a, float one, int b, int c);
    void FUN_00043ae0(int a, V3 *b, float scale, int d, float val, int e, int f, int g, int h);
};

struct Src {
    char pad0[8];
    Obj *obj;
};

struct List {
    Obj *FUN_00059c10(int id);
};

struct World {
    char pad0[0x44];
    List *list;
};
extern World *DAT_004dd700;

void *FUN_0008d690(unsigned int size);
int __cdecl FUN_00266da0(int v);
void __cdecl FUN_00018810(RefObj **slot, RefObj *ref);

struct Frame {
    char pad0[3];
    char same;             // 0xf
    float val;             // 0x10
    Obj *o;                // 0x14
    int ctx;               // 0x18
    Request x;             // 0x1c
};

// equiv-conv: FUN_00195560 ecx eax ebx stack stack stack stack stack stack stack stack stack stack stack
bool FUN_00195560(V3 *self, Src *src, V3 *b, int id, Mgr *m1, Mgr *m2, V3 *c, float scale, float f5,
                  int a6, int a7, char a8, float f9, char a10)
{
    Frame f;
    Obj *esi = src->obj;
    Obj *o = DAT_004dd700->list->FUN_00059c10(id);
    f.o = o;
    f.same = 0;
    if (esi == 0)
        return false;
    if (a8) {
        if (esi->f11c->f1b0 == o->f11c->f1b0)
            return false;
    }
    if (*esi->f10 == id)
        return false;
    f.val = f5;
    if (o) {
        if (esi->f11c->f1b0 == o->f11c->f1b0) {
            f.val = f5 * f9;
            f.same = 1;
        }
    }
    if (esi->FUN_000360f0()) {
        esi->FUN_00043350(f.val, o ? o->f12c : 0, 0, 1.0f, 0, 0);
        return true;
    }

    f.ctx = FUN_00266da0(0xd);
    f.x.FUN_00059820();
    f.x.yScaled = self->y * scale;
    f.x.xScaled = self->x * scale;
    f.x.zScaled = self->z * scale;
    f.x.target = *b;
    f.x.aim = *c;
    f.x.pos = *self;
    f.x.r54 = a7;
    f.x.a6 = a6;
    f.x.val = f.val;
    f.x.one = 1.0f;
    if (f.o)
        FUN_00018810(&f.x.p4c, f.o->f12c);
    RefObj *r = esi->f12c;
    if (r)
        r->AddRef();
    if (f.x.p50)
        f.x.p50->Release();
    f.x.p50 = r;

    if (m1) {
        void *mem = FUN_0008d690(0xb0);
        Effect *e = 0;
        if (mem)
            e = ((Effect *)mem)->FUN_000598e0(*esi->f10, &f.x);
        e->AddRef();
        Res *res = m1->v8(e, 0);
        bool use;
        if (a10)
            use = res != 0 && f.same != 0;
        else
            use = res != 0;
        if (use) {
            res->FUN_00231ad0(&esi->sub, e, -1);
        } else {
            esi->FUN_00043ae0(0, b, scale, a7, f.val, 0, 0, 0, 0);
        }
        e->Release();
    } else {
        esi->FUN_00043ae0(0, b, scale, a7, f.val, 0, 0, 0, 0);
    }

    Obj *p = f.o;
    if (p && m2) {
        void *mem = FUN_0008d690(0xb0);
        Effect *e = 0;
        if (mem)
            e = ((Effect *)mem)->FUN_000598e0(id, &f.x);
        e->AddRef();
        Res *res = m2->v8(e, 0);
        if (res) {
            if (!p->sub.FUN_00231e80(res))
                res->FUN_00231ad0(&p->sub, e, -1);
        }
        e->Release();
    }
    f.x.FUN_00059300();
    FUN_00266da0(f.ctx);
    return true;
}
