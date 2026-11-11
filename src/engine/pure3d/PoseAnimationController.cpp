// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002878b0..0x00288820 (kind game, layer engine, confidence high), dominant class pure3d::PoseAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f83362ab {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f83362ab {} using namespace fn_f83362ab;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f83362ab {
struct Arg_2878c0 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};
struct Quat_287a40 {
    float x, y, z, w;
};
struct Vec3_287a40 {
    float x, y, z;
};
struct QuatChannel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(float time, Quat_287a40* out);
    void FUN_0028a8f0(float prev, float time, Quat_287a40* out);
};
struct VecChannel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(float time, Vec3_287a40* out);
    virtual void vfunc_5(float prev, float time, Vec3_287a40* out);
};
struct ChannelPair {
    QuatChannel* quat;
    VecChannel* vec;
    float last;
};
struct Record_287a40 {
    char pad0[0x30];
    Vec3_287a40 v30;
    int pad3c;
};
struct Pose {
    char pad0[0x14];
    Quat_287a40* quats;
    Record_287a40* records;
};
struct PoseSet_287a40 {
    char pad0[8];
    Pose* pose;
    unsigned int count;
    Quat_287a40* quats;
    Record_287a40* records;
    char pad18[8];
    char f20;
    char f21;
    char f22;
    char f23;
};
struct BitSet_287a40 {
    int x0;
    unsigned int words[1];
};
struct Mask_287a40 {
    char pad0[0x10];
    BitSet_287a40* bits;
};
class PoseAnimationController_287a40 {
public:
    char pad0[0x110];
    PoseSet_287a40* set;
    char pad114[0x131 - 0x114];
    char perItem;
    char pad132[2];
    float* items;
    char pad138[0x148 - 0x138];
    int selected;
    Mask_287a40* mask;
    void FUN_00287a40(int unused, float v, float t, ChannelPair* pairs);
};
struct Elem_287db0 {
    char pad[0x2c];
    float FUN_00284f70();
};
struct Inner_287db0 {
    char pad[0x10];
    unsigned int count;
};
struct Mid_287db0 {
    char pad[8];
    Inner_287db0 *inner;
};
struct PoseAnimationController_287db0 {
    char pad00[0x28];
    unsigned int numElems;
    Elem_287db0 elems[1];
    char pad58[0x110 - 0x2c - 0x2c];
    Mid_287db0 *mid;
    char pad114[0x131 - 0x114];
    char enabled;
    char pad132[2];
    float *tracks[1];
    void FUN_00287db0();
};
struct Node { unsigned FUN_00288960(unsigned,unsigned); };
struct Map_287e20 { Node* FUN_00288ad0(unsigned,unsigned); };
struct Group_287e20 {  char data[0x2c]; };
struct Key_287e20 { unsigned a,b; };
struct Keys_287e20 { char pad[0x24]; Key_287e20* entries; };
struct Info_287e20 { char pad[8]; Keys_287e20* keys; unsigned count; };
struct Result_287e20 { unsigned rotation,translation,other; };
struct PoseAnimationController_287e20 {
 char pad0[0x28]; unsigned count; Group_287e20 groups[5]; char pad1[8]; Info_287e20* info; char pad2[8]; Result_287e20* results[5]; unsigned char dirty;
 unsigned char FUN_00285340(); void update();
};
extern void* hulk_at_0042c81c[];
} // namespace fn_f83362ab
void operator delete(void*);
namespace fn_f83362ab {
class Ref_287f40 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_287f40 {
  public:
    void* vptr;
    void Fin_00285f50();
};
class PoseAnimationController_287f40 : public BlendFrameController_287f40 {
  public:
    char pad[0x10c];
    Ref_287f40* m110;
    char pad2[4];
    int m118;
    void* m11c;
    int m120;
    int m124;
    int m128;
    int m12c;
    char pad3[4];
    void* m134;
    ~PoseAnimationController_287f40() throw();
};
struct Vec3_288080 {
    float x, y, z;
};
struct Pair_288080 {
    unsigned int a;
    unsigned int b;
};
struct NameKey_288080 {
    char pad00[8];
    unsigned int lo;          // 0x08
    unsigned int hi;          // 0x0c
};
struct SkeletonData_288080 {
    NameKey_288080 *FUN_0027b670(unsigned int lo, unsigned int hi);
};
class Skeleton {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[4];
    SkeletonData_288080 *data;       // 0x08
    unsigned int jointCount;  // 0x0c
};
void FUN_0008d340(void *p);
extern "C" void *FUN_0008d6d0(unsigned int size);
} // namespace fn_f83362ab
extern "C" Pair_288080 FUN_002672f0(const char *name, int a, int b);
namespace fn_f83362ab {
class PoseAnimationController_288080 {
public:
    char pad000[0x110];
    Skeleton *skeleton;       // 0x110
    char pad114[4];
    unsigned int capacity;    // 0x118
    Vec3_288080 *vecs0;              // 0x11c
    Vec3_288080 *vecs1;              // 0x120
    Vec3_288080 *vecs2;              // 0x124
    Vec3_288080 *vecs3;              // 0x128
    Vec3_288080 *vecs4;              // 0x12c
    unsigned char dirty;      // 0x130
    char pad131[3];
    float *vals0;             // 0x134
    float *vals1;             // 0x138
    float *vals2;             // 0x13c
    float *vals3;             // 0x140
    float *vals4;             // 0x144
    char pad148[4];
    NameKey_288080 *rootKey;         // 0x14c

