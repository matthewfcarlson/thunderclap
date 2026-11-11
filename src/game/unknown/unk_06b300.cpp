// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006b300..0x0006bd20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_fad3cf42 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fad3cf42 {} using namespace fn_fad3cf42;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fad3cf42 {
class CTrack_6b410 {
  public:
    CTrack_6b410();
    virtual hulk_intptr Fnf_00068ce0(int);
    char pad[4];
    int n;
};
class Sub {
  public:
    Sub();
    char pad[8];
};
class CJointTrack : public CTrack_6b410 {
  public:
    CJointTrack();
    int a;
    float b;
    char pad2[4];
    Sub sub;
    char flag;
    char pad3[3];
    int c, d, e;
    char flag2;
    char pad4[3];
    int f, g, h, i, j, k;
};
struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_00236d60(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int hulk_at_003f98d0;
class CTrack {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class CScrubberTrack : public CTrack {
  public:
    CScrubberTrack* vfunc_5(signed char flags);
};
class CClimbingTrack : public CTrack {
  public:
    CClimbingTrack* vfunc_5(signed char flags);
};
class CJumpTrack : public CTrack {
  public:
    CJumpTrack* vfunc_5(signed char flags);
};
struct Object {
 char pad[0x14];
 float x0,x1,y0,y1;
 float FUN_00069390(float x, float y);
 hulk_freg FUN_0006b540(float t);
};
class CDropTrack : public CTrack {
  public:
    CDropTrack* vfunc_5(signed char flags);
};
class Helper_6b620 {
  public:
    void Fnf_0027af50();
};
class CKeyPoseTrack {
  public:
    int* vptr;
    char pad[0x5c];
    CKeyPoseTrack* vfunc_5(unsigned char flag);
    void BaseDtor_00236d60();
};
void Final_0008d330(CKeyPoseTrack*);
class CSoundTrack : public CTrack {
  public:
    CSoundTrack* vfunc_5(signed char flags);
};
class CComboMessageTrack : public CTrack {
  public:
    CComboMessageTrack* vfunc_5(signed char flags);
};
class CMoveTrack : public CTrack {
  public:
    CMoveTrack* vfunc_5(signed char flags);
};
class CMoveAddTrack : public CTrack {
  public:
    CMoveAddTrack* vfunc_5(signed char flags);
};
extern hulk_freg __cdecl FUN_0004af40(float, float, float);
extern const float hulk_at_003f32b8;
class Obj {
    char pad[0x18];
    float angle;

  public:
    bool Set(float a);
};
class CMoveAddYTrack : public CTrack {
  public:
    CMoveAddYTrack* vfunc_5(signed char flags);
};
class X {
    char pad[0x18];
    float angle;

  public:
    char SetDirection_0006b7b0(float v);
};
class CSweepTrack : public CTrack {
  public:
    CSweepTrack* vfunc_5(signed char flags);
};
class CAutoTargetTrack : public CTrack {
  public:
    CAutoTargetTrack* vfunc_5(signed char flags);
};
class CDamageTrack : public CTrack {
  public:
    CDamageTrack* vfunc_5(signed char flags);
};
class CDrainHealthTrack : public CTrack {
  public:
    CDrainHealthTrack* vfunc_5(signed char flags);
};
class CComboTimerTrack : public CTrack {
  public:
    CComboTimerTrack* vfunc_5(signed char flags);
};
class CInvincibleTrack : public CTrack {
  public:
    CInvincibleTrack* vfunc_5(signed char flags);
};
class CIntangibleTrack : public CTrack {
  public:
    CIntangibleTrack* vfunc_5(signed char flags);
};
class CIntangibleToActorsTrack : public CTrack {
  public:
    CIntangibleToActorsTrack* vfunc_5(signed char flags);
};
class CCameraShakeTrack : public CTrack {
  public:
    CCameraShakeTrack* vfunc_5(signed char flags);
};
class CCameraDramaticTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCameraDramaticTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x5c];
};
class Helper_6b990 {
  public:
    void init_0027af50();
    void finish_00236d60();
};
extern char hulk_at_003fbeb8, vfTrack;
void __cdecl thunk_FUN_00267090(CCameraDramaticTrack*);
class CCameraHintTrack : public CTrack {
  public:
    CCameraHintTrack* vfunc_5(signed char flags);
};
class CJumpAttackTrack : public CTrack {
  public:
    CJumpAttackTrack* vfunc_5(signed char flags);
};
class COrientTrack : public CTrack {
  public:
    COrientTrack* vfunc_5(signed char flags);
};
class CDriftTrack : public CTrack {
  public:
    CDriftTrack* vfunc_5(signed char flags);
};
class CUninterruptibleTrack : public CTrack {
  public:
    CUninterruptibleTrack* vfunc_5(signed char flags);
};
class CInvulnerableTrack : public CTrack {
  public:
    CInvulnerableTrack* vfunc_5(signed char flags);
};
class CRageModeTrack : public CTrack {
  public:
    CRageModeTrack* vfunc_5(signed char flags);
};
class CStageTrack : public CTrack {
  public:
    CStageTrack* vfunc_5(signed char flags);
};
class CAlertStatusTrack : public CTrack {
  public:
    CAlertStatusTrack* vfunc_5(signed char flags);
};
class CDeathTrack : public CTrack {
  public:
    CDeathTrack* vfunc_5(signed char flags);
};
class CClearCollisionStun : public CTrack {
  public:
    CClearCollisionStun* vfunc_5(signed char flags);
};
class CMotionHitGroundHeightTrack : public CTrack {
  public:
    CMotionHitGroundHeightTrack* vfunc_5(signed char flags);
};
class CWallSlideTrack : public CTrack {
  public:
    CWallSlideTrack* vfunc_5(signed char flags);
};
class CTargetTrack : public CTrack {
  public:
    CTargetTrack* vfunc_5(signed char flags);
};
class ParamValueFloat_6bd00 {
  public:
    virtual void* V0_0006e840(int);
    ParamValueFloat_6bd00(int a);
};
class ParamFloatConstRange_6bd00 : public ParamValueFloat_6bd00 {
  public:
    virtual void V1_0004e0b0();
    char pad[0x0c];
    int mValue;
    ParamFloatConstRange_6bd00(int a, int b);
};


