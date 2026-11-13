// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00235a20..0x002361a0 (kind game, layer engine, confidence high), dominant class fight::FightNodeTimeCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fac1015e {
#define TREE_TU_END }
namespace fn_fac1015e {} using namespace fn_fac1015e;
namespace fn_fac1015e { extern "C" char DAT_00427ccc[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fac1015e {
extern int* hulk_at_004e5bdc;
class CCondition_235a20 {
  public:
    virtual int vfunc_0(int);
};
class FightNodeBaseCondition_235a30 {
  public:
    FightNodeBaseCondition_235a30(int);
    virtual hulk_intptr FnV_00235a20(int);
};
class Elem_235a30 {
  public:
    void Init_00233dd0();
};
class FightNodeCondition : public FightNodeBaseCondition_235a30 {
  public:
    char pad04[8];
    int field0c;
    char pad10[4];
    FightNodeCondition();
    virtual bool V2_00234270(void*);
};
extern int hulk_at_00427cf0;
extern int hulk_at_00427ccc;
class Part_235a60 {
  public:
    void Init_00234150();
};
class CCondition {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
};
} // namespace fn_fac1015e
class CCharacterTemplateVariationCondition : public CCondition {
  public:
    char pad[12];
    Part_235a60 part;
    void Run();
    void Finish_002345b0();
};
namespace fn_fac1015e {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5be4;
class CCondition_235af0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00427d14[];
struct FightNodeTimeCondition_235b00 {
    void Init_00234590(int);
};
struct Part_235b00 {
    void Init_00233dd0();
};
struct Node {
    char pad00[0x14];
    Node *parent;           // 0x14
};
struct NodeRef {
    Node *node;
};
class FightNodeParentCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, int a2, int a3);
    virtual NodeRef *vfunc_7(int a2);
    char pad04[8];
    int mode;               // 0x0c
    Node *target;           // 0x10
    char pad14[8];
    char searchAncestors;   // 0x1c
};
extern int* hulk_at_004e5bec;
class CCondition_235c00 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00427d38[];
class FightNodeBaseCondition_235c10 {
  public:
    int x[3];
    FightNodeBaseCondition_235c10(int);
};
class FightNodeTimeCondition : public FightNodeBaseCondition_235c10 {
  public:
    int y;
    int z;
    FightNodeTimeCondition();
};
void __fastcall FUN_002345b0(CEffectStopTrack*);
class CTrack {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class FightNodeBaseCondition_235c50 : public CTrack {
  public:
    FightNodeBaseCondition_235c50* vfunc_5(signed char flags);
};
} // namespace fn_fac1015e
class CNameFlagConditionBase : public CCondition {
  public:
    char pad[12];
    CNameFlagConditionBase* vfunc_5(int);
};
namespace fn_fac1015e {
class H {
  public:
    void Fna_00234150();
    void Fnb_002345b0();
};
void thunk_FUN_00267090(void*);
class FightNodeTimeCondition_235d00 : public CTrack {
  public:
    FightNodeTimeCondition_235d00* vfunc_5(signed char flags);
};
struct CAxisArcCondition_235e40;
class CStageCondition_235e50 {};
class ParamValue_235e50 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_235e50 : public ParamValue_235e50 {
  public:
    virtual void f();
};
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
struct CAxisArcCondition_235f00;
class CStageCondition_235f10 {};
class ParamValue_235f10 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_235f10 : public ParamValue_235f10 {
  public:
    virtual void f();
};
class CStageCondition_235fd0;
class ParamValue_235fd0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_235fd0 : public ParamValue_235fd0 {
  public:
    int pad;
};
struct CAxisArcCondition_236010;
class CStageCondition_236020 {};
class ParamValue_236020 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_236020 : public ParamValue_236020 {
  public:
    virtual void f();
};
class CStageCondition_2360b0;
class ParamValue_2360b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_2360b0 : public ParamValue_2360b0 {
  public:
    int pad;
};

} // namespace fn_fac1015e

// 0x00235a20 fight::FightNodeCondition::vfunc_0 (16 B): matches/0x00235a20.cpp
// sym: ?vfunc_0@FightNodeCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::FightNodeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5bdc;
    return p[index];
}

namespace fn_fac1015e {

// 0x00235a30 FUN_00235a30 (35 B): matches/0x00235a30.cpp
// sym: ??0FightNodeCondition@fn_fac1015e@@QAE@XZ
FightNodeCondition::FightNodeCondition() : FightNodeBaseCondition_235a30(0) {
    field0c = 0;
    ((Elem_235a30*)((char*)this + 0x10))->Init_00233dd0();
}

} // namespace fn_fac1015e

