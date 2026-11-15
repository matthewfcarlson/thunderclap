// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00136dc0..0x00139940 (kind game, layer game, confidence high), dominant class hulkfight::motion::FallTrack
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter templates constructed for real
#include "decls/data/game/unknown.h"   // (gx3, D18) for the merged registrations
#include "gen/owners.h"   // (gx3, D18) for the merged registrations
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f0de5d41 {
#define TREE_TU_END }
namespace fn_f0de5d41 {} using namespace fn_f0de5d41;
namespace fn_f0de5d41 {
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
namespace fn_f0de5d41 { extern "C" char DAT_00411dc4[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/hulkfight/motion.h"
void* operator new(size_t) HULK_NEW_THROW;   // (gx2, D18) the game's operator new (0x0008d690)
extern "C" void __cdecl FUN_002347b0(void* list, void* params, int count);   // (gx2, D18) a parameter list's set-up
namespace fn_f90de225 { struct Src_133830; } 
namespace fn_f90de225 { struct Vec_1335b0; } 
namespace fn_f90de225 { struct A_1330b0 { bool SetTimeBegin_001330b0(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct A_133600 { char Set(void *); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_1330c0 { char SetTimeEnd_001330c0(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_1330e0 { char SetGroundFixup_001330e0(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_133160 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_133470 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_1334a0 { char Set(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct Obj_1335b0 { char Set(struct fn_f90de225::Vec_1335b0 *); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct T_133830 { bool Set(struct fn_f90de225::Src_133830 const *); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
namespace fn_f90de225 { struct X_133480 { bool Set(int); }; }   // (gx3, D18) setters, as defined in unk_133010.cpp
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f0de5d41 {
class CStageCondition_136de0;
class ParamValue_136de0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136de0 : public ParamValue_136de0 {
  public:
    int pad;
};
class ParamValueInt_136df0 {
  public:
    ParamValueInt_136df0(int);
    virtual void f();
};
class ParamIntConstRange_136df0 : public ParamValueInt_136df0 {
  public:
    ParamIntConstRange_136df0(int, int);
    virtual void f();
    char pad[12];
    int v;
};
class CStageCondition_136e30;
class ParamValue_136e30 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136e30 : public ParamValue_136e30 {
  public:
    int pad;
};
class CStageCondition_136e80;
class ParamValue_136e80 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136e80 : public ParamValue_136e80 {
  public:
    int pad;
};
class CStageCondition_136ed0;
class ParamValue_136ed0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136ed0 : public ParamValue_136ed0 {
  public:
    int pad;
};
class CStageCondition_136f20;
class ParamValue_136f20 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136f20 : public ParamValue_136f20 {
  public:
    int pad;
};
class CStageCondition_136f70;
class ParamValue_136f70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136f70 : public ParamValue_136f70 {
  public:
    int pad;
};
class CStageCondition_136fc0;
class ParamValue_136fc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_136fc0 : public ParamValue_136fc0 {
  public:
    int pad;
};
class CStageCondition_137010;
class ParamValue_137010 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137010 : public ParamValue_137010 {
  public:
    int pad;
};
class CStageCondition_137060;
class ParamValue_137060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137060 : public ParamValue_137060 {
  public:
    int pad;
};
class CStageCondition_1370b0;
class ParamValue_1370b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1370b0 : public ParamValue_1370b0 {
  public:
    int pad;
};
class CStageCondition_137100;
class ParamValue_137100 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137100 : public ParamValue_137100 {
  public:
    int pad;
};
class CStageCondition_137150;
class ParamValue_137150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137150 : public ParamValue_137150 {
  public:
    int pad;
};
class CStageCondition_1371a0;
class ParamValue_1371a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1371a0 : public ParamValue_1371a0 {
  public:
    int pad;
};
class CStageCondition_1371f0;
class ParamValue_1371f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1371f0 : public ParamValue_1371f0 {
  public:
    int pad;
};
class CStageCondition_137240;
class ParamValue_137240 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137240 : public ParamValue_137240 {
  public:
    int pad;
};
class CStageCondition_137290;
class ParamValue_137290 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137290 : public ParamValue_137290 {
  public:
    int pad;
};
class CStageCondition_1372e0;
class ParamValue_1372e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1372e0 : public ParamValue_1372e0 {
  public:
    int pad;
};
class CStageCondition_137330;
class ParamValue_137330 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137330 : public ParamValue_137330 {
  public:
    int pad;
};
class CStageCondition_137380;
class ParamValue_137380 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137380 : public ParamValue_137380 {
  public:
    int pad;
};
class CStageCondition_1373d0;
class ParamValue_1373d0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1373d0 : public ParamValue_1373d0 {
  public:
    int pad;
};
class CStageCondition_137420;
class ParamValue_137420 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137420 : public ParamValue_137420 {
  public:
    int pad;
};
class CStageCondition_137470;
class ParamValue_137470 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_137470 : public ParamValue_137470 {
  public:
    int pad;
};
class CStageCondition_1374c0;
class ParamValue_1374c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1374c0 : public ParamValue_1374c0 {
  public:
    int pad;
};
extern TypeInfo hulk_at_0049850c, hulk_at_004ab9a8;
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_1374e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FlyingDashTrack_1374e0 {};
} }
namespace fn_f0de5d41 {
struct GrappleHoverTrack_137560;
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_137560 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f0de5d41 {
extern char DAT_0049850c;
extern char DAT_004aba50;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_004abb00;
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_1375e0 {
  public:
    virtual bool check(void*) = 0;
    virtual void other() = 0;
};
}
namespace hulkfight { namespace motion {
class FlyingBrakeTrack_1375e0 {};
} }
namespace fn_f0de5d41 {
extern char DAT_004abba8;
class Obj {
  public:
    void Do_002367c0(void*);
    void second_002367c0(int);
};
class TrackFactoryCaster_137660 {
  public:
    virtual bool vfunc_0(Obj*);
    virtual void vfunc_1();
};
int __cdecl FUN_00344e74(Obj*, int, void*, void*, int);
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_1376e0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class AirToGroundTargetTrack_1376e0 {};
} }
namespace fn_f0de5d41 {
extern char DAT_004abc58;
extern char DAT_004abd00;
} // namespace fn_f0de5d41
namespace hulkfight { namespace motion {
class HoverTrack_137760;
} }
namespace fn_f0de5d41 {
struct TrackFactoryCaster_137760 {
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};
extern "C" int __cdecl check(void*, int, void*, void*, int);
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_1377e0 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace motion {
class FallTrack_1377e0 {};
} }
namespace fn_f0de5d41 {
extern char DAT_004abda0;
} // namespace fn_f0de5d41
namespace fight {
class TrackFactoryCaster_137940 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace fn_f0de5d41 {
extern char DAT_004abf00;
} // namespace fn_f0de5d41
namespace hulkfight { namespace motion {
class FlyingAttackTrack_137940 {};
} }
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_f0de5d41 {
extern void* __cdecl FUN_0008d690(unsigned int);
extern bool SetTimeBegin_001330b0(void*, int); /* (unb4) as defined; address taken only */
extern char SetTimeEnd_001330c0(void*, int); /* (unb4) as defined; address taken only */
extern char SetGroundFixup_001330e0(void*, int); /* (unb4) as defined; address taken only */
struct ParamStorage {
    char storage[24];
    void FUN_002348e0(const char*);
};
struct Base_137b60 {
    virtual void slot0();
    char data[12];
    void(__cdecl* callback)();
    int tail;
};
} // namespace fn_f0de5d41
namespace hulkfight { namespace motion {
class GrappleHoverTrack_137b60;
} }
namespace fight {
template <class T> struct ParamFloatConstRange_137b60 : Base_137b60 {
    virtual void slot0();
};
}
namespace fight {
template <class T> struct ParamIntConstRange_137b60 : Base_137b60 {
    virtual void slot0();
};
}
namespace fn_f0de5d41 {
extern int hulk_at_00494b44, hulk_at_00494b60;
class Built_138b80 {
  public:
    int make_00134db0(int, hulk_intptr);
};
extern Built_138b80* __cdecl Allocate_0008d690(int);
extern void* hulk_at_00411d68[];
class Ref_138c10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_138c10 {
  public:
    void* vptr;
};
class HoverAction_138c10 : public Action_138c10 {
  public:
    char pad[0x20 - 4];
    Ref_138c10* m;
    HoverAction_138c10* f2(unsigned char flags);
};
extern int hulk_at_00411d84;
class RefObj_138ca0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class FallAction_138ca0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_138ca0* m2;
    RefObj_138ca0* m3;
    void* vfunc_2(unsigned char flag);
};
struct Maker_138d00 {
    int Init_001353c0(hulkfight::motion::FlyingBrakeTrack*, hulk_intptr);
};
extern int TypeA_138d00;
extern int TypeB_138d00;
extern void* __cdecl Alloc_0008d690(int);
extern int hulk_at_00411da8;
class RefObj_138d50 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class FlyingBrakeAction_138d50 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_138d50* m2;
    RefObj_138d50* m3;
    void* vfunc_2(unsigned char flag);
};
extern int gTypeA_138db0, gTypeB;
struct Result_138db0 {
    int Init_00135470(hulkfight::motion::FlyingAttackTrack*, hulk_intptr);
};
class Ref_138e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_138e00 {
  public:
    void* vptr;
};
class FlyingAttackAction_138e00 : public Action_138e00 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_138e00* m20;
    Ref_138e00* m24;
    Ref_138e00* m28;
    FlyingAttackAction_138e00* f2(unsigned char flags);
};
struct Maker_138e60 {
    int Init_00135be0(hulkfight::motion::FlyingDashTrack*, hulk_intptr);
};
extern int TypeA_138e60;
extern int TypeB_138e60;
extern int hulk_at_00411de0;
class RefObj_138eb0 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class FlyingDashAction_138eb0 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_138eb0* m2;
    RefObj_138eb0* m3;
    void* vfunc_2(unsigned char flag);
};
extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
class AllocObj_138f10 {
  public:
    int init_00135ef0(hulkfight::motion::FlyingAutoTargetTrack*, hulk_intptr);
};
extern void* hulk_at_00411dfc[];
class Ref_138f60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_138f60 {
  public:
    void* vptr;
};
class FlyingAutoTargetAction_138f60 : public Action_138f60 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_138f60* m20;
    Ref_138f60* m24;
    Ref_138f60* m28;
    FlyingAutoTargetAction_138f60* f2(unsigned char flags);
};
typedef unsigned int u32_138fc0;
extern int TypeA_138fc0, TypeB;
struct Params_138fc0 {
    int Init_001364a0(hulkfight::motion::BounceTrack*, void*);
};
extern void* Alloc(hulk_uintptr);
extern int hulk_at_00411e18;
class RefObj_139010 {
  public:
    virtual void vfunc_0();
    virtual void Release();
};
class BounceAction_139010 {
  public:
    void* mVptr;
    char pad[0x18];
    int m1;
    RefObj_139010* m2;
    RefObj_139010* m3;
    void* vfunc_2(unsigned char flag);
};
typedef unsigned int u32_139070;
extern int TypeA_139070, TypeB;
struct Params_139070 {
    int Init_00136850(hulkfight::motion::AirToGroundTargetTrack*, void*);
};
extern void* hulk_at_00411e34[];
class Ref_1390c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1390c0 {
  public:
    void* vptr;
};
class AirToGroundTargetAction_1390c0 : public Action_1390c0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1390c0* m20;
    Ref_1390c0* m24;
    Ref_1390c0* m28;
    AirToGroundTargetAction_1390c0* f2(unsigned char flags);
};
class TrackFactoryCasterTemplate_139240 {
  public:
    virtual bool cast_001374e0(void*);
};
class Manager {
  public:
    void* get_002367c0(void*);
};
extern void* find_00236ac0(const char*, TrackFactoryCasterTemplate_139240*);
class TrackFactoryCasterTemplate_1392a0 {
  public:
    virtual bool Fnf_001375e0(void*);
};
extern void* __cdecl Cast_00236ac0(void*, TrackFactoryCasterTemplate_1392a0*);
class TrackFactoryCasterTemplate_1392d0 {
  public:
    virtual bool cast_00137660(void*);
};
class Recipient {
  public:
    void use_002367c0(void*);
};
extern void* lookup_00236ac0(void*, TrackFactoryCasterTemplate_1392d0*);
class TrackFactoryCasterTemplate_139330 {
  public:
    virtual bool Cast_00137760(void*);
};
class Track {
  public:
    void* Make_002367c0(void*);
};
extern "C" void* GetTrack_00236ac0(void*, TrackFactoryCasterTemplate_139330*);
class TrackFactoryCasterTemplate_139390 {
  public:
    virtual int cast_001378a0(void*);
};
extern "C" int __cdecl first(int, TrackFactoryCasterTemplate_139390*);
extern "C" char DAT_00411bb8[];
class FlyingDashTrack_139430 {
  public:
    hulk_uintptr vt;
    unsigned int pad[2];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    void Init_00236d40();
};
extern int hulk_at_0041225c;
extern "C" void* __cdecl operator_new(unsigned int);
typedef unsigned int u32_139860;
struct Init_139860 {
    hulk_uintptr run_00133d70();
};
extern void* alloc_0008d690(unsigned int);
typedef unsigned int u32_1398f0;
struct CAutoTargetTrack_1398f0 {
    hulk_uintptr initialize_00133e30();
};

} // namespace fn_f0de5d41

// 0x00136dc0 fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_6 (26 B): matches/0x00136dc0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::**)(int))&this->f_10))(b);
}


// 0x00136de0 fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_2 (11 B): matches/0x00136de0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_2() {
    return this->f_10 == 0;
}

namespace fn_f0de5d41 {

// 0x00136df0 FUN_00136df0 (32 B): matches/0x00136df0.cpp
// sym: ??0ParamIntConstRange_136df0@fn_f0de5d41@@QAE@HH@Z
ParamIntConstRange_136df0::ParamIntConstRange_136df0(int a, int b) : ParamValueInt_136df0(a), v(b) {}

} // namespace fn_f0de5d41

// 0x00136e10 fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_6 (26 B): matches/0x00136e10.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::**)(int))&this->f_10))(b);
}


// 0x00136e30 fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_2 (11 B): matches/0x00136e30.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136e60 fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_6 (26 B): matches/0x00136e60.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::**)(int))&this->f_10))(b);
}


// 0x00136e80 fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_2 (11 B): matches/0x00136e80.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136eb0 fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_6 (26 B): matches/0x00136eb0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::**)(int))&this->f_10))(b);
}


// 0x00136ed0 fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_2 (11 B): matches/0x00136ed0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136f00 fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_6 (26 B): matches/0x00136f00.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::**)(int))&this->f_10))(b);
}


// 0x00136f20 fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_2 (11 B): matches/0x00136f20.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136f50 fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_6 (26 B): matches/0x00136f50.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::**)(int))&this->f_10))(b);
}


// 0x00136f70 fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_2 (11 B): matches/0x00136f70.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136fa0 fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::vfunc_6 (26 B): matches/0x00136fa0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::**)(int))&this->f_10))(b);
}


// 0x00136fc0 fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::vfunc_2 (11 B): matches/0x00136fc0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00136ff0 fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::vfunc_6 (26 B): matches/0x00136ff0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::BounceTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::**)(int))&this->f_10))(b);
}


// 0x00137010 fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::vfunc_2 (11 B): matches/0x00137010.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137040 fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_6 (26 B): matches/0x00137040.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x00137060 fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_2 (11 B): matches/0x00137060.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137090 fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_6 (26 B): matches/0x00137090.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x001370b0 fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_2 (11 B): matches/0x001370b0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001370e0 fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::vfunc_6 (26 B): matches/0x001370e0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::**)(int))&this->f_10))(b);
}