    void FUN_00288080(Skeleton *sk);
};
} // namespace fn_f83362ab
namespace pure3d {
class Helper_288740 {
  public:
    hulk_intptr run_002886c0(pure3d::PoseAnimationController*);
};
}
namespace fn_f83362ab {
extern int hulk_at_0048f610, hulk_at_0049b9b8, hulk_at_004ce65c;
class Result_288770 {
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
    virtual unsigned int run();
};
extern Result_288770* __cdecl resolve(void*, int, const void*, const void*, int);
struct PoseAnimationController_nv_288770 {
    void set_00288080(hulk_uintptr);
};

} // namespace fn_f83362ab

// 0x002878b0 pure3d::PoseAnimationController::vfunc_3 (3 B): matches/0x002878b0.cpp
// sym: ?vfunc_3@PoseAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::PoseAnimationController::vfunc_3() {
    return true;
}


// 0x002878c0 pure3d::PoseAnimationController::vfunc_26 (39 B): matches/0x002878c0.cpp
// sym: ?vfunc_26@PoseAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::PoseAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Arg_2878c0*)p)->count > 0)
        return ((Arg_2878c0*)p)->tag == 0x4e525450;
    return false;
}

namespace fn_f83362ab {

// 0x00287a40 FUN_00287a40 (575 B): equivalent/0x00287a40.cpp
// sym: ?FUN_00287a40@PoseAnimationController_287a40@fn_f83362ab@@QAEXHMMPAUChannelPair@2@@Z @09fcd2257115 @w444de4b43293
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 16/16)
// FUN_00287a40 @ 0x00287a40
void PoseAnimationController_287a40::FUN_00287a40(int unused, float v, float t, ChannelPair* pairs)
{
    t = 1.0f - t;
    PoseSet_287a40* s0 = set;
    Pose* base = s0->pose;
    unsigned int n = s0->count;
    BitSet_287a40* bits = mask->bits;

    for (unsigned int i = 0; i < n; i++) {
        if (!(bits->words[i >> 5] & (1u << (i & 0x1f))))
            continue;
        if (perItem)
            v = items[i];

        Quat_287a40 qa;
        Vec3_287a40 vb;
        if (pairs[i].quat != 0) {
            if (selected != (int)i)
                pairs[i].quat->vfunc_5(v, &qa);
            else
                pairs[i].quat->FUN_0028a8f0(pairs[i].last, v, &qa);
        } else {
            qa = base->quats[i];
        }
        ((owners::Quaternion_22b750 *)&qa)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_287a40 *)(&qa), (const owners::Quaternion_22b750 *)(const Quat_287a40 *)(&set->quats[i]), t);

        if (pairs[i].vec != 0) {
            if (selected == (int)i)
                pairs[i].vec->vfunc_5(pairs[i].last, v, &vb);
            else
                pairs[i].vec->vfunc_4(v, &vb);
            Vec3_287a40* r = &set->records[i].v30;
            vb.x = (r->x - vb.x) * t + vb.x;
            vb.y = (r->y - vb.y) * t + vb.y;
            vb.z = (r->z - vb.z) * t + vb.z;
        } else {
            vb = base->records[i].v30;
        }

        pairs[i].last = v;
        set->quats[i] = qa;
        set->records[i].v30 = vb;
    }
    PoseSet_287a40* done = set;
    done->f22 = 1;
    done->f23 = 1;
    done->f20 = 0;
    done->f21 = 1;
}


