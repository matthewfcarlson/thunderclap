// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c7e90..0x001c96e0 (kind game, layer game, confidence high), dominant class Render::LevelLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/Render.h"
#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"
#include "gen/Render.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9d12736 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f9d12736 {} using namespace fn_f9d12736;
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_f9d12736 {
struct I_1c7e90 {
    void Fnf_001c7870(void*, void*);
};
class C_1c7e90 {
    char pad[0x18];
    I_1c7e90 inner;

  public:
    void g(void*);
};
class Item {
  public:
    char pad[0x54];
    short id;
};
class Array {
  public:
    char pad[8];
    unsigned count;
    char pad2[8];
    Item** data;
    int size_001c7520();
    Item* get(unsigned i) { return i < count ? data[i] : 0; }
};
class Owner {
  public:
    char pad[0x18];
    Array arr;
    Item* find(int id);
};
struct C_1c7f70 {
    char pad[0x18];
};
struct Cache_1c7f70 { int FUN_001c75e0(int); };
struct Mgr_1c7f70 { char pad[0x18]; Cache_1c7f70 cache; hulk_intptr FUN_001c7f70(hulk_intptr a); };
class Ref_1c7fa0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Slot_1c7fa0 {
  public:
    Ref_1c7fa0* p;
    void Clear() {
        Ref_1c7fa0* q = p;
        if (q) {
            q->Release();
            p = 0;
        }
    }
};
class Obj_1c7fa0 {
    char pad[8];
    Slot_1c7fa0 a;
    Slot_1c7fa0 b;

  public:
    void Set(Ref_1c7fa0* x, Ref_1c7fa0* y);
};
class Item_1c8000 {
  public:
    char pad[0x28];
    char flag;
};
class Manager_1c8000 {
  public:
    char pad[0x10];
    int count;
    int capacity;
    Item_1c8000** items;
};
class Obj_1c8000 {
  public:
    void Process_0029f800(Item_1c8000*);
};
class Service_1c8000 {
  public:
    void** vt;
};
extern "C" Service_1c8000* FUN_001c3d90();
struct Key_1c8060 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af50();
};
struct Entry_1c8060 {
    unsigned lo;
    unsigned hi;
    char active;
    char pad9[3];
    bool FUN_001c6660(int query);
};
struct Index_1c8060 {
    Entry_1c8060 *FUN_001c75e0(Key_1c8060 *k);
};
class Registry_1c8060 {
public:
    char pad0[0x18];
    Index_1c8060 index;
    char pad19[0xf];
    int count;
    Entry_1c8060 **table;

