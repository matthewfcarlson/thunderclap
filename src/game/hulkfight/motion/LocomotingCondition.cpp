// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015b780..0x0015cd10 (kind game, layer game, confidence high), dominant class hulkfight::motion::LocomotingCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7eb5c06 {
#define TREE_TU_END }
namespace fn_f7eb5c06 {} using namespace fn_f7eb5c06;
namespace fn_f7eb5c06 {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/hulkfight/motion.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f7eb5c06 {
extern int* hulk_at_004e1158;
class CCondition_15b780 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1160;
class CCondition_15b7e0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00415970[];
class Str_15b820 {
  public:
    void Init_0027af50();
};
class Condition_15b820 {
  public:
    void* vptr;
    char pad[12];
    Str_15b820 s;
    void Fin_002345b0();
};
class JointPlantedCondition_15b820 : public Condition_15b820 {
  public:
    ~JointPlantedCondition_15b820();
};
extern int* hulk_at_004e1168;
class CCondition_15b860 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1170;
class CCondition_15b8d0 {
  public:
    virtual int vfunc_0(int);
};
class Track_15b8e0 {
  public:
    Track_15b8e0();
    virtual hulk_intptr Fnf_0015b8d0(int);
};
class LocomotingTrack : public Track_15b8e0 {
  public:
    LocomotingTrack();
    char pad[4];
    int a;
    int b;
    float c;
};
struct Param_15b920 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15b920 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e1178;
class CCondition_15b960 {
  public:
    virtual int vfunc_0(int);
};
struct Param_15ba40 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15ba40 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct T_15ba50 {
    char d[8];
    ~T_15ba50() throw();
};
struct Track_15ba50 {
    virtual ~Track_15ba50() throw();
    char p[0x34];
};
struct ClimbLocomotion4Track_15ba50 : Track_15ba50 {
    T_15ba50 m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    ~ClimbLocomotion4Track_15ba50() throw();
};
extern int* hulk_at_004e1180;
class CCondition_15bae0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_15bbd0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15bbd0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Elem_15bbe0 {
    char d[8];
    ~Elem_15bbe0() throw();
};
class Track_15bbe0 {
  public:
    virtual ~Track_15bbe0() throw();
    char p[0x3c];
};
class LocomotionStrafe4Track_15bbe0 : public Track_15bbe0 {
  public:
    virtual ~LocomotionStrafe4Track_15bbe0() throw();
    Elem_15bbe0 a, b, c, d, e, f, g, h, i, j, k;
};
extern int* hulk_at_004e1188;
class CCondition_15bc80 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_00415a40[];
struct Vec2_15bc90 {
    int a, b;
    void FUN_0027af00();
};
struct Track_15bc90 {
    void FUN_00236d40();
};
struct HeliLocomotionTrack : Track_15bc90 {
    void *vptr_unused;
    char pad4[0x0c - 4];
    int f0c;
    float f10;
    float f14, f18;
    int f1c, f20, f24, f28;
    float f2c, f30, f34, f38, f3c;
    int f40;
    float f44;
    int f48, f4c, f50;
    float f54, f58, f5c, f60, f64;
    int f68;
    float f6c;
    int f70, f74, f78, f7c, f80, f84, f88, f8c;
    float f90, f94;
    int f98;
    char pad9c[4];
    Vec2_15bc90 fa0;
    float fa8;
    int fac, fb0, fb4;
    float fb8, fbc, fc0, fc4, fc8, fcc, fd0, fd4;
    HeliLocomotionTrack *ctor();
};
struct Param_15bdd0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15bdd0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Sub_15bde0 {
    void init_0027af50();
};
struct HeliLocomotionTrack_nv_15bde0 {
    void parent_00236d60();
};
extern int* hulk_at_004e1190;
class CCondition_15be20 {
  public:
    virtual int vfunc_0(int);
};
struct Param_15bec0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15bec0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Sub_15bed0 {
    int a;
    int b;
    void Clear_0027af50();
};
class LocomotionSteerTrack {
  public:
    virtual ~LocomotionSteerTrack();
    void BaseDtor_00236d60();
    char pad0[0x24];
    Sub_15bed0 m28;
    Sub_15bed0 m30;
    Sub_15bed0 m38;
    Sub_15bed0 m40;
    char pad1[0x8];
    Sub_15bed0 m50;
};
extern int* hulk_at_004e1198;
class CCondition_15bf30 {
  public:
    virtual int vfunc_0(int);
};
struct Param_15bfc0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15bfc0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_00415aa0[];
struct Sub_15bfd0 {
    char pad[8];
    void init_0027af50();
};
class LocomotionSprintTrack {
  public:
    char a[0x30];
    Sub_15bfd0 s0, s1, s2, s3, s4;
    void finish_00236d60();
};
extern int* hulk_at_004e11a0;
class CCondition_15c030 {
  public:
    virtual int vfunc_0(int);
};
class Track_15c040 {
  public:
    Track_15c040();
    virtual void f();
    char pad[4];
};
class Elem_15c040 {
  public:
    Elem_15c040();
    char pad[8];
};
class GrappleLocomotionSteerTrack_15c040 : public Track_15c040 {
  public:
    GrappleLocomotionSteerTrack_15c040();
    virtual void f();
    char pad1[4];
    int val;
    float speed;
    char pad2[4];
    Elem_15c040 a, b, c, d, e;
    float x, y, z;
};
struct Param_15c0b0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_15c0b0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern "C" char DAT_00415ad0[];
class Base_15c0c0 {
  public:
    void Fin_00236d60();
};
class Member_15c0c0 {
  public:
    void Rel_0027af50();
    int pad[2];
};
class GrappleLocomotionSteerTrack {
  public:
    void Kill();
    hulk_intptr vf;
    char pad[0x14];
    Member_15c0c0 a;
    Member_15c0c0 b;
    Member_15c0c0 c;
    Member_15c0c0 d;
    Member_15c0c0 e;
};
struct A {
    char pad[0x138];
    int n;
};
struct B {
    A* get_00059a30();
};
struct C {
    B* get_000592a0();
};
extern int hulk_at_00494b44, hulk_at_00494b60;
struct Table_15c2a0 {
    char pad0[0x2c];
    int count;
    hulk_freg FUN_00226960(int index, float angle);
};
class RangeSet_15c2a0 {
public:
    char pad0[0x20];
    Table_15c2a0 *table;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;

