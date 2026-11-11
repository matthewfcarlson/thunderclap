// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00133a00..0x00134c60 (kind game, layer game, confidence high), dominant class hulkfight::motion::FlyingBrakeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f414acda {
#define TREE_TU_END }
namespace fn_f414acda {} using namespace fn_f414acda;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f414acda {
extern int* hulk_at_004e0ec8;
class CCondition_133a20 {
  public:
    virtual int vfunc_0(int);
};
class Track_133a30 {
  public:
    Track_133a30();
    virtual void f();
    char pad[4];
};
class GrappleHoverTrack : public Track_133a30 {
  public:
    GrappleHoverTrack();
    virtual void f();
    int a;
    int b;
    int c;
    int d;
};
struct Param_133a70 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133a70 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ed0;
class CCondition_133ab0 {
  public:
    virtual int vfunc_0(int);
};
struct FUN_00236d40 {
    virtual void slot0();
    char pad[8];
    FUN_00236d40();
};
struct FlyingBrakeTrack : FUN_00236d40 {
    int value0c;
    float min0;
    float max0;
    float ten;
    float max1;
    float min1;
    int index;
    int flag28;
    int flag2c;
    FlyingBrakeTrack();
    virtual void slot0();
};
struct Param_133b20 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133b20 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ed8;
class CCondition_133b60 {
  public:
    virtual int vfunc_0(int);
};
class Track_133b70 {
  public:
    Track_133b70();
    virtual void f();
    char pad[4];
};
class BounceTrack : public Track_133b70 {
  public:
    BounceTrack();
    virtual void f();
    int a;
    int c;
    float b;
    int d, z;
    float e, g, h;
    int i, j, k;
};
struct Param_133bd0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133bd0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ee0;
class CCondition_133c10 {
  public:
    virtual int vfunc_0(int);
};
struct Param_133c90 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133c90 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ee8;
class CCondition_133cd0 {
  public:
    virtual int vfunc_0(int);
};
class Track_133ce0 {
  public:
    Track_133ce0();
    virtual hulk_intptr Fnf_00133cd0(int);
};
class HoverTrack : public Track_133ce0 {
  public:
    HoverTrack();
    char pad[4];
    int a;
    int b;
    float c;
    int d;
};
struct Param_133d20 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133d20 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ef0;
class CCondition_133d60 {
  public:
    virtual int vfunc_0(int);
};
struct Param_133de0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133de0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0ef8;
class CCondition_133e20 {
  public:
    virtual int vfunc_0(int);
};
} // namespace fn_f414acda
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f414acda {
struct Track_133e30 { virtual void dummy(); char pad[4]; int enabled; int state; void FUN_00236d40(); };
struct FlyingAutoTargetTrack : Track_133e30 {
 float a,b,c,d,e,f,g,h; int i,j,k;
 virtual void dummy();
 FlyingAutoTargetTrack* FUN_00133e30();
};
struct Param_133ea0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133ea0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e0f00;
class CCondition_133ee0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_133f50 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_133f50 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct A_133f80 {
    A_133f80* Second_00059a30();
};
struct V3_133fc0 {
    float x, y, z;
};
struct Name_133fc0 {
    unsigned int lo, hi;
};
struct Xform_133fc0 {
    char data[0x54];
    void FUN_00221be0(const Xform_133fc0* src);
    hulk_freg FUN_002220d0();
};
void __cdecl FUN_00224d70(float angle, V3_133fc0* v);
class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_133fc0 name;
    char pad10[8];
    Xform_133fc0 xform;
    JointDriver* FUN_002248f0(int a);
};
struct Attach_133fc0 {
    char pad0[0x2c];
    float height;
};
struct Timing_133fc0 {
    char pad0[0x11c];
    Attach_133fc0* attach;
    char pad120[0x140 - 0x120];
    int mode;
};
struct Skeleton {
    char pad0[0x10];
    Xform_133fc0 xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_133fc0 {
    Timing_133fc0* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_133fc0 {
};
struct Config_133fc0 {
    char pad0[0x24];
    char flag24;
    char pad25[3];
    V3_133fc0 offset;
    float f34;
    char pad38[0x40 - 0x38];
    float f40;
    float f44;
    float f48;
};
struct Sink_133fc0 {
    void FUN_00099d40(struct World* w, Timing_133fc0* t, float v);
};
} // namespace fn_f414acda
struct World {
    char pad0[8];
    Sink_133fc0* sink;
};
namespace fn_f414acda {
class FallAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_133fc0* cfg;
    Target_133fc0* target;
    JointDriver* driver;
    V3_133fc0 pos;
};
struct Two_134160 {
    void* Fnf_00059a40();
};
struct Two_1345a0 {
    void* Fnf_00059a40();
};
struct Two_1346a0 {
    void* Fnf_00059a40();
};
struct Two_134790 {
    void* Fnf_00059a40();
};
struct Two_134970 {
    void* Fnf_00059a40();
};
extern void* hulk_at_00411bb8[];
class Track_134c00 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class FlyingDashTrack_134c00 : public Track_134c00 {
  public:
    FlyingDashTrack_134c00* vfunc_5(signed char flags);
};
extern void* hulk_at_00411be8[];
class Track_134c30 {
  public:
    void Destroy_00236d60(); // FUN_00236d60, __thiscall, this in ecx
};
class GrappleHoverTrack_134c30 : public Track_134c30 {
  public:
    GrappleHoverTrack_134c30* vfunc_5(signed char flags);
};


// 0x00133a00 FUN_00133a00 (19 B): matches/0x00133a00.cpp
// sym: ?FUN_00133a00@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133a00() {
    FUN_00234810(((char*)&DAT_004e0ec8), ((char*)&DAT_004e0ecc));
}

} // namespace fn_f414acda