    Entry_1c8060 *FUN_001c8060(hulk_intptr query, Key_1c8060 *out);
};
struct Vec3_1c81a0 {
    float x, y, z;
};
struct Item_1c81a0 {
    char pad00[0x20];
    float x;                // 0x20
    float y;                // 0x24
    float z;                // 0x28
};
class ItemTable_1c81a0 {
public:
    char pad00[0x28];
    int last;               // 0x28
    Item_1c81a0 **slots;           // 0x2c
    Item_1c81a0 *FUN_001c81a0(const Vec3_1c81a0 *pos);
};
struct Item_1c8250 {
    char pad[0x90];
    float v90;
    float v94;
    void FUN_001c5130(float a, float b);
};
struct Target_1c8250 {
    char pad0[0x138];
    Item_1c8250 *items[0x400 / 4];
    unsigned int count;
    void FUN_001c8250();
};
class Node {
  public:
    char pad0[0x14];
    void* mChild;
    char pad1[0x8];
    char mFlag;
    char pad4;
    char mHidden;
    char pad3[0x6d];
    float mVal;
    char Check_001c4af0();
};
struct Mgr_1c84e0 {
    char Test_0023f760(const char* s, int a, int b);
};
class Obj_1c84e0 {
  public:
    void FnA_001c7a60(Node* n, float f, int a, int b, int c);
    void FnB_001c82c0(int x, Node* n, int y);
    void Fn(hulk_intptr x, Node* n, hulk_intptr y);
};
const float scale_1c8590 = 1000.0f;
class Item_1c8590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(float, int);
    void Update_001c68e0(float);
};
class Owner_1c8590 {
  public:
    char pad0[8];
    Item_1c8590* one;
    Item_1c8590* two;
    char pad14[0x18];
    int count;
    Item_1c8590** items;
    void Run(float);
};
extern "C" char DAT_003f6098[];
extern "C" char DAT_00421abc[];
struct Ref_1c8610 {
    virtual void A();
    virtual void Release();
};
struct LevelLoader_1c8610 {
    virtual void V0();
    virtual void V1();
    char pad[0x1c - 4];
    Ref_1c8610* mRef;
    void F();
};
extern void* hulk_at_00421ad8[];
class Ref_1c86e0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Q_1c86e0 {
    void Fin_0027af50() throw();
};
struct Store {
    void* vptr;
    void Fin2_001c7500() throw();
};
struct H {
    char pad[8];
    Store st;
    char pad2[0x120 - 4];
    int a[0x100];
    int padb;
    int b[4];
    void Fin_0027af50() throw();
};
class World_1c86e0 {
  public:
    void* vptr;
    char pad0[4];
    Ref_1c86e0* m8;
    Ref_1c86e0* mc;
    H h;
    char pad2[0x750 - 0x10 - sizeof(H)];
    Ref_1c86e0* m750;
    char pad3[4];
    Q_1c86e0 q758;
    char pad4[7];
    Ref_1c86e0* m760;
    void f();
};
struct Id64_1c8790 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af50();
    void FUN_0027af70(const Id64_1c8790* src);
    Id64_1c8790* FUN_0027b0e0(const char* name);
};
struct Holder_1c8790 {
    char pad0[0x10];
    Id64_1c8790 id;
    const Id64_1c8790* FUN_001c8060(const char* name, void* table);
    bool FUN_001c8790(const char* name);
};
struct Vec3_1c88f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Profiler_1c88f0 {
    void FUN_0023f720(int *id, const char *name);
    char FUN_0023f760(const char *name, int a, int b);
    void FUN_0023f740();
};
struct Mode_1c88f0 {
    char *FUN_000897f0();
};
} // namespace fn_f9d12736
struct Singleton_4dd6ec {
};
namespace fn_f9d12736 {
class Gfx_1c88f0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};
} // namespace fn_f9d12736
class Gfx {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28(float a, float b, float c, float d);
    virtual void vfunc_29(float *a, float *b, float *c, float *d);
};
namespace fn_f9d12736 {
struct GfxHolder {
    void FUN_00293d00(Vec3_1c88f0 *v);
};
struct Visible {
    char FUN_001c2820(const void *id);
    char FUN_001c2870(const void *id);
};
struct Ctx_1c88f0 {
    char pad0[0xc];
    Visible vis;
    Vec3_1c88f0 *FUN_001c1300();
    Vec3_1c88f0 *FUN_001c12f0();
    void FUN_001c1330(int a);
    void FUN_001c1340();
    void FUN_001c25c0(int a, int b, int c);
    void FUN_001c1370(int a);
};
struct Mgr_1c88f0;
struct Aim_1c88f0 {
    float x;
    char pad4[4];
    float z;
    float f0c;
};
struct X27 {
    void FUN_0027ff80();
};
extern "C" X27 *FUN_0027f250();
struct ItemA {
    char pad0[8];
    char b8;
    char b9;
    char pad0a[0x58 - 0x0a];
    float f58;
    Vec3_1c88f0 *FUN_001c6af0();
    Aim_1c88f0 *FUN_001c63e0();
    const void *FUN_001c6ac0();
    const void *FUN_001c6ab0();
    const void *FUN_001c6aa0();
    void FUN_001c68c0(Ctx_1c88f0 *ctx);
    void FUN_001c6800(Ctx_1c88f0 *ctx, Mgr_1c88f0 *mgr, Visible *vis, float alpha);
};
struct ItemB {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Ctx_1c88f0 *ctx, Mgr_1c88f0 *mgr);
    char pad4[0x14 - 4];
    int f14;
    char pad18[0xa8 - 0x18];
    char bA8;
    void FUN_001c4b50(Vec3_1c88f0 *out);
};
struct SubObj_1c88f0 {
    char pad0[0x10];
    void FUN_001c75e0(void *p);
};
struct Mgr_1c88f0 {
    char pad0[8];
    int f08;
    int f0c;
    char f10[8];
    SubObj_1c88f0 sub18;
    int count28;
    ItemA **list2c;
    char pad30[0x138 - 0x30];
    ItemB *items[0x100];
    unsigned int count538;
    ItemB *slots[4];
    int f54c;
    char pad550[0x5c - 0x50];
    void FUN_001c84e0(Ctx_1c88f0 *ctx, ItemB *it, Vec3_1c88f0 *pos);
    void FUN_001c88f0(Ctx_1c88f0 *ctx);
};
struct Frame_1c88f0 {
    float dist;
    float alpha;
    float r150;
    float tmp12;
    float dot;
    float r295;
    float r270;
    Vec3_1c88f0 c;
    Vec3_1c88f0 pos;
    Vec3_1c88f0 dir;
    Vec3_1c88f0 unit;
    Vec3_1c88f0 v;
    int pad58;
};
struct RoomLoader_1c8f60 {
    virtual void Run();
    RoomLoader_1c8f60* Init_001c6d10(unsigned p);
};
extern RoomLoader_1c8f60* __cdecl Alloc_00263ea0(unsigned n);
class LevelLoader {
  public:
    hulk_uintptr vptr;
    int m4, m8, mc, m10;
    unsigned m14, m18;
    RoomLoader_1c8f60* m1c;
    LevelLoader(hulk_uintptr a, hulk_uintptr b);
};
extern void* hulk_at_00421abc[];
} // namespace fn_f9d12736
void operator delete(void*);
namespace fn_f9d12736 {
class Ref_1c8fd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_1c8fd0 {
  public:
    void* vptr;
    void Fin();
};
class LevelLoader_1c8fd0 : public SimpleChunkHandler_1c8fd0 {
  public:
    char pad[0x18];
    Ref_1c8fd0* m;
    LevelLoader_1c8fd0* f2(unsigned char flags);
};
class World_1c9140 : public CAction {
  public:
    World_1c9140* vfunc_2(unsigned char);
};
struct ThisCall_001c86e0 {
    void FUN_001c86e0();
};
extern void thunk_FUN_00267090(World_1c9140*);


// 0x001c7e90 FUN_001c7e90 (17 B): matches/0x001c7e90.cpp
// sym: ?g@C_1c7e90@fn_f9d12736@@QAEXPAX@Z
void C_1c7e90::g(void* x) {
    inner.Fnf_001c7870(x, x);
}


// 0x001c7f10 FUN_001c7f10 (87 B): matches/0x001c7f10.cpp
// sym: ?find@Owner@fn_f9d12736@@QAEPAVItem@2@H@Z
Item* Owner::find(int id) {
    int n = arr.size_001c7520();
    for (int i = 0; i < n; ++i) {
        if (arr.get(i) && arr.get(i)->id == id)
            return arr.get(i);
    }
    return 0;
}


// 0x001c7f70 FUN_001c7f70 (8 B): matches/0x001c7f70.cpp
// sym: ?FUN_001c7f70@Mgr_1c7f70@fn_f9d12736@@QAEHH@Z
// Same code shape as 0x000679c0 (propagated; names are from that function)
hulk_intptr Mgr_1c7f70::FUN_001c7f70(hulk_intptr a) {
    return cache.FUN_001c75e0(a);
}

} // namespace fn_f9d12736

