// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00228590..0x0022a5d0 (kind game, layer engine, confidence high), dominant class choreo2::LocomotionSteerDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb966b0a {
#define TREE_TU_END }
namespace fn_fb966b0a {} using namespace fn_fb966b0a;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_fb966b0a {
class Item_228590 {
  public:
    virtual void a();
    virtual void release();
};
extern "C" void __fastcall FUN_0022a9c0(void* self);
class LocomotionSteerDriver_228590 {
  public:
    virtual void v();
    char pad[0x2c];
    unsigned count;
    struct Entry {
        Item_228590* item;
        char rest[0x204];
    } entries[1];
    ~LocomotionSteerDriver_228590();
};
extern "C" float __cdecl FUN_0022aaa0(float, float);
extern "C" void __cdecl Work_00224d70(int, int*);
struct V {
  public:
    union { int a; float x; };
    union { int b; float y; };
    union { int c; float z; };
};
class Obj_228640 {
  public:
    char pad[0x8a8];
    int value;
    V* Get(V*);
};
struct Vec3_2286b0 {
    unsigned int a, b, c;
};
extern void __cdecl FUN_00224d70(unsigned int, Vec3_2286b0*);
struct Obj_2286b0 {
    char pad[0x8ac];
    unsigned int value;
    Vec3_2286b0 Get();
};
float __cdecl Calc_00224f10(int x);
struct V3_228720 {
    float x, y, z;
};
void __cdecl FUN_00224d70(void *transform, V3_228720 *vec);
class Emitter_228720 {
public:
    void FUN_00228720(V3_228720 *out);

    char pad0[0x8ac];
    void *transform;    // +0x8ac
    float speed;        // +0x8b0
};
struct Entry_2287b0 { unsigned index; float weight; float value; };
struct Object {
 char pad0[0x30]; unsigned limit;
 char pad1[0x8b4-0x34]; unsigned count; Entry_2287b0 entries[1];
 void FUN_002287b0(hulk_uintptr index, float weight, float value);
};
struct HeapEntry_228910 {
    int id;
    float key;
    int extra;
};
struct Item_228990 { unsigned int a, b, c; };
struct Vec3_228ac0 {
    float x, y, z;
};
class Anim_228ac0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(int a, float t, Vec3_228ac0 *out);
};
class Channel {
public:
    Anim_228ac0 *FUN_00288960(int tagA, int tagB);
};
class Obj_228ac0 {
public:
    virtual void vfunc_0();
    char pad04[0xc];
    float radius;
    float scale;
    char pad18[8];
    int f20;
    Channel *FUN_00288ad0(int lo, int hi);
};
struct Key_228ac0 {
    int lo;
    int hi;
};
struct Info_228ac0 {
    char pad0[0x10];
    unsigned int count;
    char pad14[0x24 - 0x14];
    Key_228ac0 *keys;
};
struct Entry_228ac0 {
    Anim_228ac0 *trans;
    Channel *rot;
};
struct Slot_228ac0 {
    Obj_228ac0 *obj;
    Entry_228ac0 entries[0x40];
    int f204;
};
class LocomotionSteerDriver_228ac0 {
public:
    char pad00[0x10];
    Info_228ac0 *info;
    char pad14[0x28 - 0x14];
    unsigned int stride;
    unsigned int maxIndex;
    unsigned int slotCount;
    Slot_228ac0 slots[4];
    float weights[3];
    int rows[1];

