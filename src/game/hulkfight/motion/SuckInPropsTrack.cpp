// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170b70..0x00170c10 (kind game, layer game, confidence high), dominant class hulkfight::motion::SuckInPropsTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fb2fdc2a {
#define TREE_TU_END }
namespace fn_fb2fdc2a {} using namespace fn_fb2fdc2a;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb2fdc2a {
extern int* gTable_170b90;
class CCondition_170b90 {
  public:
    virtual int vfunc_0(int);
};
class Track_170ba0 {
  public:
    Track_170ba0();
    virtual void f();
    int baseField;
};
class SuckInPropsTrack : public Track_170ba0 {
  public:
    SuckInPropsTrack();
    virtual void f();
    int flag;
    int a;
    float b;
    int c;
    int d;
    float e;
};
struct Param_170bf0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170bf0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170b70 FUN_00170b70 (19 B): matches/0x00170b70.cpp
// sym: ?FUN_00170b70@fn_fb2fdc2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170b70() {
    FUN_00234810(((char*)&DAT_004e1388), ((char*)&DAT_004e138c));
}

} // namespace fn_fb2fdc2a

// 0x00170b90 hulkfight::motion::SuckInPropsTrack::vfunc_0 (16 B): matches/0x00170b90.cpp
// sym: ?vfunc_0@SuckInPropsTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SuckInPropsTrack::vfunc_0(int index) {
    int* p = gTable_170b90;
    return p[index];
}

namespace fn_fb2fdc2a {

// 0x00170ba0 FUN_00170ba0 (50 B): matches/0x00170ba0.cpp
// sym: ??0SuckInPropsTrack@fn_fb2fdc2a@@QAE@XZ
SuckInPropsTrack::SuckInPropsTrack() {
    a = 0;
    c = 0;
    d = 0;
    b = -1.0f;
    e = 20.0f;
    flag = 1;
}

} // namespace fn_fb2fdc2a

// 0x00170be0 hulkfight::motion::SuckInPropsTrack::vfunc_6 (4 B): matches/0x00170be0.cpp
// sym: ?vfunc_6@SuckInPropsTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SuckInPropsTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170bf0 hulkfight::motion::SuckInPropsTrack::vfunc_7 (7 B): matches/0x00170bf0.cpp
// sym: ?vfunc_7@SuckInPropsTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::SuckInPropsTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

