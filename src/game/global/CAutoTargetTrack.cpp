// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00069c20..0x00069da0 (kind game, layer game, confidence high), dominant class CAutoTargetTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fabf106d {
#define TREE_TU_END }
namespace fn_fabf106d {} using namespace fn_fabf106d;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fabf106d {
extern int* hulk_at_004dcf68;
class CCondition_69c40 {
  public:
    virtual int vfunc_0(int);
};
struct Param_69cd0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_69cd0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Obj {
    char pad[20];
    float angle;

  public:
    char Set(float x);
};
class Obj_69d30 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetBase();
    char pad4[0x10 - 4];
    float unused10;
    float scale;
    hulk_freg Get();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Helper_69d70 {
  public:
    int FUN_0001d4c0(CAutoTargetTrack*, hulk_intptr);
};


// 0x00069c20 FUN_00069c20 (19 B): matches/0x00069c20.cpp
// sym: ?FUN_00069c20@fn_fabf106d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00069c20() {
    FUN_00234810(((char*)&DAT_004dcf68), ((char*)&DAT_004dcf6c));
}

} // namespace fn_fabf106d

// 0x00069c40 CAutoTargetTrack::vfunc_0 (16 B): matches/0x00069c40.cpp
// sym: ?vfunc_0@CAutoTargetTrack@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAutoTargetTrack::vfunc_0(int index) {
    int* p = hulk_at_004dcf68;
    return p[index];
}


// 0x00069c50 FUN_00069c50 (84 B): equivalent/0x00069c50.cpp [wrapped: conflict: CAutoTargetTrack]
// sym: ??0CAutoTargetTrack@fn_00069c50@@QAE@XZ
namespace fn_00069c50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00069c50 @ 0x00069c50
struct FUN_00236d40 { virtual void placeholder(); char baseData[4]; FUN_00236d40(); };
struct CAutoTargetTrack : FUN_00236d40 {
    int flag;
    int unknownC;
    float a, b, c, d;
    int enabled, pointer24, pointer28, index, pointer30, pointer34;
    unsigned char byte38;
    CAutoTargetTrack();
};
CAutoTargetTrack::CAutoTargetTrack() {
    unknownC = 0;
    pointer24 = 0;
    pointer28 = 0;
    pointer30 = 0;
    pointer34 = 0;
    byte38 = 0;
    a = -1.0f;
    b = 3.14159274f;
    c = 1.57079637f;
    d = 10.0f;
    enabled = 1;
    index = -5;
    flag = 1;
}
} // namespace fn_00069c50


// 0x00069cb0 CAutoTargetTrack::vfunc_13 (13 B): matches/0x00069cb0.cpp
// sym: ?vfunc_13@CAutoTargetTrack@@UAEXPAX@Z
// Same code shape as 0x00069020 (propagated; names are from that function)
void CAutoTargetTrack::vfunc_13(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    *p = 0xff0000ff;
}


// 0x00069cc0 CAutoTargetTrack::vfunc_6 (4 B): matches/0x00069cc0.cpp
// sym: ?vfunc_6@CAutoTargetTrack@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CAutoTargetTrack::vfunc_6() {
    return this->f_0c;
}


// 0x00069cd0 CAutoTargetTrack::vfunc_7 (7 B): matches/0x00069cd0.cpp
// sym: ?vfunc_7@CAutoTargetTrack@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CAutoTargetTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}

namespace fn_fabf106d {

// 0x00069cf0 FUN_00069cf0 (18 B): matches/0x00069cf0.cpp
// sym: ?Set@Obj@fn_fabf106d@@QAEDM@Z
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}

} // namespace fn_fabf106d

// 0x00069d10 FUN_00069d10 (18 B): matches/0x00069d10.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00069d10@@QAEDM@Z
namespace fn_00069d10 {
class Obj {
  public:
    char pad[0x18];
    float angle;
    char Set(float x);
};
char Obj::Set(float x) {
    angle = x * 0.017453292f;
    return 1;
}
} // namespace fn_00069d10

namespace fn_fabf106d {

// 0x00069d30 FUN_00069d30 (61 B): matches/0x00069d30.cpp
// sym: ?Get@Obj_69d30@fn_fabf106d@@QAEMXZ
hulk_freg Obj_69d30::Get()
{
    hulk_freg base = GetBase();
    if (base <= 0.0f)
        return -1.0f;
    if (scale <= 0.0f)
        return -1.0f;
    return base * scale;
}

} // namespace fn_fabf106d

// 0x00069d70 CAutoTargetTrack::vfunc_12 (40 B): matches/0x00069d70.cpp
// sym: ?vfunc_12@CAutoTargetTrack@@UAEHH@Z
// Same code shape as 0x000694c0 (propagated; names are from that function)
hulk_intptr CAutoTargetTrack::vfunc_12(hulk_intptr param) {
    void* p = FUN_0008d690(0x30);
    if (p)
        return ((Helper_69d70*)p)->FUN_0001d4c0(this, param);
    return 0;
}

