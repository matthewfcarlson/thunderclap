// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00068cc0..0x00068df0 (kind game, layer game, confidence high), dominant class CJointTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f51b6026 {
#define TREE_TU_END }
namespace fn_f51b6026 {} using namespace fn_f51b6026;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f51b6026 {
extern int* hulk_at_004dcf08;
class CCondition_68ce0 {
  public:
    virtual int vfunc_0(int);
};
struct Param_68d30 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_68d30 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Angles { char pad[0x34]; float x, y, z; void FUN_00068d40(float *out); };
struct Vec {
    float x, y, z;
};
class Obj {
    char pad[0x34];
    float x, y, z;

  public:
    unsigned char Set(const Vec* v);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Helper_68dc0 {
    int FUN_00018b90(CJointTrack*, hulk_intptr);
};


// 0x00068cc0 FUN_00068cc0 (19 B): matches/0x00068cc0.cpp
// sym: ?FUN_00068cc0@fn_f51b6026@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00068cc0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dcf08), ((char*)&DAT_004dcf0c));
}

} // namespace fn_f51b6026

// 0x00068ce0 CJointTrack::vfunc_0 (16 B): matches/0x00068ce0.cpp
// sym: ?vfunc_0@CJointTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CJointTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf08;
    return p[index];
}


// 0x00068cf0 FUN_00068cf0 (31 B): matches/0x00068cf0.cpp [wrapped: conflict: CJointTrack]
// sym: ?Init@CJointTrack@fn_00068cf0@@QAEXXZ
namespace fn_00068cf0 {
extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fb9c4[];
class Part_68cf0 {
  public:
    void Init_0027af50();
};
class CJointTrack {
  public:
    char pad[0x18];
    Part_68cf0 part;
    void Finish_00236d60();
    void Init();
};
void CJointTrack::Init() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003fb9c4);
    part.Init_0027af50();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f98d0);
    Finish_00236d60();
}
} // namespace fn_00068cf0


// 0x00068d10 CJointTrack::vfunc_13 (13 B): matches/0x00068d10.cpp
// sym: ?vfunc_13@CJointTrack@@UAEXPAX@Z
void CJointTrack::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = 0xffff7f7f;
}


// 0x00068d20 CJointTrack::vfunc_6 (4 B): matches/0x00068d20.cpp
// sym: ?vfunc_6@CJointTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CJointTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00068d30 CJointTrack::vfunc_7 (7 B): matches/0x00068d30.cpp
// sym: ?vfunc_7@CJointTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CJointTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_f51b6026 {

// 0x00068d40 FUN_00068d40 (72 B): equivalent/0x00068d40.cpp
// sym: ?FUN_00068d40@Angles@fn_f51b6026@@QAEXPAM@Z @f02e11c46d5d @wa016881bf4fd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00068d40 @ 0x00068d40
void Angles::FUN_00068d40(float *out) {
    out[0] = x * (*(float*)&DAT_003f3ef4);
    out[1] = y * (*(float*)&DAT_003f3ef4);
    out[2] = z * (*(float*)&DAT_003f3ef4);
}


// 0x00068d90 FUN_00068d90 (44 B): matches/0x00068d90.cpp
// sym: ?Set@Obj@fn_f51b6026@@QAEEPBUVec@2@@Z
unsigned char Obj::Set(const Vec* v) {
    x = v->x * 0.017453292f;
    y = v->y * 0.017453292f;
    z = v->z * 0.017453292f;
    return 1;
}

} // namespace fn_f51b6026

// 0x00068dc0 CJointTrack::vfunc_12 (40 B): matches/0x00068dc0.cpp
// sym: ?vfunc_12@CJointTrack@@UAEHH@Z
// Same code shape as 0x0005dd70 (propagated; names are from that function)
hulk_intptr CJointTrack::vfunc_12(hulk_intptr param) {
    Helper_68dc0* p = (Helper_68dc0*)FUN_0008d690(0x28);
    if (p)
        return p->FUN_00018b90(this, param);
    return 0;
}

