// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00306450..0x00306ef0 (kind game, layer engine, confidence high), dominant class physics::CollisionVolume
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/physics_world.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fecd5d4c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fecd5d4c {} using namespace fn_fecd5d4c;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_fecd5d4c {
class Res2 {
  public:
};
class Mgr_306490 {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Res2* Get(int id);
};
// (x64t5) the volume's owner, a CollisionObject: decls/physics_world.h's words (the owner SimState is mMgr, b6b mFlag)
class Own_306490 {
  public:
    hulk_intptr vptr;
    HULK_ENTITY_WORDS
    char name[8];
    Mgr_306490* mMgr;
    int f1c;
    void* f20;
    int f24;
    struct { int f28, f2c; void* f30; char b34, b35; };
    struct { int f38; void* f3c; struct { int f40, f44; unsigned char* f48; char b4c, b4d; }; };
    char b50, b51;
    int f54, f58, f5c, f60, f64;
    char b68, b69, b6a;
    char mFlag;
};
class Sub_306490 {
  public:
    void Update_00306490();
};
class Vec_306490 {
  public:
    Sub_306490** mBegin;
    Sub_306490** mEnd;
};
class Cls_306490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float* GetPos();  // (x64t6) slot 4: the volume's position (Box_306650 / Shape_306790's slot 4; was `int`)
    virtual void v5();
    virtual int GetId();
    int pad1;   // (x64t7) NonCopyable's reference count (decls/physics_world.h HULK_COLLISION_VOLUME_WORDS)
    int m8;
    int mC;
    Own_306490* mOwn;
    Vec_306490* mVec;
    char pad3;
    char mDone;
    char pad4[2];
    char mBuf[4];
    void Run();
};
struct Vec {
    Node** first;
    Node** last;
    hulk_uintptr size() const { return (hulk_uintptr)(last - first); }   // (x64t6) was the byte difference >> 2
    Node* operator[](unsigned i) const { return first[i]; }
};
class Node {
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void action();
    char pad[HULK_CV(0x10) - sizeof(void*)];   // (x64t6) the volume's words up to the owner (decls/physics_world.h)
    void* flag;
    Vec* children;
    void run();
};
class Child_3065b0 {
  public:
    void Update_003065b0(hulk_intptr value);  // (x64t4) 0x003065b0 itself on a child: the owner pointer (was `int`)
};
class PtrRange_3065b0 {
  public:
    Child_3065b0** begin;
    Child_3065b0** end;
};
// (x64t4) the volume's words (decls/physics_world.h): the owner and the children range pointer-sized (were a pad,
// an `int` and a 32-bit offset)
class Owner_3065b0 : public HulkCollisionVolume {
  public:
    void Set(hulk_intptr v);
};
struct Vec3_306650 {
    float x, y, z;
};
class Box_306650 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3_306650 *GetPos();
    char pad4[HULK_CV(0x28) - sizeof(void*)];   // (x64t6) the volume's words up to m28 (decls/physics_world.h)
    float ex;
    float ey;
    float ez;
    char pad34[4];
    float sx;
    float sy;
    float sz;
};
struct Vec_306790 { float x,y,z; };
struct Shape_306790 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec_306790* position(); virtual void slot5(); virtual int type();
 char padding[HULK_CV(0x28) - sizeof(void*)];   // (x64t6) the volume's words up to m28
 float extentX,extentY,extentZ;
};
extern "C" bool __cdecl FUN_00306650(void *, void *, float);
struct CollisionVolume_nv_306910 {
    void helper1_00306490();
    void helper2_00306510();
};
class Item_306930 {
public:
    virtual void AddRef();
    void FUN_003065b0(void *owner);
};
struct ItemVec_306930 {
    Item_306930 **begin;
    Item_306930 **end;
    Item_306930 **cap;
};
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
class Owner_306930 {
public:
    char pad0[HULK_CV(0x10)];   // (x64t6) the volume's words up to the owner (decls/physics_world.h)
    void *context;      // 0x10
    ItemVec_306930 *items;     // 0x14
    void FUN_00306930(Item_306930 *item);
};
typedef unsigned char byte_306a90;
extern void __cdecl Ref_0008d340(void*);
extern void __cdecl Free_0008d330(void*);
struct Obj_306a90 {
    int a;
    hulk_intptr b;
    Obj_306a90* Run(byte_306a90 flags);
};
extern void* DAT_00431b74[];
extern void* DAT_003f6098[];
void FUN_0008d330(void*) throw();
void FUN_0008d340(void*) throw();
class Ref_306ac0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec_306ac0 {
    Ref_306ac0** b;
    Ref_306ac0** e;
};
class CollisionVolume_306ac0 {
  public:
    void* vptr;
    char pad[HULK_CV(0x14) - sizeof(void*)];   // (x64t6) the volume's words up to the children (decls/physics_world.h)
    Vec_306ac0* v;
    ~CollisionVolume_306ac0() throw();
};
extern char hulk_at_004312dc[];
class CollisionSphere {
  public:
    CollisionSphere();
    hulk_intptr vptr;
    int a;           // (x64t6, x64t7) the volume's words (decls/physics_world.h): NonCopyable's reference count, the
    int b;           // owner and the children pointer-sized
    int c;
    hulk_intptr d;
    hulk_intptr e;
    char flag1;
    char flag2;
    char pad[2];
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct CollisionSphere_306c60 { CollisionSphere_306c60* FUN_00306c00(); };
struct CollisionCylinder_306c60 { CollisionCylinder_306c60* FUN_00306b40(); };
struct CollisionOBB_306c60 { CollisionOBB_306c60* FUN_00306ba0(); };
struct CollisionWall_306c60 { CollisionWall_306c60* FUN_0030e700(); };
struct CollisionAABB_306c60 { CollisionAABB_306c60* FUN_00312900(); };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual unsigned int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void attach(void* copy);
 void* clone();
};
struct Triple_306e10 {
    int a, b, c;
};
class Target_306e10 {
  public:
    int x0, x1, x2, x3, x4, x5, x6, x7;
    unsigned char flag;
    int x9;
    void Set(Triple_306e10* a, Triple_306e10* b, int c, int d, unsigned char e, int f);
};
struct S_306e70 {
    unsigned int a[8];
    unsigned char b;
    unsigned char pad[3];
    unsigned int c;
};

} // namespace fn_fecd5d4c

