// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ca850..0x000cc7e0 (kind game, layer game, confidence high), dominant class HUDOverlay
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb3f3f46 {
#define TREE_TU_END }
namespace fn_fb3f3f46 {} using namespace fn_fb3f3f46;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb3f3f46 {
class X_ca850 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
    void target();
};
class C_ca860 {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void Fn(int);
    void Target();
};
struct Inner_ca930 {
};
struct Obj_ca930 {
    void* vptr;
    char pad[0x50];
};
extern void* hulk_at_0040a498;
extern void* hulk_at_0040a47c;
class Overlay_ca950 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class Overlay_ca960 {
    char pad[0x50];
};
struct Ent_caab0;
struct Sub_caab0 {
    void Tick_001d60c0();
};
struct Ent_caab0 {
    void Prep_001d62d0();
    char pad[0xec];
    Sub_caab0* sub;
};
struct Mgr_caab0 {
    Ent_caab0* Find_001def30(char*);
};
struct Mid_caab0 {
    char pad[0xc];
    Mgr_caab0* m;
    char pad2[0x10];
    void* b;
};
struct Self_caab0 {
    char pad[0xc];
    Mid_caab0* p;
};
extern int __fastcall FUN_00024280(void*, long long);
struct Vec3_cab50 {
    float x, y, z;
};
struct Pass_cab50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
struct PassHolder_cab50 {
    Pass_cab50 *pass;
    void FUN_00293d00(const Vec3_cab50 *color);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293bf0(float a);
};
class HUDOverlay_cab50 {
public:
    char pad0[0x28];
    Sprite *sprites[5][2];   // 0x28, stride 8

    void FUN_000cab50();
};
} // namespace fn_fb3f3f46
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_fb3f3f46 {
class Obj_cac30 {
  public:
    char pad[0x474];
    int value;
    void Set(int x);
};
class Obj_cac40 {
  public:
    char pad[0x498];
    int value;
    void Set(int x);
};
class Obj_cac50 {
  public:
    char pad[0x49c];
    int value;
    void Set(int x);
};
class Obj_cacc0 {
  public:
    char pad[0x504];
    int value;
    void Set(int v);
};
struct Vec_cacd0 {
    float x, y, z;
};
class Found_cacd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual Vec_cacd0* get(Vec_cacd0*);
};
class Lookup_cacd0 {
  public:
    Found_cacd0* find_001fd780(int);
};
class Owner_cacd0 {
  public:
    char pad[0x28];
    Lookup_cacd0* manager;
};
class Obj_cacd0 {
  public:
    char pad[0xc];
    Owner_cacd0* owner;
    char pad2[0x4a8];
    Vec_cacd0 result;
    void work(int);
};
class X {
  public:
    char pad[0x4c4];
    char name[64];
    void SetName(const char*);
};
class X_cad60 {
  public:
    X_cad60() {}
    void Fn();
    char pad[0x224];
    char m224;
};
class Obj_cad70 {
  public:
    char pad[0x214];
    int value;
    int Get();
};
struct Label_cad80 {
    char pad0[0xbc];
    char text[0x80];
    int f13c;
    int f140;
    int f144;
    unsigned int color;
    void FUN_000cad80(const char *src, int a, int b, float r, float g, float bl);
};
struct X_cae50 {
    char pad[0xb8];
    unsigned int value;
};
class Obj_cae80 {
  public:
    char pad[0x88];
    void* mObj;
    void Fn(float f);
};
class Sub_cae80 {
  public:
    void Fn_000c9bd0(float f);
};
struct Args_caea0 {
    int a, b, c;
};
class Inner_caea0 {
  public:
    void FnB_000c9720(Args_caea0);
};
class Obj_caea0 {
  public:
    char pad[0x88];
    Inner_caea0* m;
    void Run(Args_caea0 x);
};
class Inner_caee0 {
  public:
    void FnA_000c7ac0();
    void FnB_000c8ef0(int);
};
class Obj_caee0 {
    char pad[0x88];
    Inner_caee0* member;

  public:
    void Target(int);
};
class SubObj_caf10 {
  public:
};
class Obj_caf10 {
  public:
    char mPad[0x88];
    SubObj_caf10* mThing;
    void Target(int arg);
};
class Sub_caf30 {
  public:
    void Target_000c7af0();
};
class Obj_caf30 {
  public:
    char pad[0x88];
    Sub_caf30* m88;
    void Target();
};
class Obj_caf40 {
  public:
    void Call_000c7b00(int);
};
class Target_caf40 {
  public:
    void Fn(int);
    char pad[0x88];
    Obj_caf40* mObj;
};
struct Triple {
    int a, b, c;
};
class Worker {
  public:
    int Run_000c7b70(int x, Triple t);
};
struct V3 {
    int x, y, z;
};
class Item {
  public:
    int Fn_000c7d10(int, int);
};
class Sub_cb050 {
  public:
    void FnA_000c8010();
    void Fn();
};
class Obj_cb050 {
  public:
    char pad[0x88];
    Sub_cb050* m;
    void Target();
};
class Sub_cb060 {
  public:
    void Helper_000c80a0(int arg);
};
class Class {
  public:
    char pad[0x88];
    Sub_cb060* mPtr;
    void Wrapper(int arg);
};
class Sub_cb080 {
  public:
    void Go_000c91c0();
};
class Owner_cb080 {
  public:
    char pad[0x88];
    Sub_cb080* m;
    void Fn();
};
struct Vec {
    float x, y, z;
};
class Inner {
  public:
    void Apply_000c9090(int, V3);
    void Fn_000c8450(int, Vec);
};
class Outer {
    char pad[0x88];
    Inner* p;

  public:
    void Run(int a, V3 v);
};
class Mgr {
  public:
    int Run_000c9210(int, int, Vec, Vec);
};
struct V {
    int a, b, c;
};
class Other {
  public:
    void Fn_000c7f50(int, int);
    void Go_000c9340(int x, int y, V v);
};
class Child {
  public:
    void Run_000c9390(int, int);
};
class Parent {
    char pad[0x88];
    Child* child;

