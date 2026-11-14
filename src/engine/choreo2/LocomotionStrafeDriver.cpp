// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00225ef0..0x00228590 (kind game, layer engine, confidence high), dominant class choreo2::LocomotionStrafeDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "decls/data/game/global.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9d100c9 {
#define TREE_TU_END }
namespace fn_f9d100c9 {} using namespace fn_f9d100c9;
#include "engine/choreo2.h"
// (ren2) floor's own name (CRT, C linkage)
#if !defined(HULK_COMPAT_CRT)
extern "C" double __cdecl floor(double);
#endif

// ---- declarations shared by the functions below
namespace fn_f9d100c9 {
class Item_225ef0 {
  public:
    virtual void a();
    virtual void release();
};
extern "C" void __fastcall FUN_0022a9c0(void* self);
class LocomotionStrafeDriver {
  public:
    virtual void Fnv_00038290();
    char pad[0x2c];
    unsigned count;
    struct Entry {
        Item_225ef0* item;
        char rest[0x204];
    } entries[1];
    ~LocomotionStrafeDriver();
};
struct Ref_225f30 { virtual void FUN_ref0(); };
struct Inner_225f30 { char pad[0x10]; unsigned count; };
struct Pair_225f30 { unsigned a, b; };
struct Entry_225f30 {
    Ref_225f30 *obj;
    Pair_225f30 pairs[64];
    unsigned tail;
};
struct Vec3_225f30 { unsigned x, y, z; };
struct Obj_225f30 {
    char pad0[0x10];
    Inner_225f30 *inner;
    char pad1[0x28 - 0x14];
    unsigned w, h, n;
    Entry_225f30 entries[9];
    Pair_225f30 grid[1];
    char pad3[0x12dc - 0x127c - 8];
    unsigned char b0, b1;
    char pad4[2];
    unsigned f12e0, f12e4, f12e8, f12ec;
    Vec3_225f30 v0, v1, v2, v3;
    unsigned f1320, f1324, f1328;
    Obj_225f30 *FUN_00225f30(Obj_225f30 *src);
};
extern "C" float __cdecl FUN_0022aaa0(float, float);
struct V3_226150 {
    int a, b, c;
};
struct Obj_226150 {
    char pad[0x12e0];
    int value;
    V3_226150 Get();
};
void Transform_00224d70(int, V3_226150*);
void __cdecl FUN_00224d70(void*,Vec3*);
struct Object { char pad[0x12e4]; void* field; void FUN_002261e0(Vec3* output); };
struct V3_226250 {
    float x, y, z;
};
void __cdecl FUN_00224d70(void *transform, V3_226250 *vec);
class Emitter_226250 {
public:
    void FUN_00226250(V3_226250 *out);

    char pad0[0x12e4];
    void *transform;    // +0x12e4
    float speed;        // +0x12e8
};
struct Entry_2262d0 {
    unsigned int id;
    float w;
    float v;
};
class Obj_2262d0 {
  public:
    char pad[0x30];
    unsigned int limit;
    char pad34[0x12ec - 0x34];
    unsigned int count;
    Entry_2262d0 e[1];
    void Add(unsigned int, float, float);
};
struct HeapEntry_226430 {
    int id;
    float key;
    int extra;
};
struct Item_2264b0 { unsigned int x, y, z; };
struct Vec3_226610 {
    float x, y, z;
};
class Chan_226610 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a, float t, Vec3_226610 *out);
};
class Child_226610 {
public:
    Chan_226610 *FUN_00288960(unsigned __int64 key);
};
class IdObj_226610 {
public:
    virtual void addRef();
    char pad04[0x10 - 4];
    float f10;
    float f14;
    char pad18[0x20 - 0x18];
    int f20;
    Child_226610 *FUN_00288ad0(unsigned __int64 key);
};
struct Slot_226610 {
    Chan_226610 *tran;
    Chan_226610 *rot;
};
struct Record_226610 {
    IdObj_226610 *id;
    Slot_226610 slots[64];
    int tail;
};
struct Entry_226610 {
    int slot;
    float weight;
};
struct Keys_226610 {
    char pad[0x10];
    unsigned count;
    char pad2[0x24 - 0x14];
    unsigned __int64 *keys;
};
class LocomotionStrafeDriver_226610 {
public:
    char pad0[0x10];
    Keys_226610 *keysOwner;
    char pad1[0x28 - 0x14];
    unsigned perRow;
    unsigned rows;
    unsigned count;
    Record_226610 records[9];
    Entry_226610 entries[1];