    void FUN_00228ac0(unsigned int index, Obj_228ac0 **objs, float weight);
};
float Ang_00224f10(V*);
class C_228d30 {
  public:
    char pad[0x8ac];
    float a;
    float b;
    void F(V* v);
};
struct Source_229360 {
    char pad0[8];
    int a;
    int b;
};
struct Anim_229360 {
    char pad0[0x10];
    float weight;
    char FUN_00288d10(int zero, int a, int b, float *outHi, float *outLo);
    hulk_freg FUN_00288de0(int which, int zero, int a, int b);
};
struct Entry_229360 {
    Anim_229360 *anim;
    char pad04[0x204 - 4];
    float bias;
};
struct Blend_229360 {
    unsigned int entry;
    float weight;
    float pad;
};
hulk_freg FUN_0004af40(float lo, float t, float x);
class LocomotionSteerDriver {
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
    virtual bool vfunc_12(Source_229360 *src, float *out);
    char pad04[0x24 - 4];
    float scale;
    char pad28[0x34 - 0x28];
    Entry_229360 entries[4];
    char padEnd[0x8b4 - 0x34 - 4 * 0x208];
    unsigned int blendCount;
    Blend_229360 blends[1];
    char FUN_00222330(Source_229360 *src);
};
struct Point_229560 { unsigned int x; union { float y; unsigned int yBits; }; unsigned int z; };
struct Item_229630 {
    int a;
    float key;
    int c;
};
void __cdecl FUN_00228910(Item_229630 *first, int hole, int top, Item_229630 value);
extern void fn_00229630(V*, int, hulk_intptr, V);
struct Elem12_229840 { char data[12]; };
extern "C" void __cdecl FUN_00229560(void *, void *, void *);
struct E_2298e0 {
    int x, y, z;
};
extern void __cdecl FUN_00229630(E_2298e0* first, hulk_intptr hole, hulk_intptr len, E_2298e0 v);
struct Elem_2299c0 {
    float a;
    float key;
    float c;
};
struct Range_2299c0 {
    Elem_2299c0 *first;
    Elem_2299c0 *second;
    Range_2299c0(Elem_2299c0 *f, Elem_2299c0 *s) : first(f), second(s) {}
};
extern "C" void __cdecl FUN_00229840(void *, void *, void *);
static inline bool Before(const Elem_2299c0 &x, const Elem_2299c0 &y)
{
    return x.key > y.key;
}
static inline void Swap(Elem_2299c0 *x, Elem_2299c0 *y)
{
    Elem_2299c0 t = *x;
    *x = *y;
    *y = t;
}
struct Item_229dd0 {
    int pad0;
    float key;
    int pad8;
};
void __cdecl FUN_00228990(Item_229dd0 *dest, Item_229dd0 *first, Item_229dd0 *last, int a, int b);
struct Elem_229ea0 { int x, y, z; };
void __cdecl FUN_00229630(Elem_229ea0 *first, int hole, hulk_intptr len, Elem_229ea0 value);
struct Item_229f40 { char data[12]; };
struct Partition { Item_229f40* leftEnd; Item_229f40* rightBegin; };
extern void __cdecl FUN_002299c0(Partition*, Item_229f40*, Item_229f40*);
extern "C" void __cdecl FUN_00229dd0(void *, void *);
extern void __cdecl FUN_002298e0(Item_229f40*, Item_229f40*, int, int);
extern "C" void __cdecl FUN_00229ea0(void *, void *);
struct V3_22a550 {
    float x, y, z;
};
struct ThisCall_00228720 {
    void GetVel_00228720(V3_22a550* out);
};
struct LocomotionSteerDriver_22a550 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Update(float dt);
    char pad[0x89c - 4];
    bool enabled;
    char pad2[0x900 - 0x89d];
    float px, py, pz;
    void Base_0022a0d0(float dt);
};


// 0x00228590 FUN_00228590 (54 B): matches/0x00228590.cpp
// sym: ??1LocomotionSteerDriver_228590@fn_fb966b0a@@QAE@XZ
// Same code shape as 0x00225ef0 (propagated; names are from that function)
LocomotionSteerDriver_228590::~LocomotionSteerDriver_228590() {
    for (unsigned i = 0; i < count; ++i)
        entries[i].item->release();
    FUN_0022a9c0(this);
}

} // namespace fn_fb966b0a

// 0x002285d0 choreo2::LocomotionSteerDriver::vfunc_14 (71 B): matches/0x002285d0.cpp
// sym: ?vfunc_14@LocomotionSteerDriver@choreo2@@UAEXM@Z
// Same code shape as 0x002260f0 (propagated; names are from that function)
void choreo2::LocomotionSteerDriver::vfunc_14(float param) {
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


// 0x00228620 choreo2::LocomotionSteerDriver::vfunc_3 (3 B): matches/0x00228620.cpp
// sym: ?vfunc_3@LocomotionSteerDriver@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::LocomotionSteerDriver::vfunc_3() {
    return true;
}

namespace fn_fb966b0a {

// 0x00228640 FUN_00228640 (78 B): matches/0x00228640.cpp
// sym: ?Get@Obj_228640@fn_fb966b0a@@QAEPAUV@2@PAU32@@Z
// data: gMinusOne = DAT_004c9e98, gZeroA = DAT_004c9e90, gZeroB = DAT_004c9e94
V* Obj_228640::Get(V* out) {
    V local;
    local.a = DAT_004c9e90;
    local.b = DAT_004c9e94;
    local.c = DAT_004c9e98;
    Work_00224d70(value, (int*)&local);
    *out = local;
    return out;
}


// 0x002286b0 FUN_002286b0 (78 B): matches/0x002286b0.cpp
// sym: ?Get@Obj_2286b0@fn_fb966b0a@@QAE?AUVec3_2286b0@2@XZ
Vec3_2286b0 Obj_2286b0::Get() {
    Vec3_2286b0 local;
    local.a = (*(unsigned int*)&DAT_004c9e90);
    local.b = (*(unsigned int*)&DAT_004c9e94);
    local.c = (*(unsigned int*)&DAT_004c9e98);
    FUN_00224d70(value, &local);
    return local;
}

} // namespace fn_fb966b0a

// 0x00228700 FUN_00228700 (26 B): matches/0x00228700.cpp
// sym: ?FUN_00228700@C_228700@owners@@QAEXH@Z
void owners::C_228700::FUN_00228700(hulk_intptr x) {
    value = Calc_00224f10(((int)x));
}

namespace fn_fb966b0a {

// 0x00228720 FUN_00228720 (124 B): equivalent/0x00228720.cpp
// sym: ?FUN_00228720@Emitter_228720@fn_fb966b0a@@QAEXPAUV3_228720@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00228720 @ 0x00228720
// Transforms the default direction by the emitter's transform and scales it by its speed.
void Emitter_228720::FUN_00228720(V3_228720 *out) {
    V3_228720 dir;
    dir.x = (*(float*)&DAT_004c9e90);
    dir.y = (*(float*)&DAT_004c9e94);
    dir.z = (*(float*)&DAT_004c9e98);
    FUN_00224d70(transform, &dir);
    float s = speed;
    dir.x = dir.x * s;
    out->x = dir.x;
    dir.y = dir.y * s;
    out->y = dir.y;
    dir.z = dir.z * s;
    out->z = dir.z;
}

} // namespace fn_fb966b0a

