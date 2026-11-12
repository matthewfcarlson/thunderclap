// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fd360..0x002fdf40 (kind game, layer engine, confidence high), dominant class physics::SimStateArticulated
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f0657c79 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f0657c79 {} using namespace fn_f0657c79;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f0657c79 {
struct Mat_2fd400 {
    int v[16];
    void Op_0022b980();
};
struct Inner_2fd400 {
    char pad[0x19];
    char flag;
};
struct A88 {
    void F1_0030f650();
    void F2_0030f4c0();
};
struct B74 {
    char pad[0x20];
    Inner_2fd400* inner;
    char pad2[0x68 - 0x24];
    char f68;
    char f69;
    void FnG_00305030();
};
struct C70 {
};
class Obj_2fd400 {
  public:
    char pad0[0x10];
    Mat_2fd400 m;
    char pad1[0x70 - 0x50];
    C70* p70;
    B74* p74;
    char pad2[0x84 - 0x78];
    char f84;
    char pad3[3];
    A88* p88;
    char pad4[0x94 - 0x8c];
    char f94;
    void Fn();
};
struct Args {
    int x;
    int y;
};
class Handler {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void Run(int, int);
};
class First {
  public:
    void Run_00310460(int, int);
};
class Obj {
    char pad[0x70];
    First* a;
    Handler* b;

  public:
    void Run(Args v);
};
struct Thing_2fd4f0 {
    char pad[0x70];
    void* a;
    void* b;
};
extern void __fastcall cleanup_00311050(void*);
extern void __fastcall next_003062a0(void*);
struct Joint_2fd520 {
    char pad0[4];
    int f4, f8, fc, f10, f14, f18;
    unsigned char f1c;
    char pad1d[0x64 - 0x1d];
};
struct Chain_2fd520 {
    char pad0[8];
};
struct H2_2fd5a0;
struct H3_2fd5a0;
struct H1 {
    H2_2fd5a0* first_0030f490(int);
};
struct H2_2fd5a0 {
    H3_2fd5a0* second_0030edf0();
};
struct H3_2fd5a0 {
    struct SimStateArticulated* third_0030f100();
};
struct SimState {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
struct SimStateArticulated : SimState {
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
    virtual void o();
    char pad[0x84];
    H1* member;
    SimStateArticulated* vfunc_4(int);
};
struct Obj1_2fd5e0 {
    void* f490_0030f490(int);
};
struct Obj2_2fd5e0 {
    void* edf_0030edf0();
};
struct Obj3_2fd5e0 {
    void* f100_0030f100();
};
struct Inner_2fd620 {
    char pad[0x1fc];
    int* items;
};
struct Block_2fd690 {
    unsigned int v[16];
};
extern "C" void * __fastcall FUN_0030edf0(void *);
void* __fastcall FnB_0030f100(void* p);
struct Target_2fd690 {
    unsigned int first;
    char pad[28];
    Block_2fd690 data;
    void Init(unsigned int arg);
};
struct Temp {
    unsigned int FUN_0030f100();
};
void __cdecl FUN_002ef760(void* output, unsigned int result, float scale, unsigned int value, void* data);
extern "C" char DAT_004318f4[];
struct Base_2fd840 {
    virtual void a();
    virtual void b();
};
class Obj_2fd840 {
  public:
    void cleanup_00312240(int);
};
class SimStateArticulated_2fd840 {
  public:
    void* vptr;
    char p1[0x6c];
    Obj_2fd840* m70;
    char p2[0x14];
    Base_2fd840* m88;
    void* m8c;
    void tail_002ef2c0();
    void run();
};
struct Matrix_2fd8a0 { unsigned int words[16]; };
struct Transform_2fd8a0 { Matrix_2fd8a0* FUN_0030f100(); };
struct Item_2fd8a0 { Transform_2fd8a0* FUN_0030edf0(); };
struct Resource_2fd8a0 { virtual void AddRef() = 0; virtual void Release() = 0;  Item_2fd8a0* FUN_0030f490(int index); };
struct Child_2fd8a0 { char padding[0x24]; int state; void FUN_00312240(Resource_2fd8a0* resource); };
struct Entry_2fd8a0 { Item_2fd8a0* item; char padding[0x1c]; Matrix_2fd8a0 matrix; char tail[4]; };
struct CountSource {  };
struct Matrix { unsigned int words[16]; };
struct Transform_2fd950 { Matrix* FUN_0030f100(); };
struct Node { Transform_2fd950* FUN_0030edf0(); };
struct Entry_2fd950 {
 Node* node;
 unsigned int first[3];
 unsigned int second[3];
 unsigned char reset;
 char padding[3];
 Matrix matrix;
 float value;
};
struct Owner_2fd950 {
 char padding[0x88];
 CountSource* source;
 Entry_2fd950* entries;
 void FUN_002fd950(float value);
};
struct Vec3_2fda20 { float x, y, z; };
struct Body_2fda20 {
    char pad0[0x30];
    Vec3_2fda20 pos;
};
struct Source_2fda20 {
    Body_2fda20 *FUN_0030f100();
};
struct Source2 {
    Source_2fda20 *FUN_0030edf0();
};
struct Link_2fda20 {
    char pad0[0x19];
    unsigned char active;
};
struct Follower_2fda20 {
    char pad0[0x20];
    Link_2fda20 *link;
    char pad24[0x68 - 0x24];
    unsigned char done;
    unsigned char done2;
    void FUN_002ef200(Vec3_2fda20 *d);
};
struct Slot_2fda20 {
    Source2 *src;
    Vec3_2fda20 dir;
    char pad10[0x1c - 0x10];
    unsigned char started;
    char pad1d[3];
    char sub[0x50 - 0x20];
    Vec3_2fda20 pos;
    int f5c;
    int f60;
    char pad64[0x64 - 0x64];
};
extern "C" void FUN_002ef760(void *sub, Body_2fda20 *b, float one, int v, Vec3_2fda20 *dir);
struct Tracker_2fda20 {
    char pad0[0x74];
    Follower_2fda20 *follower;
    char pad78[0x80 - 0x78];
    float range;
    unsigned char enabled;
    char pad85[0x8c - 0x85];
    Slot_2fda20 *slots;
    int index;
    void Update();
};
class B_2fdd80 {
  public:
    void FnH_003111f0();
};
class A_2fdd80 {
    char pad[0x70];
    B_2fdd80* p;

  public:
    void F(int);
    void FnO_002fda20();
};
struct Pose_2fddf0 {
    int words[21];
};
struct InnerCtl {
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
    char pad04[0x15];
    unsigned char flag19;
};
struct Binding_2fddf0 {
    char pad0[0x18];
    int handle;
};
struct Item_2fddf0 {
    char pad0[0x20];
    InnerCtl *ctl;
    char pad24[0x50 - 0x24];
    unsigned char locked;
    char pad51[0x68 - 0x51];
    unsigned char dirtyA;
    unsigned char dirtyB;
};
struct Flagged_2fddf0 {
    char pad0[0x94];
    unsigned char flag;
};
class Sink_2fddf0 {
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
    virtual void vfunc_13(Binding_2fddf0 *b);
    virtual void vfunc_14(Item_2fddf0 *item);
    char pad04[0x90];
    unsigned char flag94;
};
class Source_2fddf0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual Item_2fddf0 *vfunc_5(Sink_2fddf0 *sink);
    char pad04[0x14];
    Flagged_2fddf0 *flagged;
};
class Provider_2fddf0 {
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
    virtual Binding_2fddf0 *vfunc_28(Sink_2fddf0 *sink);
    char pad04[0xc];
    Flagged_2fddf0 *flagged;
    char pad14[0x24 - 0x14];
    int kind;
    char pad28[0x220 - 0x28];
    int extra;

    void FUN_00310e90(void *handler);
};
struct PoseItem {
    Pose_2fddf0 *FUN_0030ef30();
    void FUN_0030ee40(Pose_2fddf0 *pose);
};
struct Chain_2fddf0 {
    char pad0[8];
    void *owner;
    void FUN_0030f4c0();
    PoseItem *FUN_0030f490(int index);
};
struct SkeletonInfo_nv_2fddf0 {
    physics::SkeletonInfo *FUN_00312440(void *owner);
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_00263ea0(unsigned int size);
struct SimStateArticulated_nv_2fddf0 {
    Sink_2fddf0 *FUN_002fdc90(Chain_2fddf0 *chain, int arg);
};

} // namespace fn_f0657c79

// 0x002fd360 physics::SimStateArticulated::vfunc_14 (129 B): equivalent/0x002fd360.cpp [wrapped: conflict: physics::SimState; physics::SimStateArticulated]
// sym: ?vfunc_14@SimStateArticulated@physics@fn_002fd360@@QAEXH@Z @56fb937f8482 @w7d5f27bd780e
namespace fn_002fd360 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// physics::SimStateArticulated::vfunc_14 @ 0x002fd360
// 0x002fd360: SimStateArticulated::vfunc_14: re-arm the articulation and remember the first active joint
namespace physics {

struct Joints {
    void vfunc0();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Reset();
    int FUN_00306190(int index, int mode);
};

struct Body_2fd360 {
    char pad00[0x20];
    Joints* joints;
    int count;
    char pad28[0x28];
    char enabled;
    void FUN_003046f0(int enable);
};

class SimState {
public:
    virtual void v0();
    void vfunc_14_002ef3f0(int arg);
};

class SimStateArticulated : public SimState {
public:
    char pad04[0x70];
    Body_2fd360* body;
    char pad78[0x18];
    int activeJoint;
    void vfunc_14(int arg);
};

void SimStateArticulated::vfunc_14(int arg)
{
    SimState::vfunc_14_002ef3f0(arg);

    Body_2fd360* b = body;
    if (b->enabled) {
        b->FUN_003046f0(0);
        body->joints->Reset();
        body->FUN_003046f0(1);
    } else {
        b->joints->Reset();
    }

    b = body;
    activeJoint = 0;
    int n = b->count;
    for (int i = 0; i < n; ) {
        if (body->joints->FUN_00306190(i, 1) != 0) {
            activeJoint = i;
            break;
        }
        i++;
        n = body->count;
    }
}

}
} // namespace fn_002fd360