    void FUN_00226610(unsigned row, IdObj_226610 **ids, float *weights);
};
struct Vec3_2268f0 {
    float x, y, z;
};
hulk_freg __cdecl FUN_00224f10(Vec3_2268f0 *v);
class Obj_2268f0 {
public:
    char pad0[0x12e4];
    float f12e4;
    float f12e8;
    void FUN_002268f0(Vec3_2268f0 *src);
};
hulk_freg __cdecl FUN_0004af40(float lo, float hi, float v);
struct Sample_226960 {
    float value;
    float pad;
};
class Table_226960 {
public:
    char pad00[0x28];
    unsigned int count;
    char pad2c[0x1280 - 0x2c];
    Sample_226960 samples[1];
    hulk_freg FUN_00226960(unsigned int row, float v);
};
struct Curve_226a70 {
 char pad[0x2c];
 unsigned int count;
 hulk_freg FUN_00226960(unsigned int index, float angle);
 hulk_freg FUN_00226a70(float position, float angle);
};
struct Point_227300 { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
struct V {
    float a, b, c;
};
extern void Sort_00226430(V*, int, int, V);
struct Vec_2274a0 {
    int x, y, z;
};
extern void FUN_002273d0(Vec_2274a0*, int, hulk_intptr, Vec_2274a0);
extern "C" char DAT_004273c4[];
typedef unsigned int u32_227650;
void* __cdecl alloc_obj_00263ea0(unsigned int);
class Helper_227650 {
  public:
    void Fna_0022aa50(choreo2::LocomotionStrafeDriver*);
    void Fnb_00225f30(choreo2::LocomotionStrafeDriver*);
};
struct Elem12_227750 { char data[12]; };
extern "C" void __cdecl FUN_00227300(void *, void *, void *);
struct E_2277f0 {
    int x, y, z;
};
extern void __cdecl FUN_002273d0(E_2277f0* first, hulk_intptr hole, hulk_intptr len, E_2277f0 v);
extern "C" double __cdecl FUN_00224fc0(float, float);
struct Thing {
 char pad0[0x2c];
 volatile int count;
 char pad1[0x12e0-0x30];
 float valueA;
 float valueB;
 hulk_freg FUN_00226960(int, float);
 hulk_freg FUN_002278d0(float scale);
};
class Obj_227970 {
  public:
    char p[0x2c];
    int count;
    char q[0x12e0 - 0x30];
    float a, b, result;
    float Scale_00226960(int, float);
    void Target(float);
};
extern float __cdecl Calc_00224fc0(float, float);
extern "C" float __cdecl calc_00224fc0(float, float);
class Obj {
  public:
    char pad[0x12e0];
    float a, b, c;
    float apply_00226a70(float, float);
    void run(float);
};
struct Elem_227a10 {
    float a;
    float key;
    float c;
};
struct Range_227a10 {
    Elem_227a10 *first;
    Elem_227a10 *second;
    Range_227a10(Elem_227a10 *f, Elem_227a10 *s) : first(f), second(s) {}
};
extern "C" void __cdecl FUN_00227750(void *, void *, void *);
static inline bool Before(const Elem_227a10 &x, const Elem_227a10 &y)
{
    return x.key > y.key;
}
static inline void Swap(Elem_227a10 *x, Elem_227a10 *y)
{
    Elem_227a10 t = *x;
    *x = *y;
    *y = t;
}
struct Item_227e20 {
    int pad0;
    float key;
    int pad8;
};
void __cdecl FUN_002264b0(Item_227e20 *dest, Item_227e20 *first, Item_227e20 *last, int a, int b);
struct Elem_227ef0 { int x, y, z; };
void __cdecl FUN_002273d0(Elem_227ef0 *first, int hole, hulk_intptr len, Elem_227ef0 value);
struct Item_227f90 { char data[12]; };
struct Partition { Item_227f90* first; Item_227f90* second; };
extern void __cdecl FUN_00227a10(Partition*, Item_227f90*, Item_227f90*);
extern "C" void __cdecl FUN_00227e20(void *, void *);
extern void __cdecl FUN_002277f0(Item_227f90*, Item_227f90*, int, int);
extern "C" void __cdecl FUN_00227ef0(void *, void *);


// 0x00225ef0 FUN_00225ef0 (54 B): matches/0x00225ef0.cpp
// sym: ??1LocomotionStrafeDriver@fn_f9d100c9@@QAE@XZ
LocomotionStrafeDriver::~LocomotionStrafeDriver() {
    for (unsigned i = 0; i < count; ++i)
        entries[i].item->release();
    FUN_0022a9c0(this);
}


// 0x00225f30 FUN_00225f30 (441 B): equivalent/0x00225f30.cpp
// sym: ?FUN_00225f30@Obj_225f30@fn_f9d100c9@@QAEPAU12@PAU12@@Z @0dd3da5cf620 @w83f41cccbfd6
// STATUS: equivalent (tools/equiv.py level 3: 21 inputs, branch coverage 12/12)
// FUN_00225f30 @ 0x00225f30
Obj_225f30 *Obj_225f30::FUN_00225f30(Obj_225f30 *src)
{
    ((owners::Thing_22a9e0 *)this)->FUN_0022a9e0((owners::Thing_22a9e0 *)(Obj_225f30 *)src);
    w = src->w;
    h = src->h;
    n = src->n;
    unsigned cnt = inner->count;
    Entry_225f30 *d = entries;
    Entry_225f30 *s = src->entries;
    for (unsigned i = 0; i < n; i++) {
        d->obj = s->obj;
        d->obj->FUN_ref0();
        for (unsigned j = 0; j < cnt; j++)
            d->pairs[j] = s->pairs[j];
        d->tail = s->tail;
        d++;
        s++;
    }
    unsigned m = w * h;
    for (unsigned k = 0; k < m; k++)
        (&grid[0])[k] = (&src->grid[0])[k];
    b0 = src->b0;
    b1 = src->b1;
    f12e0 = src->f12e0;
    f12e4 = src->f12e4;
    f12e8 = src->f12e8;
    f12ec = src->f12ec;
    v0 = src->v0;
    v1 = src->v1;
    v2 = src->v2;
    v3 = src->v3;
    f1320 = src->f1320;
    f1324 = src->f1324;
    f1328 = src->f1328;
    return this;
}

} // namespace fn_f9d100c9

// 0x002260f0 choreo2::LocomotionStrafeDriver::vfunc_14 (71 B): matches/0x002260f0.cpp
// sym: ?vfunc_14@LocomotionStrafeDriver@choreo2@@UAEXM@Z
void choreo2::LocomotionStrafeDriver::vfunc_14(float param) {
    unsigned int i = 0;
    if (this->f_30 > 0) {
        char* p = (char*)this + 0x238;
        do {
            *(float*)p = FUN_0022aaa0(param, *(float*)(p - 0x204));
            ++i;
            p += 0x208;
        } while (i < this->f_30);
    }
}


// 0x00226140 choreo2::LocomotionStrafeDriver::vfunc_3 (3 B): matches/0x00226140.cpp
// sym: ?vfunc_3@LocomotionStrafeDriver@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::LocomotionStrafeDriver::vfunc_3() {
    return true;
}

namespace fn_f9d100c9 {

// 0x00226150 FUN_00226150 (78 B): matches/0x00226150.cpp
// sym: ?Get@Obj_226150@fn_f9d100c9@@QAE?AUV3_226150@2@XZ
V3_226150 Obj_226150::Get() {
    V3_226150 t;
    t.a = DAT_004c9e74;
    t.b = DAT_004c9e78;
    t.c = DAT_004c9e7c;
    Transform_00224d70(value, &t);
    return t;
}


// 0x002261e0 FUN_002261e0 (78 B): equivalent/0x002261e0.cpp
// sym: ?FUN_002261e0@Object@fn_f9d100c9@@QAEXPAUVec3@2@@Z @df640d7068fa @w738af95f1d36
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002261e0 @ 0x002261e0
void Object::FUN_002261e0(Vec3* output) { Vec3 value; value.x=(*(float*)&DAT_004c9e74); value.y=(*(float*)&DAT_004c9e78); value.z=(*(float*)&DAT_004c9e7c); FUN_00224d70(field,&value); *output=value; }


// 0x00226250 FUN_00226250 (124 B): equivalent/0x00226250.cpp
// sym: ?FUN_00226250@Emitter_226250@fn_f9d100c9@@QAEXPAUV3_226250@2@@Z @f651bc68cb42 @w883b8ef803cc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00226250 @ 0x00226250
// Transforms the default direction by the emitter's transform and scales it by its speed.
void Emitter_226250::FUN_00226250(V3_226250 *out) {
    V3_226250 dir;
    dir.x = (*(float*)&DAT_004c9e74);
    dir.y = (*(float*)&DAT_004c9e78);
    dir.z = (*(float*)&DAT_004c9e7c);
    FUN_00224d70(transform, &dir);
    float s = speed;
    dir.x = dir.x * s;
    out->x = dir.x;
    dir.y = dir.y * s;
    out->y = dir.y;
    dir.z = dir.z * s;
    out->z = dir.z;
}


// 0x002262d0 FUN_002262d0 (197 B): matches/0x002262d0.cpp
// sym: ?Add@Obj_2262d0@fn_f9d100c9@@QAEXIMM@Z
// data: gone = DAT_003f32dc, gzero = DAT_003f32e0
void Obj_2262d0::Add(unsigned int id, float w, float v) {
    if (w <= DAT_003f32e0)
        return;
    if (id >= limit)
        return;
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (e[i].id == id) {
            hulk_freg nw = w + e[i].w;
            e[i].w = nw;
            hulk_freg t = w / nw;
            e[i].v = t * v + (DAT_003f32dc - t) * e[i].v;
            return;
        }
    }
    e[count].id = id;
    e[count].w = w;
    e[count].v = v;
    count++;
}


