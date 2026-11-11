// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002248a0..0x00224ce0 (kind game, layer engine, confidence high), dominant class choreo2::JointDriver
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/choreo2.h"
#include "gen/choreo2.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0e84e5f {
#define TREE_TU_END }
namespace fn_f0e84e5f {} using namespace fn_f0e84e5f;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f0e84e5f {
extern "C" char DAT_004272f0[];
class JointDriver_2248a0 {
  public:
    void Init();
};
class Part_2248a0 {
  public:
    void Init();
};
class JointDriver {
  public:
    int* vptr;
    char pad[12];
    int mValue;
    int mState;
    char pad2[4];
    JointDriver* Init();
};
class Obj_2249a0 {
    char pad[0x10];

  public:
    unsigned int value;
};
class Obj_2249b0 {
    char pad[0x10];

  public:
    unsigned int value;
};
class Driver_224b90 {
    char pad[1];
};
class Helper_224c60 {
  public:
    hulk_intptr run(choreo2::JointDriver*);
};
extern void* thunk_FUN_0008d690(int);


// 0x002248a0 FUN_002248a0 (66 B): matches/0x002248a0.cpp
// sym: ?Init@JointDriver@fn_f0e84e5f@@QAEPAV12@XZ
// data: gCount_2248a0 = DAT_004e5aac
JointDriver* JointDriver::Init() {
    ((JointDriver_2248a0*)this)->Init();
    this->vptr = (int*)((hulk_intptr)DAT_004272f0);
    mValue = 0;
    mState = 3;
    ((Part_2248a0*)((char*)this + 0x18))->Init();
    ++(*(int*)&DAT_004e5aac);
    if ((*(int*)&DAT_004e5aac) <= (*(int*)&DAT_004e5ab0)) {
    } else
        (*(int*)&DAT_004e5ab0) = (*(int*)&DAT_004e5aac);
    return this;
}

} // namespace fn_f0e84e5f

// 0x002248f0 FUN_002248f0 (68 B): matches/0x002248f0.cpp [wrapped: conflict: JointDriver]
// sym: ??0JointDriver@fn_002248f0@@QAE@H@Z
namespace fn_002248f0 {
// data: gCount_2248f0 = DAT_004e5aac

extern "C" char DAT_004272f0[];
class JointDriver {
  public:
    char pad[0x18];
    void Init();
    JointDriver(int arg);
};
extern "C" void __fastcall FUN_0022a8e0(void*);
JointDriver::JointDriver(int arg) {
    FUN_0022a8e0((void*)(this));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004272f0);
    *(int*)((char*)this + 0x10) = arg;
    *(int*)((char*)this + 0x14) = 3;
    ((JointDriver*)((char*)this + 0x18))->Init();
    int a = (*(int*)&DAT_004e5aac);
    int b = (*(int*)&DAT_004e5ab0);
    a++;
    (*(int*)&DAT_004e5aac) = a;
    if (a > b)
        (*(int*)&DAT_004e5ab0) = a;
}
} // namespace fn_002248f0


// 0x00224990 choreo2::JointDriver::vfunc_3 (3 B): matches/0x00224990.cpp
// sym: ?vfunc_3@JointDriver@choreo2@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool choreo2::JointDriver::vfunc_3() {
    return true;
}

namespace fn_f0e84e5f {

// 0x002249a0 choreo2::JointDriver::vfunc_7 (4 B): matches/0x002249a0.cpp
// sym: ?FUN_002249a0@fn_f0e84e5f@@YIIPAVObj_2249a0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_002249a0(Obj_2249a0* self) {
    return self->value;
}


// 0x002249b0 choreo2::JointDriver::vfunc_8 (4 B): matches/0x002249b0.cpp
// sym: ?FUN_002249b0@fn_f0e84e5f@@YIIPAVObj_2249b0@1@@Z
// Same code shape as 0x00059a30 (propagated; names are from that function)
unsigned int __fastcall FUN_002249b0(Obj_2249b0* self) {
    return self->value;
}

} // namespace fn_f0e84e5f

// 0x002249c0 choreo2::JointDriver::vfunc_9 (3 B): matches/0x002249c0.cpp
// sym: ?vfunc_9@JointDriver@choreo2@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void choreo2::JointDriver::vfunc_9(int a) {
    (void)a;
}


// 0x002249d0 choreo2::JointDriver::vfunc_10 (440 B): equivalent/0x002249d0.cpp [wrapped: conflict: JointDriver]
// sym: ?vfunc_10@JointDriver@fn_002249d0@@UAEXHPAUTransform_2249d0@2@PAUPoseSet_2249d0@2@M@Z
namespace fn_002249d0 {
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 12/12)
// choreo2::JointDriver::vfunc_10 @ 0x002249d0
struct V3_2249d0 {
    float x, y, z;
};

struct Quat_2249d0 {
    float x, y, z, w;
};

struct Transform_2249d0 {
    char pad0[0x30];
    V3_2249d0 pos;
    Quat_2249d0 *FUN_00221cd0();
    void FUN_00221cf0(const Quat_2249d0 *q);
};

struct JointPose {
    char pad0[0x30];
    V3_2249d0 pos;
    char pad3c[4];
};

struct PoseSet_2249d0 {
    char pad0[0xc];
    unsigned int count;
    Quat_2249d0 *rotations;
    JointPose *poses;
};

