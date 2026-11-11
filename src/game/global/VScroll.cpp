// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e21e0..0x000e2800 (kind game, layer game, confidence high), dominant class VScroll
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fdc7ca3e {
#define TREE_TU_END }
namespace fn_fdc7ca3e {} using namespace fn_fdc7ca3e;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fdc7ca3e {
class Item_e2250 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
struct Cell_e23f0 {
    float out;
    float in;
    unsigned char on;
    char pad[3];
    int spare;
};
class Spreader {
public:
    char pad0[0x30];
    float limit;
    char pad34[0x44 - 0x34];
    Cell_e23f0 cells[1];
    char pad_cells[0x240 - 0x44 - sizeof(Cell_e23f0)];
    int count;
    char pad244[0x24c - 0x244];
    int skip;
    int last;
    void FUN_000e23f0();
};
class FELayout_e2470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Child_e2470 {
  public:
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
    virtual bool f10(int, int);
};
class Child_e24a0 {
  public:
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
    virtual bool f11(int, int);
};
class VScroll_e24d0 {
  public:
    virtual void vfunc_0();
    virtual bool IsEnabled();
};
class FELayout_e24e0 {
  public:
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
};
class Child_e24e0 {
  public:
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
    virtual void o(int);
};
class VScroll_e2500 : public FELayout {
  public:
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int f13(int);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    char pad[0x254 - 0x14];
    int field;
};
struct Obj_e2500 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual int get();
};
extern "C" char DAT_0049dba4[];
extern "C" char DAT_0049f4f0[];
extern int __cdecl FUN_00344e74(int, int, const char*, const char*, int);
class FELayout_e2740 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    char pad[0x34 - 4];
};
class FELayout_e2750 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class FEObject_e2760 {
  public:
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
    virtual void f15();
    virtual void f16();
};
class FELayout_e2760 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class FELayout_e27b0 {
  public:
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
};
class FEControl_e27b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void o();
};
extern char hulk_at_0049f4f0;
extern char hulk_at_0049dba4;

} // namespace fn_fdc7ca3e

// 0x000e21e0 FUN_000e21e0 (94 B): matches/0x000e21e0.cpp [wrapped: conflict: VScroll]
// sym: ??0VScroll@fn_000e21e0@@QAE@HH@Z
namespace fn_000e21e0 {
extern int hulk_at_0040c1ac;
class VScroll {
  public:
    void init_000e1f10(int, int);
    VScroll(int a, int q);
    hulk_uintptr vf;
    char pre[0x3c];
    unsigned int arr[0x80];
    unsigned int a[7];
    char gap[0x0c];
    unsigned int b;
};
VScroll::VScroll(int a, int q) {
    init_000e1f10(a, q);
    vf = (hulk_uintptr)&hulk_at_0040c1ac;
    for (int i = 0; i < 0x80; i++)
        arr[i] = 0;
    this->a[0] = 0;
    this->a[1] = 0;
    this->a[2] = 0;
    this->a[3] = 0;
    this->a[4] = 0;
    this->a[5] = 0;
    this->b = 0;
    this->a[6] = 0;
}
} // namespace fn_000e21e0


// 0x000e2250 VScroll::vfunc_1 (45 B): matches/0x000e2250.cpp
// sym: ?vfunc_1@VScroll@@UAEXXZ
void VScroll::vfunc_1() {
    for (int i = 0; i < this->f_240; ++i)
        ((Item_e2250**)((char*)this + 0x40))[i * 4]->f4();
}