// 0x001c7f80 FUN_001c7f80 (23 B): matches/0x001c7f80.cpp
// sym: ?FUN_001c7f80@Thing_1c7f80@owners@@QAEII@Z
hulk_uintptr owners::Thing_1c7f80::FUN_001c7f80(unsigned int i) {
    if (i < count)
        return values[i];
    return 0;
}

namespace fn_f9d12736 {

// 0x001c7fa0 FUN_001c7fa0 (93 B): matches/0x001c7fa0.cpp
// sym: ?Set@Obj_1c7fa0@fn_f9d12736@@QAEXPAVRef_1c7fa0@2@0@Z
void Obj_1c7fa0::Set(Ref_1c7fa0* x, Ref_1c7fa0* y) {
    if (x) {
        if (a.p)
            a.Clear();
        a.p = x;
        x->AddRef();
    }
    if (y) {
        if (b.p)
            b.Clear();
        b.p = y;
        y->AddRef();
    }
}


// 0x001c8000 FUN_001c8000 (90 B): matches/0x001c8000.cpp
// sym: ?FUN_001c8000@fn_f9d12736@@YGXPAVManager_1c8000@1@@Z
void __stdcall FUN_001c8000(Manager_1c8000* m) {
    if (m) {
        int i = 0;
        if (m->capacity > 0)
            do {
                Item_1c8000* item;
                if (i < m->count)
                    item = m->items[i];
                else
                    item = 0;
                if (item->flag) {
                    Service_1c8000* s = FUN_001c3d90();
                    Obj_1c8000* o = (Obj_1c8000*)s->vt[49];
                    o->Process_0029f800(item);
                } else {
                    Service_1c8000* s = FUN_001c3d90();
                    Obj_1c8000* o = (Obj_1c8000*)s->vt[48];
                    o->Process_0029f800(item);
                }
                ++i;
            } while (i < m->capacity);
    }
}


// 0x001c8060 FUN_001c8060 (320 B): equivalent/0x001c8060.cpp
// sym: ?FUN_001c8060@Registry_1c8060@fn_f9d12736@@QAEPAUEntry_1c8060@2@HPAUKey_1c8060@2@@Z @a77952fd16d0 @wf6c775967cd2
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 42/44, incomplete)
// FUN_001c8060 @ 0x001c8060
Entry_1c8060 *Registry_1c8060::FUN_001c8060(hulk_intptr query, Key_1c8060 *out)
{
    Entry_1c8060 *e = 0;
    bool found = false;
    if (out != 0 && (out->lo | out->hi) != 0) {
        Key_1c8060 k;
        k.lo = 0;
        ((owners::Pair_27af10 *)&k)->FUN_0027af10((unsigned int)(out->lo), (unsigned int)(out->hi));
        e = index.FUN_001c75e0(&k);
        found = (e != 0);
        k.FUN_0027af50();
    }
    if (found && e->FUN_001c6660(query))
        return e;

    for (int pass = 0; pass < 2; pass++) {
        int i = 0;
        for (;;) {
            Entry_1c8060 **t = table;
            if (t[i] == 0) {
                int n = count;
                while (i <= n) {
                    Entry_1c8060 *next = t[i + 1];
                    i++;
                    if (next != 0)
                        break;
                }
            }
            if (i > count)
                break;
            e = t[i];
            i++;
            if (e == 0)
                break;
            if ((e->active != 0) != (pass == 0))
                continue;
            if (!e->FUN_001c6660(query))
                continue;
            if (out != 0) {
                out->lo = e->lo;
                out->hi = e->hi;
            }
            return e;
        }
    }
    if (out != 0) {
        out->lo = 0;
        out->hi = 0;
    }
    return 0;
}


