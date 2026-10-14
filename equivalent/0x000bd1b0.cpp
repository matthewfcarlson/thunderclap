// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 78/80, incomplete)
// FUN_000bd1b0 @ 0x000bd1b0
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int strcmp(const char *, const char *);
extern "C" int memcmp(const void *, const void *, unsigned int);
extern unsigned int DAT_004d9968;

struct Measurer {
    int dummy;
};

struct Metrics {
    char pad0[0x24];
    void *f24;
    void *f28;
};

struct Mgr {
    char pad0[0x24];
    Measurer *measurers[1];
    unsigned short *FUN_00088ea0(const char *s);
};

struct Slot {
    float weight;
    int a;
    int b;
    int value;
};

struct SlotStack {
    Slot slots[8];
    int index;
    float scale;
    void FUN_000f78f0();
};

struct Label {
    int f0;
    char rest[0x20];
    void FUN_000f7930();
    void FUN_000f7960();
    void FUN_000f8500(const void *name, Mgr *mgr, int flag);
    void FUN_000f79a0(const unsigned short *s, Mgr *mgr);
};

struct Layout {
    Metrics *font;
    int current;
    SlotStack stack;
    Layout *FUN_000f7fe0(Metrics *font);
    void FUN_000f87f0(Label *e, void *arg);
    void FUN_000f78e0();
};

struct Style {
    int f0, f4, f8, fc;
    unsigned int f10;
    float f14;
    int f18;
    void FUN_000dee10();
};

class Screen {
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
    virtual void v12(int a);
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
    virtual void v24(int a);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28(float a, float b, float c, float d);
    virtual void v29();
    virtual struct Mesh *v30(int handle, int a, int b, int c, int d);
    virtual void v31(struct Mesh *m);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int a);
    virtual int v61();
};

struct Vertex {
    float x, y, z;
};

struct Mesh {
    char pad0[8];
    Vertex *verts;
    char pad0c[4];
    unsigned int *colors;
    void FUN_0008ef00();
};

class Layer {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Canvas {
    Layer *layer;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(float a, float b, float c);
};

class Viewport {
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
    virtual float v16();
};

struct Overlay20 {
    void FUN_00293ef0();
    void FUN_00294080();
};

struct Missions {
    char *FUN_0008a2d0();
    char *FUN_0008a060(const char *id);
};

struct Sound {
    void FUN_001ec480(const char *a, const char *b);
    void FUN_001eb2a0(float a, int b);
};

struct Dev10 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};

struct Obj68 {
    char pad0[0x10];
    Dev10 *f10;
    int pad14;
    int f18;
};

struct Probe {
    int FUN_000d3f10(const void *key);
};
struct Sink {
    void FUN_000afe80();
};
struct Obj86 {
    Probe *FUN_00086350();
    Sink *FUN_00086330();
};
struct Game {
    char pad0[0x54];
    Obj86 *f54;
};

struct Sys52 {
    char pad0[0xd8];
    int fd8;
    void FUN_0028f9a0();
    void FUN_0028faf0(int a);
};

struct TblEntry {
    const char *name;
    const char *strs[4];
};

extern TblEntry DAT_004061e8[];
extern Game *DAT_004dd700;
extern Screen *DAT_0052c2a8;
extern Canvas *DAT_0052c2ac;
extern Viewport *DAT_0052c2a4;
extern Sys52 *DAT_0052c2b4;
extern float DAT_004dde18;
extern char DAT_004dde1c;
extern float DAT_004dde20;
extern float DAT_004dde24;
extern unsigned int DAT_00409030;
extern float DAT_0049f5e0;

extern Mgr *__cdecl FUN_000fc1b0();
extern unsigned int __cdecl FUN_00267f80();
extern char __cdecl FUN_0008db80();
extern void __cdecl FUN_002684c0();
extern int __cdecl FUN_001eb200();
extern int __cdecl FUN_000fb830(unsigned short *out, int size, const unsigned short *in, float maxWidth, Measurer *m);
extern float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
extern float __cdecl FUN_000186f0(float *a, float *b);