// 0x002287a0 FUN_002287a0 (14 B): matches/0x002287a0.cpp
// sym: ?FUN_002287a0@C_2287a0@owners@@QAEMH@Z
float owners::C_2287a0::FUN_002287a0(int i) {
    return ((float*)(pad + 0x854))[i];
}

namespace fn_fb966b0a {

// 0x002287b0 FUN_002287b0 (197 B): equivalent/0x002287b0.cpp
// sym: ?FUN_002287b0@Object@fn_fb966b0a@@QAEXIMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 440 inputs, branch coverage 10/10)
// FUN_002287b0 @ 0x002287b0
void Object::FUN_002287b0(hulk_uintptr index, float weight, float value) {
 if (weight <= 0.0f) return;
 if (index >= limit) return;
 for (unsigned i=0;i<count;++i) {
  if (entries[i].index == index) {
   double sum = (double)weight + entries[i].weight;
   entries[i].weight = (float)sum;
   double ratio = (double)weight / sum;
   entries[i].value = (float)((1.0f - ratio) * entries[i].value + ratio * value);
   return;
  }
 }
 entries[count].index = index;
 entries[count].weight = weight;
 entries[count].value = value;
 ++count;
}


// 0x00228910 FUN_00228910 (121 B): matches/0x00228910.cpp
// sym: ?FUN_00228910@fn_fb966b0a@@YAXPAUHeapEntry_228910@1@HHU21@@Z
// FUN_00228910 @ 0x00228910
// Sift-up step of a binary min-heap (std::__push_heap): moves the hole from
// `hole` towards `top` while the parent's key is greater than the new key.
void FUN_00228910(HeapEntry_228910* first, int hole, int top, HeapEntry_228910 value) {
    int parent = (hole - 1) / 2;
    while (top < hole && first[parent].key > value.key) {
        first[hole] = first[parent];
        hole = parent;
        parent = (hole - 1) / 2;
    }
    first[hole] = value;
}


// 0x00228990 FUN_00228990 (269 B): equivalent/0x00228990.cpp
// sym: ?FUN_00228990@fn_fb966b0a@@YAXPAUItem_228990@1@00@Z
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 17/18, incomplete)
// FUN_00228990 @ 0x00228990
void __cdecl FUN_00228990(Item_228990* first, Item_228990* middle, Item_228990* last)
{
    hulk_intptr shift = middle - first;
    hulk_intptr count = last - first;
    hulk_intptr a = count;
    hulk_intptr b = shift;
    while (b != 0) {
        hulk_intptr remainder = a % b;
        a = b;
        b = remainder;
    }
    if (a >= count || a <= 0) return;
    Item_228990* start = first + a;
    for (hulk_intptr cycles = a; cycles != 0; --cycles, --start) {
        Item_228990 saved = *start;
        Item_228990* destination = start;
        Item_228990* source = start + shift;
        if (source == last) source = first;
        while (source != start) {
            destination->a = source->a;
            destination->b = source->b;
            destination->c = source->c;
            hulk_intptr remaining = last - source;
            destination = source;
            if (shift < remaining) source += shift;
            else source = first + (shift - remaining);
        }
        destination->a = saved.a;
        destination->b = saved.b;
        destination->c = saved.c;
    }
}

} // namespace fn_fb966b0a

// 0x00228aa0 choreo2::LocomotionSteerDriver::vfunc_2 (30 B): matches/0x00228aa0.cpp
// sym: ??_GLocomotionSteerDriver@choreo2@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
choreo2::LocomotionSteerDriver::~LocomotionSteerDriver() {}