// 0x001c81a0 FUN_001c81a0 (130 B): equivalent/0x001c81a0.cpp
// sym: ?FUN_001c81a0@ItemTable_1c81a0@fn_f9d12736@@QAEPAUItem_1c81a0@2@PBUVec3_1c81a0@2@@Z @c893d3e05ebf @w522edd1d7fda
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 11/12, incomplete)
// FUN_001c81a0 @ 0x001c81a0
// Returns the item nearest to pos (squared distance below 1e12), or null.
Item_1c81a0 *ItemTable_1c81a0::FUN_001c81a0(const Vec3_1c81a0 *pos)
{
    Item_1c81a0 *nearest = 0;
    float best = 1.0e12f;

    for (int i = 0; i <= last; i++) {
        Item_1c81a0 *item = slots[i];
        if (item == 0)
            continue;
        double dist2 = ((pos->x - item->x) * (pos->x - item->x) + (pos->z - item->z) * (pos->z - item->z)) +
                       (pos->y - item->y) * (pos->y - item->y);
        if (dist2 < best) {
            best = (float)dist2;
            nearest = item;
        }
    }
    return nearest;
}


// 0x001c8250 FUN_001c8250 (107 B): matches/0x001c8250.cpp
// sym: ?FUN_001c8250@Target_1c8250@fn_f9d12736@@QAEXXZ
// FUN_001c8250 @ 0x001c8250
void Target_1c8250::FUN_001c8250()
{
    for (unsigned int i = 0; i < count; i++) {
        Item_1c8250 *it = items[i];
        if (it != 0) {
            if (it->v94 != (*(float*)&DAT_00421898) || it->v90 != (*(float*)&DAT_00421898))
                it->FUN_001c5130((*(float*)&DAT_00421898), (*(float*)&DAT_004218c0));
        }
    }
}

} // namespace fn_f9d12736

// 0x001c82c0 FUN_001c82c0 (533 B): equivalent/0x001c82c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001c82c0@Renderer_1c82c0@fn_001c82c0@@QAEXPAUScene_1c82c0@2@PAUView@2@H@Z @6851a96601f2 @w336bcddbb6a4
namespace fn_001c82c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20039 inputs, branch coverage 20/22, incomplete)
// FUN_001c82c0 @ 0x001c82c0

struct Vec3_1c82c0 {
    float x, y, z;
};

struct Profiler_1c82c0 {
    char FUN_0023f760(const char *name, int id, int flag);
};

struct Viewer {
    void FUN_002a05c0(void *p, Vec3_1c82c0 *pos, int zero, float one);
};

struct Slot_1c82c0 {
    int f0;
    float f4;
};

struct Light {
    char pad0[0x14];
    unsigned color;
    char pad18[0x58 - 0x18];
    Slot_1c82c0 slot;
};

struct LightSet_1c82c0 {
    char pad0[0x10];
    int count;
    int numLights;
    Light **lights;
    void FUN_002a1180(int mode);
};

struct Scene_1c82c0 {
    char pad0[0xc0];
    Viewer *viewer;
    char padc4[4];
    LightSet_1c82c0 *set;
};

class Emitter_1c82c0 {
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
    virtual void v20(int a, Slot_1c82c0 *slot);
    virtual void v21();
    virtual void v22();
    virtual void v23(float f);
};

struct View {
    char pad0[0x14];
    Emitter_1c82c0 *emitter;
    char pad18[0x90 - 0x18];
    float scale;
    void FUN_001c4d30(Vec3_1c82c0 *out);
    void FUN_001c4d80();
};

struct Painter {
    void FUN_002a31d0();
    void FUN_002a31a0(unsigned color);
    void FUN_002a3250();
};

struct PainterHost {
    char pad0[8];
    Painter inner;
};

struct Renderer_1c82c0 {
    char pad0[0x760];
    PainterHost *host;
    void FUN_001c82c0(Scene_1c82c0 *scene, View *view, int unused);
};

static float ShadeSlope()
{
    return -3.863987684f;
}

