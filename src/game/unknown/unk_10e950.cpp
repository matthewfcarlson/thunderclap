// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010e950..0x0010ec90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9459e3d {
#define TREE_TU_END }
namespace fn_f9459e3d {} using namespace fn_f9459e3d;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f9459e3d {
extern void* hulk_at_0040dae4[];
} // namespace fn_f9459e3d
void operator delete[](void*);
namespace fn_f9459e3d {
class Ref_10e950 {
  public:
    virtual void F0();
    virtual void Release();
};
class Condition_10e950 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class HulkActionCountCondition_10e950 : public Condition_10e950 {
  public:
    char pad[0xc];
    void* m;
    HulkActionCountCondition_10e950* f2(unsigned char flags);
};
extern void* hulk_at_0040db04[];
class Condition_10e990 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class PropsToSuckCondition : public Condition_10e990 {
  public:
    PropsToSuckCondition* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040db24[];
class Condition_10e9c0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class RandomKeyWordWaitCondition : public Condition_10e9c0 {
  public:
    RandomKeyWordWaitCondition* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040db44[];
class Condition_10e9f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class TokenCondition : public Condition_10e9f0 {
  public:
    TokenCondition* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040db64[];
class Condition_10ea20 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class FightingOtherNPCCondition : public Condition_10ea20 {
  public:
    FightingOtherNPCCondition* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040db84[];
class Ref_10ea50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_10ea50 {
  public:
    void* vptr;
    void Fin_00236d60();
};
void Free_0008d330(void*) throw();
struct Sub_10ea50 {
    char c;
};
extern "C" void __fastcall FUN_0027af50(Sub_10ea50*) throw();
void __fastcall SubFini2(Sub_10ea50*) throw();
void __fastcall SubFini3(Sub_10ea50*) throw();
class SemaphoreClearTrack_10ea50 : public Track_10ea50 {
  public:
    char p18[20];
    Sub_10ea50 s18;
    SemaphoreClearTrack_10ea50* f(unsigned char fl);
};
extern void* hulk_at_0040dbb4[];
class Track_10ea80 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class TokenSupressTrack : public Track_10ea80 {
  public:
    TokenSupressTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040dbe4[];
class Track_10eab0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class AIHistoryCountTrack : public Track_10eab0 {
  public:
    AIHistoryCountTrack* vfunc_5(signed char flags);
};
} }
namespace hulkfight { namespace ai {
class HulkActionTrack {
  public:
    hulk_uintptr vf;
    char pad[0x14];
    HulkActionTrack* vfunc_5(unsigned int);
};
} }
namespace fn_f9459e3d {
class Sub_10eae0 {
  public:
    void Destroy_0027af50();
};
class Base_10eae0 {
  public:
    void Destroy_00236d60();
};
extern void __cdecl thunk_FUN_00267090(hulkfight::ai::HulkActionTrack*);
extern void* hulk_at_0040dc44[];
class Str_10eb10 {
  public:
    void Init_0027af50();
};
class Track_10eb10 {
  public:
    void* vptr;
    char pad[20];
    Str_10eb10 s;
    void Fin_00236d60();
};
class KeywordWaitTrack_10eb10 : public Track_10eb10 {
  public:
    void* Del(unsigned char flags);
};
extern void* hulk_at_0040dc74[];
class Track_10eb40 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class ButtonTrack : public Track_10eb40 {
  public:
    ButtonTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040dca4[];
class Sub_10eb70 {
  public:
    void Fini_0027af50();
};
class Track_10eb70 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class AIHistorySetTrack_10eb70 : public Track_10eb70 {
  public:
    char pad[0x14];
    Sub_10eb70 m18;
    AIHistorySetTrack_10eb70* f2(unsigned char flags);
};
extern void* hulk_at_0040dcd4[];
class Track_10eba0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
} // namespace fn_f9459e3d
namespace hulkfight { namespace ai {
class TokenTrack : public Track_10eba0 {
  public:
    TokenTrack* vfunc_5(signed char flags);
};
} }
namespace fn_f9459e3d {
extern void* hulk_at_0040dd04[];
class Str_10ebd0 {
  public:
    void Init_0027af50();
};
class Track_10ebd0 {
  public:
    void* vptr;
    char pad[20];
    Str_10ebd0 s;
    void Fin_00236d60();
};
class SemaphoreWaitTrack_10ebd0 : public Track_10ebd0 {
  public:
    void* Del(unsigned char flags);
};
class RefObj_10ec00 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_10ec00 {
  public:
    Action_10ec00();
    virtual void Update();
    char pad[0x18];
};
class ButtonAction_10ec00 : public Action_10ec00 {
  public:
    int mTarget;
    RefObj_10ec00* mObj;
    ButtonAction_10ec00(int target, RefObj_10ec00* obj);
    virtual void Execute();
};
extern void* hulk_at_0040dd34[];
class Ref_10ec50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_10ec50 {
  public:
    void* vptr;
};
class ButtonAction_10ec50 : public Action_10ec50 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_10ec50* m20;
    ~ButtonAction_10ec50();
};


// 0x0010e950 hulkfight::ai::HulkActionCountCondition::vfunc_5 (50 B): matches/0x0010e950.cpp
// sym: ?f2@HulkActionCountCondition_10e950@fn_f9459e3d@@QAEPAV12@E@Z
HulkActionCountCondition_10e950* HulkActionCountCondition_10e950::f2(unsigned char flags) {
    vptr = hulk_at_0040dae4;
    operator delete[](m);
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f9459e3d

// 0x0010e990 hulkfight::ai::PropsToSuckCondition::vfunc_5 (36 B): matches/0x0010e990.cpp
// sym: ?vfunc_5@PropsToSuckCondition@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::PropsToSuckCondition* hulkfight::ai::PropsToSuckCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040db04;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e9c0 hulkfight::ai::RandomKeyWordWaitCondition::vfunc_5 (36 B): matches/0x0010e9c0.cpp
// sym: ?vfunc_5@RandomKeyWordWaitCondition@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::RandomKeyWordWaitCondition* hulkfight::ai::RandomKeyWordWaitCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040db24;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e9f0 hulkfight::ai::TokenCondition::vfunc_5 (36 B): matches/0x0010e9f0.cpp
// sym: ?vfunc_5@TokenCondition@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TokenCondition* hulkfight::ai::TokenCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040db44;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010ea20 hulkfight::ai::FightingOtherNPCCondition::vfunc_5 (36 B): matches/0x0010ea20.cpp
// sym: ?vfunc_5@FightingOtherNPCCondition@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::FightingOtherNPCCondition* hulkfight::ai::FightingOtherNPCCondition::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040db64;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_f9459e3d {

// 0x0010ea50 hulkfight::ai::SemaphoreClearTrack::vfunc_5 (46 B): matches/0x0010ea50.cpp
// sym: ?f@SemaphoreClearTrack_10ea50@fn_f9459e3d@@QAEPAV12@E@Z
SemaphoreClearTrack_10ea50* SemaphoreClearTrack_10ea50::f(unsigned char fl) {
    vptr = hulk_at_0040db84;
    FUN_0027af50(&s18);
    Fin_00236d60();
    if (fl & 1)
        Free_0008d330(this);
    return this;
}

} // namespace fn_f9459e3d

// 0x0010ea80 hulkfight::ai::TokenSupressTrack::vfunc_5 (36 B): matches/0x0010ea80.cpp
// sym: ?vfunc_5@TokenSupressTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TokenSupressTrack* hulkfight::ai::TokenSupressTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040dbb4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010eab0 hulkfight::ai::AIHistoryCountTrack::vfunc_5 (36 B): matches/0x0010eab0.cpp
// sym: ?vfunc_5@AIHistoryCountTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::AIHistoryCountTrack* hulkfight::ai::AIHistoryCountTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040dbe4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010eae0 hulkfight::ai::HulkActionTrack::vfunc_5 (46 B): matches/0x0010eae0.cpp
// sym: ?vfunc_5@HulkActionTrack@ai@hulkfight@@QAEPAV123@I@Z
hulkfight::ai::HulkActionTrack* hulkfight::ai::HulkActionTrack::vfunc_5(unsigned int flags) {
    vf = ((hulk_intptr)DAT_0040dc14);
    ((Sub_10eae0*)((char*)this + 0x18))->Destroy_0027af50();
    ((Base_10eae0*)this)->Destroy_00236d60();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}

namespace fn_f9459e3d {

// 0x0010eb10 hulkfight::ai::KeywordWaitTrack::vfunc_5 (46 B): matches/0x0010eb10.cpp
// sym: ?Del@KeywordWaitTrack_10eb10@fn_f9459e3d@@QAEPAXE@Z
void* KeywordWaitTrack_10eb10::Del(unsigned char flags) {
    vptr = hulk_at_0040dc44;
    s.Init_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f9459e3d

// 0x0010eb40 hulkfight::ai::ButtonTrack::vfunc_5 (36 B): matches/0x0010eb40.cpp
// sym: ?vfunc_5@ButtonTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::ButtonTrack* hulkfight::ai::ButtonTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040dc74;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_f9459e3d {

// 0x0010eb70 hulkfight::ai::AIHistorySetTrack::vfunc_5 (46 B): matches/0x0010eb70.cpp
// sym: ?f2@AIHistorySetTrack_10eb70@fn_f9459e3d@@QAEPAV12@E@Z
AIHistorySetTrack_10eb70* AIHistorySetTrack_10eb70::f2(unsigned char flags) {
    vptr = hulk_at_0040dca4;
    m18.Fini_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f9459e3d

// 0x0010eba0 hulkfight::ai::TokenTrack::vfunc_5 (36 B): matches/0x0010eba0.cpp
// sym: ?vfunc_5@TokenTrack@ai@hulkfight@@QAEPAV123@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
hulkfight::ai::TokenTrack* hulkfight::ai::TokenTrack::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040dcd4;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

namespace fn_f9459e3d {

// 0x0010ebd0 hulkfight::ai::SemaphoreWaitTrack::vfunc_5 (46 B): matches/0x0010ebd0.cpp
// sym: ?Del@SemaphoreWaitTrack_10ebd0@fn_f9459e3d@@QAEPAXE@Z
void* SemaphoreWaitTrack_10ebd0::Del(unsigned char flags) {
    vptr = hulk_at_0040dd04;
    s.Init_0027af50();
    Fin_00236d60();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0010ec00 FUN_0010ec00 (72 B): matches/0x0010ec00.cpp
// sym: ??0ButtonAction_10ec00@fn_f9459e3d@@QAE@HPAVRefObj_10ec00@1@@Z
// Same code shape as 0x0010b980 (propagated; names are from that function)
ButtonAction_10ec00::ButtonAction_10ec00(int target, RefObj_10ec00* obj) {
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


// 0x0010ec50 FUN_0010ec50 (50 B): matches/0x0010ec50.cpp
// sym: ??1ButtonAction_10ec50@fn_f9459e3d@@QAE@XZ
ButtonAction_10ec50::~ButtonAction_10ec50() {
    vptr = hulk_at_0040dd34;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_10ec50 *)this)->FUN_002326a0();
}

} // namespace fn_f9459e3d
