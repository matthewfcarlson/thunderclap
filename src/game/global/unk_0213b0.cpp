// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000213b0..0x00021650 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f338c480 {
#define TREE_TU_END }
namespace fn_f338c480 {} using namespace fn_f338c480;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f338c480 {
extern void* g_vftable_21400[];
class Ref_21400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_21400 {
  public:
    void* vptr;
};
class CAction_21400 : public Action_21400 {
  public:
    char pad[24];
    Ref_21400* m;
    ~CAction_21400();
};
class RefObj_21490 {
  public:
    virtual void v0();
    virtual void Release();
};
struct Tidier {
};
extern void* g_vftable_21520[];
class Ref_21520 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_21520 {
  public:
    void* vptr;
};
class CAction_21520 : public Action_21520 {
  public:
    char pad[24];
    Ref_21520* m;
    ~CAction_21520();
};
extern void* g_vftable_215a0[];
class Ref_215a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_215a0 {
  public:
    void* vptr;
};
class CAction_215a0 : public Action_215a0 {
  public:
    char pad[24];
    Ref_215a0* m;
    ~CAction_215a0();
};
extern void* g_vftable_21610[];
class Ref_21610 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_21610 {
  public:
    void* vptr;
};
class CAction_21610 : public Action_21610 {
  public:
    char pad[24];
    Ref_21610* m;
    ~CAction_21610();
};

} // namespace fn_f338c480

// 0x000213b0 FUN_000213b0 (71 B): matches/0x000213b0.cpp [wrapped: conflict: CAction]
// sym: ??0CTargetAction_213b0@fn_000213b0@@QAE@HPAVIRef_213b0@1@@Z
namespace fn_000213b0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_213b0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_213b0 {
  public:
    virtual void VFunc();
    Action_213b0();
};

class CAction : public Action_213b0 {
  public:
    char m_pad[0x18];
    IRef_213b0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_213b0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CTargetAction_213b0 : public CAction {
  public:
    virtual void ProcessDrift();
    CTargetAction_213b0(int a, IRef_213b0* p);
};

CTargetAction_213b0::CTargetAction_213b0(int a, IRef_213b0* p) : CAction(a, p) {}
} // namespace fn_000213b0

namespace fn_f338c480 {

// 0x00021400 FUN_00021400 (36 B): matches/0x00021400.cpp
// sym: ??1CAction_21400@fn_f338c480@@QAE@XZ
CAction_21400::~CAction_21400() {
    vptr = g_vftable_21400;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_21400 *)this)->FUN_002326a0();
}

} // namespace fn_f338c480

// 0x00021430 FUN_00021430 (95 B): matches/0x00021430.cpp [wrapped: conflict: CAction; CHeliDeathSpiralAction]
// sym: ??0CHeliDeathSpiralAction@fn_00021430@@QAE@HPAURef@1@@Z
namespace fn_00021430 {
struct Ref {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
struct CActionBase {
    CActionBase();
    virtual void FUN_00000002();
    char pad[0x18];
    Ref* ref;
};
struct CAction : CActionBase {
    virtual void FUN_00000003();
};
struct CHeliDeathSpiralAction : CAction {
    int value;
    int state;
    int fields[7];
    CHeliDeathSpiralAction(int value, Ref* ref);
    virtual void FUN_00000004();
};
extern void* DAT_003f3390[];
extern void* DAT_003f3de0[];
CHeliDeathSpiralAction::CHeliDeathSpiralAction(int v, Ref* r) : CAction() {
    *(void***)this = DAT_003f3390;
    this->ref = 0;
    if (r)
        r->FUN_00000000();
    if (this->ref)
        this->ref->FUN_00000001();
    this->ref = r;
    state = 0;
    *(void***)this = DAT_003f3de0;
    for (int i = 0; i < 7; ++i)
        fields[i] = 0;
    value = v;
}
} // namespace fn_00021430


// 0x00021490 FUN_00021490 (61 B): matches/0x00021490.cpp
// sym: ?FUN_00021490@CHeliDeathSpiralAction@@QAEXXZ
// Same code shape as 0x0001ecb0 (propagated; names are from that function)
void CHeliDeathSpiralAction::FUN_00021490() {
    *(void* volatile*)this = (void*)vftableD;
    RefObj_21490* b = (*(RefObj_21490 *volatile *)&this->f_24);
    if (b) {
        b->Release();
        (*(RefObj_21490 *volatile *)&this->f_24) = 0;
    }
    *(void* volatile*)this = (void*)vftableA;
    RefObj_21490* a = (*(RefObj_21490 *volatile *)&this->f_1c);
    if (a) {
        a->Release();
        (*(RefObj_21490 *volatile *)&this->f_1c) = 0;
    }
    ((fight::Action *)(((Tidier*)this)))->FUN_002326a0();
}


// 0x000214d0 FUN_000214d0 (71 B): matches/0x000214d0.cpp [wrapped: conflict: CAction]
// sym: ??0CExplosionAction_214d0@fn_000214d0@@QAE@HPAVIRef_214d0@1@@Z
namespace fn_000214d0 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_214d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_214d0 {
  public:
    virtual void VFunc();
    Action_214d0();
};

class CAction : public Action_214d0 {
  public:
    char m_pad[0x18];
    IRef_214d0* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_214d0* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CExplosionAction_214d0 : public CAction {
  public:
    virtual void ProcessDrift();
    CExplosionAction_214d0(int a, IRef_214d0* p);
};

CExplosionAction_214d0::CExplosionAction_214d0(int a, IRef_214d0* p) : CAction(a, p) {}
} // namespace fn_000214d0

namespace fn_f338c480 {

// 0x00021520 FUN_00021520 (36 B): matches/0x00021520.cpp
// sym: ??1CAction_21520@fn_f338c480@@QAE@XZ
CAction_21520::~CAction_21520() {
    vptr = g_vftable_21520;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_21520 *)this)->FUN_002326a0();
}

} // namespace fn_f338c480

