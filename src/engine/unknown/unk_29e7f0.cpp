// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029e7f0..0x0029f570 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa427f67 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa427f67 {} using namespace fn_fa427f67;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fa427f67 {
struct Vec3_29e7f0 {
    float x, y, z;
};
namespace pure3d {
class Light {
public:
    virtual void v0();
    char pad04[0xf];
    char enabled;               // 0x13
    int id;                     // 0x14
    void FUN_002a0800(float* x, float* y, float* z);
};
}
namespace pure3d {
class DirectionalLight : public Light {
public:
    void FUN_002a2f20(float* x, float* y, float* z);
};
}
namespace pure3d {
class PointLight : public Light {
public:
    void FUN_002c3f20(float* a, float* b, float* c);
};
}
namespace pure3d {
class SpotLight : public Light {
public:
    void FUN_002c41c0(float* a, float* b, float* c);
    void FUN_002c4200(float* a, float* b, float* c);
    void FUN_002c4150(float* x, float* y, float* z);
};
}
struct LightRec_29e7f0 {
    char pad00[4];
    int type;                   // 0x04
    int id;                     // 0x08
    Vec3_29e7f0 pos;                   // 0x0c
    Vec3_29e7f0 dir;                   // 0x18
    float a, b, c;              // 0x24
    char pad30[0x40 - 0x30];
    void FUN_0029c240(int id, float* v2, float* v1, float r0, float r1, float r2, float q0,
                      float q1, float q2);
};
struct LightSet_29e7f0 {
    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    pure3d::Light** items;      // 0x18
};
class LightList_29e7f0 {
public:
    void FUN_0029e7f0(LightSet_29e7f0* set, Vec3_29e7f0* ambient, int tag);

