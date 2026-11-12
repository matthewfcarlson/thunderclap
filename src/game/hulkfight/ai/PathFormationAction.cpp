// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011c310..0x0011d860 (kind game, layer game, confidence high), dominant class hulkfight::ai::PathFormationAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbabf3f2 {
#define TREE_TU_END }
namespace fn_fbabf3f2 {} using namespace fn_fbabf3f2;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_fbabf3f2 {
extern int* hulk_at_004e0cb0;
class CCondition_11c310 {
  public:
    virtual int vfunc_0(int);
};
class Track_11c320 {
  public:
    Track_11c320();
    virtual void f();
    char pad[8];
    void* p0;
    float x;
    void* p1;
};
class RoutTrack : public Track_11c320 {
  public:
    RoutTrack();
    virtual void f();
    float a, b, c, d;
    char flag;
    char pad2[3];
    float g, h, i, j;
};
struct Param_11c390 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c390 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0cb8;
class CCondition_11c3d0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_11c440 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c440 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern void* hulk_at_0040f4a0[];
class Track_11c450 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class PathFormationTrack_11c450 : public Track_11c450 {
  public:
    char pad[0x30];
    void* m34;
    ~PathFormationTrack_11c450() throw();
};
extern "C" void __cdecl release(void*);
extern "C" void* __cdecl alloc(hulk_uintptr);
} // namespace fn_fbabf3f2
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_fbabf3f2 {
extern int* hulk_at_004e0cc0;
class CCondition_11c4f0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_11c560 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c560 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0cc8;
class CCondition_11c5a0 {
  public:
    virtual int vfunc_0(int);
};
class Track_11c5b0 {
  public:
    Track_11c5b0();
    virtual void f();
    char pad[8];
};
class StrafeLateralHBTrack : public Track_11c5b0 {
  public:
    StrafeLateralHBTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, g;
    float h;
};
struct Param_11c600 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c600 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0cd0;
class CCondition_11c640 {
  public:
    virtual int vfunc_0(int);
};
class Track_11c650 {
  public:
    Track_11c650();
    virtual void vf();
    char pad[8];
};
class StrafeCircleHBTrack : public Track_11c650 {
  public:
    StrafeCircleHBTrack();
    int a;
    float b;
    int c, d, e, h;
    float g;
    virtual void vf();
};
struct Param_11c6a0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c6a0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0cd8;
class CCondition_11c6e0 {
  public:
    virtual int vfunc_0(int);
};
class Track_11c6f0 {
  public:
    Track_11c6f0();
    virtual void f();
    char data[8];
};
class StrafeCircleTrack : public Track_11c6f0 {
  public:
    StrafeCircleTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g, h;
    char i;
    char pad2[3];
    float j;
    char k;
};
struct Param_11c750 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c750 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ce0;
class CCondition_11c790 {
  public:
    virtual int vfunc_0(int);
};
struct Param_11c830 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_11c830 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class PathTrack;
void __cdecl thunk_0008d340(int);
class Init_11c840 {
  public:
    void init_0027af50();
};
class Base_11c840 {
  public:
    void base_00236d60();
};
class PathTrack {
  public:
    virtual ~PathTrack();
    char pad[0x34];
    int m38;
    char pad3c[4];
};
extern int hulk_at_004a5e68;
typedef unsigned int u32_11c920;
struct Action_11c920 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
struct Info_11c920 {
    char pad[8];
    u32_11c920 x;
    u32_11c920 y;
};
struct Pair_11c920 {
    u32_11c920 x;
    u32_11c920 y;
    Pair_11c920(u32_11c920 a, u32_11c920 b) : x(a), y(b) {}
};
struct Obj_11c920 {
    Info_11c920* FnG_00059a30();
    void P1_00065dd0(Pair_11c920*);
    void P2_00065e20(Pair_11c920*);
};
struct Mid_11c920 {
};
struct Manager_11c920 {
};
struct Root_11c920 {
    char pad[0x1c];
    Manager_11c920* m;
};
extern Root_11c920* hulk_at_004dd700;
Obj_11c920* __stdcall Conv_000678d0();
struct PathFormationAction : Action_11c920 {
    char pad[0x80 - 4];
    Mid_11c920* mid;
    void vfunc_4();
};
struct ObjC_11ca80 {
    char pad[0x10];
    void* next;
};
struct ObjA_11ca80 {
    char pad[0x1c];
    float value;
    ObjC_11ca80* step_00059a30();
};
struct ObjB_11ca80 {
    char pad[0x10];
    void* child;
};
struct Child_11ca80 {
    void run_00059a50(void*);
};
struct Helper_11cac0 {
    void Second_00059a30();
};
class PathLocatorTestCondition {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup_002345b0();
    char pad[8];
    void* m_p;
};
extern void* hulk_at_0040f470[];
class Track_11cc00 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class RoutTrack_11cc00 : public Track_11cc00 {
  public:
    RoutTrack_11cc00* vfunc_5(signed char flags);
};
extern "C" char DAT_0040f4a0[];
struct Track {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};
struct PathFormationTrack : Track {
    char pad[0x30];
    void* member;
    void helper_00236d60();
    virtual PathFormationTrack* vfunc_5(unsigned char);
};
void thunk_FUN_00267090(void*);
void other_free_0008d330(void*);
extern void* hulk_at_0040f4d0[];
class Track_11cc70 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class StrafeRunTrack_11cc70 : public Track_11cc70 {
  public:
    StrafeRunTrack_11cc70* vfunc_5(signed char flags);
};
extern void* hulk_at_0040f500[];
class Track_11cca0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class StrafeLateralHBTrack_11cca0 : public Track_11cca0 {
  public:
    StrafeLateralHBTrack_11cca0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040f530[];
class Track_11ccd0 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class StrafeCircleHBTrack_11ccd0 : public Track_11ccd0 {
  public:
    StrafeCircleHBTrack_11ccd0* vfunc_5(signed char flags);
};
extern void* hulk_at_0040f560[];
class Track_11cd00 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class StrafeCircleTrack_11cd00 : public Track_11cd00 {
  public:
    StrafeCircleTrack_11cd00* vfunc_5(signed char flags);
};
extern void* hulk_at_0040f5c0[];
class Ref_11cdd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11cdd0 {
  public:
    void* vptr;
};
class StrafeRunAction_11cdd0 : public Action_11cdd0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_11cdd0* m20;
    Ref_11cdd0* m24;
    ~StrafeRunAction_11cdd0();
};

} // namespace fn_fbabf3f2

