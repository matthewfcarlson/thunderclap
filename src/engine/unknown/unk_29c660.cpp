// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029c660..0x0029e7b0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3bb83d9 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3bb83d9 {} using namespace fn_f3bb83d9;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f3bb83d9 {
struct Entry_29c660 { int first; int pad4; int second; char pad12[12]; int third; int pad28; };
struct Owner_29c660 { char pad[20]; int count; void FUN_002a0fc0(int index,int zero); };
struct Target_29c660 { Owner_29c660* owner; Entry_29c660* entries; int count; void reset(); };
class Item_29ca20 {
  public:
    virtual void F();
    virtual void G();
};
class Target_29ca20 {
  public:
    Item_29ca20* a;
    Item_29ca20* b;
    Item_29ca20* c;
    Item_29ca20* d;
    void Run();
};
struct Manager_29ca50 {
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
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38(int, int);
};
extern Manager_29ca50* hulk_at_0052c2a8;
class Target_29ca50 {
    char pad[0x10];

  public:
    int count;
    void run();
};
struct Entry_29cb70 {
    char pad0[0x14];
    unsigned int lifetime;
    int payload;
};
class Sub_29cb70 {
public:
    char pad0[0x28];
    void FUN_00231590(int payload, int flag, Entry_29cb70* entry);
};
class Pool_29cb70 {
public:
    char pad0[4];
    Sub_29cb70 sub;
    Entry_29cb70* entries;
    Entry_29cb70** finished;
    int count;
    int finishedCount;

    void FUN_0029cb70(unsigned int since);
};
class Inner_29cc40 {
  public:
    virtual void a();
    virtual void b();
};
void thunk2_0008d340(void*);
class Target_29cc40 {
  public:
    Inner_29cc40* mObj;
    void* mArg;
    Target_29cc40* run(unsigned char flags);
};
class Item_29cc70 {
  public:
    virtual void f0();
    virtual void f1();
};
class Owner_29cc70 {
  public:
    Item_29cc70* a[4];
    Owner_29cc70* run(unsigned char);
};
extern void __cdecl cleanup_0008d330(Owner_29cc70*);
struct Item_29ccb0 {
    char pad0[0x14];
    unsigned int packed;
    void FUN_002a07a0(unsigned int color);
};
struct ItemList_29ccb0 {
    char pad0[0x10];
    int capacity;
    int count;
    Item_29ccb0 **items;
};
class Shader {
public:
    char pad0[0x14];
    float scale;
    void FUN_0029ccb0(ItemList_29ccb0 *list, float amount);
};
struct Vec3_29ce40 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Light {
    char pad00[0x11];
    char active;                // 0x11
    char pad12[2];
    unsigned int color;         // 0x14 (0x00RRGGBB)
    Vec3_29ce40 pos;                   // 0x18
    char pad24[0x64 - 0x24];
    float strength;             // 0x64

    hulk_freg FUN_002a0d00(Vec3_29ce40* p);
};
struct LightList_29ce40 {
    char pad00[0x10];
    int count;                  // 0x10
    int size;                   // 0x14
    Light** items;              // 0x18
};
struct LightDesc {
    char pad00[0x18];
    unsigned char flags;        // 0x18
    char pad19[7];
};
struct LightSet_29ce40 {
    LightList_29ce40* list;            // 0x00
    LightDesc* descs;           // 0x04
};
struct DynLightSet {
    LightList_29ce40* list;            // 0x00
};
class Lighting {
public:
    void FUN_0029ce40(Vec3_29ce40* out, Vec3_29ce40* p);

