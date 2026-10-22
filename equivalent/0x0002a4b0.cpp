// STATUS: equivalent (tools/equiv.py level 3: 19683 inputs, branch coverage 62/64, incomplete)
// FUN_0002a4b0 @ 0x0002a4b0
// cl-flags: /GS
struct Pair_2a4b0 {
    int x, y;
};

struct Holder_2a4b0 {
    virtual void v0();
    virtual void v1();
};

struct Sink_2a4b0 {
    void FUN_0027ffb0(int v);
};

struct Q_2a4b0 {
    char pad0[0x60];
    void *f60;
    void *f64;
    char pad68[0xc0 - 0x68];
    void *fc0;
    char padc4[0x120 - 0xc4];
    char b120;
    char b121;
};

struct Obj_2a4b0 {
    char pad0[8];
    int f8;
    int fc;
    int *f10;
    char pad14[0x11c - 0x14];
    struct Inner_2a4b0 *f11c;
    char pad120[0x128 - 0x120];
    void *f128;
    void *f12c;
    char pad130[0x330 - 0x130];
    Obj_2a4b0 *f330;
    Obj_2a4b0 *f334;
    Obj_2a4b0 *f338;
    char pad33c[0x1ca0 - 0x33c];
    Q_2a4b0 *f1ca0;
    char pad1ca4[0x20b0 - 0x1ca4];
    int f20b0;
    int FUN_00036c60(int i);
    int FUN_00036d00();
    void FUN_000385a0(int a, int b);
    void FUN_0003a680(int a, int b, int c, int d, int e, int f, int g, int h);
    void FUN_0003ea10(int v);
};

struct Inner_2a4b0 {
    char pad0[0x1b0];
    int f1b0;
};

struct List_2a4b0 {
    Obj_2a4b0 *FUN_00059c10(int id);
    void FUN_00059e50(int id);
};

struct Cursor_2a4b0 {
    int FUN_000c7c60(int a, int b);
    void FUN_000c9100(int idx);
};
struct UI_2a4b0 {
    char pad0[0x88];
    Cursor_2a4b0 *f88;
    Cursor_2a4b0 *FUN_000cae70();
};

struct Ctx_2a4b0;

struct Ctx8 {
    void FUN_00098e30(Ctx_2a4b0 *ctx, int a, int b);
};

struct Ctx28 {
    void FUN_001fe000(Obj_2a4b0 *o);
    void FUN_001fc890(int a, int b);
};

struct CtxC {
    void FUN_001e5720(void *p);
};

struct Buf_2a4b0 {
    char data[0xb0];
    void FUN_001c9a20(int v);
};

struct Ctx30 {
    void FUN_001cbc20(Buf_2a4b0 *b);
};

struct Ctx3c {
    char pad0[8];
    UI_2a4b0 *ui;
};

struct Ctx_2a4b0 {
    char pad0[8];
    Ctx8 *c8;
    CtxC *cc;
    char pad10[0x28 - 0x10];
    Ctx28 *c28;
    char pad2c[4];
    Ctx30 *c30;
    char pad34[0x3c - 0x34];
    Ctx3c *c3c;
    char pad40[4];
    List_2a4b0 *list;
};

struct V2_2a4b0 {
    void FUN_00065d10(Pair_2a4b0 *p);
    void FUN_00065e20(Pair_2a4b0 *p);
};
struct HX {
    void FUN_001b4c40(Holder_2a4b0 *h);
};
V2_2a4b0 *FUN_000678d0();
Sink_2a4b0 *FUN_0027f250();
unsigned int FUN_00036c80();
HX *FUN_001b6580();


class Mgr_2a4b0 {
public:
    Ctx_2a4b0 *ctx;
    char pad4[8];
    int count;
    int ids[17];
    int arr1[16];
    int arr2[16];
    char padd4[0x124 - 0xd4];
    Holder_2a4b0 *f124;
    char FUN_0002a4b0(int index, char flag);
    void FUN_00024720(int a, int b);
};