  public:
    void Go(int a, int b);
};
struct Vec3_cb190 { float x, y, z; };
struct Inner_cb190 {
    int FUN_000c93e0(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r);
};
struct Wrapper_cb190 {
    char pad00[0x88];
    Inner_cb190* inner;         // 0x88
    int Forward(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r);
};
struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x88];
    union { Obj* child; class Inner* inner; Mgr* mgr; Other* other; Item* p; Obj* ptr; };
    char _m_pad_8c[0x1d8];
    char names[8][0x40];
    void SetName(const char*);
    void Full_000caab0();
    int Go(int a, int b);
    void Fn(int a, int b);
    void Action_000c90d0(int a, int b);
    void Forward(int a, int b);
    void Run_000c9100(int);
    void Forward(int);
    int Go(int a, int b, Vec c, Vec d);
    void fn_000c8410(int, Vec3);
    void Fn(int, Vec);
};
class Wrap {
    char pad[0x88];
    Obj* obj;

  public:
    void fn(int a, Vec3 v);
};
class Sub_cb260 {
  public:
    void Fn_000c8490(int x);
};
class Obj_cb260 {
  public:
    char pad[0x88];
    Sub_cb260* m88;
    void Target(int x);
};
struct Sub_cb280 {
    char pad[0x10];
    char flag;
};
class Obj_cb280 {
  public:
    char pad[0x8c];
    Sub_cb280* m8c;
    void Set(unsigned char p);
};
class Thing {
  public:
    void Act_000c7140(int);
};
class Owner {
  public:
    char _m_pad_0[0x88];
    union { class Other* other; Worker* worker; };
    Thing* thing;
    int Do(int x, Triple t);
    void Fn(int x, int y, V v);
    void Run(int);
};
struct Segment {
    virtual void unused0(); virtual void unused1(); virtual void unused2(); virtual void unused3();
    virtual void unused4(); virtual void unused5(); virtual void unused6();
    virtual float getDivisor();
    virtual void unused8(); virtual float evaluate(void* value);
};
struct Table {
    char reserved[0x24];
    Segment* segments[1];
};
struct Object {
    Table* table;
    char reserved[0x84];
    int selected;
    hulk_freg FUN_000cb6f0(int position, int index);
};
class Curve_cb750 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual void v9();
    virtual float v10(int value);
};
struct Bank {
    char pad00[0x24];
    Curve_cb750* curves[1];         // 0x24
};
struct Slot_cb750 { float value; float pad[3]; };
struct Sampler_cb750 {
    Bank* bank;               // 0x00
    char pad04[4];
    Slot_cb750 slots[1];            // 0x08 (16 bytes each)
    char pad18[0x88 - 0x18];
    int current;              // 0x88
    hulk_freg Sample(int a, int b);
};
class Iface_cb870 {
public:
    virtual void v0();
    virtual void Release();
};
class Stoppable {
public:
    virtual void v0();
    virtual void Release();
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
    virtual void Stop();
};
struct Sub_cb870 {
    char data[0x34];
};
struct Bits_cb870 {
};
static inline void Drop(Iface_cb870 *&p)
{
    if (p != 0) {
        p->Release();
        p = 0;
    }
}
class Resources_cb870 {
public:
    char pad0[0x14];
    Iface_cb870 *r14;
    Iface_cb870 *r18;
    char pad1c[0x38];
    Sub_cb870 sub54;
    Iface_cb870 *r88;
    Iface_cb870 *r8c;
    Iface_cb870 *r90;
    char pad94[0xd0];
    Iface_cb870 *r164;
    Iface_cb870 *r168;
    char pad16c[0x2c];
    Iface_cb870 *r198;
    Iface_cb870 *r19c;
    char pad1a0[0x4];
    Iface_cb870 *r1a4;
    Iface_cb870 *r1a8;
    Iface_cb870 *r1ac;
    Iface_cb870 *r1b0;
    Iface_cb870 *r1b4;
    Iface_cb870 *r1b8;
    Iface_cb870 *a1bc[3];
    Iface_cb870 *a1c8[3];
    Iface_cb870 *a1d4[3];
    Iface_cb870 *r1e0;
    Iface_cb870 *r1e4;
    Iface_cb870 *r1e8;
    int z1ec[3];
    Iface_cb870 *r1f8;
    Iface_cb870 *a1fc[6];
    char pad214[0x4];
    Stoppable *r218;
    Iface_cb870 *r21c;
    char pad220[0x14];
    Iface_cb870 *r234;
    char pad238[0xc];
    Iface_cb870 *r244;
    Iface_cb870 *r248;
    char pad24c[0x4];
    Iface_cb870 *r250;
    Iface_cb870 *r254;
    Iface_cb870 *r258;
    Iface_cb870 *r25c;
    Iface_cb870 *r260;
    char flags264[8][0x40];
    Iface_cb870 *r464;
    Iface_cb870 *r468;
    Iface_cb870 *r46c;
    char pad470[0x30];
    Iface_cb870 *r4a0;
    Iface_cb870 *r4a4;
    Iface_cb870 *r4a8;
    Iface_cb870 *r4ac;
    Iface_cb870 *r4b0;
    Iface_cb870 *r4b4;
    char pad4b8[0x50];
    Iface_cb870 *r508;