namespace fn_fb966b0a {

// 0x00228ac0 FUN_00228ac0 (596 B): equivalent/0x00228ac0.cpp
// sym: ?FUN_00228ac0@LocomotionSteerDriver_228ac0@fn_fb966b0a@@QAEXIPAPAVObj_228ac0@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 34/34)
// FUN_00228ac0 @ 0x00228ac0
void LocomotionSteerDriver_228ac0::FUN_00228ac0(unsigned int index, Obj_228ac0 **objs, float weight)
{
    if (index >= maxIndex)
        return;
    if (index == 0)
        weights[0] = 0;
    else
        weights[index] = weight;

    unsigned int n = stride + 1;
    int *row = &rows[index * n];
    unsigned int keyCount = info->count;
    if (n == 0)
        return;

    for (unsigned int k = 0; k < n; k++) {
        Obj_228ac0 *obj = objs[k];
        if (obj == 0) {
            row[k] = 4;
            continue;
        }

        unsigned int count = slotCount;
        unsigned int sel = count;
        for (unsigned int i = 0; i < slotCount; i++) {
            if (slots[i].obj == obj) {
                sel = i;
                break;
            }
        }
        if (sel == count && count < 4) {
            slots[count].obj = objs[k];
            objs[k]->vfunc_0();
            for (unsigned int j = 0; j < keyCount; j++) {
                Channel *ch = objs[k]->FUN_00288ad0(info->keys[j].lo, info->keys[j].hi);
                if (ch != 0) {
                    // FourCC tags: "ROT", "TRAN"/"VECT"
                    slots[slotCount].entries[j].rot = (Channel *)ch->FUN_00288960(0x544f52, 0x544f52);
                    slots[slotCount].entries[j].trans = ch->FUN_00288960(0x4e415254, 0x54434556);
                } else {
                    slots[slotCount].entries[j].rot = 0;
                    slots[slotCount].entries[j].trans = 0;
                }
            }
            slots[slotCount].f204 = objs[k]->f20;
            slotCount++;
        }
        row[k] = sel;

        if (weights[index] < 0.0f) {
            Anim_228ac0 *anim = slots[sel].entries[0].trans;
            if (anim != 0) {
                Obj_228ac0 *o = slots[sel].obj;
                Vec3_228ac0 out;
                out.x = 0;
                out.y = 0;
                out.z = 0;
                float t = o->radius - 1.0f;
                anim->vfunc_5(0, t, &out);
                float len = (float)sqrt(out.z * out.z + out.x * out.x + out.y * out.y);
                weights[index] = len;
                if (o->scale > 0.0f) {
                    double q = t / o->scale;
                    if (q > 0.0f)
                        weights[index] = len / q;
                }
            }
        }
    }
}


// 0x00228d20 choreo2::LocomotionSteerDriver::vfunc_5 (3 B): matches/0x00228d20.cpp
// sym: ?GetZero@fn_fb966b0a@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x00228d30 FUN_00228d30 (100 B): matches/0x00228d30.cpp
// sym: ?F@C_228d30@fn_fb966b0a@@QAEXPAUV@2@@Z
void C_228d30::F(V* v) {
    V t = *v;
    t.y = 0.0f;
    a = Ang_00224f10(&t);
    b = sqrt(t.z * t.z + t.x * t.x + t.y * t.y);
}

} // namespace fn_fb966b0a

// 0x00228da0 choreo2::LocomotionSteerDriver::vfunc_10 (914 B): equivalent/0x00228da0.cpp [wrapped: conflict: choreo2::LocomotionSteerDriver]
// sym: ?vfunc_10@LocomotionSteerDriver@choreo2@fn_00228da0@@UAEXTArgBase_228da0@3@TArgPose_228da0@3@PAURig_228da0@3@M@Z
namespace fn_00228da0 {
// STATUS: equivalent (tools/equiv.py level 3: 493 inputs, branch coverage 26/26)
// choreo2::LocomotionSteerDriver::vfunc_10 @ 0x00228da0
struct Quat_228da0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_228da0 *a, const Quat_228da0 *b, float t);
    void FUN_0022b1c0(float angle);
};

struct Vec3_228da0 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_228da0 *out);
    virtual void vf5(float frame, Quat_228da0 *out);
};

class ChannelSet;

class Pose {
public:
    char pad0[0x30];
    Vec3_228da0 position;
    Quat_228da0 *FUN_00221cd0();
    void FUN_00221cf0(Quat_228da0 *q);
    void FUN_0022be40(Vec3_228da0 *v);
};

struct Base_228da0 {
    char pad0[0x30];
    Vec3_228da0 v;
};

struct Rig_228da0 {
    char pad0[0x10];
    Quat_228da0 *quats;            // 0x10
    char *mats;             // 0x14 stride 0x40, position at +0x30
};

struct Rest_228da0 {
    char pad0[0x14];
    Quat_228da0 *quats;            // 0x14
    char *mats;             // 0x18
};

struct Mask_228da0 {
    unsigned int pad0;
    unsigned int bits[1];
};

struct MaskHolder_228da0 {
    char pad0[0x10];
    Mask_228da0 *mask;
};

struct Source_228da0 {
    char pad0[0x10];
    float length;
};

struct Chans_228da0 {
    Channel *pos;
    Channel *rot;
};

struct Blend_228da0 {
    unsigned int index;
    float weight;
    int pad;
};

hulk_freg __cdecl FUN_0004af40(float lo, float a, float b);

union ArgBase_228da0 {
    Base_228da0 *base;
    float acc;
};

union ArgPose_228da0 {
    Pose *pose;
    float w;
};

namespace choreo2 {
class LocomotionSteerDriver {
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
    virtual void vfunc_10(ArgBase_228da0 a, ArgPose_228da0 p, Rig_228da0 *rig, float t);
    virtual void vfunc_11();
    char pad04[0xc];
    Rest_228da0 *rest;             // 0x10
    MaskHolder_228da0 *maskHolder; // 0x14
    unsigned int first;     // 0x18
    unsigned int last;      // 0x1c
    char pad20[4];
    float rate;             // 0x24
    char pad28[0x34 - 0x28];
    char slots[0x89c - 0x34];
    char b89c;
    char b89d;
    char pad89e[10];
    float angle;            // 0x8a8
    char pad8ac[8];
    unsigned int blendCount;    // 0x8b4
    Blend_228da0 blends[1];            // 0x8b8
    char pad8c4[0x900 - 0x8c4];
    Vec3_228da0 acc;                   // 0x900
};
}

