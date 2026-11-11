// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fbea2d00 {
#define TREE_TU_END }
namespace fn_fbea2d00 {} using namespace fn_fbea2d00;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fbea2d00 {
typedef unsigned int u32_17b330;
extern int TypeA_17b330;
extern int TypeB_17b330;
struct Result_17b330 {
    u32_17b330 Init(void*, void*);
};
extern int Check(void*, int, int*, int*, int);
extern Result_17b330* Alloc(int);
struct RefCounted_17b380 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b380[];
class ChargeAction_17b380 {
  public:
    ChargeAction_17b380* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b380* m_20;
};
struct RefCounted_17b420 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b420[];
class ChargeClearAction_17b420 {
  public:
    ChargeClearAction_17b420* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b420* m_20;
};
struct RefCounted_17b4c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b4c0[];
class PushOutAction_17b4c0 {
  public:
    PushOutAction_17b4c0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b4c0* m_20;
};
extern int FUN_00344e74(hulk_intptr, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
class AllocObj_17b510 {
  public:
    int init(hulkfight::motion::FootPivotTrack*, hulk_intptr);
};
extern void* g_vftable_17b560[];
class Ref_17b560 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class FootPivotAction {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_17b560* m20;
    char p24[4];
    Ref_17b560* m28;
    FootPivotAction* f2(unsigned char);
};
class Helper_17b560 {
  public:
};
extern void __cdecl thunk_FUN_00267090(FootPivotAction*);
typedef unsigned int u32_17b5c0;
struct Helper_17b5c0 {
    int run(hulkfight::motion::DriftToPositionTrack*, u32_17b5c0);
};
extern int __cdecl FUN_00344e74(u32_17b5c0, int, const void*, const void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern const char RTTI1_17b5c0[];
extern const char RTTI2_17b5c0[];
extern int DAT_00417ed8;
struct VObj_17b610 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Sub38_17b610 {
    void Fn();
};
void __cdecl FUN_0008d330(void* p);
class DriftToPositionAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual DriftToPositionAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();


  private:
    char pad0[0x18];
    int m1c;
    VObj_17b610* m20;
    char pad24[0x38 - 0x24];
    Sub38_17b610 m38;
};
typedef unsigned int u32_17b660;
struct Created_17b660 {
    int init(hulkfight::motion::DriftToHulkTrack*, u32_17b660);
};
extern int __cdecl check(u32_17b660, int, const void*, const void*, int);
extern void* __cdecl alloc(hulk_uintptr);
extern const int typeA_17b660;
extern const int typeB_17b660;
struct RefCounted_17b6b0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b6b0[];
class DriftToHulkAction_17b6b0 {
  public:
    DriftToHulkAction_17b6b0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b6b0* m_20;
};
struct RefCounted_17b750 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b750[];
class TeleportAction_17b750 {
  public:
    TeleportAction_17b750* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b750* m_20;
};
extern "C" void __cdecl opdelete(void*);
extern void* const vftable_sym;
class RelObj_17b7f0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Sub28 {
  public:
    void Fn();
};
class BaseCls_17b7f0 {
  public:
};
class TeleportRelativeAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    TeleportRelativeAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad[0x18];
    int m1c;
    RelObj_17b7f0* m20;
    char pad28[4];
    Sub28 m28;
};
typedef unsigned int u32_17b8e0;
struct Helper_17b8e0 {
    int run(hulkfight::motion::SyncToLocatorTrack*, u32_17b8e0);
};
extern int __cdecl FUN_00344e74(u32_17b8e0, int, const void*, const void*, int);
extern const char RTTI1_17b8e0[];
extern const char RTTI2_17b8e0[];
struct RefCounted_17b9a0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17b9a0[];
class SuckInPropsAction_17b9a0 {
  public:
    SuckInPropsAction_17b9a0* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17b9a0* m_20;
};
struct RefCounted_17ba40 {
  public:
    virtual void f0();
    virtual void Release();
};
extern char g_vt_17ba40[];
class TargetIconDistanceAction_17ba40 {
  public:
    TargetIconDistanceAction_17ba40* vfunc_2(int flag);