    void FUN_0015c2a0(float a0, float a1, float a2, float a3, float a4, float a5);
};
struct A_15c460 {
    void* f592_000592a0();
};
struct C_15c460 {
    void f22_00222b50(void*, int, float);
};
struct D {
    void f359_00035980(int);
};
struct B_15c460 {
    C_15c460* f9a40_00059a40();
    D* f9a30_00059a30();
};
struct Data_15c4c0 {
    char pad[0x14];
    int a;
    int b;
    unsigned char c;
};
class C_15c4f0 {
  public:
    char pad[0x28];
    float m;
    hulk_freg f(float x);
};
class Handle_15c540 {
  public:
    void set_00222b50(int, int, int);
    void act_00035980(int);
};
class Ref_15c540 {
  public:
    Handle_15c540* first_00059a40();
    Handle_15c540* second_00059a30();
};
class Manager_15c540 {
  public:
};
class A_15c590 {
    char pad[0x28];

  public:
    float x;
    float y;
    hulk_freg F(float v);
};
class Obj_15c600 {
  public:
    Obj_15c600* first_00059a40();
    Obj_15c600* second_00059a30();
};
class Manager_15c600 {
  public:
};
class Setter_15c600 {
  public:
    void set_00222b50(hulk_intptr, int, int);
};
class Fin {
  public:
    void finish_00035980(int);
};
extern TypeDescriptor DAT_0048d534;
extern TypeDescriptor DAT_004b3b20;
struct Motion_15c670 { char pad0[0x24]; unsigned state; char pad28[0x880]; unsigned a8; unsigned ac; unsigned b0; };
extern void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct List_15c670 { char pad[0x68]; unsigned count;  };
struct Owner_15c670 { List_15c670* FUN_00059a40(); };
struct Link_15c670 { char pad[0x10]; Owner_15c670* owner; };
struct Character_15c670 { char pad[0x338]; Link_15c670* link; };
struct Access_15c670 { Character_15c670* FUN_00059a30(); };
struct Actor_15c670 {  };
struct A_15c740 {
};
struct B_15c740 {
    void* Next_00059a40();
};
struct C_15c740 {
    void Apply_00222b50(void*, int, float);
};
struct Table_15c780 {
    char pad0[0x2c];
    int count;
    hulk_freg FUN_00226960(int index, float angle);
};
class RangeSet_15c780 {
public:
    char pad0[0x20];
    Table_15c780 *table;
    float pad24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;

    void FUN_0015c780(float a0, float a1, float a2, float a3, float a4, float a5);
};
struct Sub_15c940 {
    void setA_00222b50(int a, int b, float c);
    void setB_00222970(int a, int b);
};
struct Child_15c940 {
    void doIt_00035980(int a);
};
struct Obj_15c940 {
    Sub_15c940* make_00059a40();
    Child_15c940* child_00059a30();
};
struct Mgr_15c940 {
};
extern char DAT_00415b00[];
struct Vec3_15c9c0 { float x, y, z; };
struct RefObj_15c9c0 {
    virtual void addRef();
    virtual void release();
};
struct Source_15c9c0 {
    char pad[0x74];
    Vec3_15c9c0 pos;
    Vec3_15c9c0 vel;
};
struct HeliLocomotionAction {
    hulk_intptr vptr;
    char pad04[0x18];
    Source_15c9c0 *f1c;
    RefObj_15c9c0 *f20;
    int f24, f28, f2c, f30, f34, f38;
    Vec3_15c9c0 pos;
    Vec3_15c9c0 vel;
    int f54, f58, f5c, f60, f64;
    void FUN_00232660();
    HeliLocomotionAction *FUN_0015c9c0(Source_15c9c0 *src, RefObj_15c9c0 *target);
};
struct Sub1_15cb40;
struct Sub2_15cb40;
struct Mid_15cb40 {
    Sub1_15cb40* FnA_00059a40();
    Sub2_15cb40* FnB_00059a30();
};
struct Mgr_15cb40 {
};
struct Sub1_15cb40 {
    void Init_00222970(int a, int b);
};
struct Sub2_15cb40 {
    void Fin_00035980(int a);
};
class A_15cb80 {
  public:
};
class B_15cb80 {
  public:
    int second_00059a30();
    void third_00035980(int);
};
struct A_15cbb0 {
    void* x;
};
struct B_15cbb0 {
    void* GetNext_00059a30();
};
struct C_15cbb0 {
    void DoThing_00035980(int);
};
extern void* hulk_at_00415950[];
class Condition_15cce0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class LocomotingCondition_15cce0 : public Condition_15cce0 {
  public:
    LocomotingCondition_15cce0* vfunc_5(signed char flags);
};

} // namespace fn_f7eb5c06

// 0x0015b780 hulkfight::motion::LocomotingCondition::vfunc_0 (16 B): matches/0x0015b780.cpp
// sym: ?vfunc_0@LocomotingCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotingCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1158;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015b7c0 FUN_0015b7c0 (19 B): matches/0x0015b7c0.cpp
// sym: ?FUN_0015b7c0@fn_f7eb5c06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015b7c0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1160), ((char*)&DAT_004e1164));
}

} // namespace fn_f7eb5c06

// 0x0015b7e0 hulkfight::motion::JointPlantedCondition::vfunc_0 (16 B): matches/0x0015b7e0.cpp
// sym: ?vfunc_0@JointPlantedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::JointPlantedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1160;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015b820 FUN_0015b820 (25 B): matches/0x0015b820.cpp
// sym: ??1JointPlantedCondition_15b820@fn_f7eb5c06@@QAE@XZ
JointPlantedCondition_15b820::~JointPlantedCondition_15b820() {
    vptr = hulk_at_00415970;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x0015b840 FUN_0015b840 (19 B): matches/0x0015b840.cpp
// sym: ?FUN_0015b840@fn_f7eb5c06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015b840(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1168), ((char*)&DAT_004e116c));
}

} // namespace fn_f7eb5c06

// 0x0015b860 hulkfight::motion::PhaseCondition::vfunc_0 (16 B): matches/0x0015b860.cpp
// sym: ?vfunc_0@PhaseCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PhaseCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1168;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015b8b0 FUN_0015b8b0 (19 B): matches/0x0015b8b0.cpp
// sym: ?FUN_0015b8b0@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015b8b0() {
    FUN_00234810(((char*)&DAT_004e1170), ((char*)&DAT_004e1174));
}

} // namespace fn_f7eb5c06