    void FUN_000cb870(Bits_cb870 *bits);
};
extern "C" float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
class UiObj_cbc40 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float a, int b);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float a);
    virtual float v13();
    virtual void v14(float a, float b);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
};
struct UiVec_cbc40 {
    char pad0[0x24];
    UiObj_cbc40 **begin;
    UiObj_cbc40 **end;
};
struct Probe_cbc40 {
    char FUN_00092940(int id);
};
struct Pawn_cbc40 {
    char pad0[0x1b0c];
    float f1b0c;
    float f1b10;
    float f1b14;
    char pad1b18[0x1b28 - 0x1b18];
    int f1b28;
    float FUN_00036090();
};
struct Obj54_cbc40 {
};
} // namespace fn_fb3f3f46
struct World {
    char pad0[0x54];
    Obj54_cbc40 *f54;
};
namespace fn_fb3f3f46 {
class HUDOverlay_cbc40 {
public:
    char pad0[0x14];
    Pawn_cbc40 *p14;
    char pad18[0x14c - 0x18];
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    int f160;
    char pad164[4];
    UiVec_cbc40 *p168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    char pad198[4];
    UiVec_cbc40 *p19c;
    int state;
    void FUN_000caa60(const char *a, int *b);
    void FUN_000cbc40(float dt);
};


// 0x000ca850 FUN_000ca850 (8 B): matches/0x000ca850.cpp
// sym: ?target@X_ca850@fn_fb3f3f46@@QAEXXZ
void X_ca850::target() {
    f5(0);
}


// 0x000ca860 FUN_000ca860 (8 B): matches/0x000ca860.cpp
// sym: ?Target@C_ca860@fn_fb3f3f46@@QAEXXZ
void C_ca860::Target() {
    Fn(2);
}


// 0x000ca930 FUN_000ca930 (25 B): matches/0x000ca930.cpp
// sym: ?Target@fn_fb3f3f46@@YIXPAUObj_ca930@1@@Z
void __fastcall Target(Obj_ca930* self) {
    self->vptr = &hulk_at_0040a498;
    ((owners::Thing_f7960 *)(((Inner_ca930*)((char*)self + 0x54))))->FUN_000f7960();
    self->vptr = &hulk_at_0040a47c;
}

} // namespace fn_fb3f3f46

// 0x000ca950 HUDOverlay::vfunc_1 (5 B): matches/0x000ca950.cpp
// sym: ?vfunc_1@HUDOverlay@@UAEXXZ
void HUDOverlay::vfunc_1() {
    *((char*)this + 0x50) = 1;
}


// 0x000ca960 HUDOverlay::vfunc_2 (5 B): matches/0x000ca960.cpp
// sym: ?vfunc_2@HUDOverlay@@UAEXXZ
void HUDOverlay::vfunc_2() {
    *((char*)this + 0x50) = 0;
}

namespace fn_fb3f3f46 {

// 0x000caa60 FUN_000caa60 (77 B): equivalent/0x000caa60.cpp
// sym: ?FUN_000caa60@fn_fb3f3f46@@YGXPADPAH@Z @be6fe615e729 @w0c9a53ffa266
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000caa60 @ 0x000caa60
void __stdcall FUN_000caa60(char *state, int *value)
{
    if (value && state) {
        if (*state == 0) {
            int next = *value + DAT_0049fcb0;
            *value = next;
            if (next > 255) {
                *value = 255;
                *state = 1;
            }
        } else {
            int next = *value - DAT_0049fcb0;
            *value = next;
            if (next < 0) {
                *value = 0;
                *state = 0;
            }
        }
    }
}


// 0x000caab0 FUN_000caab0 (149 B): matches/0x000caab0.cpp
// sym: ?FUN_000caab0@fn_fb3f3f46@@YIXPAUSelf_caab0@1@@Z
void __fastcall FUN_000caab0(Self_caab0* self) {
    char* s = (char*)self + 0x264;
    int n = 8;
    do {
        if (*s) {
            void* b = self->p->b;
            long long v = FUN_002672f0(s, 0, 0);
            if (!FUN_00024280(b, v)) {
                Ent_caab0* e = self->p->m->Find_001def30(s);
                if (e) {
                    e->Prep_001d62d0();
                    e->sub->Tick_001d60c0();
                }
            }
        }
        s += 0x40;
    } while (--n);
    *(unsigned int*)((char*)self + 0x478) = 0;
    *(unsigned int*)((char*)self + 0x47c) = 0;
    *(unsigned int*)((char*)self + 0x480) = 0;
    *(unsigned int*)((char*)self + 0x484) = 0;
    *(unsigned int*)((char*)self + 0x488) = 0;
    *(unsigned int*)((char*)self + 0x48c) = 0;
}


// 0x000cab50 FUN_000cab50 (147 B): matches/0x000cab50.cpp
// sym: ?FUN_000cab50@HUDOverlay_cab50@fn_fb3f3f46@@QAEXXZ
// FUN_000cab50 @ 0x000cab50
void HUDOverlay_cab50::FUN_000cab50()
{
    (*(PassHolder_cab50**)&DAT_0052c2ac)->pass->v15(0);
    (*(PassHolder_cab50**)&DAT_0052c2ac)->FUN_00293d00(((Vec3_cab50*)&DAT_004ddebc));
    for (int i = 0; i < 5; i++) {
        if (i != 0)
            (*(PassHolder_cab50**)&DAT_0052c2ac)->FUN_00293d00(((Vec3_cab50*)&DAT_004ddf18));
        (*(PassHolder_cab50**)&DAT_0052c2ac)->pass->v15(0);
        (*(PassHolder_cab50**)&DAT_0052c2ac)->FUN_00293bf0(-1.57079637f);
        if (sprites[i][0] != 0)
            sprites[i][0]->v8(0, 0);
        (*(PassHolder_cab50**)&DAT_0052c2ac)->pass->v16(0);
    }
    (*(PassHolder_cab50**)&DAT_0052c2ac)->pass->v16(0);
}


// 0x000cabf0 FUN_000cabf0 (59 B): matches/0x000cabf0.cpp
// sym: ?SetName@Obj@fn_fb3f3f46@@QAEXPBD@Z
void Obj::SetName(const char* s) {
    int i = 0;
    for (; i < 8; ++i) {
        if (!names[i][0]) {
            strncpy(names[i], s, 0x40);
            return;
        }
    }
    Full_000caab0();
}


// 0x000cac30 FUN_000cac30 (13 B): matches/0x000cac30.cpp
// sym: ?Set@Obj_cac30@fn_fb3f3f46@@QAEXH@Z
void Obj_cac30::Set(int x) {
    value = x;
}


// 0x000cac40 FUN_000cac40 (13 B): matches/0x000cac40.cpp
// sym: ?Set@Obj_cac40@fn_fb3f3f46@@QAEXH@Z
void Obj_cac40::Set(int x) {
    *(int*)((char*)this + 0x498) = x;
}


// 0x000cac50 FUN_000cac50 (13 B): matches/0x000cac50.cpp
// sym: ?Set@Obj_cac50@fn_fb3f3f46@@QAEXH@Z
void Obj_cac50::Set(int x) {
    value = x;
}

} // namespace fn_fb3f3f46

