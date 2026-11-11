// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000edf60..0x000ee9b0 (kind game, layer game, confidence high), dominant class ImageSelector
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff2916d8 {
#define TREE_TU_END }
namespace fn_ff2916d8 {} using namespace fn_ff2916d8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff2916d8 {
extern void* hulk_at_0040c6f4[];
extern void* hulk_at_0040c208[];
class Ref_ee000 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Pool_ee000 {
};
struct Mgr_ee000 {
    char pad[8];
    Pool_ee000* pool;
};
struct Item_ee000 {
    char pad[0x18];
    int f;
};
struct Sub_ee000 {
};
class ImageSelector_ee000 {
  public:
    void* vptr;
    char pad0[0x14];
    Sub_ee000 sub;
    char pad1[0x50 - 0x19];
    Ref_ee000* m50;
    char pad2[0xc];
    Ref_ee000* m60;
    Ref_ee000* m64;
    char pad3[0xa8 - 0x68];
    Mgr_ee000* ma8;
    void* mac;
    char pad4[0x150 - 0xb0];
    Ref_ee000* arr[8][8];
    char pad5[0x2ac - 0x250];
    Item_ee000* m2ac;
    void f();
};
struct ImageSelector_nv_ee180 {
};
extern void FUN_000c8710(void*, int);
void* thunk_FUN_0008d690(unsigned int size);
struct Vec3_ee340 {
    float x;
    float y;
    float z;
};
struct OffsetFrame_ee340 {
    Vec3_ee340 translation;
    unsigned row;
};
struct Dev1 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void v15(unsigned a);
    virtual void v16(unsigned a);
};
struct Ctx_ee340 {
    Dev1* dev;
    void FUN_00293d00(hulk_uintptr a);
    void FUN_00293da0(unsigned a, unsigned b, unsigned c);
};
} // namespace fn_ff2916d8
struct Gfx {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual unsigned v30(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e);
    virtual void v31(unsigned a);
};
namespace fn_ff2916d8 {
struct Obj14_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void v14(unsigned out, unsigned who);
    virtual void v15(unsigned out, unsigned who);
    virtual float v16(unsigned who);
    virtual float v17(unsigned who);
    virtual void s18();
    virtual void s19();
    virtual unsigned v20();
};
struct Objr {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual unsigned v51();
};
struct Objs_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual unsigned v44();
};
struct Obj50_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void v8(unsigned a, unsigned b);
};
struct Obj10_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void v5(unsigned a, unsigned b);
    virtual void v6(unsigned a, unsigned b);
};
struct NewObj_ee340 {
    virtual void v0();
    virtual void v1();
    char padding[12];
    Obj10_ee340* content;
};
struct Fmt {
    Fmt* FUN_0028edb0();
};
struct Z {
    char padding[8];
    Vec3_ee340* position;
    char padding2[4];
    unsigned* color;
    float* uv;
    void FUN_0008ef00();
};
struct Fmt7 {
    void FUN_000f7fe0(hulk_uintptr a);
};
struct Fmt8 {
    void FUN_000f80e0(hulk_uintptr a, unsigned b, unsigned c);
};
struct Fmt9 {
    void FUN_000f78e0();
};
struct CaptionEntry_ee340 {
    float scale;
    unsigned enabled;
    unsigned kind;
    unsigned reserved;
};
struct Caption_ee340 {
    char header[8];
    CaptionEntry_ee340 entries[8];
    unsigned selectedEntry;
    char tail[4];
};
struct SelectorView_ee340 {
    char beforeOwner[0x14];
    Obj14_ee340* owner;
    char beforeFlags[0x28];
    unsigned char drawFirst;
    char beforeSecond[7];
    unsigned char drawSecond;
    char afterSecond[3];
    unsigned secondImage;
    Obj50_ee340* overlay;
    unsigned transformA;
    unsigned transformB;
    unsigned transformC;
    char beforeVisibility[0x14];
    unsigned char visible;
    char beforePosition[3];
    Vec3_ee340 position;
    char beforeFirstImage[0xc4];
    unsigned firstImage;
    char beforeCells[4];
    unsigned cells[64];
    unsigned char captions[64];
    char beforeDimensions[4];
    int rows;
    int columns;
    float cellWidth;
    float cellHeight;
    char beforeSelection[4];
    unsigned selectedCell;
};
extern int DAT_00584554;
void FUN_000e11a0(float x, float y, float z, unsigned image, int mode);
void FUN_000e0cc0(float x, float y, float z, unsigned image, int mode);
void FUN_000e0a90(unsigned a_edx, float x, float y, float z, float w, unsigned color);

} // namespace fn_ff2916d8