// 0x00235a60 FUN_00235a60 (31 B): matches/0x00235a60.cpp
// sym: ?Run@CCharacterTemplateVariationCondition@@QAEXXZ
// Same code shape as 0x0004a030 (propagated; names are from that function)
void CCharacterTemplateVariationCondition::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00427cf0;
    part.Init_00234150();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00427ccc;
    Finish_002345b0();
}


// 0x00235a80 fight::FightNodeCondition::vfunc_6 (67 B): matches/0x00235a80.cpp [wrapped: conflict: fight::FightNodeCondition]
// sym: ?vfunc_6@FightNodeCondition@fight@fn_00235a80@@UAE_NHHH@Z
namespace fn_00235a80 {
namespace fight {
class FightNodeCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int, int, int);
    virtual int* lookup(int);
    char pad[8];
    int op;
    int value;
};
bool FightNodeCondition::vfunc_6(int a, int b, int c) {
    int* p = lookup(b);
    if (!p)
        return false;
    int v = value;
    int mode = op;
    int x = *p;
    switch (mode) {
    case 0:
        return x == v;
    case 1:
        return x != v;
    }
    return false;
}
} // namespace fight
} // namespace fn_00235a80

namespace fn_fac1015e {

// 0x00235ad0 FUN_00235ad0 (19 B): matches/0x00235ad0.cpp
// sym: ?FUN_00235ad0@fn_fac1015e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00235ad0() {
    FUN_00234810(((char*)&DAT_004e5be4), ((char*)&DAT_004e5be8));
}

} // namespace fn_fac1015e

// 0x00235af0 fight::FightNodeParentCondition::vfunc_0 (16 B): matches/0x00235af0.cpp
// sym: ?vfunc_0@FightNodeParentCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::FightNodeParentCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5be4;
    return p[index];
}


// 0x00235b00 FUN_00235b00 (39 B): matches/0x00235b00.cpp
// sym: ?FUN_00235b00@FightNodeParentCondition@fight@@QAEPAV12@XZ
fight::FightNodeParentCondition* fight::FightNodeParentCondition::FUN_00235b00() {
    ((FightNodeTimeCondition_235b00*)this)->Init_00234590(0);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427d14);
    *(int*)((char*)&this->compare) = 0;
    ((Part_235b00*)((char*)this + 0x10))->Init_00233dd0();
    *((char*)&this->recurse) = 1;
    return (fight::FightNodeParentCondition*)(this);
}


// 0x00235b30 FUN_00235b30 (31 B): matches/0x00235b30.cpp [wrapped: conflict: CCharacterTemplateVariationCondition]
// sym: ?Run@CCharacterTemplateVariationCondition@fn_00235b30@@QAEXXZ
namespace fn_00235b30 {
// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int hulk_at_00427d14;
extern int vtableB;
class Part_235b30 {
  public:
    void Init_00234150();
};
class CCondition {
  public:
    virtual void F();
};
class CCharacterTemplateVariationCondition : public CCondition {
  public:
    char pad[12];
    Part_235b30 part;
    void Run();
    void Finish_002345b0();
};
void CCharacterTemplateVariationCondition::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_00427d14;
    part.Init_00234150();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish_002345b0();
}
} // namespace fn_00235b30

namespace fn_fac1015e {

// 0x00235b50 fight::FightNodeParentCondition::vfunc_6 (131 B): equivalent/0x00235b50.cpp
// sym: ?vfunc_6@FightNodeParentCondition@fn_fac1015e@@UAE_NHHH@Z @474c1962185e @waae72b192bd8
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 24/24)
// fight::FightNodeParentCondition::vfunc_6 @ 0x00235b50
bool FightNodeParentCondition::vfunc_6(int a1, int a2, int a3)
{
    NodeRef *ref = vfunc_7(a2);
    if (ref == 0)
        return false;

    Node *parent = ref->node;
    if (parent != 0)
        parent = parent->parent;

    if (searchAncestors) {
        for (; parent != 0; parent = parent->parent) {
            if (parent == target)
                return mode == 0;
        }
        return mode == 1;
    }

    switch (mode) {
    case 0:
        return parent == target;
    case 1:
        return parent != target;
    }
    return false;
}


// 0x00235be0 FUN_00235be0 (19 B): matches/0x00235be0.cpp
// sym: ?FUN_00235be0@fn_fac1015e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00235be0() {
    FUN_00234810(((char*)&DAT_004e5bec), ((char*)&DAT_004e5bf0));
}

} // namespace fn_fac1015e

// 0x00235c00 fight::FightNodeTimeCondition::vfunc_0 (16 B): matches/0x00235c00.cpp
// sym: ?vfunc_0@FightNodeTimeCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::FightNodeTimeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5bec;
    return p[index];
}