// 0x00133a20 hulkfight::motion::GrappleHoverTrack::vfunc_0 (16 B): matches/0x00133a20.cpp
// sym: ?vfunc_0@GrappleHoverTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleHoverTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ec8;
    return p[index];
}

namespace fn_f414acda {

// 0x00133a30 FUN_00133a30 (40 B): matches/0x00133a30.cpp
// sym: ??0GrappleHoverTrack@fn_f414acda@@QAE@XZ
GrappleHoverTrack::GrappleHoverTrack() : b(0), d(0) {
    c = 0xbf800000;
    a = 1;
}

} // namespace fn_f414acda

// 0x00133a60 hulkfight::motion::GrappleHoverTrack::vfunc_6 (4 B): matches/0x00133a60.cpp
// sym: ?vfunc_6@GrappleHoverTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::GrappleHoverTrack::vfunc_6() {
    return this->timeBegin;
}


// 0x00133a70 hulkfight::motion::GrappleHoverTrack::vfunc_7 (7 B): matches/0x00133a70.cpp
// sym: ?vfunc_7@GrappleHoverTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::GrappleHoverTrack::vfunc_7() {
    return (hulk_freg)this->timeEnd - this->timeBegin;
}

namespace fn_f414acda {

// 0x00133a90 FUN_00133a90 (19 B): matches/0x00133a90.cpp
// sym: ?FUN_00133a90@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133a90() {
    FUN_00234810(((char*)&DAT_004e0ed0), ((char*)&DAT_004e0ed4));
}

} // namespace fn_f414acda

// 0x00133ab0 hulkfight::motion::FlyingBrakeTrack::vfunc_0 (16 B): matches/0x00133ab0.cpp
// sym: ?vfunc_0@FlyingBrakeTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingBrakeTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ed0;
    return p[index];
}

namespace fn_f414acda {

// 0x00133ac0 FUN_00133ac0 (65 B): equivalent/0x00133ac0.cpp
// sym: ??0FlyingBrakeTrack@fn_f414acda@@QAE@XZ @a19510f0b68c @w338ee64df661
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133ac0 @ 0x00133ac0
FlyingBrakeTrack::FlyingBrakeTrack() {
    value0c = 0;
    flag28 = 0;
    flag2c = 0;
    min0 = -1.0f;
    max0 = 50.0f;
    ten = 10.0f;
    max1 = 50.0f;
    min1 = -1.0f;
    index = -5;
}

} // namespace fn_f414acda

// 0x00133b10 hulkfight::motion::FlyingBrakeTrack::vfunc_6 (4 B): matches/0x00133b10.cpp
// sym: ?vfunc_6@FlyingBrakeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FlyingBrakeTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133b20 hulkfight::motion::FlyingBrakeTrack::vfunc_7 (7 B): matches/0x00133b20.cpp
// sym: ?vfunc_7@FlyingBrakeTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FlyingBrakeTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133b40 FUN_00133b40 (19 B): matches/0x00133b40.cpp
// sym: ?FUN_00133b40@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133b40() {
    FUN_00234810(((char*)&DAT_004e0ed8), ((char*)&DAT_004e0edc));
}

} // namespace fn_f414acda

// 0x00133b60 hulkfight::motion::BounceTrack::vfunc_0 (16 B): matches/0x00133b60.cpp
// sym: ?vfunc_0@BounceTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::BounceTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ed8;
    return p[index];
}

namespace fn_f414acda {

// 0x00133b70 FUN_00133b70 (77 B): matches/0x00133b70.cpp
// sym: ??0BounceTrack@fn_f414acda@@QAE@XZ
BounceTrack::BounceTrack() : c(0), d(0), z(0), j(0), k(0) {
    b = -1.0f;
    e = 7.0f;
    g = 10.0f;
    h = 1.57079637f;
    i = -5;
    a = 1;
}

} // namespace fn_f414acda

// 0x00133bc0 hulkfight::motion::BounceTrack::vfunc_6 (4 B): matches/0x00133bc0.cpp
// sym: ?vfunc_6@BounceTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::BounceTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133bd0 hulkfight::motion::BounceTrack::vfunc_7 (7 B): matches/0x00133bd0.cpp
// sym: ?vfunc_7@BounceTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::BounceTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133bf0 FUN_00133bf0 (19 B): matches/0x00133bf0.cpp
// sym: ?FUN_00133bf0@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133bf0() {
    FUN_00234810(((char*)&DAT_004e0ee0), ((char*)&DAT_004e0ee4));
}

} // namespace fn_f414acda

// 0x00133c10 hulkfight::motion::AirToGroundTargetTrack::vfunc_0 (16 B): matches/0x00133c10.cpp
// sym: ?vfunc_0@AirToGroundTargetTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::AirToGroundTargetTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ee0;
    return p[index];
}