struct Frame_228da0 {
    choreo2::LocomotionSteerDriver *self;      // 0x10
    unsigned int first;                         // 0x14
    float frame;                                // 0x18
    Mask_228da0 *mask;                                 // 0x1c
    unsigned int last;                          // 0x20
    unsigned int k;                             // 0x24
    Blend_228da0 *bl;                                  // 0x28
    Vec3_228da0 c;                                     // 0x2c
    Vec3_228da0 v;                                     // 0x38
    Quat_228da0 q2;                                    // 0x44
    Quat_228da0 q;                                     // 0x54
};

void choreo2::LocomotionSteerDriver::vfunc_10(ArgBase_228da0 a, ArgPose_228da0 p, Rig_228da0 *rig, float t)
{
    Frame_228da0 f;
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
        if (b89c) {
            Vec3_228da0 *acc = &this->acc;
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
        if (b89d) {
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
            Source_228da0 *src = *(Source_228da0 **)(slot + 0x34);
            if (src != 0) {
                double d = src->length - 1.0f;
                float dd = (float)d;
                f.frame = dd;
                f.frame = FUN_0004af40(0.0f, dd, (float)(d * rate + *(float *)(slot + 0x238)));
                if (first <= last) {
                    Chans_228da0 *ch = (Chans_228da0 *)(slot + 0x38);
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
                                f.v = *(Vec3_228da0 *)(rest->mats + i * 0x40 + 0x30);
                            Vec3_228da0 *c = (Vec3_228da0 *)(rig->mats + i * 0x40 + 0x30);
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
} // namespace fn_00228da0


// 0x00229140 choreo2::LocomotionSteerDriver::vfunc_11 (542 B): equivalent/0x00229140.cpp [wrapped: conflict: Channel; Pose; choreo2::LocomotionSteerDriver]
// sym: ?vfunc_11@LocomotionSteerDriver@choreo2@fn_00229140@@UAEDIIPAVPose@3@M@Z
namespace fn_00229140 {
// STATUS: equivalent (tools/equiv.py level 3: 6536 inputs, branch coverage 17/18, incomplete)
// choreo2::LocomotionSteerDriver::vfunc_11 @ 0x00229140
struct Quat_229140 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_229140 *a, const Quat_229140 *b, float t);
};

struct Vec3_229140 {
    float x, y, z;
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float frame, Vec3_229140 *out);
    virtual void vf5(float frame, Quat_229140 *out);
};

class ChannelSet_229140 {
public:
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Pose {
public:
    char pad0[0x30];
    Vec3_229140 position;
    Quat_229140 *FUN_00221cd0();
    void FUN_00221cf0(Quat_229140 *q);
    void FUN_0022be40(Vec3_229140 *v);
};

class Source_229140 {
public:
    char pad0[0x10];
    float length;
    ChannelSet_229140 *FUN_00288ad0(unsigned int a, unsigned int b);
};

struct Slot_229140 {
    char pad0[0x34];
    Source_229140 *source;
    char pad38[0x238 - 0x38];
    float bias;
};

struct Blend_229140 {
    unsigned int index;
    float weight;
    int pad;
};

hulk_freg __cdecl FUN_0004af40(float lo, float a, float b);

namespace choreo2 {
class LocomotionSteerDriver {
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
    char pad28[0x8b4 - 0x28];
    unsigned int blendCount;
    Blend_229140 blends[1];
};
}

char choreo2::LocomotionSteerDriver::vfunc_11(unsigned int a, unsigned int b, Pose *pose, float t)
{
    if (blendCount == 0)
        return 0;

    struct Frame {
        Quat_229140 rot;
        Vec3_229140 target;
        Vec3_229140 cur;
        Quat_229140 q;
    } fr;
    char result = 0;
    float w = 0.0f;
    volatile float acc = 1.0f - t;
    for (unsigned int i = 0; i < blendCount; i++) {
        Blend_229140 *bl = &blends[i];
        double tw = t * bl->weight;
        Slot_229140 *slot = (Slot_229140 *)((char *)this + bl->index * 0x208);
        acc = (float)(acc + tw);
        w = (float)(tw / acc);
        Source_229140 *src = slot->source;
        if (src == 0)
            continue;
        ChannelSet_229140 *set = src->FUN_00288ad0(a, b);
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
} // namespace fn_00229140

namespace fn_fb966b0a {

// 0x00229360 choreo2::LocomotionSteerDriver::vfunc_12 (438 B): equivalent/0x00229360.cpp
// sym: ?vfunc_12@LocomotionSteerDriver@fn_fb966b0a@@UAE_NPAUSource_229360@2@PAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3196 inputs, branch coverage 22/22)
// choreo2::LocomotionSteerDriver::vfunc_12 @ 0x00229360
bool LocomotionSteerDriver::vfunc_12(Source_229360 *src, float *out)
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
        Blend_229360 *bl = &blends[i];
        sum = sum + bl->weight;
        float ratio = bl->weight / sum;
        Entry_229360 *e = &entries[bl->entry];
        Anim_229360 *anim = e->anim;
        if (anim) {
            float hi;
            float lo;
            if (anim->FUN_00288d10(0, a, b, &hi, &lo)) {
                float lowT = anim->FUN_00288de0(0, 0, a, b);
                float highT = anim->FUN_00288de0(1, 0, a, b);
                hulk_freg t = anim->weight - 1.0f;
                hulk_freg c = FUN_0004af40(0.0f, t, t * scale + e->bias);
                hulk_freg r;
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


// 0x00229560 FUN_00229560 (196 B): equivalent/0x00229560.cpp
// sym: _FUN_00229560
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00229560 @ 0x00229560
extern "C" void __cdecl FUN_00229560(void * a_, void * b_, void * c)
{
    Point_229560 * a = (Point_229560 *)a_;
    Point_229560 * b = (Point_229560 *)b_;
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
    if (((Point_229560 *)c)->y > b->y) {
        unsigned int x = ((Point_229560 *)c)->x, y = ((Point_229560 *)c)->yBits, z = ((Point_229560 *)c)->z;
        ((Point_229560 *)c)->x = b->x; ((Point_229560 *)c)->yBits = b->yBits; ((Point_229560 *)c)->z = b->z;
        b->x = x; b->yBits = y; b->z = z;
    }
    if (b->y > a->y) {
        unsigned int x = b->x, y = b->yBits, z = b->z;
        b->x = a->x; b->yBits = a->yBits; b->z = a->z;
        a->x = x; a->yBits = y; a->z = z;
    }
}


// 0x00229630 FUN_00229630 (166 B): equivalent/0x00229630.cpp
// sym: ?FUN_00229630@fn_fb966b0a@@YAXPAUItem_229630@1@HHU21@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 8/8)
// FUN_00229630 @ 0x00229630
// Sift-down half of an adjust-heap (children compared by key) followed by FUN_00228910 sift-up.
void __cdecl FUN_00229630(Item_229630 *first, int top, hulk_intptr bottom, Item_229630 value)
{
    int hole = top;
    int idx = 2 * top + 2;
    while (idx < bottom) {
        if (first[idx].key > first[idx - 1].key)
            idx--;
        first[hole] = first[idx];
        hole = idx;
        idx = 2 * idx + 2;
    }
    if (idx == bottom) {
        first[hole] = first[bottom - 1];
        hole = bottom - 1;
    }
    FUN_00228910(first, hole, top, value);
}


// 0x00229700 FUN_00229700 (88 B): matches/0x00229700.cpp
// sym: ?target@fn_fb966b0a@@YAXPAUV@1@00U21@@Z
void target(V* begin, V* end, V* out, V a) {
    *out = *begin;
    fn_00229630(begin, 0, end - begin, a);
}

} // namespace fn_fb966b0a

// 0x00229760 FUN_00229760 (212 B): equivalent/0x00229760.cpp [wrapped: conflict: choreo2::LocomotionSteerDriver]
// sym: ??0LocomotionSteerDriver@choreo2@fn_00229760@@QAE@IIIPBM0@Z
namespace fn_00229760 {
// STATUS: equivalent (tools/equiv.py level 3: 351 inputs, branch coverage 8/8)
// FUN_00229760 @ 0x00229760
struct FUN_0022a980 {
    FUN_0022a980(unsigned int context);
    virtual void slot0();
    char padding[0x24];
};
namespace choreo2 {
struct LocomotionSteerDriver : FUN_0022a980 {
    unsigned int width;
    unsigned int count;
    unsigned int state;
    char pad34[0x89c-0x34];
    unsigned char enabled;
    unsigned char active;
    char pad89e[2];
    unsigned int a,b,c,d,e,f;
    char pad8b8[0x900-0x8b8];
    unsigned int g,h,i;
    virtual void slot0();
    void FUN_00228ac0(unsigned int index, const float* row, float weight);
    LocomotionSteerDriver(unsigned int context, unsigned int width_, unsigned int count_, const float* rows, const float* weights);
};
LocomotionSteerDriver::LocomotionSteerDriver(unsigned int context, unsigned int width_, unsigned int count_, const float* rows, const float* weights)
: FUN_0022a980(context) {
    width=width_; count=count_; state=0;
    enabled=1; active=1;
    a=0; b=0; c=0; d=0; e=0; f=0; g=0; h=0; i=0;
    if(rows) {
        unsigned int stride=width+1;
        for(unsigned int index=0; index<count; ++index) {
            float weight=-1.0f;
            if(weights) weight=weights[index];
            FUN_00228ac0(index, rows, weight);
            rows+=stride;
        }
    }
}
}
} // namespace fn_00229760

namespace fn_fb966b0a {

// 0x00229840 FUN_00229840 (155 B): matches/0x00229840.cpp
// sym: _FUN_00229840
// FUN_00229840 @ 0x00229840
// FUN_00229840: median-of-nine pivot selection step of a sort over 12-byte elements
extern "C" void __cdecl FUN_00229840(void *first, void *mid, void *last)
{
    int n = (int)(((Elem12_229840 *)last) - ((Elem12_229840 *)first));
    if (n > 40) {
        int step = (n + 1) / 8;
        FUN_00229560((Elem12_229840 *)((Elem12_229840 *)first), (Elem12_229840 *)(((Elem12_229840 *)first) + step), (Elem12_229840 *)(((Elem12_229840 *)first) + 2 * step));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)mid) - step), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)(((Elem12_229840 *)mid) + step));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)last) - 2 * step), (Elem12_229840 *)(((Elem12_229840 *)last) - step), (Elem12_229840 *)((Elem12_229840 *)last));
        FUN_00229560((Elem12_229840 *)(((Elem12_229840 *)first) + step), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)(((Elem12_229840 *)last) - step));
    } else {
        FUN_00229560((Elem12_229840 *)((Elem12_229840 *)first), (Elem12_229840 *)((Elem12_229840 *)mid), (Elem12_229840 *)((Elem12_229840 *)last));
    }
}