// 0x0006b410 FUN_0006b410 (84 B): matches/0x0006b410.cpp
// sym: ??0CJointTrack@fn_fad3cf42@@QAE@XZ
CJointTrack::CJointTrack()
    : a(0), b(-1.0f), flag(0), c(0), d(0), e(0), flag2(0), f(0), g(0), h(0), j(0), k(0) {
    i = -1;
    n = 1;
}


// 0x0006b470 CJointTrack::vfunc_5 (52 B): matches/0x0006b470.cpp
// sym: ?CSmartPropNameCondition_vfunc_5@fn_fad3cf42@@YIPAUCSmartPropNameCondition@1@PAU21@PAXE@Z
// Same code shape as 0x0004c720 (propagated; names are from that function)
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = &smart_vftable;
    FUN_0027af50((char*)p + 0x18);
    p->vptr = &hulk_at_003f98d0;
    FUN_00236d60(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}


// 0x0006b4b0 CScrubberTrack::vfunc_5 (36 B): matches/0x0006b4b0.cpp
// sym: ?vfunc_5@CScrubberTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CScrubberTrack* CScrubberTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b4e0 CClimbingTrack::vfunc_5 (36 B): matches/0x0006b4e0.cpp
// sym: ?vfunc_5@CClimbingTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CClimbingTrack* CClimbingTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b510 CJumpTrack::vfunc_5 (36 B): matches/0x0006b510.cpp
// sym: ?vfunc_5@CJumpTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CJumpTrack* CJumpTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b540 FUN_0006b540 (172 B): equivalent/0x0006b540.cpp
// sym: ?FUN_0006b540@Object@fn_fad3cf42@@QAEMM@Z @cb9a793a869b @wb9040271d1aa
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_0006b540 @ 0x0006b540
hulk_freg Object::FUN_0006b540(float t) {
 float dy = y1-y0;
 float dx = x1-x0;
 if (dy >= 0.0f && dx >= 0.0f && t >= 0.0f && t <= 1.0f)
  return FUN_00069390(dx*t+x0, dy*t+y0);
 if (x0 <= 0.0f) return 0.0f;
 return (y0/x0)*2.0f;
}


// 0x0006b5f0 CDropTrack::vfunc_5 (36 B): matches/0x0006b5f0.cpp
// sym: ?vfunc_5@CDropTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CDropTrack* CDropTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b620 CKeyPoseTrack::vfunc_5 (60 B): matches/0x0006b620.cpp
// sym: ?vfunc_5@CKeyPoseTrack@fn_fad3cf42@@QAEPAV12@E@Z
CKeyPoseTrack* CKeyPoseTrack::vfunc_5(unsigned char flag) {
    vptr = (int*)((hulk_intptr)DAT_003fbb34);
    ((Helper_6b620*)((char*)this + 0x60))->Fnf_0027af50();
    ((Helper_6b620*)((char*)this + 0x10))->Fnf_0027af50();
    vptr = (int*)((hulk_intptr)DAT_003f98d0);
    BaseDtor_00236d60();
    if (flag & 1)
        Final_0008d330(this);
    return this;
}