// 0x0015b8d0 hulkfight::motion::LocomotingTrack::vfunc_0 (16 B): matches/0x0015b8d0.cpp
// sym: ?vfunc_0@LocomotingTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotingTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1170;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015b8e0 FUN_0015b8e0 (39 B): matches/0x0015b8e0.cpp
// sym: ??0LocomotingTrack@fn_f7eb5c06@@QAE@XZ
LocomotingTrack::LocomotingTrack() {
    b = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f7eb5c06

// 0x0015b910 hulkfight::motion::LocomotingTrack::vfunc_6 (4 B): matches/0x0015b910.cpp
// sym: ?vfunc_6@LocomotingTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::LocomotingTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0015b920 hulkfight::motion::LocomotingTrack::vfunc_7 (7 B): matches/0x0015b920.cpp
// sym: ?vfunc_7@LocomotingTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::LocomotingTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015b940 FUN_0015b940 (19 B): matches/0x0015b940.cpp
// sym: ?FUN_0015b940@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015b940() {
    FUN_00234810(((char*)&DAT_004e1178), ((char*)&DAT_004e117c));
}

} // namespace fn_f7eb5c06

// 0x0015b960 hulkfight::motion::ClimbLocomotion4Track::vfunc_0 (16 B): matches/0x0015b960.cpp
// sym: ?vfunc_0@ClimbLocomotion4Track@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ClimbLocomotion4Track::vfunc_0(int index) {
    int* p = hulk_at_004e1178;
    return p[index];
}


// 0x0015b970 FUN_0015b970 (182 B): equivalent/0x0015b970.cpp [wrapped: conflict: hulkfight::motion::ClimbLocomotion4Track]
// sym: ??0ClimbLocomotion4Track@motion@hulkfight@fn_0015b970@@QAE@XZ @b04c71b3272d @w9a82d9469110
namespace fn_0015b970 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015b970 @ 0x0015b970
struct Name_15b970 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_15b970 {
public:
    virtual hulk_intptr b0_0015b960(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_15b970() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class ClimbLocomotion4Track : public Track_15b970 {
public:
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    virtual bool v3_00236c50(hulk_intptr, int, hulk_intptr);
    int f0c;
    float f10;
    float f14;
    float limits[7];                // 0x18 .. 0x30
    char pad34[4];
    Name_15b970 names[11];                 // 0x38 .. 0x8f
    int f90;
    float f94;
    float f98;

    ClimbLocomotion4Track();
};
} }

hulkfight::motion::ClimbLocomotion4Track::ClimbLocomotion4Track()
{
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    for (int i = 0; i < 7; i++)
        limits[i] = -1.0f;
    for (int i = 0; i < 11; i++)
        names[i].FUN_0027af00();
    f94 = 0.1f;
    f98 = 0.1f;
    f90 = 0;
}
} // namespace fn_0015b970


// 0x0015ba30 hulkfight::motion::ClimbLocomotion4Track::vfunc_6 (4 B): matches/0x0015ba30.cpp
// sym: ?vfunc_6@ClimbLocomotion4Track@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::ClimbLocomotion4Track::vfunc_6() {
    return this->f_0c;
}


// 0x0015ba40 hulkfight::motion::ClimbLocomotion4Track::vfunc_7 (7 B): matches/0x0015ba40.cpp
// sym: ?vfunc_7@ClimbLocomotion4Track@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::ClimbLocomotion4Track::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015ba50 FUN_0015ba50 (111 B): matches/0x0015ba50.cpp
// sym: ??1ClimbLocomotion4Track_15ba50@fn_f7eb5c06@@UAE@XZ
ClimbLocomotion4Track_15ba50::~ClimbLocomotion4Track_15ba50() throw() {}


// 0x0015bac0 FUN_0015bac0 (19 B): matches/0x0015bac0.cpp
// sym: ?FUN_0015bac0@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015bac0() {
    FUN_00234810(((char*)&DAT_004e1180), ((char*)&DAT_004e1184));
}

} // namespace fn_f7eb5c06

// 0x0015bae0 hulkfight::motion::LocomotionStrafe4Track::vfunc_0 (16 B): matches/0x0015bae0.cpp
// sym: ?vfunc_0@LocomotionStrafe4Track@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionStrafe4Track::vfunc_0(int index) {
    int* p = hulk_at_004e1180;
    return p[index];
}


// 0x0015baf0 FUN_0015baf0 (196 B): equivalent/0x0015baf0.cpp [wrapped: conflict: hulkfight::motion::LocomotionStrafe4Track]
// sym: ??0LocomotionStrafe4Track@motion@hulkfight@fn_0015baf0@@QAE@XZ @a9de58bf44f3 @wbaf5eb973164
namespace fn_0015baf0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015baf0 @ 0x0015baf0
struct Name_15baf0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_15baf0 {
public:
    virtual hulk_intptr b0_0015bae0(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_15baf0() { FUN_00236d40(); }
};

namespace hulkfight { namespace motion {
class LocomotionStrafe4Track : public Track_15baf0 {
public:
    virtual bool v1_00234270(void*);
    virtual bool v2_002342b0(int);
    virtual bool v3_00236c50(hulk_intptr, int, hulk_intptr);
    int f0c;
    float f10;
    float f14;
    float f18;
    char f1c;
    char pad1d[3];
    float limits[7];                // 0x20 .. 0x38
    char pad3c[4];
    Name_15baf0 names[11];                 // 0x40 .. 0x97
    int f98;
    float f9c;
    float fa0;

    LocomotionStrafe4Track();
};
} }

hulkfight::motion::LocomotionStrafe4Track::LocomotionStrafe4Track()
{
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    f18 = 6.2831854820251465f;
    f1c = 0;
    for (int i = 0; i < 7; i++)
        limits[i] = -1.0f;
    for (int i = 0; i < 11; i++)
        names[i].FUN_0027af00();
    f9c = 0.1f;
    fa0 = 0.1f;
    f98 = 0;
}
} // namespace fn_0015baf0


// 0x0015bbc0 hulkfight::motion::LocomotionStrafe4Track::vfunc_6 (4 B): matches/0x0015bbc0.cpp
// sym: ?vfunc_6@LocomotionStrafe4Track@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::LocomotionStrafe4Track::vfunc_6() {
    return this->f_0c;
}


