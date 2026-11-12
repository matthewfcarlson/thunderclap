// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00020020..0x000202f0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f81bc752 {
#define TREE_TU_END }
namespace fn_f81bc752 {} using namespace fn_f81bc752;
namespace fn_f81bc752 { extern "C" char DAT_003f3390[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f81bc752 {
extern void* hulk_at_003f3390[];
class Ref_20070 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20070 {
  public:
    void* vptr;
};
class CAction_20070 : public Action_20070 {
  public:
    char pad[24];
    Ref_20070* m;
    ~CAction_20070();
};
extern void* g_vftable_200f0[];
class Ref_200f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_200f0 {
  public:
    void* vptr;
};
class CAction_200f0 : public Action_200f0 {
  public:
    char pad[24];
    Ref_200f0* m;
    ~CAction_200f0();
};
extern void* g_vftable_20170[];
class Ref_20170 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_20170 {
  public:
    void* vptr;
};
class CAction_20170 : public Action_20170 {
  public:
    char pad[24];
    Ref_20170* m;
    ~CAction_20170();
};
extern void* g_vftable_201f0[];
class Ref_201f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_201f0 {
  public:
    void* vptr;
};
class CAction_201f0 : public Action_201f0 {
  public:
    char pad[24];
    Ref_201f0* m;
    ~CAction_201f0();
};
class RefCounted_20220 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Action_20220 {
public:
    Action_20220() throw();
    virtual void v0_00018b30();
    char pad04[0x1c - 4];
};
class CAction : public Action_20220 {
public:
    CAction(RefCounted_20220 *r) throw() {
        owner = 0;
        if (r != 0)
            r->AddRef();
        if (owner != 0)
            owner->Release();
        owner = r;
    }
    virtual void v1_00018b40();
    RefCounted_20220 *owner;
};
class CHeadTrackerAction : public CAction {
public:
    CHeadTrackerAction(int id, RefCounted_20220 *r) throw();
    virtual void v2();
    int id;
    int field24;
    char pad28[0x74 - 0x28];
    char flag74;
    char pad75[3];
    int w78;
    int w7c;
    int w80;
    float w84;
    int w88;
    int w8c;
};
extern void* gA_20290[];
class Ref_20290 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_20290 {
  public:
    void* vptr;
};
class CHeadTrackerAction_20290 : public CAction_20290 {
  public:
    char pad_1c[0x18];
    Ref_20290* m1c;
    char pad_24[0x4];
    Ref_20290* m24;
    char pad_88[0x60];
    Ref_20290* m88;
    ~CHeadTrackerAction_20290();
};

} // namespace fn_f81bc752

// 0x00020020 FUN_00020020 (71 B): matches/0x00020020.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CUninterruptibleAction_20020@fn_00020020@@QAE@PAUObj_20020@1@H@Z
namespace fn_00020020 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20020 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3bc4;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_20020* mObj;
    int mValue;
};
class CUninterruptibleAction_20020 : public CAction {
  public:
    CUninterruptibleAction_20020(Obj_20020*, int);
    virtual void V0();
};
CUninterruptibleAction_20020::CUninterruptibleAction_20020(Obj_20020* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3bc4;
}
void CUninterruptibleAction_20020::V0() {}
} // namespace fn_00020020

namespace fn_f81bc752 {

// 0x00020070 FUN_00020070 (36 B): matches/0x00020070.cpp
// sym: ??1CAction_20070@fn_f81bc752@@QAE@XZ
CAction_20070::~CAction_20070() {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20070 *)this)->FUN_002326a0();
}

} // namespace fn_f81bc752

// 0x000200a0 FUN_000200a0 (71 B): matches/0x000200a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CInvulnerableAction_200a0@fn_000200a0@@QAE@PAUObj_200a0@1@H@Z
namespace fn_000200a0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_200a0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3bec;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_200a0* mObj;
    int mValue;
};
class CInvulnerableAction_200a0 : public CAction {
  public:
    CInvulnerableAction_200a0(Obj_200a0*, int);
    virtual void V0();
};
CInvulnerableAction_200a0::CInvulnerableAction_200a0(Obj_200a0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3bec;
}
void CInvulnerableAction_200a0::V0() {}
} // namespace fn_000200a0