    char pad00[0x10];
    int capacity;               // 0x10
    int count;                  // 0x14
    char pad18[4];
    int tag;                    // 0x1c
    char pad20[4];
    LightRec_29e7f0* recs;             // 0x24
    Vec3_29e7f0 ambient;               // 0x28
    char pad34[4];
    char anyEnabled;            // 0x38
};
struct Frame_29e7f0 {
    int n;
    int i;
    float c, b, a;              // point light attenuation, read back in reverse
    float q2, q1, q0;           // spot light
    float r2, r1, r0;
    Vec3_29e7f0 dirV;
    Vec3_29e7f0 pointV;
    Vec3_29e7f0 v1;
    Vec3_29e7f0 v2;
};
struct Vec3_29ea40 {
    float x, y, z;
};
void* FUN_00263ea0(unsigned int size);
class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7(Vec3_29ea40 v);
    virtual void v8();
    virtual void v9();
    void FUN_002a0820(char flag);
    void FUN_002a07a0(int value);
};
class PointLight : public Light {
public:
    PointLight* FUN_002c3e10();
    void FUN_002c3f00(Vec3_29ea40 v);
};
class SpotLight : public Light {
public:
    SpotLight* FUN_002c4020();
    void FUN_002c4130(Vec3_29ea40 v);
    void FUN_002c41a0(Vec3_29ea40 v);
};
class DirectionalLight : public Light {
public:
    DirectionalLight* FUN_002a2e70();
    void FUN_002a2ef0(Vec3_29ea40 v);
};
struct LightRec_29ea40 {
    int f0;
    int kind;
    int value;
    Vec3_29ea40 v0c;
    Vec3_29ea40 v18;
    Vec3_29ea40 v24;
    Vec3_29ea40 v30;
    int pad3c;
};
struct LightList_29ea40 {
    char pad0[0x10];
    int size;
    int count;
    Light** items;
    void FUN_002a0fc0(int index, Light* light);
};
class LightSetup_29ea40 {
public:
    char pad0[0x14];
    int count;
    char pad18[0x24 - 0x18];
    LightRec_29ea40* recs;
    void FUN_0029ea40(LightList_29ea40* list);
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
struct LightGroup_29ecb0 {
 virtual void initialize();
 LightGroup_29ecb0* FUN_002a1140(int count);
};
struct Entry_29ecb0 { unsigned int first; unsigned int unused1; unsigned int second; char unused2[12]; unsigned int third; unsigned int unused3; };
struct Container_29ecb0 {
 LightGroup_29ecb0* manager;
 Entry_29ecb0* entries;
 int count;
 Container_29ecb0* FUN_0029ecb0(int n);
};
struct Source_29eda0 {
    float *FUN_002a0870();
    char pad0[0x12];
    char flag12;
    char flag13;
    char pad14[0x50 - 0x14];
    int mode;
};
struct Entry_29eda0 {
    int f0;
    unsigned color;
    float radiusSq;
    char pad0c[0x18 - 0xc];
    unsigned flags;
    int f1c;
};
struct Backend_29eda0 {
    void FUN_002a0fc0(int index, Source_29eda0 *src);
};
class EntryTable_29eda0 {
public:
    Backend_29eda0 *backend;
    Entry_29eda0 *entries;
    void FUN_0029eda0(int index, Source_29eda0 *src);
};
struct DirectionalLight_29ef40 {
    DirectionalLight_29ef40* FUN_002a2e70();
};
struct ProximityLight_29ef40 {
    ProximityLight_29ef40* FUN_002c3c10();
};
class LightGroup_29ef40 {
public:
    virtual void v0();
    LightGroup_29ef40* FUN_002a1140(int size);
    void FUN_002a0fc0(int index, void* cell);
};
class GridSet {
public:
    LightGroup_29ef40* grids[4];
    int width;
    int height;
    GridSet* FUN_0029ef40(int w, int h);
};
struct Item_29f0b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(int index);
};
struct List_29f0b0 { char pad[16]; int capacity; int count; Item_29f0b0** items; };
} // namespace fn_fa427f67
struct Gfx {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void setValue(int value); virtual int* getValue(List_29f0b0** output); virtual void s37(); virtual void clear(int index,int value); virtual bool has(int index);
};
namespace fn_fa427f67 {
struct Target_29f0b0 { char pad[16]; int capacity; void FUN_0029f0b0(List_29f0b0* list, int* value); };
struct Item_29f280 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
struct Container_29f280 {
    char pad[0x10];
    int count;
    char pad2[4];
    Item_29f280** items;
};
struct Receiver_29f280 {
    void second_002a0fc0(int, Item_29f280*);
};
struct Obj_29f280 {
    Container_29f280* container;
    char pad[8];
    Receiver_29f280* receiver;
    int n;
};
class Item_29f2e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class List_29f2e0 {
  public:
    char pad0[0x10];
    int count;
    char pad14[4];
    Item_29f2e0** items;
    void process_002a0fc0(int, Item_29f2e0*);
};
class Obj_29f2e0 {
  public:
    char pad0[4];
    List_29f2e0* data;
    char pad8[4];
    List_29f2e0* list;
    int n;
    hulk_intptr run();
};
class Item_29f340 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void q();
    virtual void f();
    virtual void g();
};
struct Arr_29f340 {
    char x[16];
    int count;
    char y[4];
    Item_29f340** items;
};
struct Context {
    void process_002a0fc0(int, Item_29f340*);
};
struct Obj_29f340 {
    char x[8];
    Arr_29f340* arr;
    Context* ctx;
    char y[4];
    int n;
    hulk_intptr run();
};
struct Tmp_29f3a0 {
    char pad[0x18];
    Tmp_29f3a0(void*);
    void Run_00231180(int, int);
};
struct C_29f3a0 {
    void F(int, int);
};
struct Source_29f4d0 {
    char pad00[0x4c];
    int x, y, z;
};
struct Entry_29f4d0 {
    int x, y, z;
    char pad0c[4];
    Source_29f4d0 *source;
    int f14;
    int key;
};
struct Container_29f4d0 {
    char data[0x2c];
    void FUN_00231590(int key, int flags, Entry_29f4d0 *e);
};
struct Finder_29f4d0 {
    char data[0x18];
    void FUN_00231160(Container_29f4d0 *c);
    Entry_29f4d0 *FUN_00231180(int key, int flags);
};
class Cache_29f4d0 {
public:
    char pad00[4];
    Container_29f4d0 container;
    Entry_29f4d0 **pool;
    char pad34[4];
    int poolCount;

    void FUN_0029cb70(int n);
    void FUN_0029f4d0(int key, Source_29f4d0 *src);
};


