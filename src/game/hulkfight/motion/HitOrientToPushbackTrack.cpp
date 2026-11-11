// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014dfb0..0x0014e040 (kind game, layer game, confidence high), dominant class hulkfight::motion::HitOrientToPushbackTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fdf4ce5e {
#define TREE_TU_END }
namespace fn_fdf4ce5e {} using namespace fn_fdf4ce5e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fdf4ce5e {
extern int* gTable_14dfd0;
class CCondition_14dfd0 {
  public:
    virtual int vfunc_0(int);
};
class Track_14dfe0 {
  public:
    Track_14dfe0();
    virtual void f();
    char pad[8];
    int a;
    float b;
    int c;
    int d;
    int e;
    int g;
};
class HitOrientToPushbackTrack : public Track_14dfe0 {
  public:
    HitOrientToPushbackTrack();
    virtual void f();
};
struct Param_14e020 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_14e020 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x0014dfb0 FUN_0014dfb0 (19 B): matches/0x0014dfb0.cpp
// sym: ?FUN_0014dfb0@fn_fdf4ce5e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dfb0() {
    FUN_00234810(((char*)&DAT_004e1108), ((char*)&DAT_004e110c));
}

} // namespace fn_fdf4ce5e

// 0x0014dfd0 hulkfight::motion::HitOrientToPushbackTrack::vfunc_0 (16 B): matches/0x0014dfd0.cpp
// sym: ?vfunc_0@HitOrientToPushbackTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitOrientToPushbackTrack::vfunc_0(int index) {
    int* p = gTable_14dfd0;
    return p[index];
}

namespace fn_fdf4ce5e {

// 0x0014dfe0 FUN_0014dfe0 (46 B): matches/0x0014dfe0.cpp
// sym: ??0HitOrientToPushbackTrack@fn_fdf4ce5e@@QAE@XZ
HitOrientToPushbackTrack::HitOrientToPushbackTrack() {
    a = 0;
    c = 0;
    e = 0;
    g = 0;
    b = -1.0f;
    d = -5;
}

} // namespace fn_fdf4ce5e

// 0x0014e010 hulkfight::motion::HitOrientToPushbackTrack::vfunc_6 (4 B): matches/0x0014e010.cpp
// sym: ?vfunc_6@HitOrientToPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::HitOrientToPushbackTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0014e020 hulkfight::motion::HitOrientToPushbackTrack::vfunc_7 (7 B): matches/0x0014e020.cpp
// sym: ?vfunc_7@HitOrientToPushbackTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::HitOrientToPushbackTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