namespace fn_f81bc752 {

// 0x000200f0 FUN_000200f0 (36 B): matches/0x000200f0.cpp
// sym: ??1CAction_200f0@fn_f81bc752@@QAE@XZ
CAction_200f0::~CAction_200f0() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_200f0 *)this)->FUN_002326a0();
}

} // namespace fn_f81bc752

// 0x00020120 FUN_00020120 (71 B): matches/0x00020120.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CRageModeAction_20120@fn_00020120@@QAE@PAUObj_20120@1@H@Z
namespace fn_00020120 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_20120 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3c14;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_20120* mObj;
    int mValue;
};
class CRageModeAction_20120 : public CAction {
  public:
    CRageModeAction_20120(Obj_20120*, int);
    virtual void V0();
};
CRageModeAction_20120::CRageModeAction_20120(Obj_20120* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3c14;
}
void CRageModeAction_20120::V0() {}
} // namespace fn_00020120

namespace fn_f81bc752 {

// 0x00020170 FUN_00020170 (36 B): matches/0x00020170.cpp
// sym: ??1CAction_20170@fn_f81bc752@@QAE@XZ
CAction_20170::~CAction_20170() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_20170 *)this)->FUN_002326a0();
}

} // namespace fn_f81bc752

// 0x000201a0 FUN_000201a0 (71 B): matches/0x000201a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CStageAction_201a0@fn_000201a0@@QAE@PAUObj_201a0@1@H@Z
namespace fn_000201a0 {
// Same code shape as 0x0001db40 (propagated; names are from that function)
struct Obj_201a0 {
    virtual void F();
    virtual void G();
};
extern int VBase;
extern int hulk_at_003f3c3c;
class CAction {
  public:
    CAction();
    virtual void V0();
    virtual void V1();
    char pad[0x18];
    Obj_201a0* mObj;
    int mValue;
};
class CStageAction_201a0 : public CAction {
  public:
    CStageAction_201a0(Obj_201a0*, int);
    virtual void V0();
};
CStageAction_201a0::CStageAction_201a0(Obj_201a0* arg, int value) {
    *(hulk_intptr*)this = (hulk_intptr)&VBase;
    mObj = 0;
    if (arg)
        arg->F();
    if (mObj)
        mObj->G();
    mObj = arg;
    mValue = value;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f3c3c;
}
void CStageAction_201a0::V0() {}
} // namespace fn_000201a0

namespace fn_f81bc752 {

// 0x000201f0 FUN_000201f0 (36 B): matches/0x000201f0.cpp
// sym: ??1CAction_201f0@fn_f81bc752@@QAE@XZ
CAction_201f0::~CAction_201f0() {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_201f0 *)this)->FUN_002326a0();
}


// 0x00020220 FUN_00020220 (111 B): equivalent/0x00020220.cpp
// sym: ??0CHeadTrackerAction@fn_f81bc752@@QAE@HPAVRefCounted_20220@1@@Z @be80367e20ae @w8b3208e7a313
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00020220 @ 0x00020220
// equiv-map: ??0ActionBase@@QAE@XZ = 0x00232660
CHeadTrackerAction::CHeadTrackerAction(int actionId, RefCounted_20220 *r) throw() : CAction(r)
{
    field24 = 0;
    w88 = 0;
    w8c = 0;
    id = actionId;
    flag74 = 0;
    w80 = 0;
    w7c = 0;
    w78 = 0;
    w84 = 1.0f;
}


// 0x00020290 FUN_00020290 (86 B): matches/0x00020290.cpp
// sym: ??1CHeadTrackerAction_20290@fn_f81bc752@@QAE@XZ
CHeadTrackerAction_20290::~CHeadTrackerAction_20290() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m88) {
        m88->Release();
        m88 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_20290;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_20290 *)this)->FUN_002326a0();
}

} // namespace fn_f81bc752