// 0x00287db0 FUN_00287db0 (110 B): matches/0x00287db0.cpp
// sym: ?FUN_00287db0@PoseAnimationController_287db0@fn_f83362ab@@QAEXXZ
// FUN_00287db0 @ 0x00287db0
void PoseAnimationController_287db0::FUN_00287db0()
{
    if (!enabled)
        return;
    for (unsigned int i = 0; i < numElems; i++) {
        float v = elems[i].FUN_00284f70();
        for (unsigned int j = 0; j < mid->inner->count; j++)
            tracks[i][j] = v;
    }
}


// 0x00287e20 FUN_00287e20 (284 B): equivalent/0x00287e20.cpp
// sym: ?update@PoseAnimationController_287e20@fn_f83362ab@@QAEXXZ @2e5f9ddd0e36 @w18d2ffef501d
// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 12/12)
// FUN_00287e20 @ 0x00287e20
void PoseAnimationController_287e20::update() {
 dirty |= FUN_00285340();
 if (!dirty) return;
 dirty=0;
 for(unsigned i=0;i<count;++i) {
 Map_287e20* map=((Map_287e20 *)((owners::Target_284f50 *)&(groups[i]))->FUN_00284f50());
 for(unsigned j=0;j<info->count;++j) {
 Node* node=map->FUN_00288ad0(info->keys->entries[j].a,info->keys->entries[j].b);
 if(node) {
 unsigned r=node->FUN_00288960(0x544f52,0x544f52);
 results[i][j].rotation=r;
 unsigned t=node->FUN_00288960(0x4e415254,0x54434556);
 results[i][j].translation=t;
 } else { results[i][j].rotation=0; results[i][j].translation=0; }
 }
 }
}


// 0x00287f40 FUN_00287f40 (116 B): matches/0x00287f40.cpp
// sym: ??1PoseAnimationController_287f40@fn_f83362ab@@QAE@XZ
PoseAnimationController_287f40::~PoseAnimationController_287f40() throw() {
    vptr = hulk_at_0042c81c;
    _ReadWriteBarrier();
    if (m110) {
        m110->Release();
        m110 = 0;
    }
    m118 = 0;
    if (m11c) {
        operator delete(m11c);
        m11c = 0;
        m120 = 0;
        m124 = 0;
        m128 = 0;
        m12c = 0;
    }
    if (m134)
        operator delete(m134);
    Fin_00285f50();
}

} // namespace fn_f83362ab

// 0x00287fc0 pure3d::PoseAnimationController::vfunc_24 (102 B): matches/0x00287fc0.cpp [wrapped: conflict: pure3d::BlendFrameController]
// sym: ?FUN_00287fc0@PoseAnimationController@fn_00287fc0@@QAEXHMH@Z
namespace fn_00287fc0 {
// pure3d::PoseAnimationController::vfunc_24 @ 0x00287fc0
namespace pure3d {
class BlendFrameController {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void vfunc_24(int a, float b, int c);
    char pad04[0x24];
    unsigned int count;
};
}
class PoseAnimationController : public pure3d::BlendFrameController {
  public:
    char pad2c[0x11c - 0x2c - 0x0];
    char* tracks[1];
    char pad120[0x130 - 0x120];
    unsigned char dirty;
    char pad131[0x148 - 0x131];
    int index;
    void FUN_00287db0();
    void FUN_00287fc0(int a, float b, int c);
};
void PoseAnimationController::FUN_00287fc0(int a, float b, int c) {
    pure3d::BlendFrameController::vfunc_24(a, b, c);
    dirty = 1;
    FUN_00287db0();
    if (index != 0xffff) {
        for (unsigned int i = 0; i < count; i++) {
            *(float*)(tracks[i] + index * 12 + 8) = b;
        }
    }
}
} // namespace fn_00287fc0