// 0x0015bbd0 hulkfight::motion::LocomotionStrafe4Track::vfunc_7 (7 B): matches/0x0015bbd0.cpp
// sym: ?vfunc_7@LocomotionStrafe4Track@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::LocomotionStrafe4Track::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015bbe0 FUN_0015bbe0 (114 B): matches/0x0015bbe0.cpp
// sym: ??1LocomotionStrafe4Track_15bbe0@fn_f7eb5c06@@UAE@XZ
LocomotionStrafe4Track_15bbe0::~LocomotionStrafe4Track_15bbe0() throw() {}


// 0x0015bc60 FUN_0015bc60 (19 B): matches/0x0015bc60.cpp
// sym: ?FUN_0015bc60@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015bc60() {
    FUN_00234810(((char*)&DAT_004e1188), ((char*)&DAT_004e118c));
}

} // namespace fn_f7eb5c06

// 0x0015bc80 hulkfight::motion::HeliLocomotionTrack::vfunc_0 (16 B): matches/0x0015bc80.cpp
// sym: ?vfunc_0@HeliLocomotionTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HeliLocomotionTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1188;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015bc90 FUN_0015bc90 (302 B): equivalent/0x0015bc90.cpp
// sym: ?ctor@HeliLocomotionTrack@fn_f7eb5c06@@QAEPAU12@XZ @6e790dd78289 @w8396adec38d4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015bc90 @ 0x0015bc90
HeliLocomotionTrack *HeliLocomotionTrack::ctor() {
    FUN_00236d40();
    *(volatile hulk_ulongptr *)this = (hulk_ulongptr)DAT_00415a40;
    f0c = 0;
    f14 = 100.0f;
    f18 = 25.0f;
    f1c = 0; f20 = 0; f24 = 0; f28 = 0;
    f2c = -0.5235988f;
    f30 = 0.5235988f;
    f10 = -1.0f;
    f34 = 1.0f;
    f38 = 3.0f;
    f3c = 1.5f;
    f40 = 0;
    f44 = -1.0f;
    f48 = 0;
    f5c = 1.0f;
    f64 = 1.5f;
    f4c = 0; f50 = 0;
    f54 = -0.5235988f;
    f58 = 0.5235988f;
    f60 = 3.0f;
    f68 = 0;
    f6c = -1.0f;
    f70 = 0; f74 = 0; f78 = 0; f7c = 0; f80 = 0; f84 = 0; f88 = 0; f8c = 0;
    f90 = 0.1f; f94 = 0.1f;
    f98 = 0;
    fa0.FUN_0027af00();
    fa8 = 10.0f;
    fac = 0; fb0 = 0; fb4 = 0;
    fb8 = 10.0f; fbc = 10.0f;
    fc0 = 40.0f; fc4 = 5.0f; fc8 = 0.01f;
    fcc = 0.1f; fd0 = 0.1f; fd4 = 0.1f;
    return this;
}

} // namespace fn_f7eb5c06

// 0x0015bdc0 hulkfight::motion::HeliLocomotionTrack::vfunc_6 (4 B): matches/0x0015bdc0.cpp
// sym: ?vfunc_6@HeliLocomotionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HeliLocomotionTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0015bdd0 hulkfight::motion::HeliLocomotionTrack::vfunc_7 (7 B): matches/0x0015bdd0.cpp
// sym: ?vfunc_7@HeliLocomotionTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HeliLocomotionTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0015bde0 FUN_0015bde0 (28 B): matches/0x0015bde0.cpp
// sym: ?FUN_0015bde0@HeliLocomotionTrack@motion@hulkfight@@QAEXXZ
void hulkfight::motion::HeliLocomotionTrack::FUN_0015bde0() {
    Sub_15bde0* p = (Sub_15bde0*)((char*)this + 0xa0);
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_00415a40);
    p->init_0027af50();
    ((HeliLocomotionTrack_nv_15bde0*)this)->parent_00236d60();
}

namespace fn_f7eb5c06 {

// 0x0015be00 FUN_0015be00 (19 B): matches/0x0015be00.cpp
// sym: ?FUN_0015be00@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015be00() {
    FUN_00234810(((char*)&DAT_004e1190), ((char*)&DAT_004e1194));
}

} // namespace fn_f7eb5c06

// 0x0015be20 hulkfight::motion::LocomotionSteerTrack::vfunc_0 (16 B): matches/0x0015be20.cpp
// sym: ?vfunc_0@LocomotionSteerTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionSteerTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1190;
    return p[index];
}


// 0x0015be30 FUN_0015be30 (118 B): equivalent/0x0015be30.cpp [wrapped: conflict: hulkfight::motion::LocomotionSteerTrack]
// sym: ?FUN_0015be30@LocomotionSteerTrack@motion@hulkfight@fn_0015be30@@QAEPAV1234@XZ @6293beaf5262 @w56700328d6ed
inline void *operator new(size_t, void *p) { return p; }
namespace fn_0015be30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015be30 @ 0x0015be30


struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_15be30 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class LocomotionSteerTrack {
public:
    virtual hulk_intptr vfunc_0_0015be20(int);
    int f04;
    int f08;
    int f0c;
    float f10, f14, f18, f1c, f20, f24;
    Name8_15be30 n28, n30, n38, n40;
    char b48;
    char pad49[3];
    int pad4c;
    Name8_15be30 n50;
    int f58;
    float f5c, f60;

    LocomotionSteerTrack() {}
    LocomotionSteerTrack *FUN_0015be30();
};
}
}

hulkfight::motion::LocomotionSteerTrack *hulkfight::motion::LocomotionSteerTrack::FUN_0015be30()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) LocomotionSteerTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = 50.0f;
    f18 = 6.2831855f;
    f1c = -1.0f;
    f20 = -1.0f;
    f24 = -1.0f;
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    b48 = 1;
    n50.FUN_0027af00();
    f5c = 0.1f;
    f60 = 0.1f;
    f58 = 0;
    return this;
}
} // namespace fn_0015be30