// 0x00306450 physics::CollisionVolume::vfunc_9 (61 B): equivalent/0x00306450.cpp [wrapped: conflict: physics::CollisionVolume]
// sym: ?vfunc_9@CollisionVolume@physics@fn_00306450@@UAEXXZ @1f3093908206 @wc7fb3d4276a2
namespace fn_00306450 {
// STATUS: equivalent (tools/equiv.py level 3: 2985 inputs, branch coverage 6/6)
// physics::CollisionVolume::vfunc_9 @ 0x00306450
namespace physics { struct CollisionVolume; struct ChildList { CollisionVolume **begin; CollisionVolume **end; }; struct CollisionVolume { char pad[HULK_CV(0x14) - sizeof(void*)]; /* (x64t6) up to the children (decls/physics_world.h) */ ChildList *children; virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); }; void CollisionVolume::vfunc_9() { if (children) { for (unsigned i = 0; i < (unsigned)(children->end - children->begin); ++i) children->begin[i]->vfunc_9(); } } }
} // namespace fn_00306450

namespace fn_fecd5d4c {

// 0x00306490 FUN_00306490 (128 B): matches/0x00306490.cpp
// sym: ?Run@Cls_306490@fn_fecd5d4c@@QAEXXZ
void Cls_306490::Run() {
    if (mOwn) {
        mDone = 0;
        if (GetId() != 1 && !mOwn->mFlag) {
            int id = m8;
            Res2* r = mOwn->mMgr->Get(id);
            ((owners::Mat_22c2b0 *)r)->FUN_0022c2b0((float *)mBuf, GetPos());
        }
    } else {
        mDone = 1;
    }
    if (mVec) {
        for (unsigned i = 0; i < (unsigned)(mVec->mEnd - mVec->mBegin); i++) {
            mVec->mBegin[i]->Update_00306490();
        }
    }
}


// 0x00306510 FUN_00306510 (66 B): matches/0x00306510.cpp
// sym: ?run@Node@fn_fecd5d4c@@QAEXXZ
void Node::run() {
    if (flag)
        action();
    if (children) {
        for (unsigned i = 0; i < children->size(); ++i)
            (*children)[i]->run();
    }
}

} // namespace fn_fecd5d4c