// 0x00226430 FUN_00226430 (121 B): matches/0x00226430.cpp
// sym: ?FUN_00226430@fn_f9d100c9@@YAXPAUHeapEntry_226430@1@HHU21@@Z
// FUN_00226430 @ 0x00226430
// Sift-up step of a binary min-heap (std::__push_heap): moves the hole from
// `hole` towards `top` while the parent's key is greater than the new key.
void FUN_00226430(HeapEntry_226430* first, int hole, int top, HeapEntry_226430 value) {
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key > value.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}


// 0x002264b0 FUN_002264b0 (269 B): equivalent/0x002264b0.cpp
// sym: ?FUN_002264b0@fn_f9d100c9@@YAXPAUItem_2264b0@1@00@Z @559eaa088b9e @w3836875c6296
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_002264b0 @ 0x002264b0
void __cdecl FUN_002264b0(Item_2264b0* first, Item_2264b0* middle, Item_2264b0* last)
{
    hulk_intptr step = middle - first;
    hulk_intptr count = last - first;
    hulk_intptr a = count, b = step;
    while (b != 0) { hulk_intptr r = a % b; a = b; b = r; }
    if (a >= count || a <= 0) return;
    Item_2264b0* start = first + a;
    for (hulk_intptr cycles = a; cycles != 0; --cycles, --start) {
        Item_2264b0 saved = *start;
        Item_2264b0* destination = start;
        Item_2264b0* source = start + step;
        if (source == last) source = first;
        while (source != start) {
            destination->x = source->x;
            destination->y = source->y;
            destination->z = source->z;
            hulk_intptr remaining = last - source;
            destination = source;
            if (step < remaining) source += step;
            else source = first + (step - remaining);
        }
        destination->x = saved.x;
        destination->y = saved.y;
        destination->z = saved.z;
    }
}

} // namespace fn_f9d100c9

// 0x002265c0 choreo2::LocomotionStrafeDriver::vfunc_2 (30 B): matches/0x002265c0.cpp
// sym: ??_GLocomotionStrafeDriver@choreo2@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
choreo2::LocomotionStrafeDriver::~LocomotionStrafeDriver() {}

namespace fn_f9d100c9 {

// 0x00226610 FUN_00226610 (660 B): equivalent/0x00226610.cpp
// sym: ?FUN_00226610@LocomotionStrafeDriver_226610@fn_f9d100c9@@QAEXIPAPAVIdObj_226610@2@PAM@Z @ad125f275360 @wd11ca6888a2c
// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 40/40)
// FUN_00226610 @ 0x00226610
void LocomotionStrafeDriver_226610::FUN_00226610(unsigned row, IdObj_226610 **ids, float *weights)
{
    if (row >= rows)
        return;
    Entry_226610 *e = entries + perRow * row;
    unsigned m10 = keysOwner->count;
    unsigned k = 0;
    if (perRow == 0)
        return;
    do {
        IdObj_226610 *id = ids[k];
        if (id == 0) {
            e->slot = 9;
            if (weights == 0) {
                e->weight = 0.0f;
            } else if (weights[k] >= 0.0f) {
                e->weight = weights[k];
            } else {
                e->weight = 0.0f;
            }
        } else {
            unsigned idx = count;
            unsigned i;
            for (i = 0; i < count; i++) {
                if (records[i].id == id) {
                    idx = i;
                    break;
                }
            }
            if (idx == count && count < 9) {
                records[count].id = ids[k];
                ids[k]->addRef();
                for (unsigned j = 0; j < m10; j++) {
                    unsigned __int64 key = keysOwner->keys[j];
                    Child_226610 *child = ids[k]->FUN_00288ad0(key);
                    if (child) {
                        records[count].slots[j].rot = child->FUN_00288960(0x00544f5200544f52ui64);
                        records[count].slots[j].tran = child->FUN_00288960(0x544345564e415254ui64);
                    } else {
                        records[count].slots[j].rot = 0;
                        records[count].slots[j].tran = 0;
                    }
                }
                records[count].tail = ids[k]->f20;
                count++;
            }
            e->slot = idx;
            if (row == 0) {
                e->weight = 0.0f;
            } else if (weights != 0 && weights[k] >= 0.0f) {
                e->weight = weights[k];
            } else {
                Chan_226610 *chan = records[idx].slots[0].tran;
                if (chan == 0) {
                    e->weight = 0.0f;
                } else {
                    IdObj_226610 *rid = records[idx].id;
                    Vec3_226610 v;
                    v.x = 0.0f;
                    v.y = 0.0f;
                    v.z = 0.0f;
                    float t = rid->f10 - 1.0f;
                    chan->v5(0, t, &v);
                    float len = (float)sqrt((double)(v.z * v.z + v.x * v.x + v.y * v.y));
                    e->weight = len;
                    if (rid->f14 > 0.0f) {
                        double q = t / rid->f14;
                        if (q > 0.0)
                            e->weight = (float)(len / q);
                    }
                }
            }
        }
        k++;
        e++;
    } while (k < perRow);
}


// 0x002268f0 FUN_002268f0 (100 B): equivalent/0x002268f0.cpp
// sym: ?FUN_002268f0@Obj_2268f0@fn_f9d100c9@@QAEXPAUVec3_2268f0@2@@Z @80cfe3c726e1 @w5184640f4031
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002268f0 @ 0x002268f0
void Obj_2268f0::FUN_002268f0(Vec3_2268f0 *src)
{
    Vec3_2268f0 v;
    v.x = src->x;
    v.y = 0.0f;
    v.z = src->z;
    f12e4 = FUN_00224f10(&v);
    f12e8 = (float)sqrt(v.x * v.x + v.z * v.z + v.y * v.y);
}


// 0x00226960 FUN_00226960 (135 B): matches/0x00226960.cpp
// sym: ?FUN_00226960@Table_226960@fn_f9d100c9@@QAEMIM@Z
// FUN_00226960 @ 0x00226960
// Wraps v into [0, 2*pi), then linearly interpolates between the two neighbouring samples of the row.
hulk_freg Table_226960::FUN_00226960(unsigned int row, float v)
{
    hulk_freg angle = FUN_0004af40(0.0f, 6.2831855f, v);
    hulk_freg step = 6.2831855f / (hulk_freg)count;
    hulk_freg inv = 1.0f / step;
    int j = (unsigned int)(__int64)(int)(__int64)(inv * angle) % count;
    unsigned int base = row * count;
    hulk_freg frac = inv * (angle - (hulk_freg)j * step);
    unsigned int next = (j + 1) % count;
    return (1.0f - frac) * samples[base + j].value + frac * samples[base + next].value;
}


// 0x00226a70 FUN_00226a70 (198 B): equivalent/0x00226a70.cpp
// sym: ?FUN_00226a70@Curve_226a70@fn_f9d100c9@@QAEMMM@Z @31380d6464a9 @wa892f4244319
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 6/8, incomplete)
// FUN_00226a70 @ 0x00226a70
hulk_freg Curve_226a70::FUN_00226a70(float position, float angle) {
 angle = FUN_0004af40(0.0f, 6.283185307179586f, angle);
 double base = floor(position);
 if (base < 0.0f) return 0.0f;
 unsigned int index = (unsigned int)base;
 unsigned int last = count - 1;
 if (index >= last) {
  double value = FUN_00226960(last, angle);
  double lastValue = (double)(int)last;
  if ((int)last < 0) lastValue += 4294967296.0f;
  return (hulk_freg)(value * ((double)position - lastValue));
 }
 float first = FUN_00226960(index, angle);
 double second = FUN_00226960(index + 1, angle);
 double indexValue = (double)(int)index;
 if ((int)index < 0) indexValue += 4294967296.0f;
 return (hulk_freg)((second - first) * ((double)position - indexValue) + first);
}

} // namespace fn_f9d100c9

