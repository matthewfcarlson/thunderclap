// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002843c0..0x002849c0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fffbb65f {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fffbb65f {} using namespace fn_fffbb65f;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fffbb65f {
struct Elem {
    char pad[16];
    void update_0022b650(void*);
};
class Obj {
  public:
    char pad[12];
    unsigned count;
    Elem* elems;
    char* data;
    char pad2[10];
    char dirty;
    char ready;
    void run(int);
};
class Worker_284410 {
  public:
};
class Obj_284410 {
  public:
    char p0[12];
    unsigned count;
    Worker_284410* base;
    char* values;
    char p18[8];
    unsigned char flag;
    void Run(int);
};
struct Mat_284460 {
    float m[16];
};
struct Skeleton {
  public:
    virtual void retain();
    char _m_pad_4[0xc];
    unsigned int count;
    char _m_pad_14[0x14];
    unsigned short *parent;
};
class Pose {
public:
    char pad00[8];
    Skeleton *skeleton;
    unsigned int count;
    char pad10[4];
    Mat_284460 *local;
    char pad18[4];
    Mat_284460 *world;
    char pad20[3];
    char dirty;
    void Update(const Mat_284460 *root);
};
struct Vector { unsigned int x,y,z,w; };
struct Matrix { unsigned int words[16]; void FUN_0022b980(); };
struct Source_2845a0 { char pad[20]; Vector* vectors; Matrix* matrices; };
struct Object { char pad[8]; Source_2845a0* source; unsigned int count; Vector* vectors; Matrix* matrices; Vector* optionalVectors; Matrix* resetMatrices; char pad20[2]; unsigned char flag22,flag23; unsigned int generation; void target(); };
extern "C" char DAT_0042c588[];
class Ref_2847f0 {
  public:
    virtual void A();
    virtual void B();
};
struct Obj_2847f0 {
    void** v;
    char pad4[4];
    Ref_2847f0* m;
    char pad[0x1c];
    void* p28;
};
void cleanup_0008d340(void*);
void* __cdecl FUN_0008d6d0(unsigned int);
namespace pure3d {
struct Pose {
 virtual void slot0();
 unsigned int refs;
 Skeleton* skeleton;
 unsigned int count;
 char* data;
 char* matrices;
 char* extra;
 char* matrices2;
 char pad[2];
 unsigned char flag1, flag2;
 unsigned int revision;
 void* allocation;
 Pose(Skeleton*, char);
 void FUN_002845a0();
 void FUN_00284410(int);
 void FUN_002843c0(int);
 void FUN_00284460(int);
 void FUN_002844f0(int);
};
}


// 0x002843c0 FUN_002843c0 (77 B): matches/0x002843c0.cpp
// sym: ?run@Obj@fn_fffbb65f@@QAEXH@Z
void Obj::run(int) {
    if (dirty) {
        for (unsigned i = 0; i < count; ++i)
            elems[i].update_0022b650(data + i * 64);
        dirty = 0;
        ready = 1;
    }
}


// 0x00284410 FUN_00284410 (73 B): matches/0x00284410.cpp
// sym: ?Run@Obj_284410@fn_fffbb65f@@QAEXH@Z
void Obj_284410::Run(int arg) {
    if (flag) {
        unsigned i = 0;
        if (0 < count) {
            unsigned boff = 0;
            unsigned voff = 0;
            do {
                ((owners::Quat_22b370 *)(((Worker_284410*)((char*)base + boff))))->FUN_0022b370((const float *)(values + voff));
                ++i;
                voff += 0x40;
                boff += 0x10;
            } while (i < count);
        }
        flag = 0;
    }
}


// 0x00284460 FUN_00284460 (132 B): matches/0x00284460.cpp
// sym: ?Update@Pose@fn_fffbb65f@@QAEXPBUMat_284460@2@@Z
// FUN_00284460 @ 0x00284460
void Pose::Update(const Mat_284460 *root)
{
    if (root != 0) {
        ((owners::Matrix_22ca90 *)world)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat_284460 *)local, (const owners::Matrix_22ca90 *)(const Mat_284460 *)root);
    } else {
        if (!dirty)
            return;
        *world = *local;
    }
    Mat_284460 *out = world + 1;
    Mat_284460 *in = local + 1;
    for (unsigned int i = 1; i < count; i++) {
        ((owners::Matrix_22ca90 *)out)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat_284460 *)in, (const owners::Matrix_22ca90 *)(const Mat_284460 *)(world + skeleton->parent[i]));
        out++;
        in++;
    }
    dirty = 0;
}

} // namespace fn_fffbb65f