// 0x000e2280 VScroll::vfunc_2 (360 B): equivalent/0x000e2280.cpp [wrapped: conflict: FELayout; VScroll]
// sym: ?vfunc_2@VScroll@fn_000e2280@@UAEXXZ @cb867981fe79 @w4b27edc9e55a
namespace fn_000e2280 {
// STATUS: equivalent (tools/equiv.py level 3: 19494 inputs, branch coverage 8/8)
// VScroll::vfunc_2 @ 0x000e2280

struct V3_e2280 {
    float x, y, z;
};

class Pen_e2280 {
public:
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
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};

struct Renderer_e2280 {
    Pen_e2280* pen;
    void FUN_00293d00(const V3_e2280* v);
    void FUN_00293da0(V3_e2280 axis);
    void FUN_00293bf0(float angle);
};

class Child_e2280 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void vfunc_8(int a, int b);
};

class Widget_e2280 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void vfunc_5();
};

struct Item_e2280 {
    Widget_e2280* obj;
    int pad[2];
    char active;
    char pad2[3];
};

struct Anchor_e2280 {
    const V3_e2280* FUN_000f6370(V3_e2280* out);
};

void __cdecl FUN_000e11a0(V3_e2280 size, int color, int mode);

class FELayout {
public:
    virtual void a0();
    virtual void a1();
};

class VScroll : public FELayout {
public:
    virtual void vfunc_2();
    char pad04[0x14];
    Anchor_e2280 anchor;
    char pad19[0x17];
    float height;
    char pad34[0xc];
    Item_e2280 items[32];
    int itemCount;
    char pad244[0x10];
    float width;
    Child_e2280* child;
    V3_e2280 axis;
};