// 0x0011c310 hulkfight::ai::RoutTrack::vfunc_0 (16 B): matches/0x0011c310.cpp
// sym: ?vfunc_0@RoutTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::RoutTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cb0;
    return p[index];
}

namespace fn_fbabf3f2 {

// 0x0011c320 FUN_0011c320 (93 B): matches/0x0011c320.cpp
// sym: ??0RoutTrack@fn_fbabf3f2@@QAE@XZ
RoutTrack::RoutTrack() : Track_11c320() {
    p0 = 0;
    p1 = 0;
    x = -1.0f;
    a = 1.0f;
    b = 15.0f;
    c = 0.5f;
    d = 3.0f;
    flag = 1;
    g = 2.5f;
    h = 5.5f;
    i = 2.0f;
    j = 4.0f;
}

} // namespace fn_fbabf3f2

// 0x0011c380 hulkfight::ai::RoutTrack::vfunc_6 (4 B): matches/0x0011c380.cpp
// sym: ?vfunc_6@RoutTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::RoutTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c390 hulkfight::ai::RoutTrack::vfunc_7 (7 B): matches/0x0011c390.cpp
// sym: ?vfunc_7@RoutTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::RoutTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c3b0 FUN_0011c3b0 (19 B): matches/0x0011c3b0.cpp
// sym: ?FUN_0011c3b0@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c3b0() {
    FUN_00234810(((char*)&DAT_004e0cb8), ((char*)&DAT_004e0cbc));
}

} // namespace fn_fbabf3f2

// 0x0011c3d0 hulkfight::ai::PathFormationTrack::vfunc_0 (16 B): matches/0x0011c3d0.cpp
// sym: ?vfunc_0@PathFormationTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::PathFormationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cb8;
    return p[index];
}


// 0x0011c3e0 FUN_0011c3e0 (69 B): matches/0x0011c3e0.cpp [wrapped: conflict: hulkfight::ai::PathFormationTrack]
// sym: ??0PathFormationTrack@ai@hulkfight@fn_0011c3e0@@QAE@XZ
namespace fn_0011c3e0 {
namespace hulkfight {
namespace ai {
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class PathFormationTrack : public Base {
  public:
    PathFormationTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g;
    int j, k, h, i;
};
PathFormationTrack::PathFormationTrack() : a(0), c(0), d(0), e(0), f1(0), h(0), i(0) {
    b = -1.0f;
    g = 1.0f;
    j = 3;
    k = 10;
}
} // namespace ai
} // namespace hulkfight
} // namespace fn_0011c3e0


// 0x0011c430 hulkfight::ai::PathFormationTrack::vfunc_6 (4 B): matches/0x0011c430.cpp
// sym: ?vfunc_6@PathFormationTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::PathFormationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c440 hulkfight::ai::PathFormationTrack::vfunc_7 (7 B): matches/0x0011c440.cpp
// sym: ?vfunc_7@PathFormationTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::PathFormationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c450 FUN_0011c450 (29 B): matches/0x0011c450.cpp
// sym: ??1PathFormationTrack_11c450@fn_fbabf3f2@@QAE@XZ
PathFormationTrack_11c450::~PathFormationTrack_11c450() throw() {
    void* t = m34;
    vptr = hulk_at_0040f4a0;
    Free(t);
    Fin_00236d60();
}

} // namespace fn_fbabf3f2

// 0x0011c470 FUN_0011c470 (82 B): matches/0x0011c470.cpp
// sym: ?FUN_0011c470@Obj_11c470@owners@@QAEDPBD@Z
char owners::Obj_11c470::FUN_0011c470(const char* s) {
    release(str);
    if (!s) {
        str = (char*)s;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}

namespace fn_fbabf3f2 {

// 0x0011c4d0 FUN_0011c4d0 (19 B): matches/0x0011c4d0.cpp
// sym: ?FUN_0011c4d0@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c4d0() {
    FUN_00234810(((char*)&DAT_004e0cc0), ((char*)&DAT_004e0cc4));
}

} // namespace fn_fbabf3f2

// 0x0011c4f0 hulkfight::ai::StrafeRunTrack::vfunc_0 (16 B): matches/0x0011c4f0.cpp
// sym: ?vfunc_0@StrafeRunTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::StrafeRunTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cc0;
    return p[index];
}