// 0x002844f0 FUN_002844f0 (165 B): equivalent/0x002844f0.cpp [wrapped: conflict: Pose]
// sym: ?FUN_002844f0@Pose@fn_002844f0@@QAEXPBURow16_2844f0@2@@Z
namespace fn_002844f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2533 inputs, branch coverage 8/8)
// FUN_002844f0 @ 0x002844f0
struct Row16_2844f0 {
    int a, b, c, d;
};

extern "C" void __cdecl FUN_0022b080(float *, const float *, const float *);

struct Skeleton {
    char pad0[0x28];
    unsigned short *parents;    // 0x28
};

class Pose {
public:
    char pad0[8];
    Skeleton *skeleton;         // 0x08
    unsigned int count;         // 0x0c
    Row16_2844f0 *local;               // 0x10
    char pad14[4];
    Row16_2844f0 *world;               // 0x18
    void FUN_002844f0(const Row16_2844f0 *root);
};

void Pose::FUN_002844f0(const Row16_2844f0 *root)
{
    if (world == 0)
        return;
    if (root != 0) {
        Row16_2844f0 rootCopy;
        ((owners::Quat_22b370 *)&rootCopy)->FUN_0022b370((const float *)(const Row16_2844f0 *)root);
        FUN_0022b080((float *)(Row16_2844f0 *)world, (const float *)(Row16_2844f0 *)local, (const float *)(Row16_2844f0 *)(&rootCopy));
    } else {
        world[0] = local[0];
    }
    Row16_2844f0 *src = local + 1;
    Row16_2844f0 *dst = world + 1;
    for (unsigned int i = 1; i < count; i++) {
        FUN_0022b080((float *)(Row16_2844f0 *)dst, (const float *)(Row16_2844f0 *)src, (const float *)(Row16_2844f0 *)(world + skeleton->parents[i]));
        dst++;
        src++;
    }
}
} // namespace fn_002844f0

namespace fn_fffbb65f {

// 0x002845a0 FUN_002845a0 (184 B): equivalent/0x002845a0.cpp
// sym: ?target@Object@fn_fffbb65f@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 135 inputs, branch coverage 6/6)
// FUN_002845a0 @ 0x002845a0
void Object::target() {
 for(unsigned int i=0;i<count;++i) {
  const volatile Vector* src=source->vectors+i;
  volatile Vector* dst=vectors+i;
  dst->x=src->x; dst->y=src->y; dst->z=src->z; dst->w=src->w;
  const volatile unsigned int* ms=source->matrices[i].words;
  volatile unsigned int* md=matrices[i].words;
  for(unsigned int j=0;j<16;++j) md[j]=ms[j];
  resetMatrices[i].FUN_0022b980();
  Vector* v=optionalVectors;
  if(v) { v[i].z=0; v[i].y=0; v[i].x=0; v[i].w=0x3f800000; }
 }
 unsigned int next=generation+1;
 flag22=0; flag23=1; generation=next;
}

} // namespace fn_fffbb65f

// 0x00284660 FUN_00284660 (359 B): equivalent/0x00284660.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_00284660@Pose@fn_00284660@@QAE_NPAV12@MI@Z
namespace fn_00284660 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00284660 @ 0x00284660
struct Quat_284660 {
    float x, y, z, w;
};

struct Vec3Pad {
    float x, y, z;
};

struct Matrix {
    char pad00[0x30];
    Vec3Pad pos;
    float pad3c;
};

extern "C" void __cdecl FUN_0022b080(float *, const float *, const float *);

struct Info_284660 {
    char pad00[0x10];
    unsigned int count;
};

class Pose {
public:
    char pad00[8];
    Info_284660* info;
    char pad0c[4];
    Quat_284660* quats;
    Matrix* mats;
    char pad18[8];
    char f20;
    char f21;
    char f22;
    char f23;

    bool FUN_00284660(Pose* other, float t, unsigned int only);
};