// 0x002298e0 FUN_002298e0 (97 B): matches/0x002298e0.cpp
// sym: ?FUN_002298e0@fn_fb966b0a@@YAXPAUE_2298e0@1@0@Z
void __cdecl FUN_002298e0(E_2298e0* first, E_2298e0* last) {
    hulk_intptr len = last - first;
    hulk_intptr parent = len / 2;
    while (parent > 0) {
        parent--;
        FUN_00229630(first, parent, len, first[parent]);
    }
}


// 0x002299c0 FUN_002299c0 (971 B): equivalent/0x002299c0.cpp
// sym: ?FUN_002299c0@fn_fb966b0a@@YA?AURange_2299c0@1@PAUElem_2299c0@1@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 61/62, incomplete)
// FUN_002299c0 @ 0x002299c0
// std::_Unguarded_partition over 12-byte elements ordered descending by the float at +4
Range_2299c0 FUN_002299c0(Elem_2299c0 *first, Elem_2299c0 *last)
{
    Elem_2299c0 *mid = first + (last - first) / 2;
    FUN_00229840((Elem_2299c0 *)first, (Elem_2299c0 *)mid, (Elem_2299c0 *)(last - 1));
    Elem_2299c0 *pfirst = mid;
    Elem_2299c0 *plast = pfirst + 1;
    while (first < pfirst && !Before(pfirst[-1], *pfirst) && !Before(*pfirst, pfirst[-1])) {
        --pfirst;
    }
    while (plast < last && !Before(*plast, *pfirst) && !Before(*pfirst, *plast)) {
        ++plast;
    }
    Elem_2299c0 *gfirst = plast;
    Elem_2299c0 *glast = pfirst;
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
            return Range_2299c0(pfirst, plast);
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


// 0x00229dd0 FUN_00229dd0 (124 B): equivalent/0x00229dd0.cpp
// sym: _FUN_00229dd0
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 15/18, incomplete)
// FUN_00229dd0 @ 0x00229dd0
// Insertion sort of [first, last) by descending key.
extern "C" void FUN_00229dd0(void * first_, void *last) {
    Item_229dd0 * first = (Item_229dd0 *)first_;
    if (first == ((Item_229dd0 *)last)) {
        return;
    }
    for (Item_229dd0 *cur = first + 1; cur != ((Item_229dd0 *)last); cur++) {
        Item_229dd0 *next = cur + 1;
        Item_229dd0 *pos;
        if (cur->key > first->key) {
            pos = first;
        } else {
            pos = cur;
            while (cur->key > (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_00228990(pos, cur, next, 0, 0);
        }
    }
}


// 0x00229ea0 FUN_00229ea0 (154 B): equivalent/0x00229ea0.cpp
// sym: _FUN_00229ea0
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 4/4)
// FUN_00229ea0 @ 0x00229ea0
// Heap-sort phase: repeatedly moves the root to the back and re-sifts.
extern "C" void __cdecl FUN_00229ea0(void *first, void * last_)
{
    Elem_229ea0 * last = (Elem_229ea0 *)last_;
    while (last - ((Elem_229ea0 *)first) > 1) {
        --last;
        Elem_229ea0 value = *last;
        *last = *((Elem_229ea0 *)first);
        FUN_00229630(((Elem_229ea0 *)first), 0, last - ((Elem_229ea0 *)first), value);
    }
}


// 0x00229f40 FUN_00229f40 (289 B): equivalent/0x00229f40.cpp
// sym: ?FUN_00229f40@fn_fb966b0a@@YAXPAUItem_229f40@1@0H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 12/14, incomplete)
// FUN_00229f40 @ 0x00229f40
void __cdecl FUN_00229f40(Item_229f40* first, Item_229f40* last, hulk_intptr budget) {
    while (last-first > 32) {
        if (budget <= 0) {
            if (last-first > 1) FUN_002298e0(first,last,0,0);
            FUN_00229ea0((Item_229f40 *)first,(Item_229f40 *)last);
            return;
        }
        Partition split;
        FUN_002299c0(&split,first,last);
        budget = budget/2 + (budget/2)/2;
        if (split.leftEnd-first < last-split.rightBegin) {
            FUN_00229f40(first,split.leftEnd,budget);
            first=split.rightBegin;
        } else {
            FUN_00229f40(split.rightBegin,last,budget);
            last=split.leftEnd;
        }
    }
    if (last-first > 1) FUN_00229dd0((Item_229f40 *)first,(Item_229f40 *)last);
}

} // namespace fn_fb966b0a

