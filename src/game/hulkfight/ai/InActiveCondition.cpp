// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010e3e0..0x0010e950 (kind game, layer game, confidence high), dominant class hulkfight::ai::InActiveCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fad6e2b1 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fad6e2b1 {} using namespace fn_fad6e2b1;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fad6e2b1 {
namespace fight {
class Params_10e3e0 {
public:
    virtual void vfunc_0();
};
}
class CFightParams_10e3e0 : public fight::Params_10e3e0 {
public:
    virtual void vfunc_0();
};
struct StateInfo_10e3e0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};
struct Anim_10e3e0 {
    char pad0[0x80];
    StateInfo_10e3e0 state;
};
struct Holder_10e3e0 {
};
} // namespace fn_fad6e2b1
struct World {
    char pad0[0x54];
    Holder_10e3e0 *holder;
};
namespace fn_fad6e2b1 {
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);
struct Fighter_10e3e0 {
    char pad0[0x1ba4];
    char flag1ba4;
    char pad1ba5[0x1cee - 0x1ba5];
    unsigned char level;
    char pad1cef[0x1d40 - 0x1cef];
    char flag1d40;
};
extern "C" Fighter_10e3e0 *__fastcall FUN_00059a30(Context *ctx);
struct Clock_10e3e0 {
    char pad0[0x2b0];
    int now;
    char pad2b4[0x2d0 - 0x2b4];
    int limit;
};
Clock_10e3e0 *__cdecl FUN_000678d0();
class InActiveCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight::Params_10e3e0 *params, int c);
    char pad04[0xc];
    char invert;
};
struct KeywordData {
    char pad[0x18];
    int first;
    int second;
};
struct Result {
    float FUN_00037290(int, int);
};
struct Stage {
    Result* FUN_00059a30();
};
struct Source {
    Stage* FUN_000592a0();
};
struct Timer {
    char pad0[0x18];
    int arg0;               // 0x18
    int arg1;               // 0x1c
};
struct Mixer;
struct Handle_10e570 {
    Mixer* FUN_00059a30();
};
struct Mgr_10e570 {
    Handle_10e570* FUN_000592a0();
};
namespace hulkfight { namespace ai {
class KeywordWaitAction {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual bool vfunc_5(int skip, float dt);
    char _m_pad_4[0x18];
    union { KeywordData* data; Timer* timer; };
    union { Mgr_10e570* manager; Source* source; };
    union { float value; float wait; };
    union { float elapsed; int status; };
    unsigned char vfunc_3(int unused1, int unused2);
};
} }
struct Mixer {
    float FUN_00037290(int a, int b);
};
extern void* hulk_at_0040d984[];
class Condition_10e6f0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class OnBlockedTriangleCondition_10e6f0 : public Condition_10e6f0 {
  public:
    OnBlockedTriangleCondition_10e6f0* vfunc_5(signed char flags);
};
struct Sub_10e720 {
    void init_00234150();
};
class AIFightNodeCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual AIFightNodeCondition* vfunc_5(unsigned char param);
    virtual void v6();
    void baseInit_002345b0();
    char pad[0x0c];
};
extern void thunk_FUN_00267090(AIFightNodeCondition*);
extern void* hulk_at_0040d9c4[];
class Condition_10e750 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class DefendingCondition_10e750 : public Condition_10e750 {
  public:
    DefendingCondition_10e750* vfunc_5(signed char flags);
};
extern "C" void __cdecl thunk_FUN_00267090(void* p);
extern int hulk_at_0040d9e4;
class AIHistoryNameCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual AIHistoryNameCondition* vfunc_5(int flag);
    virtual void vfunc_6();
    int pad4;
    int pad8;
    int padc;
    void* m10;
    void reset_002345b0();
};
class Condition_10e7c0 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class HulkActionLargestCondition_10e7c0 : public Condition_10e7c0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    HulkActionLargestCondition_10e7c0* f5(unsigned char flags);
};
extern void* hulk_at_0040da24[];
class Condition_10e800 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class PropsToChuckCondition_10e800 : public Condition_10e800 {
  public:
    PropsToChuckCondition_10e800* vfunc_5(signed char flags);
};
extern int hulk_at_0040da44;
class HulkActionRecentCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual HulkActionRecentCondition* vfunc_5(char);
    virtual void vfunc_6();
    char pad[12];
    void* m10;
    void Finish_002345b0();
};
extern void* hulk_at_0040da64[];
class Condition_10e870 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class LeashedCondition_10e870 : public Condition_10e870 {
  public:
    LeashedCondition_10e870* vfunc_5(signed char flags);
};
extern void* hulk_at_0040da84[];
class Condition_10e8a0 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class KeyWordWaitCondition_10e8a0 : public Condition_10e8a0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    KeyWordWaitCondition_10e8a0* f5(unsigned char flags);
};
class FormationReadyCondition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    int pad4;
    int pad8;
    int padc;
    int m10;
    FormationReadyCondition* vfunc_5(int);
    void Cleanup_002345b0();
};
extern "C" void __cdecl helper(hulk_intptr);
extern "C" void __cdecl helper2_0008d330(FormationReadyCondition*);
extern int hulk_at_0040daa4;
extern void* hulk_at_0040dac4[];
class Condition_10e920 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class InActiveCondition_10e920 : public Condition_10e920 {
  public:
    InActiveCondition_10e920* vfunc_5(signed char flags);
};


