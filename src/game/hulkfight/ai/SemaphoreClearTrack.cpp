// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010d080..0x0010d0f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreClearTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f31cf280 {
#define TREE_TU_END }
namespace fn_f31cf280 {} using namespace fn_f31cf280;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f31cf280 {
extern int* gTable_10d080;
class CCondition_10d080 {
  public:
    virtual int vfunc_0(int);
};
class Track_10d090 {
  public:
    Track_10d090();
    virtual void f();
    char p[4];
};
class Sub {
  public:
    Sub();
    char data[8];
};
class SemaphoreClearTrack : public Track_10d090 {
  public:
    SemaphoreClearTrack();
    virtual void f();
    char a[4];
    int n;
    float v;
    char pad[4];
    Sub sub;
    char x, y;
};
struct Param_10d0e0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10d0e0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

} // namespace fn_f31cf280

// 0x0010d080 hulkfight::ai::SemaphoreClearTrack::vfunc_0 (16 B): matches/0x0010d080.cpp
// sym: ?vfunc_0@SemaphoreClearTrack@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::SemaphoreClearTrack::vfunc_0(int index) {
    int* p = gTable_10d080;
    return p[index];
}

namespace fn_f31cf280 {

// 0x0010d090 FUN_0010d090 (55 B): matches/0x0010d090.cpp
// sym: ??0SemaphoreClearTrack@fn_f31cf280@@QAE@XZ
SemaphoreClearTrack::SemaphoreClearTrack() : Track_10d090(), n(0), v(-1.0f), sub(), x(0), y(0) {
    *(int*)((char*)this + 8) = 1;
}

} // namespace fn_f31cf280

// 0x0010d0d0 hulkfight::ai::SemaphoreClearTrack::vfunc_6 (4 B): matches/0x0010d0d0.cpp
// sym: ?vfunc_6@SemaphoreClearTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::ai::SemaphoreClearTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0010d0e0 hulkfight::ai::SemaphoreClearTrack::vfunc_7 (7 B): matches/0x0010d0e0.cpp
// sym: ?vfunc_7@SemaphoreClearTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::SemaphoreClearTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