bool Pose::FUN_00284660(Pose* other, float t, unsigned int only)
{
    for (unsigned int i = 0; i < info->count; i++) {
        if (i != only) {
            ((owners::Quaternion_22b750 *)&(quats[i]))->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_284660 *)(&quats[i]), (const owners::Quaternion_22b750 *)(const Quat_284660 *)(&other->quats[i]), t);
            Vec3Pad* d = &mats[i].pos;
            const Vec3Pad* s = &other->mats[i].pos;
            d->x = (s->x - d->x) * t + d->x;
            d->y = (s->y - d->y) * t + d->y;
            d->z = (s->z - d->z) * t + d->z;
        } else {
            Quat_284660 q;
            q.x = 0.0f;
            q.y = 0.0f;
            q.z = 0.0f;
            q.w = 1.0f;
            ((owners::Quaternion_22b750 *)&q)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_284660 *)(&q), (const owners::Quaternion_22b750 *)(const Quat_284660 *)(&other->quats[i]), t);
            FUN_0022b080((float *)(Quat_284660 *)(&q), (const float *)(const Quat_284660 *)(&q), (const float *)(const Quat_284660 *)(&quats[i]));
            quats[i] = q;
            Vec3Pad* d = &mats[i].pos;
            const Vec3Pad* s = &other->mats[i].pos;
            d->x = t * s->x + d->x;
            d->y = t * s->y + d->y;
            d->z = t * s->z + d->z;
        }
    }
    f22 = 1;
    f23 = 1;
    f20 = 0;
    f21 = 1;
    return true;
}
} // namespace fn_00284660

namespace fn_fffbb65f {

// 0x002847f0 FUN_002847f0 (48 B): matches/0x002847f0.cpp
// sym: ?target@fn_fffbb65f@@YIXPCUObj_2847f0@1@@Z
void __fastcall target(volatile Obj_2847f0* self) {
    self->v = (void**)((hulk_intptr)DAT_0042c588);
    Ref_2847f0* r = self->m;
    if (r) {
        r->B();
        self->m = 0;
    }
    cleanup_0008d340(self->p28);
    self->v = (void**)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_fffbb65f

// 0x00284820 FUN_00284820 (50 B): matches/0x00284820.cpp
// sym: ?FUN_00284820@C_284820@owners@@QAEXH@Z
void owners::C_284820::FUN_00284820(hulk_intptr x) {
    A(((int)x));
    B(((int)x));
    D(((int)x));
    E(((int)x));
    ++count;
}


// 0x00284860 FUN_00284860 (73 B): matches/0x00284860.cpp [wrapped: conflict: Obj]
// sym: ?fn@Obj@fn_00284860@@QAEXHHPAUItem@2@@Z
namespace fn_00284860 {
struct Item {
    int v[16];
};
class Obj {
  public:
    char pad[0x1c];
    Item* items;
    char pad2[4];
    int count;
    void Fna_00284410(int);
    void Fnb_002843c0(int);
    void Fnc_00284460(int);
    void Fnd_002844f0(int);
    void fn(int index, int value, Item* out);
};
void Obj::fn(int index, int value, Item* out) {
    Fna_00284410(value);
    Fnb_002843c0(value);
    Fnc_00284460(value);
    Fnd_002844f0(value);
    ++count;
    *out = items[index];
}
} // namespace fn_00284860


// 0x002848b0 FUN_002848b0 (86 B): matches/0x002848b0.cpp
// sym: ?FUN_002848b0@Obj_2848b0@owners@@QAEXHHPAH@Z
void owners::Obj_2848b0::FUN_002848b0(hulk_intptr index, int value, int* out) {
    H1(value);
    H2(value);
    H3(value);
    H4(value);
    ++count;
    int* q = (int*)((char*)base + (((int)index) << 6) + 0x30);
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
}

namespace fn_fffbb65f {

// 0x00284910 FUN_00284910 (176 B): equivalent/0x00284910.cpp
// sym: ??0Pose@pure3d@fn_fffbb65f@@QAE@PAUSkeleton@2@D@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00284910 @ 0x00284910
namespace pure3d {
Pose::Pose(Skeleton* s, char optional) {
 refs=0; skeleton=s; extra=0; flag1=1; flag2=1; revision=0;
 s->retain();
 unsigned int n=skeleton->count;
 count=n;
 unsigned int bytes=n*144;
 if(optional) bytes+=n*16;
 char* p=(char*)FUN_0008d6d0(bytes);
 allocation=p; matrices=p;
 p+=count*64; matrices2=p;
 p+=count*64; data=p;
 extra=optional ? p+count*16 : 0;
 FUN_002845a0(); FUN_00284410(0); FUN_002843c0(0); FUN_00284460(0); FUN_002844f0(0);
 ++revision;
}
}

} // namespace fn_fffbb65f