// 0x002fd3f0 physics::SimStateArticulated::vfunc_6 (5 B): not yet verified
namespace fn_f0657c79 {

// 0x002fd400 FUN_002fd400 (145 B): matches/0x002fd400.cpp
// sym: ?Fn@Obj_2fd400@fn_f0657c79@@QAEXXZ
void Obj_2fd400::Fn() {
    if (f94)
        return;
    Mat_2fd400 saved = m;
    m.Op_0022b980();
    if (p88) {
        p88->F1_0030f650();
        p88->F2_0030f4c0();
    }
    if (p74) {
        p74->FnG_00305030();
        B74* b = p74;
        b->inner->flag = 0;
        b->f68 = 1;
        b->f69 = 1;
    }
    if (p70)
        ((owners::C_311060 *)p70)->FUN_00311060();
    m = saved;
    f94 = 1;
    f84 = 0;
}

} // namespace fn_f0657c79

// 0x002fd4a0 FUN_002fd4a0 (16 B): matches/0x002fd4a0.cpp
// sym: ?FUN_002fd4a0@C_2fd4a0@owners@@QAEXXZ
void owners::C_2fd4a0::FUN_002fd4a0() {
    int* p = this->p;
    if (p) {
        p[0x44 / 4] = 0;
        p[0x40 / 4] = 0;
    }
}