void Renderer_1c82c0::FUN_001c82c0(Scene_1c82c0 *scene, View *view, int unused)
{
    Viewer *viewer = scene->viewer;
    Emitter_1c82c0 *em = view->emitter;
    if (em == 0)
        return;

    Vec3_1c82c0 pos;
    view->FUN_001c4d30(&pos);
    LightSet_1c82c0 *set = scene->set;
    if ((*(Profiler_1c82c0**)&DAT_004dd6e8)->FUN_0023f760("Compute Lights", 0x6c, 1)) {
        set->FUN_002a1180(2);
        viewer->FUN_002a05c0(set, &pos, 0, 1.0f);
    }
    view->FUN_001c4d80();

    int count = set->numLights;
    if (count > 1)
        count = 1;
    for (int i = 0; i < count; i++) {
        if (i >= set->count)
            continue;
        Light *light = set->lights[i];
        if (light == 0)
            continue;

        Slot_1c82c0 *slot = &light->slot;
        float x = -slot->f4;
        static float slope = ShadeSlope();
        if (x < 0.2588f)
            continue;

        double t = 1.0;
        if (x < 0.0f)
            t = (x - 0.2588f) * slope;
        double tb = t * view->scale;
        double base = (double)((light->color >> 16) & 0xff) * 1.0;
        int c0 = (int)base;
        int c1 = (int)((255 - c0) * tb + c0);
        unsigned color = (((0xffffff00u | c1) << 8) | c1) << 8 | c1;

        host->inner.FUN_002a31d0();
        host->inner.FUN_002a31a0(color);
        em->v20(0, slot);
        em->v23(20.0f);
        em->v8(0, 0);
        host->inner.FUN_002a3250();
    }
}
} // namespace fn_001c82c0

namespace fn_f9d12736 {

// 0x001c84e0 FUN_001c84e0 (162 B): matches/0x001c84e0.cpp
// sym: ?Fn@Obj_1c84e0@fn_f9d12736@@QAEXHPAVNode@2@H@Z
// data: g_mgr_1c84e0 = DAT_004dd6e8
void Obj_1c84e0::Fn(hulk_intptr x, Node* n, hulk_intptr y) {
    if (!n)
        return;
    if (n->mHidden)
        return;
    if (!(*(Mgr_1c84e0**)&DAT_004dd6e8)->Test_0023f760("Compute Shadows", 0x73, 1))
        return;
    if (n->mFlag) {
        float f = 0.6f;
        if (n->Check_001c4af0())
            f = 1.0f;
        FnA_001c7a60(n, f, (int)(n->mVal * 127.0f + 128.0f), 0x80, 0xff);
    }
    if (n->mChild) {
        FnB_001c82c0(x, n, y);
    }
}


// 0x001c8590 FUN_001c8590 (125 B): matches/0x001c8590.cpp
// sym: ?Run@Owner_1c8590@fn_f9d12736@@QAEXM@Z
void Owner_1c8590::Run(float dt) {
    if (one)
        one->g(dt * scale_1c8590, 0);
    if (two)
        two->g(dt * scale_1c8590, 0);
    int i = 0;
    for (;;) {
        Item_1c8590** a = items;
        while (a[i] == 0 && i <= count)
            ++i;
        if (i > count)
            break;
        Item_1c8590* p = a[i++];
        if (!p)
            break;
        p->Update_001c68e0(dt);
    }
}


// 0x001c8610 FUN_001c8610 (36 B): matches/0x001c8610.cpp
// sym: ?F@LevelLoader_1c8610@fn_f9d12736@@QAEXXZ
void LevelLoader_1c8610::F() {
    *(void**)this = (void*)((hulk_intptr)DAT_00421abc);
    _ReadWriteBarrier();
    Ref_1c8610* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
}


// 0x001c86e0 FUN_001c86e0 (172 B): matches/0x001c86e0.cpp
// sym: ?f@World_1c86e0@fn_f9d12736@@QAEXXZ
void World_1c86e0::f() {
    *(void* volatile*)&vptr = hulk_at_00421ad8;
    Ref_1c86e0* r8 = *(Ref_1c86e0* volatile*)&m8;
    if (r8) {
        r8->Release();
        m8 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m750) {
        m750->Release();
        m750 = 0;
    }
    if (m760) {
        m760->Release();
        m760 = 0;
    }
    q758.Fin_0027af50();
    H* hp = &h;
    int* p = hp->b + 4;
    int n = 4;
    do {
        --p;
        *p = 0;
    } while (--n);
    p = h.a + 0x100;
    n = 0x100;
    do {
        --p;
        *p = 0;
    } while (--n);
    Store* s = &h.st;
    s->vptr = g_s;
    ((Render::StoreBase *)s)->FUN_001c7720();
    s->Fin2_001c7500();
    hp->Fin_0027af50();
}


// 0x001c8790 FUN_001c8790 (120 B): equivalent/0x001c8790.cpp
// sym: ?FUN_001c8790@Holder_1c8790@fn_f9d12736@@QAE_NPBD@Z @987febfd7fe6 @w2ed7cf8dc80a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c8790 @ 0x001c8790
bool Holder_1c8790::FUN_001c8790(const char* name) {
    Id64_1c8790 tmp;
    tmp.FUN_0027b0e0(((char*)&DAT_003f335c));
    const Id64_1c8790* found = FUN_001c8060(name, ((char*)&DAT_004e23b0));
    if (found)
        tmp.FUN_0027af70(found);
    if ((tmp.lo | tmp.hi) != 0) {
        id.FUN_0027af70(&tmp);
        if ((tmp.lo | tmp.hi) != 0) {
            tmp.FUN_0027af50();
            return true;
        }
    }
    tmp.FUN_0027af50();
    return false;
}

} // namespace fn_f9d12736