// 0x00288030 pure3d::PoseAnimationController::vfunc_6 (48 B): matches/0x00288030.cpp [wrapped: conflict: PoseAnimationController]
// sym: ?vfunc_6@PoseAnimationController@fn_00288030@@UAEXHD@Z
namespace fn_00288030 {
class BlendFrameController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
    virtual void f7();
};
class PoseAnimationController : public BlendFrameController {
  public:
    char pad[12];
    unsigned char flag;
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void vfunc_6(int, char);
    void helper_00287db0();
};
void PoseAnimationController::vfunc_6(int a, char b) {
    BlendFrameController::f6(a, 0);
    helper_00287db0();
    if (flag == 1 || b == 1)
        BlendFrameController::f7();
}
} // namespace fn_00288030


// 0x00288060 pure3d::PoseAnimationController::vfunc_12 (24 B): matches/0x00288060.cpp [wrapped: conflict: PoseAnimationController]
// sym: ?vfunc_12@PoseAnimationController@fn_00288060@@UAEXH@Z
namespace fn_00288060 {
class BlendFrameController {
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
    virtual void vfunc_12(int);
};
class PoseAnimationController : public BlendFrameController {
  public:
    virtual void vfunc_12(int);
    void helper_00287db0();
};
void PoseAnimationController::vfunc_12(int param) {
    BlendFrameController::vfunc_12(param);
    helper_00287db0();
}
} // namespace fn_00288060

namespace fn_f83362ab {

// 0x00288080 FUN_00288080 (463 B): equivalent/0x00288080.cpp
// sym: ?FUN_00288080@PoseAnimationController_288080@fn_f83362ab@@QAEXPAVSkeleton@2@@Z @b1f9a864ec0a @w86d57f8def39
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 20/20)
// FUN_00288080 @ 0x00288080
void PoseAnimationController_288080::FUN_00288080(Skeleton *sk)
{
    if (sk == skeleton)
        return;
    if (skeleton == 0 || skeleton->data != sk->data)
        dirty = 1;
    if (sk)
        sk->AddRef();
    if (skeleton)
        skeleton->Release();
    skeleton = sk;

    if (capacity < sk->jointCount) {
        if (vecs0)
            FUN_0008d340(vecs0);
        capacity = skeleton->jointCount;
        vecs0 = (Vec3_288080 *)FUN_0008d6d0(capacity * 0x3c);
        if (vals0)
            FUN_0008d340(vals0);
        vals0 = (float *)FUN_0008d6d0(capacity * 0x14);
        vecs1 = vecs0 + capacity;
        vals1 = vals0 + capacity;
        vecs2 = vecs1 + capacity;
        vals2 = vals1 + capacity;
        vecs3 = vecs2 + capacity;
        vals3 = vals2 + capacity;
        vecs4 = vecs3 + capacity;
        vals4 = vals3 + capacity;
    }

    if (rootKey)
        rootKey = skeleton->data->FUN_0027b670(rootKey->lo, rootKey->hi);
    if (rootKey == 0) {
        SkeletonData_288080 *d = skeleton->data;
        Pair_288080 p = FUN_002672f0("root", 0, 0);
        rootKey = d->FUN_0027b670(p.a, p.b);
    }
}

} // namespace fn_f83362ab

// 0x002882a0 pure3d::PoseAnimationController::vfunc_27 (74 B): matches/0x002882a0.cpp [wrapped: conflict: pure3d::PoseAnimationController]
// sym: ?vfunc_27@PoseAnimationController@pure3d@fn_002882a0@@UAEXXZ
namespace fn_002882a0 {
namespace pure3d {
struct Sub {
    float calc_00284f70();
    int convert_00284f50();
};
class PoseAnimationController {
  public:
    virtual void vfunc_27();
    char pad[0x28];
    Sub sub;
    char pad2[0xe4];
    float value;
    char pad3[4];
    float other;
    void pre_00287e20();
    void post_00287a40(int, float, float, float);
};
void PoseAnimationController::vfunc_27() {
    if (!(value < 1e-5f)) {
        pre_00287e20();
        post_00287a40(sub.convert_00284f50(), sub.calc_00284f70(), value, other);
    }
}
} // namespace pure3d
} // namespace fn_002882a0