  private:
    hulk_intptr vtable;
    char pad[0x1c - 4];
    int m_1c;
    RefCounted_17ba40* m_20;
};
typedef unsigned int u32_17ba90;
struct Helper_17ba90 {
    int run(hulkfight::motion::MoveJointTrack*, u32_17ba90);
};
extern int __cdecl FUN_00344e74(u32_17ba90, int, const void*, const void*, int);
extern const char RTTI1_17ba90[];
extern const char RTTI2_17ba90[];
extern "C" char DAT_00417fb8[];
class Ref_17bae0 {
  public:
    virtual void f0();
    virtual void f1();
};
class MoveJointAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual MoveJointAction* v2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x18];
    int m1c;
    Ref_17bae0* m20;
    Ref_17bae0* volatile m24;
    Ref_17bae0* volatile m28;
};
void destroy(MoveJointAction*);
extern void* g_vftable_17bb80[];
class Ref_17bb80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_17bb80 {
  public:
    void* vptr;
};
class TargetBreakAction_17bb80 : public Action_17bb80 {
  public:
    char pad[0x18];
    Ref_17bb80* m;
    TargetBreakAction_17bb80* f2(unsigned char flags);
};
typedef unsigned int u32_17bbc0;
extern int RTTI1_17bbc0, RTTI2;
struct Result_17bbc0 {
    u32_17bbc0 setup(hulkfight::motion::SurfTrack*, hulk_uintptr);
};
extern Result_17bbc0* alloc(int);
extern int g_vftable_17bc10;
class RefObj_17bc10 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class SurfAction_17bc10 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_17bc10* m2;
    RefObj_17bc10* m3;
    void* vfunc_2(unsigned char flag);
};

} // namespace fn_fbea2d00

// 0x0017b330 hulkfight::motion::ChargeTrack::vfunc_10 (70 B): matches/0x0017b330.cpp
// sym: ?vfunc_10@ChargeTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001131c0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ChargeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b330 a = (u32_17b330)__p0; u32_17b330 b = (u32_17b330)__p1; void * p = (void *)__p2;

    if (Check(p, 0, &TypeA_17b330, &TypeB_17b330, 0)) {
        Result_17b330* q = Alloc(0x28);
        if (q)
            return (int)(q->Init(this, p));
    }
    return (int)(0);
}

namespace fn_fbea2d00 {

// 0x0017b380 hulkfight::motion::ChargeAction::vfunc_2 (71 B): matches/0x0017b380.cpp
// sym: ?vfunc_2@ChargeAction_17b380@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ChargeAction_17b380* ChargeAction_17b380::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b380;
    RefCounted_17b380* q = *(RefCounted_17b380* volatile*)&m_20;
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


// 0x0017b420 hulkfight::motion::ChargeClearAction::vfunc_2 (71 B): matches/0x0017b420.cpp
// sym: ?vfunc_2@ChargeClearAction_17b420@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
ChargeClearAction_17b420* ChargeClearAction_17b420::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b420;
    RefCounted_17b420* q = *(RefCounted_17b420* volatile*)&m_20;
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


// 0x0017b4c0 hulkfight::motion::PushOutAction::vfunc_2 (71 B): matches/0x0017b4c0.cpp
// sym: ?vfunc_2@PushOutAction_17b4c0@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
PushOutAction_17b4c0* PushOutAction_17b4c0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b4c0;
    RefCounted_17b4c0* q = *(RefCounted_17b4c0* volatile*)&m_20;
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

} // namespace fn_fbea2d00

// 0x0017b510 hulkfight::motion::FootPivotTrack::vfunc_10 (70 B): matches/0x0017b510.cpp
// sym: ?vfunc_10@FootPivotTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001134e0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FootPivotTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_17b510* p = (AllocObj_17b510*)FUN_0008d690(0x2c);
        if (p)
            return p->init(this, c);
    }
    return 0;
}

namespace fn_fbea2d00 {

// 0x0017b560 hulkfight::motion::FootPivotAction::vfunc_2 (90 B): matches/0x0017b560.cpp
// sym: ?f2@FootPivotAction@fn_fbea2d00@@QAEPAV12@E@Z
FootPivotAction* FootPivotAction::f2(unsigned char flags) {
    *(void**)this = &g_vftable_17b560;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(((Helper_17b560*)this)))->FUN_002326a0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fbea2d00

// 0x0017b5c0 hulkfight::motion::DriftToPositionTrack::vfunc_10 (70 B): matches/0x0017b5c0.cpp
// sym: ?vfunc_10@DriftToPositionTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001421d0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::DriftToPositionTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b5c0 a = (u32_17b5c0)__p0; u32_17b5c0 b = (u32_17b5c0)__p1; u32_17b5c0 c = (u32_17b5c0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_17b5c0, RTTI2_17b5c0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17b5c0*)p)->run(this, c);
    }
    return 0;
}