// 0x00133c20 FUN_00133c20 (81 B): matches/0x00133c20.cpp [wrapped: conflict: hulkfight::motion::AirToGroundTargetTrack]
// sym: ??0AirToGroundTargetTrack@motion@hulkfight@fn_00133c20@@QAE@XZ
namespace fn_00133c20 {
namespace hulkfight {
namespace motion {
class Base {
  public:
    Base();
    virtual hulk_intptr Fnf_00133c10(int);
    int x;
    int flag;
};
class AirToGroundTargetTrack : public Base {
  public:
    AirToGroundTargetTrack();
    int a;
    float b, c, d, e, f, g;
    int h, i, j, k;
};
AirToGroundTargetTrack::AirToGroundTargetTrack()
    : a(0), b(-1.0f), c(0), d(50.0f), e(100.0f), f(100.0f), g(3.1415927f / 2.0f), h(0), i(-5), j(0), k(0) {
    flag = 1;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00133c20


// 0x00133c80 hulkfight::motion::AirToGroundTargetTrack::vfunc_6 (4 B): matches/0x00133c80.cpp
// sym: ?vfunc_6@AirToGroundTargetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::AirToGroundTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133c90 hulkfight::motion::AirToGroundTargetTrack::vfunc_7 (7 B): matches/0x00133c90.cpp
// sym: ?vfunc_7@AirToGroundTargetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::AirToGroundTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133cb0 FUN_00133cb0 (19 B): matches/0x00133cb0.cpp
// sym: ?FUN_00133cb0@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133cb0() {
    FUN_00234810(((char*)&DAT_004e0ee8), ((char*)&DAT_004e0eec));
}

} // namespace fn_f414acda

// 0x00133cd0 hulkfight::motion::HoverTrack::vfunc_0 (16 B): matches/0x00133cd0.cpp
// sym: ?vfunc_0@HoverTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HoverTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ee8;
    return p[index];
}

namespace fn_f414acda {

// 0x00133ce0 FUN_00133ce0 (40 B): matches/0x00133ce0.cpp
// sym: ??0HoverTrack@fn_f414acda@@QAE@XZ
HoverTrack::HoverTrack() {
    b = 0;
    d = 0;
    c = -1.0f;
    a = 1;
}

} // namespace fn_f414acda

// 0x00133d10 hulkfight::motion::HoverTrack::vfunc_6 (4 B): matches/0x00133d10.cpp
// sym: ?vfunc_6@HoverTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HoverTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133d20 hulkfight::motion::HoverTrack::vfunc_7 (7 B): matches/0x00133d20.cpp
// sym: ?vfunc_7@HoverTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HoverTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133d40 FUN_00133d40 (19 B): matches/0x00133d40.cpp
// sym: ?FUN_00133d40@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133d40() {
    FUN_00234810(((char*)&DAT_004e0ef0), ((char*)&DAT_004e0ef4));
}

} // namespace fn_f414acda

// 0x00133d60 hulkfight::motion::FallTrack::vfunc_0 (16 B): matches/0x00133d60.cpp
// sym: ?vfunc_0@FallTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FallTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ef0;
    return p[index];
}


// 0x00133d70 FUN_00133d70 (81 B): equivalent/0x00133d70.cpp [wrapped: conflict: hulkfight::motion::FallTrack]
// sym: ??0FallTrack@motion@hulkfight@fn_00133d70@@QAE@XZ @3c71db577839 @w76e064f63083
namespace fn_00133d70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133d70 @ 0x00133d70
namespace hulkfight { namespace motion {
class FUN_00236d40 {
public:
    virtual hulk_intptr dummy_00133d60(int);
    char padding[8];
    FUN_00236d40();
};
class FallTrack : public FUN_00236d40 {
public:
    unsigned int value0c;
    float value10;
    unsigned int value14, value18, value1c, value20;
    unsigned char value24;
    char pad25[3];
    unsigned int value28, value2c, value30;
    float value34;
    unsigned int value38;
    unsigned char value3c;
    char pad3d[3];
    int value40;
    unsigned int value44, value48;
    FallTrack();
};
FallTrack::FallTrack() {
    value0c = 0;
    value14 = 0;
    value18 = 0;
    value1c = 0;
    value20 = 0;
    value24 = 0;
    value10 = -1.0f;
    value28 = 0;
    value2c = 0;
    value30 = 0;
    value38 = 0;
    value44 = 0;
    value48 = 0;
    value34 = 9.8f;
    value3c = 1;
    value40 = -5;
}
} }
} // namespace fn_00133d70


// 0x00133dd0 hulkfight::motion::FallTrack::vfunc_6 (4 B): matches/0x00133dd0.cpp
// sym: ?vfunc_6@FallTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FallTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133de0 hulkfight::motion::FallTrack::vfunc_7 (7 B): matches/0x00133de0.cpp
// sym: ?vfunc_7@FallTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FallTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133e00 FUN_00133e00 (19 B): matches/0x00133e00.cpp
// sym: ?FUN_00133e00@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133e00() {
    FUN_00234810(((char*)&DAT_004e0ef8), ((char*)&DAT_004e0efc));
}

} // namespace fn_f414acda

// 0x00133e20 hulkfight::motion::FlyingAutoTargetTrack::vfunc_0 (16 B): matches/0x00133e20.cpp
// sym: ?vfunc_0@FlyingAutoTargetTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingAutoTargetTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ef8;
    return p[index];
}

namespace fn_f414acda {

// 0x00133e30 FUN_00133e30 (88 B): equivalent/0x00133e30.cpp
// sym: ?FUN_00133e30@FlyingAutoTargetTrack@fn_f414acda@@QAEPAU12@XZ @46b904d89519 @wc26d7421ec28
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133e30 @ 0x00133e30
FlyingAutoTargetTrack* FlyingAutoTargetTrack::FUN_00133e30() {
 FUN_00236d40();
 state=0;
 new (this) FlyingAutoTargetTrack;
 a=-1.0f; b=1.57079637f; c=0.0f; d=0.0f; e=-1.0f;
 j=0; k=0; f=30.0f; g=6.28318548f; h=100.0f; i=-5;
 enabled=1;
 return this;
}

} // namespace fn_f414acda