// 0x0022a0d0 FUN_0022a0d0 (1152 B): equivalent/0x0022a0d0.cpp [wrapped: conflict: FUN_0004af40]
// sym: ?FUN_0022a0d0@Spawner_22a0d0@fn_0022a0d0@@QAEXM@Z
namespace fn_0022a0d0 {
// STATUS: equivalent (tools/equiv.py level 3: 867 inputs, branch coverage 36/36)
// FUN_0022a0d0 @ 0x0022a0d0
struct Shape_22a0d0 {
    char pad[0x10];
    float f10;
    float f14;
};

struct Slot_22a0d0 {
    char pad[0x34];
    Shape_22a0d0 *shape;
    char pad2[0x208 - 0x38];
};

struct Elem_22a0d0 {
    int idx;
    float w;
    float f;
};

float __cdecl FUN_0004af40(float lo, float hi, float x);
float __cdecl FUN_0015cf40(float x);
void __cdecl FUN_00229f40(Elem_22a0d0 *first, Elem_22a0d0 *last, hulk_intptr n);

class Spawner_22a0d0 {
public:
    char pad0[0x20];
    float f20;
    float f24;
    unsigned n;
    unsigned m;
    char pad30[0x854 - 0x30];
    float tab[3];
    void *grid[16];
    float angle;
    float blend;
    char pad8a8[8];
    float t;
    unsigned k;
    Elem_22a0d0 arr[1];