// 0x0010e3e0 hulkfight::ai::InActiveCondition::vfunc_6 (325 B): equivalent/0x0010e3e0.cpp
// sym: ?vfunc_6@InActiveCondition@fn_fad6e2b1@@UAEDHPAVParams_10e3e0@fight@2@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3247 inputs, branch coverage 30/30; Wine build 697 inputs, 30/30)
// hulkfight::ai::InActiveCondition::vfunc_6 @ 0x0010e3e0
char InActiveCondition::vfunc_6(int a, fight::Params_10e3e0 *params, int c)
{
    if (dynamic_cast<CFightParams_10e3e0 *>(params) == 0)
        return 0;
    Fighter_10e3e0 *f = FUN_00059a30(FUN_000592a0(params));
    if (f == 0)
        return 0;

    int kind = -1;
    int sub = -1;
    Anim_10e3e0 *anim = ((Anim_10e3e0 *)((owners::C_86310 *)(DAT_004dd700->holder))->FUN_00086310());
    if (anim) {
        kind = anim->state.FUN_00088fa0();
        sub = anim->state.FUN_00088fb0();
    }

    if (invert) {
        if (kind == 7 && sub == 2)
            return 1;
        if ((float)f->level == 0.0f)
            return 1;
        if (f->flag1d40)
            return 1;
        int now = FUN_000678d0()->now;
        if (now < FUN_000678d0()->limit)
            return 1;
        return f->flag1ba4;
    }
    if (kind == 7 && sub == 2)
        return 0;
    if ((float)f->level == 0.0f)
        return 0;
    if (f->flag1d40)
        return 0;
    int now = FUN_000678d0()->now;
    if (now < FUN_000678d0()->limit)
        return 0;
    return f->flag1ba4 == 0;
}


// 0x0010e530 hulkfight::ai::KeywordWaitAction::vfunc_3 (62 B): matches/0x0010e530.cpp
// sym: ?vfunc_3@KeywordWaitAction@ai@hulkfight@fn_fad6e2b1@@QAEEHH@Z
namespace hulkfight { namespace ai {
unsigned char KeywordWaitAction::vfunc_3(int unused1, int unused2) {
    if (!source)
        return 0;
    Stage* stage = source->FUN_000592a0();
    Result* result = stage->FUN_00059a30();
    status = 0;
    int first = data->first;
    int second = data->second;
    value = result->FUN_00037290(first, second);
    return 1;
}
} }


// 0x0010e570 hulkfight::ai::KeywordWaitAction::vfunc_5 (127 B): equivalent/0x0010e570.cpp
// sym: ?vfunc_5@KeywordWaitAction@ai@hulkfight@fn_fad6e2b1@@UAE_NHM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::ai::KeywordWaitAction::vfunc_5 @ 0x0010e570
// Advances the elapsed time; false while the wait is still running.
bool hulkfight::ai::KeywordWaitAction::vfunc_5(int skip, float dt)
{
    if (skip == 0) {
        Mixer* mixer = manager->FUN_000592a0()->FUN_00059a30();
        elapsed = dt + elapsed;
        volatile float v = mixer->FUN_00037290(timer->arg0, timer->arg1);
        wait = v;
        if (v > 0.0f) {
            if (elapsed >= v)
                return false;
        }
        return true;
    }
    return true;
}