struct Frame_2a4b0 {
    Pair_2a4b0 pair;          // 0x10
    Buf_2a4b0 buf;            // 0x18
};

char Mgr_2a4b0::FUN_0002a4b0(int index, char flag)
{
    Frame_2a4b0 f;
    if (index < 0 || index >= count) {
        return 0;
    }
    Obj_2a4b0 *o = ctx->list->FUN_00059c10(ids[index]);
    if (o) {
        Sink_2a4b0 *sink = FUN_0027f250();
        if (sink) {
            for (unsigned int i = 0; i < FUN_00036c80(); i++)
            {
                int tmp1 = o->FUN_00036c60(i);
                sink->FUN_0027ffb0(tmp1);
            }
        }
        if (!flag) {
            ctx->c28->FUN_001fe000(o);
            o->FUN_000385a0(0, 1);
        }
        Inner_2a4b0 *inner = o->f11c;
        UI_2a4b0 *ui = ctx->c3c->ui;
        if (inner && inner->f1b0 != 1 && ui && ui->FUN_000cae70()) {
            int v = o->FUN_00036d00();
            int arg1_ = v;
            int slot = ui->FUN_000cae70()->FUN_000c7c60(1, arg1_);
            if (slot >= 0)
            {
                int arg2_ = slot;
                ui->FUN_000cae70()->FUN_000c9100(arg2_);
            }
        }
        if (o->f128 && ctx->cc)
            ctx->cc->FUN_001e5720(o->f128);
    }

    ctx->c28->FUN_001fc890(o->f8, o->fc);
    f.pair.x = o->f8;
    f.pair.y = o->fc;
    Pair_2a4b0 * arg3_ = &f.pair;
    FUN_000678d0()->FUN_00065d10(arg3_);
    f.pair.x = o->f8;
    f.pair.y = o->fc;
    Pair_2a4b0 * arg4_ = &f.pair;
    FUN_000678d0()->FUN_00065e20(arg4_);
    FUN_00024720(o->f8, o->fc);
    ctx->c8->FUN_00098e30(ctx, o->f8, o->fc);

    for (int i = 0; i < count; i++) {
        Obj_2a4b0 *other = ctx->list->FUN_00059c10(ids[i]);
        if (i != index && other) {
            if (other->f330 == o)
                other->f330 = 0;
            if (other->f334 == o)
                other->f334 = 0;
            if (other->f338 == o)
                other->FUN_0003a680(0, -1, 0, 0, 0, 0, 0, 0);
            Q_2a4b0 *q = other->f1ca0;
            if (q) {
                void *t60 = q->f60;
                q->b121 = 0;
                q->b120 = 0;
                if (t60 == o->f12c)
                    q->f60 = 0;
                void *t64 = q->f64;
                if (t64 == o->f12c) {
                    q->f64 = 0;
                    q->fc0 = 0;
                }
            }
        }
    }

    Holder_2a4b0 *h = f124;
    if (o == (Obj_2a4b0 *)h && h) {
        h->v1();
        f124 = 0;
        Holder_2a4b0 * arg5_ = f124;
        FUN_001b6580()->FUN_001b4c40(arg5_);
    }
    if (o->f20b0 == 0)
        o->FUN_0003ea10(1);
    o->FUN_0003ea10(2);

    if (index < count) {
        count--;
        ids[index] = 0;
        if (count > 0) {
            ids[index] = ids[count];
            ids[count] = 0;
            arr1[index] = arr1[count];
            arr2[index] = arr2[count];
        }
    }

    Ctx30 *c30 = ctx->c30;
    if (c30) {
        f.buf.FUN_001c9a20(*o->f10);
        c30->FUN_001cbc20(&f.buf);
    }
    ctx->list->FUN_00059e50(*o->f10);
    return 1;
}