// 0x00226b40 choreo2::LocomotionStrafeDriver::vfunc_10 (914 B): equivalent/0x00226b40.cpp [wrapped: conflict: choreo2::LocomotionStrafeDriver]
// sym: ?vfunc_10@LocomotionStrafeDriver@choreo2@fn_00226b40@@UAEXTArgBase_226b40@3@TArgPose_226b40@3@PAURig_226b40@3@M@Z @fe77adee07c4 @w290f3a376aa3
namespace fn_00226b40 {
// STATUS: equivalent (tools/equiv.py level 3: 734 inputs, branch coverage 26/26)
// choreo2::LocomotionStrafeDriver::vfunc_10 @ 0x00226b40
struct Quat_226b40 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_226b40 *a, const Quat_226b40 *b, float t);
    void FUN_0022b1c0(float angle);
};

struct Vec3_226b40 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_226b40 *out);
    virtual void vf5(float frame, Quat_226b40 *out);
};

class ChannelSet;

class Pose {
public:
    char pad0[0x30];
    Vec3_226b40 position;
    Quat_226b40 *FUN_00221cd0();
    void FUN_00221cf0(Quat_226b40 *q);
    void FUN_0022be40(Vec3_226b40 *v);
};

struct Base_226b40 {
    char pad0[0x30];
    Vec3_226b40 v;
};

struct Rig_226b40 {
    char pad0[0x10];
    Quat_226b40 *quats;            // 0x10
    char *mats;             // 0x14 stride 0x40, position at +0x30
};

struct Rest_226b40 {
    char pad0[0x14];
    Quat_226b40 *quats;            // 0x14
    char *mats;             // 0x18
};

struct Mask_226b40 {
    unsigned int pad0;
    unsigned int bits[1];
};

struct MaskHolder_226b40 {
    char pad0[0x10];
    Mask_226b40 *mask;
};

struct Source_226b40 {
    char pad0[0x10];
    float length;
};

struct Chans_226b40 {
    Channel *pos;
    Channel *rot;
};

struct Blend_226b40 {
    unsigned int index;
    float weight;
    int pad;
};

hulk_freg __cdecl FUN_0004af40(float lo, float a, float b);

union ArgBase_226b40 {
    Base_226b40 *base;
    float acc;
};

union ArgPose_226b40 {
    Pose *pose;
    float w;
};

namespace choreo2 {
class LocomotionStrafeDriver {
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
    virtual void vfunc_10(ArgBase_226b40 a, ArgPose_226b40 p, Rig_226b40 *rig, float t);
    virtual void vfunc_11();
    char pad04[0xc];
    Rest_226b40 *rest;             // 0x10
    MaskHolder_226b40 *maskHolder; // 0x14
    unsigned int first;     // 0x18
    unsigned int last;      // 0x1c
    char pad20[4];
    float rate;             // 0x24
    char pad28[0x34 - 0x28];
    char slots[0x12dc - 0x34];
    char b12dc;
    char b12dd;
    char pad12de[2];
    float angle;            // 0x12e0
    char pad12e4[8];
    unsigned int blendCount;    // 0x12ec
    Blend_226b40 blends[1];            // 0x12f0
};
}

struct Frame_226b40 {
    choreo2::LocomotionStrafeDriver *self;      // 0x10
    unsigned int first;                         // 0x14
    float frame;                                // 0x18
    Mask_226b40 *mask;                                 // 0x1c
    unsigned int last;                          // 0x20
    unsigned int k;                             // 0x24
    Blend_226b40 *bl;                                  // 0x28
    Vec3_226b40 c;                                     // 0x2c
    Vec3_226b40 v;                                     // 0x38
    Quat_226b40 q2;                                    // 0x44
    Quat_226b40 q;                                     // 0x54
};

