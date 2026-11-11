// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ed820..0x000edf60 (kind game, layer game, confidence high), dominant class TextTable
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#define TREE_TU_BEGIN namespace fn_faf882a3 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faf882a3 {} using namespace fn_faf882a3;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faf882a3 {
class Elem_ed820 {
  public:
    void Init_000f7930();
    char d[0x24];
};
class FEControl_ed820 {
  public:
    FEControl_ed820(int);
    virtual void X();
    char pad[0x14c];
};
class TextTable : public FEControl_ed820 {
  public:
    virtual void X();
    int m150, m154, m158;
    Elem_ed820 arr[0x200];
    int a, b, c, d;
    float e;
    float f[8];
    TextTable(int);
};


// 0x000ed820 FUN_000ed820 (160 B): matches/0x000ed820.cpp
// sym: ??0TextTable@fn_faf882a3@@QAE@H@Z
TextTable::TextTable(int x) : FEControl_ed820(x) {
    for (int i = 0; i < 0x200; i++)
        arr[i].Init_000f7930();
    m150 = 0;
    m154 = 0;
    m158 = 0;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0.1f;
    for (int j = 0; j < 8; j++)
        f[j] = 1.0f;
}

} // namespace fn_faf882a3

// 0x000ed8c0 TextTable::vfunc_8 (33 B): matches/0x000ed8c0.cpp [wrapped: conflict: TextTable]
// sym: ?vfunc_8@TextTable@fn_000ed8c0@@QAEMXZ
namespace fn_000ed8c0 {
// Same code shape as 0x000ecdf0 (propagated; names are from that function)
struct Vec3_ed8c0 {
    int pad;
    float x;
    float y;
};
struct X_ed8c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p(Vec3_ed8c0*, void*);
};
struct TextTable {
    char pad[20];
    X_ed8c0* obj;
    hulk_freg vfunc_8();
};
hulk_freg TextTable::vfunc_8() {
    Vec3_ed8c0 v;
    obj->p(&v, this);
    return v.x * 1.05f;
}
} // namespace fn_000ed8c0


// 0x000ed8f0 TextTable::vfunc_9 (32 B): matches/0x000ed8f0.cpp [wrapped: conflict: TextTable]
// sym: ?vfunc_9@TextTable@fn_000ed8f0@@QAEMXZ
namespace fn_000ed8f0 {
// Same code shape as 0x000ece20 (propagated; names are from that function)
struct TextTable;
struct Sub_ed8f0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15(float*, TextTable*);
};
struct TextTable {
    char pad[0x14];
    Sub_ed8f0* sub;
    hulk_freg vfunc_9();
};
hulk_freg TextTable::vfunc_9() {
    char local[12];
    sub->f15((float*)local, this);
    return *(float*)local * 1.05f;
}
} // namespace fn_000ed8f0


// 0x000ed990 TextTable::vfunc_3 (453 B): equivalent/0x000ed990.cpp [wrapped: conflict: TextTable]
// sym: ?vfunc_3@TextTable@fn_000ed990@@UAEXXZ
namespace fn_000ed990 {
// STATUS: equivalent (tools/equiv.py level 3: 19737 inputs, branch coverage 22/22)
// TextTable::vfunc_3 @ 0x000ed990
struct Vec3_ed990 {
    float x, y, z;
};

union Word_ed990 {
    float f;
    int i;
    unsigned int u;
};

struct BCell_ed990 {
    Word_ed990 a, b, c, d;
};

struct Source_ed990;

struct Builder {
    unsigned int hdr[2];
    BCell_ed990 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_ed990 *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
    float FUN_000f8840(void *cell);
};

class Source_ed990 {
public:
    virtual void v0();
};

class Level2_ed990 {
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
    virtual Source_ed990* v44();
};

struct Level1_ed990 {
    char pad0[4];
    Level2_ed990 *level2;
};

class TextTable;

class Owner_ed990 {
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
    virtual void v14(Vec3_ed990 *out, TextTable *obj);
    virtual void v15(Vec3_ed990 *out, TextTable *obj);
    virtual float v16(TextTable *obj);
    virtual float v17(TextTable *obj);
    char pad04[4];
    Level1_ed990 *p8;
};


struct Cell_ed990 {
    char pad00[0x24];
};

class FEControl_ed990 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
};

class TextTable : public FEControl_ed990 {
public:
    virtual void vfunc_3();
    char pad04[0x10];
    Owner_ed990 *owner;
    char pad18[0x7c - 0x18];
    float f7c;
    char pad80[0x15c - 0x80];
    Cell_ed990 cells[64][8];
    int rowCount;
    int colCount;
    int rowFirst;
    int rowLast;
    float spacing;
};

void TextTable::vfunc_3()
{
    FEControl_ed990::vfunc_3();

    Builder x;
    x.FUN_000f7fe0(owner->p8->level2->v44());
    float t = owner->v17(this);
    x.cells[x.cursor].a.f = owner->v16(this) * t;

    int lastRow = 0;
    if (rowCount > 0) {
        Cell_ed990 *row = &cells[0][0];
        float used = 0.0f;
        int i = 0;
        do {
            float widest = 0.0f;
            Cell_ed990 *c = row;
            for (int j = 0; j < colCount; j++) {
                float w = x.FUN_000f8840(c);
                if (w > widest)
                    widest = w;
                c++;
            }
            float next = widest + used + spacing;
            Vec3_ed990 size;
            owner->v15(&size, this);
            if (next >= size.y) {
                lastRow = i;
                break;
            }
            used = next;
            i++;
            row += 8;
        } while (i < rowCount);
    }

    rowFirst = 0;
    rowLast = rowCount;
    if (rowCount > lastRow)
        rowLast = lastRow - 1;

    if (rowCount > 0) {
        float widest = 0.0f;
        for (int j = 0; j < colCount; j++) {
            float w = x.FUN_000f8840(&cells[rowFirst][j]);
            if (w > widest)
                widest = w;
        }
        Vec3_ed990 size;
        owner->v15(&size, this);
        f7c = size.y * 0.5f - widest * 0.5f;
    }
    x.FUN_000f78e0();
}
} // namespace fn_000ed990


// 0x000edb60 TextTable::vfunc_5 (1015 B): equivalent/0x000edb60.cpp [wrapped: conflict: Builder; TextTable]
// sym: ?vfunc_5@TextTable@fn_000edb60@@UAEXXZ
namespace fn_000edb60 {
// STATUS: equivalent (tools/equiv.py level 3: 515 inputs, branch coverage 32/32)
// TextTable::vfunc_5 @ 0x000edb60

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
} // namespace fn_000edb60

