// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 28/28)
// TextWindow::vfunc_5 @ 0x000ed400
#include "decls/data/engine/pure3d/prop.h"

struct Vec3_ed400 {
    float x, y, z;
};

union Word_ed400 {
    float f;
    int i;
    unsigned int u;
};

struct BCell_ed400 {
    Word_ed400 a, b, c, d;
};

struct Source_ed400;

struct Builder {
    unsigned int hdr[2];
    BCell_ed400 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_ed400 *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
    void FUN_000f81b0(int v, int font, void *flags);
};

class Source_ed400 {
public:
    virtual void v0();
};

class Level2_ed400 {
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
    virtual Source_ed400* v44();
};

struct Level1_ed400 {
    char pad0[4];
    Level2_ed400 *level2;
};

class TextWindow;

class Owner_ed400 {
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
    virtual char v13(TextWindow *obj);
    virtual void v14(Vec3_ed400 *out, TextWindow *obj);
    virtual void v15(Vec3_ed400 *out, TextWindow *obj);
    virtual float v16(TextWindow *obj);
    virtual float v17(TextWindow *obj);
    char pad04[4];
    Level1_ed400 *p8;
};


class Pass_ed400 {
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

struct PassHolder_ed400 {
    Pass_ed400 *pass;
    void FUN_00293d00(const Vec3_ed400 *v);
    void FUN_00293da0(int a, int b, int c);
};

class Widget_ed400 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};



void __cdecl FUN_000e11a0(Vec3_ed400 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_ed400 v, int a, int b);

class TextWindow {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x10];
    Owner_ed400 *owner;               // 0x14
    char pad18[0x3c - 0x18];
    unsigned int color;         // 0x3c
    unsigned char flag40;
    char pad41[7];
    unsigned char flag48;       // 0x48
    char pad49[3];
    int val4c;
    Widget_ed400 *child;              // 0x50
    int v54, v58, v5c;
    char pad60[0x6c - 0x60];
    unsigned int v6c;           // 0x6c
    unsigned int v70;           // 0x70
    unsigned char active;       // 0x74
    char pad75[3];
    Vec3_ed400 anchor;                // 0x78
    char pad84[0xa4 - 0x84];
    int fa4;
    char pada8[0x148 - 0xa8];
    int val148;
    char pad14c[0x154 - 0x14c];
    Widget_ed400 *obj154;
    Widget_ed400 *obj158;
    char pad15c[0x164 - 0x15c];
    int items[0x200];
    int count;                  // 0x964
    float spacing;              // 0x968
    int first;                  // 0x96c
    int last;                   // 0x970
};

struct Frame_ed400 {
    Vec3_ed400 b;                     // 0
    float m;                    // 0xc
    float mc;                   // 0x10
    Vec3_ed400 a;                     // 0x14
    float e0;                   // 0x20
    Vec3_ed400 c;                     // 0x24
    Builder x;                  // 0x30
};

void TextWindow::vfunc_5()
{
    if (active == 0)
        return;

    Frame_ed400 f;

    if (flag40 == 1) {
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.b, this);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&f.b);
        owner->v15(&f.b, this);
        FUN_000e11a0(f.b, val148, 2);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (flag48 == 1) {
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.b, this);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&f.b);
        owner->v15(&f.b, this);
        FUN_000e0cc0(f.b, val4c, 0);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (child != 0) {
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.b, this);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&f.b);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293da0(v54, v58, v5c);
        child->v8(0, 0);
        (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v16(0);
    }

    f.x.FUN_000f7fe0(owner->p8->level2->v44());
    f.x.cells[f.x.cursor].c.u = v70;
    f.x.cells[f.x.cursor].b.u = v6c;
    f.mc = owner->v17(this);
    f.x.cells[f.x.cursor].a.f = owner->v16(this) * f.mc;
    f.x.cells[f.x.cursor].d.u = color;
    (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v15(0);
    (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&anchor);
    last = count - 1;
    owner->v14(&f.a, this);
    owner->v15(&f.b, this);
    int mode = v70;
    f.m = f.b.y * 0.5f + f.a.y - spacing * 0.5f;
    if (mode == 2) {
        owner->v14(&f.a, this);
        if (!(f.m < (float)count * spacing * 0.5f + f.a.y - spacing * 0.5f))
            f.m = (float)count * spacing * 0.5f + f.a.y - spacing * 0.5f;
    }
    f.mc = f.m;
    owner->v14(&f.c, this);
    owner->v14(&f.a, this);
    f.b.x = f.a.x * 1.05f;
    f.b.y = f.m;
    f.b.z = f.c.z;
    (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&f.b);

    int i = first;
    if (i < count) {
        int *p = &items[i];
        do {
            f.x.FUN_000f81b0(*p, fa4, (char *)owner->p8 + 0x978);
            f.b.x = 0.0f;
            f.b.y = spacing * -1.05f;
            f.b.z = 0.0f;
            (*(PassHolder_ed400**)&DAT_0052c2ac)->FUN_00293d00(&f.b);
            f.mc = f.mc - spacing * 1.05f;
            f.e0 = f.m - f.mc + spacing;
            owner->v15(&f.c, this);
            if (f.e0 >= f.c.y) {
                last = i;
                break;
            }
            i++;
            p++;
        } while (i < count);
    }
    (*(PassHolder_ed400**)&DAT_0052c2ac)->pass->v16(0);
    if (owner->v13(this)) {
        if (obj154 != 0 && first != 0)
            obj154->v8(0, 0);
        if (obj158 != 0 && last != count - 1)
            obj158->v8(0, 0);
    }
    f.x.FUN_000f78e0();
}