// 0x002882f0 pure3d::PoseAnimationController::vfunc_28 (933 B): equivalent/0x002882f0.cpp [wrapped: conflict: pure3d::PoseAnimationController]
// sym: ?vfunc_28@PoseAnimationController@pure3d@fn_002882f0@@UAEXXZ @b2db782cea39 @wc12103a4bbc1
namespace fn_002882f0 {
// STATUS: equivalent (tools/equiv.py level 3: 205 inputs, branch coverage 26/26)
// pure3d::PoseAnimationController::vfunc_28 @ 0x002882f0
struct Vec3_2882f0 {
    float x, y, z;
};

struct Quat_2882f0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_2882f0* a, const Quat_2882f0* b, float t);
};

struct Mat4_2882f0 {
    char pad00[0x30];
    Vec3_2882f0 pos;
    float w;
};

class RotChannel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(float t, Quat_2882f0* out);
    void FUN_0028a8f0(float prevT, float t, Quat_2882f0* out);
};

class PosChannel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float t, Vec3_2882f0* out);
    virtual void vf5(float prevT, float t, Vec3_2882f0* out);
};

struct Binding_2882f0 {
    RotChannel* rot;
    PosChannel* pos;
    float prevTime;
};

struct Layer_2882f0 {
    float time;
    char pad04[0x14 - 4];
    float weight;
    char pad18[0x2c - 0x18];
    float FUN_00284f70();
    float FUN_00284f60();
};

struct SourcePose {
    char pad00[0x14];
    Quat_2882f0* quats;
    Mat4_2882f0* mats;
};

struct PoseBuffer {
    char pad00[8];
    SourcePose* src;
    unsigned int count;
    Quat_2882f0* quats;
    Mat4_2882f0* mats;
    char pad18[8];
    char flag20;
    char flag21;
    char flag22;
    char flag23;
};

struct Mask_2882f0 {
    int pad00;
    unsigned int bits[1];
};

struct Filter_2882f0 {
    char pad00[0x10];
    Mask_2882f0* mask;
};

struct BlendFrame {
    Vec3_2882f0 p0;
    Vec3_2882f0 v;
    Quat_2882f0 q;
    Quat_2882f0 r;
};

namespace pure3d {

class PoseAnimationController {
public:
    virtual void vfunc_0();
    char pad04[0x28 - 4];
    unsigned int layerCount;
    Layer_2882f0 layers[5];
    char pad108[0x110 - 0x108];
    PoseBuffer* pose;
    float weight;
    char pad118[4];
    Binding_2882f0* binds[4];
    char pad12c[4];
    char flag130;
    char useTimes;
    char pad132[2];
    float* times[4];
    char pad144[4];
    int special;
    Filter_2882f0* filter;
    void FUN_00287e20();
    virtual void vfunc_28();
};

void PoseAnimationController::vfunc_28()
{
    if (weight < 0.00001f)
        return;
    FUN_00287e20();
    bool partial = weight < 1.0f;
    SourcePose* src = pose->src;
    float invw = 1.0f - weight;
    unsigned int n = pose->count;
    Mask_2882f0* mask = filter->mask;

    for (unsigned int i = 0; i < n; i++) {
        if (!(mask->bits[i >> 5] & (1u << (i & 31))))
            continue;

        BlendFrame f;
        f.q.x = 0;
        f.q.y = 0;
        f.q.z = 0;
        f.q.w = 1.0f;
        f.p0.x = 0;
        f.p0.y = 0;
        f.p0.z = 0;

        for (unsigned int l = 0; l < layerCount; l++) {
            float tt = layers[l].FUN_00284f70();
            float wl = layers[l].FUN_00284f60();
            if (useTimes)
                tt = times[l][i];

            if (binds[l][i].rot) {
                if (special != (int)i)
                    binds[l][i].rot->vf5(tt, &f.r);
                else
                    binds[l][i].rot->FUN_0028a8f0(binds[l][i].prevTime, tt, &f.r);
                f.q.FUN_0022b750(&f.q, &f.r, wl);
            } else {
                f.q.FUN_0022b750(&f.q, &src->quats[i], wl);
            }

            if (binds[l][i].pos) {
                if (special != (int)i)
                    binds[l][i].pos->vf4(tt, &f.v);
                else
                    binds[l][i].pos->vf5(binds[l][i].prevTime, tt, &f.v);
                f.p0.x = (f.v.x - f.p0.x) * wl + f.p0.x;
                f.p0.y = (f.v.y - f.p0.y) * wl + f.p0.y;
                f.p0.z = (f.v.z - f.p0.z) * wl + f.p0.z;
            } else {
                Vec3_2882f0* sp = &src->mats[i].pos;
                f.p0.x = (sp->x - f.p0.x) * wl + f.p0.x;
                f.p0.y = (sp->y - f.p0.y) * wl + f.p0.y;
                f.p0.z = (sp->z - f.p0.z) * wl + f.p0.z;
            }
            binds[l][i].prevTime = tt;
        }

        if (partial) {
            f.q.FUN_0022b750(&f.q, &pose->quats[i], invw);
            Vec3_2882f0* dp = &pose->mats[i].pos;
            f.p0.x = (dp->x - f.p0.x) * invw + f.p0.x;
            f.p0.y = (dp->y - f.p0.y) * invw + f.p0.y;
            f.p0.z = (dp->z - f.p0.z) * invw + f.p0.z;
        }
        pose->quats[i] = f.q;
        pose->mats[i].pos = f.p0;
    }

    PoseBuffer* pb = pose;
    pb->flag22 = 1;
    pb->flag23 = 1;
    pb->flag20 = 0;
    pb->flag21 = 1;
}

}
} // namespace fn_002882f0