// 0x000edf60 FUN_000edf60 (90 B): matches/0x000edf60.cpp [wrapped: conflict: ImageSelector]
// sym: ??0ImageSelector@fn_000edf60@@QAE@H@Z
namespace fn_000edf60 {
class FEControl_edf60 {
  public:
    FEControl_edf60(int);
    virtual ~FEControl_edf60();
};
class ImageSelector : public FEControl_edf60 {
  public:
    char pad[0x14c];
    int b[0x40];
    char gap[0x40];
    int a[8];
    ImageSelector(int);
};
ImageSelector::ImageSelector(int arg) : FEControl_edf60(arg) {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    int* p = b;
    for (int i = 0; i < 0x40; ++i)
        p[i] = 0;
}
} // namespace fn_000edf60


// 0x000edfc0 ImageSelector::vfunc_8 (27 B): matches/0x000edfc0.cpp [wrapped: helper definitions (17 out-of-line function bodies)]
// sym: ?vfunc_8@ImageSelector@fn_000edfc0@@QAEMXZ
namespace fn_000edfc0 {
class ImageSelector {
  public:
    char pad[0x14];
    struct Obj {
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
        virtual void p(float*, ImageSelector*);
    }* mControl;
    float vfunc_8();
};
void ImageSelector::Obj::a() {}
void ImageSelector::Obj::b() {}
void ImageSelector::Obj::c() {}
void ImageSelector::Obj::d() {}
void ImageSelector::Obj::e() {}
void ImageSelector::Obj::f() {}
void ImageSelector::Obj::g() {}
void ImageSelector::Obj::h() {}
void ImageSelector::Obj::i() {}
void ImageSelector::Obj::j() {}
void ImageSelector::Obj::k() {}
void ImageSelector::Obj::l() {}
void ImageSelector::Obj::m() {}
void ImageSelector::Obj::n() {}
void ImageSelector::Obj::o() {}
void ImageSelector::Obj::p(float*, ImageSelector*) {}
float ImageSelector::vfunc_8() {
    char x[12];
    mControl->p((float*)x, this);
    return *(float*)(x + 4);
}
} // namespace fn_000edfc0

namespace fn_ff2916d8 {

// 0x000ee000 FUN_000ee000 (185 B): matches/0x000ee000.cpp
// sym: ?f@ImageSelector_ee000@fn_ff2916d8@@QAEXXZ
void ImageSelector_ee000::f() {
    Item_ee000* it = m2ac;
    vptr = hulk_at_0040c6f4;
    if (it) {
        ((owners::Obj_f8c30 *)(ma8->pool))->FUN_000f8c30((const char *)(&it->f));
        m2ac = 0;
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (arr[i][j]) {
                arr[i][j]->Release();
                arr[i][j] = 0;
            }
    vptr = hulk_at_0040c208;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete(mac);
        mac = 0;
    }
    ((owners::Thing_f7960 *)&sub)->FUN_000f7960();
}

} // namespace fn_ff2916d8