// 0x00306560 physics::CollisionVolume::vfunc_7 (65 B): equivalent/0x00306560.cpp [wrapped: conflict: physics::CollisionVolume]
// sym: ?FUN_00306560@CollisionVolume@physics@fn_00306560@@QAEXPAX@Z @8055fba4d6ec @wea49f8ffcb6c
namespace fn_00306560 {
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 6/6)
// physics::CollisionVolume::vfunc_7 @ 0x00306560
namespace physics {
struct CollisionVolume;
struct ChildList { CollisionVolume **begin; CollisionVolume **end; };
struct CollisionVolume {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(void *value);
    char pad[HULK_CV(0x14) - sizeof(void*)];   // (x64t6) the volume's words up to the children (decls/physics_world.h)
    ChildList *children;
    void FUN_00306560(void *value);
};
void CollisionVolume::FUN_00306560(void *value) {
    if (children) {
        for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); ++i)
            children->begin[i]->vfunc_7(value);
    }
}
}
} // namespace fn_00306560

namespace fn_fecd5d4c {

// 0x003065b0 FUN_003065b0 (75 B): matches/0x003065b0.cpp
// sym: ?Set@Owner_3065b0@fn_fecd5d4c@@QAEXH@Z
void Owner_3065b0::Set(hulk_intptr v) {
    if ((hulk_intptr)owner != v) {
        owner = (void*)v;
        if (children) {
            for (unsigned int i = 0; i < (unsigned int)(((PtrRange_3065b0*)children)->end - ((PtrRange_3065b0*)children)->begin); ++i) {
                ((PtrRange_3065b0*)children)->begin[i]->Update_003065b0((hulk_intptr)owner);
            }
        }
    }
}

} // namespace fn_fecd5d4c

// 0x00306600 FUN_00306600 (69 B): matches/0x00306600.cpp [wrapped: conflict: Node]
// sym: ?Set@Node@fn_00306600@@QAEXH@Z
namespace fn_00306600 {
class Node;
struct List {
    Node** first;
    Node** last;
};
class Node {
  public:
    char pad[HULK_CV(8)];   // (x64t6) the volume's words (decls/physics_world.h): the id, then up to the children
    int value;
    char pad2[HULK_CV(0x14) - HULK_CV(0xc)];
    List* children;
    void Set(int v);
};
void Node::Set(int v) {
    value = v;
    if (children) {
        for (unsigned i = 0; i < (unsigned)(children->last - children->first); ++i)
            children->first[i]->Set(v);
    }
}
} // namespace fn_00306600

namespace fn_fecd5d4c {

// 0x00306650 FUN_00306650 (319 B): equivalent/0x00306650.cpp
// sym: _FUN_00306650 @3c86561b3d06 @w29e8587265a7
// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 18/18)
// FUN_00306650 @ 0x00306650
// equiv-conv: FUN_00306650 esi edi stack
extern "C" bool FUN_00306650(void * a_, void *b, float margin)
{
    Box_306650 * a = (Box_306650 *)a_;
    Vec3_306650 *pb = ((Box_306650 *)b)->GetPos();
    Vec3_306650 *pa = a->GetPos();
    float d = pb->y - pa->y;
    if (a->ey == (*(float*)&DAT_003f32e0)) {
        if (margin + ((Box_306650 *)b)->ey < d * a->sy)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (((Box_306650 *)b)->ey + a->ey + margin < d)
            return false;
    }

    pb = ((Box_306650 *)b)->GetPos();
    pa = a->GetPos();
    d = pb->x - pa->x;
    if (a->ex == (*(float*)&DAT_003f32e0)) {
        if (margin + ((Box_306650 *)b)->ex < d * a->sx)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (margin + ((Box_306650 *)b)->ex + a->ex < d)
            return false;
    }

    pb = ((Box_306650 *)b)->GetPos();
    pa = a->GetPos();
    d = pb->z - pa->z;
    if (a->ez == (*(float*)&DAT_003f32e0)) {
        if (margin + ((Box_306650 *)b)->ez < d * a->sz)
            return false;
    } else {
        *(unsigned *)&d &= 0x7fffffff;
        if (margin + ((Box_306650 *)b)->ez + a->ez < d)
            return false;
    }
    return true;
}


// 0x00306790 FUN_00306790 (264 B): equivalent/0x00306790.cpp
// sym: ?FUN_00306790@fn_fecd5d4c@@YA_NPAUShape_306790@1@0M@Z @b3b6578cf068 @w816897d766e3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00306790 @ 0x00306790
// equiv-conv: FUN_00306650 esi edi stack
// equiv-conv: FUN_00306790 eax ebx stack
bool FUN_00306790(Shape_306790* a, Shape_306790* b, float margin) {
 if(a->type()==8) return FUN_00306650((Shape_306790 *)a,(Shape_306790 *)b,margin);
 if(b->type()==8) return FUN_00306650((Shape_306790 *)b,(Shape_306790 *)a,margin);
 Vec_306790* pb=b->position(); Vec_306790* pa=a->position();
 union { float f; unsigned int u; } delta;
 delta.f=pb->x-pa->x; delta.u &= 0x7fffffff;
 if (a->extentX+b->extentX+margin < delta.f) return false;
 pb=b->position(); pa=a->position();
 delta.f=pb->z-pa->z; delta.u &= 0x7fffffff;
 if (a->extentZ+b->extentZ+margin < delta.f) return false;
 pb=b->position(); pa=a->position();
 delta.f=pb->y-pa->y; delta.u &= 0x7fffffff;
 return !(a->extentY+b->extentY+margin < delta.f);
}

} // namespace fn_fecd5d4c