namespace fn_fac1015e {

// 0x00235c10 FUN_00235c10 (34 B): matches/0x00235c10.cpp
// sym: ??0FightNodeTimeCondition@fn_fac1015e@@QAE@XZ
FightNodeTimeCondition::FightNodeTimeCondition() : FightNodeBaseCondition_235c10(0) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427d38);
    y = 0;
    z = 0;
}


// 0x00235c40 FUN_00235c40 (11 B): matches/0x00235c40.cpp
// sym: ?FUN_00235c40@fn_fac1015e@@YIXPAVCEffectStopTrack@@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_00235c40(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_00427ccc);
    FUN_002345b0(self);
}


// 0x00235c50 fight::FightNodeBaseCondition::vfunc_5 (36 B): matches/0x00235c50.cpp
// sym: ?vfunc_5@FightNodeBaseCondition_235c50@fn_fac1015e@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FightNodeBaseCondition_235c50* FightNodeBaseCondition_235c50::vfunc_5(signed char flags) {
    *(void***)this = (void**)DAT_00427ccc;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fac1015e

// 0x00235c80 fight::FightNodeCondition::vfunc_5 (52 B): matches/0x00235c80.cpp
// sym: ?vfunc_5@CNameFlagConditionBase@@QAEPAV1@H@Z
// Same code shape as 0x0004c020 (propagated; names are from that function)
CNameFlagConditionBase* CNameFlagConditionBase::vfunc_5(int p) {
    CNameFlagConditionBase* s = this;
    *(void (**)())s = &vt_name;
    ((H*)((char*)s + 0x10))->Fna_00234150();
    *(void (**)())s = &vt_cond;
    ((H*)s)->Fnb_002345b0();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}


// 0x00235cc0 fight::FightNodeParentCondition::vfunc_5 (52 B): matches/0x00235cc0.cpp [wrapped: same definition as 0x00235c80 in this TU]
// sym: ?vfunc_5@CNameFlagConditionBase@fn_00235cc0@@QAEPAV12@H@Z
namespace fn_00235cc0 {
// Same code shape as 0x0004c020 (propagated; names are from that function)
class CCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class CNameFlagConditionBase : public CCondition {
  public:
    char pad[12];
    CNameFlagConditionBase* vfunc_5(int);
};
class FightNodeTimeCondition_235cc0 {
  public:
    void Fna_00234150();
    void Fnb_002345b0();
};
extern void vt_name_00427d14();
extern void vt_cond_00427ccc();
void thunk_FUN_00267090(void*);
CNameFlagConditionBase* CNameFlagConditionBase::vfunc_5(int p) {
    CNameFlagConditionBase* s = this;
    *(void (**)())s = &vt_name_00427d14;
    ((FightNodeTimeCondition_235cc0*)((char*)s + 0x10))->Fna_00234150();
    *(void (**)())s = &vt_cond_00427ccc;
    ((FightNodeTimeCondition_235cc0*)s)->Fnb_002345b0();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}
} // namespace fn_00235cc0

namespace fn_fac1015e {

// 0x00235d00 fight::FightNodeTimeCondition::vfunc_5 (36 B): matches/0x00235d00.cpp
// sym: ?vfunc_5@FightNodeTimeCondition_235d00@fn_fac1015e@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FightNodeTimeCondition_235d00* FightNodeTimeCondition_235d00::vfunc_5(signed char flags) {
    *(void***)this = (void**)DAT_00427ccc;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fac1015e

// 0x00235d30 fight::FightNodeTimeCondition::vfunc_6 (192 B): equivalent/0x00235d30.cpp [wrapped: conflict: fight::FightNodeTimeCondition]
// sym: ?vfunc_6@FightNodeTimeCondition@fight@fn_00235d30@@UAE_NIII@Z @6c22b7617baf @wb5780400b347
namespace fn_00235d30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// fight::FightNodeTimeCondition::vfunc_6 @ 0x00235d30
struct TimeData { char pad[28]; float time; };
extern "C" bool __cdecl FUN_00018960(float, float, float);
namespace fight {
struct FightNodeTimeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(unsigned a, unsigned b, unsigned c); virtual TimeData* FUN_00344f51(unsigned);
 char pad[8]; unsigned comparison; float threshold;
};
bool FightNodeTimeCondition::vfunc_6(unsigned a, unsigned b, unsigned c) {
 TimeData* data = FUN_00344f51(b);
 if (!data) return false;
 float time = data->time;
 switch (comparison) {
 case 0: return time < threshold;
 case 1: return time <= threshold;
 case 2: return FUN_00018960(time, threshold, 0.00001f);
 case 3: return !FUN_00018960(time, threshold, 0.00001f);
 case 4: return time >= threshold;
 case 5: return time > threshold;
 default: return false;
 }
}
}
} // namespace fn_00235d30


// 0x00235e40 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_7 (6 B): matches/0x00235e40.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00235e50 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_6 (30 B): matches/0x00235e50.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_235e50 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_235e50*)&DAT_003f335c));
}