// 0x000cac60 FUN_000cac60 (92 B): matches/0x000cac60.cpp
// sym: ?FUN_000cac60@Obj_cac60@owners@@QAEXXZ
void owners::Obj_cac60::FUN_000cac60() {
    int i;
    for (i = 0; i < 8; i++)
        a[i][0] = 0;
    x478 = 0;
    x47c = 0;
    x480 = 0;
    x484 = 0;
    x488 = 0;
    x48c = 0;
    x494 = 0xff;
    x498 = -1;
    x49c = (int)0xbf800000;
}

namespace fn_fb3f3f46 {

// 0x000cacc0 FUN_000cacc0 (13 B): matches/0x000cacc0.cpp
// sym: ?Set@Obj_cacc0@fn_fb3f3f46@@QAEXH@Z
void Obj_cacc0::Set(int v) {
    value = v;
}


// 0x000cacd0 FUN_000cacd0 (98 B): matches/0x000cacd0.cpp
// sym: ?work@Obj_cacd0@fn_fb3f3f46@@QAEXH@Z
void Obj_cacd0::work(int id) {
    Lookup_cacd0* m = owner->manager;
    Found_cacd0* p = m->find_001fd780(id);
    if (!p) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        return;
    }
    Vec_cacd0 tmp;
    Vec_cacd0* v = p->get(&tmp);
    result.x = v->x;
    result.y = v->y;
    result.z = v->z;
}


// 0x000cad40 FUN_000cad40 (25 B): matches/0x000cad40.cpp
// sym: ?SetName@X@fn_fb3f3f46@@QAEXPBD@Z
void X::SetName(const char* s) {
    strncpy(name, s, 64);
}


// 0x000cad60 FUN_000cad60 (8 B): matches/0x000cad60.cpp
// sym: ?Fn@X_cad60@fn_fb3f3f46@@QAEXXZ
void X_cad60::Fn() {
    m224 = 0;
}


// 0x000cad70 FUN_000cad70 (7 B): matches/0x000cad70.cpp
// sym: ?Get@Obj_cad70@fn_fb3f3f46@@QAEHXZ
int Obj_cad70::Get() {
    return value;
}


// 0x000cad80 FUN_000cad80 (115 B): matches/0x000cad80.cpp
// sym: ?FUN_000cad80@Label_cad80@fn_fb3f3f46@@QAEXPBDHHMMM@Z
// FUN_000cad80 @ 0x000cad80
void Label_cad80::FUN_000cad80(const char *src, int a, int b, float r, float g, float bl)
{
    strncpy(text, src, 0x80);
    f13c = a;
    f140 = b;
    f144 = 0;
    unsigned int c = (int)r | 0xffffff00;
    c = (c << 8) | (int)g;
    c = (c << 8) | (int)bl;
    color = c;
}

} // namespace fn_fb3f3f46

// 0x000cae40 FUN_000cae40 (13 B): matches/0x000cae40.cpp
// sym: ?FUN_000cae40@Target_cae40@owners@@QAEXH@Z
void owners::Target_cae40::FUN_000cae40(int value) {
    *(int*)((char*)this + 0xb8) = value;
}

namespace fn_fb3f3f46 {

// 0x000cae50 FUN_000cae50 (7 B): matches/0x000cae50.cpp
// sym: ?target@fn_fb3f3f46@@YIIPAUX_cae50@1@@Z
unsigned int __fastcall target(X_cae50* self) {
    return self->value;
}


// 0x000cae60 FUN_000cae60 (6 B): matches/0x000cae60.cpp
// sym: ?FUN_000cae60@fn_fb3f3f46@@YAHXZ
int FUN_000cae60() {
    return 0x78d;
}

} // namespace fn_fb3f3f46

// 0x000cae70 FUN_000cae70 (7 B): matches/0x000cae70.cpp
// sym: ?FUN_000cae70@C_cae70@owners@@QAEHXZ
hulk_intptr owners::C_cae70::FUN_000cae70() {
    return value;
}

