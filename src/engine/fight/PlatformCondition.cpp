// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0023cb40..0x0023cf00 (kind game, layer engine, confidence high), dominant class fight::PlatformCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe0f08cb {
#define TREE_TU_END }
namespace fn_fe0f08cb {} using namespace fn_fe0f08cb;
namespace fn_fe0f08cb {
struct FactoryCtor { void init_002343b0(); };   // (unb4) the factory constructors InitHelper::init stood for
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_fe0f08cb {
class Obj_23cb40 {
  public:
    char pad[12];
    unsigned char value;
    char SetPS2_0023cb40(unsigned char b);
};
class C_23cb50 {
  public:
    char pad[13];
    char m;
    bool SetXBox_0023cb50(char c);
};
class Obj_23cb60 {
  public:
    char pad[0xe];
    char mVal;
    char SetGameCube_0023cb60(char v);
};
class O_23cb70 {
  public:
    char pad[0xf];
    bool SetWin32_0023cb70(char v);
};
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c4c;
class CCondition_23cba0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00428980[];
class Condition_23cc00 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class PlatformCondition_23cc00 : public Condition_23cc00 {
  public:
    PlatformCondition_23cc00* vfunc_5(signed char flags);
};
class CStageCondition_23cc70;
class ParamValue_23cc70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23cc70 : public ParamValue_23cc70 {
  public:
    int pad;
};
extern int hulk_at_00491ca8;
class PlatformCondition {};
struct Factory_23cde0 {
    hulk_intptr vptr;
};
extern int hulk_at_004289c0;
extern void __cdecl FUN_002343e0(PlatformCondition*, Factory_23cde0*);
class ConditionFactoryCasterTemplate_23ce00 {
  public:
    virtual bool Cast_0023cc90(void*);
};
void* Make_002343e0(void*, ConditionFactoryCasterTemplate_23ce00*);
} // namespace fn_fe0f08cb
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fe0f08cb {
class TrackFactoryTemplate_23ce30 {
  public:
    TrackFactoryTemplate_23ce30() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C++" __declspec(nothrow) void FUN_0023cce0();
typedef unsigned int u32_23ce70;
extern "C" void* __cdecl Alloc(hulk_uintptr);
extern u32_23ce70 PlatformVtable;
class PlatformCondition_23ce70 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[8];
    void init_00234590(int);
    u8 flags[4];
};
extern int hulk_at_004289ec;
struct ConditionFactoryTemplate_23ceb0 {
    void* m_vptr;
    void base1_dtor_0023cb80();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};


// 0x0023cb40 FUN_0023cb40 (12 B): matches/0x0023cb40.cpp
// sym: ?SetPS2_0023cb40@Obj_23cb40@fn_fe0f08cb@@QAEDE@Z
char Obj_23cb40::SetPS2_0023cb40(unsigned char b) {
    value = b;
    return 1;
}


// 0x0023cb50 FUN_0023cb50 (12 B): matches/0x0023cb50.cpp
// sym: ?SetXBox_0023cb50@C_23cb50@fn_fe0f08cb@@QAE_ND@Z
bool C_23cb50::SetXBox_0023cb50(char c) {
    m = c;
    return true;
}


// 0x0023cb60 FUN_0023cb60 (12 B): matches/0x0023cb60.cpp
// sym: ?SetGameCube_0023cb60@Obj_23cb60@fn_fe0f08cb@@QAEDD@Z
char Obj_23cb60::SetGameCube_0023cb60(char v) {
    mVal = v;
    return 1;
}


// 0x0023cb70 FUN_0023cb70 (12 B): matches/0x0023cb70.cpp
// sym: ?SetWin32_0023cb70@O_23cb70@fn_fe0f08cb@@QAE_ND@Z
bool O_23cb70::SetWin32_0023cb70(char v) {
    ((char*)this)[0xf] = v;
    return true;
}


// 0x0023cb80 FUN_0023cb80 (19 B): matches/0x0023cb80.cpp
// sym: ?FUN_0023cb80@fn_fe0f08cb@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023cb80(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e5c4c), ((char*)&DAT_004e5c50));
}

} // namespace fn_fe0f08cb

// 0x0023cba0 fight::PlatformCondition::vfunc_0 (16 B): matches/0x0023cba0.cpp
// sym: ?vfunc_0@PlatformCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::PlatformCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c4c;
    return p[index];
}


// 0x0023cbf0 fight::PlatformCondition::vfunc_6 (6 B): matches/0x0023cbf0.cpp [wrapped: conflict: fight::Condition; fight::Param; fight::PlatformCondition]
// sym: ?vfunc_6@PlatformCondition@fight@fn_0023cbf0@@UAEEHHH@Z
namespace fn_0023cbf0 {
namespace fight {

class Param {
  public:
    virtual void pfunc_1();
    virtual void pfunc_2();
    virtual void pfunc_4();
};

class Condition {
  public:
    virtual void cfunc_0();
    virtual void cfunc_3();
};

class PlatformCondition : public Condition, public Param {
  public:
    virtual void vfunc_0();
    virtual void vfunc_5();
    virtual unsigned char vfunc_6(int, int, int);
    char mPad[0x0d - 0x08];
    char mFlag;
};

} // namespace fight

unsigned char fight::PlatformCondition::vfunc_6(int, int, int) {
    return mFlag;
}
} // namespace fn_0023cbf0