// 0x002886a0 pure3d::PoseAnimationController::vfunc_2 (30 B): matches/0x002886a0.cpp
// sym: ??_GPoseAnimationController@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::PoseAnimationController::~PoseAnimationController() {}


// 0x002886c0 FUN_002886c0 (117 B): matches/0x002886c0.cpp [wrapped: conflict: pure3d::PoseAnimationController]
// sym: ??0PoseAnimationController@pure3d@fn_002886c0@@QAE@ABU012@@Z
namespace fn_002886c0 {
namespace pure3d {
struct Base_2886c0 {
    Base_2886c0(const Base_2886c0& o);
    virtual void v0();
    char p[0x10c];
};
struct PoseAnimationController : Base_2886c0 {
    int i110;
    int i114;
    int i118;
    int i11c;
    char pad[0x11];
    char c131;
    char pad2[2];
    int i134;
    char pad3[0x10];
    int i148;
    int i14c;
    PoseAnimationController(const PoseAnimationController& o);
    void Set_00288080(int);
    virtual void v1();
};
PoseAnimationController::PoseAnimationController(const PoseAnimationController& o) : Base_2886c0(o) {
    i110 = 0;
    i114 = 0x3f800000;
    i118 = 0;
    i148 = 0xffff;
    i14c = 0;
    i11c = 0;
    i134 = 0;
    Set_00288080(o.i110);
    c131 = o.c131;
    i14c = o.i14c;
}
} // namespace pure3d
} // namespace fn_002886c0


// 0x00288740 pure3d::PoseAnimationController::vfunc_4 (34 B): matches/0x00288740.cpp
// sym: ?vfunc_4@PoseAnimationController@pure3d@@UAEPAXXZ
void* pure3d::PoseAnimationController::vfunc_4() {
    pure3d::Helper_288740* p = (pure3d::Helper_288740*)thunk_FUN_0008d690(0x150);
    if (p)
        return (void*)(p->run_002886c0(this));
    return (void*)(0);
}


// 0x00288770 pure3d::PoseAnimationController::vfunc_5 (91 B): matches/0x00288770.cpp
// sym: ?vfunc_5@PoseAnimationController@pure3d@@UAEXPAX@Z
void pure3d::PoseAnimationController::vfunc_5(void* __p0) { void * arg = (void *)__p0;

    Result_288770* p = resolve(arg, 0, &hulk_at_0048f610, &hulk_at_0049b9b8, 0);
    if (p) {
        ((PoseAnimationController_nv_288770*)this)->set_00288080(p->run());
    } else {
        hulk_uintptr x = (hulk_uintptr)resolve(arg, 0, &hulk_at_0048f610, &hulk_at_004ce65c, 0);
        ((PoseAnimationController_nv_288770*)this)->set_00288080(x);
    }
}