// 0x0006b660 CSoundTrack::vfunc_5 (36 B): matches/0x0006b660.cpp
// sym: ?vfunc_5@CSoundTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSoundTrack* CSoundTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b690 CComboMessageTrack::vfunc_5 (36 B): matches/0x0006b690.cpp
// sym: ?vfunc_5@CComboMessageTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CComboMessageTrack* CComboMessageTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b6c0 CMoveTrack::vfunc_5 (36 B): matches/0x0006b6c0.cpp
// sym: ?vfunc_5@CMoveTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CMoveTrack* CMoveTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b720 CMoveAddTrack::vfunc_5 (36 B): matches/0x0006b720.cpp
// sym: ?vfunc_5@CMoveAddTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CMoveAddTrack* CMoveAddTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b750 FUN_0006b750 (41 B): matches/0x0006b750.cpp
// sym: ?Set@Obj@fn_fad3cf42@@QAE_NM@Z
bool Obj::Set(float a) {
    angle = FUN_0004af40(-180.0f, 180.0f, a) * hulk_at_003f32b8;
    return true;
}


// 0x0006b780 CMoveAddYTrack::vfunc_5 (36 B): matches/0x0006b780.cpp
// sym: ?vfunc_5@CMoveAddYTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CMoveAddYTrack* CMoveAddYTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b7b0 FUN_0006b7b0 (41 B): matches/0x0006b7b0.cpp
// sym: ?SetDirection_0006b7b0@X@fn_fad3cf42@@QAEDM@Z
char X::SetDirection_0006b7b0(float v) {
    angle = FUN_0004af40(-180.0f, 180.0f, v) * 0.017453292f;
    return 1;
}


// 0x0006b7e0 CSweepTrack::vfunc_5 (36 B): matches/0x0006b7e0.cpp
// sym: ?vfunc_5@CSweepTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CSweepTrack* CSweepTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b810 CAutoTargetTrack::vfunc_5 (36 B): matches/0x0006b810.cpp
// sym: ?vfunc_5@CAutoTargetTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAutoTargetTrack* CAutoTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b840 CDamageTrack::vfunc_5 (36 B): matches/0x0006b840.cpp
// sym: ?vfunc_5@CDamageTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CDamageTrack* CDamageTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b870 CDrainHealthTrack::vfunc_5 (36 B): matches/0x0006b870.cpp
// sym: ?vfunc_5@CDrainHealthTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CDrainHealthTrack* CDrainHealthTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b8a0 CComboTimerTrack::vfunc_5 (36 B): matches/0x0006b8a0.cpp
// sym: ?vfunc_5@CComboTimerTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CComboTimerTrack* CComboTimerTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b8d0 CInvincibleTrack::vfunc_5 (36 B): matches/0x0006b8d0.cpp
// sym: ?vfunc_5@CInvincibleTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CInvincibleTrack* CInvincibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b900 CIntangibleTrack::vfunc_5 (36 B): matches/0x0006b900.cpp
// sym: ?vfunc_5@CIntangibleTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIntangibleTrack* CIntangibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b930 CIntangibleToActorsTrack::vfunc_5 (36 B): matches/0x0006b930.cpp
// sym: ?vfunc_5@CIntangibleToActorsTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CIntangibleToActorsTrack* CIntangibleToActorsTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b960 CCameraShakeTrack::vfunc_5 (36 B): matches/0x0006b960.cpp
// sym: ?vfunc_5@CCameraShakeTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCameraShakeTrack* CCameraShakeTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006b990 CCameraDramaticTrack::vfunc_5 (69 B): matches/0x0006b990.cpp
// sym: ?vfunc_5@CCameraDramaticTrack@fn_fad3cf42@@UAEPAV12@E@Z
CCameraDramaticTrack* CCameraDramaticTrack::vfunc_5(unsigned char flag) {
    CCameraDramaticTrack* self = this;
    *(void**)self = &hulk_at_003fbeb8;
    Helper_6b990* h = (Helper_6b990*)((char*)self + 0x60);
    int n = 8;
    do {
        h = (Helper_6b990*)((char*)h - 8);
        h->init_0027af50();
        --n;
    } while (n);
    *(void**)self = &vfTrack;
    ((Helper_6b990*)self)->finish_00236d60();
    if (flag & 1)
        thunk_FUN_00267090(self);
    return self;
}