// 0x00137100 fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::vfunc_2 (11 B): matches/0x00137100.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137130 fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::vfunc_6 (26 B): matches/0x00137130.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::HoverTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::**)(int))&this->f_10))(b);
}


// 0x00137150 fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::vfunc_2 (11 B): matches/0x00137150.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137180 fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::vfunc_6 (26 B): matches/0x00137180.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FallTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::**)(int))&this->f_10))(b);
}


// 0x001371a0 fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::vfunc_2 (11 B): matches/0x001371a0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001371d0 fight::ParamBool<hulkfight::motion::FallTrack>::vfunc_6 (26 B): matches/0x001371d0.cpp
// sym: ?vfunc_6@?$ParamBool@VFallTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FallTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FallTrack>::**)(int))&this->f_10))(b);
}


// 0x001371f0 fight::ParamBool<hulkfight::motion::FallTrack>::vfunc_2 (11 B): matches/0x001371f0.cpp
// sym: ?vfunc_2@?$ParamBool@VFallTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137220 fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_6 (26 B): matches/0x00137220.cpp
// sym: ?vfunc_6@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FallTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FallTrack>::**)(int))&this->f_10))(b);
}


// 0x00137240 fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_2 (11 B): matches/0x00137240.cpp
// sym: ?vfunc_2@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137270 fight::ParamIntConstRange<hulkfight::motion::FallTrack>::vfunc_6 (26 B): matches/0x00137270.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FallTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FallTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FallTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FallTrack>::**)(int))&this->f_10))(b);
}