void VScroll::vfunc_2()
{
    V3_e2280 v;

    if (child != 0) {
        (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_15(0);
        { const V3_e2280 *anchorPos = anchor.FUN_000f6370(&v); (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(anchorPos); }
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.01f;
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(&v);
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293da0(axis);
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
        child->vfunc_8(0, 0);
        (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_16(0);
    }

    for (int i = 0; i < itemCount; i++) {
        if (items[i].active)
            items[i].obj->vfunc_5();
    }

    (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_15(0);
    { const V3_e2280 *anchorPos = anchor.FUN_000f6370(&v); (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(anchorPos); }
    V3_e2280 size;
    size.x = width * 1.1f;
    size.y = height * 1.1f;
    size.z = 0.0f;
    FUN_000e11a0(size, -256, 2);
    (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_16(0);
}
} // namespace fn_000e2280

namespace fn_fdc7ca3e {

// 0x000e23f0 FUN_000e23f0 (117 B): matches/0x000e23f0.cpp
// sym: ?FUN_000e23f0@Spreader@fn_fdc7ca3e@@QAEXXZ
// FUN_000e23f0 @ 0x000e23f0
void Spreader::FUN_000e23f0()
{
    hulk_freg acc = 0.0f;
    for (int i = 0; i < count; i++) {
        if (i < skip) {
            cells[i].on = 0;
            *(int *)&cells[i].out = 0;
        } else {
            acc = cells[i].in * 1.05f + acc;
            if (acc > limit) {
                cells[i].on = 0;
                *(int *)&cells[i].out = 0;
            } else {
                cells[i].on = 1;
                cells[i].out = acc - cells[i].in * 0.5f;
                last = i;
            }
        }
    }
}

} // namespace fn_fdc7ca3e

// 0x000e2470 VScroll::vfunc_5 (41 B): matches/0x000e2470.cpp
// sym: ?vfunc_5@VScroll@@UAE_NHH@Z
bool VScroll::vfunc_5(int a, int b) {
    if ((*(Child_e2470 * *)&this->f_244) && (*(Child_e2470 * *)&this->f_244)->f10(a, b))
        return true;
    return false;
}


// 0x000e24a0 VScroll::vfunc_6 (41 B): matches/0x000e24a0.cpp
// sym: ?vfunc_6@VScroll@@UAE_NHH@Z
bool VScroll::vfunc_6(int a, int b) {
    if ((*(Child_e24a0 * *)&this->f_244) && (*(Child_e24a0 * *)&this->f_244)->f11(a, b))
        return true;
    return false;
}

namespace fn_fdc7ca3e {

// 0x000e24d0 VScroll::vfunc_19 (3 B): matches/0x000e24d0.cpp
// sym: ?IsEnabled@VScroll_e24d0@fn_fdc7ca3e@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool VScroll_e24d0::IsEnabled() {
    return true;
}

} // namespace fn_fdc7ca3e

// 0x000e24e0 VScroll::vfunc_9 (20 B): matches/0x000e24e0.cpp
// sym: ?vfunc_9@VScroll@@UAEXH@Z
void VScroll::vfunc_9(int x) {
    if ((*(Child_e24e0 * *)&this->f_244))
        (*(Child_e24e0 * *)&this->f_244)->o(x);
}

namespace fn_fdc7ca3e {

// 0x000e2500 VScroll::vfunc_13 (45 B): matches/0x000e2500.cpp
// sym: ?f13@VScroll_e2500@fn_fdc7ca3e@@UAEHH@Z
int VScroll_e2500::f13(int p) {
    Obj_e2500* h = *(Obj_e2500**)((char*)this + 8);
    return h->get() == (hulk_intptr)this && field == p;
}

} // namespace fn_fdc7ca3e

// 0x000e2530 VScroll::vfunc_18 (174 B): matches/0x000e2530.cpp
// sym: ?vfunc_18@VScroll@@UAEXPAX@Z
void VScroll::vfunc_18(void* __p0) { void * item = (void *)__p0;

    if (this->f_240 < 0x20) {
        ((hulk_intptr*)((char*)this + (this->f_240 + 4) * 16))[0] = (hulk_intptr)item;
        ((int*)((char*)this + 0x48 + this->f_240 * 16))[0] = 0;
        if (!(*(int *)&this->f_244)) {
            if (FUN_00344e74(((int*)((char*)this + (this->f_240 + 4) * 16))[0], 0, (const char*)((hulk_intptr)DAT_0049dba4),
                             (const char*)((hulk_intptr)DAT_0049f4f0), 0))
                (*(int *)&this->f_244) = FUN_00344e74(((int*)((char*)this + (this->f_240 + 4) * 16))[0], 0, (const char*)((hulk_intptr)DAT_0049dba4),
                                        (const char*)((hulk_intptr)DAT_0049f4f0), 0);
        }
        ++this->f_240;
        if (this->f_240 > 1)
            ++this->f_268;
    }
}


// 0x000e25e0 VScroll::vfunc_14 (197 B): equivalent/0x000e25e0.cpp [wrapped: conflict: VScroll]
// sym: ?vfunc_14@VScroll@fn_000e25e0@@UAEPAUVec3_e25e0@2@PAU32@H@Z @bd9cc7799243 @w921a1a72bcc9
namespace fn_000e25e0 {
// STATUS: equivalent (tools/equiv.py level 3: 384 inputs, branch coverage 8/8)
// VScroll::vfunc_14 @ 0x000e25e0
struct Vec3_e25e0 { float x,y,z; };
struct Transform_e25e0 { Vec3_e25e0* FUN_000f6370(Vec3_e25e0* out); char data[0x18]; };
struct Item_e25e0 { int id; float y; int unused; unsigned char enabled; char pad[3]; };
struct VScroll {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual Vec3_e25e0* vfunc_14(Vec3_e25e0* out,int id);
 char pad04[0x14]; Transform_e25e0 transform; float height; char pad34[0xc]; Item_e25e0 items[32]; int count;
};
Vec3_e25e0* VScroll::vfunc_14(Vec3_e25e0* out,int id) {
 int i; for(i=0;i<count;++i) if(items[i].id==id) break;
 if(i>=count) { out->z=0.0f; out->x=0.0f; out->y=0.0f; return out; }
 Item_e25e0& item=items[i];
 if(!item.enabled) { out->z=-1.0f; out->x=0.0f; out->y=0.0f; return out; }
 Vec3_e25e0 temp, temp2;
 Vec3_e25e0* p=transform.FUN_000f6370(&temp);
 float y=height*0.5f+p->y-item.y;
 p=transform.FUN_000f6370(&temp);
 float z=p->z;
 p=transform.FUN_000f6370(&temp2);
 out->x=p->x; out->z=z; out->y=y; return out;
}
} // namespace fn_000e25e0


// 0x000e26b0 VScroll::vfunc_15 (141 B): matches/0x000e26b0.cpp [wrapped: conflict: VScroll]
// sym: ?FUN_000e26b0@VScroll@fn_000e26b0@@QAEXPAUVec3_e26b0@2@H@Z
namespace fn_000e26b0 {
// VScroll::vfunc_15 @ 0x000e26b0
// VScroll: position of the item with the given key: x from the layout origin, y = the item's stored
// value, z from the layout size; all zero when the key is unknown.
struct Vec3_e26b0 {
    float x, y, z;
};

class Layout_e26b0 {
public:
    char pad0[0x28];
    Vec3_e26b0* FUN_000f6370(Vec3_e26b0* out);
};

struct Item_e26b0 {
    int key;
    int pad4;
    float value;
    int padc;
};

struct Frame_e26b0 {
    float savedZ;
    Vec3_e26b0 first;
    Vec3_e26b0 second;
};

class VScroll {
public:
    char pad0[0x18];
    Layout_e26b0 layout;
    Item_e26b0 items[0x20];
    int itemCount;

    void FUN_000e26b0(Vec3_e26b0* out, int key);
};

void VScroll::FUN_000e26b0(Vec3_e26b0* out, int key)
{
    for (int i = 0; i < itemCount; i++) {
        if (items[i].key == key) {
            Frame_e26b0 f;
            f.savedZ = layout.FUN_000f6370(&f.first)->z;
            float y = items[i].value;
            float x = layout.FUN_000f6370(&f.second)->x;
            out->x = x;
            out->y = y;
            out->z = f.savedZ;
            return;
        }
    }
    out->x = 0;
    out->y = 0;
    out->z = 0;
}
} // namespace fn_000e26b0


// 0x000e2740 VScroll::vfunc_16 (6 B): matches/0x000e2740.cpp
// sym: ?vfunc_16@VScroll@@UAEMH@Z
// Same code shape as 0x000e21a0 (propagated; names are from that function)
hulk_freg VScroll::vfunc_16(int ) {
    return this->f_34;
}


// 0x000e2750 VScroll::vfunc_17 (6 B): matches/0x000e2750.cpp
// sym: ?vfunc_17@VScroll@@UAEMH@Z
// Same code shape as 0x000e21b0 (propagated; names are from that function)
hulk_freg VScroll::vfunc_17(int ) {
    return this->f_38;
}


// 0x000e2760 VScroll::vfunc_12 (74 B): matches/0x000e2760.cpp
// sym: ?vfunc_12@VScroll@@UAEXXZ
void VScroll::vfunc_12() {
    for (int i = 0; i < this->f_240; ++i) {
        FEObject_e2760* p = ((FEObject_e2760 *)__RTDynamicCast(*(void**)((char*)this + 0x40 + i * 16), 0, (void*)(((hulk_intptr)DAT_0049dba4)), (void*)(((hulk_intptr)DAT_0049f4f0)), 0));
        if (p)
            p->f16();
    }
}


// 0x000e27b0 VScroll::vfunc_11 (74 B): matches/0x000e27b0.cpp
// sym: ?vfunc_11@VScroll@@UAEXXZ
void VScroll::vfunc_11() {
    int i = 0;
    if (this->f_240 > 0) {
        char* p = (char*)this + 0x40;
        do {
            int* q = (int*)__RTDynamicCast((void*)*(hulk_intptr*)p, 0, &hulk_at_0049dba4, &hulk_at_0049f4f0, 0);
            if (q)
                ((FEControl_e27b0*)q)->o();
            ++i;
            p += 0x10;
        } while (i < this->f_240);
    }
}