    char pad00[0x28];
    char frozen;                // 0x28
    char pad29[3];
    LightSet_29ce40* statics;          // 0x2c
    char pad30[0x3c - 0x30];
    DynLightSet* dynamics;      // 0x3c
};
struct Vec3_29d2c0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Source_29d2c0 {
    char pad0[0x11];
    unsigned char active;
    char pad12[2];
    unsigned int color;
    Vec3_29d2c0 pos;
    float FUN_002a0d00(const Vec3_29d2c0 *p);
    void FUN_002c3f20(float *a, float *b, float *c);
};
struct SourceList {
    char pad0[0x10];
    int size;
    int count;
    Source_29d2c0 **items;
};
struct Particle_29d2c0 {
    float life;
    unsigned int color;
    float radius2;
    Vec3_29d2c0 dir;
    unsigned int mask;
    unsigned int pad1c;
};
struct Pool_29d2c0 {
    SourceList *list;
    Particle_29d2c0 *particles;
};
int __cdecl FUN_0009fa70(const int *value, const int *lo, const int *hi);
class Emitter_29d2c0 {
public:
    char pad0[0x18];
    int active;
    char pad1c[0x34 - 0x1c];
    Pool_29d2c0 *pool;
    float FUN_0029d2c0(const Vec3_29d2c0 *pos, unsigned int mask);
};
class Obj_29dcc0 {
  public:
    char pad[0x18];
    int field;
    char pad2[0x0c];
    char flag;
    float FnA_0029d090(int, int);
    float FnB_0029d2c0(int, int);
    float FnC_0029d880(int, int);
    float FnD_0029d5d0(int, int);
    hulk_freg F(int, int);
};
struct Hdr {
    char pad0[0x14];
    int count;
};
namespace pure3d {
class Entity_29df90 {
public:
    virtual void v0();
};
}
namespace pure3d {
class Light_29df90 : public Entity_29df90 {
public:
    virtual void v1();
};
}
namespace pure3d {
class DirectionalLight_29df90 : public Light_29df90 {
public:
    char pad04[0x13 - 4];
    char flag13;
    char pad14[0x68 - 0x14];
    DirectionalLight_29df90 *FUN_002a2e70();
    void FUN_002a07a0(unsigned int color);
    void FUN_002a2fc0(V3 *v);
};
}
struct Group {
    char pad0[0x10];
    int size;                   // 0x10
    int count;                  // 0x14
    pure3d::Light_29df90 **items;      // 0x18
    void FUN_002a0fc0(int index, pure3d::Light_29df90 *light);
};
struct Entry {
    float weight;               // 0x00
    unsigned int color;         // 0x04
    char pad08[4];
    V3 dir;                     // 0x0c
    unsigned int flags;         // 0x18
    char pad1c[4];
};
struct Slots {
};
struct Table {
    Slots *slots;
    Entry *entries;             // 0x04
    void FUN_0029c660();
};
union Arg2 {
    float *rgb;
    float scale;
};
union Arg3 {
    int mode;
    char flag;
};
void *thunk_FUN_0008d690(unsigned int size);
class Manager {
public:
    char pad0[0x40];
    Table *table;               // 0x40
    hulk_freg FUN_0029dcc0(int mode, int n);
    hulk_freg FUN_0029dd30(Table *t);
    void FUN_0029df90(Group *group, Arg2 a2, Arg3 a3);
};
extern char DAT_004c534c[];
extern char DAT_004cf658[];
void *__cdecl FUN_00263ea0(unsigned int size);
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct V3_29e320 {
    float x, y, z;
};
struct Node {
  public:
    float key;
    int f4;
    char _m_pad_8[0x4];
    float vx;
    float vy;
    float vz;
    char _m_pad_18[0x4];
    Node *next;
    Node *FUN_002a2e70();
    void FUN_002a07a0(unsigned int color);
    void FUN_002a2fc0(const V3_29e320 *pos);
};
struct Block {
    Hdr *hdr;
    Node *elems;
};
struct Sorter {
    Node *head;
    Node sentinel;
    int capacity;
};
class SortedMerge {
public:
    char pad00[0x28];
    char extra;
    char pad29[7];
    Block *blocks[4];
    char pad40[8];
    Sorter *sorter;
    hulk_freg FUN_0029dd30(Block *out);
};
struct Container_29e320 {
    char pad0[0x10];
    int count;              // 0x10
    int size;               // 0x14
    Node **items;           // 0x18
    void FUN_002a0fc0(int index, Node *node);
};
struct List_29e320 {
};
struct Rec_29e320 {                // 0x20 bytes
    int f00;
    unsigned int color;     // 0x04
    int f08;
    V3_29e320 pos;                 // 0x0c
    int f18;
    int f1c;
};
struct Holder40 {
    List_29e320 *list;
    Rec_29e320 *recs;
    void FUN_0029c660();
};
union Arg3_29e320 {
    int value;
    char flag;
};
static inline int ColorMax(unsigned int c)
{
    int m = c & 0xff;
    int g = (c >> 8) & 0xff;
    if (g >= m)
        m = g;
    int b = (c >> 16) & 0xff;
    if (b >= m)
        m = b;
    return m;
}
class Effect_29e320 {
public:
    char pad0[0x40];
    Holder40 *f40;
    hulk_freg FUN_0029dcc0(int a, int b);
    hulk_freg FUN_0029dd30(Holder40 *h);
    void FUN_0029e320(Container_29e320 *c, V3_29e320 *p, Arg3_29e320 a3);
};
struct Target_29e5c0 {
    bool FUN_0022d2b0(void* p, int v);
};
struct Counter_29e5c0 {
    char pad0[0x1c];
    int f1c;
    int f20;
    char pad24[4];
    char buf[0x10];
    char flag;
    char pad39[3];
    int count;
    int reload;
};
struct Tracker_29e5c0 {
    char pad0[0x24];
    int id;
    hulk_freg FUN_0029dcc0(Target_29e5c0* t, int mode);
    bool FUN_0029e5c0(Target_29e5c0* t, Counter_29e5c0* c);
};
struct ItemList {
    char pad[0x10];
    int capacity;
    int count;
    void** items;
};
struct Grow_29e640 {
};
struct Item_29e680 {
    void Func_002a0820(int);
};
struct Obj_29e680 {
    char pad[0x10];
    int limit;
    int count;
    Item_29e680** items;
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
struct Entry_29e6c0 {
 unsigned char active; char pad[3];
 unsigned int a; int index; unsigned int c,d,e,f,g;
 float x,y;
 unsigned int h,i,j,k,l;
 float limit;
};
struct FUN_0027b070 {
 virtual void placeholder();
 char pad[12];
 FUN_0027b070();
};
namespace pure3d {
struct LightsChooserCache : FUN_0027b070 {
 int count; unsigned int f14,f18; int f1c; float f20; Entry_29e6c0* entries;
 unsigned int f28,f2c,f30,color;
 unsigned char flag; char pad38[3]; unsigned int f3c,f40;
 virtual void placeholder();
 LightsChooserCache(hulk_intptr);
};
}


// 0x0029c660 FUN_0029c660 (194 B): equivalent/0x0029c660.cpp
// sym: ?reset@Target_29c660@fn_f3bb83d9@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0029c660 @ 0x0029c660
void Target_29c660::reset() { for(int i=count-1;i>=0;--i) { entries[i].first=0; entries[i].second=0; entries[i].third=0; } for(int j=owner->count-1;j>=0;--j) owner->FUN_002a0fc0(j,0); }


// 0x0029ca20 FUN_0029ca20 (35 B): matches/0x0029ca20.cpp
// sym: ?Run@Target_29ca20@fn_f3bb83d9@@QAEXXZ
void Target_29ca20::Run() {
    d->G();
    c->G();
    b->G();
    a->G();
}


// 0x0029ca50 FUN_0029ca50 (44 B): matches/0x0029ca50.cpp
// sym: ?run@Target_29ca50@fn_f3bb83d9@@QAEXXZ
void Target_29ca50::run() {
    int i = 0;
    if (count > 0)
        do {
            hulk_at_0052c2a8->f38(i, 0);
            ++i;
        } while (i < count);
}


// 0x0029cb70 FUN_0029cb70 (140 B): equivalent/0x0029cb70.cpp
// sym: ?FUN_0029cb70@Pool_29cb70@fn_f3bb83d9@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 10/10)
// FUN_0029cb70 @ 0x0029cb70
// Age the pool's entries by the time elapsed since `since`: expire the ones whose lifetime is used up
// and queue the finished ones for reuse.
void Pool_29cb70::FUN_0029cb70(unsigned int since)
{
    unsigned int now = *(*(unsigned int**)&DAT_0052c2b4);
    if (now > since) {
        since = now - since;
    } else {
        since = 1;
    }
    ((owners::X_231070 *)&sub)->FUN_00231070();
    for (int i = 0; i < count; ++i) {
        Entry_29cb70* e = &entries[i];
        if (e->lifetime != 0) {
            if (e->lifetime > since) {
                sub.FUN_00231590(e->payload, 0, e);
            } else {
                finished[finishedCount] = e;
                ++finishedCount;
                entries[i].lifetime = 0;
            }
        }
    }
}


// 0x0029cc40 FUN_0029cc40 (45 B): matches/0x0029cc40.cpp
// sym: ?run@Target_29cc40@fn_f3bb83d9@@QAEPAV12@E@Z
Target_29cc40* Target_29cc40::run(unsigned char flags) {
    mObj->b();
    thunk2_0008d340(mArg);
    if (flags & 1)
        thunk(this);
    return this;
}


// 0x0029cc70 FUN_0029cc70 (56 B): matches/0x0029cc70.cpp
// sym: ?run@Owner_29cc70@fn_f3bb83d9@@QAEPAV12@E@Z
Owner_29cc70* Owner_29cc70::run(unsigned char flags) {
    a[3]->f1();
    a[2]->f1();
    a[1]->f1();
    a[0]->f1();
    if (flags & 1)
        cleanup_0008d330(this);
    return this;
}


// 0x0029ccb0 FUN_0029ccb0 (308 B): equivalent/0x0029ccb0.cpp
// sym: ?FUN_0029ccb0@Shader@fn_f3bb83d9@@QAEXPAUItemList_29ccb0@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 1274 inputs, branch coverage 31/32, incomplete)
// FUN_0029ccb0 @ 0x0029ccb0
void Shader::FUN_0029ccb0(ItemList_29ccb0 *list, float amount)
{
    int sum = 0;
    int n = list->count;
    int i;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (i < list->capacity) {
                Item_29ccb0 *it = list->items[i];
                if (it) {
                    int m = it->packed & 0xff;
                    int g = (it->packed >> 8) & 0xff;
                    int b = (it->packed >> 16) & 0xff;
                    if (!(g < m))
                        m = g;
                    if (!(b < m))
                        m = b;
                    sum += m;
                }
            }
        }
        i = 0;
        do {
            if (i < list->capacity) {
                Item_29ccb0 *it = list->items[i];
                if (it) {
                    unsigned int color;
                    if (sum != 0) {
                        int m = it->packed & 0xff;
                        int g = (it->packed >> 8) & 0xff;
                        int b = (it->packed >> 16) & 0xff;
                        if (!(g < m))
                            m = g;
                        if (!(b < m))
                            m = b;
                        int c = (int)(__int64)((float)m * scale / sum * amount * m);
                        if (c < 0)
                            c = 0;
                        else if (c > 255)
                            c = 255;
                        int inv = 255 - c;
                        color = 0xff000000u | (inv << 16) | (inv << 8) | inv;
                    } else {
                        color = (*(unsigned int*)&DAT_004cf734);
                    }
                    it->FUN_002a07a0(color);
                }
            }
            i++;
        } while (i < list->count);
    }
}