// 0x00137290 fight::ParamIntConstRange<hulkfight::motion::FallTrack>::vfunc_2 (11 B): matches/0x00137290.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FallTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001372c0 fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6 (26 B): matches/0x001372c0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x001372e0 fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2 (11 B): matches/0x001372e0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137310 fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6 (26 B): matches/0x00137310.cpp
// sym: ?vfunc_6@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x00137330 fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2 (11 B): matches/0x00137330.cpp
// sym: ?vfunc_2@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137360 fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6 (26 B): matches/0x00137360.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::**)(int))&this->f_10))(b);
}


// 0x00137380 fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2 (11 B): matches/0x00137380.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001373b0 fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_6 (26 B): matches/0x001373b0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x001373d0 fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_2 (11 B): matches/0x001373d0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137400 fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::vfunc_6 (26 B): matches/0x00137400.cpp
// sym: ?vfunc_6@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::motion::FlyingAttackTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x00137420 fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::vfunc_2 (11 B): matches/0x00137420.cpp
// sym: ?vfunc_2@?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x00137450 fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::vfunc_6 (26 B): matches/0x00137450.cpp
// sym: ?vfunc_6@?$ParamBool@VFallTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::motion::FlyingAttackTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x00137470 fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::vfunc_2 (11 B): matches/0x00137470.cpp
// sym: ?vfunc_2@?$ParamBool@VFallTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001374a0 fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_6 (26 B): matches/0x001374a0.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::**)(int))&this->f_10))(b);
}


// 0x001374c0 fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_2 (11 B): matches/0x001374c0.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001374e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_0 (36 B): matches/0x001374e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFlyingDashTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, (void*)(&hulk_at_0049850c), (void*)(&hulk_at_004ab9a8), 0)) != 0;
}


// 0x00137510 fight::ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_0 (30 B): matches/0x00137510.cpp
// sym: ??_G?$ParamFloatConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137530 fight::ParamIntConstRange<hulkfight::motion::FlyingDashTrack>::vfunc_0 (30 B): matches/0x00137530.cpp
// sym: ??_G?$ParamIntConstRange@VFlyingDashTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137560 fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_0 (36 B): matches/0x00137560.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VGrappleHoverTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004aba50, 0) != 0;
}


// 0x00137590 fight::ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_0 (30 B): matches/0x00137590.cpp
// sym: ??_G?$ParamFloatConstRange@VGrappleHoverTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001375b0 fight::ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>::vfunc_0 (30 B): matches/0x001375b0.cpp
// sym: ??_G?$ParamIntConstRange@VGrappleHoverTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001375e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingBrakeTrack>::vfunc_0 (36 B): matches/0x001375e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFlyingBrakeTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingBrakeTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return __RTDynamicCast(p, 0, (void*)(&DAT_0049850c), (void*)(&DAT_004abb00), 0) != 0;
}


