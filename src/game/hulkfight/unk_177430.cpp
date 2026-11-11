// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00177430..0x00177690 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f92fa536 {
#define TREE_TU_END }
namespace fn_f92fa536 {} using namespace fn_f92fa536;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f92fa536 {
class RefObj_177430 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_177430 {
  public:
    Action_177430();
    virtual void Update();
    char pad[0x18];
};
class CriticalMassDrainAction_177430 : public Action_177430 {
  public:
    int mTarget;
    RefObj_177430* mObj;
    CriticalMassDrainAction_177430(int target, RefObj_177430* obj);
    virtual void Execute();
};
extern void* hulk_at_0041804c[];
class Ref_177480 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_177480 {
  public:
    void* vptr;
};
class CriticalMassDrainAction_177480 : public Action_177480 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_177480* m20;
    ~CriticalMassDrainAction_177480();
};
class Ref_1774c0 {
  public:
    virtual void A();
    virtual void Drop();
};
class Action_1774c0 {
  public:
    virtual void V();
    char pad[0x18];
    Action_1774c0();
};
extern void* hulk_at_00418068;
class MomentumXZAddAction_1774c0 : public Action_1774c0 {
  public:
    int a;
    Ref_1774c0* b;
    int c;
    int d;
    int e;
    int f;
    MomentumXZAddAction_1774c0(int, Ref_1774c0*);
};
extern void* g_vftable_177510[];
class Ref_177510 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_177510 {
  public:
    void* vptr;
};
class MomentumXZAddAction_177510 : public Action_177510 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_177510* m20;
    ~MomentumXZAddAction_177510();
};
class RefObj_177550 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_177550 {
  public:
    Action_177550();
    virtual void Update();
    char pad[0x18];
};
class VisibilityAction_177550 : public Action_177550 {
  public:
    int mTarget;
    RefObj_177550* mObj;
    VisibilityAction_177550(int target, RefObj_177550* obj);
    virtual void Execute();
};
extern void* hulk_at_00418084[];
class Ref_1775a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1775a0 {
  public:
    void* vptr;
};
class VisibilityAction_1775a0 : public Action_1775a0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1775a0* m20;
    ~VisibilityAction_1775a0();
};
class RefObj_1775e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_1775e0 {
  public:
    Action_1775e0();
    virtual void Update();
    char pad[0x18];
};
class SnapToGroundAction_1775e0 : public Action_1775e0 {
  public:
    int mTarget;
    RefObj_1775e0* mObj;
    SnapToGroundAction_1775e0(int target, RefObj_1775e0* obj);
    virtual void Execute();
};
extern void* hulk_at_004180a0[];
class Ref_177630 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_177630 {
  public:
    void* vptr;
};
class SnapToGroundAction_177630 : public Action_177630 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_177630* m20;
    ~SnapToGroundAction_177630();
};


// 0x00177430 FUN_00177430 (72 B): matches/0x00177430.cpp
// sym: ??0CriticalMassDrainAction_177430@fn_f92fa536@@QAE@HPAVRefObj_177430@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
CriticalMassDrainAction_177430::CriticalMassDrainAction_177430(int target, RefObj_177430* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00177480 FUN_00177480 (50 B): matches/0x00177480.cpp
// sym: ??1CriticalMassDrainAction_177480@fn_f92fa536@@QAE@XZ
CriticalMassDrainAction_177480::~CriticalMassDrainAction_177480() {
    vptr = hulk_at_0041804c;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_177480 *)this)->FUN_002326a0();
}


// 0x001774c0 FUN_001774c0 (80 B): matches/0x001774c0.cpp
// sym: ??0MomentumXZAddAction_1774c0@fn_f92fa536@@QAE@HPAVRef_1774c0@1@@Z
MomentumXZAddAction_1774c0::MomentumXZAddAction_1774c0(int x, Ref_1774c0* p) {
    *(void**)this = &hulk_at_00418068;
    int* q = &a;
    *q = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    a = x;
    if (p)
        p->A();
    if (b)
        b->Drop();
    b = p;
}


// 0x00177510 FUN_00177510 (50 B): matches/0x00177510.cpp
// sym: ??1MomentumXZAddAction_177510@fn_f92fa536@@QAE@XZ
MomentumXZAddAction_177510::~MomentumXZAddAction_177510() {
    vptr = g_vftable_177510;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_177510 *)this)->FUN_002326a0();
}


// 0x00177550 FUN_00177550 (72 B): matches/0x00177550.cpp
// sym: ??0VisibilityAction_177550@fn_f92fa536@@QAE@HPAVRefObj_177550@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
VisibilityAction_177550::VisibilityAction_177550(int target, RefObj_177550* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x001775a0 FUN_001775a0 (50 B): matches/0x001775a0.cpp
// sym: ??1VisibilityAction_1775a0@fn_f92fa536@@QAE@XZ
VisibilityAction_1775a0::~VisibilityAction_1775a0() {
    vptr = hulk_at_00418084;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1775a0 *)this)->FUN_002326a0();
}


// 0x001775e0 FUN_001775e0 (72 B): matches/0x001775e0.cpp
// sym: ??0SnapToGroundAction_1775e0@fn_f92fa536@@QAE@HPAVRefObj_1775e0@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
SnapToGroundAction_1775e0::SnapToGroundAction_1775e0(int target, RefObj_1775e0* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}


// 0x00177630 FUN_00177630 (50 B): matches/0x00177630.cpp
// sym: ??1SnapToGroundAction_177630@fn_f92fa536@@QAE@XZ
SnapToGroundAction_177630::~SnapToGroundAction_177630() {
    vptr = hulk_at_004180a0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_177630 *)this)->FUN_002326a0();
}

} // namespace fn_f92fa536