    void FUN_002287b0(void *g, float w, float tt);
    void FUN_0022a0d0(float dt);
};

void Spawner_22a0d0::FUN_0022a0d0(float dt)
{
    unsigned n0 = n;
    unsigned m1 = m - 1;
    unsigned stride = n0 + 1;
    unsigned row = m1;
    k = 0;
    float T0 = tab[row];
    while (!(t >= T0) && row != 0) {
        row--;
        T0 = tab[row];
    }
    float B = blend;
    if (B > 0.01f && n0 != 0) {
        angle = FUN_0004af40(0.0f, 6.28318548f, angle);
        unsigned n1 = n;
        float step = 6.28318548f / (float)n1;
        float inv = 1.0f / step;
        unsigned idx = (int)(angle * inv);
        unsigned i0 = idx % n1;
        unsigned i1 = (i0 + 1) % n1;
        float S = FUN_0015cf40((angle - (float)i0 * step) * inv);
        unsigned a0 = row * stride;
        if (row >= m - 1) {
            FUN_002287b0(grid[a0 + i0 + 1], (1.0f - S) * B, T0);
            FUN_002287b0(grid[a0 + i1 + 1], S * B, T0);
            FUN_002287b0(grid[a0], 1.0f - B, T0);
        } else {
            volatile float U = tab[row + 1];
            volatile float R = (t - T0) / (U - T0);
            volatile float Rm = 1.0f - R;
            volatile float Sm = 1.0f - S;
            FUN_002287b0(grid[a0 + i0 + 1], Rm * Sm * B, T0);
            FUN_002287b0(grid[a0 + i1 + 1], Rm * S * B, T0);
            volatile float Bm = 1.0f - B;
            FUN_002287b0(grid[a0], Rm * Bm, T0);
            unsigned a1 = a0 + stride;
            FUN_002287b0(grid[a1 + i0 + 1], Sm * R * B, U);
            FUN_002287b0(grid[a1 + i1 + 1], R * S * B, U);
            FUN_002287b0(grid[a1], Bm * R, U);
        }
    } else if (row >= m1) {
        FUN_002287b0(grid[row * stride], 1.0f, T0);
    } else {
        volatile float V = tab[row + 1];
        volatile float R = (t - T0) / (V - T0);
        FUN_002287b0(grid[row * stride], 1.0f - R, T0);
        FUN_002287b0(grid[(row + 1) * stride], R, V);
    }

    Elem_22a0d0 *first = arr;
    Elem_22a0d0 *last = &arr[k];
    FUN_00229f40(first, last, last - first);

    float sum = 0.0f;
    for (unsigned i = 0; i < k; i++) {
        if (arr[i].w < 0.01f) {
            k = i;
            break;
        }
        sum += arr[i].w;
    }

    f20 = 0.0f;
    float W = 0.0f;
    if (k != 0) {
        double inv2 = 1.0f / sum;
        for (unsigned i = 0; i < k; i++) {
            volatile float nw = inv2 * arr[i].w;
            arr[i].w = nw;
            W += nw * arr[i].f;
            Shape_22a0d0 *sh = ((Slot_22a0d0 *)this)[arr[i].idx].shape;
            if (sh) {
                float a = sh->f10 - 1.0f;
                float b = sh->f14;
                if (b < 0.0f)
                    b = 1.0f;
                f20 = a / b * nw + f20;
            }
        }
    }

    if (f20 > 0.0f) {
        double X;
        if (W > 0.0f && t > 0.0f)
            X = t / W * dt;
        else
            X = dt;
        float v = X / f20 + f24;
        f24 = v;
        f24 = FUN_0015cf40(v);
    }
}
} // namespace fn_0022a0d0

namespace fn_fb966b0a {

// 0x0022a550 choreo2::LocomotionSteerDriver::vfunc_9 (122 B): matches/0x0022a550.cpp
// sym: ?Update@LocomotionSteerDriver_22a550@fn_fb966b0a@@UAEXM@Z
void LocomotionSteerDriver_22a550::Update(float dt) {
    if (enabled && *(int*)((char*)this + 0x18) == 0) {
        V3_22a550 v;
        ((ThisCall_00228720*)(this))->GetVel_00228720(&v);
        v.x *= dt;
        v.y *= dt;
        v.z *= dt;
        px += v.x;
        py += v.y;
        pz += v.z;
    }
    Base_0022a0d0(dt);
}

} // namespace fn_fb966b0a