class JointDriver {
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
    virtual void vfunc_10(int a, Transform_2249d0 *target, PoseSet_2249d0 *set, float t);
    char pad04[0x10 - 4];
    unsigned int index;
    unsigned char flags;
    char pad15[3];
    Transform_2249d0 goal;
};

void JointDriver::vfunc_10(int a, Transform_2249d0 *target, PoseSet_2249d0 *set, float t)
{
    if (index == 0) {
        if (flags & 1) {
            V3_2249d0 p = target->pos;
            p.x = (goal.pos.x - p.x) * t + p.x;
            p.y = (goal.pos.y - p.y) * t + p.y;
            p.z = (goal.pos.z - p.z) * t + p.z;
            ((owners::Target_22be40 *)target)->FUN_0022be40((const int *)(const V3_2249d0 *)(&p));
        }
        if (flags & 2) {
            Quat_2249d0 q = *target->FUN_00221cd0();
            ((owners::Quaternion_22b750 *)&q)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_2249d0 *)(&q), (const owners::Quaternion_22b750 *)(const Quat_2249d0 *)(goal.FUN_00221cd0()), t);
            target->FUN_00221cf0(&q);
        }
    } else {
        if (index >= set->count)
            return;
        if (flags & 1) {
            JointPose *jp = &set->poses[index];
            V3_2249d0 p = jp->pos;
            float x = (goal.pos.x - p.x) * t + p.x;
            float y = (goal.pos.y - p.y) * t + p.y;
            float z = (goal.pos.z - p.z) * t + p.z;
            jp->pos.z = z;
            jp->pos.x = x;
            jp->pos.y = y;
        }
        if (flags & 2) {
            Quat_2249d0 q = set->rotations[index];
            ((owners::Quaternion_22b750 *)&q)->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_2249d0 *)(&q), (const owners::Quaternion_22b750 *)(const Quat_2249d0 *)(goal.FUN_00221cd0()), t);
            set->rotations[index] = q;
        }
    }
}
} // namespace fn_002249d0


// 0x00224b90 choreo2::JointDriver::vfunc_11 (5 B): matches/0x00224b90.cpp
// sym: ?vfunc_11@JointDriver@choreo2@@UAE_NHHHH@Z
bool choreo2::JointDriver::vfunc_11(int , int , int , int ) {
    return false;
}


// 0x00224ba0 choreo2::JointDriver::vfunc_13 (3 B): matches/0x00224ba0.cpp
// sym: ?vfunc_13@JointDriver@choreo2@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char choreo2::JointDriver::vfunc_13() {
    return 0;
}


// 0x00224bb0 choreo2::JointDriver::vfunc_2 (44 B): matches/0x00224bb0.cpp [wrapped: conflict: choreo2::JointDriver]
// sym: ?vfunc_2@JointDriver@choreo2@fn_00224bb0@@UAEPAV123@E@Z
namespace fn_00224bb0 {
// data: g_refCount = DAT_004e5aac

extern "C" char DAT_004272f0[];
typedef unsigned char byte_224bb0;
namespace choreo2 {
class JointDriver {
  public:
    virtual void a();
    virtual void b();
    virtual JointDriver* vfunc_2(byte_224bb0);
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
};
} // namespace choreo2
class JointDriver_224bb0 {
  public:
    void call();
};
extern void thunk_FUN_00267090(choreo2::JointDriver*);
choreo2::JointDriver* choreo2::JointDriver::vfunc_2(byte_224bb0 param) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004272f0);
    --(*(int*)&DAT_004e5aac);
    ((JointDriver_224bb0*)this)->call();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00224bb0


// 0x00224be0 FUN_00224be0 (85 B): matches/0x00224be0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0JointDriver@fn_00224be0@@QAE@PAUArg_224be0@1@@Z
namespace fn_00224be0 {
// data: gCount_224be0 = DAT_004e5aac

class Driver_224be0 {
  public:
    Driver_224be0();
    virtual void g();
    char b[12];
};
class Sub_224be0 {
  public:
    Sub_224be0();
    void Init(void* p);
    char pad[8];
};
struct Arg_224be0 {
    char x[16];
    int a;
    int b;
    char c[4];
};
class JointDriver : public Driver_224be0 {
  public:
    JointDriver(Arg_224be0* p);
    virtual void f();
    int m10;
    int m14;
    Sub_224be0 m18;
};
JointDriver::JointDriver(Arg_224be0* p) {
    m10 = p->a;
    m14 = p->b;
    m18.Init((char*)p + 0x18);
    int n = (*(int*)&DAT_004e5aac) + 1;
    (*(int*)&DAT_004e5aac) = n;
    if (n > (*(int*)&DAT_004e5ab0))
        (*(int*)&DAT_004e5ab0) = n;
}
void JointDriver::f() {}
} // namespace fn_00224be0


// 0x00224c60 choreo2::JointDriver::vfunc_5 (31 B): matches/0x00224c60.cpp
// sym: ?vfunc_5@JointDriver@choreo2@@UAEPAXXZ
void* choreo2::JointDriver::vfunc_5() {
    Helper_224c60* p = (Helper_224c60*)thunk_FUN_0008d690(0x70);
    if (p)
        return (void*)(p->run(this));
    return (void*)(0);
}