// 0x00133e90 hulkfight::motion::FlyingAutoTargetTrack::vfunc_6 (4 B): matches/0x00133e90.cpp
// sym: ?vfunc_6@FlyingAutoTargetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FlyingAutoTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133ea0 hulkfight::motion::FlyingAutoTargetTrack::vfunc_7 (7 B): matches/0x00133ea0.cpp
// sym: ?vfunc_7@FlyingAutoTargetTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FlyingAutoTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f414acda {

// 0x00133ec0 FUN_00133ec0 (19 B): matches/0x00133ec0.cpp
// sym: ?FUN_00133ec0@fn_f414acda@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133ec0() {
    FUN_00234810(((char*)&DAT_004e0f00), ((char*)&DAT_004e0f04));
}

} // namespace fn_f414acda

// 0x00133ee0 hulkfight::motion::FlyingAttackTrack::vfunc_0 (16 B): matches/0x00133ee0.cpp
// sym: ?vfunc_0@FlyingAttackTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingAttackTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0f00;
    return p[index];
}


// 0x00133ef0 FUN_00133ef0 (76 B): equivalent/0x00133ef0.cpp [wrapped: conflict: hulkfight::motion::FlyingAttackTrack]
// sym: ??0FlyingAttackTrack@motion@hulkfight@fn_00133ef0@@QAE@XZ @9aab3b396e3c @wff78e7b8cfcf
namespace fn_00133ef0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00133ef0 @ 0x00133ef0
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void unused();
    char baseData[8];
    FUN_00236d40();
};
struct FlyingAttackTrack : FUN_00236d40 {
    int field0c;
    float field10;
    int field14;
    int field18;
    float field1c;
    float field20;
    int field24;
    int field28;
    float field2c;
    unsigned char field30;
    char reserved31[3];
    int field34;
    int field38;
    int field3c;
    virtual void unused();
    FlyingAttackTrack();
};
FlyingAttackTrack::FlyingAttackTrack() : FUN_00236d40() {
    field0c = 0;
    field10 = -1.0f;
    field14 = 0;
    field18 = 0;
    field1c = -1.0f;
    field24 = 0;
    field28 = 0;
    field30 = 0;
    field38 = 0;
    field3c = 0;
    field20 = 50.0f;
    field2c = 3.14159274f;
    field34 = -5;
}
}}
} // namespace fn_00133ef0


// 0x00133f40 hulkfight::motion::FlyingAttackTrack::vfunc_6 (4 B): matches/0x00133f40.cpp
// sym: ?vfunc_6@FlyingAttackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FlyingAttackTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00133f50 hulkfight::motion::FlyingAttackTrack::vfunc_7 (7 B): matches/0x00133f50.cpp
// sym: ?vfunc_7@FlyingAttackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FlyingAttackTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x00133f70 hulkfight::motion::GrappleHoverTrack::vfunc_8 (16 B): matches/0x00133f70.cpp [wrapped: conflict: fight::Param; fight::Track; hulkfight::motion::GrappleHoverTrack]
// sym: ?vfunc_8@GrappleHoverTrack@motion@hulkfight@fn_00133f70@@UAEHHH@Z
namespace fn_00133f70 {
namespace fight {
class Track {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int, int);
};
class Param {};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleHoverTrack : public fight::Track, public fight::Param {
  public:
    virtual int vfunc_8(int, int);
};
} // namespace motion
} // namespace hulkfight
extern "C" hulk_intptr FUN_0005a3f0(hulk_intptr);
int hulkfight::motion::GrappleHoverTrack::vfunc_8(int a, int b) {
    return FUN_0005a3f0(b);
}
} // namespace fn_00133f70


// 0x00133f80 hulkfight::motion::HoverAction::vfunc_5 (61 B): matches/0x00133f80.cpp
// sym: ?vfunc_5@HoverAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::HoverAction::vfunc_5(hulk_intptr param, int unused) {
    if (param == 0) {
        A_133f80* p = ((A_133f80 *)((owners::Object_592a0 *)(((A_133f80*)*(void**)((char*)this + 0x20))))->FUN_000592a0());
        p = p->Second_00059a30();
        if (this->f_1c > 0)
            ((owners::C_359c0 *)p)->FUN_000359c0(1);
        else
            ((owners::C_359c0 *)p)->FUN_000359c0(3);
    }
    return true;
}