// 0x003068a0 physics::CollisionVolume::vfunc_12 (54 B): equivalent/0x003068a0.cpp [wrapped: conflict: physics::CollisionVolume]
// sym: ?vfunc_12@CollisionVolume@physics@fn_003068a0@@UAEXPAU123@PAX@Z @847fdbab3db3 @w1b23463e1896
namespace fn_003068a0 {
// STATUS: equivalent (tools/equiv.py level 3: 14802 inputs, branch coverage 4/4)
// physics::CollisionVolume::vfunc_12 @ 0x003068a0
// physics::CollisionVolume::vfunc_12 @ 0x003068a0
namespace physics {
struct CollisionVolume {
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
    virtual void vfunc_12(CollisionVolume*, void*);
    char pad[HULK_CV(0x19) - sizeof(void*)];   // (x64t6) the volume's words up to c19 (decls/physics_world.h)
    unsigned char dirty;
};
}
// equiv-conv: FUN_00306790 eax ebx stack
void __cdecl FUN_00306790(physics::CollisionVolume*, physics::CollisionVolume*, void*);
void physics::CollisionVolume::vfunc_12(CollisionVolume* other, void* arg) {
    if (!dirty) vfunc_10();
    if (!other->dirty) other->vfunc_10();
    FUN_00306790(this, other, arg);
}
} // namespace fn_003068a0


// 0x00306910 physics::CollisionVolume::vfunc_10 (28 B): matches/0x00306910.cpp
// sym: ?vfunc_10@CollisionVolume@physics@@UAEXXZ
void physics::CollisionVolume::vfunc_10() {
    ((CollisionVolume_nv_306910*)this)->helper1_00306490();
    ((CollisionVolume_nv_306910*)this)->helper2_00306510();
    vfunc_8();
    this->f_19 = 1;
}

namespace fn_fecd5d4c {

// 0x00306930 FUN_00306930 (149 B): equivalent/0x00306930.cpp
// sym: ?FUN_00306930@Owner_306930@fn_fecd5d4c@@QAEXPAVItem_306930@2@@Z @30d61565d000 @w0463aa48f06b
// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 14/14)
// FUN_00306930 @ 0x00306930
void Owner_306930::FUN_00306930(Item_306930 *item)
{
    if (items == 0) {
        ItemVec_306930 *v = (ItemVec_306930 *)FUN_0008d690(sizeof(ItemVec_306930) + 4);   // (x64t6) 0x10: three pointers and a word
        if (v) {
            v->begin = 0;
            v->end = 0;
            v->cap = 0;
        }
        items = v;
    } else {
        for (unsigned int i = 0; i < (unsigned int)(items->end - items->begin); i++) {
            if (items->begin[i] == item)
                return;
        }
    }
    ItemVec_306930 *v = items;
    if (v->end < v->cap) {
        Item_306930 **slot = v->end;
        v->end = slot + 1;
        if (slot)
            *slot = item;
    }
    item->AddRef();
    item->FUN_003065b0(context);
}

} // namespace fn_fecd5d4c