// 0x0029e7f0 FUN_0029e7f0 (579 B): equivalent/0x0029e7f0.cpp
// sym: ?FUN_0029e7f0@LightList_29e7f0@fn_fa427f67@@QAEXPAULightSet_29e7f0@2@PAUVec3_29e7f0@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 16013 inputs, branch coverage 18/18)
// FUN_0029e7f0 @ 0x0029e7f0
// FUN_0029e7f0 @ 0x0029e7f0
void LightList_29e7f0::FUN_0029e7f0(LightSet_29e7f0* set, Vec3_29e7f0* ambientColor, int newTag)
{
    Frame_29e7f0 f;
    f.n = 0;
    anyEnabled = 0;
    for (f.i = 0; f.i < set->count; f.i++) {
        if (f.n >= capacity)
            break;
        if (f.i >= set->capacity)
            continue;
        pure3d::Light* light = set->items[f.i];
        if (!light)
            continue;
        if (light->enabled)
            anyEnabled = 1;

        pure3d::DirectionalLight* dl = dynamic_cast<pure3d::DirectionalLight*>(light);
        if (dl) {
            dl->FUN_002a2f20(&f.dirV.x, &f.dirV.y, &f.dirV.z);
            LightRec_29e7f0* rec = &recs[f.n];
            int id = dl->id;
            rec->type = 0;
            rec->id = id;
            rec->dir = f.dirV;
            f.n++;
            continue;
        }
        pure3d::PointLight* pl = dynamic_cast<pure3d::PointLight*>(light);
        if (pl) {
            pl->FUN_002c3f20(&f.a, &f.b, &f.c);
            pl->FUN_002a0800(&f.pointV.x, &f.pointV.y, &f.pointV.z);
            LightRec_29e7f0* rec = &recs[f.n];
            int id = pl->id;
            rec->type = 1;
            rec->id = id;
            rec->pos = f.pointV;
            rec->a = f.a;
            rec->b = f.b;
            rec->c = f.c;
            f.n++;
            continue;
        }
        pure3d::SpotLight* sl = dynamic_cast<pure3d::SpotLight*>(light);
        if (sl) {
            sl->FUN_002c41c0(&f.q0, &f.q1, &f.q2);
            sl->FUN_002c4200(&f.r0, &f.r1, &f.r2);
            sl->FUN_002a0800(&f.v2.x, &f.v2.y, &f.v2.z);
            sl->FUN_002c4150(&f.v1.x, &f.v1.y, &f.v1.z);
            recs[f.n].FUN_0029c240(sl->id, &f.v2.x, &f.v1.x, f.r0, f.r1, f.r2, f.q0, f.q1, f.q2);
            f.n++;
        }
    }
    count = f.n;
    ambient = *ambientColor;
    tag = newTag;
}


// 0x0029ea40 FUN_0029ea40 (574 B): equivalent/0x0029ea40.cpp
// sym: ?FUN_0029ea40@LightSetup_29ea40@fn_fa427f67@@QAEXPAULightList_29ea40@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 32/32)
// FUN_0029ea40 @ 0x0029ea40
void LightSetup_29ea40::FUN_0029ea40(LightList_29ea40* list)
{
    for (int i = 0; i < list->count; i++) {
        Light* light = 0;
        if (i < list->size)
            light = list->items[i];

        if (count <= i) {
            if (light)
                light->FUN_002a0820(0);
            list->FUN_002a0fc0(i, 0);
            continue;
        }

        switch (recs[i].kind) {
        case 0: {
            DirectionalLight* d = dynamic_cast<DirectionalLight*>(light);
            if (d == 0) {
                void* mem = FUN_00263ea0(0x68);
                d = mem ? ((DirectionalLight*)mem)->FUN_002a2e70() : 0;
                light = d;
            }
            d->FUN_002a2ef0(recs[i].v18);
            break;
        }
        case 1: {
            PointLight* p = dynamic_cast<PointLight*>(light);
            if (p == 0) {
                void* mem = FUN_00263ea0(0x68);
                p = mem ? ((PointLight*)mem)->FUN_002c3e10() : 0;
                light = p;
            }
            p->vfunc_7(recs[i].v0c);
            p->FUN_002c3f00(recs[i].v24);
            break;
        }
        case 2: {
            SpotLight* s = dynamic_cast<SpotLight*>(light);
            if (s == 0) {
                void* mem = FUN_00263ea0(0x80);
                s = mem ? ((SpotLight*)mem)->FUN_002c4020() : 0;
                light = s;
            }
            s->vfunc_7(recs[i].v0c);
            s->FUN_002c4130(recs[i].v18);
            s->FUN_002c41a0(recs[i].v24);
            recs[i].v30 = recs[i].v30; // x87 load/store round trip in the original (quiets signalling NaNs)
            break;
        }
        default:
            if (light) {
                light->FUN_002a0820(0);
                light = 0;
            }
            list->FUN_002a0fc0(i, light);
            continue;
        }

        if (light) {
            light->FUN_002a0820(1);
            light->FUN_002a07a0(recs[i].value);
        }
        list->FUN_002a0fc0(i, light);
    }
    ((owners::A_2a1180 *)list)->FUN_002a1180(count);
}


