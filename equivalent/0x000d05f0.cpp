// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 76/76)
// HUDOverlay::vfunc_4 @ 0x000d05f0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" double floor(double);
extern "C" double sqrt(double);
extern unsigned int DAT_004d9968;
extern int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
extern unsigned __int64 __cdecl FUN_002672f0(const void *name, int a, int b);

struct V3_d05f0 {
    float x, y, z;
};

struct Metrics_d05f0 {
    int dummy;
};

struct Slot_d05f0 {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack_d05f0 {
    Slot_d05f0 slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Label_d05f0 {
    int f0;
    char rest[0x20];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const void *name, Metrics_d05f0 *font, int flag);
};

struct Layout_d05f0 {
    Metrics_d05f0 *font;
    int current;
    SlotStack_d05f0 stack;
    Layout_d05f0 *FUN_000f7fe0(Metrics_d05f0 *font);
    void FUN_000f87f0(Label_d05f0 *e, void *arg);
    void FUN_000f80e0(const char *text, int a, const void *b);
    void FUN_000f78e0();
};

class Screen_d05f0 {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual int v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(int a, int b);
};

class Layer_d05f0 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Canvas {
    Layer_d05f0 *layer;
    void FUN_00293d00(const void *v);
    void FUN_00293bf0(float angle);
    void FUN_00293da0(float a, float b, float c);
};

class UiObj_d05f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float a, int b);
    virtual char v7();
    virtual void v8(int a, int b);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float a);
    virtual void v13();
    virtual void v14(float a, float b);
    virtual void v15(float *a, float *b);
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
};

struct UiVec_d05f0 {
    char pad0[0x24];
    UiObj_d05f0 **begin;
    UiObj_d05f0 **end;
};

struct Clock_d05f0 {
    float FUN_00085f80();
};
struct Obj10_d05f0 {
    int FUN_00059a50(V3_d05f0 *out);
};
struct World {
    char pad0[0x10];
    Obj10_d05f0 *p10;
};
struct ObjMgr {
    World *FUN_00024280(unsigned __int64 id);
};
struct Owner_d05f0 {
    char pad0[0x20];
    ObjMgr *objmgr;
    char pad24[0x58 - 0x24];
    Clock_d05f0 *clock;
};
struct Obj80 {
    float FUN_001cc8a0();
};
struct Part_d05f0 {
    void FUN_000c75b0();
    void FUN_000c72e0();
    void FUN_000c8850();
};

extern Screen_d05f0 *DAT_0052c2a8;
extern Canvas *DAT_0052c2ac;
extern V3_d05f0 DAT_004ddf00;
extern V3_d05f0 DAT_004dde98;
extern V3_d05f0 DAT_004ddef4;
extern V3_d05f0 DAT_004ddeb0;
extern float DAT_0049fcf4;
extern float DAT_0049fcf0;
extern float DAT_0049fd00;
extern float DAT_0049fcfc;
extern float DAT_0049fd28;
extern float DAT_0049fcc4;
extern int DAT_0049fcf8;
extern int DAT_0049fd08;

struct Frame_d05f0 {
    int padLow;
    float dist2;                // 0x00
    float out1;                 // 0x04
    union {
        int n1;
        float out2b;
    } s8;                       // 0x08
    union {
        float out2a;
        int n23;
    } sc;                       // 0x0c
    float dist1;                // 0x10
    Layout_d05f0 layout;              // 0x14
    union {
        char buf[0x44];
        Label_d05f0 e2;
        int digits[6];
        V3_d05f0 p3;
    } u;                        // 0xa4
    unsigned int cookie;        // 0xe8
};

class HUDOverlay {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x0c - 4];
    Owner_d05f0 *owner;
    char pad10[0x78 - 0x10];
    float f78;
    Metrics_d05f0 *font;
    Obj80 *p80;
    char pad84[4];
    Part_d05f0 *p88;
    Part_d05f0 *p8c;
    char pad90[4];
    char f94[0x14];
    float fa8;
    int iac;
    float fb0;
    int ib4;
    int flags;
    char fbc[0x13c - 0xbc];
    float f13c;
    float f140;
    float f144;
    int i148;
    char pad14c[0x1f8 - 0x14c];
    UiObj_d05f0 *p1f8;
    UiObj_d05f0 *arr[6];
    char pad214[0x244 - 0x214];
    UiObj_d05f0 *p244;
    UiVec_d05f0 *p248;
    int i24c;
    char pad250[0x4a0 - 0x250];
    UiObj_d05f0 *p4a0;
    char pad4a4[0x4ac - 0x4a4];
    UiVec_d05f0 *p4ac;
    UiVec_d05f0 *p4b0;
    UiVec_d05f0 *p4b4;
    V3_d05f0 v4b8;
    char name4c4[0x504 - 0x4c4];
    float f504;
    UiObj_d05f0 *p508;
    void FUN_000cc7e0();
    void FUN_000cf740();
    void FUN_000cda90();
    void FUN_000cab50();
};