void choreo2::LocomotionStrafeDriver::vfunc_10(ArgBase_226b40 a, ArgPose_226b40 p, Rig_226b40 *rig, float t)
{
    Frame_226b40 f;
    f.self = this;
    if (maskHolder != 0)
        f.mask = maskHolder->mask;
    else
        f.mask = 0;
    unsigned int first = this->first;
    unsigned int last = this->last;
    f.first = first;
    f.last = last;
    if (first == 0) {
        Pose *pose = p.pose;
        if (b12dc) {
            Vec3_226b40 *acc = (Vec3_226b40 *)((char *)this + 0x1320);
            f.c = *acc;
            // x87: the sums, s1 * t, f.c.z * t and 1 - t stay in registers (53 bits); only the stores round
            double s0 = (double)f.c.x + a.base->v.x;
            double s1 = (double)f.c.y + a.base->v.y;
            f.c.z = (float)((double)f.c.z + a.base->v.z);
            f.c.x = (float)(s0 * t);
            double s1t = s1 * t;
            // the original reloads the stored (rounded) x and z: the volatile reads keep MSVC from reusing its register copies
            double s2t = (double)*(volatile float *)&f.c.z * t;
            double u = 1.0 - (double)t;
            f.c.x = (float)(u * pose->position.x + *(volatile float *)&f.c.x);
            f.c.y = (float)(u * pose->position.y + s1t);
            f.c.z = (float)(u * pose->position.z + s2t);
            pose->FUN_0022be40(&f.c);
            acc->z = 0;
            acc->y = 0;
            acc->x = 0;
        }
        if (b12dd) {
            f.q.FUN_0022b1c0(angle);
            f.q2 = *pose->FUN_00221cd0();
            f.q2.FUN_0022b750(&f.q2, &f.q, t);
            pose->FUN_00221cf0(&f.q2);
        }
        first = 1;
        f.first = first;
    }
    if (blendCount > 0) {
        f.k = 0;
        f.bl = &blends[0];
        a.acc = 1.0f - t;
        do {
            char *slot = (char *)this + f.bl->index * 0x208;
            a.acc = a.acc + t * f.bl->weight;
            p.w = t * f.bl->weight / a.acc;
            Source_226b40 *src = *(Source_226b40 **)(slot + 0x34);
            if (src != 0) {
                double d = src->length - 1.0f;
                float dd = (float)d;
                f.frame = dd;
                f.frame = FUN_0004af40(0.0f, dd, (float)(d * rate + *(float *)(slot + 0x238)));
                if (first <= last) {
                    Chans_226b40 *ch = (Chans_226b40 *)(slot + 0x38);
                    unsigned int i = first;
                    do {
                        if (f.mask == 0 || (f.mask->bits[i >> 5] & (1u << (i & 0x1f)))) {
                            if (ch[i].rot != 0)
                                ch[i].rot->vf5(f.frame, &f.q);
                            else
                                f.q = rest->quats[i];
                            f.q2 = rig->quats[i];
                            f.q2.FUN_0022b750(&f.q2, &f.q, p.w);
                            rig->quats[i] = f.q2;
                            if (ch[i].pos != 0)
                                ch[i].pos->vf4(f.frame, &f.v);
                            else
                                f.v = *(Vec3_226b40 *)(rest->mats + i * 0x40 + 0x30);
                            Vec3_226b40 *c = (Vec3_226b40 *)(rig->mats + i * 0x40 + 0x30);
                            f.c = *c;
                            c->z = (f.v.z - f.c.z) * p.w + f.c.z;
                            c->x = (f.v.x - f.c.x) * p.w + f.c.x;
                            c->y = (f.v.y - f.c.y) * p.w + f.c.y;
                        }
                        i++;
                    } while (i <= f.last);
                }
            }
            f.k++;
            f.bl++;
        } while (f.k < blendCount);
    }
}
} // namespace fn_00226b40


// 0x00226ee0 choreo2::LocomotionStrafeDriver::vfunc_11 (542 B): equivalent/0x00226ee0.cpp [wrapped: conflict: Channel; Pose; choreo2::LocomotionStrafeDriver]
// sym: ?vfunc_11@LocomotionStrafeDriver@choreo2@fn_00226ee0@@UAEDIIPAVPose@3@M@Z @84f24cbdb484 @w854d305f3fce
namespace fn_00226ee0 {
// STATUS: equivalent (tools/equiv.py level 3: 6674 inputs, branch coverage 17/18, incomplete)
// choreo2::LocomotionStrafeDriver::vfunc_11 @ 0x00226ee0
struct Quat_226ee0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_226ee0 *a, const Quat_226ee0 *b, float t);
};

struct Vec3_226ee0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_226ee0 *out);
    virtual void vf5(float frame, Quat_226ee0 *out);
};

class ChannelSet_226ee0 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3_226ee0 position;
    Quat_226ee0 *FUN_00221cd0();
    void FUN_00221cf0(Quat_226ee0 *q);
    void FUN_0022be40(Vec3_226ee0 *v);
};

class Source_226ee0 {
public:
    char pad0[0x10];
    float length;
    ChannelSet_226ee0 *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Slot_226ee0 {
    char pad0[0x34];
    Source_226ee0 *source;
    char pad38[0x238 - 0x38];
    float bias;
};

struct Blend_226ee0 {
    unsigned int index;
    float weight;
    int pad;
};

hulk_freg __cdecl FUN_0004af40(float lo, float a, float b);

namespace choreo2 {
class LocomotionStrafeDriver {
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
    virtual char vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t);
    char pad04[0x24 - 4];
    float rate;
    char pad28[0x12ec - 0x28];
    unsigned int blendCount;
    Blend_226ee0 blends[1];
};
}

char choreo2::LocomotionStrafeDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    if (blendCount == 0)
        return 0;

    struct Frame {
        Quat_226ee0 rot;
        Vec3_226ee0 target;
        Vec3_226ee0 cur;
        Quat_226ee0 q;
    } fr;
    char result = 0;
    float w = 0.0f;
    volatile float acc = 1.0f - t;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend_226ee0 *bl = &blends[i];
        double tw = t * bl->weight;
        Slot_226ee0 *slot = (Slot_226ee0 *)((char *)this + bl->index * 0x208);
        acc = (float)(acc + tw);
        w = (float)(tw / acc);
        Source_226ee0 *src = slot->source;
        if (src == 0)
            continue;
        ChannelSet_226ee0 *set = src->FUN_00288ad0(a, b);
        if (set == 0)
            continue;
        double d = src->length - 1.0f;
        float dd = (float)d;
        float frame = FUN_0004af40(0.0f, dd, (float)(d * rate + slot->bias));
        Channel *rotCh = set->FUN_00288960(0x544f52, 0x544f52);
        if (rotCh != 0) {
            rotCh->vf5(frame, &fr.rot);
            fr.q = *pose->FUN_00221cd0();
            fr.q.FUN_0022b750(&fr.q, &fr.rot, w);
            pose->FUN_00221cf0(&fr.q);
            if (w > 0.0f)
                result = 1;
        }
        Channel *posCh = set->FUN_00288960(0x4e415254, 0x54434556);
        if (posCh == 0)
            continue;
        posCh->vf4(frame, &fr.target);
        fr.cur = pose->position;
        fr.cur.x = (fr.target.x - fr.cur.x) * w + fr.cur.x;
        fr.cur.y = (fr.target.y - fr.cur.y) * w + fr.cur.y;
        fr.cur.z = (fr.target.z - fr.cur.z) * w + fr.cur.z;
        pose->FUN_0022be40(&fr.cur);
        if (w > 0.0f)
            result = 1;
    }
    return result;
}
} // namespace fn_00226ee0