// 0x0029ce40 FUN_0029ce40 (588 B): equivalent/0x0029ce40.cpp
// sym: ?FUN_0029ce40@Lighting@fn_f3bb83d9@@QAEXPAUVec3_29ce40@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 9439 inputs, branch coverage 32/32)
// FUN_0029ce40 @ 0x0029ce40
void Lighting::FUN_0029ce40(Vec3_29ce40* out, Vec3_29ce40* p)
{
    if (!out)
        return;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;

    int i;
    for (i = statics->list->size - 1; i >= 0; i--) {
        if (i >= statics->list->count)
            continue;
        Light* item = statics->list->items[i];
        if (!item)
            continue;
        unsigned int color = item->color;
        double v = item->FUN_002a0d00(p);
        if (v != 0.0) {
            if (statics->descs[i].flags & 2)
                v = v * -1.0f;
            out->x = (float)(((color >> 16) & 0xff) * v + out->x);
            out->y = (float)(((color >> 8) & 0xff) * v + out->y);
            out->z = (float)((color & 0xff) * v + out->z);
        }
    }

    if (frozen)
        return;
    for (i = dynamics->list->size - 1; i >= 0; i--) {
        if (i >= dynamics->list->count)
            continue;
        Light* item = dynamics->list->items[i];
        if (!item)
            continue;
        if (!item->active)
            continue;
        if (item->FUN_002a0d00(p) == 0.0f)
            continue;

        Vec3_29ce40 d;
        float a, b, falloff;
        d.x = p->x - item->pos.x;
        d.y = p->y - item->pos.y;
        d.z = p->z - item->pos.z;
        ((owners::C_2c3d20 *)item)->FUN_002c3d20((hulk_intptr)(&a), (hulk_intptr)(&b), (int *)(&falloff));
        double len = d.FUN_0022d110();
        double lenSq = len * len * falloff;
        double w = item->strength;
        double lit = w * w * falloff * 0.0588235296f;
        if (lit > 1.0f)
            lit = 1.0f;
        if (lenSq > 0.0) {
            double k = lit / lenSq;
            unsigned int color = item->color;
            out->x = (float)(((color >> 16) & 0xff) * k + out->x);
            out->y = (float)(((color >> 8) & 0xff) * k + out->y);
            out->z = (float)((color & 0xff) * k + out->z);
        }
    }
}

} // namespace fn_f3bb83d9

