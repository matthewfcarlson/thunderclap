// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010ac20..0x0010b2a0 (kind game, layer game, confidence medium), dominant class CSeparationBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f3deebf2 {
#define TREE_TU_END }
namespace fn_f3deebf2 {} using namespace fn_f3deebf2;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3deebf2 {
struct Vec3_10ac60 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Vec4_10ac60 {
    float x, y, z, w;
};
struct Locator {
    void FUN_00059a50(Vec3_10ac60 *out);
};
struct Body_10ac60 {
    char pad[0x10];
    Locator *locator;
    char FUN_000359e0(Vec4_10ac60 *out);
};
struct Vec3_10ad90 {
    float x, y, z;
};
struct List_10ad90 {
    char pad[0xc];
    int count;
    int GetItem_00024190(int i);
    bool IsSkipped_00025d30(int id);
};
struct Agent_10ad90 {
    char pad[0x20];
    List_10ad90* list;
};
hulk_freg FUN_0010ac60(int ex, int item, float w, Vec3_10ad90* out);
extern "C" void *__cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);
struct V3_10ae50 {
    float x, y, z;
    bool FUN_0022d2b0(V3_10ae50 *out, float eps);
    hulk_freg FUN_0022d110();
};
struct Part_10ae50 {
    char pad0[0x129];
    char flag129;
};
struct Item_10ae50 {
    char pad0[0x1ca0];
    Part_10ae50 *part;
};
struct Group_10ae50 {
    char pad0[0xc];
    int count;
    Item_10ae50 *FUN_00024190(int index);
    bool FUN_00025d30(Item_10ae50 *item);
};
} // namespace fn_f3deebf2
struct World {
    char pad0[0x20];
    Group_10ae50 *group;
};
namespace fn_f3deebf2 {
hulk_freg __cdecl FUN_0010ac60(void *a, Item_10ae50 *item, void *b, V3_10ae50 *out);
struct Vector { float x,y,z; };
struct Collection_10b1c0 { char pad[12]; int count; Item* FUN_00024190(int index); bool FUN_00025d30(Item* item); };
struct Owner_10b1c0 { char pad[32]; Collection_10b1c0* collection; };
hulk_freg __cdecl FUN_0010ac60(Item*, Item*, int, Vector*);

} // namespace fn_f3deebf2

// 0x0010ac20 CSeparationBehaviour::vfunc_2 (31 B): matches/0x0010ac20.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0010ac20@@UAEPAV123@E@Z
namespace fn_0010ac20 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSteeringBehaviour_10ac20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public CSteeringBehaviour_10ac20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0010ac20

namespace fn_f3deebf2 {

// 0x0010ac60 FUN_0010ac60 (301 B): equivalent/0x0010ac60.cpp
// sym: ?FUN_0010ac60@fn_f3deebf2@@YAMPAUBody_10ac60@1@0MPAUVec3_10ac60@1@@Z @40ff7cdc0de0 @w2bc546d66f04
// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// FUN_0010ac60 @ 0x0010ac60
hulk_freg FUN_0010ac60(Body_10ac60 *a, Body_10ac60 *b, float radius, Vec3_10ac60 *out)
{
    Vec3_10ac60 pa;
    Vec3_10ac60 pb;
    Vec4_10ac60 info;
    float ra;                           // float locals in the original (fstp dword): 0.5 * a denormal rounds
    float rb;

    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;

    a->locator->FUN_00059a50(&pa);
    b->locator->FUN_00059a50(&pb);

    float dx = pa.x - pb.x;
    ra = 0.0f;
    hulk_freg dz = pa.z - pb.z;
    float dzs = dz;                     // stored (fst), and the product reads it back: unrounded * rounded
    float d2 = dz * dzs + dx * dx;

    if (a->FUN_000359e0(&info))
        ra = info.w * 0.5f;
    rb = 0.0f;
    if (b->FUN_000359e0(&info))
        rb = info.w * 0.5f;

    hulk_freg reach = rb + ra + radius;
    if (!(d2 < reach * reach))
        return -1.0f;

    out->x = dx;
    out->y = 0.0f;
    out->z = dz;
    out->FUN_0022d110();

    hulk_freg gap = (hulk_freg)sqrt((double)d2) - ra - rb;
    if (gap < 0.0f)
        return 0.0f;
    return gap;
}

} // namespace fn_f3deebf2

// 0x0010ad90 CSeparationBehaviour::vfunc_3 (185 B): matches/0x0010ad90.cpp
// sym: ?vfunc_3@CSeparationBehaviour@@UAE_NHHPAXHH@Z
bool CSeparationBehaviour::vfunc_3(hulk_intptr __p0, int ex, void* __p2, int p5, int p6) { Agent_10ad90 * a = (Agent_10ad90 *)__p0; Vec3_10ad90 * out = (Vec3_10ad90 *)__p2;

    int n = a->list->count;
    int i = 0;
    out->z = 0.0f;
    out->y = 0.0f;
    out->x = 0.0f;
    if (0 < n) {
        do {
            int item = a->list->GetItem_00024190(i);
            if (!a->list->IsSkipped_00025d30(item) && item != ex) {
                Vec3_10ad90 tmp;
                FUN_0010ac60(ex, item, 1.0f, &tmp);
                out->x += tmp.x;
                out->y += tmp.y;
                out->z += tmp.z;
            }
            ++i;
        } while (i < n);
    }
    if (this->f_0c) {
        float w = this->f_08;
        out->x = w * out->x;
        out->y = w * out->y;
        out->z = w * out->z;
    }
    return true;
}