// 0x0015beb0 hulkfight::motion::LocomotionSteerTrack::vfunc_6 (4 B): matches/0x0015beb0.cpp
// sym: ?vfunc_6@LocomotionSteerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::LocomotionSteerTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0015bec0 hulkfight::motion::LocomotionSteerTrack::vfunc_7 (7 B): matches/0x0015bec0.cpp
// sym: ?vfunc_7@LocomotionSteerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::LocomotionSteerTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015bed0 FUN_0015bed0 (57 B): matches/0x0015bed0.cpp
// sym: ??1LocomotionSteerTrack@fn_f7eb5c06@@UAE@XZ
LocomotionSteerTrack::~LocomotionSteerTrack() {
    m50.Clear_0027af50();
    m40.Clear_0027af50();
    m38.Clear_0027af50();
    m30.Clear_0027af50();
    m28.Clear_0027af50();
    BaseDtor_00236d60();
}


// 0x0015bf10 FUN_0015bf10 (19 B): matches/0x0015bf10.cpp
// sym: ?FUN_0015bf10@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015bf10() {
    FUN_00234810(((char*)&DAT_004e1198), ((char*)&DAT_004e119c));
}

} // namespace fn_f7eb5c06

// 0x0015bf30 hulkfight::motion::LocomotionSprintTrack::vfunc_0 (16 B): matches/0x0015bf30.cpp
// sym: ?vfunc_0@LocomotionSprintTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionSprintTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1198;
    return p[index];
}


// 0x0015bf40 FUN_0015bf40 (105 B): equivalent/0x0015bf40.cpp [wrapped: conflict: hulkfight::motion::LocomotionSprintTrack]
// sym: ?FUN_0015bf40@LocomotionSprintTrack@motion@hulkfight@fn_0015bf40@@QAEPAV1234@XZ @4e19b539c422 @w782aee0c976a
namespace fn_0015bf40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015bf40 @ 0x0015bf40


struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_15bf40 {
    int lo, hi;
    void FUN_0027af00();
};

namespace hulkfight {
namespace motion {
class LocomotionSprintTrack {
public:
    virtual hulk_intptr vfunc_0_0015bf30(int);
    int f04;
    int f08;
    int f0c;
    float f10, f14;
    int f18, f1c, f20, f24;
    float f28;
    char pad2c[4];
    Name8_15bf40 n30, n38, n40, n48, n50;
    int f58;
    float f5c, f60;

    LocomotionSprintTrack() {}
    LocomotionSprintTrack *FUN_0015bf40();
};
}
}

hulkfight::motion::LocomotionSprintTrack *hulkfight::motion::LocomotionSprintTrack::FUN_0015bf40()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) LocomotionSprintTrack;
    f0c = 0;
    f10 = -1.0f;
    f14 = -1.0f;
    f18 = 0;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = -1.0f;
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    n50.FUN_0027af00();
    f58 = 0;
    f5c = 0.1f;
    f60 = 0.1f;
    return this;
}
} // namespace fn_0015bf40


// 0x0015bfb0 hulkfight::motion::LocomotionSprintTrack::vfunc_6 (4 B): matches/0x0015bfb0.cpp
// sym: ?vfunc_6@LocomotionSprintTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::LocomotionSprintTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0015bfc0 hulkfight::motion::LocomotionSprintTrack::vfunc_7 (7 B): matches/0x0015bfc0.cpp
// sym: ?vfunc_7@LocomotionSprintTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::LocomotionSprintTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015bfd0 FUN_0015bfd0 (57 B): matches/0x0015bfd0.cpp
// sym: ?FUN_0015bfd0@fn_f7eb5c06@@YIXPAVLocomotionSprintTrack@1@PAX@Z
void __fastcall FUN_0015bfd0(LocomotionSprintTrack* self, void*) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00415aa0);
    self->s4.init_0027af50();
    self->s3.init_0027af50();
    self->s2.init_0027af50();
    self->s1.init_0027af50();
    self->s0.init_0027af50();
    self->finish_00236d60();
}


// 0x0015c010 FUN_0015c010 (19 B): matches/0x0015c010.cpp
// sym: ?FUN_0015c010@fn_f7eb5c06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015c010() {
    FUN_00234810(((char*)&DAT_004e11a0), ((char*)&DAT_004e11a4));
}

} // namespace fn_f7eb5c06

// 0x0015c030 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_0 (16 B): matches/0x0015c030.cpp
// sym: ?vfunc_0@GrappleLocomotionSteerTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_0(int index) {
    int* p = hulk_at_004e11a0;
    return p[index];
}

namespace fn_f7eb5c06 {

// 0x0015c040 FUN_0015c040 (90 B): matches/0x0015c040.cpp
// sym: ??0GrappleLocomotionSteerTrack_15c040@fn_f7eb5c06@@QAE@XZ
GrappleLocomotionSteerTrack_15c040::GrappleLocomotionSteerTrack_15c040() : val(0), speed(-1.0f), x(0), y(0.1f), z(0.1f) {}

} // namespace fn_f7eb5c06

// 0x0015c0a0 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_6 (4 B): matches/0x0015c0a0.cpp
// sym: ?vfunc_6@GrappleLocomotionSteerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0015c0b0 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_7 (7 B): matches/0x0015c0b0.cpp
// sym: ?vfunc_7@GrappleLocomotionSteerTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f7eb5c06 {

// 0x0015c0c0 FUN_0015c0c0 (57 B): matches/0x0015c0c0.cpp
// sym: ?Kill@GrappleLocomotionSteerTrack@fn_f7eb5c06@@QAEXXZ
void GrappleLocomotionSteerTrack::Kill() {
    vf = ((hulk_intptr)DAT_00415ad0);
    e.Rel_0027af50();
    d.Rel_0027af50();
    c.Rel_0027af50();
    b.Rel_0027af50();
    a.Rel_0027af50();
    ((Base_15c0c0*)this)->Fin_00236d60();
}

} // namespace fn_f7eb5c06

// 0x0015c240 hulkfight::motion::LocomotingCondition::vfunc_6 (82 B): matches/0x0015c240.cpp
// sym: ?vfunc_6@LocomotingCondition@motion@hulkfight@@UAE_NPAX00@Z
bool hulkfight::motion::LocomotingCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int x = (int)__p0; C * obj = (C *)__p1; int z = (int)__p2;

    if (!__RTDynamicCast(obj, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0))
        return false;
    unsigned char v = obj->get_000592a0()->get_00059a30()->n > 0;
    return (unsigned char)(v - (*(unsigned char *)&this->f_0c)) == 0;
}

