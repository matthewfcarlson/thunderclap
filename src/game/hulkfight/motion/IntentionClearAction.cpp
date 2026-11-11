// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b0c0..0x0017b330 (kind game, layer game, confidence medium), dominant class hulkfight::motion::IntentionClearAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fbf77592 {
#define TREE_TU_END }
namespace fn_fbf77592 {} using namespace fn_fbf77592;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fbf77592 {
extern int ParamsRTTI;
extern int CFightParamsRTTI;
extern int TypeCheck(void*, int, int*, int*, int);
extern "C" void* FUN_0008d690(int);
class Obj_17b0c0 {
  public:
    int Init(hulkfight::motion::JointTrackerTrack*, void*);
};
extern "C" char DAT_00417df0[];
class Ref_17b110 {
  public:
    virtual void f0();
    virtual void f1();
};
class IntentionClearAction_17b110 {
  public:
};
class JointTrackerAction;
void delthis(JointTrackerAction*);
class JointTrackerAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual JointTrackerAction* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x18];
    int m1c;
    Ref_17b110* m20;
    Ref_17b110* m24;
    char pad28[0x4c];
    Ref_17b110* m74;
};
typedef unsigned int u32_17b170;
extern int desc1_17b170;
extern int desc2_17b170;
int __cdecl check(void* obj, int z, void* d1, void* d2, int z2);
struct Result_17b170 {
    int init(void* self, void* p);
};
struct Track_17b170 {
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
    virtual int v10(u32_17b170, u32_17b170, void*);
};
typedef unsigned int u32_17b1e0;
struct Result_17b1e0 {
    int Init(hulkfight::motion::JointRelativeTrack*, u32_17b1e0);
};
extern int __cdecl Check5(u32_17b1e0, int, void*, void*, int);
extern char g_a_17b1e0;
extern char g_b_17b1e0;
extern int g_vftable_17b230;
class RefObj_17b230 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class JointRelativeAction_17b230 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_17b230* m2;
    RefObj_17b230* m3;
    void* vfunc_2(unsigned char flag);
};
class Params_17b290 {
  public:
    int x;
};
extern Params_17b290 TypeA_17b290;
extern Params_17b290 TypeB_17b290;
int __cdecl Check(void*, int, Params_17b290*, Params_17b290*, int);
struct IntentionClearAction_nv_17b290 {
    int Init(hulkfight::motion::IntentionClearTrack*, hulk_intptr);
};
hulkfight::motion::IntentionClearAction* __cdecl Alloc(int);
struct RefCounted_17b2e0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b2e0[];
class IntentionClearAction_17b2e0 {
  public:
    IntentionClearAction_17b2e0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b2e0* m_20;
};

} // namespace fn_fbf77592

// 0x0017b0c0 hulkfight::motion::JointTrackerTrack::vfunc_10 (70 B): matches/0x0017b0c0.cpp
// sym: ?vfunc_10@JointTrackerTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::JointTrackerTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { void * p = (void *)__p2;

    if (TypeCheck(p, 0, &ParamsRTTI, &CFightParamsRTTI, 0)) {
        void* q = FUN_0008d690(0x78);
        if (q)
            return ((Obj_17b0c0*)q)->Init(this, p);
    }
    return 0;
}

namespace fn_fbf77592 {

// 0x0017b110 hulkfight::motion::JointTrackerAction::vfunc_2 (95 B): matches/0x0017b110.cpp
// sym: ?vfunc_2@JointTrackerAction@fn_fbf77592@@UAEPAV12@H@Z
JointTrackerAction* JointTrackerAction::vfunc_2(int flag) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_00417df0);
    Ref_17b110* volatile* p = &m74;
    Ref_17b110* a = *p;
    if (a) {
        a->f1();
        m74 = 0;
    }
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(((IntentionClearAction_17b110*)this)))->FUN_002326a0();
    if (flag & 1)
        delthis(this);
    return this;
}

} // namespace fn_fbf77592

// 0x0017b170 hulkfight::motion::JointPivotTrackerTrack::vfunc_10 (73 B): matches/0x0017b170.cpp
// sym: ?vfunc_10@JointPivotTrackerTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::JointPivotTrackerTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b170 a = (u32_17b170)__p0; u32_17b170 b = (u32_17b170)__p1; void * c = (void *)__p2;

    if (check(c, 0, &desc1_17b170, &desc2_17b170, 0)) {
        Result_17b170* p = (Result_17b170*)FUN_0008d690(0x84);
        if (p)
            return p->init(this, c);
    }
    return 0;
}


// 0x0017b1c0 hulkfight::motion::JointPivotTrackerAction::vfunc_2 (30 B): matches/0x0017b1c0.cpp
// sym: ??_GJointPivotTrackerAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::JointPivotTrackerAction::~JointPivotTrackerAction() {}


// 0x0017b1e0 hulkfight::motion::JointRelativeTrack::vfunc_10 (70 B): matches/0x0017b1e0.cpp
// sym: ?vfunc_10@JointRelativeTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::JointRelativeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b1e0 a = (u32_17b1e0)__p0; u32_17b1e0 b = (u32_17b1e0)__p1; u32_17b1e0 c = (u32_17b1e0)__p2;

    if (Check5(c, 0, &g_b_17b1e0, &g_a_17b1e0, 0)) {
        Result_17b1e0* r = (Result_17b1e0*)FUN_0008d690(100);
        if (r)
            return r->Init(this, c);
    }
    return 0;
}

namespace fn_fbf77592 {

// 0x0017b230 hulkfight::motion::JointRelativeAction::vfunc_2 (90 B): matches/0x0017b230.cpp
// sym: ?vfunc_2@JointRelativeAction_17b230@fn_fbf77592@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* JointRelativeAction_17b230::vfunc_2(unsigned char flag) {
    volatile JointRelativeAction_17b230* self = this;
    self->mVptr = &g_vftable_17b230;
    RefObj_17b230* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_17b230* t2 = self->m2;
    if (t2) {
        t2->Release();
        self->m2 = 0;
    }
    int v1 = self->m1;
    if (v1) {
        self->m1 = 0;
    }
    BaseDtor(this);
    if (flag & 1)
        operator_delete(this);
    return this;
}

} // namespace fn_fbf77592

// 0x0017b290 hulkfight::motion::IntentionClearTrack::vfunc_10 (70 B): matches/0x0017b290.cpp
// sym: ?vfunc_10@IntentionClearTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x0010bd40 (propagated; names are from that function)
hulk_intptr hulkfight::motion::IntentionClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b290, &TypeB_17b290, 0);
    if (result) {
        hulkfight::motion::IntentionClearAction* p = Alloc(0x24);
        if (p)
            return ((IntentionClearAction_nv_17b290*)(((hulkfight::motion::IntentionClearAction*)(p))))->Init(this, c);
    }
    return 0;
}

namespace fn_fbf77592 {

// 0x0017b2e0 hulkfight::motion::IntentionClearAction::vfunc_2 (71 B): matches/0x0017b2e0.cpp
// sym: ?vfunc_2@IntentionClearAction_17b2e0@fn_fbf77592@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
IntentionClearAction_17b2e0* IntentionClearAction_17b2e0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b2e0;
    RefCounted_17b2e0* q = *(RefCounted_17b2e0* volatile*)&m_20;
    if (q != 0) {
        q->Release();
        m_20 = 0;
    }
    if (m_1c != 0) {
        m_1c = 0;
    }
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1) {
        opdel(this);
    }
    return this;
}

} // namespace fn_fbf77592