namespace fn_fb3f3f46 {

// 0x000cae80 FUN_000cae80 (18 B): matches/0x000cae80.cpp
// sym: ?Fn@Obj_cae80@fn_fb3f3f46@@QAEXM@Z
void Obj_cae80::Fn(float f) {
    if (mObj)
        ((Sub_cae80*)mObj)->Fn_000c9bd0(f);
}


// 0x000caea0 FUN_000caea0 (58 B): matches/0x000caea0.cpp
// sym: ?Run@Obj_caea0@fn_fb3f3f46@@QAEXUArgs_caea0@2@@Z
void Obj_caea0::Run(Args_caea0 x) {
    if (m) {
        ((owners::Target_c7ad0 *)m)->FUN_000c7ad0();
        m->FnB_000c9720(x);
    }
}


// 0x000caee0 FUN_000caee0 (38 B): matches/0x000caee0.cpp
// sym: ?Target@Obj_caee0@fn_fb3f3f46@@QAEXH@Z
void Obj_caee0::Target(int x) {
    if (member) {
        member->FnA_000c7ac0();
        member->FnB_000c8ef0(x);
    }
}


// 0x000caf10 FUN_000caf10 (18 B): matches/0x000caf10.cpp
// sym: ?Target@Obj_caf10@fn_fb3f3f46@@QAEXH@Z
void Obj_caf10::Target(int arg) {
    if (mThing)
        ((owners::C_c7ae0 *)mThing)->FUN_000c7ae0(arg);
}


// 0x000caf30 FUN_000caf30 (16 B): matches/0x000caf30.cpp
// sym: ?Target@Obj_caf30@fn_fb3f3f46@@QAEXXZ
void Obj_caf30::Target() {
    if (m88)
        m88->Target_000c7af0();
}


// 0x000caf40 FUN_000caf40 (18 B): matches/0x000caf40.cpp
// sym: ?Fn@Target_caf40@fn_fb3f3f46@@QAEXH@Z
void Target_caf40::Fn(int x) {
    Obj_caf40* p = mObj;
    if (p)
        p->Call_000c7b00(x);
}


// 0x000caf60 FUN_000caf60 (51 B): matches/0x000caf60.cpp
// sym: ?Do@Owner@fn_fb3f3f46@@QAEHHUTriple@2@@Z
int Owner::Do(int x, Triple t) {
    Worker* w = worker;
    int result = -1;
    if (w)
        result = w->Run_000c7b70(x, t);
    return result;
}


// 0x000cafa0 FUN_000cafa0 (48 B): matches/0x000cafa0.cpp
// sym: ?Run@Outer@fn_fb3f3f46@@QAEXHUV3@2@@Z
void Outer::Run(int a, V3 v) {
    if (p)
        p->Apply_000c9090(a, v);
}


// 0x000cafd0 FUN_000cafd0 (21 B): matches/0x000cafd0.cpp
// sym: ?Go@Obj@fn_fb3f3f46@@QAEHHH@Z
int Obj::Go(int a, int b) {
    int result = -1;
    Item* q = p;
    if (q)
        result = q->Fn_000c7d10(a, b);
    return result;
}


// 0x000caff0 FUN_000caff0 (18 B): matches/0x000caff0.cpp
// sym: ?Fn@Obj@fn_fb3f3f46@@QAEXHH@Z
void Obj::Fn(int a, int b) {
    if (other)
        other->Fn_000c7f50(a, b);
}


// 0x000cb010 FUN_000cb010 (18 B): matches/0x000cb010.cpp
// sym: ?Forward@Obj@fn_fb3f3f46@@QAEXHH@Z
void Obj::Forward(int a, int b) {
    if (child)
        child->Action_000c90d0(a, b);
}


// 0x000cb030 FUN_000cb030 (18 B): matches/0x000cb030.cpp
// sym: ?Forward@Obj@fn_fb3f3f46@@QAEXH@Z
void Obj::Forward(int x) {
    if (ptr)
        ptr->Run_000c9100(x);
}


// 0x000cb050 FUN_000cb050 (16 B): matches/0x000cb050.cpp
// sym: ?Target@Obj_cb050@fn_fb3f3f46@@QAEXXZ
void Obj_cb050::Target() {
    if (m)
        m->FnA_000c8010();
}


// 0x000cb060 FUN_000cb060 (18 B): matches/0x000cb060.cpp
// sym: ?Wrapper@Class@fn_fb3f3f46@@QAEXH@Z
void Class::Wrapper(int arg) {
    Sub_cb060* p = mPtr;
    if (p)
        p->Helper_000c80a0(arg);
}


// 0x000cb080 FUN_000cb080 (16 B): matches/0x000cb080.cpp
// sym: ?Fn@Owner_cb080@fn_fb3f3f46@@QAEXXZ
void Owner_cb080::Fn() {
    if (m)
        m->Go_000c91c0();
}


// 0x000cb090 FUN_000cb090 (81 B): matches/0x000cb090.cpp
// sym: ?Go@Obj@fn_fb3f3f46@@QAEHHHUVec@2@0@Z
int Obj::Go(int a, int b, Vec c, Vec d) {
    int result = -1;
    if (mgr)
        result = mgr->Run_000c9210(a, b, c, d);
    return result;
}


// 0x000cb130 FUN_000cb130 (53 B): matches/0x000cb130.cpp
// sym: ?Fn@Owner@fn_fb3f3f46@@QAEXHHUV@2@@Z
void Owner::Fn(int x, int y, V v) {
    if (other)
        other->Go_000c9340(x, y, v);
}


// 0x000cb170 FUN_000cb170 (18 B): matches/0x000cb170.cpp
// sym: ?Go@Parent@fn_fb3f3f46@@QAEXHH@Z
void Parent::Go(int a, int b) {
    if (child)
        child->Run_000c9390(a, b);
}


// 0x000cb190 FUN_000cb190 (106 B): equivalent/0x000cb190.cpp
// sym: ?Forward@Wrapper_cb190@fn_fb3f3f46@@QAEHHHUVec3_cb190@2@00@Z @215ba11e9ece @w4d0158fda182
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000cb190 @ 0x000cb190
int Wrapper_cb190::Forward(int a, int b, Vec3_cb190 p, Vec3_cb190 q, Vec3_cb190 r)
{
    if (inner == 0)
        return -1;
    return inner->FUN_000c93e0(a, b, p, q, r);
}


// 0x000cb200 FUN_000cb200 (48 B): matches/0x000cb200.cpp
// sym: ?fn@Wrap@fn_fb3f3f46@@QAEXHUVec3@2@@Z
void Wrap::fn(int a, Vec3 v) {
    if (obj)
        obj->fn_000c8410(a, v);
}


// 0x000cb230 FUN_000cb230 (48 B): matches/0x000cb230.cpp
// sym: ?Fn@Obj@fn_fb3f3f46@@QAEXHUVec@2@@Z
void Obj::Fn(int a, Vec v) {
    if (inner)
        inner->Fn_000c8450(a, v);
}


// 0x000cb260 FUN_000cb260 (18 B): matches/0x000cb260.cpp
// sym: ?Target@Obj_cb260@fn_fb3f3f46@@QAEXH@Z
void Obj_cb260::Target(int x) {
    Sub_cb260* p = m88;
    if (p)
        p->Fn_000c8490(x);
}


// 0x000cb280 FUN_000cb280 (24 B): matches/0x000cb280.cpp
// sym: ?Set@Obj_cb280@fn_fb3f3f46@@QAEXE@Z
void Obj_cb280::Set(unsigned char p) {
    if (m8c) {
        m8c->flag = (p == 1);
    }
}

} // namespace fn_fb3f3f46