// 0x0006b9e0 CCameraHintTrack::vfunc_5 (36 B): matches/0x0006b9e0.cpp
// sym: ?vfunc_5@CCameraHintTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCameraHintTrack* CCameraHintTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006ba10 CJumpAttackTrack::vfunc_5 (36 B): matches/0x0006ba10.cpp
// sym: ?vfunc_5@CJumpAttackTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CJumpAttackTrack* CJumpAttackTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006ba40 COrientTrack::vfunc_5 (36 B): matches/0x0006ba40.cpp
// sym: ?vfunc_5@COrientTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
COrientTrack* COrientTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006ba70 CDriftTrack::vfunc_5 (36 B): matches/0x0006ba70.cpp
// sym: ?vfunc_5@CDriftTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CDriftTrack* CDriftTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006baa0 CUninterruptibleTrack::vfunc_5 (36 B): matches/0x0006baa0.cpp
// sym: ?vfunc_5@CUninterruptibleTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CUninterruptibleTrack* CUninterruptibleTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bad0 CInvulnerableTrack::vfunc_5 (36 B): matches/0x0006bad0.cpp
// sym: ?vfunc_5@CInvulnerableTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CInvulnerableTrack* CInvulnerableTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bb00 CRageModeTrack::vfunc_5 (36 B): matches/0x0006bb00.cpp
// sym: ?vfunc_5@CRageModeTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CRageModeTrack* CRageModeTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bb30 CStageTrack::vfunc_5 (36 B): matches/0x0006bb30.cpp
// sym: ?vfunc_5@CStageTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CStageTrack* CStageTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fad3cf42

// 0x0006bb60 CHeadTrackerTrack::vfunc_5 (52 B): matches/0x0006bb60.cpp [wrapped: same definition as 0x0006b470 in this TU]
// sym: ?CSmartPropNameCondition_vfunc_5@fn_0006bb60@@YIPAUCSmartPropNameCondition@1@PAU21@PAXE@Z
namespace fn_0006bb60 {
// Same code shape as 0x0004c720 (propagated; names are from that function)
struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_00236d60(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int hulk_at_003fc0d0;
extern int condition_vftable_6bb60;
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = &hulk_at_003fc0d0;
    FUN_0027af50((char*)p + 0x18);
    p->vptr = &condition_vftable_6bb60;
    FUN_00236d60(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}
} // namespace fn_0006bb60

namespace fn_fad3cf42 {

// 0x0006bba0 CAlertStatusTrack::vfunc_5 (36 B): matches/0x0006bba0.cpp
// sym: ?vfunc_5@CAlertStatusTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CAlertStatusTrack* CAlertStatusTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bbd0 CDeathTrack::vfunc_5 (36 B): matches/0x0006bbd0.cpp
// sym: ?vfunc_5@CDeathTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CDeathTrack* CDeathTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fad3cf42

// 0x0006bc00 CAIHintTrack::vfunc_5 (52 B): matches/0x0006bc00.cpp [wrapped: same definition as 0x0006b470 in this TU]
// sym: ?CSmartPropNameCondition_vfunc_5@fn_0006bc00@@YIPAUCSmartPropNameCondition@1@PAU21@PAXE@Z
namespace fn_0006bc00 {
// Same code shape as 0x0004c720 (propagated; names are from that function)
struct CSmartPropNameCondition {
    void* vptr;
    char pad[0x14];
};
extern "C" void __fastcall FUN_0027af50(void*);
extern void __fastcall FUN_00236d60(void*);
extern void __cdecl thunk_FUN_00267090(void*);
extern int hulk_at_003fc184;
extern int condition_vftable_6bc00;
CSmartPropNameCondition* __fastcall CSmartPropNameCondition_vfunc_5(CSmartPropNameCondition* p, void*,
                                                                    unsigned char flags) {
    p->vptr = &hulk_at_003fc184;
    FUN_0027af50((char*)p + 0x18);
    p->vptr = &condition_vftable_6bc00;
    FUN_00236d60(p);
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}
} // namespace fn_0006bc00

namespace fn_fad3cf42 {

// 0x0006bc40 CClearCollisionStun::vfunc_5 (36 B): matches/0x0006bc40.cpp
// sym: ?vfunc_5@CClearCollisionStun@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CClearCollisionStun* CClearCollisionStun::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bc70 CMotionHitGroundHeightTrack::vfunc_5 (36 B): matches/0x0006bc70.cpp
// sym: ?vfunc_5@CMotionHitGroundHeightTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CMotionHitGroundHeightTrack* CMotionHitGroundHeightTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bca0 CWallSlideTrack::vfunc_5 (36 B): matches/0x0006bca0.cpp
// sym: ?vfunc_5@CWallSlideTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CWallSlideTrack* CWallSlideTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bcd0 CTargetTrack::vfunc_5 (36 B): matches/0x0006bcd0.cpp
// sym: ?vfunc_5@CTargetTrack@fn_fad3cf42@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CTargetTrack* CTargetTrack::vfunc_5(signed char flags) {
    *(void***)this = CTrack_vftable;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0006bd00 FUN_0006bd00 (32 B): matches/0x0006bd00.cpp
// sym: ??0ParamFloatConstRange_6bd00@fn_fad3cf42@@QAE@HH@Z
ParamFloatConstRange_6bd00::ParamFloatConstRange_6bd00(int a, int b) : ParamValueFloat_6bd00(a) {
    mValue = b;
}

} // namespace fn_fad3cf42