// 0x00137610 fight::ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_0 (30 B): matches/0x00137610.cpp
// sym: ??_G?$ParamFloatConstRange@VFlyingBrakeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137630 fight::ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>::vfunc_0 (30 B): matches/0x00137630.cpp
// sym: ??_G?$ParamIntConstRange@VFlyingBrakeTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137660 fight::TrackFactoryCasterTemplate<hulkfight::motion::BounceTrack>::vfunc_0 (36 B): matches/0x00137660.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VBounceTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::BounceTrack>::vfunc_0(void* __p0) { Obj * p = (Obj *)__p0;

    return (int)FUN_00344e74(p, 0, (void*)&DAT_0049850c, (void*)&DAT_004abba8, 0) != 0;
}


// 0x00137690 fight::ParamFloatConstRange<hulkfight::motion::BounceTrack>::vfunc_0 (30 B): matches/0x00137690.cpp
// sym: ??_G?$ParamFloatConstRange@VBounceTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001376b0 fight::ParamIntConstRange<hulkfight::motion::BounceTrack>::vfunc_0 (30 B): matches/0x001376b0.cpp
// sym: ??_G?$ParamIntConstRange@VBounceTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001376e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0 (36 B): matches/0x001376e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VAirToGroundTargetTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004abc58, 0) != 0;
}


// 0x00137710 fight::ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0 (30 B): matches/0x00137710.cpp
// sym: ??_G?$ParamFloatConstRange@VAirToGroundTargetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137730 fight::ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0 (30 B): matches/0x00137730.cpp
// sym: ??_G?$ParamIntConstRange@VAirToGroundTargetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137760 fight::TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_0 (36 B): matches/0x00137760.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VHoverTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HoverTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    return (FUN_00344e74((void*)a, 0, (void*)&DAT_0049850c, (void*)&DAT_004abd00, 0) != 0);
}


// 0x00137790 fight::ParamFloatConstRange<hulkfight::motion::HoverTrack>::vfunc_0 (30 B): matches/0x00137790.cpp
// sym: ??_G?$ParamFloatConstRange@VHoverTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001377b0 fight::ParamIntConstRange<hulkfight::motion::HoverTrack>::vfunc_0 (30 B): matches/0x001377b0.cpp
// sym: ??_G?$ParamIntConstRange@VHoverTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001377e0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FallTrack>::vfunc_0 (36 B): matches/0x001377e0.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFallTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FallTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return check(p, 0, &DAT_0049850c, &DAT_004abda0, 0) != 0;
}


// 0x00137810 fight::ParamFloatConstRange<hulkfight::motion::FallTrack>::vfunc_0 (30 B): matches/0x00137810.cpp
// sym: ??_G?$ParamFloatConstRange@VFallTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137830 fight::ParamBool<hulkfight::motion::FallTrack>::vfunc_0 (30 B): matches/0x00137830.cpp
// sym: ??_G?$ParamBool@VFallTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137850 fight::ParamVector<hulkfight::motion::FallTrack>::vfunc_0 (30 B): matches/0x00137850.cpp
// sym: ??_G?$ParamVector@VFallTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137870 fight::ParamIntConstRange<hulkfight::motion::FallTrack>::vfunc_0 (30 B): matches/0x00137870.cpp
// sym: ??_G?$ParamIntConstRange@VFallTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001378a0 fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0 (36 B): matches/0x001378a0.cpp [wrapped: conflict: a; fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::motion::FlyingAutoTargetTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFlyingAutoTargetTrack@motion@hulkfight@fn_001378a0@@@fight@fn_001378a0@@UAEHPAX@Z
namespace fn_001378a0 {
class Track;
extern "C++" __declspec(nothrow) int __cdecl Find(void*, int, void*, void*, void*);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FlyingAutoTargetTrack {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* hulk_at_004abe50;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0(void* p) {
    return Find(p, 0, &a, &hulk_at_004abe50, 0) != 0;
}
} // namespace fn_001378a0


// 0x001378d0 fight::ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0 (30 B): matches/0x001378d0.cpp
// sym: ??_G?$ParamFloatConstRange@VFlyingAutoTargetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001378f0 fight::ParamVector<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0 (30 B): matches/0x001378f0.cpp
// sym: ??_G?$ParamVector@VFlyingAutoTargetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137910 fight::ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_0 (30 B): matches/0x00137910.cpp
// sym: ??_G?$ParamIntConstRange@VFlyingAutoTargetTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137940 fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_0 (36 B): matches/0x00137940.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FlyingAttackTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004abf00, 0) != 0;
}


// 0x00137970 fight::ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_0 (30 B): matches/0x00137970.cpp
// sym: ??_G?$ParamFloatConstRange@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x00137990 fight::ParamVector<hulkfight::motion::FlyingAttackTrack>::vfunc_0 (30 B): matches/0x00137990.cpp
// sym: ??_G?$ParamVector@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001379b0 fight::ParamBool<hulkfight::motion::FlyingAttackTrack>::vfunc_0 (30 B): matches/0x001379b0.cpp
// sym: ??_G?$ParamBool@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this


// 0x001379d0 fight::ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>::vfunc_0 (30 B): matches/0x001379d0.cpp
// sym: ??_G?$ParamIntConstRange@VFlyingAttackTrack@motion@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (gx2, D18) implicit: the registration that constructs the class emits this

namespace fn_f0de5d41 {

} // namespace fn_f0de5d41

// 0x001379f0 FUN_001379f0 (358 B): matches/0x001379f0.cpp
// sym: ?FUN_001379f0@@YAXXZ
// (gx2, D18) from FallTrack.iso_001379f0.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::FlyingDashTrack>, ParamIntConstRange<hulkfight::motion::FlyingDashTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_001379f0()
{
    if (DAT_004e0ec4 == 0) {
        ::fight::ParamValue* params[6];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingDashTrack>("timeBegin", &owners::Obj_133010::FUN_00133010);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingDashTrack>("timeEnd", &owners::Obj_133020::FUN_00133020);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingDashTrack>("velocity", &owners::Obj_133040::FUN_00133040);
        params[3] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FlyingDashTrack>("priority", &owners::Obj_133060::FUN_00133060);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingDashTrack>("blendInTime", &owners::X_133080::FUN_00133080);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingDashTrack>("blendOutTime", &owners::X_1330a0::FUN_001330a0);
        FUN_002347b0(&DAT_004e0ec0, params, 6);
    }
    DAT_004e0ec4++;
}