// 0x000ee0c0 ImageSelector::vfunc_20 (178 B): equivalent/0x000ee0c0.cpp [wrapped: conflict: ImageSelector]
// sym: ?vfunc_20@ImageSelector@fn_000ee0c0@@QAEXPAUItem_ee0c0@2@_N@Z @1896516dae7c @w67d5918d48d8
namespace fn_000ee0c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// ImageSelector::vfunc_20 @ 0x000ee0c0
struct Item_ee0c0 { virtual void vfunc_0(); };
struct Receiver_ee0c0 { void FUN_000f8b90(int value); };
struct ImageSelector {
 virtual void vfunc_0();
 char pad[0x150-4];
 Item_ee0c0* cells[8][8];
 char gap250[0x40];
 int count;
 int field294;
 int width;
 char gap[8];
 int selected;
 int current;
 Receiver_ee0c0* receiver;
 void vfunc_20(Item_ee0c0* item, bool select);
};
void ImageSelector::vfunc_20(Item_ee0c0* item, bool select) {
 if (!item) return;
 int row = -1, col = -1;
 for (int r=0;r<8;++r) {
  for (int c=0;c<8;++c) {
   if (!cells[r][c]) {
    cells[r][c]=item;
    item->vfunc_0();
    row=r; col=c;
    break;
   }
  }
 }
 if (row == -1 || col == -1) return;
 if (select) {
  int index=width*row+col;
  current=index;
  selected=index;
  if (receiver) receiver->FUN_000f8b90(index);
  vfunc_0();
 }
 ++count;
}
} // namespace fn_000ee0c0


// 0x000ee180 ImageSelector::vfunc_19 (124 B): matches/0x000ee180.cpp
// sym: ?vfunc_19@ImageSelector@@UAEXHHHHH@Z
void ImageSelector::vfunc_19(int p2, int p3, int p4, int p5, int __p4) { char p6 = (char)__p4;

    if (p2 && p3 >= 0 && p3 < 8 && p4 >= 0 && p4 < 8) {
        FUN_000c8710((char*)this + 0x150 + (p4 + p3 * 8) * 4, p2);
        *((char*)this + 0x250 + p4 + p3 * 8) = (char)p5;
        if (p6) {
            *(int*)((char*)this + 0x2a4) = *(int*)((char*)this + 0x2a8) =
                *(int*)((char*)this + 0x298) * p3 + p4;
            ((::ImageSelector *)(((ImageSelector_nv_ee180*)this)))->FUN_000e4020();
        }
        ++*(int*)((char*)this + 0x290);
    }
}


// 0x000ee200 ImageSelector::vfunc_21 (51 B): matches/0x000ee200.cpp [wrapped: conflict: ImageSelector]
// sym: ?v21@ImageSelector@fn_000ee200@@UAEXXZ
namespace fn_000ee200 {
class Ref_ee200 {
  public:
    virtual void f0();
    virtual void f1();
};
class ImageSelector {
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
    char pad[0x150 - 4];
    Ref_ee200* items[64];
};
void ImageSelector::v21() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (items[i * 8 + j]) {
                items[i * 8 + j]->f1();
                items[i * 8 + j] = 0;
            }
}
} // namespace fn_000ee200


// 0x000ee240 ImageSelector::vfunc_22 (83 B): matches/0x000ee240.cpp [wrapped: conflict: ImageSelector]
// sym: ?vfunc_22@ImageSelector@fn_000ee240@@UAEXH@Z
namespace fn_000ee240 {
class Receiver {
  public:
    void notify_000f8b90(int);
};
class ImageSelector {
  public:
    virtual void changed();
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void vfunc_22(int);
    virtual void f23();
    char pad[0x14c];
    void* images[0x51];
    int rows;
    int cols;
    char pad2[0xc];
    int selected;
    Receiver* receiver;
};
void ImageSelector::vfunc_22(int n) {
    if (n >= 0 && n < rows * cols && images[n % cols + (n / cols) * 8]) {
        selected = n;
        if (receiver)
            receiver->notify_000f8b90(n);
        changed();
    }
}
} // namespace fn_000ee240