namespace fn_f0657c79 {

// 0x002fd4b0 FUN_002fd4b0 (49 B): matches/0x002fd4b0.cpp
// sym: ?Run@Obj@fn_f0657c79@@QAEXUArgs@2@@Z
void Obj::Run(Args v) {
    if (a)
        a->Run_00310460(v.x, v.y);
    if (b)
        b->Run(v.x, v.y);
}


// 0x002fd4f0 FUN_002fd4f0 (33 B): matches/0x002fd4f0.cpp
// sym: ?target@fn_f0657c79@@YIXPAUThing_2fd4f0@1@@Z
void __fastcall target(Thing_2fd4f0* self) {
    if (self->a)
        cleanup_00311050(self->a);
    if (self->b)
        next_003062a0(*(void**)((char*)self->b + 0x20));
}

} // namespace fn_f0657c79

// 0x002fd520 physics::SimStateArticulated::vfunc_7 (118 B): equivalent/0x002fd520.cpp
// sym: ?vfunc_7@SimStateArticulated@physics@@UAEXXZ @6bb72b0aabac @w11e1ef0a0247
// STATUS: equivalent (tools/equiv.py level 3: 2977 inputs, branch coverage 6/6)
// physics::SimStateArticulated::vfunc_7 @ 0x002fd520
void physics::SimStateArticulated::vfunc_7() {
    this->f_58 = 0;
    this->f_54 = 0;
    (*(int *)&this->f_50) = 0;
    this->f_64 = 0;
    this->f_60 = 0;
    this->f_5c = 0;
    this->f_80 = 0;
    if ((*(Chain_2fd520 * *)&this->f_88) != 0) {
        for (int i = 0; i < ((owners::C_30f450 *)((*(Chain_2fd520 * *)&this->f_88)))->FUN_0030f450(); i++) {
            Joint_2fd520 *j = &(*(Joint_2fd520 * *)&this->f_8c)[i];
            j->f1c = 1;
            j->fc = 0;
            j->f8 = 0;
            j->f4 = 0;
            j->f18 = 0;
            j->f14 = 0;
            j->f10 = 0;
        }
    }
}