// 0x003069d0 FUN_003069d0 (177 B): equivalent/0x003069d0.cpp [wrapped: conflict: Node]
// sym: ?FUN_003069d0@Node@fn_003069d0@@QAE_NPAU12@@Z @30e14a2065d5 @w896ae72915b6
namespace fn_003069d0 {
// STATUS: equivalent (tools/equiv.py level 3: 89 inputs, branch coverage 18/18)
// FUN_003069d0 @ 0x003069d0
struct Node;
struct Children_3069d0 { Node** begin; Node** end; };
struct Node {
 virtual void slot0();
 virtual void slot1();
 char pad[HULK_CV(0x14) - sizeof(void*)];   // (x64t6) the volume's words up to the children (decls/physics_world.h)
 Children_3069d0* children;
 bool FUN_003069d0(Node* target);
};
bool Node::FUN_003069d0(Node* target) {
 Children_3069d0* list = children;
 bool result = false;
 if (list) {
  unsigned count = (unsigned)(list->end - list->begin);
  for (unsigned i=0; i<count; ++i) {
   if (list->begin[i] == target) {
    Node** pos = list->begin+i;
    if (pos) {
     Node** end = list->end;
     for (Node** next=pos+1; next!=end; ++next) next[-1]=*next;
     --list->end;
     target->slot1();
     return true;
    }
    break;
   }
   count = (unsigned)(list->end-list->begin);
  }
  for (unsigned i=0; i<(unsigned)(list->end-list->begin); ++i) {
   result = list->begin[i]->FUN_003069d0(target);
   list = children;
  }
 }
 return result;
}
} // namespace fn_003069d0

namespace fn_fecd5d4c {

// 0x00306a90 FUN_00306a90 (43 B): matches/0x00306a90.cpp
// sym: ?Run@Obj_306a90@fn_fecd5d4c@@QAEPAU12@E@Z
Obj_306a90* Obj_306a90::Run(byte_306a90 flags) {
    hulk_intptr value = a;
    b = value;
    if (value)
        Ref_0008d340((void*)value);
    if (flags & 1)
        Free_0008d330((void*)this);
    return this;
}


// 0x00306ac0 FUN_00306ac0 (120 B): matches/0x00306ac0.cpp
// sym: ??1CollisionVolume_306ac0@fn_fecd5d4c@@QAE@XZ
CollisionVolume_306ac0::~CollisionVolume_306ac0() throw() {
    vptr = DAT_00431b74;
    if (v) {
        for (unsigned i = 0; i < (unsigned)(v->e - v->b); i++)
            v->b[i]->Release();
        v->e = v->b;
        Vec_306ac0* p = v;
        if (p) {
            p->e = p->b;
            if (p->b)
                FUN_0008d340(p->b);
            FUN_0008d330(p);
        }
    }
    vptr = DAT_003f6098;
}

} // namespace fn_fecd5d4c

// 0x00306b40 FUN_00306b40 (81 B): equivalent/0x00306b40.cpp [wrapped: conflict: physics::CollisionCylinder]
// sym: ??0CollisionCylinder@physics@fn_00306b40@@QAE@XZ @b3d5cc5274a1 @wd68932b1e035
namespace fn_00306b40 {
extern "C" char DAT_004313cc[];   // (x64t6) physics::CollisionCylinder's vftable
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00306b40 @ 0x00306b40
namespace physics {
struct Triple {
    char data[0x2c];
    void FUN_00306e70();
};
// (x64t6) the vftable stored by address (DAT_004313cc; the class's own was a stub natively) and the volume's words
// pointer-sized where decls/physics_world.h's are (the owner, the children; x64t7: NonCopyable's count is an int)
class CollisionCylinder {
public:
    void* vftable;
    unsigned int value04;
    int value08;
    int value0c;
    hulk_uintptr value10;
    hulk_uintptr value14;
    unsigned char enabled;
    unsigned char flag;
    char padding1a[2];
    unsigned int value1c;
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned int value2c;
    unsigned int value30;
    float scale;
    Triple first;
    Triple second;
    CollisionCylinder();
};
CollisionCylinder::CollisionCylinder() {
    value04 = 0;
    value10 = 0;
    value14 = 0;
    enabled = 1;
    flag = 0;
    value08 = -1;
    value0c = -1;
    value1c = 0;
    value20 = 0;
    value24 = 0;
    value28 = 0;
    value2c = 0;
    value30 = 0;
    scale = 1.0f;
    vftable = (void*)DAT_004313cc;
    first.FUN_00306e70();
    second.FUN_00306e70();
}
}
} // namespace fn_00306b40