// 0x00021550 FUN_00021550 (71 B): matches/0x00021550.cpp [wrapped: conflict: CAction]
// sym: ??0CPropActorSetStateAction_21550@fn_00021550@@QAE@HPAVIRef_21550@1@@Z
namespace fn_00021550 {
// Same code shape as 0x0001fde0 (propagated; names are from that function)
class IRef_21550 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_21550 {
  public:
    virtual void VFunc();
    Action_21550();
};

class CAction : public Action_21550 {
  public:
    char m_pad[0x18];
    IRef_21550* m_pRef;
    int m_param;
    virtual void Process();
    CAction(int a, IRef_21550* p) {
        m_pRef = 0;
        if (p)
            p->AddRef();
        if (m_pRef)
            m_pRef->Release();
        m_pRef = p;
        m_param = a;
    }
};

class CPropActorSetStateAction_21550 : public CAction {
  public:
    virtual void ProcessDrift();
    CPropActorSetStateAction_21550(int a, IRef_21550* p);
};

CPropActorSetStateAction_21550::CPropActorSetStateAction_21550(int a, IRef_21550* p) : CAction(a, p) {}
} // namespace fn_00021550

namespace fn_f338c480 {

// 0x000215a0 FUN_000215a0 (36 B): matches/0x000215a0.cpp
// sym: ??1CAction_215a0@fn_f338c480@@QAE@XZ
CAction_215a0::~CAction_215a0() {
    vptr = g_vftable_215a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_215a0 *)this)->FUN_002326a0();
}

} // namespace fn_f338c480

// 0x000215d0 FUN_000215d0 (64 B): matches/0x000215d0.cpp [wrapped: conflict: CAction; CClearHitRecordsAction]
// sym: ??0CClearHitRecordsAction@fn_000215d0@@QAE@PAVArg_215d0@1@@Z
namespace fn_000215d0 {
class Arg_215d0 {
  public:
    virtual void F0();
    virtual void F1();
};
class CAction {
  public:
    CAction();
    virtual void F0();
    char pad[24];
    Arg_215d0* mArg;
};
class CClearHitRecordsAction : public CAction {
  public:
    CClearHitRecordsAction(Arg_215d0*);
    virtual void F0();
};
extern int vt1_215d0, vt2;
CClearHitRecordsAction::CClearHitRecordsAction(Arg_215d0* p) {
    *(hulk_intptr*)this = (hulk_intptr)&vt1_215d0;
    int* q = (int*)&mArg;
    *q = 0;
    if (p)
        p->F0();
    if (mArg)
        mArg->F1();
    mArg = p;
    *(hulk_intptr*)this = (hulk_intptr)&vt2;
}
} // namespace fn_000215d0

namespace fn_f338c480 {

// 0x00021610 FUN_00021610 (36 B): matches/0x00021610.cpp
// sym: ??1CAction_21610@fn_f338c480@@QAE@XZ
CAction_21610::~CAction_21610() {
    vptr = g_vftable_21610;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_21610 *)this)->FUN_002326a0();
}

} // namespace fn_f338c480