namespace fn_f0657c79 {

// 0x002fd5a0 physics::SimStateArticulated::vfunc_4 (49 B): matches/0x002fd5a0.cpp
// sym: ?vfunc_4@SimStateArticulated@fn_f0657c79@@QAEPAU12@H@Z
SimStateArticulated* SimStateArticulated::vfunc_4(int p) {
    if (p >= 0 && member)
        return member->first_0030f490(p)->second_0030edf0()->third_0030f100();
    return (SimStateArticulated*)((char*)this + 0x10);
}

} // namespace fn_f0657c79

// 0x002fd5e0 physics::SimStateArticulated::vfunc_5 (52 B): matches/0x002fd5e0.cpp
// sym: ?vfunc_5@SimStateArticulated@physics@@UAEPAXH@Z
void* physics::SimStateArticulated::vfunc_5(int x) {
    if (x >= 0 && (*(void * *)&this->f_88)) {
        Obj1_2fd5e0* a = (Obj1_2fd5e0*)(*(void * *)&this->f_88);
        Obj2_2fd5e0* b = (Obj2_2fd5e0*)a->f490_0030f490(x);
        Obj3_2fd5e0* c = (Obj3_2fd5e0*)b->edf_0030edf0();
        return (void*)((char*)c->f100_0030f100() + 0x30);
    }
    return (void*)((char*)this + 0x40);
}


// 0x002fd620 physics::SimStateArticulated::vfunc_9 (32 B): matches/0x002fd620.cpp
// sym: ?vfunc_9@SimStateArticulated@physics@@UAEII@Z
unsigned int physics::SimStateArticulated::vfunc_9(unsigned int __p0) { int index = (int)__p0;

    Inner_2fd620* p = (*(Inner_2fd620 * *)&this->f_70);
    if (index > 0 && p != 0 && p->items[index] == 0)
        p = 0;
    return (unsigned int)((hulk_intptr)p);
}


