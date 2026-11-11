// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00133980..0x00133a00 (kind game, layer game, confidence high), dominant class hulkfight::motion::FlyingDashTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fecf82fa {
#define TREE_TU_END }
namespace fn_fecf82fa {} using namespace fn_fecf82fa;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fecf82fa {
extern int* hulk_at_004e0ec0;
class CCondition_133980 {
  public:
    virtual int vfunc_0(int);
};
class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Track_133990 : public Base {
  public:
    Track_133990() {
        a = 0;
        b = 0;
        c = 0;
    }
    int a;
    float x;
    float y;
    int z;
    int b;
    int c;
};
class FlyingDashTrack : public Track_133990 {
  public:
    FlyingDashTrack();
    virtual void f();
};
struct Param_1339e0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1339e0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_fecf82fa

// 0x00133980 hulkfight::motion::FlyingDashTrack::vfunc_0 (16 B): matches/0x00133980.cpp
// sym: ?vfunc_0@FlyingDashTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::FlyingDashTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0ec0;
    return p[index];
}

namespace fn_fecf82fa {

// 0x00133990 FUN_00133990 (50 B): matches/0x00133990.cpp
// sym: ??0FlyingDashTrack@fn_fecf82fa@@QAE@XZ
FlyingDashTrack::FlyingDashTrack() {
    x = -1.0f;
    y = 50.0f;
    z = -5;
}

} // namespace fn_fecf82fa

// 0x001339d0 hulkfight::motion::FlyingDashTrack::vfunc_6 (4 B): matches/0x001339d0.cpp
// sym: ?vfunc_6@FlyingDashTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::FlyingDashTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001339e0 hulkfight::motion::FlyingDashTrack::vfunc_7 (7 B): matches/0x001339e0.cpp
// sym: ?vfunc_7@FlyingDashTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::FlyingDashTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