// 0x0011c500 FUN_0011c500 (72 B): matches/0x0011c500.cpp [wrapped: conflict: hulkfight::ai::StrafeRunTrack]
// sym: ??0StrafeRunTrack@ai@hulkfight@fn_0011c500@@QAE@XZ
namespace fn_0011c500 {
namespace hulkfight {
namespace ai {
class TrackBase {
  public:
    TrackBase();
    virtual void f();
    char pad[8];
};
class StrafeRunTrack : public TrackBase {
  public:
    StrafeRunTrack();
    virtual void f();
    int a;
    float b;
    int c, d, e, f1;
    float g, h;
    char i, j;
    char pad2[2];
    int k;
    float l;
};
StrafeRunTrack::StrafeRunTrack() : a(0), c(0), d(0), e(0), f1(0), i(0), j(0), k(0) {
    b = -1.0f;
    g = 40.0f;
    h = 1.5f;
    l = 1.0f;
}
} // namespace ai
} // namespace hulkfight
} // namespace fn_0011c500


// 0x0011c550 hulkfight::ai::StrafeRunTrack::vfunc_6 (4 B): matches/0x0011c550.cpp
// sym: ?vfunc_6@StrafeRunTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::StrafeRunTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c560 hulkfight::ai::StrafeRunTrack::vfunc_7 (7 B): matches/0x0011c560.cpp
// sym: ?vfunc_7@StrafeRunTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::StrafeRunTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c580 FUN_0011c580 (19 B): matches/0x0011c580.cpp
// sym: ?FUN_0011c580@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c580() {
    FUN_00234810(((char*)&DAT_004e0cc8), ((char*)&DAT_004e0ccc));
}

} // namespace fn_fbabf3f2

// 0x0011c5a0 hulkfight::ai::StrafeLateralHBTrack::vfunc_0 (16 B): matches/0x0011c5a0.cpp
// sym: ?vfunc_0@StrafeLateralHBTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::StrafeLateralHBTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cc8;
    return p[index];
}

namespace fn_fbabf3f2 {

// 0x0011c5b0 FUN_0011c5b0 (49 B): matches/0x0011c5b0.cpp
// sym: ??0StrafeLateralHBTrack@fn_fbabf3f2@@QAE@XZ
StrafeLateralHBTrack::StrafeLateralHBTrack() : Track_11c5b0(), a(0), c(0), d(0), e(0), g(0) {
    b = -1.0f;
    h = 1.0f;
}

} // namespace fn_fbabf3f2

// 0x0011c5f0 hulkfight::ai::StrafeLateralHBTrack::vfunc_6 (4 B): matches/0x0011c5f0.cpp
// sym: ?vfunc_6@StrafeLateralHBTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::StrafeLateralHBTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c600 hulkfight::ai::StrafeLateralHBTrack::vfunc_7 (7 B): matches/0x0011c600.cpp
// sym: ?vfunc_7@StrafeLateralHBTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::StrafeLateralHBTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c620 FUN_0011c620 (19 B): matches/0x0011c620.cpp
// sym: ?FUN_0011c620@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c620() {
    FUN_00234810(((char*)&DAT_004e0cd0), ((char*)&DAT_004e0cd4));
}

} // namespace fn_fbabf3f2

// 0x0011c640 hulkfight::ai::StrafeCircleHBTrack::vfunc_0 (16 B): matches/0x0011c640.cpp
// sym: ?vfunc_0@StrafeCircleHBTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::StrafeCircleHBTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cd0;
    return p[index];
}

namespace fn_fbabf3f2 {

// 0x0011c650 FUN_0011c650 (49 B): matches/0x0011c650.cpp
// sym: ??0StrafeCircleHBTrack@fn_fbabf3f2@@QAE@XZ
StrafeCircleHBTrack::StrafeCircleHBTrack() : Track_11c650(), a(0), b(-1.0f), c(0), d(0), e(0), h(0), g(1.0f) {}

} // namespace fn_fbabf3f2

// 0x0011c690 hulkfight::ai::StrafeCircleHBTrack::vfunc_6 (4 B): matches/0x0011c690.cpp
// sym: ?vfunc_6@StrafeCircleHBTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::StrafeCircleHBTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c6a0 hulkfight::ai::StrafeCircleHBTrack::vfunc_7 (7 B): matches/0x0011c6a0.cpp
// sym: ?vfunc_7@StrafeCircleHBTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::StrafeCircleHBTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c6c0 FUN_0011c6c0 (19 B): matches/0x0011c6c0.cpp
// sym: ?FUN_0011c6c0@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c6c0() {
    FUN_00234810(((char*)&DAT_004e0cd8), ((char*)&DAT_004e0cdc));
}

} // namespace fn_fbabf3f2

// 0x0011c6e0 hulkfight::ai::StrafeCircleTrack::vfunc_0 (16 B): matches/0x0011c6e0.cpp
// sym: ?vfunc_0@StrafeCircleTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::StrafeCircleTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0cd8;
    return p[index];
}

namespace fn_fbabf3f2 {

// 0x0011c6f0 FUN_0011c6f0 (69 B): matches/0x0011c6f0.cpp
// sym: ??0StrafeCircleTrack@fn_fbabf3f2@@QAE@XZ
StrafeCircleTrack::StrafeCircleTrack()
    : Track_11c6f0(), a(0), b(-1.0f), c(0), d(0), e(0), f1(0), g(40.0f), h(1.5f), i(0), j(1.0f), k(0) {}

} // namespace fn_fbabf3f2