// 0x002fd640 physics::SimStateArticulated::vfunc_10 (3 B): matches/0x002fd640.cpp
// sym: ?vfunc_10@SimStateArticulated@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::SimStateArticulated::vfunc_10(int a) {
    (void)a;
}

namespace fn_f0657c79 {

// 0x002fd690 FUN_002fd690 (39 B): matches/0x002fd690.cpp
// sym: ?Init@Target_2fd690@fn_f0657c79@@QAEXI@Z
void Target_2fd690::Init(unsigned int arg) {
    first = arg;
    void* p = FnB_0030f100(FUN_0030edf0((void *)(hulk_uintptr)(unsigned int)arg));
    data = *(Block_2fd690*)p;
}

} // namespace fn_f0657c79

// 0x002fd730 FUN_002fd730 (56 B): matches/0x002fd730.cpp
// sym: ?FUN_002fd730@Obj_2fd730@owners@@QAEXXZ
void owners::Obj_2fd730::FUN_002fd730() {
    if (!flag) {
        flag = 1;
        FUN_002ef760(output, ((Temp *)FUN_0030edf0(context))->FUN_0030f100(), 1.0f, value, data);
    }
}

namespace fn_f0657c79 {

// 0x002fd840 FUN_002fd840 (78 B): matches/0x002fd840.cpp
// sym: ?run@SimStateArticulated_2fd840@fn_f0657c79@@QAEXXZ
void SimStateArticulated_2fd840::run() {
    vptr = (void*)((hulk_intptr)DAT_004318f4);
    if (m8c)
        release((char*)m8c - 4);
    if (m70)
        m70->cleanup_00312240(0);
    if (m88) {
        m88->b();
        m88 = 0;
    }
    tail_002ef2c0();
}

} // namespace fn_f0657c79

// 0x002fd890 physics::SimStateArticulated::vfunc_11 (3 B): matches/0x002fd890.cpp
// sym: ?vfunc_11@SimStateArticulated@physics@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool physics::SimStateArticulated::vfunc_11() {
    return (bool)(0);
}


// 0x002fd8a0 FUN_002fd8a0 (174 B): equivalent/0x002fd8a0.cpp
// sym: ?FUN_002fd8a0@SimStateArticulated@physics@@QAEXPAX@Z @7fb514757079 @w0f1e7ae325ae
// STATUS: equivalent (tools/equiv.py level 3: 2970 inputs, branch coverage 14/14)
// FUN_002fd8a0 @ 0x002fd8a0
void physics::SimStateArticulated::FUN_002fd8a0(void* __p0) { Resource_2fd8a0 * incoming = (Resource_2fd8a0 *)__p0;

 if (incoming) incoming->AddRef();
 if ((*(Resource_2fd8a0 * *)&this->f_88)) (*(Resource_2fd8a0 * *)&this->f_88)->Release();
 (*(Resource_2fd8a0 * *)&this->f_88) = incoming;
 if (incoming) {
  if (((owners::C_30f450 *)incoming)->FUN_0030f450() > 0) {
   int index = 0;
   do {
    Item_2fd8a0* item = (*(Resource_2fd8a0 * *)&this->f_88)->FUN_0030f490(index);
    Entry_2fd8a0* entry = &(*(Entry_2fd8a0 * *)&this->f_8c)[index];
    entry->item = item;
    Transform_2fd8a0* transform = item->FUN_0030edf0();
    Matrix_2fd8a0* matrix = transform->FUN_0030f100();
    for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
    ++index;
   } while (index < ((owners::C_30f450 *)((*(Resource_2fd8a0 * *)&this->f_88)))->FUN_0030f450());
  }
  Child_2fd8a0* current = (*(Child_2fd8a0 * *)&this->f_70);
  if (current && current->state == 1) current->FUN_00312240(incoming);
 }
}

