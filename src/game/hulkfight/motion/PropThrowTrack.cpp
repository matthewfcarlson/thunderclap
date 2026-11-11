// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180ed0..0x00180fc0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropThrowTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fb360e22 {
#define TREE_TU_END }
namespace fn_fb360e22 {} using namespace fn_fb360e22;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb360e22 {
extern int* hulk_at_004e1498;
class CCondition_180ef0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_180fb0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_180fb0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00180ed0 FUN_00180ed0 (19 B): matches/0x00180ed0.cpp
// sym: ?FUN_00180ed0@fn_fb360e22@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180ed0() {
    FUN_00234810(((char*)&DAT_004e1498), ((char*)&DAT_004e149c));
}

} // namespace fn_fb360e22

// 0x00180ef0 hulkfight::motion::PropThrowTrack::vfunc_0 (16 B): matches/0x00180ef0.cpp
// sym: ?vfunc_0@PropThrowTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropThrowTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1498;
    return p[index];
}


// 0x00180f00 FUN_00180f00 (146 B): equivalent/0x00180f00.cpp [wrapped: conflict: hulkfight::motion::PropThrowTrack]
// sym: ?FUN_00180f00@PropThrowTrack@motion@hulkfight@fn_00180f00@@QAEPAV1234@XZ @c9905223d9e6 @wf8cf7a9d5983
inline void *operator new(size_t, void *p) { return p; }
namespace fn_00180f00 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00180f00 @ 0x00180f00


struct PropThrowTrack_180f00 {
    char data[12];
    void FUN_00236d40();
};
struct Name8_180f00 {
    int lo, hi;
    void FUN_0027af00();
};
struct Name12 {
    int a, b, c;
    void FUN_00233dd0();
};

namespace hulkfight {
namespace motion {
class PropThrowTrack {
public:
    virtual hulk_intptr vfunc_0_00180ef0(int);
    int f04;
    int f08;
    int f0c;
    float f10;
    int f14;
    char b18;
    char pad19[3];
    int f1c, f20;
    float f24, f28, f2c, f30, f34, f38, f3c, f40;
    int f44, f48, f4c, f50, f54, f58;
    float f5c, f60;
    int f64;
    Name12 n68;
    char pad74[4];
    Name8_180f00 n78;
    char b80;
    char pad81[3];

    PropThrowTrack() {}
    PropThrowTrack *FUN_00180f00();
};
}
}

hulkfight::motion::PropThrowTrack *hulkfight::motion::PropThrowTrack::FUN_00180f00()
{
    ((PropThrowTrack_180f00 *)this)->FUN_00236d40();
    new (this) PropThrowTrack;
    f10 = -1.0f;
    f0c = 0;
    f14 = 0;
    b18 = 0;
    f24 = -1.0f;
    f1c = 0;
    f20 = 0;
    f2c = 100.0f;
    f34 = 100.0f;
    f5c = 100.0f;
    f60 = 100.0f;
    f28 = 10.0f;
    f30 = 10.0f;
    f38 = 0.17453294f;
    f3c = 1.7453293f;
    f40 = 1.5707964f;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    f64 = 0;
    n68.FUN_00233dd0();
    n78.FUN_0027af00();
    b80 = 1;
    f08 = 1;
    return this;
}
} // namespace fn_00180f00


// 0x00180fa0 hulkfight::motion::PropThrowTrack::vfunc_6 (4 B): matches/0x00180fa0.cpp
// sym: ?vfunc_6@PropThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropThrowTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00180fb0 hulkfight::motion::PropThrowTrack::vfunc_7 (7 B): matches/0x00180fb0.cpp
// sym: ?vfunc_7@PropThrowTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropThrowTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