namespace fn_fbea2d00 {

// 0x0017b610 hulkfight::motion::DriftToPositionAction::vfunc_2 (79 B): matches/0x0017b610.cpp
// sym: ?vfunc_2@DriftToPositionAction@fn_fbea2d00@@UAEPAV12@E@Z
DriftToPositionAction* DriftToPositionAction::vfunc_2(unsigned char param) {
    volatile unsigned int* p = (volatile unsigned int*)this;
    p[0] = (hulk_uintptr)&DAT_00417ed8;
    VObj_17b610* m = (VObj_17b610*)p[8];
    if (m != 0) {
        m->f1();
        p[8] = 0;
    }
    if (m1c != 0) {
        int* q = &m1c;
        *q = 0;
    }
    m38.Fn();
    ((fight::Action *)this)->FUN_002326a0();
    if (param & 1) {
        FUN_0008d330((void*)this);
    }
    return this;
}

} // namespace fn_fbea2d00

// 0x0017b660 hulkfight::motion::DriftToHulkTrack::vfunc_10 (70 B): matches/0x0017b660.cpp
// sym: ?vfunc_10@DriftToHulkTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00138c50 (propagated; names are from that function)
hulk_intptr hulkfight::motion::DriftToHulkTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b660 a = (u32_17b660)__p0; u32_17b660 b = (u32_17b660)__p1; u32_17b660 c = (u32_17b660)__p2;

    if (check(c, 0, &typeA_17b660, &typeB_17b660, 0)) {
        Created_17b660* p = (Created_17b660*)alloc(0x38);
        if (p)
            return p->init(this, c);
    }
    return 0;
}

namespace fn_fbea2d00 {

// 0x0017b6b0 hulkfight::motion::DriftToHulkAction::vfunc_2 (71 B): matches/0x0017b6b0.cpp
// sym: ?vfunc_2@DriftToHulkAction_17b6b0@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
DriftToHulkAction_17b6b0* DriftToHulkAction_17b6b0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b6b0;
    RefCounted_17b6b0* q = *(RefCounted_17b6b0* volatile*)&m_20;
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


// 0x0017b750 hulkfight::motion::TeleportAction::vfunc_2 (71 B): matches/0x0017b750.cpp
// sym: ?vfunc_2@TeleportAction_17b750@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TeleportAction_17b750* TeleportAction_17b750::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b750;
    RefCounted_17b750* q = *(RefCounted_17b750* volatile*)&m_20;
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


// 0x0017b7f0 hulkfight::motion::TeleportRelativeAction::vfunc_2 (79 B): matches/0x0017b7f0.cpp
// sym: ?vfunc_2@TeleportRelativeAction@fn_fbea2d00@@QAEPAV12@E@Z
TeleportRelativeAction* TeleportRelativeAction::vfunc_2(unsigned char param) {
    char* self = (char*)this;
    *(void**)self = (void*)&vftable_sym;
    RelObj_17b7f0** pp = (RelObj_17b7f0**)(self + 0x20);
    RelObj_17b7f0* p = *pp;
    if (p) {
        p->Release();
        *pp = 0;
    }
    int* q1c = (int*)(self + 0x1c);
    int v = *q1c;
    if (v) {
        *q1c = 0;
    }
    ((Sub28*)(self + 0x28))->Fn();
    ((fight::Action *)(((BaseCls_17b7f0*)self)))->FUN_002326a0();
    if (param & 1) {
        opdelete(self);
    }
    return (TeleportRelativeAction*)self;
}

} // namespace fn_fbea2d00

// 0x0017b8e0 hulkfight::motion::SyncToLocatorTrack::vfunc_10 (70 B): matches/0x0017b8e0.cpp
// sym: ?vfunc_10@SyncToLocatorTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001421d0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SyncToLocatorTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b8e0 a = (u32_17b8e0)__p0; u32_17b8e0 b = (u32_17b8e0)__p1; u32_17b8e0 c = (u32_17b8e0)__p2;

    if (FUN_00344e74(c, 0, RTTI1_17b8e0, RTTI2_17b8e0, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17b8e0*)p)->run(this, c);
    }
    return 0;
}


