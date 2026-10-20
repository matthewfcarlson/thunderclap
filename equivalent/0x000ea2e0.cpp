// STATUS: equivalent (tools/equiv.py level 3: 937 inputs, branch coverage 52/52)
// TextSelector::vfunc_3 @ 0x000ea2e0
// TextSelector::vfunc_3 @ 0x000ea2e0: measure the selector's text entries
struct Vec3 {
    float x, y, z;
};

struct Font {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float v7();
    float FUN_000dfbf0(const char *s);
};

struct Pane {
    char pad0[0x24];
    Font *font;
};

class Chain4 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual struct Pane *v44();
};

struct Chain8 {
    char pad0[4];
    Chain4 *f4;
};

struct TextSelector;

struct Slot16 {
    float x;
    char pad[12];
};

// matrix-stack style helper local: first dword set by its constructor, 8 entries, depth at +0x88
struct Xform {
    Pane *pane;
    char pad4[4];
    Slot16 entries[8];
    int depth;
    float FUN_000f88a0(void *item);
    float FUN_000f8840(void *item);
    void FUN_000f7fe0(Pane *p);
    void FUN_000f78e0();
};

struct Box {
    float a, b, c;
};

class Host {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual Vec3 *v15(Vec3 *out, TextSelector *self);
    virtual float v16(TextSelector *self);
    virtual float v17(TextSelector *self);
    char pad4[4];
    Chain8 *f8;
};

struct Item {
    char text[0x18];           // 0x00
    char flag;                 // 0x18
    char pad19[3];
    float scaled;              // 0x1c
    int sel;                   // 0x20
    char pad24[4];
    void *obj;                 // 0x28
    char pad2c[0x38 - 0x2c];
};

void __cdecl FUN_000f69e0(void *obj, Box *out);
extern "C" int __cdecl FUN_0034483c();

class FEControl_ea2e0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};

struct Frame {
    union {
        float b;             // 0x10
        int bi;
    };
    float a;                 // 0x14
    Vec3 tmpA;               // 0x18
    Box out;                 // 0x24
    Xform x;                 // 0x30
    float t;                 // 0xbc
};

class TextSelector : public FEControl_ea2e0 {
public:
    virtual void vfunc_3();
    char pad04[0x10];
    Host *host;                // 0x14
    char pad18[0x6c - 0x18];
    int f6c;
    int f70;
    char pad74[4];
    float f78;
    float f7c;
    char pad80[0x154 - 0x80];
    int f154;
    Item items[128];           // 0x158
    int count;                 // 0x1d58
    int mode;                  // 0x1d5c
    float f1d60, f1d64, f1d68, f1d6c, f1d70, f1d74, f1d78;
    int f1d7c, f1d80;
};

void TextSelector::vfunc_3()
{
    Frame f;
    int i;
    FEControl_ea2e0::vfunc_3();
    f1d60 = 0;
    f1d64 = 0;
    f1d74 = 0;
    f1d78 = 0;
    f.x.FUN_000f7fe0(host->f8->f4->v44());
    f.b = host->v17(this);
    f.x.entries[f.x.depth].x = host->v16(this) * f.b;
    f1d60 = f.x.FUN_000f88a0(&pad18) + f1d60;
    f1d64 = f.x.FUN_000f8840(&pad18) + f1d64;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            Item *it = &items[i];
            it->flag = 1;
            it->sel = -1;
            host->v15(&f.tmpA, this);
            it->scaled = f.tmpA.x * f1d68;
            it->sel = -1;
            f.a = f.x.FUN_000f88a0(it);
            f.b = f.x.FUN_000f8840(it);
            if (it->obj != 0) {
                FUN_000f69e0(it->obj, &f.out);
                if (f.out.a > f.a)
                    f.a = f.out.a;
                if (f.out.b > f.b)
                    f.b = f.out.b;
            }
            if (f.a > f1d74)
                f1d74 = f.a;
            if (f.b > f1d78)
                f1d78 = f.b;
        }
    }
    if (mode == 0) {
        Font *font = f.x.pane->font;
        Slot16 *top = &f.x.entries[f.x.depth];
        f.b = 14.0f / font->v7();
        f1d60 = font->FUN_000dfbf0(": ") * top->x * f.b + f1d60 + f1d74;
        if (f1d78 > f1d64)
            f1d64 = f1d78;
    } else if (mode == 2) {
        int e = count;
        f.b = 0.0f;
        for (i = 0; i < count; i++) {
            host->v15(&f.tmpA, this);
            if (f.b + f1d78 >= f.tmpA.y) {
                e = i;
                break;
            }
            f.b = (f.b + f1d78) + f1d70;
        }
        f1d7c = 0;
        f1d80 = count - 1;
        if (count > e)
            f1d80 = e - 1;
        while (f1d80 < f154 && f1d80 < count - 1) {
            f1d7c++;
            f1d80++;
        }
        f1d60 = f1d74 + f1d60;
        f.bi = f1d80 + 1;
        f.t = (f1d70 + f1d78) * (float)f.bi - f1d70;
        if (f.t > f1d64)
            f1d64 = f.t;
    } else {
        host->v15(&f.tmpA, this);
        float xw = f1d6c + f1d74;
        int n = (int)(f.tmpA.x / xw);
        f1d7c = 0;
        f1d80 = count - 1;
        if (count > n)
            f1d80 = n - 1;
        f.bi = f1d80 + 1;
        f1d60 = (float)f.bi * xw + f1d60;
        if (f1d78 > f1d64)
            f1d64 = f1d78;
    }
    switch (f6c) {
    case 1:
        f78 = f78 - f1d60 * 0.5f;
        break;
    case 2:
        f78 = f78 - f1d60;
        break;
    }
    if (mode == 2) {
        switch (f70) {
        case 3:
            host->v15(&f.tmpA, this);
            f7c = f1d64 - f.tmpA.y * 0.5f;
            break;
        case 2:
            f7c = f1d64 * 0.5f;
            break;
        case 1: {
            Vec3 *t2 = (Vec3 *)&f.out;
            host->v15(t2, this);
            f.b = t2->y * 0.5f;
            f7c = f.b - f.x.FUN_000f8840(&items[f1d7c]) * 0.5f;
            break;
        }
        }
    }
    f.x.FUN_000f78e0();
}