// 0x0010e6f0 hulkfight::ai::OnBlockedTriangleCondition::vfunc_5 (36 B): matches/0x0010e6f0.cpp
// sym: ?vfunc_5@OnBlockedTriangleCondition_10e6f0@fn_fad6e2b1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
OnBlockedTriangleCondition_10e6f0* OnBlockedTriangleCondition_10e6f0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040d984;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e720 hulkfight::ai::AIFightNodeCondition::vfunc_5 (46 B): matches/0x0010e720.cpp
// sym: ?vfunc_5@AIFightNodeCondition@fn_fad6e2b1@@UAEPAV12@E@Z
AIFightNodeCondition* AIFightNodeCondition::vfunc_5(unsigned char param) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040d9a4);
    ((Sub_10e720*)((char*)this + 0xc))->init_00234150();
    baseInit_002345b0();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0010e750 hulkfight::ai::DefendingCondition::vfunc_5 (36 B): matches/0x0010e750.cpp
// sym: ?vfunc_5@DefendingCondition_10e750@fn_fad6e2b1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
DefendingCondition_10e750* DefendingCondition_10e750::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040d9c4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e780 hulkfight::ai::AIHistoryNameCondition::vfunc_5 (50 B): matches/0x0010e780.cpp
// sym: ?vfunc_5@AIHistoryNameCondition@fn_fad6e2b1@@UAEPAV12@H@Z
AIHistoryNameCondition* AIHistoryNameCondition::vfunc_5(int flag) {
    void* x = m10;
    *(void**)this = &hulk_at_0040d9e4;
    thunk_FUN_00267090(x);
    reset_002345b0();
    if (flag & 1)
        operator delete(this);
    return this;
}


// 0x0010e7c0 hulkfight::ai::HulkActionLargestCondition::vfunc_5 (50 B): matches/0x0010e7c0.cpp
// sym: ?f5@HulkActionLargestCondition_10e7c0@fn_fad6e2b1@@QAEPAV12@E@Z
HulkActionLargestCondition_10e7c0* HulkActionLargestCondition_10e7c0::f5(unsigned char flags) {
    void* a = m10;
    vptr = g_vA;
    operator delete[](a);
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0010e800 hulkfight::ai::PropsToChuckCondition::vfunc_5 (36 B): matches/0x0010e800.cpp
// sym: ?vfunc_5@PropsToChuckCondition_10e800@fn_fad6e2b1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PropsToChuckCondition_10e800* PropsToChuckCondition_10e800::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040da24;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e830 hulkfight::ai::HulkActionRecentCondition::vfunc_5 (50 B): matches/0x0010e830.cpp
// sym: ?vfunc_5@HulkActionRecentCondition@fn_fad6e2b1@@UAEPAV12@D@Z
HulkActionRecentCondition* HulkActionRecentCondition::vfunc_5(char a) {
    void* x = m10;
    *(void**)this = &hulk_at_0040da44;
    thunk_FUN_00267090(x);
    Finish_002345b0();
    if (a & 1)
        operator delete(this);
    return this;
}


// 0x0010e870 hulkfight::ai::LeashedCondition::vfunc_5 (36 B): matches/0x0010e870.cpp
// sym: ?vfunc_5@LeashedCondition_10e870@fn_fad6e2b1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
LeashedCondition_10e870* LeashedCondition_10e870::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040da64;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0010e8a0 hulkfight::ai::KeyWordWaitCondition::vfunc_5 (50 B): matches/0x0010e8a0.cpp
// sym: ?f5@KeyWordWaitCondition_10e8a0@fn_fad6e2b1@@QAEPAV12@E@Z
KeyWordWaitCondition_10e8a0* KeyWordWaitCondition_10e8a0::f5(unsigned char flags) {
    void* p = m10;
    vptr = hulk_at_0040da84;
    operator delete[](p);
    Fin_002345b0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0010e8e0 hulkfight::ai::FormationReadyCondition::vfunc_5 (50 B): matches/0x0010e8e0.cpp
// sym: ?vfunc_5@FormationReadyCondition@fn_fad6e2b1@@QAEPAV12@H@Z
FormationReadyCondition* FormationReadyCondition::vfunc_5(int flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&hulk_at_0040daa4;
    helper(m10);
    Cleanup_002345b0();
    if (flag & 1)
        helper2_0008d330(this);
    return this;
}


// 0x0010e920 hulkfight::ai::InActiveCondition::vfunc_5 (36 B): matches/0x0010e920.cpp
// sym: ?vfunc_5@InActiveCondition_10e920@fn_fad6e2b1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
InActiveCondition_10e920* InActiveCondition_10e920::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040dac4;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fad6e2b1