// 0x00235e70 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_8 (26 B): matches/0x00235e70.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<fight::FightNodeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<fight::FightNodeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<fight::FightNodeCondition>::**)(int))&this->f_18))(b);
}


// 0x00235e90 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_2 (11 B): matches/0x00235e90.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_2() {
    return this->f_18 == 0;
}

namespace fn_fac1015e {

// 0x00235ec0 fight::ParamBranch<fight::FightNodeCondition>::vfunc_6 (12 B): matches/0x00235ec0.cpp
// sym: ?vfunc_6@ParamBranch@fn_fac1015e@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fac1015e

// 0x00235f00 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_7 (6 B): matches/0x00235f00.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00235f10 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_6 (30 B): matches/0x00235f10.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_235f10 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_235f10*)&DAT_003f335c));
}


// 0x00235f30 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_8 (26 B): matches/0x00235f30.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<fight::FightNodeParentCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<fight::FightNodeParentCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<fight::FightNodeParentCondition>::**)(int))&this->f_18))(b);
}


// 0x00235f50 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_2 (11 B): matches/0x00235f50.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00235f80 fight::ParamBranch<fight::FightNodeParentCondition>::vfunc_6 (12 B): matches/0x00235f80.cpp [wrapped: same definition as 0x00235ec0 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_00235f80@@UAEXPAX@Z
namespace fn_00235f80 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_00235f80


// 0x00235fb0 fight::ParamBool<fight::FightNodeParentCondition>::vfunc_6 (26 B): matches/0x00235fb0.cpp
// sym: ?vfunc_6@?$ParamBool@VFightNodeParentCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<fight::FightNodeParentCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<fight::FightNodeParentCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<fight::FightNodeParentCondition>*)a)->*(*(bool (fight::ParamBool<fight::FightNodeParentCondition>::**)(int))&this->f_10))(b);
}


// 0x00235fd0 fight::ParamBool<fight::FightNodeParentCondition>::vfunc_2 (11 B): matches/0x00235fd0.cpp
// sym: ?vfunc_2@?$ParamBool@VFightNodeParentCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<fight::FightNodeParentCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00236010 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_7 (6 B): matches/0x00236010.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x00236020 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_6 (30 B): matches/0x00236020.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_236020 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_236020*)&DAT_003f335c));
}


// 0x00236040 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_8 (26 B): matches/0x00236040.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<fight::FightNodeTimeCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<fight::FightNodeTimeCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<fight::FightNodeTimeCondition>::**)(int))&this->f_18))(b);
}


// 0x00236060 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_2 (11 B): matches/0x00236060.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x00236090 fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_6 (26 B): matches/0x00236090.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFightNodeTimeCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<fight::FightNodeTimeCondition>*)a)->*(*(bool (fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::**)(int))&this->f_10))(b);
}


// 0x002360b0 fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_2 (11 B): matches/0x002360b0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFightNodeTimeCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x002360c0 fight::ParamEnumConstList<fight::FightNodeCondition>::vfunc_0 (30 B): matches/0x002360c0.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<fight::FightNodeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<fight::FightNodeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2360c0)
#endif


// 0x002360e0 fight::ParamBranch<fight::FightNodeCondition>::vfunc_0 (30 B): matches/0x002360e0.cpp
// sym: ??_G?$ParamBranch@VFightNodeCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::FightNodeCondition>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<fight::FightNodeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x2360e0)
#endif


// 0x00236100 fight::ParamEnumConstList<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236100.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<fight::FightNodeParentCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<fight::FightNodeParentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x236100)
#endif


// 0x00236120 fight::ParamBranch<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236120.cpp
// sym: ??_G?$ParamBranch@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBranch<fight::FightNodeParentCondition>::~ParamBranch() {}
#if defined(HULK_PTR64)
template class fight::ParamBranch<fight::FightNodeParentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x236120)
#endif


// 0x00236140 fight::ParamBool<fight::FightNodeParentCondition>::vfunc_0 (30 B): matches/0x00236140.cpp
// sym: ??_G?$ParamBool@VFightNodeParentCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<fight::FightNodeParentCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<fight::FightNodeParentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x236140)
#endif


// 0x00236160 fight::ParamEnumConstList<fight::FightNodeTimeCondition>::vfunc_0 (30 B): matches/0x00236160.cpp
// sym: ??_G?$ParamEnumConstList@VFightNodeTimeCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<fight::FightNodeTimeCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<fight::FightNodeTimeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x236160)
#endif


// 0x00236180 fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::vfunc_0 (30 B): matches/0x00236180.cpp
// sym: ??_G?$ParamFloatConstRange@VFightNodeTimeCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<fight::FightNodeTimeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x236180)
#endif