// 0x0029ecb0 FUN_0029ecb0 (233 B): equivalent/0x0029ecb0.cpp
// sym: ?FUN_0029ecb0@Container_29ecb0@fn_fa427f67@@QAEPAU12@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 277 inputs, branch coverage 10/10)
// FUN_0029ecb0 @ 0x0029ecb0
Container_29ecb0* Container_29ecb0::FUN_0029ecb0(int n) {
 count = n;
 LightGroup_29ecb0* allocation = (LightGroup_29ecb0*)FUN_00263ea0(0x28);
 manager = allocation ? allocation->FUN_002a1140(n) : 0;
 manager->initialize();
 entries = (Entry_29ecb0*)FUN_0008d6d0((unsigned int)n * 32);
 for (int i = 0; i < n; ++i) {
 entries[i].first = 0;
 entries[i].second = 0;
 entries[i].third = 0;
 }
 return this;
}


// 0x0029eda0 FUN_0029eda0 (402 B): equivalent/0x0029eda0.cpp
// sym: ?FUN_0029eda0@EntryTable_29eda0@fn_fa427f67@@QAEXHPAUSource_29eda0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 18/18)
// FUN_0029eda0 @ 0x0029eda0
void EntryTable_29eda0::FUN_0029eda0(int index, Source_29eda0 *src)
{
    backend->FUN_002a0fc0(index, src);
    entries[index].f0 = 0;
    entries[index].color = (*(unsigned*)&DAT_004cf730);
    entries[index].f1c = 0;
    entries[index].flags = 0;
    if (!src)
        return;

    if (((int)((owners::C_2a0850 *)src)->FUN_002a0850()) == 1) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = *p;
        float v = entries[index].radiusSq;
        entries[index].radiusSq = v * v;
    } else if (((int)((owners::C_2a0850 *)src)->FUN_002a0850()) == 2) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
    } else if (((int)((owners::C_2a0850 *)src)->FUN_002a0850()) == 3) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
    } else {
        entries[index].radiusSq = 1.0e12f;
    }

    if (src->mode != 2 && src->flag12)
        entries[index].flags |= 4;
    else
        entries[index].flags &= ~4u;

    if (src->flag13)
        entries[index].flags |= 8;
    else
        entries[index].flags &= ~8u;

    entries[index].flags &= ~0x13u;
    int mode = src->mode;
    if (mode == 0)
        entries[index].flags |= 0x11;
    else if (mode == 2)
        entries[index].flags |= 0x12;
}