// 0x0011c740 hulkfight::ai::StrafeCircleTrack::vfunc_6 (4 B): matches/0x0011c740.cpp
// sym: ?vfunc_6@StrafeCircleTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::StrafeCircleTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c750 hulkfight::ai::StrafeCircleTrack::vfunc_7 (7 B): matches/0x0011c750.cpp
// sym: ?vfunc_7@StrafeCircleTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::StrafeCircleTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c770 FUN_0011c770 (19 B): matches/0x0011c770.cpp
// sym: ?FUN_0011c770@fn_fbabf3f2@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c770() {
    FUN_00234810(((char*)&DAT_004e0ce0), ((char*)&DAT_004e0ce4));
}

} // namespace fn_fbabf3f2

// 0x0011c790 hulkfight::ai::PathTrack::vfunc_0 (16 B): matches/0x0011c790.cpp
// sym: ?vfunc_0@PathTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::PathTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ce0;
    return p[index];
}


// 0x0011c7a0 FUN_0011c7a0 (118 B): matches/0x0011c7a0.cpp [wrapped: conflict: hulkfight::ai::PathTrack]
// sym: ??0PathTrack@ai@hulkfight@fn_0011c7a0@@QAE@XZ
namespace fn_0011c7a0 {
// FUN_0011c7a0 @ 0x0011c7a0
struct Name_11c7a0 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_11c7a0 {
public:
    virtual hulk_intptr b0_0011c790(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_11c7a0() { FUN_00236d40(); }
};

namespace hulkfight {
namespace ai {
class PathTrack : public Track_11c7a0 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_0011cd30(int);
    virtual void v5_0011c820();
    virtual void vfunc_6_0011c830();
    virtual void* vfunc_7_00236ba0(void*, void*);

    int f0c;
    float f10;
    int f14, f18, f1c, f20;
    float f24;
    int f28, f2c, f30, f34, f38;
    char f3c, f3d;
    char pad3e[2];
    Name_11c7a0 name;
    char f48, f49;
    char pad4a[2];
    int f4c;
    float f50, f54, f58, f5c;

    PathTrack();
};
}
}

hulkfight::ai::PathTrack::PathTrack() {
    f0c = 0;
    f10 = -1.0f;
    f14 = 0; f18 = 0; f1c = 0; f20 = 0;
    f24 = 1.0f;
    f28 = 0; f2c = 0; f30 = 0; f34 = 0; f38 = 0;
    f3c = 0;
    f3d = 0;
    name.FUN_0027af00();
    f49 = 0;
    f4c = 0;
    f48 = 1;
    f50 = 2.5f;
    f54 = 5.5f;
    f58 = 2.0f;
    f5c = 4.0f;
}
} // namespace fn_0011c7a0


// 0x0011c820 hulkfight::ai::PathTrack::vfunc_6 (4 B): matches/0x0011c820.cpp
// sym: ?vfunc_6@PathTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::PathTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0011c830 hulkfight::ai::PathTrack::vfunc_7 (7 B): matches/0x0011c830.cpp
// sym: ?vfunc_7@PathTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::PathTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fbabf3f2 {

// 0x0011c840 FUN_0011c840 (37 B): matches/0x0011c840.cpp
// sym: ??1PathTrack@fn_fbabf3f2@@UAE@XZ
PathTrack::~PathTrack() {
    thunk_0008d340(m38);
    ((Init_11c840*)((char*)this + 0x40))->init_0027af50();
    ((Base_11c840*)this)->base_00236d60();
}

} // namespace fn_fbabf3f2

// 0x0011c900 hulkfight::ai::StrafeRunAction::vfunc_3 (29 B): matches/0x0011c900.cpp
// sym: ?vfunc_3@StrafeRunAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::StrafeRunAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    int value = hulk_at_004a5e68;
    if (value > 8)
        value = 1;
    this->f_2c = value;
    hulk_at_004a5e68 = value + 1;
    return true;
}

namespace fn_fbabf3f2 {

// 0x0011c920 hulkfight::ai::PathFormationAction::vfunc_4 (116 B): matches/0x0011c920.cpp
// sym: ?vfunc_4@PathFormationAction@fn_fbabf3f2@@QAEXXZ
void PathFormationAction::vfunc_4() {
    if (mid) {
        Info_11c920* i = ((Obj_11c920 *)((owners::Object_592a0 *)mid)->FUN_000592a0())->FnG_00059a30();
        Conv_000678d0()->P1_00065dd0(&Pair_11c920(i->x, i->y));
        Conv_000678d0()->P2_00065e20(&Pair_11c920(i->x, i->y));
        ((owners::Ring_1ae150 *)(hulk_at_004dd700->m))->FUN_001ae150((hulk_intptr)((char*)this + 0x1c));
    }
}

} // namespace fn_fbabf3f2

// 0x0011ca80 hulkfight::ai::RoutAction::vfunc_3 (54 B): matches/0x0011ca80.cpp
// sym: ?vfunc_3@RoutAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::RoutAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    ObjA_11ca80* x = ((ObjA_11ca80 *)((owners::Object_592a0 *)((*(ObjB_11ca80 * *)&this->f_38)))->FUN_000592a0());
    ObjC_11ca80* y = x->step_00059a30();
    (*(void * *)&this->f_5c) = y;
    float f = (*(ObjA_11ca80 * *)&this->f_34)->value;
    this->f_70 = f * f;
    ((Child_11ca80*)y->next)->run_00059a50((char*)this + 0x28);
    return true;
}