// 0x000ee2a0 ImageSelector::vfunc_3 (158 B): matches/0x000ee2a0.cpp [wrapped: conflict: ImageSelector]
// sym: ?vfunc_3@ImageSelector@fn_000ee2a0@@UAEXXZ
namespace fn_000ee2a0 {
// ImageSelector::vfunc_3 @ 0x000ee2a0
// ImageSelector::vfunc_3 @ 0x000ee2a0: recompute cell size and origin from the owner's reported extent
struct Vec3_ee2a0 {
    float x, y, z;
};

class FEControl_ee2a0;

class Owner_ee2a0 {
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
    virtual void GetExtent(Vec3_ee2a0 *out, FEControl_ee2a0 *who);
};

class FEControl_ee2a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner_ee2a0 *owner;
};

class ImageSelector : public FEControl_ee2a0 {
public:
    virtual void vfunc_3();
    char pad18[0x78 - 0x18];
    float originX;
    float originY;
    char pad80[0x294 - 0x80];
    int rows;
    int columns;
    float cellW;
    float cellH;
};

void ImageSelector::vfunc_3()
{
    Vec3_ee2a0 s;
    FEControl_ee2a0::vfunc_3();
    owner->GetExtent(&s, this);
    cellW = s.x / columns;
    owner->GetExtent(&s, this);
    cellH = s.y / rows;
    owner->GetExtent(&s, this);
    originX = cellW * 0.5f - s.x * 0.5f;
    owner->GetExtent(&s, this);
    originY = s.y * 0.5f - cellH * 0.5f;
}
} // namespace fn_000ee2a0