// 0x000cb2a0 FUN_000cb2a0 (51 B): matches/0x000cb2a0.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_000cb2a0@@QAEHHUArg@2@@Z
namespace fn_000cb2a0 {
struct Arg {
    int a, b, c;
};
class Helper {
  public:
    int Fn_000c6f20(int, Arg);
};
class Obj {
    char pad[0x8c];

  public:
    Helper* p;
    int Fn(int, Arg);
};
int Obj::Fn(int x, Arg a) {
    int r = -1;
    if (p)
        r = p->Fn_000c6f20(x, a);
    return r;
}
} // namespace fn_000cb2a0


// 0x000cb2e0 FUN_000cb2e0 (48 B): matches/0x000cb2e0.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_000cb2e0@@QAEXHUV@2@@Z
namespace fn_000cb2e0 {
struct V {
    int a, b, c;
};
class Obj {
    char pad[0x8c];

  public:
    void* p;
    void Fn(int x, V v);
};
class Sub {
  public:
    void Go_000c6fa0(int x, V v);
};
void Obj::Fn(int x, V v) {
    if (p)
        ((Sub*)p)->Go_000c6fa0(x, v);
}
} // namespace fn_000cb2e0


// 0x000cb310 FUN_000cb310 (21 B): matches/0x000cb310.cpp [wrapped: conflict: Obj]
// sym: ?fn@Obj@fn_000cb310@@QAEHHH@Z
namespace fn_000cb310 {
class Obj {
  public:
    char pad[0x8c];
    Obj* p;
    int action_000c6fe0(int, int);
    int fn(int, int);
};
int Obj::fn(int a, int b) {
    int result = -1;
    Obj* q = p;
    if (q)
        result = q->action_000c6fe0(a, b);
    return result;
}
} // namespace fn_000cb310

namespace fn_fb3f3f46 {

// 0x000cb330 FUN_000cb330 (18 B): matches/0x000cb330.cpp
// sym: ?Run@Owner@fn_fb3f3f46@@QAEXH@Z
void Owner::Run(int x) {
    if (!thing)
        return;
    return thing->Act_000c7140(x);
}

} // namespace fn_fb3f3f46

// 0x000cb350 HUDOverlay::vfunc_5 (3 B): matches/0x000cb350.cpp
// sym: ?vfunc_5@HUDOverlay@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void HUDOverlay::vfunc_5(int a) {
    (void)a;
}

// 0x000cb680 thunk_FUN_001d04a0 (5 B): not yet verified
namespace fn_fb3f3f46 {

// 0x000cb6f0 FUN_000cb6f0 (94 B): equivalent/0x000cb6f0.cpp
// sym: ?FUN_000cb6f0@Object@fn_fb3f3f46@@QAEMHH@Z @96b81ec8b4cf @w975db8b59ff5
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_000cb6f0 @ 0x000cb6f0
hulk_freg Object::FUN_000cb6f0(int position, int index) {
    if (position < 0) return (*(float*)&DAT_003f32e0);
    Segment* base = table->segments[0];
    Segment* item = table->segments[index];
    int chosen = selected;
    volatile float* value = (volatile float*)((char*)this + 8 + chosen * 16);
    // the original loads the vptr before the table lookup call and the slot after it
    typedef float (__fastcall *EvalFn)(Segment*, int, void*);
    void** vtable = *(void***)item;
    void* arg = ((void *)((owners::C_f7220 *)table)->FUN_000f7220((hulk_intptr)position));
    float result = ((EvalFn)vtable[9])(item, 0, arg);
    float divisor = base->getDivisor();
    double product = (*value / divisor) * result; // keep the original's multiplication order
    return product * (*(float*)&DAT_0040cc38);
}


// 0x000cb750 FUN_000cb750 (106 B): equivalent/0x000cb750.cpp
// sym: ?Sample@Sampler_cb750@fn_fb3f3f46@@QAEMHH@Z @9059db30b10f @w83046938c86c
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// FUN_000cb750 @ 0x000cb750
hulk_freg Sampler_cb750::Sample(int a, int b)
{
    if (a < 0)
        return 0.0f;
    Curve_cb750* curve = bank->curves[b];
    Curve_cb750* first = bank->curves[0];
    Slot_cb750* slot = &slots[current];
    float inv = 14.0f / first->v7();
    // the original loads the curve's vptr before the bank lookup call and the slot after it
    typedef float (__fastcall *EvalFn)(Curve_cb750*, int, int);
    void** vtable = *(void***)curve;
    int arg = ((int)((owners::C_f7220 *)bank)->FUN_000f7220((hulk_intptr)a));
    return ((EvalFn)vtable[10])(curve, 0, arg) * slot->value * inv;
}


// 0x000cb7d0 FUN_000cb7d0 (107 B): equivalent/0x000cb7d0.cpp
// sym: _FUN_000cb7d0 @c20e4cc3d487 @w521db6bdbba9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000cb7d0 @ 0x000cb7d0
// equiv-conv: FUN_000cb7d0 ecx edx stack
extern "C" void FUN_000cb7d0(float *a, float *b, float limit)
{
    volatile float av = *b - *a;
    *(volatile unsigned int *)&av &= 0x7fffffff;
    if (av <= 9.99999975e-06f)
        return;
    double d = *b - *a;
    volatile float nl = -limit;
    if (d >= nl) {
        if (d <= limit)
            *a = (float)(d + *a);
        else
            *a = limit + *a;
    } else {
        if (d > limit)
            *a = limit + *a;
        else
            *a = nl + *a;
    }
}

} // namespace fn_fb3f3f46

