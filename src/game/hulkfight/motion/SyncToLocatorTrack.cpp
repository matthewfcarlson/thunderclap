// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170030..0x00170100 (kind game, layer game, confidence high), dominant class hulkfight::motion::SyncToLocatorTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_fde03247 {
#define TREE_TU_END }
namespace fn_fde03247 {} using namespace fn_fde03247;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fde03247 {
struct Tail_170030 {
    void Init_0027af50();
};
struct JointRelativeTrack_170030 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00417958;
extern int* hulk_at_004e1310;
class CCondition_170070 {
  public:
    virtual int vfunc_0(int);
};
class Track_170080 {
  public:
    Track_170080();
    virtual void a();
    virtual void b();
    int x, y;
};
class Sub_170080 {
  public:
    Sub_170080();
    int a, b;
};
class SyncToLocatorTrack : public Track_170080 {
  public:
    SyncToLocatorTrack();
    virtual void a();
    virtual void b();
    int m0;
    float f0, f1, f2;
    char pad[4];
    Sub_170080 sub;
    int fields[10];
};
struct Param_1700f0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1700f0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170030 FUN_00170030 (25 B): matches/0x00170030.cpp
// sym: ?Run@JointRelativeTrack_170030@fn_fde03247@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void JointRelativeTrack_170030::Run() {
    vptr = &hulk_at_00417958;
    ((Tail_170030*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x00170050 FUN_00170050 (19 B): matches/0x00170050.cpp
// sym: ?FUN_00170050@fn_fde03247@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170050() {
    FUN_00234810(((char*)&DAT_004e1310), ((char*)&DAT_004e1314));
}

} // namespace fn_fde03247

// 0x00170070 hulkfight::motion::SyncToLocatorTrack::vfunc_0 (16 B): matches/0x00170070.cpp
// sym: ?vfunc_0@SyncToLocatorTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SyncToLocatorTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1310;
    return p[index];
}

namespace fn_fde03247 {

// 0x00170080 FUN_00170080 (92 B): matches/0x00170080.cpp
// sym: ??0SyncToLocatorTrack@fn_fde03247@@QAE@XZ
SyncToLocatorTrack::SyncToLocatorTrack() : m0(0), f0(1.0f), f1(-1.0f), f2(-1.0f) {
    fields[0] = 0;
    fields[1] = 0;
    fields[2] = 0;
    fields[3] = 0;
    fields[4] = 0;
    fields[5] = 0;
    fields[6] = 0;
    fields[8] = 0;
    fields[9] = 0;
    fields[7] = -5;
    y = 1;
}

} // namespace fn_fde03247

// 0x001700e0 hulkfight::motion::SyncToLocatorTrack::vfunc_6 (4 B): matches/0x001700e0.cpp
// sym: ?vfunc_6@SyncToLocatorTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SyncToLocatorTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001700f0 hulkfight::motion::SyncToLocatorTrack::vfunc_7 (7 B): matches/0x001700f0.cpp
// sym: ?vfunc_7@SyncToLocatorTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::SyncToLocatorTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