// 0x001c8810 FUN_001c8810 (80 B): matches/0x001c8810.cpp
// sym: ?FUN_001c8810@Bag_1c8810@owners@@QAEXH@Z
void owners::Bag_1c8810::FUN_001c8810(hulk_intptr value) {
    if (((int)value) != 0) {
        unsigned int n = count;
        unsigned int i = 0;
        if (n > 0) {
            int* p = items;
            do {
                if (*p == ((int)value))
                    return;
                ++i;
                ++p;
            } while (i < count);
        }
        if (n < 0x100) {
            count = n + 1;
            items[n] = ((int)value);
        }
    }
}


// 0x001c8860 FUN_001c8860 (85 B): matches/0x001c8860.cpp
// sym: ?FUN_001c8860@C_1c8860@owners@@QAEXH@Z
void owners::C_1c8860::FUN_001c8860(int value) {
    unsigned int n = count;
    unsigned int i = 0;
    if (n > 0) {
        int* p = items;
        do {
            if (*p == value) {
                unsigned int m = n - 1;
                count = m;
                items[i] = items[m];
                return;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}

namespace fn_f9d12736 {

// 0x001c88f0 FUN_001c88f0 (1635 B): equivalent/0x001c88f0.cpp
// sym: ?FUN_001c88f0@Mgr_1c88f0@fn_f9d12736@@QAEXPAUCtx_1c88f0@2@@Z @1f8ca49270c9 @w364e46ed2e8f
// STATUS: equivalent (tools/equiv.py level 3: 110 inputs, branch coverage 83/92, incomplete)
// FUN_001c88f0 @ 0x001c88f0
void Mgr_1c88f0::FUN_001c88f0(Ctx_1c88f0 *ctx)
{
    Frame_1c88f0 f;
    f54c = 0;
    (*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f720(&DAT_004c5470, "Rendering");
    if ((*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f760("Draw Background", 0x62, 1)) {
        ctx->FUN_001c1330(0);
        if (f0c != 0) {
            (*(*(Gfx_1c88f0***)&DAT_0052c2ac))->vfunc_15(0);
            Vec3_1c88f0 *cp = ctx->FUN_001c1300();
            f.unit.x = cp->x;
            f.unit.y = cp->y;
            f.unit.z = cp->z;
            f.unit.y = 0.0f;
            ((GfxHolder *)(*(Gfx_1c88f0***)&DAT_0052c2ac))->FUN_00293d00(&f.unit);
            ctx->FUN_001c25c0(f0c, (hulk_intptr)DAT_004e2314, 0);
            (*(*(Gfx_1c88f0***)&DAT_0052c2ac))->vfunc_16(0);
            ctx->FUN_001c1340();
        }
        if (f08 != 0) {
            DAT_0052c2a8->vfunc_29(&f.tmp12, &f.r150, &f.dist, &f.alpha);
            DAT_0052c2a8->vfunc_28(f.tmp12 * 0.99f, f.r150, f.dist, f.alpha);
            ctx->FUN_001c25c0(f08, 0, 0);
            ctx->FUN_001c1370(0);
            DAT_0052c2a8->vfunc_28(f.tmp12, f.r150, f.dist, f.alpha);
        }
    }
    (*(Profiler_1c88f0**)&DAT_004dd6e8)->FUN_0023f740();
    sub18.FUN_001c75e0(&f10);
    Vec3_1c88f0 *cam = ctx->FUN_001c1300();
    f.pos.x = cam->x;
    f.pos.y = cam->y;
    f.pos.z = cam->z;
    Vec3_1c88f0 *fwd = ctx->FUN_001c12f0();
    f.dir.x = fwd->x;
    f.dir.y = fwd->y;
    f.dir.z = fwd->z;
    f.dir.y = 0.0f;
    f.dir.FUN_0022d110();
    f.r270 = DAT_004c53bc * DAT_004c53bc;
    f.r150 = DAT_004c53c0 * DAT_004c53c0;
    f.r295 = (DAT_004c53c4 + DAT_004c53bc) * (DAT_004c53c4 + DAT_004c53bc);

    int idx = 0;
    for (;;) {
        ItemA **list = list2c;
        if (list[idx] == 0) {
            int cnt = count28;
            while (!(idx > cnt)) {
                ItemA *n = list[idx + 1];
                idx++;
                if (n)
                    break;
            }
        }
        if (idx > count28)
            break;
        ItemA *it = list[idx];
        idx++;
        if (!it)
            break;
        if (!it->b8)
            continue;
        if ((*(char*)&DAT_004c53b8)) {
            f.v.x = f.pos.x;
            f.v.y = f.pos.y;
            f.v.z = f.pos.z;
            Vec3_1c88f0 *ip = it->FUN_001c6af0();
            float dx = f.v.x - ip->x;
            float dz = f.v.z - ip->z;
            bool show;
            if ((*(char*)&DAT_004e23a0)) {
                show = true;
            } else if (dz * dz + dx * dx < f.r150) {
                show = ctx->vis.FUN_001c2870(it->FUN_001c6ac0()) != 0;
            } else {
                show = false;
            }
            if (show)
                it->FUN_001c68c0(ctx);
        }
        char bl = 0;
        char *mode = ((Mode_1c88f0 *)((owners::C_86310 *)DAT_004dd6ec)->FUN_00086310())->FUN_000897f0();
        bool skipNear = false;
        if (mode[0] == 'd' && mode[1] == 't') {
            if ((*(char*)&DAT_004e23a0))
                skipNear = true;
            else
                bl = 1;
        } else if ((*(char*)&DAT_004e23a0)) {
            skipNear = true;
        }
        if (!skipNear) {
            Aim_1c88f0 *q = it->FUN_001c63e0();
            if (q->f0c != 0.0f) {
                if (!ctx->vis.FUN_001c2820(it->FUN_001c6ab0())) {
                    it->f58 = 0.0f;
                    continue;
                }
                if (!ctx->vis.FUN_001c2870(it->FUN_001c6aa0())) {
                    it->f58 = 0.0f;
                    continue;
                }
            }
        }
        f.c.x = f.pos.x;
        f.c.y = f.pos.y;
        f.c.z = f.pos.z;
        Aim_1c88f0 *q2 = it->FUN_001c63e0();
        f.c.x = f.c.x - q2->x;
        f.c.y = 0.0f;
        f.c.z = f.c.z - q2->z;
        f.dist = f.c.z * f.c.z + f.c.x * f.c.x;
        if (bl) {
            f.unit = f.c;
            f.unit.FUN_0022d110();
            f.dot = f.dir.z * f.unit.z + f.dir.x * f.unit.x + f.unit.y * f.dir.y;
            f.tmp12 = f.dot;
            *(int *)&f.tmp12 &= 0x7fffffff;
            float a = (2.0f - f.tmp12 * f.tmp12) * f.pos.y;
            float c1;
            if (a < 1.0f)
                c1 = 1.0f;
            else if (a <= 1.3f)
                c1 = a;
            else if (a > 1.3f)
                c1 = 1.3f;
            else
                c1 = 1.0f;
            float prod = c1 * f.dist;
            float b = 1.2f - f.pos.y * 0.004f;
            float c2;
            if (b < 1.0f)
                c2 = 1.0f;
            else if (b <= 1.3f)
                c2 = b;
            else if (b > 1.3f)
                c2 = 1.3f;
            else
                c2 = 1.0f;
            DAT_004c546c = c2 * 0.6f + DAT_004c546c * 0.4f;
            f.dist = prod * DAT_004c546c;
        }
        if (!(*(char*)&DAT_004e23a0) && !it->b9) {
            if (!(f.dist < f.r295)) {
                it->f58 = 0.0f;
                continue;
            }
        }
        f.alpha = 0.0f;
        if (!it->b9) {
            if (f.dist > f.r270)
                f.alpha = (float)((sqrt(f.dist) - DAT_004c53bc) / DAT_004c53c4);
        }
        if (it->f58 > f.alpha)
            f.alpha = it->f58;
        else
            it->f58 = 0.0f;
        it->FUN_001c6800(ctx, this, &ctx->vis, f.alpha);
    }

    ctx->FUN_001c1370(1);
    unsigned int n;
    ItemB **p;
    p = &items[0];
    for (n = 0; n < count538; n++, p++) {
        ItemB *m = *p;
        if (!m->bA8)
            continue;
        m->FUN_001c4b50(&f.v);
        if (!ctx->vis.FUN_001c2820(&f.v)) {
            ((owners::Target_1c4b20 *)m)->FUN_001c4b20();
            continue;
        }
        if (m->f14 == 0) {
            m->vfunc_3(ctx, this);
            continue;
        }
        unsigned int k;
        for (k = 0; k < 4; k++) {
            if (slots[k] == 0) {
                slots[k] = m;
                break;
            }
        }
        if (k == 4)
            m->vfunc_3(ctx, this);
    }
    ctx->FUN_001c1370(1);
    FUN_0027f250()->FUN_0027ff80();
    p = &items[0];
    for (n = 0; n < count538; n++, p++) {
        ItemB *m = *p;
        if (m->bA8) {
            m->FUN_001c4b50(&f.v);
            if (ctx->vis.FUN_001c2820(&f.v))
                FUN_001c84e0(ctx, m, &f.pos);
        }
    }
    for (int k = 0; k < 4; k++) {
        if (slots[k]) {
            slots[k]->vfunc_3(ctx, this);
            slots[k] = 0;
        }
    }
}


// 0x001c8f60 FUN_001c8f60 (108 B): matches/0x001c8f60.cpp
// sym: ??0LevelLoader@fn_f9d12736@@QAE@II@Z
LevelLoader::LevelLoader(hulk_uintptr a, hulk_uintptr b) {
    m4 = 0;
    m8 = 0x60000700;
    mc = 0;
    m10 = 0;
    vptr = ((hulk_intptr)DAT_00421abc);
    m14 = a;
    m18 = b;
    RoomLoader_1c8f60* t = Alloc_00263ea0(0x18);
    RoomLoader_1c8f60* r;
    if (t)
        r = t->Init_001c6d10(m14);
    else
        r = 0;
    m1c = r;
    r->Run();
}


// 0x001c8fd0 Render::LevelLoader::vfunc_2 (56 B): matches/0x001c8fd0.cpp
// sym: ?f2@LevelLoader_1c8fd0@fn_f9d12736@@QAEPAV12@E@Z
LevelLoader_1c8fd0* LevelLoader_1c8fd0::f2(unsigned char flags) {
    vptr = hulk_at_00421abc;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    vptr = g_vftable2;
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f9d12736

// 0x001c9030 FUN_001c9030 (258 B): equivalent/0x001c9030.cpp [wrapped: conflict: Render::Store; Render::World; pure3d::ShadowGenerator]
// sym: ??0World@Render@fn_001c9030@@QAE@XZ @cec9d731f3cf @w8682c1072ede
inline void* operator new(size_t, void* p) { return p; }
namespace fn_001c9030 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_001c9030 @ 0x001c9030
/* size_t: tree_prelude.h */

extern "C" void* __cdecl FUN_00263ea0(unsigned);
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct Small_1c9030 { char data[8]; void FUN_0027af00(); };
struct StoreBase { char data[0x120]; void FUN_001c77e0(int,int); };
namespace Render { struct Room; template<class T> struct Store { virtual void slot0(); char data[0x11c]; }; }
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(unsigned,int); };
struct Shader_1c9030 { virtual void init(); char pad[12]; Stream* stream; Shader_1c9030* FUN_0028edb0(); };
struct ShadowData { char data[12]; void FUN_002a30a0(); };
namespace pure3d { struct ShadowGenerator { virtual void init_00018b30(); unsigned value; ShadowData data; }; }
namespace Render { struct World {
virtual void slot0(); unsigned pad4,field8,fieldC; Small_1c9030 first; StoreBase rooms; unsigned entries[256]; unsigned field538; unsigned fields53c[4]; unsigned field54c; char pad550[0x200]; Shader_1c9030* resource; unsigned pad754; Small_1c9030 last; pure3d::ShadowGenerator* shadow; World();
}; }
Render::World::World() {
first.FUN_0027af00(); rooms.FUN_001c77e0(250,1); new (&rooms) Store<Room>;
for(int i=0;i<256;++i) entries[i]=0;
for(int j=0;j<4;++j) fields53c[j]=0;
last.FUN_0027af00();
for(int k=0;k<4;++k) fields53c[k]=0;
field538=0; field54c=0; field8=0; fieldC=0;
Shader_1c9030* r=(Shader_1c9030*)FUN_00263ea0(32); if(r) r=r->FUN_0028edb0(); resource=r; r->init(); resource->stream->s6(0x444d4c42,4);
pure3d::ShadowGenerator* s=(pure3d::ShadowGenerator*)FUN_0008d690((int)sizeof(pure3d::ShadowGenerator));
if(s) { s->value=0; new(s) pure3d::ShadowGenerator; s->data.FUN_002a30a0(); }
shadow=s; s->init_00018b30();
}
} // namespace fn_001c9030

namespace fn_f9d12736 {

// 0x001c9140 Render::World::vfunc_0 (30 B): matches/0x001c9140.cpp
// sym: ?vfunc_2@World_1c9140@fn_f9d12736@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
World_1c9140* World_1c9140::vfunc_2(unsigned char flags) {
    ((ThisCall_001c86e0*)(this))->FUN_001c86e0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f9d12736