namespace fn_f0657c79 {

// 0x002fd950 FUN_002fd950 (195 B): equivalent/0x002fd950.cpp
// sym: ?FUN_002fd950@Owner_2fd950@fn_f0657c79@@QAEXM@Z @321120e665aa @w3b291f3bd6af
// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 8/8)
// FUN_002fd950 @ 0x002fd950
void Owner_2fd950::FUN_002fd950(float value) {
 if (!source) return;
 int index = 0;
 if (((owners::C_30f450 *)source)->FUN_0030f450() <= 0) return;
 do {
  Entry_2fd950* entry = entries + index;
  if (value == 0.0f) {
   entry->first[2] = 0;
   entry->first[1] = 0;
   entry->first[0] = 0;
   entry->second[2] = 0;
   entry->second[1] = 0;
   entry->second[0] = 0;
   entry->reset = 1;
  } else {
   entry->value = value;
   Transform_2fd950* transform = entry->node->FUN_0030edf0();
   Matrix* matrix = transform->FUN_0030f100();
   for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
   entry->reset = 0;
  }
  ++index;
 } while (index < ((owners::C_30f450 *)source)->FUN_0030f450());
}


// 0x002fda20 FUN_002fda20 (421 B): equivalent/0x002fda20.cpp
// sym: ?Update@Tracker_2fda20@fn_f0657c79@@QAEXXZ @aef9166af522 @w5aaf6fa7d3a6
// STATUS: equivalent (tools/equiv.py level 3: 19895 inputs, branch coverage 16/16)
// FUN_002fda20 @ 0x002fda20
void Tracker_2fda20::Update()
{
    if (follower != 0 && !follower->done) {
        Slot_2fda20 *s = &slots[index];
        Body_2fda20 *b = s->src->FUN_0030edf0()->FUN_0030f100();
        Slot_2fda20 *s2 = &slots[index];
        Vec3_2fda20 d;
        d.x = b->pos.x - s2->pos.x;
        d.y = b->pos.y - s2->pos.y;
        d.z = b->pos.z - s2->pos.z;
        if (d.z * d.z + d.y * d.y + d.x * d.x > 0.0f) {
            follower->FUN_002ef200(&d);
        } else {
            Link_2fda20 *l = follower->link;
            follower->done = 1;
            l->active = 0;
        }
    }
    if (enabled) {
        Slot_2fda20 *s = &slots[index];
        if (!s->started) {
            s->started = 1;
            FUN_002ef760(s->sub, s->src->FUN_0030edf0()->FUN_0030f100(), 1.0f, s->f60, &s->dir);
        }
        Vec3_2fda20 *v = &slots[index].dir;
        hulk_freg lenSq = v->x * v->x + v->y * v->y + v->z * v->z;
        float h = DAT_004d2960 * range;
        if (lenSq > h * h) {
            range = (float)sqrt(lenSq);
            Follower_2fda20 *f = follower;
            if (f != 0) {
                f->link->active = 0;
                f->done = 1;
                f->done2 = 1;
            }
        } else if (lenSq < range / DAT_004d2960) {
            range = (float)sqrt(lenSq);
        }
    }
}

} // namespace fn_f0657c79