namespace fn_f7eb5c06 {

// 0x0015c2a0 FUN_0015c2a0 (439 B): equivalent/0x0015c2a0.cpp
// sym: ?FUN_0015c2a0@RangeSet_15c2a0@fn_f7eb5c06@@QAEXMMMMMM@Z @44d88004b64a @w86c9e1ebaa25
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 18/18)
// FUN_0015c2a0 @ 0x0015c2a0
void RangeSet_15c2a0::FUN_0015c2a0(float a0, float a1, float a2, float a3, float a4, float a5)
{
    if (a3 < 0.0f)
        f34 = table->FUN_00226960(table->count - 1, 0.0f);
    else
        f34 = a3;

    if (a4 < 0.0f) {
        f38 = table->FUN_00226960(table->count - 1, 1.5707964f);
        f40 = table->FUN_00226960(table->count - 1, 4.7123890f);
    } else {
        f38 = a4;
        f40 = a4;
    }

    if (a5 < 0.0f)
        f3c = table->FUN_00226960(table->count - 1, 3.1415927f);
    else
        f3c = a5;

    int n = table->count;
    if (a0 < 0.0f) {
        if (n == 3)
            f24 = table->FUN_00226960(1, 0.0f);
        else
            f24 = table->FUN_00226960(table->count - 1, 0.0f) * 0.5f;
    } else {
        f24 = a0;
    }

    if (a1 < 0.0f) {
        if (n == 3) {
            f28 = table->FUN_00226960(1, 1.5707964f);
            f30 = table->FUN_00226960(1, 4.7123890f);
        } else {
            f28 = table->FUN_00226960(table->count - 1, 1.5707964f) * 0.5f;
            f30 = table->FUN_00226960(table->count - 1, 4.7123890f) * 0.5f;
        }
    } else {
        f28 = a1;
        f30 = a1;
    }

    if (a2 < 0.0f) {
        if (n == 3)
            f2c = table->FUN_00226960(1, 3.1415927f);
        else
            f2c = table->FUN_00226960(table->count - 1, 3.1415927f) * 0.5f;
    } else {
        f2c = a2;
    }
}

} // namespace fn_f7eb5c06

// 0x0015c460 hulkfight::motion::LocomotionStrafeAction::vfunc_4 (73 B): matches/0x0015c460.cpp
// sym: ?vfunc_4@LocomotionStrafeAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::LocomotionStrafeAction::vfunc_4() {
    if ((*(void * *)&this->f_20)) {
        B_15c460* b = (B_15c460*)(*(A_15c460 * *)&this->f_1c)->f592_000592a0();
        C_15c460* c = b->f9a40_00059a40();
        if (c) {
            c->f22_00222b50((*(void * *)&this->f_20), 0, -1.0f);
            D* d = b->f9a30_00059a30();
            if (d)
                d->f359_00035980(0);
        }
    }
}


// 0x0015c4b0 hulkfight::motion::LocomotionStrafe4Action::vfunc_6 (10 B): matches/0x0015c4b0.cpp
// sym: ?vfunc_6@LocomotionStrafe4Action@motion@hulkfight@@UAE_JXZ
__int64 hulkfight::motion::LocomotionStrafe4Action::vfunc_6() {
    unsigned long long result = *(unsigned long long*)((char*)(*(void * *)&this->f_44) + 0x40);
    return (__int64)(result);
}


// 0x0015c4c0 hulkfight::motion::LocomotionStrafe4Action::vfunc_8 (39 B): matches/0x0015c4c0.cpp
// sym: ?vfunc_8@LocomotionStrafe4Action@motion@hulkfight@@UAEXPAX00@Z
void hulkfight::motion::LocomotionStrafe4Action::vfunc_8(void* __p0, void* __p1, void* __p2) { int * p2 = (int *)__p0; int * p3 = (int *)__p1; unsigned char * p4 = (unsigned char *)__p2;

    *p2 = (*(Data_15c4c0 * *)&this->f_44)->a;
    *p3 = (*(Data_15c4c0 * *)&this->f_44)->b;
    *p4 = (*(Data_15c4c0 * *)&this->f_44)->c;
}

namespace fn_f7eb5c06 {

// 0x0015c4f0 FUN_0015c4f0 (69 B): matches/0x0015c4f0.cpp
// sym: ?f@C_15c4f0@fn_f7eb5c06@@QAEMM@Z
// data: kZero_15c4f0 = DAT_003f32e0
hulk_freg C_15c4f0::f(float x) {
    if (x <= DAT_003f32e0)
        return DAT_003f32e0;
    hulk_freg t = x;
    *(int*)&x = 1;
    if (!(t > DAT_003f32e0))
        *(int*)&x = 0;
    return (hulk_freg)*(int*)&x * m;
}

} // namespace fn_f7eb5c06

// 0x0015c540 hulkfight::motion::LocomotionSprintAction::vfunc_4 (73 B): matches/0x0015c540.cpp
// sym: ?vfunc_4@LocomotionSprintAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::LocomotionSprintAction::vfunc_4() {
    if (this->f_24) {
        Ref_15c540* x = ((Ref_15c540 *)((owners::Object_592a0 *)((*(Manager_15c540 * *)&this->f_20)))->FUN_000592a0());
        Handle_15c540* h = x->first_00059a40();
        if (h) {
            h->set_00222b50(this->f_24, 0, (int)0xbf800000);
            h = x->second_00059a30();
            if (h)
                h->act_00035980(0);
        }
    }
}

namespace fn_f7eb5c06 {

// 0x0015c590 FUN_0015c590 (107 B): matches/0x0015c590.cpp
// sym: ?F@A_15c590@fn_f7eb5c06@@QAEMM@Z
hulk_freg A_15c590::F(float v) {
    if (v <= 0.0f)
        return 0.0f;
    if (v <= 0.5f)
        return (v + v) * x;
    if (v < 1.0f) {
        hulk_freg t = v - 0.5f;
        t = t + t;
        return t * y + (1.0f - t) * x;
    }
    return v * y;
}

} // namespace fn_f7eb5c06