// 0x000cb840 HUDOverlay::vfunc_0 (45 B): matches/0x000cb840.cpp [wrapped: conflict: HUDOverlay]
// sym: ?vfunc_0@HUDOverlay@fn_000cb840@@UAEPAV12@E@Z
namespace fn_000cb840 {
struct Helper_cb840 {
    void Fnf_000f7960();
};
class HUDOverlay {
  public:
    virtual HUDOverlay* vfunc_0(unsigned char);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[0x54];
};
extern int hudvt, ovt;
void thunk_FUN_00267090(HUDOverlay*);
HUDOverlay* HUDOverlay::vfunc_0(unsigned char flags) {
    Helper_cb840* h = (Helper_cb840*)((char*)this + 0x54);
    *(void**)this = &hudvt;
    h->Fnf_000f7960();
    *(void**)this = &ovt;
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000cb840

namespace fn_fb3f3f46 {

// 0x000cb870 FUN_000cb870 (975 B): equivalent/0x000cb870.cpp
// sym: ?FUN_000cb870@Resources_cb870@fn_fb3f3f46@@QAEXPAUBits_cb870@2@@Z @7f1cd8f5a1d9 @w6a0f3d52fb37
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 94/94)
// FUN_000cb870 @ 0x000cb870
void Resources_cb870::FUN_000cb870(Bits_cb870 *bits)
{
    ((owners::Obj_f7a10 *)&sub54)->FUN_000f7a10((hulk_intptr)(-1), 0);
    Drop(r14);
    Drop(r18);
    Drop(r88);
    Drop(r8c);
    Drop(r90);
    Drop(r164);
    Drop(r168);
    Drop(r198);
    Drop(r19c);
    Drop(r1a4);
    Drop(r1a8);
    Drop(r1ac);
    Drop(r1b0);
    Drop(r1b4);
    Drop(r1b8);
    for (int i = 0; i < 3; i++) {
        Drop(a1bc[i]);
        Drop(a1c8[i]);
        Drop(a1d4[i]);
        z1ec[i] = 0;
    }
    Drop(r1e0);
    Drop(r1e4);
    Drop(r1e8);
    Drop(r1f8);
    for (int i = 0; i < 6; i++) {
        Drop(a1fc[i]);
    }
    if (r218 != 0) {
        r218->Stop();
    }
    if (r218 != 0) {
        r218->Release();
        r218 = 0;
    }
    Drop(r21c);
    Drop(r234);
    Drop(r244);
    Drop(r248);
    Drop(r250);
    Drop(r254);
    Drop(r258);
    Drop(r25c);
    Drop(r260);
    for (int i = 0; i < 8; i++) {
        flags264[i][0] = 0;
    }
    Drop(r464);
    Drop(r468);
    Drop(r46c);
    Drop(r4a0);
    Drop(r4a4);
    Drop(r4a8);
    Drop(r4ac);
    Drop(r4b0);
    Drop(r4b4);
    Drop(r508);
    ((owners::Slots_d6dd0 *)bits)->FUN_000d6dd0((hulk_intptr)this);
}


// 0x000cbc40 FUN_000cbc40 (2970 B): equivalent/0x000cbc40.cpp
// sym: ?FUN_000cbc40@HUDOverlay_cbc40@fn_fb3f3f46@@QAEXM@Z @90c4f6dd84f4 @w8427508362ea
// STATUS: equivalent (tools/equiv.py level 3: 5746 inputs, branch coverage 150/150)
// FUN_000cbc40 @ 0x000cbc40
// equiv-conv: FUN_000cb7d0 ecx edx stack
void HUDOverlay_cbc40::FUN_000cbc40(float dt)
{
    if (p14 == 0)
        return;
    f154 = p14->f1b0c;
    float t;
    t = f154 - f158;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f14c - f150;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f15c = 0.0f;
        if (f15c > 0.5f)
            FUN_000cb7d0(&f158, &f154, dt * 200.0f);
    }

    float a = p14->f1b0c;
    f174 = a - p14->FUN_00036090();
    t = f174 - f178;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f16c - f170;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f180 = 0.0f;
        if (f180 > 0.5f)
            FUN_000cb7d0(&f178, &f174, dt * 100.0f);
    }

    f18c = p14->f1b0c;
    t = f18c - f190;
    if (t < 0.0f)
        t = -t;
    if (!(t <= 1e-05f)) {
        t = f184 - f188;
        if (t < 0.0f)
            t = -t;
        if (t <= 1e-05f)
            f194 = 0.0f;
        if (f194 > 0.5f)
            FUN_000cb7d0(&f190, &f18c, dt * 100.0f);
    }

    f15c = dt + f15c;
    f180 = dt + f180;
    f194 = dt + f194;

    t = f154 - f158;
    if (t < 0.0f)
        t = -t;
    bool settled = false;
    if (t <= 1e-05f) {
        settled = true;
        if (state == 1) {
            t = f174 - f178;
            if (t < 0.0f)
                t = -t;
            if (!(t <= 1e-05f))
                settled = false;
        }
    }
    if (settled) {
        if (f160 < 0xff) {
            char zero = 0;
            FUN_000caa60(&zero, &f160);
        }
    } else {
        FUN_000caa60(&DAT_004dde78, &f160);
    }
    f14c = f154;
    f150 = f158;
    f16c = f174;
    f170 = f178;
    f184 = f18c;
    f188 = f190;

