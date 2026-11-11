// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00170950..0x00170a40 (kind game, layer game, confidence high), dominant class hulkfight::motion::SurfTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f3cfc85f {
#define TREE_TU_END }
namespace fn_f3cfc85f {} using namespace fn_f3cfc85f;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f3cfc85f {
struct Tail_170950 {
    void Init_0027af50();
};
struct JointPivotTrackerTrack_170950 {
    void* vptr;
    char pad[0x14];
    void Finish_00236d60();
    void Run();
};
extern void* hulk_at_00417b98;
extern int* hulk_at_004e1370;
class CCondition_170990 {
  public:
    virtual int vfunc_0(int);
};
struct Param_170a20 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_170a20 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};


// 0x00170950 FUN_00170950 (25 B): matches/0x00170950.cpp
// sym: ?Run@JointPivotTrackerTrack_170950@fn_f3cfc85f@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void JointPivotTrackerTrack_170950::Run() {
    vptr = &hulk_at_00417b98;
    ((Tail_170950*)((char*)this + 0x18))->Init_0027af50();
    Finish_00236d60();
}


// 0x00170970 FUN_00170970 (19 B): matches/0x00170970.cpp
// sym: ?FUN_00170970@fn_f3cfc85f@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00170970() {
    FUN_00234810(((char*)&DAT_004e1370), ((char*)&DAT_004e1374));
}

} // namespace fn_f3cfc85f

// 0x00170990 hulkfight::motion::SurfTrack::vfunc_0 (16 B): matches/0x00170990.cpp
// sym: ?vfunc_0@SurfTrack@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SurfTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1370;
    return p[index];
}


// 0x001709a0 FUN_001709a0 (98 B): equivalent/0x001709a0.cpp [wrapped: conflict: hulkfight::motion::SurfTrack]
// sym: ??0SurfTrack@motion@hulkfight@fn_001709a0@@QAE@XZ @03b2f56c899e @w170039b8e358
namespace fn_001709a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001709a0 @ 0x001709a0
namespace hulkfight { namespace motion {
struct FUN_00236d40 {
    virtual void Update();
    char unknown[8];
    FUN_00236d40();
};
struct SurfTrack : FUN_00236d40 {
    int field0c;
    float field10, field14, field18, field1c, field20;
    int field24, field28;
    float field2c, field30, field34, field38;
    int field3c, field40, field44;
    virtual void Update();
    SurfTrack();
};
SurfTrack::SurfTrack() {
    field0c = field24 = field28 = field40 = field44 = 0;
    field10 = -1.0f;
    field14 = 20.0f;
    field18 = 21.0f;
    field1c = 10.0f;
    field20 = 50.0f;
    field2c = 0.7853982f;
    field30 = 6.2831855f;
    field34 = field38 = 0.7853982f;
    field3c = -5;
}
} }
} // namespace fn_001709a0


// 0x00170a10 hulkfight::motion::SurfTrack::vfunc_6 (4 B): matches/0x00170a10.cpp
// sym: ?vfunc_6@SurfTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::motion::SurfTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00170a20 hulkfight::motion::SurfTrack::vfunc_7 (7 B): matches/0x00170a20.cpp
// sym: ?vfunc_7@SurfTrack@motion@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::motion::SurfTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