// 0x0015c600 hulkfight::motion::LocomotionSteerAction::vfunc_4 (83 B): matches/0x0015c600.cpp
// sym: ?vfunc_4@LocomotionSteerAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::LocomotionSteerAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        Obj_15c600* edi = ((Obj_15c600 *)((owners::Object_592a0 *)(((Manager_15c600*)(*(void * *)&this->f_20))))->FUN_000592a0());
        Obj_15c600* p = edi->first_00059a40();
        if (p) {
            ((Setter_15c600*)p)->set_00222b50((hulk_intptr)(*(void * *)&this->f_24), 0, (int)0xbf800000);
            if (*((char*)(*(void * *)&this->f_1c) + 0x48)) {
                p = edi->second_00059a30();
                if (p)
                    ((Fin*)p)->finish_00035980(0);
            }
        }
    }
}


// 0x0015c660 hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_8 (16 B): matches/0x0015c660.cpp
// sym: ?vfunc_8@GrappleLocomotionSteerTrack@motion@hulkfight@@UAEPAXPAX0@Z
void* hulkfight::motion::GrappleLocomotionSteerTrack::vfunc_8(void* __p0, void* __p1) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1;

    return (void*)(FUN_0005a3f0(b));
}


// 0x0015c670 hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5 (200 B): equivalent/0x0015c670.cpp
// sym: ?vfunc_5@GrappleLocomotionSteerAction@motion@hulkfight@@UAE_NHH@Z @6218bd70aeeb @w238838123978
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5 @ 0x0015c670
bool hulkfight::motion::GrappleLocomotionSteerAction::vfunc_5(hulk_intptr flag, int unused) {
if (flag) return true;
if (!(*(Motion_15c670 * *)&this->f_24)) return false;
Link_15c670* link = ((Access_15c670 *)((owners::Object_592a0 *)((*(Actor_15c670 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30()->link;
if (!link) return false;
List_15c670* list = link->owner->FUN_00059a40();
if (!list) return false;
for (unsigned i=0; i<list->count; ++i) {
Motion_15c670* src = (Motion_15c670*)FUN_00344e74(((void *)((owners::C_222e20 *)list)->FUN_00222e20(i)),0,&DAT_0048d534,&DAT_004b3b20,0);
if (src) {
(*(Motion_15c670 * *)&this->f_24)->state=src->state;
(*(Motion_15c670 * *)&this->f_24)->ac=src->ac;
(*(Motion_15c670 * *)&this->f_24)->a8=src->a8;
(*(Motion_15c670 * *)&this->f_24)->b0=src->b0;
return true;
}
}
return false;
}


// 0x0015c740 hulkfight::motion::GrappleLocomotionSteerAction::vfunc_4 (49 B): matches/0x0015c740.cpp
// sym: ?vfunc_4@GrappleLocomotionSteerAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::GrappleLocomotionSteerAction::vfunc_4() {
    if ((*(void * *)&this->f_24)) {
        void* a = ((void *)((owners::Object_592a0 *)((*(A_15c740 * *)&this->f_20)))->FUN_000592a0());
        void* b = ((B_15c740*)a)->Next_00059a40();
        if (b)
            ((C_15c740*)b)->Apply_00222b50((*(void * *)&this->f_24), 0, -1.0f);
    }
}

namespace fn_f7eb5c06 {

// 0x0015c780 FUN_0015c780 (439 B): equivalent/0x0015c780.cpp
// sym: ?FUN_0015c780@RangeSet_15c780@fn_f7eb5c06@@QAEXMMMMMM@Z @2095cad2181c @w6771851a46d5
// STATUS: equivalent (tools/equiv.py level 3: 3034 inputs, branch coverage 18/18)
// FUN_0015c780 @ 0x0015c780
void RangeSet_15c780::FUN_0015c780(float a0, float a1, float a2, float a3, float a4, float a5)
{
    if (a3 < 0.0f)
        f38 = table->FUN_00226960(table->count - 1, 0.0f);
    else
        f38 = a3;

    if (a4 < 0.0f) {
        f3c = table->FUN_00226960(table->count - 1, 1.5707964f);
        f44 = table->FUN_00226960(table->count - 1, 4.7123890f);
    } else {
        f3c = a4;
        f44 = a4;
    }

    if (a5 < 0.0f)
        f40 = table->FUN_00226960(table->count - 1, 3.1415927f);
    else
        f40 = a5;

    int n = table->count;
    if (a0 < 0.0f) {
        if (n == 3)
            f28 = table->FUN_00226960(1, 0.0f);
        else
            f28 = table->FUN_00226960(table->count - 1, 0.0f) * 0.5f;
    } else {
        f28 = a0;
    }

    if (a1 < 0.0f) {
        if (n == 3) {
            f2c = table->FUN_00226960(1, 1.5707964f);
            f34 = table->FUN_00226960(1, 4.7123890f);
        } else {
            f2c = table->FUN_00226960(table->count - 1, 1.5707964f) * 0.5f;
            f34 = table->FUN_00226960(table->count - 1, 4.7123890f) * 0.5f;
        }
    } else {
        f2c = a1;
        f34 = a1;
    }

    if (a2 < 0.0f) {
        if (n == 3)
            f30 = table->FUN_00226960(1, 3.1415927f);
        else
            f30 = table->FUN_00226960(table->count - 1, 3.1415927f) * 0.5f;
    } else {
        f30 = a2;
    }
}

} // namespace fn_f7eb5c06

// 0x0015c940 hulkfight::motion::ClimbLocomotionAction::vfunc_4 (90 B): matches/0x0015c940.cpp
// sym: ?vfunc_4@ClimbLocomotionAction@motion@hulkfight@@UAEXXZ
 // namespace hulkfight
void hulkfight::motion::ClimbLocomotionAction::vfunc_4() {
    if (this->f_20) {
        Obj_15c940* o = ((Obj_15c940 *)((owners::Object_592a0 *)((*(Mgr_15c940 * *)&this->f_1c)))->FUN_000592a0());
        Sub_15c940* s = o->make_00059a40();
        if (s) {
            s->setA_00222b50(this->f_20, 0, -1.0f);
            s->setB_00222970(this->f_24, 0);
            Child_15c940* c = o->child_00059a30();
            if (c)
                c->doIt_00035980(0);
        }
    }
}


// 0x0015c9a0 hulkfight::motion::ClimbLocomotion4Action::vfunc_6 (10 B): matches/0x0015c9a0.cpp
// sym: ?vfunc_6@ClimbLocomotion4Action@motion@hulkfight@@UAE_JXZ
__int64 hulkfight::motion::ClimbLocomotion4Action::vfunc_6() {
    return (__int64)(*(unsigned long long*)((char*)(*(void * *)&this->f_48) + 0x38));
}


// 0x0015c9b0 hulkfight::motion::ClimbLocomotion4Action::vfunc_8 (15 B): matches/0x0015c9b0.cpp
// sym: ?vfunc_8@ClimbLocomotion4Action@motion@hulkfight@@UAEXPAX@Z
void hulkfight::motion::ClimbLocomotion4Action::vfunc_8(void* __p0) { void * out = (void *)__p0;

    *(void**)out = *(void**)((char*)(*(void * *)&this->f_48) + 0x14);
}

namespace fn_f7eb5c06 {

// 0x0015c9c0 FUN_0015c9c0 (154 B): equivalent/0x0015c9c0.cpp
// sym: ?FUN_0015c9c0@HeliLocomotionAction@fn_f7eb5c06@@QAEPAU12@PAUSource_15c9c0@2@PAURefObj_15c9c0@2@@Z @f309cec0489d @wd2434cb4d25c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0015c9c0 @ 0x0015c9c0
HeliLocomotionAction *HeliLocomotionAction::FUN_0015c9c0(Source_15c9c0 *src, RefObj_15c9c0 *target)
{
    FUN_00232660();
    f1c = src;
    f20 = target;
    vptr = (hulk_intptr)DAT_00415b00;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f38 = 0;
    f54 = 0;
    f58 = 0;
    f5c = 0;
    f60 = 0;
    f64 = 0;
    f20->addRef();
    pos = f1c->pos;
    vel = f1c->vel;
    return this;
}

} // namespace fn_f7eb5c06

// 0x0015ca60 hulkfight::motion::HeliLocomotionAction::vfunc_3 (219 B): equivalent/0x0015ca60.cpp [wrapped: conflict: hulkfight::motion::HeliLocomotionAction]
// sym: ?vfunc_3@HeliLocomotionAction@motion@hulkfight@fn_0015ca60@@UAE_NHH@Z @cdde7acf3cfb @wc9ef7e2a3f3e
namespace fn_0015ca60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::HeliLocomotionAction::vfunc_3 @ 0x0015ca60
struct Controller_15ca60; struct Entity; struct Motion_15ca60; struct Clip;
struct Owner_15ca60 { Controller_15ca60* FUN_000592a0(); };
struct Controller_15ca60 { Entity* FUN_00059a30(); Motion_15ca60* FUN_00059a40(); };
struct Vector { float x,y,z; };
struct Entity { char pad[0x8c]; unsigned int state; hulk_freg FUN_000354c0(); void FUN_00035660(Vector*); void FUN_00035980(int); };
struct Settings_15ca60 { char pad[0x8c]; float x,y,z; };
struct Label_15ca60 { void FUN_0027b040(const char*); };
struct Clip { virtual void vfunc_0(); unsigned int pad; Label_15ca60 label; Clip* FUN_002248f0(int); };
struct Motion_15ca60 { void FUN_00222890(Clip*,float,float,float,float,float,float); };
void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct HeliLocomotionAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Settings_15ca60* settings; Owner_15ca60* owner; Clip* clip; float value; unsigned int state; Vector vector;
};
bool HeliLocomotionAction::vfunc_3(int,int) {
 Controller_15ca60* controller=owner->FUN_000592a0();
 Entity* entity=controller->FUN_00059a30();
 Motion_15ca60* motion=controller->FUN_00059a40();
 if (!motion) return false;
 float x=settings->x, y=settings->y, z=settings->z;
 Clip* created=(Clip*)FUN_00263ea0(0x70);
 if(created) created=created->FUN_002248f0(0);
 clip=created;
 created->label.FUN_0027b040("heliLocomotion");
 clip->vfunc_0();
 motion->FUN_00222890(clip,-1.0f,x,1.0f,y,z,-1.0f);
 value=entity->FUN_000354c0();
 state=entity->state;
 entity->FUN_00035660(&vector);
 entity->FUN_00035980(1);
 return true;
}
}}
} // namespace fn_0015ca60