// 0x00227100 choreo2::LocomotionStrafeDriver::vfunc_12 (438 B): equivalent/0x00227100.cpp [wrapped: conflict: FUN_0004af40; LocomotionStrafeDriver]
// sym: ?vfunc_12@LocomotionStrafeDriver@fn_00227100@@UAE_NPAUSource_227100@2@PAM@Z @d04622291f4c @w20762f9c3eb0
namespace fn_00227100 {
// STATUS: equivalent (tools/equiv.py level 3: 17998 inputs, branch coverage 22/22)
// choreo2::LocomotionStrafeDriver::vfunc_12 @ 0x00227100
struct Source_227100 {
    char pad0[8];
    int a;
    int b;
};

struct Anim_227100 {
    char pad0[0x10];
    float weight;
    char FUN_00288d10(int zero, int a, int b, float *outHi, float *outLo);
    float FUN_00288de0(int which, int zero, int a, int b);
};

struct Entry_227100 {
    Anim_227100 *anim;
    char pad04[0x204 - 4];
    float bias;
};

struct Blend_227100 {
    unsigned int entry;
    float weight;
    float pad;
};

float FUN_0004af40(float lo, float t, float x);

class LocomotionStrafeDriver {
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
    virtual bool vfunc_12(Source_227100 *src, float *out);
    char pad04[0x24 - 4];
    float scale;
    char pad28[0x34 - 0x28];
    Entry_227100 entries[9];
    char padEnd[0x12ec - 0x34 - 9 * 0x208];
    unsigned int blendCount;
    Blend_227100 blends[1];
    char FUN_00222330(Source_227100 *src);
};

bool LocomotionStrafeDriver::vfunc_12(Source_227100 *src, float *out)
{
    if (blendCount == 0)
        return false;
    if (!FUN_00222330(src))
        return false;

    int a = src->a;
    int b = src->b;
    *out = 0.0f;
    bool result = false;
    float sum = 0.0f;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend_227100 *bl = &blends[i];
        sum = sum + bl->weight;
        float ratio = bl->weight / sum;
        Entry_227100 *e = &entries[bl->entry];
        Anim_227100 *anim = e->anim;
        if (anim) {
            float hi;
            float lo;
            if (anim->FUN_00288d10(0, a, b, &hi, &lo)) {
                float lowT = anim->FUN_00288de0(0, 0, a, b);
                float highT = anim->FUN_00288de0(1, 0, a, b);
                hulk_freg tx = anim->weight - 1.0f;
                float t = tx;                // stored (fst), the product reads it unrounded
                hulk_freg c = FUN_0004af40(0.0f, t, tx * scale + e->bias);     // st0, compared unrounded
                float r;
                if (highT >= lowT) {
                    if (!(c >= lowT))
                        r = 1.0f;
                    else if (c < highT)
                        r = 0.0f;
                    else
                        r = 1.0f;
                } else {
                    if (!(c >= highT))
                        r = 0.0f;
                    else if (c < lowT)
                        r = 1.0f;
                    else
                        r = 0.0f;
                }
                result = true;
                *out = (r - *out) * ratio + *out;
            }
        }
    }
    return result;
}
} // namespace fn_00227100

namespace fn_f9d100c9 {

// 0x00227300 FUN_00227300 (196 B): equivalent/0x00227300.cpp
// sym: _FUN_00227300 @ff9bcf2ad356 @w2e731d2c70a9
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00227300 @ 0x00227300
extern "C" void __cdecl FUN_00227300(void * a_, void * b_, void * c)
{
    Point_227300 * a = (Point_227300 *)a_;
    Point_227300 * b = (Point_227300 *)b_;
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
    if (((Point_227300 *)c)->y > b->y) {
        unsigned int x = ((Point_227300 *)c)->x, y = ((Point_227300 *)c)->yBits, z = ((Point_227300 *)c)->z;
        ((Point_227300 *)c)->x = b->x; ((Point_227300 *)c)->yBits = b->yBits; ((Point_227300 *)c)->z = b->z;
        b->x = x; b->yBits = y; b->z = z;
    }
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
}


// 0x002273d0 FUN_002273d0 (166 B): matches/0x002273d0.cpp
// sym: ?FUN_002273d0@fn_f9d100c9@@YAXPAUV@1@HHU21@@Z
void FUN_002273d0(V* arr, int b, int n, V value) {
    int start = b;
    int c = b + b + 2;
    if (c < n) {
        do {
            if (arr[c].b > arr[c - 1].b)
                --c;
            arr[b] = arr[c];
            b = c;
            c = c + c + 2;
        } while (c < n);
    }
    if (c == n) {
        arr[b] = arr[n - 1];
        b = n - 1;
    }
    Sort_00226430(arr, b, start, value);
}


// 0x002274a0 FUN_002274a0 (88 B): matches/0x002274a0.cpp
// sym: ?FUN_002274a0@fn_f9d100c9@@YAXPAUVec_2274a0@1@00U21@@Z
void FUN_002274a0(Vec_2274a0* first, Vec_2274a0* last, Vec_2274a0* out, Vec_2274a0 value) {
    *out = *first;
    FUN_002273d0(first, 0, last - first, value);
}

} // namespace fn_f9d100c9

// 0x00227590 FUN_00227590 (183 B): equivalent/0x00227590.cpp [wrapped: conflict: choreo2::LocomotionStrafeDriver]
// sym: ??0LocomotionStrafeDriver@choreo2@fn_00227590@@QAE@PAXIIPBI1@Z @a3602cd2f2b0 @w51952b492de1
namespace fn_00227590 {
// STATUS: equivalent (tools/equiv.py level 3: 375 inputs, branch coverage 8/8)
// FUN_00227590 @ 0x00227590
struct FUN_0022a980 {
    virtual void slot0();
    FUN_0022a980(void*);
    char padding[0x24];
};
namespace choreo2 {
struct LocomotionStrafeDriver : FUN_0022a980 {
    virtual void slot0();
    unsigned width;
    unsigned count;
    unsigned zero30;
    char pad34[0x12dc-0x34];
    unsigned char flagA,flagB;
    char padDE[2];
    unsigned zeroE0,zeroE4,zeroE8,zeroEC;
    char padF0[0x1320-0x12f0];
    unsigned zero20,zero24,zero28;
    void FUN_00226610(unsigned, const unsigned*, const unsigned*);
    LocomotionStrafeDriver(void*,unsigned,unsigned,const unsigned*,const unsigned*);
};
LocomotionStrafeDriver::LocomotionStrafeDriver(void* context,unsigned w,unsigned n,const unsigned* data,const unsigned* other) : FUN_0022a980(context) {
    flagA=1; flagB=1;
    width=w; count=n; zero30=0;
    zeroE0=0; zeroE4=0; zeroE8=0; zeroEC=0;
    zero20=0; zero24=0; zero28=0;
    if(data) {
        unsigned strideOther=other!=0;
        for(unsigned i=0;i<count;++i) {
            unsigned offset=width*i;
            FUN_00226610(i,data+offset,other+offset*strideOther);
        }
    }
}
}
} // namespace fn_00227590


// 0x00227650 choreo2::LocomotionStrafeDriver::vfunc_5 (55 B): matches/0x00227650.cpp
// sym: ?vfunc_5@LocomotionStrafeDriver@choreo2@@UAEPAXXZ
void* choreo2::LocomotionStrafeDriver::vfunc_5() {
    void* p = alloc_obj_00263ea0(0x1330);
    if (p) {
        ((Helper_227650*)p)->Fna_0022aa50(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004273c4);
        ((Helper_227650*)p)->Fnb_00225f30(this);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f9d100c9 {

// 0x00227750 FUN_00227750 (155 B): matches/0x00227750.cpp
// sym: _FUN_00227750
// FUN_00227750 @ 0x00227750
// FUN_00227750: median-of-nine pivot selection step of a sort over 12-byte elements
extern "C" void __cdecl FUN_00227750(void *first, void *mid, void *last)
{
    int n = (int)(((Elem12_227750 *)last) - ((Elem12_227750 *)first));
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00227300((Elem12_227750 *)((Elem12_227750 *)first), (Elem12_227750 *)(((Elem12_227750 *)first) + step), (Elem12_227750 *)(((Elem12_227750 *)first) + 2 * step));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)mid) - step), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)(((Elem12_227750 *)mid) + step));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)last) - 2 * step), (Elem12_227750 *)(((Elem12_227750 *)last) - step), (Elem12_227750 *)((Elem12_227750 *)last));
        FUN_00227300((Elem12_227750 *)(((Elem12_227750 *)first) + step), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)(((Elem12_227750 *)last) - step));
    } else {
        FUN_00227300((Elem12_227750 *)((Elem12_227750 *)first), (Elem12_227750 *)((Elem12_227750 *)mid), (Elem12_227750 *)((Elem12_227750 *)last));
    }
}