// 0x0011cac0 hulkfight::ai::RoutAction::vfunc_4 (20 B): matches/0x0011cac0.cpp
// sym: ?vfunc_4@RoutAction@ai@hulkfight@@UAEXXZ
void hulkfight::ai::RoutAction::vfunc_4() {
    if ((*(Helper_11cac0 * *)&this->f_38)) {
        Helper_11cac0* h = (*(Helper_11cac0 * *)&this->f_38);
        h = (Helper_11cac0*)((owners::Object_592a0 *)h)->FUN_000592a0();
        h->Second_00059a30();
    }
}

namespace fn_fbabf3f2 {

// 0x0011cbc0 hulkfight::ai::PathLocatorTestCondition::vfunc_5 (50 B): matches/0x0011cbc0.cpp
// sym: ?vfunc_5@PathLocatorTestCondition@fn_fbabf3f2@@QAEPAXE@Z
void* PathLocatorTestCondition::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &PathLocatorTestCondition_vftable;
    ai_free(m_p);
    Cleanup_002345b0();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}


// 0x0011cc00 hulkfight::ai::RoutTrack::vfunc_5 (36 B): matches/0x0011cc00.cpp
// sym: ?vfunc_5@RoutTrack_11cc00@fn_fbabf3f2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
RoutTrack_11cc00* RoutTrack_11cc00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040f470;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0011cc30 hulkfight::ai::PathFormationTrack::vfunc_5 (50 B): matches/0x0011cc30.cpp
// sym: ?vfunc_5@PathFormationTrack@fn_fbabf3f2@@UAEPAU12@E@Z
PathFormationTrack* PathFormationTrack::vfunc_5(unsigned char flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_0040f4a0);
    thunk_FUN_00267090(member);
    helper_00236d60();
    if (flag & 1)
        other_free_0008d330(this);
    return this;
}


// 0x0011cc70 hulkfight::ai::StrafeRunTrack::vfunc_5 (36 B): matches/0x0011cc70.cpp
// sym: ?vfunc_5@StrafeRunTrack_11cc70@fn_fbabf3f2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
StrafeRunTrack_11cc70* StrafeRunTrack_11cc70::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040f4d0;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0011cca0 hulkfight::ai::StrafeLateralHBTrack::vfunc_5 (36 B): matches/0x0011cca0.cpp
// sym: ?vfunc_5@StrafeLateralHBTrack_11cca0@fn_fbabf3f2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
StrafeLateralHBTrack_11cca0* StrafeLateralHBTrack_11cca0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040f500;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0011ccd0 hulkfight::ai::StrafeCircleHBTrack::vfunc_5 (36 B): matches/0x0011ccd0.cpp
// sym: ?vfunc_5@StrafeCircleHBTrack_11ccd0@fn_fbabf3f2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
StrafeCircleHBTrack_11ccd0* StrafeCircleHBTrack_11ccd0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040f530;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x0011cd00 hulkfight::ai::StrafeCircleTrack::vfunc_5 (36 B): matches/0x0011cd00.cpp
// sym: ?vfunc_5@StrafeCircleTrack_11cd00@fn_fbabf3f2@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
StrafeCircleTrack_11cd00* StrafeCircleTrack_11cd00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040f560;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fbabf3f2

// 0x0011cd30 hulkfight::ai::PathTrack::vfunc_5 (58 B): matches/0x0011cd30.cpp [wrapped: conflict: PathTrack]
// sym: ?vfunc_5@PathTrack@fn_0011cd30@@UAEPAV12@H@Z
namespace fn_0011cd30 {
extern "C++" __declspec(nothrow) void __cdecl opdel1_0008d340(void*);
extern "C++" __declspec(nothrow) void __cdecl opdel2_0008d330(void*);
extern const char hulk_at_0040f590[];

class M40 {
  public:
    ~M40();
};

class PathTrack {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual PathTrack* vfunc_5(int flag);
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    void BaseDtor_00236d60();
};

PathTrack* PathTrack::vfunc_5(int flag) {
    *(void**)this = (void*)hulk_at_0040f590;
    opdel1_0008d340(*(void**)((char*)this + 0x38));
    ((M40*)((char*)this + 0x40))->~M40();
    this->BaseDtor_00236d60();
    if (flag & 1) {
        opdel2_0008d330((void*)this);
    }
    return this;
}
} // namespace fn_0011cd30


// 0x0011cd70 FUN_0011cd70 (81 B): equivalent/0x0011cd70.cpp [wrapped: conflict: hulkfight::ai::StrafeRunAction]
// sym: ??0StrafeRunAction@ai@hulkfight@fn_0011cd70@@QAE@PAXPAURefObject@123@@Z @b4f59cbfb603 @wab25e1bd325d
namespace fn_0011cd70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0011cd70 @ 0x0011cd70
namespace hulkfight { namespace ai {
struct RefObject {
    virtual void AddRef();
    virtual void Release();
};
struct FUN_00232660 {
    FUN_00232660();
    virtual void method0();
    char padding[0x18];
};
struct StrafeRunAction : FUN_00232660 {
    void* action;
    RefObject* ref;
    int field24;
    int field28;
    int field2c;
    StrafeRunAction(void* a, RefObject* r);
    virtual void method0();
};
StrafeRunAction::StrafeRunAction(void* a, RefObject* r) : FUN_00232660() {
    action = a;
    ref = 0;
    field24 = 0;
    field28 = 1;
    field2c = 0;
    if (r) r->AddRef();
    if (ref) ref->Release();
    ref = r;
}
}}
} // namespace fn_0011cd70