// 0x00306ba0 FUN_00306ba0 (81 B): equivalent/0x00306ba0.cpp [wrapped: conflict: physics::CollisionOBB]
// sym: ??0CollisionOBB@physics@fn_00306ba0@@QAE@XZ @d648a0421ffd @wdf3f372793c1
namespace fn_00306ba0 {
extern "C" char DAT_004317dc[];   // (x64t6) physics::CollisionOBB's vftable
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00306ba0 @ 0x00306ba0
namespace physics {
struct Block { void FUN_0030eaa0(); char data[0x40]; };
// (x64t6) the vftable stored by address (DAT_004317dc; the class's own was a stub natively) and the volume's words
// pointer-sized where decls/physics_world.h's are (the owner, the children; x64t7: NonCopyable's count is an int)
class CollisionOBB {
public:
    void* vftable;
    int field4;
    int field8;
    int fieldC;
    hulk_intptr field10;
    hulk_intptr field14;
    unsigned char field18;
    unsigned char field19;
    char pad1A[2];
    int field1C, field20, field24, field28, field2C, field30;
    float field34;
    char pad38[4];
    Block block3C;
    Block block7C;
    CollisionOBB();
};
CollisionOBB::CollisionOBB() {
    field4 = 0;
    field10 = 0;
    field14 = 0;
    field18 = 1;
    field19 = 0;
    field8 = -1;
    fieldC = -1;
    field1C = 0;
    field20 = 0;
    field24 = 0;
    field28 = 0;
    field2C = 0;
    field30 = 0;
    field34 = 1.0f;
    vftable = (void*)DAT_004317dc;
    block3C.FUN_0030eaa0();
    block7C.FUN_0030eaa0();
}
}
} // namespace fn_00306ba0

namespace fn_fecd5d4c {

// 0x00306c00 FUN_00306c00 (61 B): matches/0x00306c00.cpp
// sym: ??0CollisionSphere@fn_fecd5d4c@@QAE@XZ
CollisionSphere::CollisionSphere() {
    a = 0;
    d = 0;
    e = 0;
    flag1 = 1;
    flag2 = 0;
    _ReadWriteBarrier();
    b = -1;
    c = b;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0x3f800000;
    vptr = (hulk_intptr)hulk_at_004312dc;
}

} // namespace fn_fecd5d4c

// 0x00306c40 physics::CollisionVolume::vfunc_2 (30 B): matches/0x00306c40.cpp
// sym: ??_GCollisionVolume@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::CollisionVolume::~CollisionVolume() {}

namespace fn_fecd5d4c {

// 0x00306c60 FUN_00306c60 (169 B): equivalent/0x00306c60.cpp
// sym: ?clone@Object@fn_fecd5d4c@@QAEPAXXZ @0a45091c4441 @wafe20abc2dbc
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 21/22, incomplete)
// FUN_00306c60 @ 0x00306c60
void* Object::clone() {
 void* result = 0;
 void* memory;
 switch (type()) {
 case 1:
  memory = FUN_0008d690(sizeof(HulkCollisionAABB));   // (x64t6) its record (decls/physics_world.h): 0x44 on 32-bit
  if (memory) result = ((CollisionAABB_306c60*)memory)->FUN_00312900();
  break;
 case 2:
  memory = FUN_0008d690(sizeof(HulkCollisionCylinder));   // (x64t6) its record (decls/physics_world.h): 0x8c on 32-bit
  if (memory) result = ((CollisionCylinder_306c60*)memory)->FUN_00306b40();
  break;
 case 5:
  memory = FUN_0008d690(sizeof(HulkCollisionOBB));   // (x64t6) its record (decls/physics_world.h): 0xbc on 32-bit
  if (memory) result = ((CollisionOBB_306c60*)memory)->FUN_00306ba0();
  break;
 case 7:
  memory = FUN_0008d690(sizeof(HulkCollisionSphere));   // (x64t6) its record (decls/physics_world.h): 0x48 on 32-bit
  if (memory) result = ((CollisionSphere_306c60*)memory)->FUN_00306c00();
  break;
 case 8:
  memory = FUN_0008d690(sizeof(HulkCollisionWall));   // (x64t5) the wall's record (0x60 on 32-bit; 4 short natively)
  if (memory) result = ((CollisionWall_306c60*)memory)->FUN_0030e700();
  break;
 }
 if (result) attach(result);
 return result;
}

} // namespace fn_fecd5d4c