// 0x0017b930 hulkfight::motion::SyncToLocatorAction::vfunc_2 (30 B): matches/0x0017b930.cpp
// sym: ??_GSyncToLocatorAction@motion@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::motion::SyncToLocatorAction::~SyncToLocatorAction() {}

namespace fn_fbea2d00 {

// 0x0017b9a0 hulkfight::motion::SuckInPropsAction::vfunc_2 (71 B): matches/0x0017b9a0.cpp
// sym: ?vfunc_2@SuckInPropsAction_17b9a0@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
SuckInPropsAction_17b9a0* SuckInPropsAction_17b9a0::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17b9a0;
    RefCounted_17b9a0* q = *(RefCounted_17b9a0* volatile*)&m_20;
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


// 0x0017ba40 hulkfight::motion::TargetIconDistanceAction::vfunc_2 (71 B): matches/0x0017ba40.cpp
// sym: ?vfunc_2@TargetIconDistanceAction_17ba40@fn_fbea2d00@@QAEPAV12@H@Z
// Same code shape as 0x0010bd90 (propagated; names are from that function)
TargetIconDistanceAction_17ba40* TargetIconDistanceAction_17ba40::vfunc_2(int flag) {
    volatile hulk_intptr* p = (volatile hulk_intptr*)this;
    *p = (hulk_intptr)&g_vt_17ba40;
    RefCounted_17ba40* q = *(RefCounted_17ba40* volatile*)&m_20;
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

} // namespace fn_fbea2d00

// 0x0017ba90 hulkfight::motion::MoveJointTrack::vfunc_10 (70 B): matches/0x0017ba90.cpp
// sym: ?vfunc_10@MoveJointTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001421d0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::MoveJointTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17ba90 a = (u32_17ba90)__p0; u32_17ba90 b = (u32_17ba90)__p1; u32_17ba90 c = (u32_17ba90)__p2;

    if (FUN_00344e74(c, 0, RTTI1_17ba90, RTTI2_17ba90, 0)) {
        void* p = FUN_0008d690(0x58);
        if (p)
            return ((Helper_17ba90*)p)->run(this, c);
    }
    return 0;
}

namespace fn_fbea2d00 {

// 0x0017bae0 hulkfight::motion::MoveJointAction::vfunc_2 (95 B): matches/0x0017bae0.cpp
// sym: ?v2@MoveJointAction@fn_fbea2d00@@UAEPAV12@E@Z
MoveJointAction* MoveJointAction::v2(unsigned char flag) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_00417fb8);
    Ref_17bae0* a = m24;
    if (a) {
        a->f1();
        m24 = 0;
    }
    Ref_17bae0* b = m28;
    if (b) {
        b->f1();
        m28 = 0;
    }
    Ref_17bae0* c = m20;
    if (c) {
        c->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1)
        destroy(this);
    return this;
}


// 0x0017bb80 hulkfight::motion::TargetBreakAction::vfunc_2 (57 B): matches/0x0017bb80.cpp
// sym: ?f2@TargetBreakAction_17bb80@fn_fbea2d00@@QAEPAV12@E@Z
TargetBreakAction_17bb80* TargetBreakAction_17bb80::f2(unsigned char flags) {
    vptr = g_vftable_17bb80;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_17bb80 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fbea2d00

// 0x0017bbc0 hulkfight::motion::SurfTrack::vfunc_10 (70 B): matches/0x0017bbc0.cpp
// sym: ?vfunc_10@SurfTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001571a0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SurfTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17bbc0 a = (u32_17bbc0)__p0; u32_17bbc0 b = (u32_17bbc0)__p1; hulk_uintptr c = (u32_17bbc0)__p2;

    if (check((void*)c, 0, &RTTI1_17bbc0, &RTTI2, 0)) {
        Result_17bbc0* p = alloc(0x44);
        if (p)
            return (int)(p->setup(this, c));
    }
    return (int)(0);
}

namespace fn_fbea2d00 {

// 0x0017bc10 hulkfight::motion::SurfAction::vfunc_2 (90 B): matches/0x0017bc10.cpp
// sym: ?vfunc_2@SurfAction_17bc10@fn_fbea2d00@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* SurfAction_17bc10::vfunc_2(unsigned char flag) {
    volatile SurfAction_17bc10* self = this;
    self->mVptr = &g_vftable_17bc10;
    RefObj_17bc10* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_17bc10* t2 = self->m2;
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

} // namespace fn_fbea2d00