namespace fn_fe0f08cb {

// 0x0023cc00 fight::PlatformCondition::vfunc_5 (36 B): matches/0x0023cc00.cpp
// sym: ?vfunc_5@PlatformCondition_23cc00@fn_fe0f08cb@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PlatformCondition_23cc00* PlatformCondition_23cc00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00428980;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_fe0f08cb

// 0x0023cc50 fight::ParamBool<fight::PlatformCondition>::vfunc_6 (26 B): matches/0x0023cc50.cpp
// sym: ?vfunc_6@?$ParamBool@VPlatformCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<fight::PlatformCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<fight::PlatformCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<fight::PlatformCondition>*)a)->*(*(bool (fight::ParamBool<fight::PlatformCondition>::**)(int))&this->f_10))(b);
}


// 0x0023cc70 fight::ParamBool<fight::PlatformCondition>::vfunc_2 (11 B): matches/0x0023cc70.cpp
// sym: ?vfunc_2@?$ParamBool@VPlatformCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<fight::PlatformCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0023cc90 fight::ConditionFactoryCasterTemplate<fight::PlatformCondition>::vfunc_0 (36 B): matches/0x0023cc90.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VPlatformCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::PlatformCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023ccc0 fight::ParamBool<fight::PlatformCondition>::vfunc_0 (30 B): matches/0x0023ccc0.cpp
// sym: ??_G?$ParamBool@VPlatformCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<fight::PlatformCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<fight::PlatformCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23ccc0)
#endif


// 0x0023cce0 FUN_0023cce0 (256 B): equivalent/0x0023cce0.cpp [wrapped: conflict: fight::ParamBool]
// sym: _FUN_0023cce0 @cce7cdfb2bb4 @wbac80ea5cc63
namespace fn_0023cce0 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_0023cce0 @ 0x0023cce0


extern "C" void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetPS2_0023cb40();
void __cdecl SetXBox_0023cb50();
void __cdecl SetGameCube_0023cb60();
void __cdecl SetWin32_0023cb70();
namespace fight {
class PlatformCondition;
template<class T> struct ParamBool {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_00234860(const char*);
};
}
void __cdecl FUN_002347b0(int*, fight::ParamBool<fight::PlatformCondition>**, int);
extern "C" void __cdecl FUN_0023cce0() {
 if (DAT_004e5c50 == 0) {
 typedef fight::ParamBool<fight::PlatformCondition> P;
 P* items[4];
 P* p = (P*)FUN_0008d690((int)sizeof(P));
 if(p) { p->FUN_00234860("pS2"); new (p) P; p->callback = SetPS2_0023cb40; }
 items[0]=p;
 p=(P*)FUN_0008d690((int)sizeof(P));
 if(p) { p->FUN_00234860("xBox"); new (p) P; p->callback = SetXBox_0023cb50; }
 items[1]=p;
 p=(P*)FUN_0008d690((int)sizeof(P));
 if(p) { p->FUN_00234860("gameCube"); new (p) P; p->callback = SetGameCube_0023cb60; }
 items[2]=p;
 p=(P*)FUN_0008d690((int)sizeof(P));
 if(p) { p->FUN_00234860("win32"); new (p) P; p->callback = SetWin32_0023cb70; }
 items[3]=p;
 FUN_002347b0(&DAT_004e5c4c,items,4);
 }
 ++DAT_004e5c50;
}
} // namespace fn_0023cce0

namespace fn_fe0f08cb {

// 0x0023cde0 FUN_0023cde0 (27 B): matches/0x0023cde0.cpp
// sym: ?FUN_0023cde0@fn_fe0f08cb@@YAXPAVPlatformCondition@1@@Z
void __cdecl FUN_0023cde0(PlatformCondition* p) {
    Factory_23cde0 f;
    f.vptr = (hulk_intptr)&hulk_at_004289c0;
    FUN_002343e0(p, &f);
}


// 0x0023ce00 FUN_0023ce00 (38 B): matches/0x0023ce00.cpp
// sym: _FUN_0023ce00
extern "C" void FUN_0023ce00(Factory* f, void* p) {
    ConditionFactoryCasterTemplate_23ce00 c;
    void* r = Make_002343e0(p, &c);
    f->Do(r);
}

} // namespace fn_fe0f08cb

// 0x0023ce30 fight::ConditionFactoryCasterTemplate<fight::PlatformCondition>::vfunc_1 (60 B): matches/0x0023ce30.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VPlatformCondition@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<fight::PlatformCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23ce30));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_23ce30* t = new (mem) TrackFactoryTemplate_23ce30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0023cce0();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023ce70 fight::ConditionFactoryTemplate<fight::PlatformCondition>::vfunc_5 (54 B): matches/0x0023ce70.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VPlatformCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::PlatformCondition>::vfunc_5() {
    PlatformCondition_23ce70* p = (PlatformCondition_23ce70*)Alloc(0x10);
    if (p != 0) {
        p->init_00234590(0);
        p->flags[0] = 1;
        p->flags[1] = 1;
        p->flags[2] = 1;
        p->flags[3] = 1;
        *(hulk_uintptr*)p = (hulk_uintptr)&PlatformVtable;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe0f08cb {

// 0x0023ceb0 fight::ConditionFactoryTemplate<fight::PlatformCondition>::vfunc_2 (43 B): matches/0x0023ceb0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_23ceb0@fn_fe0f08cb@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_23ceb0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004289ec;
    base1_dtor_0023cb80();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_fe0f08cb