void HUDOverlay::vfunc_4()
{
    Frame_d05f0 f;
    f.cookie = DAT_004d9968;
    int nscr = DAT_0052c2a8->v34();
    for (int i = 0; i < nscr; i++)
        DAT_0052c2a8->v38(i, 0);

    if (flags & 0x400) {
        p8c->FUN_000c75b0();
        p8c->FUN_000c72e0();
    }
    if (flags & 4)
        p88->FUN_000c8850();

    SlotStack_d05f0 *st = &f.layout.stack;
    if (flags & 0x200) {
        DAT_0052c2ac->layer->v15(0);
        DAT_0052c2ac->FUN_00293d00(&DAT_004ddf00);
        f.layout.FUN_000f7fe0(font);
        st->FUN_000f78f0();
        st->slots[st->index].b = 1;
        st->slots[st->index].a = 0;
        if (fb0 > 0.0f) {
            st->slots[st->index].weight = ((fb0 / DAT_0049fcf4) * 2.0f + 1.0f) * f78 * DAT_0049fd00;
            st->slots[st->index].value = 0xc4fef618;
            FUN_000964a0(f.u.buf, 0x40, "%d", ib4);
            f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, 0);
        }
        FUN_000964a0(f.u.buf, 0x40, "%d", iac);
        if (fa8 > 0.0f) {
            st->slots[st->index].weight = ((fa8 / DAT_0049fcf0) * 2.0f + 1.0f) * f78 * DAT_0049fd00;
            st->slots[st->index].value = 0xc4fef618;
            f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, 0);
        }
        st->slots[st->index].value = 0xfffef618;
        float k;
        if (fa8 > 0.2f)
            k = 1.2f;
        else
            k = 1.0f;
        st->slots[st->index].weight = k * f78 * DAT_0049fd00;
        f.layout.FUN_000f80e0(f.u.buf, DAT_0049fd08, f94);
        if (st->index > 0)
            st->index--;
        DAT_0052c2ac->layer->v16(0);
        f.layout.FUN_000f78e0();
    }

    if (f144 < f140) {
        DAT_0052c2ac->layer->v15(0);
        f.layout.FUN_000f7fe0(font);
        f.u.e2.FUN_000f7930();
        f.u.e2.FUN_000f8500(fbc, font, 1);
        f.u.e2.f0 = DAT_0049fcf8;
        st->FUN_000f78f0();
        int alpha = (int)((f144 / f140) * 255.0f);
        st->slots[st->index].value = ((255 - alpha) << 24) | (i148 & 0xffffff);
        st->slots[st->index].b = 2;
        st->slots[st->index].a = 1;
        st->slots[st->index].weight = (f144 / f140) * f13c * f78;
        f.layout.FUN_000f87f0(&f.u.e2, 0);
        if (st->index > 0)
            st->index--;
        DAT_0052c2ac->layer->v16(0);
        f.u.e2.FUN_000f7960();
        f.layout.FUN_000f78e0();
    }

    FUN_000cc7e0();
    if (flags & 0x10) {
        float x = p80->FUN_001cc8a0();
        int n1 = (int)floor(x);
        f.u.digits[5] = (n1 / 600) % 6;
        int n2 = (int)floor(x);
        f.u.digits[0] = (n2 / 60) % 10 + 10;
        int n3 = (int)floor(x);
        f.u.digits[1] = (n3 / 10) % 6 + 20;
        int n4 = (int)floor(x);
        f.u.digits[2] = n4 % 10 + 30;
        int n5 = (int)floor(x * 10.0f);
        f.u.digits[3] = n5 % 10 + 40;
        int n6 = (int)floor(x * 100.0f);
        f.u.digits[4] = n6 % 10 + 50;
        for (int i = 0; i < 6; i++) {
            if (arr[i] != 0) {
                arr[i]->v12((float)f.u.digits[i]);
                arr[i]->v7();
            }
        }
        DAT_0052c2ac->layer->v15(0);
        DAT_0052c2ac->FUN_00293d00(&DAT_004dde98);
        DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
        float c = DAT_0049fcfc;
        DAT_0052c2ac->FUN_00293da0(c, c, c);
        if (p1f8 != 0)
            p1f8->v8(0, 0);
        DAT_0052c2ac->layer->v16(0);
    }

    FUN_000cf740();
    if ((flags & 0xa) && p244 != 0) {
        p244->v6(owner->clock->FUN_00085f80() * 1000.0f, 0);
        DAT_0052c2ac->layer->v15(0);
        DAT_0052c2ac->FUN_00293d00(&DAT_004ddef4);
        DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
        float c = DAT_0049fd28;
        DAT_0052c2ac->FUN_00293da0(c, c, c);
        p244->v8(0, 0);
        if (i24c == 4 && p244->v7()) {
            unsigned char cnt = (unsigned char)(p248->end - p248->begin);
            for (int i = 0; i < cnt; i++) {
                UiObj_d05f0 *o = p248->begin[(unsigned char)i];
                o->v14(125.0f, 217.0f);
                o->v12(125.0f);
                o->v16(2);
                o->v18(-1);
                cnt = (unsigned char)(p248->end - p248->begin);
            }
        }
        DAT_0052c2ac->layer->v16(0);
    }

    FUN_000cda90();
    if ((flags & 0x20) && p4a0 != 0) {
        f.dist1 = 0.0f;
        f.dist2 = 0.0f;
        ObjMgr *om1 = owner->objmgr;
        World *w1 = om1->FUN_00024280(FUN_002672f0("hulk", 0, 0));
        if (w1 != 0) {
            V3_d05f0 &p = f.u.p3;
            w1->p10->FUN_00059a50(&p);
            f.dist1 = (float)sqrt((p.z - v4b8.z) * (p.z - v4b8.z) + (p.y - v4b8.y) * (p.y - v4b8.y) + (p.x - v4b8.x) * (p.x - v4b8.x));
        }
        ObjMgr *om2 = owner->objmgr;
        World *w2 = om2->FUN_00024280(FUN_002672f0(name4c4, 0, 0));
        if (w2 != 0) {
            V3_d05f0 &p = f.u.p3;
            w2->p10->FUN_00059a50(&p);
            f.dist2 = (float)sqrt((p.z - v4b8.z) * (p.z - v4b8.z) + (p.y - v4b8.y) * (p.y - v4b8.y) + (p.x - v4b8.x) * (p.x - v4b8.x));
        }
        if (p4ac != 0) {
            f.s8.n1 = (unsigned char)(p4ac->end - p4ac->begin);
            for (int i = 0; i < f.s8.n1; i++) {
                p4ac->begin[(unsigned char)i]->v15(&f.out1, &f.sc.out2a);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4ac->begin[(unsigned char)i]->v12(((f.sc.out2a - f.out1) / denom) * f.dist2);
                p4ac->begin[(unsigned char)i]->v7();
            }
        }
        if (p4b0 != 0) {
            f.sc.n23 = (unsigned char)(p4b0->end - p4b0->begin);
            for (int i = 0; i < f.sc.n23; i++) {
                p4b0->begin[(unsigned char)i]->v15(&f.out1, &f.s8.out2b);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4b0->begin[(unsigned char)i]->v12(((f.s8.out2b - f.out1) / denom) * f.dist1);
                p4b0->begin[(unsigned char)i]->v7();
            }
        }
        if (p4b4 != 0) {
            f.sc.n23 = (unsigned char)(p4b4->end - p4b4->begin);
            for (int i = 0; i < f.sc.n23; i++) {
                p4b4->begin[(unsigned char)i]->v15(&f.out1, &f.s8.out2b);
                float denom = (f504 == 0.0f) ? 1.0f : f504;
                p4b4->begin[(unsigned char)i]->v12(((f.s8.out2b - f.out1) / denom) * f.dist2);
                p4b4->begin[(unsigned char)i]->v7();
            }
        }
        DAT_0052c2ac->layer->v15(0);
        DAT_0052c2ac->FUN_00293d00(&DAT_004ddeb0);
        DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
        float c = DAT_0049fcc4;
        DAT_0052c2ac->FUN_00293da0(c, c, c);
        p4a0->v8(0, 0);
        DAT_0052c2ac->layer->v16(0);
    }

    if (flags & 0x800) {
        DAT_0052c2ac->layer->v15(0);
        DAT_0052c2ac->FUN_00293da0(4.0f, 4.0f, 4.0f);
        p508->v8(0, 0);
        DAT_0052c2ac->layer->v16(0);
    }
    FUN_000cab50();
    __security_check_cookie(f.cookie);
}