// 0x0029d090 FUN_0029d090 (552 B): equivalent/0x0029d090.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_0029d090@Lights@fn_0029d090@@QAEMPAUV3@2@I@Z
namespace fn_0029d090 {
// STATUS: equivalent (tools/equiv.py level 3: 2668 inputs, branch coverage 35/38, incomplete)
// FUN_0029d090 @ 0x0029d090
struct V3 {
    float x, y, z;
};

struct Light {
    char pad0[0x11];
    unsigned char active;           // 0x11
    char pad12[2];
    unsigned int color;             // 0x14
    V3 pos;                         // 0x18
    char pad24[0x58 - 0x24];
    V3 dir;                         // 0x58
    hulk_freg FUN_002a0d00(V3 *p);
};

struct LightList {
    char pad0[0x10];
    int limit;                      // 0x10
    int count;                      // 0x14
    Light **items;                  // 0x18
};

struct Record {
    float intensity;                // 0x00
    unsigned int color;             // 0x04
    float radius2;                  // 0x08
    V3 dir;                         // 0x0c
    unsigned int flags;             // 0x18
    char pad1c[4];
};

struct Pool {
    LightList *list;                // 0x00
    Record *records;                // 0x04
};

class Lights {
public:
    char pad0[0x18];
    int active;                     // 0x18
    char pad1c[0x30 - 0x1c];
    Pool *pool;                     // 0x30
    float FUN_0029d090(V3 *pos, unsigned int mask);
};

static int clamp255(int v)
{
    if (v >= 0) {
        if (v > 0xff)
            v = 0xff;
    } else {
        v = 0;
    }
    return v;
}

float Lights::FUN_0029d090(V3 *pos, unsigned int mask)
{
    float total = 0.0f;
    int idx = pool->list->count - 1;
    if (idx < 0)
        return total;

    for (; idx >= 0; --idx) {
        LightList *list = pool->list;
        if (idx >= list->limit || list->items[idx] == 0 || !list->items[idx]->active) {
            pool->records[idx].intensity = 0;
            continue;
        }
        Light *l = list->items[idx];
        Record *r = &pool->records[idx];
        if ((r->flags & mask) != mask) {
            pool->records[idx].intensity = 0;
            continue;
        }

        double dx = (double)pos->x - l->pos.x;
        double dy = (double)pos->y - l->pos.y;
        double dz = (double)pos->z - l->pos.z;
        double dist2 = dz * dz + dy * dy + dx * dx;
        if (dist2 >= r->radius2) {
            r->intensity = 0;
            continue;
        }

        float f = l->FUN_002a0d00(pos);
        unsigned int c = l->color;
        int cr = c & 0xff;
        int cg = (c >> 8) & 0xff;
        int cb = (c >> 16) & 0xff;
        int m = cg;
        if (cg < cr)
            m = cr;
        if (cb >= m)
            m = cb;
        double val = (double)m * f;
        int ir = (int)((double)cr * f);
        int ig = (int)((double)cg * f);
        int ib = (int)((double)cb * f);
        ir = clamp255(ir);
        ig = clamp255(ig);
        ib = clamp255(ib);
        unsigned int out = (((((unsigned int)ib | 0xffffff00u) << 8) | ig) << 8) | ir;
        pool->records[idx].color = out;
        pool->records[idx].intensity = (float)val;
        Record *r2 = &pool->records[idx];
        r2->dir = l->dir;
        if (val >= 0.0)
            ++active;
        total = (float)(val + total);
    }
    return total;
}
} // namespace fn_0029d090

namespace fn_f3bb83d9 {

// 0x0029d2c0 FUN_0029d2c0 (769 B): equivalent/0x0029d2c0.cpp
// sym: ?FUN_0029d2c0@Emitter_29d2c0@fn_f3bb83d9@@QAEMPBUVec3_29d2c0@2@I@Z
// STATUS: equivalent (tools/equiv.py level 3: 2728 inputs, branch coverage 29/30, incomplete)
// FUN_0029d2c0 @ 0x0029d2c0
float Emitter_29d2c0::FUN_0029d2c0(const Vec3_29d2c0 *pos, unsigned int mask)
{
    float total = 0.0f;
    // Stack slots the original shares: the clamp arguments sit between v2 and d, and the callee's
    // extent over the value slots reaches the neighbouring word.
    struct Locals {
        int hi2;
        float o2, o3;
        int lo1;
        int i;
        float o1;
        int hi1;
        int v2, lo2, v1, hi3, lo3, v0;
        Vec3_29d2c0 d;
    } fr;

    for (fr.i = pool->list->count - 1; fr.i >= 0; fr.i--) {
        int i = fr.i;
        Pool_29d2c0 *p = pool;
        SourceList *l = p->list;
        if (i >= l->size) {
            p->particles[i].life = 0.0f;
            continue;
        }
        Source_29d2c0 *src = l->items[i];
        if (src == 0 || src->active == 0) {
            p->particles[i].life = 0.0f;
            continue;
        }
        if ((p->particles[i].mask & mask) != mask) {
            p->particles[i].life = 0.0f;
            continue;
        }
        Vec3_29d2c0 &d = fr.d;
        d.x = pos->x - src->pos.x;
        d.y = pos->y - src->pos.y;
        d.z = pos->z - src->pos.z;
        Particle_29d2c0 *e = &p->particles[i];
        float dist2 = d.z * d.z + d.y * d.y + d.x * d.x;
        if (dist2 >= e->radius2) {      // NaN falls through, as in the original (test ah,1 / je)
            e->life = 0.0f;
            continue;
        }
        if (dist2 < 1e-8f) {
            e->life = 0.0f;
            continue;
        }
        float w = src->FUN_002a0d00(pos);
        if (w == 0.0f) {
            pool->particles[i].life = 0.0f;
            continue;
        }
        src->FUN_002c3f20(&fr.o1, &fr.o2, &fr.o3);
        float o1 = fr.o1, o2 = fr.o2, o3 = fr.o3;
        float len = d.FUN_0022d110();
        double s;
        if (o2 > 0.0f)
            s = len * o2;
        else if (o3 > 0.0f)
            s = len * len * o3;
        else
            s = o1;

        unsigned int color = (*(unsigned int*)&DAT_004cf730);
        float life = 0.0f;
        if (s > 0.0) {
            unsigned int col = src->color;
            double ratio = w / s;
            int c0 = col & 0xff;
            int c1 = (col >> 8) & 0xff;
            int c2 = (col >> 16) & 0xff;
            int m = c1 >= c0 ? c1 : c0;
            if (!(c2 < m))
                m = c2;
            life = (float)(m * ratio);
            fr.v0 = (int)(c0 * ratio);
            fr.v1 = (int)(c1 * ratio);
            fr.v2 = (int)(c2 * ratio);
            fr.lo1 = 0;
            fr.hi1 = 255;
            fr.hi2 = 255;
            fr.lo2 = 0;
            fr.hi3 = 255;
            fr.lo3 = 0;
            unsigned int r1 = FUN_0009fa70(&fr.v2, &fr.lo1, &fr.hi1);
            color = (r1 | 0xffffff00) << 8;
            color |= FUN_0009fa70(&fr.v1, &fr.lo2, &fr.hi2);
            color <<= 8;
            color |= FUN_0009fa70(&fr.v0, &fr.lo3, &fr.hi3);
        }
        pool->particles[i].color = color;
        pool->particles[i].life = life;
        Particle_29d2c0 *e2 = &pool->particles[i];
        e2->dir.x = d.x;
        e2->dir.y = d.y;
        e2->dir.z = d.z;
        if (life > 0.0f)
            active++;
        total = life + total;
    }
    return total;
}

} // namespace fn_f3bb83d9