// 0x0029ef40 FUN_0029ef40 (357 B): equivalent/0x0029ef40.cpp
// sym: ?FUN_0029ef40@GridSet@fn_fa427f67@@QAEPAV12@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_0029ef40 @ 0x0029ef40
GridSet* GridSet::FUN_0029ef40(int w, int h)
{
    int i;
    void* mem;
    width = w > 1 ? w : 1;
    height = h > 1 ? h : 1;

    mem = FUN_00263ea0(0x28);
    grids[0] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    grids[1] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    grids[2] = mem ? ((LightGroup_29ef40*)mem)->FUN_002a1140(width) : 0;
    mem = FUN_00263ea0(0x28);
    if (mem) {
        int n = width;
        if (!(width >= height))
            n = height;
        grids[3] = ((LightGroup_29ef40*)mem)->FUN_002a1140(n);
    } else {
        grids[3] = 0;
    }
    grids[0]->v0();
    grids[1]->v0();
    grids[2]->v0();
    grids[3]->v0();

    for (i = 0; i < width; i++) {
        mem = FUN_00263ea0(0x68);
        DirectionalLight_29ef40* a = mem ? ((DirectionalLight_29ef40*)mem)->FUN_002a2e70() : 0;
        grids[0]->FUN_002a0fc0(i, a);
        mem = FUN_00263ea0(0x68);
        ProximityLight_29ef40* b = mem ? ((ProximityLight_29ef40*)mem)->FUN_002c3c10() : 0;
        grids[1]->FUN_002a0fc0(i, b);
        grids[3]->FUN_002a0fc0(i, 0);
    }
    for (i = 0; i < height; i++) {
        mem = FUN_00263ea0(0x68);
        DirectionalLight_29ef40* a = mem ? ((DirectionalLight_29ef40*)mem)->FUN_002a2e70() : 0;
        grids[2]->FUN_002a0fc0(i, a);
    }
    return this;
}


// 0x0029f0b0 FUN_0029f0b0 (181 B): equivalent/0x0029f0b0.cpp
// sym: ?FUN_0029f0b0@Target_29f0b0@fn_fa427f67@@QAEXPAUList_29f0b0@2@PAH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2159 inputs, branch coverage 20/20)
// FUN_0029f0b0 @ 0x0029f0b0
void Target_29f0b0::FUN_0029f0b0(List_29f0b0* list, int* value) {
 int i=0;
 if(list) { int count=list->count; while(i<count) { if(i>=capacity || i>=list->capacity) break; Item_29f0b0* item=list->items[i]; if(!item) break; item->slot5(i); ++i; } }
 while(i<capacity) { if(!DAT_0052c2a8->has(i)) break; DAT_0052c2a8->clear(i,0); ++i; }
 int* current=DAT_0052c2a8->getValue(&list);
 if(*current!=*value) DAT_0052c2a8->setValue(*value);
}


// 0x0029f280 FUN_0029f280 (81 B): matches/0x0029f280.cpp
// sym: ?FUN_0029f280@fn_fa427f67@@YIPAHPAUObj_29f280@1@@Z
int* __fastcall FUN_0029f280(Obj_29f280* self) {
    ((owners::A_2a1180 *)(self->receiver))->FUN_002a1180(self->n);
    for (int i = 0; i < self->n; ++i) {
        Container_29f280* c = self->container;
        Item_29f280* item = i < c->count ? c->items[i] : (Item_29f280*)0;
        item->f6();
        self->receiver->second_002a0fc0(i, item);
    }
    return (int*)self->receiver;
}


// 0x0029f2e0 FUN_0029f2e0 (82 B): matches/0x0029f2e0.cpp
// sym: ?run@Obj_29f2e0@fn_fa427f67@@QAEHXZ
hulk_intptr Obj_29f2e0::run() {
    ((owners::A_2a1180 *)list)->FUN_002a1180(n);
    int i = 0;
    if (n > 0) {
        do {
            Item_29f2e0* x;
            if (i < data->count)
                x = data->items[i];
            else
                x = 0;
            x->f6();
            list->process_002a0fc0(i, x);
            ++i;
        } while (i < n);
    }
    return (hulk_intptr)list;
}


// 0x0029f340 FUN_0029f340 (82 B): matches/0x0029f340.cpp
// sym: ?run@Obj_29f340@fn_fa427f67@@QAEHXZ
hulk_intptr Obj_29f340::run() {
    ((owners::A_2a1180 *)ctx)->FUN_002a1180(n);
    int i = 0;
    if (n > 0)
        do {
            Item_29f340* p;
            if (i < arr->count)
                p = arr->items[i];
            else
                p = 0;
            p->f();
            ctx->process_002a0fc0(i, p);
            ++i;
        } while (i < n);
    return (hulk_intptr)ctx;
}