// 0x00306d30 physics::CollisionVolume::vfunc_14 (208 B): equivalent/0x00306d30.cpp [wrapped: conflict: physics::CollisionVolume]
// sym: ?vfunc_14@CollisionVolume@physics@fn_00306d30@@UAEXPAU123@@Z @ba75bf38d0a5 @wda00f107bda6
namespace fn_00306d30 {
// STATUS: equivalent (tools/equiv.py level 3: 403 inputs, branch coverage 12/12)
// physics::CollisionVolume::vfunc_14 @ 0x00306d30
extern "C" void* __cdecl FUN_0008d690(unsigned int);
namespace physics { struct CollisionVolume; }
struct VolumeArray {
 physics::CollisionVolume **begin, **end, **limit;
 unsigned int extra;
 void FUN_002ede00(int count);
};
namespace physics {
struct CollisionVolume {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual void vfunc_8();
 virtual void vfunc_9();
 virtual void vfunc_10();
 virtual void vfunc_11();
 virtual void vfunc_12();
 virtual void vfunc_13();
 virtual void vfunc_14(CollisionVolume* dest);
 unsigned int field4, field8, fieldC, field10;
 VolumeArray* children;
 unsigned char flag;
 char pad19[3];
 unsigned int field1C, field20, field24, field28, field2C, field30, field34;
 CollisionVolume* FUN_00306c60();
};
void CollisionVolume::vfunc_14(CollisionVolume* dest) {
 dest->field28 = field28;
 dest->field2C = field2C;
 dest->field30 = field30;
 dest->field34 = field34;
 dest->flag = flag;
 dest->field8 = field8;
 dest->fieldC = fieldC;
 dest->field1C = field1C;
 dest->field20 = field20;
 dest->field24 = field24;
 if (children) {
  VolumeArray* a = (VolumeArray*)FUN_0008d690((int)sizeof(VolumeArray));
  if (a) { a->begin=0; a->end=0; a->limit=0; }
  dest->children=a;
  dest->children->FUN_002ede00((int)((char*)children->end-(char*)children->begin)>>2);
  unsigned int i=0;
  while (i < (unsigned int)((int)((char*)children->end-(char*)children->begin)>>2)) {
   CollisionVolume* child=children->begin[i]->FUN_00306c60();
   child->vfunc_0();
   VolumeArray* out=dest->children;
   if ((hulk_uintptr)out->end < (hulk_uintptr)out->limit) {
    CollisionVolume** place=out->end;
    out->end=place+1;
    if(place) *place=child;
   }
   ++i;
  }
 }
}
}
} // namespace fn_00306d30

namespace fn_fecd5d4c {

// 0x00306e00 FUN_00306e00 (1 B): matches/0x00306e00.cpp
// sym: ?FUN_00306e00@fn_fecd5d4c@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00306e00() {}


// 0x00306e10 FUN_00306e10 (72 B): matches/0x00306e10.cpp
// sym: ?Set@Target_306e10@fn_fecd5d4c@@QAEXPAUTriple_306e10@2@0HHEH@Z
void Target_306e10::Set(Triple_306e10* a, Triple_306e10* b, int c, int d, unsigned char e, int f) {
    x0 = a->a;
    x1 = a->b;
    x2 = a->c;
    x3 = b->a;
    x4 = b->b;
    x5 = b->c;
    x6 = c;
    x7 = d;
    flag = e;
    x9 = f;
}


// 0x00306e70 FUN_00306e70 (39 B): matches/0x00306e70.cpp
// sym: ?target@fn_fecd5d4c@@YIPAUS_306e70@1@PAU21@@Z
S_306e70* __fastcall target(S_306e70* p) {
    p->a[0] = 0;
    p->a[1] = 0;
    p->a[2] = 0;
    p->a[3] = 0;
    p->a[4] = 0x3f800000;
    p->a[5] = 0;
    p->a[6] = 0x3f800000;
    p->a[7] = 0x3f800000;
    p->b = 0;
    p->c = 0;
    return p;
}

} // namespace fn_fecd5d4c
