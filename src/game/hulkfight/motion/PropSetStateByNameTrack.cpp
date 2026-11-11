// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00180bd0..0x00180c50 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropSetStateByNameTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f050cd5e {
#define TREE_TU_END }
namespace fn_f050cd5e {} using namespace fn_f050cd5e;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f050cd5e {
extern int* gTable_180bf0;
class CCondition_180bf0 {
  public:
    virtual int vfunc_0(int);
};


// 0x00180bd0 FUN_00180bd0 (19 B): matches/0x00180bd0.cpp
// sym: ?FUN_00180bd0@fn_f050cd5e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180bd0() {
    FUN_00234810(((char*)&DAT_004e1470), ((char*)&DAT_004e1474));
}

} // namespace fn_f050cd5e

// 0x00180bf0 hulkfight::motion::PropSetStateByNameTrack::vfunc_0 (16 B): matches/0x00180bf0.cpp
// sym: ?vfunc_0@PropSetStateByNameTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropSetStateByNameTrack::vfunc_0(int index) {
    int* p = gTable_180bf0;
    return p[index];
}


// 0x00180c00 FUN_00180c00 (47 B): matches/0x00180c00.cpp [wrapped: conflict: hulkfight::motion::PropSetStateByNameTrack]
// sym: ??0PropSetStateByNameTrack@motion@hulkfight@fn_00180c00@@QAE@XZ
namespace fn_00180c00 {
namespace hulkfight {
namespace motion {
class Base {
  public:
    virtual void f();
    Base();
    char pad[4];
};
class Elem {
  public:
    Elem();
};
class PropSetStateByNameTrack : public Base {
  public:
    virtual void f();
    PropSetStateByNameTrack();
    int m8;
    int mC;
    int m10;
    char pad14[4];
    Elem m18;
};
PropSetStateByNameTrack::PropSetStateByNameTrack() : Base(), mC(0), m10(-1), m18() {
    m8 = 1;
}
} // namespace motion
} // namespace hulkfight
} // namespace fn_00180c00


// 0x00180c30 hulkfight::motion::PropSetStateByNameTrack::vfunc_6 (4 B): matches/0x00180c30.cpp
// sym: ?vfunc_6@PropSetStateByNameTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::PropSetStateByNameTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00180c40 hulkfight::motion::PropSetStateByNameTrack::vfunc_7 (7 B): matches/0x00180c40.cpp
// sym: ?vfunc_7@PropSetStateByNameTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::motion::PropSetStateByNameTrack::vfunc_7() {
    return DAT_003f32e0;
}