namespace fn_f414acda {

// 0x00133fc0 hulkfight::motion::FallAction::vfunc_3 (409 B): equivalent/0x00133fc0.cpp
// sym: ?vfunc_3@FallAction@fn_f414acda@@UAE_NHH@Z @ef29cb808292 @w856729939bf4
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// hulkfight::motion::FallAction::vfunc_3 @ 0x00133fc0
bool FallAction::vfunc_3(int a, int b)
{
    Clock_133fc0* clock = ((Clock_133fc0 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_133fc0* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    pos = cfg->offset;
    FUN_00224d70(skel->xform.FUN_002220d0(), &pos);
    if (!cfg->flag24) {
        V3_133fc0 move;
        move.x = 0.0f;
        move.y = 0.0f;
        move.z = 0.0f;
        ((owners::Thing_356c0 *)timing)->FUN_000356c0((unsigned int *)(V3_133fc0 *)(&move));
        pos.x = move.x + pos.x;
        pos.y = move.y + pos.y;
        pos.z = move.z + pos.z;
    }
    Config_133fc0* c = cfg;
    float c44 = c->f44;
    float c48 = c->f48;
    float c40 = c->f40;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"fall");
    driver->AddRef();
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c40, 1.0f, c44, c48, -1.0f);
    DAT_004dd700->sink->FUN_00099d40(DAT_004dd700, timing, cfg->f34);
    if (((int)((owners::Widget_35910 *)timing)->FUN_00035910()) == 7 && timing->mode == 1) {
        V3_133fc0 lift;
        lift.x = 0.0f;
        lift.y = timing->attach->height * 0.5f;
        lift.z = 0.0f;
        ((owners::C_357a0 *)timing)->FUN_000357a0((float *)(V3_133fc0 *)(&lift));
    }
    return true;
}

} // namespace fn_f414acda

// 0x00134160 hulkfight::motion::FallAction::vfunc_4 (37 B): matches/0x00134160.cpp
// sym: ?vfunc_4@FallAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::FallAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_134160*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x00134190 hulkfight::motion::FlyingBrakeAction::vfunc_3 (406 B): equivalent/0x00134190.cpp [wrapped: conflict: JointDriver; Skeleton]
// sym: ?vfunc_3@FlyingBrakeAction@fn_00134190@@UAE_NHH@Z @af10704c691b @w8104811d052d
namespace fn_00134190 {
// STATUS: equivalent (tools/equiv.py level 3: 19951 inputs, branch coverage 8/8)
// hulkfight::motion::FlyingBrakeAction::vfunc_3 @ 0x00134190
struct V3_134190 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Name_134190 {
    unsigned int lo, hi;
};
struct Xform_134190 {
    char data[0x54];
    void FUN_00221be0(const Xform_134190* src);
};
void* FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_134190 name;
    char pad10[4];
    int enabled;
    Xform_134190 xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing_134190 {
};
struct Skeleton {
    char pad0[0x10];
    Xform_134190 xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_134190 {
    Timing_134190* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_134190 {
};
class Config_134190 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float GetSpeed();
    char pad8[0x14 - 4];
    float maxSpeed;
    char pad18[0x24 - 0x18];
    float f24;
    float f28;
    float f2c;
};

class FlyingBrakeAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_134190* cfg;
    Target_134190* target;
    JointDriver* driver;
    V3_134190 pos;
    V3_134190 vel;
};

bool FlyingBrakeAction::vfunc_3(int a, int b)
{
    Clock_134190* clock = ((Clock_134190 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_134190* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    Config_134190* c = cfg;
    float c28 = c->f28;
    float c2c = c->f2c;
    float c24 = c->f24;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"flyingBrake");
    driver->AddRef();
    driver->enabled = 1;
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c24, 1.0f, c28, c2c, -1.0f);
    ((owners::Thing_356c0 *)timing)->FUN_000356c0((unsigned int *)(V3_134190 *)(&pos));
    float f = cfg->GetSpeed();
    if (f > 0.0f) {
        V3_134190 dir;
        dir.x = pos.x;
        dir.y = 0.0f;
        dir.z = pos.z;
        float len = dir.FUN_0022d110();
        float s = cfg->maxSpeed;
        if (s > len)
            s = len;
        // the original rounds each stage through the vel members
        volatile float *v = &vel.x;
        v[0] = dir.x * s;
        v[2] = dir.z * s;
        v[1] = s * dir.y;
        v[0] = v[0] - pos.x;
        v[1] = v[1] - pos.y;
        v[2] = v[2] - pos.z;
        v[1] = 0.0f;
        double r = 1.0f / f;
        v[0] = v[0] * r;
        v[1] = v[1] * r;
        v[2] = v[2] * r;
    }
    return true;
}
} // namespace fn_00134190


// 0x00134330 hulkfight::motion::FlyingBrakeAction::vfunc_5 (618 B): equivalent/0x00134330.cpp [wrapped: conflict: hulkfight::motion::FlyingBrakeAction]
// sym: ?vfunc_5@FlyingBrakeAction@motion@hulkfight@fn_00134330@@UAEDHM@Z @cd8df6caa73d @wbe5562b14f35
namespace fn_00134330 {
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 18/18)
// hulkfight::motion::FlyingBrakeAction::vfunc_5 @ 0x00134330
struct V3_134330 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    bool FUN_0022d2b0(const V3_134330* other, float epsilon);
    void FUN_0022be40(const V3_134330* p);
};

struct Tuning_134330 {
    char pad0[0x34];
    float scale;                // 0x34
};

struct Stats_134330 {
    char pad0[0x11c];
    Tuning_134330* tuning;             // 0x11c
    char pad120[0x140 - 0x120];
    int state;                  // 0x140
    char pad144[0x1ae0 - 0x144];
    V3_134330 aimB;                    // 0x1ae0
    char pad1aec[0x1af8 - 0x1aec];
    V3_134330 aimA;                    // 0x1af8
    void FUN_000359c0(int v);
    void FUN_00035550(V3_134330* out);
    void FUN_000357a0(V3_134330* v);
};

struct Pool_134330 {
    Stats_134330* FUN_00059a30();
    bool FUN_00059a50(V3_134330* out);
};

struct Owner_134330 {
    Pool_134330* FUN_000592a0();
};

struct Mover_134330 {
    char pad0[0x18];
    V3_134330 pos;                     // 0x18
};