namespace fn_f3deebf2 {

// 0x0010ae50 FUN_0010ae50 (877 B): equivalent/0x0010ae50.cpp
// sym: ?FUN_0010ae50@fn_f3deebf2@@YAMPAUWorld@@PAX1PAUV3_10ae50@1@2_NPAPAUItem_10ae50@1@@Z @d28dabf94ae7 @w52746f704a77
// STATUS: equivalent (tools/equiv.py level 3: 183 inputs, branch coverage 48/50, incomplete)
// FUN_0010ae50 @ 0x0010ae50
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
float __cdecl FUN_0010ae50(World *w, void *a, void *b, V3_10ae50 *dir, V3_10ae50 *sum, bool mark, Item_10ae50 **hit)
{
    int n = w->group->count;
    float best = -1.0f;
    float r;
    sum->z = 0.0f;
    sum->y = 0.0f;
    sum->x = 0.0f;
    if (hit)
        *hit = 0;
    V3_10ae50 *arr = (V3_10ae50 *)FUN_0008d6d0(n * 12);
    for (int k = 0; k < n; k++) {
        arr[k].z = 0.0f;
        arr[k].y = 0.0f;
        arr[k].x = 0.0f;
    }
    for (int i = 0; i < n; i++) {
        V3_10ae50 wv;
        wv.x = 0.0f;
        wv.y = 0.0f;
        wv.z = 0.0f;
        Item_10ae50 *item = w->group->FUN_00024190(i);
        if (item == 0)
            continue;
        if (w->group->FUN_00025d30(item))
            continue;
        if ((void *)item == a)
            continue;
        r = FUN_0010ac60(a, item, b, &wv);
        if (r < 0.0f || !(r >= 0.0f))
            continue;
        for (int k = 0; k < n; k++) {
            V3_10ae50 t;
            t.x = 0.0f;
            t.y = 0.0f;
            t.z = 0.0f;
            if (!arr[k].FUN_0022d2b0(&t, 1e-5f)) {
                if (wv.z * arr[k].z + wv.y * arr[k].y + wv.x * arr[k].x < -0.7f) {
                    arr[k].z = 0.0f;
                    arr[k].y = 0.0f;
                    arr[k].x = 0.0f;
                    r = -1.0f;
                }
            }
        }
        if (r < 0.0f)
            continue;
        int j;
        for (j = 0; j < n; j++) {
            V3_10ae50 t2;
            t2.x = 0.0f;
            t2.y = 0.0f;
            t2.z = 0.0f;
            if (arr[j].FUN_0022d2b0(&t2, 1e-5f))
                break;
        }
        if (j < n)
            arr[j] = wv;
        if (mark) {
            Part_10ae50 *p = item->part;
            if (p)
                p->flag129 = 1;
        }
        if (wv.x * dir->x + wv.y * dir->y + wv.z * dir->z < 0.0f) {
            dir->z = 0.0f;
            dir->y = 0.0f;
            dir->x = 0.0f;
        }
        if (best < 0.0f || r < best) {
            best = r;
            if (hit)
                *hit = item;
        }
    }
    for (int j = 0; j < n; j++) {
        sum->x = arr[j].x + sum->x;
        sum->y = arr[j].y + sum->y;
        sum->z = sum->z + arr[j].z;
    }
    sum->FUN_0022d110();
    thunk_FUN_00267090(arr);
    return best;
}


// 0x0010b1c0 FUN_0010b1c0 (209 B): equivalent/0x0010b1c0.cpp
// sym: _FUN_0010b1c0 @24ceada94323 @weaf0050d8d0d
// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 16/16)
// FUN_0010b1c0 @ 0x0010b1c0
extern "C" float __cdecl FUN_0010b1c0(Owner_10b1c0* owner, Item* subject, int flags, Vector* output)
{
 int count = owner->collection->count;
 float best = -1.0f;
 output->z = 0.0f; output->y = 0.0f; output->x = 0.0f;
 for(int i=0;i<count;++i) {
  Item* item=owner->collection->FUN_00024190(i);
  if(item && !owner->collection->FUN_00025d30(item) && item != subject) {
   Vector contribution;
   float value=FUN_0010ac60(subject,item,flags,&contribution);
   output->x = contribution.x + output->x;
   output->y = contribution.y + output->y;
   output->z = contribution.z + output->z;
   if(best < 0.0f || (value > 0.0f && value < best)) best=value;
  }
 }
 return best;
}

} // namespace fn_f3deebf2