namespace fn_fbabf3f2 {

// 0x0011cdd0 FUN_0011cdd0 (69 B): matches/0x0011cdd0.cpp
// sym: ??1StrafeRunAction_11cdd0@fn_fbabf3f2@@QAE@XZ
StrafeRunAction_11cdd0::~StrafeRunAction_11cdd0() {
    vptr = hulk_at_0040f5c0;
    _ReadWriteBarrier();
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
    ((fight::Action *)(Action_11cdd0 *)this)->FUN_002326a0();
}

} // namespace fn_fbabf3f2

// 0x0011ce20 hulkfight::ai::StrafeRunAction::vfunc_5 (1169 B): equivalent/0x0011ce20.cpp [wrapped: conflict: hulkfight::ai::StrafeRunAction]
// sym: ?vfunc_5@StrafeRunAction@ai@hulkfight@fn_0011ce20@@UAE_NTSlot_11ce20@4@0@Z @1a197f42245b @w3525a6bec9e5
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0011ce20 {
// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 74/74)
// hulkfight::ai::StrafeRunAction::vfunc_5 @ 0x0011ce20
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double pow(double, double);
#endif


struct Vec3_11ce20 {
    float x, y, z;
    float FUN_0022d110();
};

union Slot_11ce20 {
    int i;
    float f;
    unsigned int u;
};

class RefCounted_11ce20 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Mount_11ce20 {
    char pad0[0x18];
    bool FUN_00059a50(Vec3_11ce20 *out);
};

struct Target_11ce20 : RefCounted_11ce20 {
    char pad04[0x3c];
    Vec3_11ce20 pos;
};

struct Player_11ce20 {
    char pad0[0x10];
    Mount_11ce20 *mount;
};

struct Hub20_11ce20 {
    char pad0[0x124];
    Player_11ce20 *player;
};

struct World {
    char pad0[0x20];
    Hub20_11ce20 *hub;
};

struct Stats_11ce20 {
    char pad0[0x10];
    Mount_11ce20 *mount;
    char pad14[0x328 - 0x14];
    Target_11ce20 *target;
    char pad32c[0x2064 - 0x32c];
    Vec3_11ce20 aim;
    float f2070;
    Vec3_11ce20 dir;
    bool FUN_00035660(Vec3_11ce20 *out);
};

void *__fastcall FUN_000592a0(void *owner);
Stats_11ce20 *__fastcall FUN_00059a30(void *x);
extern "C" float FUN_00224f10(Vec3_11ce20 *v);
extern "C++" __declspec(nothrow) float FUN_00224fc0(float from, float to);
extern "C" void FUN_00224d70(float angle, Vec3_11ce20 *v);


struct Tuning_11ce20 {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    char b2c;
    char b2d;
    char pad2e[2];
    float f30;
    float f34;
};

namespace hulkfight {
namespace ai {
class StrafeRunAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(Slot_11ce20 a0, Slot_11ce20 a1);
    char pad04[0x18];
    Tuning_11ce20 *tuning;
    void *owner;
    RefCounted_11ce20 *held;
    int f28;
    int mode;
};

bool StrafeRunAction::vfunc_5(Slot_11ce20 a0, Slot_11ce20 a1)
{
    if (a0.i != 0)
        return true;
    if (owner == 0)
        return false;

    Stats_11ce20 *stats = FUN_00059a30(FUN_000592a0(owner));
    Target_11ce20 *target = stats->target;
    if (target == 0) {
        target = (Target_11ce20 *)held;
        if (target == 0)
            return true;
    }
    target->AddRef();
    if (held != 0)
        held->Release();
    held = target;

    struct Frame {
        float angle;
        float dist;
        float step;
        float t18;
        float t1c;
        float dy;
        Vec3_11ce20 w;
        Vec3_11ce20 d;
        Vec3_11ce20 fwd;
        Vec3_11ce20 pos;
        Vec3_11ce20 q;
    } fr;

    fr.pos = target->pos;
    Tuning_11ce20 *tn = tuning;
    if (tn->b2d) {
        int m = mode;
        if (m == 1 || m == 2 || m == 8)
            fr.pos.x = fr.pos.x + tn->f30;
        if (m == 6 || m == 5 || m == 4)
            fr.pos.x = fr.pos.x - tn->f30;
        if (m == 2 || m == 3 || m == 4)
            fr.pos.z = fr.pos.z + tn->f30;
        if (m == 8 || m == 7 || m == 6)
            fr.pos.z = fr.pos.z - tn->f30;
    }
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    stats->mount->FUN_00059a50(&fr.q);

    fr.d.x = fr.pos.x - fr.q.x;
    fr.d.y = 0.0f;
    fr.d.z = fr.pos.z - fr.q.z;
    fr.dy = -(fr.pos.y - fr.q.y);
    fr.dist = fr.d.FUN_0022d110();

    fr.fwd.x = 0.0f;
    fr.fwd.y = 0.0f;
    fr.fwd.z = 0.0f;
    stats->FUN_00035660(&fr.fwd);
    fr.fwd.y = 0.0f;
    fr.fwd.FUN_0022d110();

    tn = tuning;
    a0.f = tn->f14;
    fr.t1c = fr.fwd.z * fr.d.z + fr.fwd.x * fr.d.x + fr.fwd.y * fr.d.y;
    if (fr.t1c < 0.0f) {
        if (f28 > 0)
            f28 = -f28;
        if (fr.dist > a0.f) {
            f28 = 1;
            fr.w = fr.d;
        } else {
            fr.w = fr.fwd;
        }
    } else {
        if (f28 >= 0) {
            fr.w = fr.d;
        } else if (fr.dist > a0.f) {
            f28 = 1;
            fr.w = fr.d;
        } else {
            fr.w = fr.fwd;
        }
    }

    fr.step = tn->f18;
    if (fr.step <= 0.0f) {
        stats->aim = fr.w;
    } else {
        fr.angle = FUN_00224f10(&fr.fwd);
        fr.t18 = FUN_00224f10(&fr.w);
        double diff = FUN_00224fc0(fr.angle, fr.t18);
        fr.step = fr.step * a1.f;
        a1.f = (float)diff;
        a1.u &= 0x7fffffff;
        if (a1.f <= fr.step) {
            fr.angle = fr.t18;
        } else if (diff < 0.0f) {
            fr.angle = fr.angle - fr.step;
        } else {
            fr.angle = fr.step + fr.angle;
        }
        fr.w = (*(Vec3_11ce20*)&DAT_004a6ac0);
        FUN_00224d70(fr.angle, &fr.w);
        stats->aim = fr.w;
    }
    stats->dir = stats->aim;

    if (f28 > 0 && fr.t1c > 0.0f) {
        tn = tuning;
        fr.t1c = tn->f1c;
        fr.t18 = tn->f20;
        Hub20_11ce20 *hub = DAT_004dd700->hub;
        Player_11ce20 *pl = hub->player;
        if (pl != 0) {
            pl->mount->FUN_00059a50(&fr.pos);
            Tuning_11ce20 *t3 = tuning;
            fr.step = t3->f28;
            a1.f = t3->f24;
            if (t3->b2c) {
                if (fr.pos.y > a1.f) {
                    double k = 1.0f / pow(fr.pos.y / a1.f, fr.step);
                    fr.t1c = k * t3->f1c;
                    fr.t18 = k * t3->f20;
                }
            }
        }
        if (fr.dy < fr.t1c) {
            if (fr.dist > a0.f || !(a0.f > 0.0f))
                stats->aim.y = 1.0f;
            else
                stats->aim.y = fr.dist / a0.f;
            stats->aim.FUN_0022d110();
        } else if (fr.dy > fr.t18) {
            if (fr.dist > a0.f || !(a0.f > 0.0f))
                stats->aim.y = -1.0f;
            else
                stats->aim.y = -(fr.dist / a0.f);
            stats->aim.FUN_0022d110();
        }
    }
    stats->f2070 = tuning->f34;
    return true;
}
}
}
} // namespace fn_0011ce20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0011d2c0 hulkfight::ai::PathFormationAction::vfunc_5 (1431 B): equivalent/0x0011d2c0.cpp [wrapped: conflict: World]
// sym: ?F@PathFormationAction@fn_0011d2c0@@QAEDHM@Z @a84797e9e69e @wdcb0707d657a
namespace fn_0011d2c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3087 inputs, branch coverage 62/62)
// hulkfight::ai::PathFormationAction::vfunc_5 @ 0x0011d2c0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct V3_11d2c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Body_11d2c0 {
    struct Info_11d2c0 *FUN_00059a30();
    void FUN_00059a50(V3_11d2c0 *out);
};
struct Info_11d2c0 {
    char pad[0x140];
    int f140;
};