// 0x00137b60 FUN_00137b60 (213 B): matches/0x00137b60.cpp
// sym: ?FUN_00137b60@@YAXXZ
// (gx2, D18) rewritten; constructs the real ParamFloatConstRange<hulkfight::motion::GrappleHoverTrack>, ParamIntConstRange<hulkfight::motion::GrappleHoverTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00137b60()
{
    if (DAT_004e0ecc == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleHoverTrack>("timeBegin", &fn_f90de225::A_1330b0::SetTimeBegin_001330b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::GrappleHoverTrack>("timeEnd", &fn_f90de225::Obj_1330c0::SetTimeEnd_001330c0);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::GrappleHoverTrack>("groundFixup", &fn_f90de225::Obj_1330e0::SetGroundFixup_001330e0);
        FUN_002347b0(&DAT_004e0ec8, params, 3);
    }
    DAT_004e0ecc++;
}



// 0x00137c40 FUN_00137c40 (511 B): matches/0x00137c40.cpp
// sym: ?FUN_00137c40@@YAXXZ
// (gx2, D18) from FallTrack.iso_00137c40.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::FlyingBrakeTrack>, ParamIntConstRange<hulkfight::motion::FlyingBrakeTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00137c40()
{
    if (DAT_004e0ed4 == 0) {
        ::fight::ParamValue* params[9];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("timeBegin", &owners::Obj_1330f0::FUN_001330f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("timeEnd", &owners::Obj_133100::FUN_00133100);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("velocityXZ", &owners::Obj_133120::FUN_00133120);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("gravity", &owners::C_133140::FUN_00133140);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("gravityUp", &fn_f90de225::Obj_133160::Set);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("terminalVelocity", &owners::Obj_133180::FUN_00133180);
        params[6] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FlyingBrakeTrack>("priority", &owners::Obj_1331a0::FUN_001331a0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("blendInTime", &owners::Obj_1331c0::FUN_001331c0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingBrakeTrack>("blendOutTime", &owners::Obj_1331e0::FUN_001331e0);
        FUN_002347b0(&DAT_004e0ed0, params, 9);
    }
    DAT_004e0ed4++;
}



// 0x00137e40 FUN_00137e40 (562 B): matches/0x00137e40.cpp
// sym: ?FUN_00137e40@@YAXXZ
// (gx2, D18) from FallTrack.iso_00137e40.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::BounceTrack>, ParamIntConstRange<hulkfight::motion::BounceTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00137e40()
{
    if (DAT_004e0edc == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("timeBegin", &owners::Obj_1331f0::FUN_001331f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("timeEnd", &owners::Obj_133200::FUN_00133200);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("flightTime", &owners::Obj_133220::FUN_00133220);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("upDistance", &owners::Obj_133240::FUN_00133240);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("drift", &owners::X_133260::FUN_00133260);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("minForwardVelocity", &owners::Obj_133280::FUN_00133280);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("turningVelocity", &owners::Thing_1332a0::FUN_001332a0);
        params[7] = new ::fight::ParamIntConstRange< ::hulkfight::motion::BounceTrack>("priority", &owners::Obj_1332d0::FUN_001332d0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("blendInTime", &owners::Obj_1332f0::FUN_001332f0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::BounceTrack>("blendOutTime", &owners::X_133310::FUN_00133310);
        FUN_002347b0(&DAT_004e0ed8, params, 10);
    }
    DAT_004e0edc++;
}



// 0x00138080 FUN_00138080 (613 B): matches/0x00138080.cpp
// sym: ?FUN_00138080@@YAXXZ
// (gx2, D18) from FallTrack.iso_00138080.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::AirToGroundTargetTrack>, ParamIntConstRange<hulkfight::motion::AirToGroundTargetTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_00138080()
{
    if (DAT_004e0ee4 == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("timeBegin", &owners::Obj_133320::FUN_00133320);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("timeEnd", &owners::Obj_133330::FUN_00133330);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("velocityXZMin", &owners::X_133350::FUN_00133350);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("velocityXZMax", &owners::Obj_133370::FUN_00133370);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("accelerationXZ", &owners::Obj_133390::FUN_00133390);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("gravity", &owners::Obj_1333b0::FUN_001333b0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("turningVelocity", &owners::Obj_1333d0::FUN_001333d0);
        params[7] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("targetOffset", &owners::X_133400::FUN_00133400);
        params[8] = new ::fight::ParamIntConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("priority", &owners::Obj_133420::FUN_00133420);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("blendInTime", &owners::Obj_133440::FUN_00133440);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::AirToGroundTargetTrack>("blendOutTime", &owners::Obj_133460::FUN_00133460);
        FUN_002347b0(&DAT_004e0ee0, params, 11);
    }
    DAT_004e0ee4++;
}



// 0x001382f0 FUN_001382f0 (213 B): matches/0x001382f0.cpp
// sym: ?FUN_001382f0@@YAXXZ
// (gx2, D18) from FallTrack.iso_001382f0.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::HoverTrack>, ParamIntConstRange<hulkfight::motion::HoverTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_001382f0()
{
    if (DAT_004e0eec == 0) {
        ::fight::ParamValue* params[3];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HoverTrack>("timeBegin", &fn_f90de225::Obj_133470::Set);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::HoverTrack>("timeEnd", &fn_f90de225::X_133480::Set);
        params[2] = new ::fight::ParamIntConstRange< ::hulkfight::motion::HoverTrack>("groundFixup", &fn_f90de225::Obj_1334a0::Set);
        FUN_002347b0(&DAT_004e0ee8, params, 3);
    }
    DAT_004e0eec++;
}



// 0x001383d0 FUN_001383d0 (766 B): matches/0x001383d0.cpp
// sym: ?FUN_001383d0@@YAXXZ
// (gx2, D18) from FallTrack.iso_001383d0.cpp; constructs the real ParamBool<hulkfight::motion::FallTrack>, ParamFloatConstRange<hulkfight::motion::FallTrack>, ParamIntConstRange<hulkfight::motion::FallTrack>, ParamVector<hulkfight::motion::FallTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_001383d0()
{
    if (DAT_004e0ef4 == 0) {
        ::fight::ParamValue* params[14];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("timeBegin", &owners::Obj_1334b0::FUN_001334b0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("timeEnd", &owners::Obj_1334c0::FUN_001334c0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("turningVelocityMin", &owners::Obj_1334e0::FUN_001334e0);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("turningVelocityMinForwardSpeedCap", &owners::Obj_133510::FUN_00133510);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("turningVelocityMax", &owners::Obj_133530::FUN_00133530);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("turningVelocityMaxForwardSpeedCap", &owners::Obj_133560::FUN_00133560);
        params[6] = new ::fight::ParamBool< ::hulkfight::motion::FallTrack>("useInitialVelocity", &owners::Obj_133580::FUN_00133580);
        params[7] = new ::fight::ParamVector< ::hulkfight::motion::FallTrack>("initialVelocity", &fn_f90de225::Obj_1335b0::Set);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("gravity", &owners::Obj_1335e0::FUN_001335e0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("maxVelocity", &fn_f90de225::A_133600::Set);
        params[10] = new ::fight::ParamBool< ::hulkfight::motion::FallTrack>("limitTurning", &owners::T_133620::FUN_00133620);
        params[11] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FallTrack>("priority", &owners::Obj_133640::FUN_00133640);
        params[12] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("blendInTime", &owners::Obj_133660::FUN_00133660);
        params[13] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FallTrack>("blendOutTime", &owners::O_133680::FUN_00133680);
        FUN_002347b0(&DAT_004e0ef0, params, 14);
    }
    DAT_004e0ef4++;
}



// 0x001386d0 FUN_001386d0 (562 B): matches/0x001386d0.cpp
// sym: ?FUN_001386d0@@YAXXZ
// (gx2, D18) from FallTrack.iso_001386d0.cpp; constructs the real ParamFloatConstRange<hulkfight::motion::FlyingAutoTargetTrack>, ParamIntConstRange<hulkfight::motion::FlyingAutoTargetTrack>, ParamVector<hulkfight::motion::FlyingAutoTargetTrack>,
// whose vftable and scalar deleting destructor it emits
void FUN_001386d0()
{
    if (DAT_004e0efc == 0) {
        ::fight::ParamValue* params[10];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("timeBegin", &owners::X_133690::FUN_00133690);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("timeEnd", &owners::O_1336a0::FUN_001336a0);
        params[2] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("turningVelocity", &owners::Obj_1336c0::FUN_001336c0);
        params[3] = new ::fight::ParamVector< ::hulkfight::motion::FlyingAutoTargetTrack>("offset", &owners::Obj_133700::FUN_00133700);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("velocity", &owners::X_133730::FUN_00133730);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("targetArc", &owners::Obj_133750::FUN_00133750);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("targetDistance", &owners::X_133780::FUN_00133780);
        params[7] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("priority", &owners::C_1337a0::FUN_001337a0);
        params[8] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("blendInTime", &owners::Obj_1337c0::FUN_001337c0);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAutoTargetTrack>("blendOutTime", &owners::Obj_1337e0::FUN_001337e0);
        FUN_002347b0(&DAT_004e0ef8, params, 10);
    }
    DAT_004e0efc++;
}



// 0x00138910 FUN_00138910 (613 B): matches/0x00138910.cpp
// sym: _FUN_00138910
// (gx2, D18) from FallTrack.iso_00138910.cpp; constructs the real ParamBool<hulkfight::motion::FlyingAttackTrack>, ParamFloatConstRange<hulkfight::motion::FlyingAttackTrack>, ParamIntConstRange<hulkfight::motion::FlyingAttackTrack>, ParamVector<hulkfight::motion::FlyingAttackTrack>,
// whose vftable and scalar deleting destructor it emits
extern "C" void FUN_00138910()
{
    if (DAT_004e0f04 == 0) {
        ::fight::ParamValue* params[11];
        params[0] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("timeBegin", &owners::Obj_1337f0::FUN_001337f0);
        params[1] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("timeEnd", &owners::X_133800::FUN_00133800);
        params[2] = new ::fight::ParamVector< ::hulkfight::motion::FlyingAttackTrack>("direction", &fn_f90de225::T_133830::Set);
        params[3] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("velocity", &owners::Obj_133860::FUN_00133860);
        params[4] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("acceleration", &owners::Obj_133880::FUN_00133880);
        params[5] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("heightMin", &owners::Obj_1338a0::FUN_001338a0);
        params[6] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("tracking", &owners::O_1338c0::FUN_001338c0);
        params[7] = new ::fight::ParamBool< ::hulkfight::motion::FlyingAttackTrack>("faceDirection", &owners::X_1338f0::FUN_001338f0);
        params[8] = new ::fight::ParamIntConstRange< ::hulkfight::motion::FlyingAttackTrack>("priority", &owners::X_133910::FUN_00133910);
        params[9] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("blendInTime", &owners::Obj_133930::FUN_00133930);
        params[10] = new ::fight::ParamFloatConstRange< ::hulkfight::motion::FlyingAttackTrack>("blendOutTime", &owners::O_133950::FUN_00133950);
        FUN_002347b0(&DAT_004e0f00, params, 11);
    }
    DAT_004e0f04++;
}



// 0x00138b80 hulkfight::motion::HoverTrack::vfunc_10 (73 B): matches/0x00138b80.cpp
// sym: ?vfunc_10@HoverTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::HoverTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (((int)(hulk_uintptr)__RTDynamicCast((void*)c, 0, (void*)((hulk_intptr)&hulk_at_00494b44), (void*)((hulk_intptr)&hulk_at_00494b60), 0))) {
        Built_138b80* p = Allocate_0008d690(0x24);
        if (p) {
            int m = this->f_14;
            return p->make_00134db0(m, c);
        }
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00138c10 hulkfight::motion::HoverAction::vfunc_2 (57 B): matches/0x00138c10.cpp
// sym: ?f2@HoverAction_138c10@fn_f0de5d41@@QAEPAV12@E@Z
HoverAction_138c10* HoverAction_138c10::f2(unsigned char flags) {
    vptr = hulk_at_00411d68;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_138c10 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00138ca0 hulkfight::motion::FallAction::vfunc_2 (90 B): matches/0x00138ca0.cpp
// sym: ?vfunc_2@FallAction_138ca0@fn_f0de5d41@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* FallAction_138ca0::vfunc_2(unsigned char flag) {
    volatile FallAction_138ca0* self = this;
    self->mVptr = &hulk_at_00411d84;
    RefObj_138ca0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_138ca0* t2 = self->m2;
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

} // namespace fn_f0de5d41

// 0x00138d00 hulkfight::motion::FlyingBrakeTrack::vfunc_10 (70 B): matches/0x00138d00.cpp
// sym: ?vfunc_10@FlyingBrakeTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::FlyingBrakeTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (IsType((void*)c, 0, &TypeA_138d00, &TypeB_138d00, 0)) {
        Maker_138d00* p = (Maker_138d00*)Alloc_0008d690(0x40);
        if (p)
            return p->Init_001353c0(this, c);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00138d50 hulkfight::motion::FlyingBrakeAction::vfunc_2 (90 B): matches/0x00138d50.cpp
// sym: ?vfunc_2@FlyingBrakeAction_138d50@fn_f0de5d41@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* FlyingBrakeAction_138d50::vfunc_2(unsigned char flag) {
    volatile FlyingBrakeAction_138d50* self = this;
    self->mVptr = &hulk_at_00411da8;
    RefObj_138d50* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_138d50* t2 = self->m2;
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

} // namespace fn_f0de5d41

// 0x00138db0 hulkfight::motion::FlyingAttackTrack::vfunc_10 (70 B): matches/0x00138db0.cpp
// sym: ?vfunc_10@FlyingAttackTrack@motion@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::motion::FlyingAttackTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (TypeCheck((void*)c, 0, &gTypeA_138db0, &gTypeB, 0)) {
        Result_138db0* p = (Result_138db0*)Alloc_0008d690(0x3c);
        if (p)
            return p->Init_00135470(this, c);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00138e00 hulkfight::motion::FlyingAttackAction::vfunc_2 (95 B): matches/0x00138e00.cpp
// sym: ?f2@FlyingAttackAction_138e00@fn_f0de5d41@@QAEPAV12@E@Z
FlyingAttackAction_138e00* FlyingAttackAction_138e00::f2(unsigned char flags) {
    vptr = ((void**)DAT_00411dc4);
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_138e00 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f0de5d41

// 0x00138e60 hulkfight::motion::FlyingDashTrack::vfunc_10 (70 B): matches/0x00138e60.cpp
// sym: ?vfunc_10@FlyingDashTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00138d00 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingDashTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (IsType((void*)c, 0, &TypeA_138e60, &TypeB_138e60, 0)) {
        Maker_138e60* p = (Maker_138e60*)Alloc_0008d690(0x40);
        if (p)
            return p->Init_00135be0(this, c);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00138eb0 hulkfight::motion::FlyingDashAction::vfunc_2 (90 B): matches/0x00138eb0.cpp
// sym: ?vfunc_2@FlyingDashAction_138eb0@fn_f0de5d41@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* FlyingDashAction_138eb0::vfunc_2(unsigned char flag) {
    volatile FlyingDashAction_138eb0* self = this;
    self->mVptr = &hulk_at_00411de0;
    RefObj_138eb0* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_138eb0* t2 = self->m2;
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

} // namespace fn_f0de5d41

// 0x00138f10 hulkfight::motion::FlyingAutoTargetTrack::vfunc_10 (70 B): matches/0x00138f10.cpp
// sym: ?vfunc_10@FlyingAutoTargetTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x001134e0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingAutoTargetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_138f10* p = (AllocObj_138f10*)FUN_0008d690(0x2c);
        if (p)
            return p->init_00135ef0(this, c);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00138f60 hulkfight::motion::FlyingAutoTargetAction::vfunc_2 (95 B): matches/0x00138f60.cpp
// sym: ?f2@FlyingAutoTargetAction_138f60@fn_f0de5d41@@QAEPAV12@E@Z
FlyingAutoTargetAction_138f60* FlyingAutoTargetAction_138f60::f2(unsigned char flags) {
    vptr = hulk_at_00411dfc;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_138f60 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f0de5d41

// 0x00138fc0 hulkfight::motion::BounceTrack::vfunc_10 (70 B): matches/0x00138fc0.cpp
// sym: ?vfunc_10@BounceTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BounceTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_138fc0 a = (u32_138fc0)__p0; u32_138fc0 b = (u32_138fc0)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_138fc0, &TypeB, 0)) {
        Params_138fc0* q = (Params_138fc0*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_001364a0(this, p);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x00139010 hulkfight::motion::BounceAction::vfunc_2 (90 B): matches/0x00139010.cpp
// sym: ?vfunc_2@BounceAction_139010@fn_f0de5d41@@QAEPAXE@Z
// Same code shape as 0x00119ea0 (propagated; names are from that function)
void* BounceAction_139010::vfunc_2(unsigned char flag) {
    volatile BounceAction_139010* self = this;
    self->mVptr = &hulk_at_00411e18;
    RefObj_139010* t3 = self->m3;
    if (t3) {
        t3->Release();
        self->m3 = 0;
    }
    RefObj_139010* t2 = self->m2;
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

} // namespace fn_f0de5d41

// 0x00139070 hulkfight::motion::AirToGroundTargetTrack::vfunc_10 (70 B): matches/0x00139070.cpp
// sym: ?vfunc_10@AirToGroundTargetTrack@motion@hulkfight@@UAEHHHH@Z
// Same code shape as 0x00119fb0 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AirToGroundTargetTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_139070 a = (u32_139070)__p0; u32_139070 b = (u32_139070)__p1; void * p = (void *)__p2;

    if (IsKindOf(p, 0, &TypeA_139070, &TypeB, 0)) {
        Params_139070* q = (Params_139070*)Alloc_0008d690(0x34);
        if (q)
            return q->Init_00136850(this, p);
    }
    return 0;
}

namespace fn_f0de5d41 {

// 0x001390c0 hulkfight::motion::AirToGroundTargetAction::vfunc_2 (95 B): matches/0x001390c0.cpp
// sym: ?f2@AirToGroundTargetAction_1390c0@fn_f0de5d41@@QAEPAV12@E@Z
AirToGroundTargetAction_1390c0* AirToGroundTargetAction_1390c0::f2(unsigned char flags) {
    vptr = hulk_at_00411e34;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1390c0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00139240 FUN_00139240 (38 B): matches/0x00139240.cpp
// sym: _FUN_00139240
extern "C" void* FUN_00139240(Manager* m, const char* name) {
    TrackFactoryCasterTemplate_139240 caster;
    return m->get_002367c0(find_00236ac0(name, &caster));
}

} // namespace fn_f0de5d41

// 0x00139270 FUN_00139270 (38 B): matches/0x00139270.cpp [wrapped: conflict: find]
// sym: _FUN_00139270
namespace fn_00139270 {
class TrackFactoryCasterTemplate_139270 {
  public:
    virtual bool Fnf_00137560(void*);
    TrackFactoryCasterTemplate_139270() {}
};
class Owner {
  public:
    void use_002367c0(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl find_00236ac0(void*, TrackFactoryCasterTemplate_139270*);
extern "C" void FUN_00139270(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_139270 caster;
    owner->use_002367c0(find_00236ac0(name, &caster));
}
} // namespace fn_00139270

namespace fn_f0de5d41 {

// 0x001392a0 FUN_001392a0 (38 B): matches/0x001392a0.cpp
// sym: _FUN_001392a0
extern "C" void FUN_001392a0(Obj* obj, void* input) {
    TrackFactoryCasterTemplate_1392a0 caster;
    obj->Do_002367c0(Cast_00236ac0(input, &caster));
}


// 0x001392d0 FUN_001392d0 (38 B): matches/0x001392d0.cpp
// sym: _FUN_001392d0
extern "C" void FUN_001392d0(Recipient* r, void* name) {
    TrackFactoryCasterTemplate_1392d0 caster;
    void* p = lookup_00236ac0(name, &caster);
    r->use_002367c0(p);
}

} // namespace fn_f0de5d41

// 0x00139300 FUN_00139300 (38 B): matches/0x00139300.cpp [wrapped: conflict: Find]
// sym: _FUN_00139300
namespace fn_00139300 {
class TrackFactoryCasterTemplate_139300 {
  public:
    virtual bool Cast_001376e0(void*);
};
extern int __cdecl Find_00236ac0(int, TrackFactoryCasterTemplate_139300*);
class Owner {
  public:
    void Apply_002367c0(int);
};
extern "C" void __cdecl FUN_00139300(Owner* owner, int id) {
    TrackFactoryCasterTemplate_139300 caster;
    int v = Find_00236ac0(id, &caster);
    owner->Apply_002367c0(v);
}
} // namespace fn_00139300

namespace fn_f0de5d41 {

// 0x00139330 FUN_00139330 (38 B): matches/0x00139330.cpp
// sym: _FUN_00139330
extern "C" void* FUN_00139330(Track* t, void* p) {
    TrackFactoryCasterTemplate_139330 c;
    void* r = GetTrack_00236ac0(p, &c);
    return t->Make_002367c0(r);
}

} // namespace fn_f0de5d41

// 0x00139360 FUN_00139360 (38 B): matches/0x00139360.cpp [wrapped: conflict: Find]
// sym: _FUN_00139360
namespace fn_00139360 {
class TrackFactoryCasterTemplate_139360 {
  public:
    virtual bool Dummy_001377e0(void*);
};
class Owner {
  public:
    void Set_002367c0(void*);
};
void* __cdecl Find_00236ac0(const char*, TrackFactoryCasterTemplate_139360*);
extern "C" void FUN_00139360(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_139360 caster;
    owner->Set_002367c0(Find_00236ac0(name, &caster));
}
} // namespace fn_00139360

namespace fn_f0de5d41 {

// 0x00139390 FUN_00139390 (38 B): matches/0x00139390.cpp
// sym: _FUN_00139390
extern "C" void FUN_00139390(Obj* o, int n) {
    TrackFactoryCasterTemplate_139390 c;
    int r = first(n, &c);
    o->second_002367c0(r);
}

} // namespace fn_f0de5d41

// 0x001393c0 FUN_001393c0 (38 B): matches/0x001393c0.cpp [wrapped: conflict: Manager; first]
// sym: _FUN_001393c0
namespace fn_001393c0 {
class TrackFactoryCasterTemplate_1393c0 {
  public:
    virtual bool cast_00137940(void*);
};
class Manager {
  public:
    int get_002367c0(void* p);
};
extern "C++" __declspec(nothrow) void* first_00236ac0(void*, TrackFactoryCasterTemplate_1393c0*);
extern "C" int __cdecl FUN_001393c0(Manager* mgr, void* name) {
    TrackFactoryCasterTemplate_1393c0 caster;
    void* p = first_00236ac0(name, &caster);
    return mgr->get_002367c0(p);
}
} // namespace fn_001393c0


// 0x00139430 fight::TrackFactoryTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_5 (80 B): matches/0x00139430.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFlyingDashTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_5() {
    FlyingDashTrack_139430* p = (FlyingDashTrack_139430*)Alloc_0008d690(0x24);
    if (p) {
        p->Init_00236d40();
        p->vt = ((hulk_intptr)DAT_00411bb8);
        p->a = 0;
        p->b = 0xbf800000;
        p->c = 0x42480000;
        p->d = 0xfffffffb;
        p->e = 0;
        p->f = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0de5d41 {

// 0x00139480 fight::TrackFactoryTemplate<hulkfight::motion::FlyingDashTrack>::vfunc_2 (43 B): matches/0x00139480.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f0de5d41@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041225c;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f0de5d41

// 0x00139540 fight::TrackFactoryTemplate<hulkfight::motion::GrappleHoverTrack>::vfunc_2 (43 B): matches/0x00139540.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00139540@@QAEPAXE@Z
namespace fn_00139540 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412278;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133a00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412278;
    base1_dtor_00133a00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00139540


// 0x00139610 fight::TrackFactoryTemplate<hulkfight::motion::FlyingBrakeTrack>::vfunc_2 (43 B): matches/0x00139610.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00139610@@QAEPAXE@Z
namespace fn_00139610 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412294;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133a90();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412294;
    base1_dtor_00133a90();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00139610


// 0x00139680 fight::TrackFactoryTemplate<hulkfight::motion::BounceTrack>::vfunc_5 (24 B): matches/0x00139680.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VBounceTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x000704b0 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::BounceTrack>::vfunc_5() {
    void* p = operator_new(0x34);
    if (p)
        return (void*)(Construct(p));
    return (void*)(0);
}


// 0x001396a0 fight::TrackFactoryTemplate<hulkfight::motion::BounceTrack>::vfunc_2 (43 B): matches/0x001396a0.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001396a0@@QAEPAXE@Z
namespace fn_001396a0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004122b0;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133b40();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004122b0;
    base1_dtor_00133b40();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001396a0


// 0x00139730 fight::TrackFactoryTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_2 (43 B): matches/0x00139730.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00139730@@QAEPAXE@Z
namespace fn_00139730 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004122cc;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133bf0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004122cc;
    base1_dtor_00133bf0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00139730


// 0x001397f0 fight::TrackFactoryTemplate<hulkfight::motion::HoverTrack>::vfunc_2 (43 B): matches/0x001397f0.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001397f0@@QAEPAXE@Z
namespace fn_001397f0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_004122e8;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133cb0();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004122e8;
    base1_dtor_00133cb0();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001397f0


// 0x00139860 fight::TrackFactoryTemplate<hulkfight::motion::FallTrack>::vfunc_5 (24 B): matches/0x00139860.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFallTrack@motion@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FallTrack>::vfunc_5() {
    void* p = alloc_0008d690(0x4c);
    if (p)
        return (void*)(((Init_139860*)p)->run_00133d70());
    return (void*)(0);
}


// 0x00139880 fight::TrackFactoryTemplate<hulkfight::motion::FallTrack>::vfunc_2 (43 B): matches/0x00139880.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00139880@@QAEPAXE@Z
namespace fn_00139880 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412304;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133d40();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412304;
    base1_dtor_00133d40();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00139880


// 0x001398f0 fight::TrackFactoryTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_5 (24 B): matches/0x001398f0.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VFlyingAutoTargetTrack@motion@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x00075d20 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_5() {
    CAutoTargetTrack_1398f0* p = (CAutoTargetTrack_1398f0*)alloc_0008d690(0x3c);
    if (p)
        return (void*)(p->initialize_00133e30());
    return (void*)(0);
}


// 0x00139910 fight::TrackFactoryTemplate<hulkfight::motion::FlyingAutoTargetTrack>::vfunc_2 (43 B): matches/0x00139910.cpp [wrapped: same definition as 0x00139480 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_00139910@@QAEPAXE@Z
namespace fn_00139910 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_00412320;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_00133e00();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00412320;
    base1_dtor_00133e00();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_00139910