// 0x002277f0 FUN_002277f0 (97 B): matches/0x002277f0.cpp
// sym: ?FUN_002277f0@fn_f9d100c9@@YAXPAUE_2277f0@1@0@Z
void __cdecl FUN_002277f0(E_2277f0* first, E_2277f0* last) {
    hulk_intptr len = last - first;
    hulk_intptr parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_002273d0(first, parent, len, first[parent]);
    }
}


// 0x002278d0 FUN_002278d0 (74 B): equivalent/0x002278d0.cpp
// sym: ?FUN_002278d0@Thing@fn_f9d100c9@@QAEMM@Z @67abcc7c68ef @wd957f6416cad
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_002278d0 @ 0x002278d0
hulk_freg Thing::FUN_002278d0(float scale) {
 int index = count - 1;
 float factor = (float)FUN_00224fc0(valueB, valueA);
 return FUN_00226960(index, factor) * scale;
}

} // namespace fn_f9d100c9

// 0x00227920 FUN_00227920 (68 B): matches/0x00227920.cpp [wrapped: conflict: FUN_00224fc0]
// sym: ?FUN_00227920@Object@fn_00227920@@QAEXH@Z
namespace fn_00227920 {
extern hulk_freg __cdecl FUN_00224fc0(float, float);
struct Object {
    char pad[0x12e0];
    float value0;
    float value1;
    void FUN_00226a70(int, float);
    void FUN_00227920(int);
};
void Object::FUN_00227920(int arg) {
    float a = value0, b = value1;
    float result = FUN_00224fc0(b, a);
    FUN_00226a70(arg, result);
}
} // namespace fn_00227920

namespace fn_f9d100c9 {

// 0x00227970 FUN_00227970 (80 B): matches/0x00227970.cpp
// sym: ?Target@Obj_227970@fn_f9d100c9@@QAEXM@Z
void Obj_227970::Target(float param) {
    float x = a;
    float y = b;
    int n = count - 1;
    float r = Calc_00224fc0(y, x);
    float s = Scale_00226960(n, r);
    result = s * param;
}


// 0x002279c0 FUN_002279c0 (74 B): matches/0x002279c0.cpp
// sym: ?run@Obj@fn_f9d100c9@@QAEXM@Z
void Obj::run(float x) {
    float aa = a;
    float bb = b;
    float y = calc_00224fc0(bb, aa);
    c = apply_00226a70(x, y);
}


// 0x00227a10 FUN_00227a10 (971 B): equivalent/0x00227a10.cpp
// sym: ?FUN_00227a10@fn_f9d100c9@@YA?AURange_227a10@1@PAUElem_227a10@1@0@Z @089991e8ccaa @w10d320cfa72f
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 61/62, incomplete)
// FUN_00227a10 @ 0x00227a10
// std::_Unguarded_partition over 12-byte elements ordered descending by the float at +4
Range_227a10 FUN_00227a10(Elem_227a10 *first, Elem_227a10 *last)
{
    Elem_227a10 *mid = first + (last - first) / 2;
    FUN_00227750((Elem_227a10 *)first, (Elem_227a10 *)mid, (Elem_227a10 *)(last - 1));
    Elem_227a10 *pfirst = mid;
    Elem_227a10 *plast = pfirst + 1;
    while (first < pfirst && !Before(pfirst[-1], *pfirst) && !Before(*pfirst, pfirst[-1])) {
        --pfirst;
    }
    while (plast < last && !Before(*plast, *pfirst) && !Before(*pfirst, *plast)) {
        ++plast;
    }
    Elem_227a10 *gfirst = plast;
    Elem_227a10 *glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Before(*pfirst, *gfirst)) {
            } else if (Before(*gfirst, *pfirst)) {
                break;
            } else {
                Swap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Before(glast[-1], *pfirst)) {
            } else if (Before(*pfirst, glast[-1])) {
                break;
            } else {
                Swap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            return Range_227a10(pfirst, plast);
        }
        if (glast == first) {
            if (plast != gfirst) {
                Swap(pfirst, plast);
            }
            ++plast;
            Swap(pfirst++, gfirst++);
        } else if (gfirst == last) {
            if (--glast != --pfirst) {
                Swap(glast, pfirst);
            }
            Swap(pfirst, --plast);
        } else {
            Swap(gfirst++, --glast);
        }
    }
}


