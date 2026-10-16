// STATUS: equivalent (tools/equiv.py level 3: 515 inputs, branch coverage 32/32)
// TextTable::vfunc_5 @ 0x000edb60
#include "decls/data/engine/pure3d/prop.h"

struct Vec3_edb60 {
    float x, y, z;
};

union Word_edb60 {
    float f;
    int i;
    unsigned int u;
};

struct BCell_edb60 {
    Word_edb60 a, b, c, d;
};

struct Source_edb60;

struct Builder {
    unsigned int hdr[2];
    BCell_edb60 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_edb60 *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
    float FUN_000f8840(void *cell);
};

class Source_edb60 {
public:
    virtual void v0();
};

class Level2_edb60 {
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
    virtual Source_edb60* v44();
};

struct Level1_edb60 {
    char pad0[4];
    Level2_edb60 *level2;
};

class TextTable;

class Owner_edb60 {
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
    virtual char v13(TextTable *obj);
    virtual void v14(Vec3_edb60 *out, TextTable *obj);
    virtual void v15(Vec3_edb60 *out, TextTable *obj);
    virtual float v16(TextTable *obj);
    virtual float v17(TextTable *obj);
    char pad04[4];
    Level1_edb60 *p8;
};


class Pass_edb60 {
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

struct PassHolder_edb60 {
    Pass_edb60 *pass;
    void FUN_00293d00(const Vec3_edb60 *v);
    void FUN_00293da0(int a, int b, int c);
};

class Widget_edb60 {
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

struct Flag118 {
    char pad0[0x118];
    float f118;
};

struct Cell_edb60 {
    char pad00[0x10];
    int f10;
    int f14;
    char b18;
    char pad19[3];
    float colx;
    int f20;
};


void __cdecl FUN_000e11a0(Vec3_edb60 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_edb60 v, int a, int b);

class TextTable {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x10];
    Owner_edb60 *owner;
    char pad18[0x3c - 0x18];
    unsigned int color;
    unsigned char flag40;
    char pad41[7];
    unsigned char flag48;
    char pad49[3];
    int val4c;
    Widget_edb60 *child;
    int v54, v58, v5c;
    char pad60[0x74 - 0x60];
    unsigned char active;
    char pad75[3];
    Vec3_edb60 anchor;
    char pad84[0x148 - 0x84];
    int val148;
    char pad14c[0x154 - 0x14c];
    Flag118 *obj154;
    Flag118 *obj158;
    Cell_edb60 cells[64][8];
    int rowCount;
    int colCount;
    int rowFirst;
    int rowLast;
    float spacing;
    float colX[8];
};

void TextTable::vfunc_5()
{
    if (active == 0)
        return;

    struct Frame {
        union {
            float f1;
            int r;
        } u10;
        float m;
        Vec3_edb60 v2;
        Vec3_edb60 v1;
        Cell_edb60 *rowptr;
        int j;
        Builder x;
    } f;

    if (flag40 == 1) {
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        owner->v15(&f.v2, this);
        FUN_000e11a0(f.v2, val148, 2);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (flag48 == 1) {
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        owner->v15(&f.v2, this);
        FUN_000e0cc0(f.v2, val4c, 0);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (child != 0) {
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293da0(v54, v58, v5c);
        child->v8(0, 0);
        (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v16(0);
    }

    f.x.FUN_000f7fe0(owner->p8->level2->v44());
    f.u10.f1 = owner->v17(this);
    f.x.cells[f.x.cursor].a.f = owner->v16(this) * f.u10.f1;
    f.x.cells[f.x.cursor].c.i = 1;
    f.x.cells[f.x.cursor].b.i = 0;
    f.x.cells[f.x.cursor].d.u = color;
    f.x.hdr[1] = color;
    (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v15(0);
    owner->v14(&f.v1, this);
    (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
    (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&anchor);

    f.u10.r = rowFirst;
    if (f.u10.r <= rowLast) {
        f.rowptr = &cells[f.u10.r][0];
        do {
            (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v15(0);
            f.m = 0.0f;
            f.j = 0;
            if (colCount > 0) {
                Cell_edb60 *c = f.rowptr;
                float *cx = colX;
                do {
                    if (c->f10 != 0 || c->f14 != -1) {
                        c->b18 = 1;
                        c->f20 = -1;
                        c->colx = *cx;
                        f.x.FUN_000f87f0(c, 0);
                        f.v2.x = *cx;
                        f.v2.y = 0.0f;
                        f.v2.z = 0.0f;
                        (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v2);
                        float w = f.x.FUN_000f8840(c);
                        if (w > f.m)
                            f.m = w;
                    }
                    f.j++;
                    cx++;
                    c++;
                } while (f.j < colCount);
            }
            (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v16(0);
            f.v1.y = -(f.m + spacing);
            f.v1.x = 0.0f;
            f.v1.z = 0.0f;
            (*(PassHolder_edb60**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
            f.u10.r++;
            f.rowptr += 8;
        } while (f.u10.r <= rowLast);
    }
    (*(PassHolder_edb60**)&DAT_0052c2ac)->pass->v16(0);
    if (owner->v13(this) && obj158 != 0 && obj154 != 0) {
        if (rowFirst != 0)
            obj154->f118 = 1.0f;
        else
            obj154->f118 = 0.0f;
        if (rowLast == rowCount - 1)
            obj158->f118 = 0.0f;
        else
            obj158->f118 = 1.0f;
    }
    f.x.FUN_000f78e0();
}