struct Limits_134330 {
    char pad0[0x18];
    float f18;
    float f1c;
    float f20;
};

namespace hulkfight { namespace motion {

class FlyingBrakeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int skip, float dt);
    char pad04[0x18];
    Limits_134330* limits;             // 0x1c
    Owner_134330* owner;               // 0x20
    Mover_134330* mover;               // 0x24
    V3_134330 vel;                     // 0x28
    V3_134330 acc;                     // 0x34
};

char FlyingBrakeAction::vfunc_5(int skip, float dt)
{
    if (skip != 0)
        return 1;
    if (mover == 0)
        return 0;

    Pool_134330* pool = owner->FUN_000592a0();
    Stats_134330* stats = pool->FUN_00059a30();
    stats->FUN_000359c0(3);

    V3_134330 p;
    p.x = 0.0f;
    p.y = 0.0f;
    p.z = 0.0f;
    pool->FUN_00059a50(&p);

    if (stats->state == 4) {
        V3_134330 v = stats->aimA;
        V3_134330 zero;
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        if (v.FUN_0022d2b0(&zero, 1e-5f)) {
            v = stats->aimB;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            if (v.FUN_0022d2b0(&zero, 1e-5f)) {
                stats->FUN_00035550(&v);
                v.x = v.x * -1.0f;
                v.z = v.z * -1.0f;
            }
        }
        v.y = 0.0f;
        v.FUN_0022d110();
        float s = stats->tuning->scale;
        v.x = v.x * s;
        v.y = v.y * s;
        v.z = v.z * s;
        stats->FUN_000357a0(&v);
    }

    if (vel.y > 0.0f)
        acc.y = -limits->f1c;
    else
        acc.y = -limits->f18;

    vel.x = dt * acc.x + vel.x;
    vel.y = dt * acc.y + vel.y;
    vel.z = dt * acc.z + vel.z;

    Limits_134330* lim = limits;
    float m = lim->f20;
    if (!(m < 0.0f)) {
        float negm = -m;
        if (negm > vel.y) {
            double ny = (lim->f1c + lim->f18) * dt + vel.y;
            vel.y = (float)ny;
            if (ny > negm)
                vel.y = negm;
        }
    }

    // the original reads the rounded velocity back from the members; tz is a rounded frame copy
    volatile float *vv = &vel.x;
    double tx = vv[0] * dt;
    double ty = vv[1] * dt;
    volatile float tz = vv[2] * dt;
    p.x = p.x + tx;
    p.y = p.y + ty;
    p.z = p.z + tz;
    mover->pos.FUN_0022be40(&p);
    return 1;
}

}}
} // namespace fn_00134330


// 0x001345a0 hulkfight::motion::FlyingBrakeAction::vfunc_4 (37 B): matches/0x001345a0.cpp
// sym: ?vfunc_4@FlyingBrakeAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::FlyingBrakeAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_1345a0*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x001345d0 hulkfight::motion::FlyingDashAction::vfunc_5 (206 B): equivalent/0x001345d0.cpp [wrapped: conflict: hulkfight::motion::FlyingDashAction]
// sym: ?vfunc_5@FlyingDashAction@motion@hulkfight@fn_001345d0@@UAE_NHM@Z @ed28e3ad28ad @w4374b31e28fd
namespace fn_001345d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::FlyingDashAction::vfunc_5 @ 0x001345d0
struct Vec3_1345d0 { float x,y,z; };
struct Transform_1345d0 { void FUN_0022be40(const Vec3_1345d0*); };
struct Object { char pad[0x18]; Transform_1345d0 transform; };
struct Mode_1345d0 { void FUN_000359c0(int); };
struct Actor_1345d0 { Mode_1345d0* FUN_00059a30(); void FUN_00059a50(Vec3_1345d0*); };
struct Owner_1345d0 { Actor_1345d0* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct FlyingDashAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float);
 char padding[0x1c]; Owner_1345d0* owner; Object* object; Vec3_1345d0 velocity;
};
bool FlyingDashAction::vfunc_5(int state,float dt) {
 if(state!=0) return true;
 if(!object) return false;
 Actor_1345d0* actor=owner->FUN_000592a0();
 actor->FUN_00059a30()->FUN_000359c0(3);
 Vec3_1345d0 position; position.x=0.0f; position.y=0.0f; position.z=0.0f;
 actor->FUN_00059a50(&position);
 volatile float dz=velocity.z*dt;
 position.x=position.x+velocity.x*dt;
 position.y=position.y+velocity.y*dt;
 position.z=position.z+dz;
 object->transform.FUN_0022be40(&position);
 return true;
}
}}
} // namespace fn_001345d0