// 0x002fdbd0 FUN_002fdbd0 (190 B): equivalent/0x002fdbd0.cpp [wrapped: conflict: Matrix]
// sym: ?FUN_002fdbd0@Object@fn_002fdbd0@@QAEXPAUVec_2fdbd0@2@0@Z @aaf3f397f464 @wae803c1ba988
namespace fn_002fdbd0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_002fdbd0 @ 0x002fdbd0
struct Vec_2fdbd0 { float x,y,z; };
struct Matrix { char pad[0x30]; Vec_2fdbd0 position; };
struct Node { Matrix* FUN_0030f100(); };
struct Owner_2fdbd0 { Node* FUN_0030edf0(); };
void __cdecl FUN_002ef760(Matrix*, Matrix*, float, void*, Vec_2fdbd0*);
struct Object {
 Owner_2fdbd0* owner;
 Vec_2fdbd0 base;
 Vec_2fdbd0 axis;
 unsigned char initialized;
 char pad[3];
 Matrix cached;
 char pad2[4];
 void* context;
 void FUN_002fdbd0(Vec_2fdbd0* input, Vec_2fdbd0* output);
};
void Object::FUN_002fdbd0(Vec_2fdbd0* input, Vec_2fdbd0* output) {
 if (!initialized) {
  void* c = context;
  initialized = 1;
  Matrix* m = owner->FUN_0030edf0()->FUN_0030f100();
  FUN_002ef760(&cached, m, 1.0f, c, &base);
 }
 Matrix* m = owner->FUN_0030edf0()->FUN_0030f100();
 double dx = (double)input->x - m->position.x;
 double dy = (double)input->y - m->position.y;
 double dz = (double)input->z - m->position.z;
 float y = (float)(dx * axis.z - dz * axis.x);
// z is spilled (rounded) and reloaded in the original
 volatile float z = (float)(dy * axis.x - dx * axis.y);
 double x = dz * axis.y - dy * axis.z;
 output->y = y;
 output->z = z;
 output->x = (float)x;
 output->x = *(volatile float*)&output->x + base.x; // reloaded from the destination in the original
 output->y = y + base.y;
 output->z = z + base.z;
}
} // namespace fn_002fdbd0


// 0x002fdc90 FUN_002fdc90 (198 B): equivalent/0x002fdc90.cpp [wrapped: conflict: physics::SimStateArticulated]
// sym: ??0SimStateArticulated@physics@fn_002fdc90@@QAE@PAUSource_2fdc90@2@H@Z @909bec620553 @we880da19999b
namespace fn_002fdc90 {
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 6/6)
// FUN_002fdc90 @ 0x002fdc90
struct Source_2fdc90 { int FUN_0030f450(); };
struct Transform_2fdc90 { void FUN_0022b980(); char data[64]; };
struct Entry_2fdc90 { int a,b,c,d,e,f,g; unsigned char enabled; char pad[3]; Transform_2fdc90 transform; int last; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int bytes);
struct FUN_002ef7f0 {
 FUN_002ef7f0(int mode);   // (x64t7) SimState's constructor (0x002ef7f0) takes the mode word at 0x6c, an int (was a pointer)
 virtual void slot0();
 char base[128];
};
namespace physics {
struct SimStateArticulated : FUN_002ef7f0 {
 virtual void slot0();
 unsigned char enabled;
 char pad85[3];
 int field88;
 Entry_2fdc90* entries;
 int field90;
 unsigned char field94;
 void FUN_002fd8a0(Source_2fdc90* source);
 SimStateArticulated(Source_2fdc90* source, int mode);
};
}
physics::SimStateArticulated::SimStateArticulated(Source_2fdc90* source, int mode) : FUN_002ef7f0(mode) {
 field88=0; field90=0; field94=0; enabled=1;
 int count=source->FUN_0030f450();
 int* allocation=(int*)FUN_0008d6d0((unsigned int)count*100+4);
 Entry_2fdc90* result=0;
 if(allocation) {
  *allocation=count;
  result=(Entry_2fdc90*)(allocation+1);
  if(count>0) for(int i=0;i<count;++i) {
   Entry_2fdc90& item=result[i];
   item.a=0; item.b=0; item.c=0; item.d=0; item.e=0; item.f=0; item.g=0;
   item.last=0; item.enabled=1;
   item.transform.FUN_0022b980();
  }
 }
 entries=result;
 FUN_002fd8a0(source);
}
} // namespace fn_002fdc90


// 0x002fdd60 physics::SimStateArticulated::vfunc_2 (30 B): matches/0x002fdd60.cpp
// sym: ??_GSimStateArticulated@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::SimStateArticulated::~SimStateArticulated() {}

