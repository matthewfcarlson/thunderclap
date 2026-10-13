// STATUS: equivalent (tools/equiv.py level 3: 2926 inputs, branch coverage 39/40, incomplete)
// FUN_000cda90 @ 0x000cda90
struct Batch {
    char pad00[8];
    unsigned int *pos;
    char pad0c[4];
    unsigned int *col;
    void FUN_0008ef00();
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
    virtual Batch *Begin(unsigned int id, int a, int b, int c, int d);
    virtual void End(Batch *b);
};
extern Device *DAT_0052c2a8;

class Cam {
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
    virtual void Push(int a);
    virtual void Pop(int a);
};

struct Vec3f { float x, y, z; };
struct Renderer {
    Cam *cam;
    void FUN_00293d00(const void *v);
    void FUN_00293bf0(float a);
    void FUN_00293da0(float a, float b, float c);
};
extern Renderer *DAT_0052c2ac;
extern Vec3f DAT_004ddef4;
extern float DAT_0049fd28;

class Widget {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void Flush(int a, int b);
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void SetValue(float v);
};

struct WList {
    char pad00[8];
    unsigned char count;
    char pad09[0x1b];
    Widget **items;
};

struct Pt {
    char pad00[0x10];
    float f10;
    char pad14[4];
    unsigned int f18;
};

struct Id { char pad[0x10]; unsigned int id; };

class Obj {
public:
    char pad00[0x90];
    Id *p90;
    char pad94[0x24];
    unsigned int flags;
    char padbc[0x250 - 0xbc];
    Widget *p250;
    Widget *p254;
    Widget *p258;
    WList *p25c;
    WList *p260;
    char pad264[0x464 - 0x264];
    Pt *p464;
    Pt *p468;
    float f46c;
    float f470;
    int f474;
    char pad478[8];
    float f480;
    float f484;
    float f488;
    char pad48c[8];
    int f494;
    int f498;
    float f49c;
    void FUN_000cda90();
};

union I {
    int i;
    unsigned int u;
    float f;
};

struct Frame {
    unsigned int s10;
    unsigned int s14;
    I s18;
    I s1c;
    int A;
    I s24;
    I s28;
    I s2c;
    float g1;
};

void Obj::FUN_000cda90()
{
    Frame f;
    if (!(flags & 2))
        return;
    if (p250 == 0)
        return;
    float T = f49c;
    if (T == -1.0f)
        T = f488;
    f.s2c.i = 0xfa0;
    if (f474 != 0)
        f.s2c.i = 0x189c;
    int idx = f498;
    int cnt = idx + 1;
    if (idx == -1) {
        cnt = 1 - (int)(T / (float)f.s2c.i * -5.0f);
        if (cnt > 6)
            cnt = 6;
    }
    f.s1c.f = 1.0f / (T / cnt + 1.0f);
    f.A = (int)(f.s1c.f * f480);
    f.s24.i = (int)(f.s1c.f * f484);
    int D = (int)(T / cnt + 1.0f);
    f.s2c.i = (int)f480 % D;
    f.g1 = (float)f.s2c.i * f.s1c.f;
    f.s2c.i = (int)f484 % D;
    f.s2c.f = (float)f.s2c.i * f.s1c.f;
    DAT_0052c2ac->cam->Push(0);
    DAT_0052c2ac->FUN_00293d00(&DAT_004ddef4);
    DAT_0052c2ac->FUN_00293bf0(-1.5707964f);
    DAT_0052c2ac->FUN_00293da0(DAT_0049fd28, DAT_0049fd28, DAT_0049fd28);
    p250->Flush(0, 0);
    unsigned int alpha = (unsigned int)f494 << 24;
    unsigned int col1 = alpha | 0xff0000;
    Widget *obj1 = p258;
    WList *wl = p260;
    if (f474 != 0) {
        obj1 = p254;
        wl = p25c;
        col1 = alpha | 0x79fe4;
    }
    f.s1c.u = (unsigned int)obj1;
    unsigned int col2 = alpha | 0xf0e614;
    int A = f.A;
    if (A != f.s24.i) {
        if (f494 > 0x80) {
            f.s18.i = 0;
            if (wl->count > 0) {
                do {
                    Widget *w = wl->items[(unsigned char)f.s18.i];
                    f.s28.i = f.s24.i;
                    if (A >= f.s24.i)
                        f.s28.i = A;
                    w->SetValue((float)f.s28.i);
                    f.s18.i++;
                    A = f.A;
                } while (f.s18.i < wl->count);
                obj1 = (Widget *)f.s1c.u;
            }
            obj1->Flush(0, 0);
            obj1 = (Widget *)f.s1c.u;
            A = f.A;
        }
        f.s18.i = 0;
        if (wl->count > 0) {
            do {
                Widget *w = wl->items[(unsigned char)f.s18.i];
                f.s28.i = A;
                if (!(A < f.s24.i))
                    f.s28.i = f.s24.i;
                w->SetValue((float)f.s28.i);
                f.s18.i++;
                A = f.A;
            } while (f.s18.i < wl->count);
            obj1 = (Widget *)f.s1c.u;
        }
    } else {
        f.s18.i = 0;
        if (wl->count > 0) {
            f.s28.f = (float)f.A;
            do {
                Widget *w = wl->items[(unsigned char)f.s18.i];
                w->SetValue(f.s28.f);
                f.s18.i++;
            } while (f.s18.i < wl->count);
            obj1 = (Widget *)f.s1c.u;
        }
    }
    obj1->Flush(0, 0);
    f.s2c.f = f.s2c.f;
    float X1 = p464->f10 - f.g1 * f470;
    f.s10 = *(unsigned int *)&p464->f10;
    f.s14 = p464->f18;
    f.s18.f = X1;
    f.s1c.u = p468->f18;
    int edi;
    if (f480 > f484 && (f.s28.f = f480 - f484, f.s28.u &= 0x7fffffff, f.s28.f > 1e-5f)) {
        float Y2 = p464->f10 - f.s2c.f * f470;
        f.s18.f = Y2;
        Batch *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    } else if (f.s24.i > f.A) {
        f.s2c.f = p464->f10 - f.s2c.f * f470;
        Batch *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s2c.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s2c.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    } else {
        Batch *b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        unsigned int *pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col1;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        f.s18.f = p464->f10 - f.s2c.f * f470;
        f.s10 = 0;
        float x1 = p464->f10 - f.g1 * f470;
        *(float *)&f.s10 = x1;
        b = DAT_0052c2a8->Begin(p90->id, 1, 0x2020, 4, 0);
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s14;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s18.u;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        pp = b->pos;
        pp[0] = f.s10;
        pp[1] = 0;
        pp[2] = f.s1c.u;
        *b->col = col2;
        b->FUN_0008ef00();
        DAT_0052c2a8->End(b);
        edi = 0;
    }
    DAT_0052c2ac->cam->Pop(edi);
}