// 0x0029f3a0 FUN_0029f3a0 (38 B): matches/0x0029f3a0.cpp
// sym: ?F@C_29f3a0@fn_fa427f67@@QAEXHH@Z
// Same code shape as 0x00236630 (propagated; names are from that function)
void C_29f3a0::F(int a, int b) {
    Tmp_29f3a0 t(this);
    t.Run_00231180(a, b);
}

} // namespace fn_fa427f67

// 0x0029f3d0 FUN_0029f3d0 (247 B): equivalent/0x0029f3d0.cpp [wrapped: compile error C2039: 'FUN_0029e6c0' : is not a member of 'fn_fa427f67::pure3d::Light']
// sym: ??0CacheManager@LightsChooser@pure3d@fn_0029f3d0@@QAE@PAXH@Z
namespace fn_0029f3d0 {
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 14/14)
// FUN_0029f3d0 @ 0x0029f3d0
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
void* __cdecl FUN_00263ea0(unsigned int);
struct Pool_29f3d0 { char data[0x24]; void FUN_00231550(int,int,int); };
struct Helper_29f3d0 { void FUN_00231160(Pool_29f3d0*); };
struct Light { virtual void slot0(); Light* FUN_0029e6c0(void*); };
struct Entry_29f3d0 { char data[12]; Light* light; unsigned int a,b,c; };
struct EntryArray { int count; Entry_29f3d0 entries[1]; };
namespace pure3d { struct LightsChooser { struct CacheManager {
 virtual void slot0();
 Pool_29f3d0 pool;
 Helper_29f3d0* helper;
 Entry_29f3d0* entries;
 Entry_29f3d0** pointers;
 int count;
 int available;
 CacheManager(void* context,int n);
}; }; }
pure3d::LightsChooser::CacheManager::CacheManager(void* context,int n) {
 pool.FUN_00231550(n*2,0x50,0x64);
 count=n; available=n;
 Helper_29f3d0* h=(Helper_29f3d0*)FUN_0008d690(0x18);
 if(h) h->FUN_00231160(&pool);
 helper=h;
 int length=count;
 EntryArray* block=(EntryArray*)FUN_0008d6d0(length*0x1c+4);
 Entry_29f3d0* result=0;
 if(block) {
  block->count=length;
  result=block->entries;
  if(length-1>=0) for(int i=0;i<length;++i) {
   result[i].light=0; result[i].a=0; result[i].b=0; result[i].c=0;
  }
 }
 entries=result;
 pointers=(Entry_29f3d0 **)FUN_0008d6d0(count * sizeof(Entry_29f3d0 *));
 for(int i=0;i<count;++i) {
  Light* light=(Light*)FUN_00263ea0(0x48);
  if(light) light=light->FUN_0029e6c0(context);
  entries[i].light=light;
  entries[i].light->slot0();
  pointers[i]=&entries[i];
 }
}
} // namespace fn_0029f3d0

namespace fn_fa427f67 {

// 0x0029f4d0 FUN_0029f4d0 (157 B): equivalent/0x0029f4d0.cpp
// sym: ?FUN_0029f4d0@Cache_29f4d0@fn_fa427f67@@QAEXHPAUSource_29f4d0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 10/10)
// FUN_0029f4d0 @ 0x0029f4d0
// FUN_0029f4d0: find (or take from the free pool) the entry for a key and fill it from a source object
void Cache_29f4d0::FUN_0029f4d0(int key, Source_29f4d0 *src)
{
    Finder_29f4d0 finder;
    finder.FUN_00231160(&container);
    Entry_29f4d0 *e = finder.FUN_00231180(key, 0);
    if (e == 0) {
        if (poolCount == 0) {
            FUN_0029cb70(5);
            if (poolCount == 0)
                FUN_0029cb70(2);
        }
        if (poolCount != 0) {
            poolCount--;
            e = pool[poolCount];
            e->key = key;
        }
        container.FUN_00231590(key, 0, e);
        if (e == 0)
            return;
    }
    e->x = src->x;
    e->y = src->y;
    e->z = src->z;
    e->source = src;
    e->f14 = *(*(int**)&DAT_0052c2b4);
}

} // namespace fn_fa427f67