    struct Frame {
        int pad0;
        union {
            float f;
            int i;
            Probe_cbc40 *p;
        } w[8];                 // w[1] = base+0x14 ... w[8] = base+0x30 (indexes 1..7 used)
    };
    Frame f;
    bool bl = false;
    f.w[2].f = 0.0f;            // A
    f.w[1].f = 0.0f;            // B
    f.w[3].p = ((Probe_cbc40 *)((owners::A_86340 *)(DAT_004dd700->f54))->FUN_00086340());
    int st = state;
    bool doLists = true;
    if (st == 0) {
        int m = p14->f1b28;
        if (m == 1) {
            state = 4;
            bl = true;
            f.w[2].f = 0.0f;
            f.w[1].f = 25.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[1].f = 40.0f;
                if (f.w[3].p->FUN_00092940(0x29e))
                    f.w[1].f = 60.0f;
            }
        } else if (m == 2) {
            state = 6;
            bl = true;
            f.w[2].f = 0.0f;
            f.w[1].f = 15.0f;
        }
        f178 = f174;
        f190 = f18c;
        if (!bl)
            doLists = false;
    } else if (st == 1) {
        dt = dt * 1000.0f;
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i++)
            p19c->begin[(unsigned char)i]->v6(dt, 1);
        if (p14->f1b28 == 1) {
            doLists = false;
        } else {
            state = 3;
            f.w[2].f = 100.0f;
            f.w[1].f = 135.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[2].f = 80.0f;
                if (f.w[3].p->FUN_00092940(0x29e))
                    f.w[2].f = 60.0f;
            }
        }
    } else if (st == 2) {
        dt = dt * 1000.0f;
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i++)
            p19c->begin[(unsigned char)i]->v6(dt, 1);
        if (p14->f1b28 == 2) {
            doLists = false;
        } else {
            state = 5;
            f.w[2].f = 120.0f;
            f.w[1].f = 135.0f;
        }
    } else if (st == 3) {
        float *ms = &f.w[4].f;
        int *n = &f.w[5].i;
        float *hi = &f.w[3].f;
        float *lo = &f.w[6].f;
        float *val = &f.w[7].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        f17c = 0.0f;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                *val = (o->v13() - 120.0f) * 0.0666666701f;
                f17c = FUN_000186b0(val, lo, hi);
                if (o->v22())
                    (*(int *)&dt)++;
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        int cB = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                cB++;
        }
        if (*(int *)&dt != *n || cB != n2) {
            doLists = false;
        } else {
            state = 0;
            f.w[2].f = 0.0f;
            f.w[1].f = 0.0f;
        }
    } else if (st == 4) {
        float *ms = &f.w[5].f;
        int *n = &f.w[8].i;
        float *hi = &f.w[7].f;
        float *lo = &f.w[6].f;
        float *val = &f.w[4].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        f17c = 0.0f;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                *val = o->v13() * 0.0666666701f;
                f17c = 1.0f - FUN_000186b0(val, lo, hi);
                if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                    (*(int *)&dt)++;
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        int cB = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (o->v22())
                cB++;
        }
        if (*(int *)&dt != *n || cB != n2) {
            doLists = false;
        } else {
            state = 1;
            f178 = 0.0f;
            f.w[2].f = 25.0f;
            f.w[1].f = 25.0f;
            if (f.w[3].p->FUN_00092940(0x28b)) {
                f.w[2].f = 40.0f;
                f.w[1].f = 40.0f;
                if (f.w[3].p->FUN_00092940(0x29e)) {
                    f.w[2].f = 60.0f;
                    f.w[1].f = 60.0f;
                }
            }
        }
    } else if (st == 5 || st == 6) {
        float *ms = &f.w[5].f;
        int *n = &f.w[3].i;
        float *hi = &f.w[8].f;
        float *lo = &f.w[7].f;
        float *val = &f.w[6].f;
        *ms = dt * 1000.0f;
        *n = (unsigned char)(p19c->end - p19c->begin);
        *(int *)&dt = 0;
        if (*n > 0) {
            *hi = 1.0f;
            *lo = 0.0f;
            for (int i = 0; i < *n; i++) {
                UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
                o->v6(*ms, 1);
                if (st == 5) {
                    *val = (o->v13() - 120.0f) * 0.0666666701f;
                    f17c = FUN_000186b0(val, lo, hi);
                    if (o->v22())
                        (*(int *)&dt)++;
                } else {
                    *val = o->v13() * 0.0666666701f;
                    f17c = 1.0f - FUN_000186b0(val, lo, hi);
                    if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                        (*(int *)&dt)++;
                }
            }
        }
        int n2 = (unsigned char)(p168->end - p168->begin);
        f.w[4].i = 0;
        for (int i = 0; i < n2; i++) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v6(*ms, 1);
            if (st == 5) {
                if (o->v22() || FUN_00344e74(o, 0, DAT_0049fd74, DAT_0049fd9c, 0) != 0)
                    f.w[4].i++;
            } else {
                if (o->v22())
                    f.w[4].i++;
            }
        }
        if (*(int *)&dt != *n || f.w[4].i != n2) {
            doLists = false;
        } else if (st == 5) {
            state = 0;
            f.w[2].f = 0.0f;
            f.w[1].f = 0.0f;
        } else {
            state = 2;
            f.w[2].f = 15.0f;
            f.w[1].f = 15.0f;
        }
    } else {
        doLists = false;
    }
    if (doLists) {
        int n = (unsigned char)(p19c->end - p19c->begin);
        for (int i = 0; i < n; i = i) {
            UiObj_cbc40 *o = p19c->begin[(unsigned char)i];
            o->v14(f.w[2].f, f.w[1].f);
            o->v12(f.w[2].f);
            n = (unsigned char)(p19c->end - p19c->begin);
            i++;
        }
        n = (unsigned char)(p168->end - p168->begin);
        for (int i = 0; i < n; i = i) {
            UiObj_cbc40 *o = p168->begin[(unsigned char)i];
            o->v14(f.w[2].f, f.w[1].f);
            o->v12(f.w[2].f);
            n = (unsigned char)(p168->end - p168->begin);
            i++;
        }
    }
}

} // namespace fn_fb3f3f46