struct Sub11c_11d2c0 {
    char pad[0x380];
    int f380;
};

struct Source_11d2c0 {
    char pad0[0x1a60];
    V3_11d2c0 v1a60;
};

struct Thing_11d2c0 {
    char pad0[8];
    Source_11d2c0 *p8;
    int mode;
    char pad10[0x40 - 0x10];
    V3_11d2c0 v40;
};

struct Owner_11d2c0 {
    char pad0[0x10];
    Body_11d2c0 *p10;
    char pad14[0x11c - 0x14];
    Sub11c_11d2c0 *p11c;
    char pad120[0x328 - 0x120];
    Thing_11d2c0 *f328;
    char pad32c[0x1a60 - 0x32c];
    V3_11d2c0 v1a60;
    char pad1a6c[0x1b38 - 0x1a6c];
    float f1b38;
    char pad1b3c[0x2064 - 0x1b3c];
    V3_11d2c0 dir;
    float speed;
    V3_11d2c0 aim;
    void FUN_00035550(V3_11d2c0 *out);
};

struct Target7c {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x28 - 4];
    int f28;
    char pad2c[4];
    float f30;
};

struct Global_11d2c0 {
    char pad0[0x150];
    int f150;
    char pad154[0x2c8 - 0x154];
    int f2c8;
    void FUN_000671b0(V3_11d2c0 *p);
};
Global_11d2c0 *FUN_000678d0();

struct Hub1c_11d2c0 {
    char FUN_001ae2c0(V3_11d2c0 *a, V3_11d2c0 *b, V3_11d2c0 *c, float f1, float f2, float f3, int i1, int i2, int i3, int i4, int i5,
                      float t, int i6);
};
struct World {
    char pad0[0x1c];
    Hub1c_11d2c0 *f1c;
};

void FUN_00018810(Thing_11d2c0 **slot, Thing_11d2c0 *t);
extern "C" char FUN_00018960(float a, float b, float eps);

class PathFormationAction {
public:
    char pad0[0x1c];
    char b1c;
    char b1d;
    char pad1e[2];
    V3_11d2c0 v20;
    V3_11d2c0 v2c;
    char pad38[0x64 - 0x38];
    V3_11d2c0 v64;
    char pad70[4];
    int mode;
    char pad78[4];
    Target7c *p7c;
    void *p80;
    Thing_11d2c0 *p84;
    char pad88[0xb8 - 0x88];
    Owner_11d2c0 *owner;
    char padbc[4];
    int idLo;
    int idHi;
    char bC8;
    char padc9[3];
    float fCC;
    char F(int a, float dt);
};

