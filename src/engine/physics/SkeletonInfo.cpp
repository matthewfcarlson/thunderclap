// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00312440..0x00312900 (kind game, layer engine, confidence medium), dominant class physics::SkeletonInfo
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f6834bb6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f6834bb6 {} using namespace fn_f6834bb6;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f6834bb6 {
extern "C" char DAT_0043223c[];
void __cdecl thunk_0008d340(void*);
struct SkeletonInfo_3128d0 {
    void Dtor_0027afd0();
};
struct SkeletonInfo {
    void* vf;
    char pad[12];
    void* member;
    void Free();
};

} // namespace fn_f6834bb6

// 0x00312440 FUN_00312440 (931 B): equivalent/0x00312440.cpp [wrapped: conflict: physics::SkeletonInfo; pure3d::Entity]
// sym: ??0SkeletonInfo@physics@fn_00312440@@QAE@PAUSkeletonSrc@2@@Z @9cc685c8d1a3 @w80f772fc8d89
namespace fn_00312440 {
// STATUS: equivalent (tools/equiv.py level 3: 31 inputs, branch coverage 34/34)
// FUN_00312440 @ 0x00312440

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_312440 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Mat4_312440 {
    char pad00[0x30];
    Vec3_312440 pos;
    float w;
    void FUN_0022c3b0(Vec3_312440* in, Vec3_312440* out);
};

struct NameHolder_312440 {
    char pad[8];
    void FUN_0027af70(NameHolder_312440* src);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    NameHolder_312440 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Bone_312440 {
    Vec3_312440 pos;
    Vec3_312440 axis;
    float len;
};

struct SkeletonSrc {
    char pad00[8];
    NameHolder_312440 nameHolder;
    int count;
    char pad14[0x1c - 0x14];
    Mat4_312440* local;
    Mat4_312440* world;
    char pad24[4];
    unsigned short* parent;
};

extern "C" void* FUN_0008d6d0(unsigned int size);
extern "C" void* FUN_00266e00(int kind, unsigned int size);
extern "C" void FUN_00267090(void* p);

namespace physics {

class SkeletonInfo : public pure3d::Entity {
public:
    Bone_312440* bones;
    int count;
    virtual void vfunc_0();
    SkeletonInfo(SkeletonSrc* src);
};

SkeletonInfo::SkeletonInfo(SkeletonSrc* src)
{
    int n = src->count;
    count = n;
    Bone_312440* arr = 0;
    int* mem = (int*)FUN_0008d6d0(n * 0x1c + 4);
    if (mem) {
        *mem = n;
        arr = (Bone_312440*)(mem + 1);
        for (int i = 0; i < n; i++) {
            arr[i].pos.x = 0;
            arr[i].pos.y = 0;
            arr[i].pos.z = 0;
            arr[i].axis.x = 0;
            arr[i].axis.y = 0;
            arr[i].axis.z = 0;
            arr[i].len = 0;
        }
    }
    bones = arr;
    nameHolder.FUN_0027af70(&src->nameHolder);

    int* counts = (int*)FUN_00266e00(1, count * 4);
    memset(counts, 0, count * 4);

    for (int i = 1; i < count; i++) {
        int j = src->parent[i];
        if (counts[j] == 0) {
            Vec3_312440* p = &src->local[i].pos;
            Bone_312440* b = &bones[j];
            b->pos.x = p->x + b->pos.x;
            b->pos.y = p->y + b->pos.y;
            b->pos.z = p->z + b->pos.z;
            Vec3_312440* q = &src->local[j].pos;
            b = &bones[j];
            b->pos.x = b->pos.x - q->x;
            b->pos.y = b->pos.y - q->y;
            b->pos.z = b->pos.z - q->z;
            counts[j] = counts[j] + 1;
        }
    }

    for (int k = 0; k < count; k++) {
        if (counts[k] > 0)
            bones[k].len = bones[k].pos.FUN_0022d110() / counts[k];
    }

    for (int k = 0; k < count; k++) {
        Bone_312440* parent = &bones[src->parent[k]];
        Bone_312440* b = &bones[k];
        b->axis.x = parent->pos.y * b->pos.z - parent->pos.z * b->pos.y;
        b->axis.y = parent->pos.z * b->pos.x - b->pos.z * parent->pos.x;
        b->axis.z = b->pos.y * parent->pos.x - parent->pos.y * b->pos.x;
        bones[k].axis.FUN_0022d110();
        b = &bones[k];
        double X = b->axis.y * b->pos.z - b->axis.z * b->pos.y;
        double Y = b->pos.x * b->axis.z - b->pos.z * b->axis.x;
        double Z = b->pos.y * b->axis.x - b->pos.x * b->axis.y;
        double len = sqrt(Z * Z + Y * Y + X * X);
        if (len < 0.8f) {
            b->axis.z = 0;
            b->axis.y = 0;
            b->axis.x = 0;
        }
    }

    for (int k = 0; k < count; k++) {
        if (counts[k] > 0) {
            Bone_312440* b = &bones[k];
            Vec3_312440 v = b->pos;
            src->world[k].FUN_0022c3b0(&v, &b->pos);
        } else {
            Bone_312440* from = &bones[src->parent[k]];
            Bone_312440* to = &bones[k];
            *to = *from;
            to = &bones[k];
            to->axis.x = 1.0f;
            to->axis.y = 0;
            to->axis.z = 0;
        }
    }

    for (int k = 1; k < count; k++) {
        Bone_312440* b = &bones[k];
        unsigned int j = src->parent[k];
        Vec3_312440 v = b->axis;
        src->world[j].FUN_0022c3b0(&v, &b->axis);
    }

    FUN_00267090(counts);
}

}
} // namespace fn_00312440


// 0x003128b0 physics::SkeletonInfo::vfunc_2 (30 B): matches/0x003128b0.cpp
// sym: ??_GSkeletonInfo@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::SkeletonInfo::~SkeletonInfo() {}

namespace fn_f6834bb6 {

// 0x003128d0 FUN_003128d0 (36 B): matches/0x003128d0.cpp
// sym: ?Free@SkeletonInfo@fn_f6834bb6@@QAEXXZ
void SkeletonInfo::Free() {
    vf = (void*)((hulk_intptr)DAT_0043223c);
    if (member)
        thunk_0008d340((char*)member - 4);
    ((SkeletonInfo_3128d0*)this)->Dtor_0027afd0();
}

} // namespace fn_f6834bb6