namespace fn_f0657c79 {

// 0x002fdd80 FUN_002fdd80 (26 B): matches/0x002fdd80.cpp
// sym: ?F@A_2fdd80@fn_f0657c79@@QAEXH@Z
void A_2fdd80::F(int x) {
    if (p)
        p->FnH_003111f0();
    FnO_002fda20();
}

} // namespace fn_f0657c79

// 0x002fdda0 physics::SimStateArticulated::vfunc_8 (52 B): matches/0x002fdda0.cpp [wrapped: conflict: physics::SimState; physics::SimStateArticulated]
// sym: ?vfunc_8@SimStateArticulated@physics@fn_002fdda0@@UAEXHHH@Z
namespace fn_002fdda0 {
namespace physics {
class SimState {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void vfunc_8(int, int, int);
    char pad[0x88];
};
struct Part_2fdda0 {
    char data[0x64];
    void call_002fdbd0(int, int);
};
class SimStateArticulated : public SimState {
  public:
    Part_2fdda0* parts;
    void vfunc_8(int a, int b, int index);
};
void SimStateArticulated::vfunc_8(int a, int b, int index) {
    if (index >= 0)
        parts[index].call_002fdbd0(a, b);
    else
        SimState::vfunc_8(a, b, -1);
}
} // namespace physics
} // namespace fn_002fdda0

namespace fn_f0657c79 {

// 0x002fddf0 FUN_002fddf0 (331 B): equivalent/0x002fddf0.cpp
// sym: _FUN_002fddf0 @62133270368b @waf3f2bd1909a
// STATUS: equivalent (tools/equiv.py level 3: 19978 inputs, branch coverage 29/30, incomplete)
// FUN_002fddf0 @ 0x002fddf0
extern "C" Sink_2fddf0 *__cdecl FUN_002fddf0(Chain_2fddf0 *chain, Source_2fddf0 *source, Provider_2fddf0 *provider)
{
    chain->FUN_0030f4c0();
    Pose_2fddf0 *pose = chain->FUN_0030f490(0)->FUN_0030ef30();
    chain->FUN_0030f490(0)->FUN_0030ee40(pose);

    physics::SimStateArticulated *mem = (physics::SimStateArticulated *)FUN_0008d690((int)sizeof(physics::SimStateArticulated));
    if (mem == 0)
        return 0;
    Sink_2fddf0 *sink = ((SimStateArticulated_nv_2fddf0*)(((physics::SimStateArticulated*)(mem))))->FUN_002fdc90(chain, 0);
    if (sink == 0)
        return 0;

    Binding_2fddf0 *binding = 0;
    if (provider != 0) {
        if (provider->kind == 1 && provider->extra == 0) {
            physics::SkeletonInfo *h = (physics::SkeletonInfo *)FUN_00263ea0(0x18);
            if (h != 0)
                h = ((SkeletonInfo_nv_2fddf0*)(((physics::SkeletonInfo*)(h))))->FUN_00312440(chain->owner);
            provider->FUN_00310e90(h);
        }
        if (provider->flagged != 0) {
            if (provider->flagged->flag != 0)
                sink->flag94 = 1;
            binding = provider->vfunc_28(sink);
        } else {
            binding = provider->vfunc_28(sink);
        }
        sink->vfunc_13(binding);
    }

    if (source != 0) {
        Item_2fddf0 *item;
        if (source->flagged != 0) {
            if (source->flagged->flag != 0)
                sink->flag94 = 1;
            item = source->vfunc_5(sink);
        } else {
            item = source->vfunc_5(sink);
        }
        sink->vfunc_14(item);
        if (item->dirtyA != 0 || item->dirtyB != 0)
            item->ctl->vfunc_10();
        item->ctl->vfunc_8();
        if (item->locked == 0) {
            item->ctl->flag19 = 0;
            item->dirtyA = 1;
            item->dirtyB = 1;
        }
        if (binding != 0)
            ((owners::C_304740 *)item)->FUN_00304740((hulk_intptr)(binding->handle));
    }
    return sink;
}

} // namespace fn_f0657c79