struct Frame {
    union {
        float f;
        int i;
    } s0;                       // 0x00
    union {
        float f;
        int i;
    } s4;                       // 0x04
    int s8;                     // 0x08
    unsigned int dt;            // 0x0c
    void *self;                 // 0x10
    float lo;                   // 0x14
    int saved25;                // 0x18
    float hi;                   // 0x1c
    int saved61;                // 0x20
    Label e1;                   // 0x24
    int saved55;                // 0x48
    Layout layout;              // 0x4c
    Style style;                // 0xdc
    unsigned short buf[0x80];   // 0xf8
    char padHigh[0x2f8 - 0x1f8];
    unsigned int cookie;        // 0x2f8
};

class Menu {
public:
    char pad0[0x20];
    Overlay20 *p20;
    char pad24[8];
    unsigned int t2c;
    int *p30;
    Missions *p34;
    char pad38[4];
    Sound *p3c;
    char pad40[0x68 - 0x40];
    Obj68 *p68;
    void FUN_000bd1b0(unsigned char flag);
};

void Menu::FUN_000bd1b0(unsigned char flag)
{
    Frame f;
    f.cookie = DAT_004d9968;
    f.self = this;
    f.layout.FUN_000f7fe0((Metrics *)FUN_000fc1b0());
    SlotStack *st = &f.layout.stack;
    Menu *me = this;
    if (f.layout.font->f24 != 0 && f.layout.font->f28 != 0) {
        unsigned int now = FUN_00267f80();
        f.dt = now - t2c;
        if (f.dt >= 0x80)
            f.dt = 0x80;
        if (f.dt >= 0x40 && !FUN_0008db80()) {
            float aspect = 1.33333f / DAT_0052c2a4->v16();
            DAT_004dd700->f54->FUN_00086330()->FUN_000afe80();
            FUN_002684c0();
            FUN_002684c0();
            FUN_002684c0();
            t2c = now;
            DAT_0052c2b4->fd8 = 0;
            DAT_0052c2b4->FUN_0028f9a0();
            f.saved25 = DAT_0052c2a8->v25();
            DAT_0052c2a8->v24(0);
            f.saved55 = DAT_0052c2a8->v55();
            DAT_0052c2a8->v54(0);
            f.saved61 = DAT_0052c2a8->v61();
            DAT_0052c2a8->v60(1);
            p20->FUN_00293ef0();
            DAT_0052c2a8->v28(0.1f, 10000.0f, 0.5235988f, DAT_0052c2a4->v16());
            DAT_0052c2a8->v12(7);
            char *id = p34->FUN_0008a2d0();
            f.s8 = (int)id;
            bool done = false;
            if (p34 != 0) {
                char *r = p34->FUN_0008a060(id);
                if (r != 0 && memcmp(r, "complete", 9) == 0)
                    done = true;
            }
            if (!done) {
                if (DAT_004dd700->f54->FUN_00086350()->FUN_000d3f10(&DAT_00409030) == 0) {
                    DAT_004dde24 = 0.0f;
                } else if (p30 != 0 && (*p30 == 2 || *p30 == 3)) {
                    f.s4.i = 0;
                    if (DAT_004061e8[0].name != 0) {
                        TblEntry *e = DAT_004061e8;
                        for (;;) {
                            if (strcmp(e->name, id) == 0)
                                break;
                            f.s4.i++;
                            e++;
                            if (e->name == 0)
                                break;
                        }
                    }
                    int idx = f.s4.i;
                    if (DAT_004061e8[idx].name != 0) {
                        DAT_004dde24 = (float)f.dt * 0.001f + DAT_004dde24;
                        f.e1.FUN_000f7930();
                        f.s0.f = 1.0f;
                        float t = FUN_000186f0(&DAT_004dde24, &f.s0.f);
                        f.s0.f = t;
                        f.e1.f0 = 1;
                        st->FUN_000f78f0();
                        st->slots[st->index].value = 0xff000000;
                        st->slots[st->index].weight = 0.016f;
                        st->slots[st->index].b = 2;
                        st->slots[st->index].a = 1;
                        f.style.FUN_000dee10();
                        f.style.f10 = ((int)(f.s0.f * 128.0f) << 24) | 0x2bae11;
                        f.style.f14 = 1.0f;
                        DAT_0052c2ac->layer->v15(0);
                        DAT_0052c2ac->layer->v13(0);
                        DAT_0052c2ac->FUN_00293da0(aspect, aspect, 1.0f);
                        DAT_0052c2ac->FUN_00293d40(0.0f, 1.4f, 10.0f);
                        f.e1.FUN_000f8500("TBS_MENU_ITEM_PM_MISSION_OBJECTIVES", FUN_000fc1b0(), 1);
                        f.layout.FUN_000f87f0(&f.e1, &f.style);
                        DAT_0052c2ac->layer->v16(0);
                        if (st->index > 0)
                            st->index--;
                        f.e1.f0 = 0;
                        st->FUN_000f78f0();
                        st->slots[st->index].weight = 0.014f;
                        st->slots[st->index].b = 1;
                        st->slots[st->index].a = 0;
                        f.s4.f = 0.0f;
                        f.s8 = (int)&DAT_004061e8[idx].strs[0];
                        for (int k = 0; k < 4; k++, f.s8 += 4) {
                            const char *str = *(const char **)f.s8;
                            if (str != 0 && *str != 0) {
                                f.s0.f = DAT_004dde24 - (float)(k + 1) * 0.25f;
                                f.lo = 0.01f;
                                f.hi = 1.0f;
                                float c = FUN_000186b0(&f.s0.f, &f.lo, &f.hi);
                                int a8 = (int)(c * 255.0f);
                                st->slots[st->index].value = (a8 << 24) | 0xffffff;
                                DAT_0052c2ac->layer->v15(0);
                                DAT_0052c2ac->layer->v13(0);
                                DAT_0052c2ac->FUN_00293da0(aspect, aspect, 1.0f);
                                f.s0.f = 1.0f - f.s4.f;
                                DAT_0052c2ac->FUN_00293d40(-2.1f, f.s0.f, 10.0f);
                                f.e1.FUN_000f8500("TBS_MISSION_OBJECTIVE_STATUS_INCOMPLETE", FUN_000fc1b0(), 1);
                                f.layout.FUN_000f87f0(&f.e1, 0);
                                DAT_0052c2ac->layer->v16(0);
                                DAT_0052c2ac->layer->v15(0);
                                DAT_0052c2ac->layer->v13(0);
                                DAT_0052c2ac->FUN_00293da0(aspect, aspect, 1.0f);
                                DAT_0052c2ac->FUN_00293d40(-1.8f, f.s0.f, 10.0f);
                                f.s0.i = FUN_000fb830((unsigned short *)f.buf, 0x100, FUN_000fc1b0()->FUN_00088ea0(str), 460.0f,
                                                       FUN_000fc1b0()->measurers[f.e1.f0]);
                                f.e1.FUN_000f79a0((unsigned short *)f.buf, FUN_000fc1b0());
                                f.layout.FUN_000f87f0(&f.e1, 0);
                                DAT_0052c2ac->layer->v16(0);
                                f.s4.f = (float)f.s0.i * 0.2f + f.s4.f + 0.1f;
                            }
                        }
                        if (st->index > 0)
                            st->index--;
                        f.e1.FUN_000f7960();
                        me = (Menu *)f.self;
                    }
                }
            }

            f.s0.f = (float)f.dt * 0.001f;
            {
                float v = DAT_004dde20 + f.s0.f;
                DAT_004dde20 = v;
                if (v > 3.0f) {
                    do {
                        v = v - 3.0f;
                    } while (v > 3.0f);
                    DAT_004dde20 = v;
                }
            }
            if (!flag)
                DAT_004dde1c = 0;

            if (f.layout.font->f28 != 0) {
                DAT_0052c2ac->layer->v15(0);
                DAT_0052c2ac->layer->v13(0);
                DAT_0052c2ac->FUN_00293da0(aspect, aspect, 1.0f);
                DAT_0052c2ac->FUN_00293d40(0.0f, -1.0f, 10.0f);
                f.e1.FUN_000f7930();
                f.e1.f0 = 1;
                unsigned int c1 = 0x2b;
                unsigned int cA = 0xae;
                unsigned int cB = 0x11;
                if (flag) {
                    f.e1.FUN_000f8500("TBS_MENU_ITEM_PRESS_START2_XBOX", FUN_000fc1b0(), 1);
                    c1 = 0xfe;
                    cA = 0xf6;
                    cB = 0x18;
                    if (!DAT_004dde1c) {
                        me->p3c->FUN_001ec480("start", "prestart");
                        DAT_004dde1c = 1;
                    }
                    me->p3c->FUN_001eb2a0(0.01f, 1);
                } else {
                    f.e1.FUN_000f8500("TBS_MENU_ITEM_MC_LOADING_1", FUN_000fc1b0(), 1);
                }
                st->FUN_000f78f0();
                st->slots[st->index].b = 2;
                st->slots[st->index].a = 1;
                unsigned int base = ((c1 << 8) | cA) << 8;
                for (int i = 0; i < 2; i++) {
                    float t = ((float)i * DAT_0049f5e0 * 0.5f + DAT_004dde20) / DAT_0049f5e0;
                    while (t > 1.0f)
                        t = t - 1.0f;
                    int a8 = (int)(255.0f * t);
                    st->slots[st->index].value = ((0xff - a8) << 24) | base | cB;
                    st->slots[st->index].weight = t * 0.05f;
                    f.layout.FUN_000f87f0(&f.e1, 0);
                }
                f.style.FUN_000dee10();
                unsigned int col2 = ((((c1 | 0xffffff00) << 8) | cA) << 8) | cB;
                f.style.f10 = 0x7f000000;
                f.style.f14 = 1.0f;
                st->slots[st->index].value = col2;
                st->slots[st->index].weight = 0.016f;
                f.layout.FUN_000f87f0(&f.e1, &f.style);
                if (st->index > 0)
                    st->index--;
                DAT_0052c2ac->layer->v16(0);
                f.e1.FUN_000f7960();
            }

            if (!flag) {
                DAT_004dde18 = 0.0f;
            } else {
                DAT_004dde18 = DAT_004dde18 + f.s0.f;
                float m;
                if (DAT_004dde18 < 1.0f)
                    m = DAT_004dde18;
                else
                    m = 1.0f;
                unsigned int col = ((unsigned int)(int)((1.0f - m) * 255.0f) << 24) | 0x2bae11;
                DAT_0052c2ac->layer->v15(0);
                DAT_0052c2ac->layer->v13(0);
                DAT_0052c2ac->FUN_00293da0(aspect, aspect, 1.0f);
                DAT_0052c2ac->FUN_00293d40(0.0f, 0.0f, 10.0f);
                Obj68 *o68 = me->p68;
                o68->f10->v6(0x444d4c42, 1);
                o68->f18 = 1;
                Mesh *mesh = DAT_0052c2a8->v30((int)me->p68->f10, 1, 0x2020, 4, 0);
                {
                    Vertex *vv = mesh->verts;
                    vv->x = -8.0f;
                    vv->y = -4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex *vv = mesh->verts;
                    vv->x = 8.0f;
                    vv->y = -4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex *vv = mesh->verts;
                    vv->x = -8.0f;
                    vv->y = 4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                {
                    Vertex *vv = mesh->verts;
                    vv->x = 8.0f;
                    vv->y = 4.0f;
                    vv->z = 0.0f;
                }
                *mesh->colors = col;
                mesh->FUN_0008ef00();
                DAT_0052c2a8->v31(mesh);
                DAT_0052c2ac->layer->v16(0);
            }
            me->p20->FUN_00294080();
            DAT_0052c2a8->v54(f.saved55);
            DAT_0052c2a8->v60(f.saved61);
            DAT_0052c2a8->v24(f.saved25);
            DAT_0052c2b4->FUN_0028faf0(1);
            if (FUN_001eb200())
                FUN_00267f80();
        }
    }
    f.layout.FUN_000f78e0();
    __security_check_cookie(f.cookie);
}