// 0x0029d5d0 FUN_0029d5d0 (688 B): equivalent/0x0029d5d0.cpp [wrapped: conflict: SourceList]
// sym: ?FUN_0029d5d0@Mixer@fn_0029d5d0@@QAEMPBUV3@2@I@Z
namespace fn_0029d5d0 {
// STATUS: equivalent (tools/equiv.py level 3: 10453 inputs, branch coverage 34/42, incomplete)
// FUN_0029d5d0 @ 0x0029d5d0

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Source {
    char pad0[0x11];
    unsigned char active;
    char pad12[2];
    unsigned int color;
    V3 pos;
    char pad24[0x3c];
    float scale;
    float falloff;
};

struct SourceList {
    char pad0[0x10];
    int count;
    int total;
    Source **items;
};

struct Slot {
    float value;
    unsigned int color;
    float radiusSq;
    V3 dir;
    unsigned int flags;
    char pad1c[4];
};

struct SlotSet {
    SourceList *list;
    Slot *slots;
};

class Mixer {
public:
    char pad0[0x18];
    int hits;
    char pad1c[0x20];
    SlotSet *set;
    float FUN_0029d5d0(const V3 *pos, unsigned int mask);
};

float Mixer::FUN_0029d5d0(const V3 *pos, unsigned int mask)
{
    float sum = 0;
    for (int i = set->list->total - 1; i >= 0; i--) {
        SlotSet *s = set;
        SourceList *list = s->list;
        int off = i * 32;
        Source *src;
        if (i < list->count && (src = list->items[i]) != 0 && src->active != 0
            && (s->slots[i].flags & mask) == mask) {
            V3 d;
            d.x = pos->x - src->pos.x;
            d.y = pos->y - src->pos.y;
            d.z = pos->z - src->pos.z;
            Slot *slot = &s->slots[i];
            if (!(d.z * d.z + d.y * d.y + d.x * d.x >= slot->radiusSq)) {
                float unusedA, unusedB, factor;
                ((owners::C_2c3d20 *)src)->FUN_002c3d20((hulk_intptr)(&unusedA), (hulk_intptr)(&unusedB), (int *)(&factor));
                float len = d.FUN_0022d110();
                unsigned int color = (*(unsigned int*)&DAT_004cf730);
                volatile float t = len * len * factor;
                volatile float z = src->falloff * src->falloff * factor * (*(float*)&DAT_0042d618);
                if (z > 1.0f)
                    z = 1.0f;
                double v = (*(float*)&DAT_003f32e0);
                if (t > (*(float*)&DAT_003f32e0)) {
                    unsigned int c = src->color;
                    int b0 = c & 0xff;
                    int b1 = (c >> 8) & 0xff;
                    int b2 = (c >> 16) & 0xff;
                    volatile float scale = z / t;
                    int mx = b1 >= b0 ? b1 : b0;
                    if (!(b2 < mx))
                        mx = b2;
                    v = (double)mx * scale;
                    int r = (int)(b0 * scale);
                    int g = (int)(b1 * scale);
                    int b = (int)(b2 * scale);
                    if (r < 0) r = 0; else if (r > 255) r = 255;
                    if (g < 0) g = 0; else if (g > 255) g = 255;
                    if (b < 0) b = 0; else if (b > 255) b = 255;
                    color = 0xff000000u | ((unsigned int)b << 16) | ((unsigned int)g << 8) | (unsigned int)r;
                }
                set->slots[i].color = color;
                set->slots[i].value = (float)v;
                set->slots[i].dir = d;
                if (v > (*(float*)&DAT_003f32e0))
                    hits++;
                sum += v;
            } else {
                slot->value = 0;
            }
        } else {
            set->slots[i].value = 0;
        }
    }
    return sum;
}
} // namespace fn_0029d5d0


