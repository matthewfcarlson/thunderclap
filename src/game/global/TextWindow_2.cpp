// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ecd70..0x000ed820 (kind game, layer game, confidence high), dominant class TextWindow
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_fc766a14 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc766a14 {} using namespace fn_fc766a14;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fc766a14 {
struct Vec3_ecdf0 {
    int pad;
    float x;
    float y;
};
struct X_ecdf0 {
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
    virtual void p(Vec3_ecdf0*, void*);
};
struct TextWindow;
struct Sub_ece20 {
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
    virtual void f15(float*, TextWindow*);
};
struct TextWindow {
  public:
    char _m_pad_0[0x14];
    union { X_ecdf0* obj; Sub_ece20* sub; };
    hulk_freg vfunc_8();
    hulk_freg vfunc_9();
};
class Obj_ece40 {
  public:
    virtual void x();
    virtual void Release();
};
extern char hulk_at_0040c64c[];
extern char hulk_at_0040c42c[];
void destroy_0008d340(void*);
class Target_ece40 {
  public:
    char pad[0x154];
    Obj_ece40* a;
    Obj_ece40* b;
    void* c;
    void Finish_000e9030();
};

} // namespace fn_fc766a14

// 0x000ecd70 FUN_000ecd70 (125 B): equivalent/0x000ecd70.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ??0TextWindow@fn_000ecd70@@QAE@H@Z @a66726eb2984 @w05e67a56d782
namespace fn_000ecd70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000ecd70 @ 0x000ecd70
// equiv-map: ??0WindowBase@@QAE@H@Z = 0x000e9240


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int);
#endif


class FEControl_ecd70 {
public:
    FEControl_ecd70(int arg) throw();
    virtual void vfunc_0();
    char pad04[0x150 - 4];
};

class TextWindow : public FEControl_ecd70 {
public:
    int f150, f154, f158, f15c, f160;
    int cells[0x200];       // 0x164
    int f964;
    char pad968[4];
    int f96c, f970, f974;
    int serial;             // 0x978
    float f97c;
    TextWindow(int arg) throw();
    virtual void vfunc_0();
};

TextWindow::TextWindow(int arg) throw()
    : FEControl_ecd70(arg)
{
    f150 = 0;
    f154 = 0;
    f158 = 0;
    f15c = 0;
    f160 = 0;
    memset(cells, 0, sizeof(cells));
    serial = DAT_004a0fe8++;
    f964 = 0;
    f96c = 0;
    f970 = 0;
    f974 = 0;
    f97c = 1.0f;
}
} // namespace fn_000ecd70

namespace fn_fc766a14 {

// 0x000ecdf0 TextWindow::vfunc_8 (33 B): matches/0x000ecdf0.cpp
// sym: ?vfunc_8@TextWindow@fn_fc766a14@@QAEMXZ
hulk_freg TextWindow::vfunc_8() {
    Vec3_ecdf0 v;
    obj->p(&v, this);
    return v.x * 1.05f;
}


// 0x000ece20 TextWindow::vfunc_9 (32 B): matches/0x000ece20.cpp
// sym: ?vfunc_9@TextWindow@fn_fc766a14@@QAEMXZ
hulk_freg TextWindow::vfunc_9() {
    char local[12];
    sub->f15((float*)local, this);
    return *(float*)local * 1.05f;
}


// 0x000ece40 FUN_000ece40 (102 B): matches/0x000ece40.cpp
// sym: ?target@fn_fc766a14@@YIXPAVTarget_ece40@1@@Z
void __fastcall target(Target_ece40* s) {
    *(void**)s = hulk_at_0040c64c;
    if (s->c) {
        destroy_0008d340(s->c);
        s->c = 0;
    }
    if (s->a) {
        s->a->Release();
        s->a = 0;
    }
    if (s->b) {
        s->b->Release();
        s->b = 0;
    }
    *(void**)s = hulk_at_0040c42c;
    s->Finish_000e9030();
}

} // namespace fn_fc766a14

// 0x000ed360 TextWindow::vfunc_3 (159 B): equivalent/0x000ed360.cpp [wrapped: conflict: TextWindow]
// sym: ?vfunc_3@TextWindow@fn_000ed360@@UAEXXZ @12eb3636912b @w961464842dd5
namespace fn_000ed360 {
// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 0/0)
// TextWindow::vfunc_3 @ 0x000ed360
// TextWindow::vfunc_3 @ 0x000ed360: recompute the line scale from the owner's reported extent
class Metrics_ed360 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    hulk_freg FUN_000dfbf0(const char *s);
};

struct Font {
    char pad0[0x24];
    Metrics_ed360 *metrics;
};

struct LayoutEntry {
    float scale;
    int f4;
    int f8;
    int f12;
};

struct Layout_ed360 {
    Font *font;
    int f4;
    LayoutEntry entries[8];
    int index;
    float f8c;
    Layout_ed360 *FUN_000f7fe0(Font *font);
    hulk_freg FUN_000f88a0(const unsigned short *text);
    void FUN_000f78e0();
};

class Fonts_ed360 {
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
    virtual Font *v44();
};

struct Hold_ed360 {
    char pad0[4];
    Fonts_ed360 *fonts;
};

struct Vec3_ed360 {
    float x, y, z;
};

class FEControl_ed360;

class Owner_ed360 {
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
    virtual void v15(Vec3_ed360 *out, FEControl_ed360 *who);
    virtual float v16(FEControl_ed360 *who);
    virtual float v17(FEControl_ed360 *who);
    char pad04[8 - 4];
    Hold_ed360 *hold;
};

class FEControl_ed360 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner_ed360 *owner;
};

class TextWindow : public FEControl_ed360 {
public:
    virtual void vfunc_3();
    char pad18[0x968 - 0x18];
    float f968;
    char pad96c[0x97c - 0x96c];
    float f97c;

    void FUN_000ecf10(float v);
};

void TextWindow::vfunc_3()
{
    struct Frame {
        float k;
        Vec3_ed360 tmp;
        Layout_ed360 layout;
    } fr;

    FEControl_ed360::vfunc_3();
    fr.layout.FUN_000f7fe0(owner->hold->fonts->v44());
    fr.k = owner->v17(this);
    fr.layout.entries[fr.layout.index].scale = owner->v16(this) * fr.k;
    f968 = 14.0f * fr.layout.entries[fr.layout.index].scale;
    owner->v15(&fr.tmp, this);
    FUN_000ecf10(fr.tmp.x * f97c);
    fr.layout.FUN_000f78e0();
}
} // namespace fn_000ed360


// 0x000ed400 TextWindow::vfunc_5 (1053 B): equivalent/0x000ed400.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?vfunc_5@TextWindow@fn_000ed400@@UAEXXZ @6e0859d495ab @wa0f6e73ad254
namespace fn_000ed400 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 28/28)
// TextWindow::vfunc_5 @ 0x000ed400

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
} // namespace fn_000ed400

