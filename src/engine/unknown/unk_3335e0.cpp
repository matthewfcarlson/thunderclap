// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003335e0..0x003338a0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0b54823 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0b54823 {} using namespace fn_f0b54823;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f0b54823 {
typedef unsigned int U_3335e0;
extern "C" U_3335e0* __cdecl FUN_0031c680(U_3335e0* out, U_3335e0 color, U_3335e0 mask, U_3335e0 alpha);
struct ThisCall_003335e0 {
};
struct Object {
    char pad[0x30];
    float value;
    void FUN_00333780(float input);
};
class T_3337d0 {
  public:
    char pad[0x48];
    char mFlag;
    void Set(void* p);
};
class A_3337f0 {
  public:
    char pad[0x6c];
    int m6c;
    void Set(int x);
};
class A_333800 {
  public:
    char pad[0x64];
    int m64;
    void Set(int arg);
};
class Obj_333810 {
  public:
    char pad[0x68];
    int m68;
    void Set(int x);
};
class Body_333820 {
  public:
    char pad[0x70];
    int mX;
    void SetX(int v);
};

} // namespace fn_f0b54823

// 0x003335e0 FUN_003335e0 (360 B): equivalent/0x003335e0.cpp
// sym: ?FUN_003335e0@Obj_3335e0@owners@@QAEXXZ @2c6ad95d3be4 @w5619a25df0d9
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 23/23)
// FUN_003335e0 @ 0x003335e0
void owners::Obj_3335e0::FUN_003335e0()
{
    // Frame slots: t1 shares the slot the original uses for the int->float conversion of 255 - alpha.
    struct Locals { U_3335e0 t1, t2, t3, t4, t5; } local;
    U_3335e0 a0 = alpha;
    U_3335e0 inverse = 255 - a0;
    local.t1 = inverse;
    activeMode = (mode == 0 && a0 > 0) ? 1 : mode;
    double v = (double)inverse * 0.0039215688593685627f * scale;
    if (!(v >= 0.0f && v <= 1.0f))
        v = (v > 1.0f) ? 1.0f : 0.0f;
    result = (float)v;
    c58 = c6c;
    c50 = c64;
    c54 = c68;
    c5c = c70;
    if (!enabled)
        return;
    switch (activeMode) {
    case 1:
    case 7:
        c50 = (c50 & 0xffffff) | ((((c50 >> 24) * inverse) << 16) & 0xff000000);
        break;
    case 2:
    case 3: {
        U_3335e0 *r = FUN_0031c680(&local.t1, c6c, 0xff000000, a0);
        U_3335e0 a = alpha;
        U_3335e0 val = *r;
        U_3335e0 arg = c64;
        c58 = val;
        r = FUN_0031c680(&local.t2, arg, 0xff000000, a);
        a = alpha;
        val = *r;
        arg = c68;
        c50 = val;
        r = FUN_0031c680(&local.t3, arg, 0xff000000, a);
        val = *r;
        a = alpha;
        arg = c70;
        c54 = val;
        r = FUN_0031c680(&local.t4, arg, 0xff000000, a);
        c5c = *r;
        break;
    }
    case 4:
    case 5:
        c5c = *FUN_0031c680(&local.t5, c70, 0xffffffff, a0);
        break;
    }
}


// 0x00333770 FUN_00333770 (15 B): matches/0x00333770.cpp
// sym: ?FUN_00333770@C_333770@owners@@QAEXH@Z
// Same code shape as 0x0030a260 (propagated; names are from that function)
void owners::C_333770::FUN_00333770(int x) {
    value = x;
    ((owners::Obj_3335e0 *)(((ThisCall_003335e0*)(this))))->FUN_003335e0();
}

namespace fn_f0b54823 {

// 0x00333780 FUN_00333780 (77 B): equivalent/0x00333780.cpp
// sym: ?FUN_00333780@Object@fn_f0b54823@@QAEXM@Z @e46f0baaf3df @w40e917982e71
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00333780 @ 0x00333780
void Object::FUN_00333780(float input) {
    if (input < (*(float*)&DAT_003f32e0))
        value = (*(float*)&DAT_003f32e0);
    else if (input > (*(float*)&DAT_003f32dc))
        value = (*(float*)&DAT_003f32dc);
    else
        value = input;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}


// 0x003337d0 FUN_003337d0 (20 B): matches/0x003337d0.cpp
// sym: ?Set@T_3337d0@fn_f0b54823@@QAEXPAX@Z
void T_3337d0::Set(void* p) {
    mFlag = (p != 0);
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}


// 0x003337f0 FUN_003337f0 (15 B): matches/0x003337f0.cpp
// sym: ?Set@A_3337f0@fn_f0b54823@@QAEXH@Z
void A_3337f0::Set(int x) {
    m6c = x;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}


// 0x00333800 FUN_00333800 (15 B): matches/0x00333800.cpp
// sym: ?Set@A_333800@fn_f0b54823@@QAEXH@Z
void A_333800::Set(int arg) {
    m64 = arg;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}


// 0x00333810 FUN_00333810 (15 B): matches/0x00333810.cpp
// sym: ?Set@Obj_333810@fn_f0b54823@@QAEXH@Z
void Obj_333810::Set(int x) {
    m68 = x;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}


// 0x00333820 FUN_00333820 (15 B): matches/0x00333820.cpp
// sym: ?SetX@Body_333820@fn_f0b54823@@QAEXH@Z
void Body_333820::SetX(int v) {
    mX = v;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}

} // namespace fn_f0b54823

// 0x00333830 FUN_00333830 (85 B): equivalent/0x00333830.cpp [wrapped: conflict: Object]
// sym: ?FUN_00333830@Object@fn_00333830@@QAEXM@Z @38867181918d @w05beb5d9cc3c
namespace fn_00333830 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_00333830 @ 0x00333830
struct Object { char pad[0x38]; int value;  void FUN_00333830(float amount); };
void Object::FUN_00333830(float amount) {
    int result = (int)(amount * 255.0f);
    if (result < 0) result = 0;
    else if (result > 255) result = 255;
    value = result;
    ((owners::Obj_3335e0 *)this)->FUN_003335e0();
}
} // namespace fn_00333830