// 0x0029d880 FUN_0029d880 (1084 B): equivalent/0x0029d880.cpp [wrapped: conflict: DAT_004cf730; Light]
// sym: ?FUN_0029d880@LightMgr@fn_0029d880@@QAEMPAUV3@2@I@Z
namespace fn_0029d880 {
// STATUS: equivalent (tools/equiv.py level 3: 17928 inputs, branch coverage 51/54, incomplete)
// FUN_0029d880 @ 0x0029d880
// checked with equiv.py --time-budget 1500 at 20000 inputs (the default budget stops early)

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl cos(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl pow(double, double);
#endif


struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Rec {
    float f0;                        // 0x00  light intensity
    unsigned int color;              // 0x04
    float f8;                        // 0x08  reach squared
    V3 dir;                          // 0x0c
    unsigned int mask;               // 0x18
    char pad1c[4];
};

class Light {
public:
    char pad00[0x11];
    char enabled;                    // 0x11
    char pad12[2];
    unsigned int color;              // 0x14
    V3 pos;                          // 0x18
    char pad24[0x58 - 0x24];
    V3 dir;                          // 0x58
    float FUN_002a0d00(V3 *where);
    void FUN_002c41c0(float *a, float *b, float *c);
    void FUN_002c4200(float *a, float *b, float *c);
};

struct LightList {
    char pad00[0x10];
    int limit;                       // 0x10
    int count;                       // 0x14
    Light **items;                   // 0x18
};

struct LightCtx {
    LightList *list;                 // 0x00
    Rec *recs;                       // 0x04
};

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
char __cdecl FUN_00018960(float a, float b, float eps);

extern unsigned int DAT_004cf730;

// The original keeps these unrounded on the FPU stack, so they are recomputed at each use.
static __forceinline float Reach(float len, float p0, float p1, float p2)
{
    if (p1 > 0.0f)
        return len * p1;
    if (p2 > 0.0f)
        return len * len * p2;
    return p0;
}

static __forceinline float Intensity(bool useColor, int m, float fac)
{
    return useColor ? (float)m * fac : 0.0f;
}

class LightMgr {
public:
    char pad00[0x18];
    int lit;                         // 0x18
    char pad1c[0x38 - 0x1c];
    LightCtx *ctx;                   // 0x38
    float FUN_0029d880(V3 *pos, unsigned int mask);
};

float LightMgr::FUN_0029d880(V3 *pos, unsigned int mask)
{
    struct Frame {
        float fac;                   // 0x00
        float c1;                    // 0x04
        int idx;                     // 0x08
        float acc;                   // 0x0c
        union {
            float len;
            int r8;
        } u10;                       // 0x10
        float q1;                    // 0x14
        float p1;                    // 0x18
        float p2;                    // 0x1c
        union {
            float a;
            int m;
        } u20;                       // 0x20
        float q2;                    // 0x24
        float pw;                    // 0x28
        float p0;                    // 0x2c
        float k30;                   // 0x30
        float k34;                   // 0x34
        float k38;                   // 0x38
        float k3c;                   // 0x3c
        int g8;                      // 0x40
        int b8;                      // 0x44
        V3 d;                        // 0x48
    } f;

    f.idx = ctx->list->count - 1;
    f.acc = 0.0f;
    for (; f.idx >= 0; f.idx--) {
        LightList *list = ctx->list;
        if (f.idx >= list->limit) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        Light *light = list->items[f.idx];
        if (light == 0 || light->enabled == 0) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        if ((ctx->recs[f.idx].mask & mask) != mask) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }

        f.d = *pos;
        f.d.x = f.d.x - light->pos.x;
        f.d.y = f.d.y - light->pos.y;
        f.d.z = f.d.z - light->pos.z;
        if (f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x >= ctx->recs[f.idx].f8) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }

        f.u20.a = light->FUN_002a0d00(pos);
        if (f.u20.a == 0.0f) {
            ctx->recs[f.idx].f0 = 0.0f;
            continue;
        }
        light->FUN_002c41c0(&f.p0, &f.p1, &f.p2);
        f.u10.len = f.d.FUN_0022d110();
        if (!(Reach(f.u10.len, f.p0, f.p1, f.p2) <= 0.0f))
            f.fac = f.u20.a / Reach(f.u10.len, f.p0, f.p1, f.p2);
        else
            f.fac = 0.0f;
        f.u10.len = f.d.z * light->dir.z + f.d.y * light->dir.y + f.d.x * light->dir.x;
        light->FUN_002c4200(&f.c1, &f.q1, &f.q2);
        f.c1 = (float)cos(f.c1 * 0.5f);
        if (f.u10.len < f.c1)
            f.fac = 0.0f;

        unsigned int color;
        bool useColor;
        if (!(f.fac > 0.0f)) {
            color = DAT_004cf730;
            useColor = false;
        } else {
            float r2;
            f.q1 = (float)cos(f.q1 * 0.5f);
            if (f.q1 - f.c1 == 0.0f) {
                r2 = 0.0f;
            } else {
                f.u20.a = (f.u10.len - f.c1) / (f.q1 - f.c1);
                f.k30 = 1.0f;
                f.k34 = 0.0f;
                r2 = FUN_000186b0(&f.u20.a, &f.k34, &f.k30);
            }
            f.fac = r2 * f.fac;
            if (FUN_00018960(f.q2, 0.0f, 1e-5f))
                f.pw = 1.0f;
            else
                f.pw = (float)pow(f.u10.len, f.q2);
            f.k38 = 1.0f;
            f.k3c = 0.0f;
            f.fac = FUN_000186b0(&f.pw, &f.k3c, &f.k38) * f.fac;

            unsigned int cl = light->color;
            f.u10.r8 = cl & 0xff;
            f.g8 = (cl >> 8) & 0xff;
            int mx = f.g8 >= f.u10.r8 ? f.g8 : f.u10.r8;
            f.b8 = (cl >> 16) & 0xff;
            f.u20.m = f.b8 < mx ? mx : f.b8;
            int rr = (int)(f.u10.r8 * f.fac);
            int gg = (int)(f.g8 * f.fac);
            int bb = (int)(f.b8 * f.fac);
            if (rr < 0)
                rr = 0;
            else if (rr > 0xff)
                rr = 0xff;
            if (gg < 0)
                gg = 0;
            else if (gg > 0xff)
                gg = 0xff;
            if (bb < 0)
                bb = 0;
            else if (bb > 0xff)
                bb = 0xff;
            color = (((0xffffff00u | bb) << 8 | gg) << 8) | rr;
            useColor = true;
        }
        ctx->recs[f.idx].color = color;
        ctx->recs[f.idx].f0 = Intensity(useColor, f.u20.m, f.fac);
        ctx->recs[f.idx].dir = f.d;
        if (Intensity(useColor, f.u20.m, f.fac) > 0.0f)
            lit++;
        f.acc = Intensity(useColor, f.u20.m, f.fac) + f.acc;
    }
    return f.acc;
}
} // namespace fn_0029d880