// 0x001346a0 hulkfight::motion::FlyingDashAction::vfunc_4 (37 B): matches/0x001346a0.cpp
// sym: ?vfunc_4@FlyingDashAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::FlyingDashAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_1346a0*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x001346d0 hulkfight::motion::FlyingAutoTargetAction::vfunc_3 (181 B): equivalent/0x001346d0.cpp [wrapped: conflict: hulkfight::motion::FlyingAutoTargetAction]
// sym: ?vfunc_3@FlyingAutoTargetAction@motion@hulkfight@fn_001346d0@@UAE_NHH@Z @3246783b7414 @wcd4070f6c153
namespace fn_001346d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::FlyingAutoTargetAction::vfunc_3 @ 0x001346d0
struct VectorPart { void FUN_00221be0(const void*); };
struct NamePart { void FUN_0027b040(const char*); };
struct JointDriver_1346d0 {
 virtual void vfunc_0();
 char pad4[4];
 NamePart name;
 char pad9[15];
 VectorPart vector;
 JointDriver_1346d0* FUN_002248f0(int);
};
struct Target_1346d0 {
 char pad[16];
 char position[12];
 void FUN_00222890(JointDriver_1346d0*,float,float,float,float,float,float);
};
struct Controller_1346d0 {
 void FUN_00059a30();
 Target_1346d0* FUN_00059a40();
};
struct Source_1346d0 { Controller_1346d0* FUN_000592a0(); };
struct Settings_1346d0 { char pad[48]; float x,y,z; };
extern void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct FlyingAutoTargetAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
 virtual bool vfunc_3(int,int);
 virtual void vfunc_4(); virtual void vfunc_5();
 char pad[24]; Settings_1346d0* settings; Source_1346d0* source; JointDriver_1346d0* created;
};
bool FlyingAutoTargetAction::vfunc_3(int,int) {
 Controller_1346d0* controller=source->FUN_000592a0();
 controller->FUN_00059a30();
 Target_1346d0* target=controller->FUN_00059a40();
 if (!target) return false;
 float x=settings->x, y=settings->y, z=settings->z;
 JointDriver_1346d0* storage=(JointDriver_1346d0*)FUN_00263ea0(0x70);
 JointDriver_1346d0* object=storage ? storage->FUN_002248f0(0) : 0;
 created=object;
 object->name.FUN_0027b040("flyingAutoTarget");
 created->vfunc_0();
 created->vector.FUN_00221be0(target->position);
 target->FUN_00222890(created,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
}}
} // namespace fn_001346d0


// 0x00134790 hulkfight::motion::FlyingAutoTargetAction::vfunc_4 (37 B): matches/0x00134790.cpp
// sym: ?vfunc_4@FlyingAutoTargetAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::FlyingAutoTargetAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_134790*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x001347c0 hulkfight::motion::BounceAction::vfunc_3 (423 B): equivalent/0x001347c0.cpp [wrapped: conflict: World; hulkfight::motion::BounceAction]
// sym: ?vfunc_3@BounceAction@motion@hulkfight@fn_001347c0@@UAEDHH@Z @efc882144442 @w1bdcda8dc482
namespace fn_001347c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 10/10)
// hulkfight::motion::BounceAction::vfunc_3 @ 0x001347c0
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

struct Vec3_1347c0 { float x, y, z; };

struct Pose {
    char data[1];
};

struct Transform_1347c0 {
    void FUN_00221be0(const Pose *pose);
};

struct ResourceName_1347c0 {
    char data[12];
    void FUN_0027b040(const char *name);
};

class JointDriver_1347c0 {
public:
    virtual void vfunc_0();
    char pad04[4];
    ResourceName_1347c0 name;
    unsigned int flags;
    Transform_1347c0 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_1347c0)];
    JointDriver_1347c0 *FUN_002248f0(unsigned int id);
};

struct Scene_1347c0 {
    char pad0[0x10];
    Pose pose;
    void FUN_00222890(JointDriver_1347c0 *obj, float a, float b, float c, float d, float e, float f);
};

struct Stats_1347c0 {
    hulk_freg FUN_000354c0();
    void FUN_000356c0(Vec3_1347c0 *out);
};

struct BounceData_1347c0 {
    char pad0[0x14];
    float f14;
    float f18;
    char pad1c[4];
    float f20;
    char pad24[4];
    float f28;
    float f2c;
    float f30;
};

struct World;
struct Manager_1347c0 {
    void FUN_00099d20(World *g, Stats_1347c0 *s, float a, float b, float c);
};

struct World {
    char pad0[8];
    Manager_1347c0 *manager;
};

void *__fastcall FUN_000592a0(void *owner);
extern "C" Stats_1347c0 *__fastcall FUN_00059a30(void *x);
extern "C" Scene_1347c0 *__fastcall FUN_00059a40(void *x);
extern "C++" __declspec(nothrow) void FUN_00224d70(float angle, Vec3_1347c0 *v);
void *__cdecl FUN_00263ea0(unsigned int size);