// 0x000ee340 ImageSelector::vfunc_5 (1644 B): equivalent/0x000ee340.cpp
// sym: ?vfunc_5@ImageSelector@@UAEXXZ @74e609eb4cc8 @w83c0f583c541
// STATUS: equivalent (tools/equiv.py level 3: 4231 inputs, branch coverage 28/28)
// ImageSelector::vfunc_5 @ 0x000ee340
// ImageSelector::vfunc_5: draw the image grid, selection highlight and captions.
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-conv: FUN_000e0a90 edx stack stack stack stack stack
void ImageSelector::vfunc_5() {
    SelectorView_ee340* selector = (SelectorView_ee340*)this;
    OffsetFrame_ee340 frame;
    Vec3_ee340 imagePosition;
    Vec3_ee340 step;
    Caption_ee340 caption;

    if (!selector->visible)
        return;

    if (selector->drawFirst == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((hulk_uintptr)&frame.translation, (hulk_uintptr)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&frame.translation);
        selector->owner->v15((hulk_uintptr)&imagePosition, (hulk_uintptr)this);
        unsigned image = selector->firstImage;
        FUN_000e11a0(imagePosition.x, imagePosition.y, imagePosition.z, image, 2);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    if (selector->drawSecond == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((hulk_uintptr)&frame.translation, (hulk_uintptr)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&frame.translation);
        selector->owner->v15((hulk_uintptr)&imagePosition, (hulk_uintptr)this);
        unsigned image = selector->secondImage;
        FUN_000e0cc0(imagePosition.x, imagePosition.y, imagePosition.z, image, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    if (selector->overlay) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((hulk_uintptr)&frame.translation, (hulk_uintptr)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&frame.translation);
        (*(Ctx_ee340**)&DAT_0052c2ac)
            ->FUN_00293da0(selector->transformA, selector->transformB, selector->transformC);
        selector->overlay->v8(0, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
    selector->owner->v14((hulk_uintptr)&frame.translation, (hulk_uintptr)this);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&frame.translation);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&selector->position);

    if (selector->rows > 0) {
        frame.row = 0;
        unsigned char* captionRow = selector->captions;
        unsigned* cellRow = selector->cells;
        do {
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
            unsigned column = 0;
            unsigned* cell = cellRow;
            if (selector->columns > 0) {
                do {
                    if (*cell) {
                        void* memory = thunk_FUN_0008d690(0x20);
                        NewObj_ee340* formatted = memory ? (NewObj_ee340*)((Fmt*)memory)->FUN_0028edb0() : 0;
                        formatted->v0();
                        formatted->content->v6(0x444d4c42, 1);
                        hulk_uintptr currentCell = *cell;
                        unsigned label = currentCell ? *(unsigned*)(currentCell + 0x10) : 0;
                        formatted->content->v5(((unsigned)0x584554), label);

                        hulk_uintptr texture = (hulk_uintptr)formatted->content;
                        volatile float width = selector->cellWidth * 0.8f;
                        volatile float height = selector->cellHeight * 0.8f;
                        volatile float left = width * -0.5f;
                        volatile float right = width * 0.5f;
                        volatile float top = height * 0.5f;
                        volatile float bottom = height * -0.5f;
                        hulk_uintptr vertexData = DAT_0052c2a8->v30(texture, 0, 0x2021, 6, 0);
                        if (vertexData) {
                            Z* vertices = (Z*)vertexData;
                            for (int vertex = 0; vertex < 6; ++vertex) {
                                int corner = vertex == 0 || vertex == 3 ? 0
                                             : vertex == 1              ? 1
                                             : vertex == 5              ? 3
                                                                        : 2;
                                float x = corner == 0 || corner == 1 ? left : right;
                                float y = corner == 0 || corner == 3 ? bottom : top;
                                float u = corner == 0 || corner == 1 ? 0.0f : 1.0f;
                                float v = corner == 0 || corner == 3 ? 0.0f : 1.0f;
                                Vec3_ee340* position = vertices->position;
                                position->x = x;
                                position->y = y;
                                position->z = 0.0f;
                                *vertices->color = 0xffffffff;
                                float* uv = vertices->uv;
                                uv[0] = u;
                                uv[1] = v;
                                vertices->FUN_0008ef00();
                            }
                        }
                        DAT_0052c2a8->v31(vertexData);
                        formatted->v1();

                        if (selector->selectedCell == selector->columns * frame.row + column) {
                            FUN_000e0a90(1, selector->cellWidth * 0.8f, selector->cellHeight * 0.8f, 1.0f,
                                         0.02f, 0xff51c4ff);
                        }
                        if (captionRow[column]) {
                            hulk_uintptr text = selector->owner->v20();
                            text = ((Objr*)text)->v51();
                            text = ((Objs_ee340*)text)->v44();
                            ((Fmt7*)&caption)->FUN_000f7fe0(text);
                            volatile float verticalScale = selector->owner->v17((hulk_uintptr)this);
                            float horizontalScale = selector->owner->v16((hulk_uintptr)this);
                            caption.entries[caption.selectedEntry].scale = horizontalScale * verticalScale;
                            caption.entries[caption.selectedEntry].enabled = 1;
                            caption.entries[caption.selectedEntry].kind = 2;
                            ((Fmt8*)&caption)->FUN_000f80e0((hulk_uintptr)&DAT_0040b0a0, 0, 0);
                            ((Fmt9*)&caption)->FUN_000f78e0();
                        }
                    }
                    step.x = selector->cellWidth;
                    step.y = 0.0f;
                    step.z = 0.0f;
                    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&step);
                    ++column;
                    ++cell;
                } while ((int)column < selector->columns);
            }
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
            frame.translation.x = 0.0f;
            frame.translation.y = -selector->cellHeight;
            frame.translation.z = 0.0f;
            (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((hulk_uintptr)&frame.translation);
            ++frame.row;
            cellRow += 8;
            captionRow += 8;
        } while ((int)frame.row < selector->rows);
    }
    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
}