namespace fn_f3bb83d9 {

// 0x0029dcc0 FUN_0029dcc0 (101 B): matches/0x0029dcc0.cpp
// sym: ?F@Obj_29dcc0@fn_f3bb83d9@@QAEMHH@Z
hulk_freg Obj_29dcc0::F(int a, int b) {
    field = 0;
    float r = FnA_0029d090(a, b);
    r = r + FnB_0029d2c0(a, b);
    r = r + FnC_0029d880(a, b);
    if (flag)
        return FnD_0029d5d0(a, b) + r;
    return r;
}


// 0x0029dd30 FUN_0029dd30 (597 B): equivalent/0x0029dd30.cpp
// sym: ?FUN_0029dd30@SortedMerge@fn_f3bb83d9@@QAEMPAUBlock@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 25/26, incomplete)
// FUN_0029dd30 @ 0x0029dd30
hulk_freg SortedMerge::FUN_0029dd30(Block *out)
{
    hulk_freg sum = 0.0f;
    int n = out->hdr->count;
    sorter->head = &sorter->sentinel;
    sorter->capacity = n;

    Block *src[4];
    src[0] = blocks[0];
    src[1] = blocks[1];
    src[2] = blocks[2];
    src[3] = blocks[3];
    int numBlocks = 3 + (extra != 0);

    for (int b = 0; b < numBlocks; b++) {
        Block *blk = src[b];
        for (int j = blk->hdr->count - 1; j >= 0; j--) {
            Sorter *s = sorter;
            Node *cur = blk->elems + j;
            Node *prev = 0;
            Node *node = s->head;
            int i = 0;
            if (s->capacity > 0) {
                do {
                    if (cur->key > node->key) {
                        cur->next = node;
                        if (prev == 0)
                            s->head = cur;
                        else
                            prev->next = cur;
                        break;
                    }
                    i++;
                    prev = node;
                    node = node->next;
                } while (i < s->capacity);
            }
        }
    }

    Node *node = sorter->head;
    for (int k = 0; k < n; k++) {
        out->elems[k].f4 = node->f4;
        out->elems[k].vx = node->vx;
        out->elems[k].vy = node->vy;
        out->elems[k].vz = node->vz;
        out->elems[k].key = node->key;
        sum += node->key;
        node = node->next;
    }
    return sum;
}


// 0x0029df90 FUN_0029df90 (902 B): equivalent/0x0029df90.cpp
// sym: ?FUN_0029df90@Manager@fn_f3bb83d9@@QAEXPAUGroup@2@TArg2@2@TArg3@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 11440 inputs, branch coverage 47/50, incomplete)
// FUN_0029df90 @ 0x0029df90
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void Manager::FUN_0029df90(Group *group, Arg2 a2, Arg3 a3)
{
    int count = group->count;
    table->FUN_0029c660();
    ((owners::A_2a1180 *)(table->slots))->FUN_002a1180(count + 1);
    hulk_freg k = FUN_0029dcc0(a3.mode, 0x10);
    float *rgb = a2.rgb;
    hulk_freg a = rgb[0] < 0.0f ? rgb[0] : 0.0f;
    hulk_freg b = rgb[1] < 0.0f ? rgb[1] : 0.0f;
    hulk_freg c = rgb[2] < 0.0f ? rgb[2] : 0.0f;
    hulk_freg m = (c + b + a) * 0.333f;
    a2.scale = 1.0f;
    a3.flag = 0;
    if (k > 0.0f && m < -0.0001f) {
        a3.flag = 1;
        double t = (m + k) / k;
        a2.scale = (hulk_freg)t;
        if (t < 0.0)
            a2.scale = 0.0f;
    }
    hulk_freg ret = FUN_0029dd30(table);
    Entry *first = &table->entries[count];
    double total = (k - ret) + first->weight;
    int ival = 0;
    if (first->weight > 0.0f) {
        double prod = total * 0.33f;
        double v = prod;
        if (first->weight > prod)
            v = first->weight;
        ival = (int)(__int64)(v * a2.scale);
        hulk_freg d = (hulk_freg)ival;
        rgb[0] = d + rgb[0];
        rgb[1] = d + rgb[1];
        rgb[2] = d + rgb[2];
    }
    for (int i = 0; i < count; i++) {
        if ((int)(__int64)table->entries[i].weight - ival <= 0) {
            group->FUN_002a0fc0(i, 0);
            continue;
        }
        pure3d::Light_29df90 *item = 0;
        if (i < group->size)
            item = group->items[i];
        pure3d::DirectionalLight_29df90 *light = dynamic_cast<pure3d::DirectionalLight_29df90 *>(item);
        if (light == 0) {
            void *mem = thunk_FUN_0008d690((int)sizeof(pure3d::DirectionalLight_29df90));
            if (mem != 0)
                light = ((pure3d::DirectionalLight_29df90 *)mem)->FUN_002a2e70();
            else
                light = 0;
            group->FUN_002a0fc0(i, light);
        }
        unsigned int raw = table->entries[i].color;
        if (a3.flag) {
            int r = (int)(__int64)((hulk_freg)((raw >> 16) & 0xff) * a2.scale);
            unsigned int col = 0xffffff00 | r;
            col <<= 8;
            int g = (int)(__int64)((hulk_freg)((raw >> 8) & 0xff) * a2.scale);
            col |= g;
            col <<= 8;
            int bl = (int)(__int64)((hulk_freg)(raw & 0xff) * a2.scale);
            col |= bl;
            raw = col;
        }
        int cb = (int)(__int64)(raw & 0xff) - ival;
        int cg = (int)(__int64)((raw >> 8) & 0xff) - ival;
        int cr = (int)(__int64)((raw >> 16) & 0xff) - ival;
        if (cb < 0)
            cb = 0;
        else if (cb > 0xff)
            cb = 0xff;
        if (cg < 0)
            cg = 0;
        else if (cg > 0xff)
            cg = 0xff;
        if (cr < 0)
            cr = 0;
        else if (cr > 0xff)
            cr = 0xff;
        unsigned int out = 0xffffff00 | cr;
        out <<= 8;
        out |= cg;
        out <<= 8;
        out |= cb;
        light->FUN_002a07a0(out);
        V3 dir = table->entries[i].dir;
        light->FUN_002a2fc0(&dir);
        light->flag13 = (table->entries[i].flags & 8) == 8;
    }
}


// 0x0029e320 FUN_0029e320 (664 B): equivalent/0x0029e320.cpp
// sym: ?FUN_0029e320@Effect_29e320@fn_f3bb83d9@@QAEXPAUContainer_29e320@2@PAUV3_29e320@2@TArg3_29e320@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 40/42, incomplete)
// FUN_0029e320 @ 0x0029e320
  // 0.0
  // -0.0001
  // 0.333
void Effect_29e320::FUN_0029e320(Container_29e320 *c, V3_29e320 *p, Arg3_29e320 a3)
{
    int n = c->size;
    if (n == 0)
        return;

    f40->FUN_0029c660();
    ((owners::A_2a1180 *)(f40->list))->FUN_002a1180(n + 1);
    float scale = FUN_0029dcc0(a3.value, 4);

    float x = p->x < (*(float*)&DAT_003f32e0) ? p->x : (*(float*)&DAT_003f32e0);
    float y = p->y < (*(float*)&DAT_003f32e0) ? p->y : (*(float*)&DAT_003f32e0);
    float z = p->z < (*(float*)&DAT_003f32e0) ? p->z : (*(float*)&DAT_003f32e0);
    float blend = 1.0f;
    a3.flag = 0;
    float avg = (z + y + x) * (*(float*)&DAT_0042d620);
    if (scale > (*(float*)&DAT_003f32e0) && avg < (*(float*)&DAT_0042d61c)) {
        a3.flag = 1;
        blend = (avg + scale) / scale;
        if (blend < (*(float*)&DAT_003f32e0))
            blend = 0.0f;
    }

    FUN_0029dd30(f40);
    int top = ColorMax(f40->recs[n].color);
    for (int i = 0; i < n; i++) {
        int m = ColorMax(f40->recs[i].color) - top;
        int v;
        if (m < 0)
            v = 0;
        else if (m > 0xff)
            v = 0xff;
        else
            v = m;
        if (a3.flag)
            v = (int)(v * blend);
        if (v <= 0) {
            c->FUN_002a0fc0(i, 0);
        } else {
            Node *node = i < c->count ? c->items[i] : 0;
            Node *obj = (Node *)FUN_00344e74(node, 0, DAT_004c534c, DAT_004cf658, 0);
            if (!obj) {
                void *mem = FUN_00263ea0(0x68);
                if (mem)
                    obj = ((Node *)mem)->FUN_002a2e70();
                else
                    obj = 0;
                c->FUN_002a0fc0(i, obj);
            }
            obj->FUN_002a07a0((((v | 0xffffff00u) << 8 | v) << 8) | v);
            V3_29e320 pos = f40->recs[i].pos;
            obj->FUN_002a2fc0(&pos);
        }
    }
}


// 0x0029e5c0 FUN_0029e5c0 (120 B): equivalent/0x0029e5c0.cpp
// sym: ?FUN_0029e5c0@Tracker_29e5c0@fn_f3bb83d9@@QAE_NPAUTarget_29e5c0@2@PAUCounter_29e5c0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0029e5c0 @ 0x0029e5c0
bool Tracker_29e5c0::FUN_0029e5c0(Target_29e5c0* t, Counter_29e5c0* c) {
    int left = c->count - 1;
    c->count = left;
    if (left > 0)
        return true;
    c->count = c->reload + left;
    if (t->FUN_0022d2b0(c->buf, c->f20) && id == c->f1c) {
        if (c->flag) {
            if (!(FUN_0029dcc0(t, 8) <= 0.0f))
                return false;
        }
        return true;
    }
    return false;
}


// 0x0029e640 FUN_0029e640 (63 B): matches/0x0029e640.cpp
// sym: ?FUN_0029e640@fn_f3bb83d9@@YGXPAUItemList@1@@Z
void __stdcall FUN_0029e640(ItemList* list) {
    if (!list)
        return;
    int n = 0;
    int i = 0;
    while (i < list->count) {
        if (i >= list->capacity || !list->items[i])
            break;
        ++n;
        ++i;
    }
    ((owners::A_2a1180 *)(((Grow_29e640*)list)))->FUN_002a1180(n);
}


// 0x0029e680 FUN_0029e680 (54 B): matches/0x0029e680.cpp
// sym: ?FUN_0029e680@fn_f3bb83d9@@YGXPAUObj_29e680@1@@Z
void __stdcall FUN_0029e680(Obj_29e680* p) {
    if (p) {
        int i = 0;
        if (p->count > 0)
            do {
                if (i < p->limit) {
                    Item_29e680* it = p->items[i];
                    if (it)
                        it->Func_002a0820(1);
                }
                ++i;
            } while (i < p->count);
    }
}


// 0x0029e6c0 FUN_0029e6c0 (227 B): equivalent/0x0029e6c0.cpp
// sym: ??0LightsChooserCache@pure3d@fn_f3bb83d9@@QAE@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 18165 inputs, branch coverage 8/8)
// FUN_0029e6c0 @ 0x0029e6c0
namespace pure3d {
LightsChooserCache::LightsChooserCache(hulk_intptr n) {
 count=n; f14=0; f18=0; f1c=-1; f20=0.001f;
 entries=0; f28=0; f2c=0; f30=0;
 f3c=1; f40=1; color=(*(unsigned int*)&DAT_004cf730); flag=0;
 int size=count>0?count:0;
 count=size;
 Entry_29e6c0* p=(Entry_29e6c0*)FUN_0008d6d0((unsigned int)size*64);
 if(p) {
 for(int t=0;t<size;++t) {
 p[t].active=0; p[t].a=0; p[t].index=-1; p[t].c=0;p[t].d=0;p[t].e=0;p[t].f=0;p[t].g=0;
 p[t].x=1.0f;p[t].y=1.0f;p[t].h=0;p[t].i=0;p[t].j=0;p[t].k=0;p[t].l=0;p[t].limit=10000000.0f;
 }
 }
 entries=p;
}
}

} // namespace fn_f3bb83d9