// 0x00227e20 FUN_00227e20 (124 B): equivalent/0x00227e20.cpp
// sym: _FUN_00227e20 @5a3286e1c233 @w4ad1a66c2401
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 15/18, incomplete)
// FUN_00227e20 @ 0x00227e20
// Insertion sort of [first, last) by descending key.
extern "C" void FUN_00227e20(void * first_, void *last) {
    Item_227e20 * first = (Item_227e20 *)first_;
    if (first == ((Item_227e20 *)last)) {
        return;
    }
    for (Item_227e20 *cur = first + 1; cur != ((Item_227e20 *)last); cur++) {
        Item_227e20 *next = cur + 1;
        Item_227e20 *pos;
        if (cur->key > first->key) {
            pos = first;
        } else {
            pos = cur;
            while (cur->key > (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_002264b0(pos, cur, next, 0, 0);
        }
    }
}


// 0x00227ef0 FUN_00227ef0 (154 B): equivalent/0x00227ef0.cpp
// sym: _FUN_00227ef0 @3233611142a0 @w4accedab624c
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00227ef0 @ 0x00227ef0
// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
extern "C" void __cdecl FUN_00227ef0(void *first, void * last_)
{
    Elem_227ef0 * last = (Elem_227ef0 *)last_;
    while (last - ((Elem_227ef0 *)first) > 1) {
        --last;
        Elem_227ef0 value = *last;
        *last = *((Elem_227ef0 *)first);
        FUN_002273d0(((Elem_227ef0 *)first), 0, last - ((Elem_227ef0 *)first), value);
    }
}


// 0x00227f90 FUN_00227f90 (289 B): equivalent/0x00227f90.cpp
// sym: ?FUN_00227f90@fn_f9d100c9@@YAXPAUItem_227f90@1@0H@Z @db3db42142e9 @w5f370168d72f
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00227f90 @ 0x00227f90
void __cdecl FUN_00227f90(Item_227f90* first, Item_227f90* last, hulk_intptr budget) {
 hulk_intptr count = last-first;
 while (count > 32 && budget > 0) {
  Partition p;
  FUN_00227a10(&p, first, last);
  budget = budget/2 + (budget/2)/2;
  hulk_intptr right = last-p.second;
  hulk_intptr left = p.first-first;
  if (left < right) {
   FUN_00227f90(first,p.first,budget);
   first=p.second;
  } else {
   FUN_00227f90(p.second,last,budget);
   last=p.first;
  }
  count=last-first;
 }
 if(count <= 32) {
  if(count > 1) FUN_00227e20((Item_227f90 *)first,(Item_227f90 *)last);
 } else {
  if(last-first > 1) FUN_002277f0(first,last,0,0);
  FUN_00227ef0((Item_227f90 *)first,(Item_227f90 *)last);
 }
}

} // namespace fn_f9d100c9

// 0x00228120 FUN_00228120 (938 B): equivalent/0x00228120.cpp [wrapped: conflict: FUN_0004af40; FUN_00224fc0]
// sym: ?FUN_00228120@Sampler_228120@fn_00228120@@QAEXM@Z @c11de106dc66 @w6d991b36fa4c
namespace fn_00228120 {
// STATUS: equivalent (tools/equiv.py level 3: 385 inputs, branch coverage 30/30)
// FUN_00228120 @ 0x00228120
struct Obj_228120 {
    char pad00[0x10];
    float a10;
    float b14;
};

struct Slot_228120 {
    Obj_228120* obj;
    char pad04[0x204];
};

struct Cell_228120 {
    int id;
    float val;
};

struct Entry_228120 {
    int id;
    float weight;
    float value;
};

float FUN_00224fc0(float a, float b);
float FUN_0004af40(float lo, float hi, float x);
float FUN_0015cf40(float x);
void FUN_00227f90(Entry_228120* first, Entry_228120* last, hulk_intptr count);

class Sampler_228120 {
public:
    char pad00[0x20];
    float f20;
    float f24;
    unsigned int width;
    unsigned int height;
    char pad30[4];
    Slot_228120 slots[9];
    Cell_228120 cells[12];
    char pad_dc[4];
    float f12e0;
    float f12e4;
    float threshold;
    unsigned int count;
    Entry_228120 entries[16];

    void FUN_002262d0(int id, float weight, float value);
    void FUN_00228120(float arg);
};

void Sampler_228120::FUN_00228120(float arg)
{
    unsigned int n = width * height;
    count = 0;
    float a = FUN_00224fc0(f12e4, f12e0);
    hulk_freg ang = FUN_0004af40(0.0f, 6.28318548f, a);     // st0, used unrounded

    double step = 6.28318548f / (double)width;
    double inv = 1.0f / step;
    unsigned int idx = (unsigned int)(__int64)(inv * ang) % width;     // _ftol: the low word of the 64-bit value
    unsigned int next = (idx + 1) % width;
    volatile float tt = FUN_0015cf40((float)((ang - (double)idx * step) * inv));
    volatile float u1 = 1.0f - tt;

    unsigned int row = height - 1;
    unsigned int ca = next + width * row;
    unsigned int cb = idx + width * row;
    volatile float v;
    for (;;) {
        v = tt * cells[ca].val + u1 * cells[cb].val;
        if (threshold >= v)
            break;
        if (row == 0)
            break;
        row--;
        ca -= width;
        cb -= width;
    }

    unsigned int above = cb + width;
    if (above >= n) {
        FUN_002262d0(cells[cb].id, u1, v);
        FUN_002262d0(cells[ca].id, tt, v);
    } else {
        unsigned int aboveNext = ca + width;
        volatile float v2 = u1 * cells[above].val + tt * cells[aboveNext].val;
        volatile float f = (threshold - v) / (v2 - v);
        volatile float g = 1.0f - f;
        FUN_002262d0(cells[cb].id, g * u1, v);
        FUN_002262d0(cells[ca].id, g * tt, v);
        FUN_002262d0(cells[above].id, u1 * f, v2);
        FUN_002262d0(cells[aboveNext].id, f * tt, v2);
    }

    Entry_228120* first = &entries[0];
    Entry_228120* last = &entries[count];
    FUN_00227f90(first, last, last - first);

    double acc = 0;
    for (unsigned int k = 0; k < count; k++) {
        if (entries[k].weight < 0.01f) {
            count = k;
            break;
        }
        acc += entries[k].weight;
    }

    f20 = 0;
    volatile float s2f = 0;
    if (count != 0) {
        double rinv = 1.0f / acc;
        double s2 = s2f;
        for (unsigned int k = 0; k < count; k++) {
            volatile float nw = rinv * entries[k].weight;
            entries[k].weight = nw;
            s2 = s2 + nw * entries[k].value;
            Obj_228120* o = slots[entries[k].id].obj;
            if (o) {
                double num = o->a10 - 1.0f;
                float den = o->b14;
                if (den < 0)
                    den = 1.0f;
                f20 = num / den * nw + f20;
            }
        }
        s2f = (float)s2;
    }

    if (f20 > 0.0f) {
        double val;
        if (s2f > 0.0f && threshold > 0.0f)
            val = threshold / s2f * arg;
        else
            val = arg;
        volatile float r = val / f20 + f24;
        f24 = r;
        f24 = FUN_0015cf40(r);
    }
}
} // namespace fn_00228120


// 0x002284d0 choreo2::LocomotionStrafeDriver::vfunc_9 (122 B): matches/0x002284d0.cpp [wrapped: conflict: LocomotionStrafeDriver]
// sym: ?vfunc_9@LocomotionStrafeDriver@fn_002284d0@@UAEXM@Z
namespace fn_002284d0 {
// choreo2::LocomotionStrafeDriver::vfunc_9 @ 0x002284d0
struct Vec3_2284d0 {
    float x, y, z;
};

class LocomotionStrafeDriver {
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
    virtual void vfunc_9(float dt);
    char pad04[0x14];
    int blocked;
    char pad1c[0x12dc - 0x1c];
    char applyMotion;
    char pad12dd[0x1320 - 0x12dd];
    Vec3_2284d0 offset;
    void FUN_00228120(float dt);
};

struct ThisCall_00226250 {
    void FUN_00226250(Vec3_2284d0* out);
};

void LocomotionStrafeDriver::vfunc_9(float dt) {
    if (applyMotion && blocked == 0) {
        Vec3_2284d0 d;
        ((ThisCall_00226250*)(this))->FUN_00226250(&d);
        volatile float* scaledZ = &d.z;
        hulk_freg x = d.x * dt;
        hulk_freg y = d.y * dt;
        *scaledZ = d.z * dt;
        offset.x = x + offset.x;
        offset.y = y + offset.y;
        offset.z = *scaledZ + offset.z;
    }
    FUN_00228120(dt);
}
} // namespace fn_002284d0