// 0x0015cb40 hulkfight::motion::HeliLocomotionAction::vfunc_4 (61 B): matches/0x0015cb40.cpp
// sym: ?vfunc_4@HeliLocomotionAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::HeliLocomotionAction::vfunc_4() {
    Mid_15cb40* m = ((Mid_15cb40 *)((owners::Object_592a0 *)((*(Mgr_15cb40 * *)&this->f_20)))->FUN_000592a0());
    Sub1_15cb40* s = m->FnA_00059a40();
    if (s) {
        s->Init_00222970(this->f_24, 0);
        Sub2_15cb40* t = m->FnB_00059a30();
        if (t)
            t->Fin_00035980(0);
    }
}


// 0x0015cb80 hulkfight::motion::LocomotingAction::vfunc_3 (46 B): matches/0x0015cb80.cpp
// sym: ?vfunc_3@LocomotingAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::LocomotingAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    hulk_intptr x;
    if ((*(A_15cb80 * *)&this->f_1c) == 0)
        return false;
    x = ((int)((owners::Object_592a0 *)((*(A_15cb80 * *)&this->f_1c)))->FUN_000592a0());
    if (x == 0)
        return false;
    x = ((B_15cb80*)x)->second_00059a30();
    if (x == 0)
        return false;
    ((B_15cb80*)x)->third_00035980(1);
    return true;
}


// 0x0015cbb0 hulkfight::motion::LocomotingAction::vfunc_4 (37 B): matches/0x0015cbb0.cpp
// sym: ?vfunc_4@LocomotingAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::LocomotingAction::vfunc_4() {
    A_15cbb0* p = (*(A_15cbb0 * *)&this->f_1c);
    if (p) {
        B_15cbb0* q = (B_15cbb0*)((void *)((owners::Object_592a0 *)p)->FUN_000592a0());
        if (q) {
            C_15cbb0* r = (C_15cbb0*)q->GetNext_00059a30();
            if (r)
                r->DoThing_00035980(0);
        }
    }
}

namespace fn_f7eb5c06 {

// 0x0015cce0 hulkfight::motion::LocomotingCondition::vfunc_5 (36 B): matches/0x0015cce0.cpp
// sym: ?vfunc_5@LocomotingCondition_15cce0@fn_f7eb5c06@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
LocomotingCondition_15cce0* LocomotingCondition_15cce0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00415950;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f7eb5c06