char PathFormationAction::F(int a, float dt)
{
    Owner_11d2c0 *own = owner;
    int var4 = 1;
    if (own)
        var4 = own->p11c->f380;
    fCC = dt + fCC;
    if (a != 0)
        return 1;
    if (!p80 || !own)
        return 0;
    V3_11d2c0 U;
    V3_11d2c0 W;
    U.x = 0; U.y = 0; U.z = 0;
    W.x = 0; W.y = 0; W.z = 0;
    float T = 0.0f;
    Thing_11d2c0 *th = own->f328;
    if (!th) {
        th = p84;
        if (!th)
            return 1;
    }
    V3_11d2c0 P = th->v40;
    int c28 = p7c->f28;
    FUN_000678d0()->f2c8 = c28;
    if (FUN_000678d0()->f150 < p7c->f28)
        return 1;
    FUN_000678d0()->FUN_000671b0(&P);
    owner->FUN_00035550(&U);
    V3_11d2c0 X;
    X.x = U.x; X.y = U.y; X.z = U.z;
    own = owner;
    v20 = own->v1a60;
    float f1b = owner->f1b38;
    if (!(f1b == 0.0f))
        T = f1b;
    FUN_00018810(&p84, th);

    bool skipTo2d4 = false;
    if (bC8) {
        if (!(idLo == (*(int*)&DAT_004e0d18) && idHi == (*(int*)((char*)&DAT_004e0d18 + 4)))) {
            if (fCC > 5.0f) {
                bC8 = 0;
                fCC = 0;
            }
        }
        if (bC8) {
            float r = p7c->v7();
            if (!(r < 0.0f))
                skipTo2d4 = true;
        }
    }
    if (!skipTo2d4) {
        V3_11d2c0 Y;
        if (th->mode == 1) {
            Y = th->p8->v1a60;
        } else {
            Y = th->v40;
        }
        if (owner->p10->FUN_00059a30()->f140 != 1)
            return 1;
        V3_11d2c0 Z;
        owner->p10->FUN_00059a50(&Z);
        V3_11d2c0 Q = v2c;
        char ok = DAT_004dd700->f1c->FUN_001ae2c0(&v2c, &Z, &Y, 6.0f, 200.0f, 360.0f, 1, 0, 3, var4, 1, T, 0);
        if (ok)
            bC8 = 1;
        else
            v2c = Q;
        b1c = 1;
    }
    W.x = v2c.x - v20.x;
    W.y = 0;
    W.z = v2c.z - v20.z;
    float lenW = W.FUN_0022d110();
    T = lenW;

    float A, B;
    if (!bC8 || !b1d) {
        A = 0.0f;
        B = X.y;
    } else if (mode != 2) {
        V3_11d2c0 Y;
        Y.x = v64.x - v20.x;
        Y.y = 0;
        Y.z = v64.z - v20.z;
        float L = Y.FUN_0022d110();
        int lo = idLo;
        int d28 = (*(int*)&DAT_004e0d28);
        int hi = idHi;
        bool toW;
        if ((lo == d28 && hi == (*(int*)((char*)&DAT_004e0d28 + 4))) || (lo == (*(int*)&DAT_004e0d18) && hi == (*(int*)((char*)&DAT_004e0d18 + 4)))) {
            toW = false;
        } else if (FUN_00018960(L, 0.0f, 1.0e-5f)) {
            toW = true;
        } else {
            toW = !(T > p7c->f30);
        }
        if (toW) {
            U.x = W.x; U.y = W.y; U.z = W.z;
            X.x = W.x;
            X.z = W.z;
            A = 0.0f;
            B = W.y;
        } else {
            U.x = Y.x; U.y = Y.y; U.z = Y.z;
            if (lo == d28 && hi == (*(int*)((char*)&DAT_004e0d28 + 4))) {
                U.x = Y.x * -1.0f;
                U.y = Y.y * -1.0f;
                U.z = Y.z * -1.0f;
            }
            X.x = Y.x;
            X.z = Y.z;
            A = 1.0f;
            B = Y.y;
        }
    } else {
        V3_11d2c0 Y;
        Y.x = v2c.x - v20.x;
        Y.y = v2c.y;
        Y.z = v2c.z - v20.z;
        if (T > p7c->f30) {
            U.x = Y.x;
            U.y = 0;
            U.z = Y.z;
            if (idLo == (*(int*)&DAT_004e0d28) && idHi == (*(int*)((char*)&DAT_004e0d28 + 4))) {
                *(unsigned int *)&U.y = 0x80000000;
                U.x = Y.x * -1.0f;
                U.z = Y.z * -1.0f;
            }
            X.x = Y.x;
            X.z = Y.z;
            A = 1.0f;
            B = 0.0f;
        } else {
            U.x = W.x; U.y = W.y; U.z = W.z;
            X.x = W.x;
            X.z = W.z;
            A = 0.0f;
            B = W.y;
        }
    }
    Owner_11d2c0 *o = owner;
    o->speed = A;
    o->dir.x = X.x;
    o->dir.y = B;
    o->dir.z = X.z;
    o->aim.x = U.x;
    o->aim.y = U.y;
    o->aim.z = U.z;
    return 1;
}
} // namespace fn_0011d2c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