namespace hulkfight { namespace motion {

class BounceAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    BounceData_1347c0 *data;
    void *owner;
    JointDriver_1347c0 *joint;
    float f28;
    float f2c;
    float f30;
};

char BounceAction::vfunc_3(int a, int b)
{
    void *fighter = FUN_000592a0(owner);
    Stats_1347c0 *stats = FUN_00059a30(fighter);
    Scene_1347c0 *scene = FUN_00059a40(fighter);
    if (scene == 0)
        return 0;

    BounceData_1347c0 *d = data;
    hulk_freg b28 = d->f28;
    hulk_freg b2c = d->f2c;
    hulk_freg b30 = d->f30;

    void *mem = FUN_00263ea0(0x70);
    JointDriver_1347c0 *obj = 0;
    if (mem)
        obj = ((JointDriver_1347c0 *)mem)->FUN_002248f0(0);
    joint = obj;

    obj->name.FUN_0027b040("bounce");
    joint->vfunc_0();
    joint->transform.FUN_00221be0(&scene->pose);
    scene->FUN_00222890(joint, -1.0f, b28, 1.0f, b2c, b30, -1.0f);

    Vec3_1347c0 w;
    w.x = (*(float*)&DAT_004abf64);
    w.y = (*(float*)((char*)&DAT_004abf64 + 4));
    w.z = (*(float*)((char*)&DAT_004abf64 + 8));
    FUN_00224d70(stats->FUN_000354c0(), &w);

    Vec3_1347c0 x;
    x.x = 0.0f;
    x.y = 0.0f;
    x.z = 0.0f;
    stats->FUN_000356c0(&x);

    d = data;
    hulk_freg dot = w.z * x.z + w.y * x.y + x.x * w.x;
    f2c = dot;
    hulk_freg lo = d->f20;
    if (dot < lo)
        f2c = lo;
    if (f2c < 0.0f)
        f2c = 0;
    hulk_freg dur = d->f14;
    if (dur > 0.0f) {
        hulk_freg twice = d->f18 + d->f18;
        f28 = twice / dur;
        f30 = twice / (dur * dur);
    }

    DAT_004dd700->manager->FUN_00099d20(DAT_004dd700, stats, f2c, f28, f30);
    return 1;
}

}}
} // namespace fn_001347c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00134970 hulkfight::motion::BounceAction::vfunc_4 (37 B): matches/0x00134970.cpp
// sym: ?vfunc_4@BounceAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00134160 (propagated; names are from that function)
void hulkfight::motion::BounceAction::vfunc_4() {
    void* x = (*(One * *)&this->f_20)->f();
    void* y = ((Two_134970*)x)->Fnf_00059a40();
    if (y)
        ((Three*)y)->f((*(void * *)&this->f_24), 0);
}


// 0x001349a0 hulkfight::motion::AirToGroundTargetAction::vfunc_3 (371 B): equivalent/0x001349a0.cpp [wrapped: conflict: JointDriver; Skeleton; World]
// sym: ?vfunc_3@AirToGroundTargetAction@fn_001349a0@@UAE_NHH@Z @03318a111106 @wfcf7f806df9a
namespace fn_001349a0 {
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 6/6)
// hulkfight::motion::AirToGroundTargetAction::vfunc_3 @ 0x001349a0
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

struct V3_1349a0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Name_1349a0 {
    unsigned int lo, hi;
};
struct Xform_1349a0 {
    char data[0x54];
    void FUN_00221be0(const Xform_1349a0* src);
};
void* FUN_00263ea0(unsigned int size);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name_1349a0 name;
    char pad10[8];
    Xform_1349a0 xform;
    JointDriver* FUN_002248f0(int a);
};

struct Timing_1349a0 {
    bool FUN_00035550(V3_1349a0* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform_1349a0 xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock_1349a0 {
    Timing_1349a0* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target_1349a0 {
};
struct Config_1349a0 {
    char pad0[0x20];
    float f20;
    char pad24[8];
    float f2c;
    float f30;
    float f34;
};
struct Sink_1349a0 {
    void FUN_00099d40(struct World* w, Timing_1349a0* t, float v);
};
struct World {
    char pad0[8];
    Sink_1349a0* sink;
};

class AirToGroundTargetAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config_1349a0* cfg;
    Target_1349a0* target;
    JointDriver* driver;
    char pad28[4];
    float speed;
    float lateral;
};

bool AirToGroundTargetAction::vfunc_3(int a, int b)
{
    Clock_1349a0* clock = ((Clock_1349a0 *)((owners::Object_592a0 *)target)->FUN_000592a0());
    Timing_1349a0* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    Config_1349a0* c = cfg;
    hulk_freg c30 = c->f30;
    hulk_freg c34 = c->f34;
    hulk_freg c2c = c->f2c;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    ((owners::Target_27b040 *)&(d->name))->FUN_0027b040((hulk_uintptr)"airToGroundTarget");
    driver->AddRef();
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c2c, 1.0f, c30, c34, -1.0f);
    V3_1349a0 fwd;
    fwd.x = 0.0f;
    fwd.y = 0.0f;
    fwd.z = -1.0f;
    timing->FUN_00035550(&fwd);
    fwd.y = 0.0f;
    fwd.FUN_0022d110();
    V3_1349a0 vel;
    vel.x = 0.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    ((owners::Thing_356c0 *)timing)->FUN_000356c0((unsigned int *)(V3_1349a0 *)(&vel));
    lateral = vel.y;
    vel.y = 0.0f;
    hulk_freg s = vel.x * fwd.x + vel.z * fwd.z + fwd.y * 0.0f;
    if (s < 0.0f)
        speed = 0.0f;
    else
        speed = s;
    DAT_004dd700->sink->FUN_00099d40(DAT_004dd700, timing, cfg->f20);
    return true;
}
} // namespace fn_001349a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f414acda {

// 0x00134b60 FUN_00134b60 (11 B): matches/0x00134b60.cpp
// sym: ?FUN_00134b60@fn_f414acda@@YAXPAHH@Z
void __cdecl FUN_00134b60(int* p, int value) {
    *p = value;
}


// 0x00134c00 hulkfight::motion::FlyingDashTrack::vfunc_5 (36 B): matches/0x00134c00.cpp
// sym: ?vfunc_5@FlyingDashTrack_134c00@fn_f414acda@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FlyingDashTrack_134c00* FlyingDashTrack_134c00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00411bb8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00134c30 hulkfight::motion::GrappleHoverTrack::vfunc_5 (36 B): matches/0x00134c30.cpp
// sym: ?vfunc_5@GrappleHoverTrack_134c30@fn_f414acda@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
GrappleHoverTrack_134c30* GrappleHoverTrack_134c30::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00411be8;
    Destroy_00236d60();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f414acda
