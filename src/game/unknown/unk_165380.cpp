// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00165380..0x001665e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5579237 {
#define TREE_TU_END }
namespace fn_f5579237 {} using namespace fn_f5579237;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f5579237 {
class Obj_165380 {
  public:
    char pad[0xc];
    int mVal;
    char SetCompare_00165380(int x);
};
class C_165390 {
  public:
    char pad[0x10];
    int m10;
    char SetCharge_00165390(int v);
};
class Obj_1653a0 {
  public:
    char pad[0x14];
    void* mValue;
    bool SetType_001653a0(void* p);
};
class Obj_1653b0 {
  public:
    char pad[0xc];
    int m;
    bool SetCompare_001653b0(int v);
};
class Obj_1653c0 {
  public:
    char pad[0x10];
    int mValue;
    bool SetMotionState_001653c0(int x);
};
class X_1653d0 {
  public:
    char Set(char c);
    char Pad[12];
    char m;
};
class A_165430 {
  public:
    virtual void v0();
    char pad[0x10 - 4];
    int m10;
    char b14;
    char Set(int x);
};
struct Src_165470 {
    int a;
    int b;
    int c;
};
class Obj_165470 {
  public:
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    bool Set(Src_165470* s);
};
struct Src_1654b0 {
    int a;
    int b;
    int c;
};
struct Obj_1654b0 {
    char pad[0x24];
    int m24, m28, m2c;
    bool Set(Src_1654b0* p);
};
class X_165540 {
  public:
    char c;
    char pad[11];
    char mValue;
    char Fn(char c);
};
class Obj_165550 {
  public:
    char pad[0xd];
    char mD;
    char Fn(char c);
};
class X_165560 {
  public:
    char pad[0xe];
    char Set(unsigned char c);
};
class Obj_165570 {
  public:
    char pad[15];
    char value;
    bool Set(char x);
};
class O_165580 {
  public:
    char pad[0xc];
    int m;
    bool SetCompare_00165580(int a);
};
class Obj_165590 {
  public:
    char pad[0x10];
    void* m10;
    bool SetLocomotionMotionState_00165590(void* p);
};
class C_1655a0 {
  public:
    char pad[12];
    int mValue;
    char SetCompare_001655a0(int v);
};
struct X_1655b0 {
    char pad[0x10];
    int m;
    bool SetConstant_001655b0(int v);
};
class Vec3_1655f0 {
  public:
    int x, y, z;
};
class Obj_1655f0 {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Set(const Vec3_1655f0* v);
};
class Obj_1656c0 {
  public:
    char m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, mA, mB;
    int mC;
    char SetCompare_001656c0(int x);
};
class Obj_1656d0 {
  public:
    char pad[0x10];
    int m10;
    bool SetLocomotionMotionState_001656d0(int v);
};
class Obj_165710 {
  public:
    int m0;
    char pad[8];
    int m1;
    bool SetCompare_00165710(int v);
};
class O_165720 {
  public:
    char SetHealth_00165720(int v);
    char pad[0x10];
    int m10;
};
class X_165730 {
  public:
    char SetConstant_00165730(int a);
    char m[0x14];
    int value;
};
struct Src_1657f0 {
    int a;
    int b;
    int c;
};
struct Obj_1657f0 {
    char pad[0x18];
    int x;
    int y;
    int z;
    bool Set(Src_1657f0* s);
};
struct Vec3_165830 {
    int x, y, z;
};
class Obj_165830 {
  public:
    char pad[0x24];
    int a, b, c;
    bool Copy(Vec3_165830* src);
};
const float kDegreesToRadians = 0.017453292519943295f;
class X_165940 {
    char pad[12];
    int m;

  public:
    bool SetCompare_00165940(int v);
};
class A_165950 {
  public:
    char pad[0x10];
    int value;
    bool SetRageMode_00165950(int x);
};
class Obj_1659d0 {
  public:
    char m0;
    char m1;
    char pad[8];
    int mField;
    char SetCompare_001659d0(int v);
};
class Obj_1659e0 {
  public:
    bool SetHealth_001659e0(int x);
};
class O_1659f0 {
  public:
    char pad[0x14];
    void* m14;
    bool SetConstant_001659f0(void* p);
};
extern int* hulk_at_004e11d8;
class CCondition_165a50 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e11e0;
class CCondition_165ac0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e11e8;
class CCondition_165b30 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e11f0;
class CCondition_165b90 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e11f8;
class CCondition_165c00 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1200;
class CCondition_165c70 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1208;
class CCondition_165ce0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_00416718[];
class Str_165d30 {
  public:
    void Init_0027af50();
};
class Condition_165d30 {
  public:
    void* vptr;
    char pad[12];
    Str_165d30 s;
    void Fin_002345b0();
};
class RayCastTargetCondition_165d30 : public Condition_165d30 {
  public:
    ~RayCastTargetCondition_165d30();
};
extern int* hulk_at_004e1210;
class CCondition_165d70 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1218;
class CCondition_165de0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1220;
class CCondition_165e50 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1228;
class CCondition_165ec0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1230;
class CCondition_165f30 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_004167b8[];
class Str_165f80 {
  public:
    void Init_0027af50();
};
class Condition_165f80 {
  public:
    void* vptr;
    char pad[12];
    Str_165f80 s;
    void Fin_002345b0();
};
class RayCastConeCondition_165f80 : public Condition_165f80 {
  public:
    ~RayCastConeCondition_165f80();
};
extern int* hulk_at_004e1238;
class CCondition_165fc0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1240;
class CCondition_166020 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1248;
class CCondition_166090 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1250;
class CCondition_166100 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1258;
class CCondition_166170 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1260;
class CCondition_1661e0 {
  public:
    virtual int vfunc_0(int);
};
class TargetCharacterTemplateCondition_166210 {
  public:
    int a, b;
    virtual ~TargetCharacterTemplateCondition_166210();
    int d;
    virtual void hulk_slot_F(); void FnF_002345b0();
};
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
extern int* hulk_at_004e1268;
class CCondition_1662b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1270;
class CCondition_166320 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1278;
class CCondition_166390 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_004168d8[];
struct Sub_1663a0 {
    void Init_0027af00();
};
struct RayCastCondition {
    void* vptr;
    char pad[0x14];
    volatile int a[5];
    volatile float b;
    char padc[8];
    void BaseInit_00234590(int);
    RayCastCondition();
};
extern void* hulk_at_004168d8[];
class Str_1663f0 {
  public:
    void Init_0027af50();
};
class Condition_1663f0 {
  public:
    void* vptr;
    char pad[12];
    Str_1663f0 s;
    void Fin_002345b0();
};
class RayCastCondition_1663f0 : public Condition_1663f0 {
  public:
    ~RayCastCondition_1663f0();
};
extern int* hulk_at_004e1280;
class CCondition_166430 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1288;
class CCondition_166490 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1290;
class CCondition_166500 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1298;
class CCondition_166570 {
  public:
    virtual int vfunc_0(int);
};


// 0x00165380 FUN_00165380 (12 B): matches/0x00165380.cpp
// sym: ?SetCompare_00165380@Obj_165380@fn_f5579237@@QAEDH@Z
char Obj_165380::SetCompare_00165380(int x) {
    mVal = x;
    return 1;
}


// 0x00165390 FUN_00165390 (12 B): matches/0x00165390.cpp
// sym: ?SetCharge_00165390@C_165390@fn_f5579237@@QAEDH@Z
char C_165390::SetCharge_00165390(int v) {
    m10 = v;
    return 1;
}


// 0x001653a0 FUN_001653a0 (12 B): matches/0x001653a0.cpp
// sym: ?SetType_001653a0@Obj_1653a0@fn_f5579237@@QAE_NPAX@Z
bool Obj_1653a0::SetType_001653a0(void* p) {
    mValue = p;
    return true;
}


// 0x001653b0 FUN_001653b0 (12 B): matches/0x001653b0.cpp
// sym: ?SetCompare_001653b0@Obj_1653b0@fn_f5579237@@QAE_NH@Z
bool Obj_1653b0::SetCompare_001653b0(int v) {
    m = v;
    return true;
}


// 0x001653c0 FUN_001653c0 (12 B): matches/0x001653c0.cpp
// sym: ?SetMotionState_001653c0@Obj_1653c0@fn_f5579237@@QAE_NH@Z
bool Obj_1653c0::SetMotionState_001653c0(int x) {
    mValue = x;
    return true;
}


// 0x001653d0 FUN_001653d0 (12 B): matches/0x001653d0.cpp
// sym: ?Set@X_1653d0@fn_f5579237@@QAEDD@Z
char X_1653d0::Set(char c) {
    m = c;
    return 1;
}

} // namespace fn_f5579237

// 0x001653e0 FUN_001653e0 (12 B): matches/0x001653e0.cpp
// sym: ?FUN_001653e0@Obj_1653e0@owners@@QAEDH@Z
char owners::Obj_1653e0::FUN_001653e0(int v) {
    mValue = v;
    return 1;
}


// 0x001653f0 FUN_001653f0 (12 B): matches/0x001653f0.cpp
// sym: ?FUN_001653f0@X_1653f0@owners@@QAEDH@Z
char owners::X_1653f0::FUN_001653f0(int a) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = a;
    return 1;
}


// 0x00165400 FUN_00165400 (12 B): matches/0x00165400.cpp
// sym: ?FUN_00165400@Obj_165400@owners@@QAE_NH@Z
bool owners::Obj_165400::FUN_00165400(int value) {
    mField = value;
    return true;
}


// 0x00165410 FUN_00165410 (12 B): matches/0x00165410.cpp
// sym: ?FUN_00165410@Obj_165410@owners@@QAE_NH@Z
bool owners::Obj_165410::FUN_00165410(int value) {
    mValue = value;
    return true;
}


// 0x00165420 FUN_00165420 (12 B): matches/0x00165420.cpp
// sym: ?FUN_00165420@X_165420@owners@@QAE_NH@Z
bool owners::X_165420::FUN_00165420(int v) {
    m = v;
    return true;
}

namespace fn_f5579237 {

// 0x00165430 FUN_00165430 (12 B): matches/0x00165430.cpp
// sym: ?Set@A_165430@fn_f5579237@@QAEDH@Z
char A_165430::Set(int x) {
    m10 = x;
    char r = 1;
    return r;
}

} // namespace fn_f5579237

// 0x00165440 FUN_00165440 (4 B): matches/0x00165440.cpp
// sym: ?FUN_00165440@A_165440@owners@@QAEPAXXZ
void* owners::A_165440::FUN_00165440() {
    return (char*)this + 0x10;
}

namespace fn_f5579237 {

// 0x00165470 FUN_00165470 (26 B): matches/0x00165470.cpp
// sym: ?Set@Obj_165470@fn_f5579237@@QAE_NPAUSrc_165470@2@@Z
bool Obj_165470::Set(Src_165470* s) {
    m18 = s->a;
    m1c = s->b;
    m20 = s->c;
    return true;
}


// 0x001654b0 FUN_001654b0 (26 B): matches/0x001654b0.cpp
// sym: ?Set@Obj_1654b0@fn_f5579237@@QAE_NPAUSrc_1654b0@2@@Z
bool Obj_1654b0::Set(Src_1654b0* p) {
    m24 = p->a;
    m28 = p->b;
    m2c = p->c;
    return true;
}

} // namespace fn_f5579237

// 0x001654e0 FUN_001654e0 (12 B): matches/0x001654e0.cpp
// sym: ?FUN_001654e0@Obj_1654e0@owners@@QAE_NH@Z
bool owners::Obj_1654e0::FUN_001654e0(int x) {
    m30 = x;
    return true;
}


// 0x00165500 FUN_00165500 (12 B): matches/0x00165500.cpp
// sym: ?FUN_00165500@X_165500@owners@@QAEDD@Z
char owners::X_165500::FUN_00165500(char v) {
    m34 = v;
    return 1;
}


// 0x00165510 FUN_00165510 (12 B): matches/0x00165510.cpp
// sym: ?FUN_00165510@X_165510@owners@@QAEDH@Z
char owners::X_165510::FUN_00165510(int v) {
    mValue = v;
    return 1;
}


// 0x00165520 FUN_00165520 (18 B): matches/0x00165520.cpp
// sym: ?FUN_00165520@Thing_165520@owners@@QAEDM@Z
char owners::Thing_165520::FUN_00165520(float x) {
    angle = x * 0.017453292f;
    return 1;
}

namespace fn_f5579237 {

// 0x00165540 FUN_00165540 (12 B): matches/0x00165540.cpp
// sym: ?Fn@X_165540@fn_f5579237@@QAEDD@Z
char X_165540::Fn(char c) {
    mValue = c;
    return 1;
}


// 0x00165550 FUN_00165550 (12 B): matches/0x00165550.cpp
// sym: ?Fn@Obj_165550@fn_f5579237@@QAEDD@Z
char Obj_165550::Fn(char c) {
    mD = c;
    return 1;
}


// 0x00165560 FUN_00165560 (12 B): matches/0x00165560.cpp
// sym: ?Set@X_165560@fn_f5579237@@QAEDE@Z
char X_165560::Set(unsigned char c) {
    *(char*)((char*)this + 0xe) = c;
    return 1;
}


// 0x00165570 FUN_00165570 (12 B): matches/0x00165570.cpp
// sym: ?Set@Obj_165570@fn_f5579237@@QAE_ND@Z
bool Obj_165570::Set(char x) {
    value = x;
    return true;
}


// 0x00165580 FUN_00165580 (12 B): matches/0x00165580.cpp
// sym: ?SetCompare_00165580@O_165580@fn_f5579237@@QAE_NH@Z
bool O_165580::SetCompare_00165580(int a) {
    m = a;
    return true;
}


// 0x00165590 FUN_00165590 (12 B): matches/0x00165590.cpp
// sym: ?SetLocomotionMotionState_00165590@Obj_165590@fn_f5579237@@QAE_NPAX@Z
bool Obj_165590::SetLocomotionMotionState_00165590(void* p) {
    m10 = p;
    return true;
}


// 0x001655a0 FUN_001655a0 (12 B): matches/0x001655a0.cpp
// sym: ?SetCompare_001655a0@C_1655a0@fn_f5579237@@QAEDH@Z
char C_1655a0::SetCompare_001655a0(int v) {
    mValue = v;
    return 1;
}


// 0x001655b0 FUN_001655b0 (12 B): matches/0x001655b0.cpp
// sym: ?SetConstant_001655b0@X_1655b0@fn_f5579237@@QAE_NH@Z
bool X_1655b0::SetConstant_001655b0(int v) {
    m = v;
    return true;
}

} // namespace fn_f5579237

// 0x001655c0 FUN_001655c0 (4 B): matches/0x001655c0.cpp
// sym: ?FUN_001655c0@Obj_1655c0@owners@@QAEPAHXZ
int* owners::Obj_1655c0::FUN_001655c0() {
    return (int*)((char*)this + 0x10);
}

namespace fn_f5579237 {

// 0x001655f0 FUN_001655f0 (26 B): matches/0x001655f0.cpp
// sym: ?Set@Obj_1655f0@fn_f5579237@@QAE_NPBVVec3_1655f0@2@@Z
bool Obj_1655f0::Set(const Vec3_1655f0* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}

} // namespace fn_f5579237

// 0x00165620 FUN_00165620 (12 B): matches/0x00165620.cpp
// sym: ?FUN_00165620@Obj_165620@owners@@QAEDH@Z
char owners::Obj_165620::FUN_00165620(int x) {
    Value = x;
    return 1;
}


// 0x00165640 FUN_00165640 (12 B): matches/0x00165640.cpp
// sym: ?FUN_00165640@X_165640@owners@@QAEDH@Z
char owners::X_165640::FUN_00165640(int v) {
    mVal = v;
    return 1;
}


// 0x00165660 FUN_00165660 (12 B): matches/0x00165660.cpp
// sym: ?FUN_00165660@X_165660@owners@@QAEDH@Z
char owners::X_165660::FUN_00165660(int v) {
    m = v;
    return 1;
}


// 0x00165680 FUN_00165680 (12 B): matches/0x00165680.cpp
// sym: ?FUN_00165680@Obj_165680@owners@@QAEDD@Z
char owners::Obj_165680::FUN_00165680(char v) {
    m30 = v;
    return 1;
}


// 0x00165690 FUN_00165690 (12 B): matches/0x00165690.cpp
// sym: ?FUN_00165690@Obj_165690@owners@@QAE_ND@Z
bool owners::Obj_165690::FUN_00165690(char v) {
    value = v;
    return true;
}


// 0x001656a0 FUN_001656a0 (12 B): matches/0x001656a0.cpp
// sym: ?FUN_001656a0@Obj_1656a0@owners@@QAEDH@Z
char owners::Obj_1656a0::FUN_001656a0(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}


// 0x001656b0 FUN_001656b0 (12 B): matches/0x001656b0.cpp
// sym: ?FUN_001656b0@X_1656b0@owners@@QAE_NH@Z
bool owners::X_1656b0::FUN_001656b0(int value) {
    mValue = value;
    return true;
}

namespace fn_f5579237 {

// 0x001656c0 FUN_001656c0 (12 B): matches/0x001656c0.cpp
// sym: ?SetCompare_001656c0@Obj_1656c0@fn_f5579237@@QAEDH@Z
char Obj_1656c0::SetCompare_001656c0(int x) {
    mC = x;
    return 1;
}


// 0x001656d0 FUN_001656d0 (12 B): matches/0x001656d0.cpp
// sym: ?SetLocomotionMotionState_001656d0@Obj_1656d0@fn_f5579237@@QAE_NH@Z
bool Obj_1656d0::SetLocomotionMotionState_001656d0(int v) {
    m10 = v;
    return true;
}

} // namespace fn_f5579237

// 0x001656e0 FUN_001656e0 (12 B): matches/0x001656e0.cpp
// sym: ?FUN_001656e0@X_1656e0@owners@@QAEDH@Z
char owners::X_1656e0::FUN_001656e0(int a) {
    m = a;
    return 1;
}


// 0x00165700 FUN_00165700 (12 B): matches/0x00165700.cpp
// sym: ?FUN_00165700@Obj_165700@owners@@QAEDH@Z
char owners::Obj_165700::FUN_00165700(int v) {
    mField = v;
    return 1;
}

namespace fn_f5579237 {

// 0x00165710 FUN_00165710 (12 B): matches/0x00165710.cpp
// sym: ?SetCompare_00165710@Obj_165710@fn_f5579237@@QAE_NH@Z
bool Obj_165710::SetCompare_00165710(int v) {
    m1 = v;
    return true;
}


// 0x00165720 FUN_00165720 (12 B): matches/0x00165720.cpp
// sym: ?SetHealth_00165720@O_165720@fn_f5579237@@QAEDH@Z
char O_165720::SetHealth_00165720(int v) {
    m10 = v;
    return 1;
}


// 0x00165730 FUN_00165730 (12 B): matches/0x00165730.cpp
// sym: ?SetConstant_00165730@X_165730@fn_f5579237@@QAEDH@Z
char X_165730::SetConstant_00165730(int a) {
    value = a;
    return 1;
}

} // namespace fn_f5579237

// 0x00165750 FUN_00165750 (12 B): matches/0x00165750.cpp
// sym: ?FUN_00165750@C_165750@owners@@QAE_NH@Z
bool owners::C_165750::FUN_00165750(int a) {
    *(int*)((char*)this + 12) = a;
    return true;
}


// 0x00165770 FUN_00165770 (12 B): matches/0x00165770.cpp
// sym: ?FUN_00165770@Obj_165770@owners@@QAEDH@Z
char owners::Obj_165770::FUN_00165770(int v) {
    m10 = v;
    return 1;
}


// 0x00165780 FUN_00165780 (18 B): matches/0x00165780.cpp
// sym: ?FUN_00165780@Obj_165780@owners@@QAEDM@Z
char owners::Obj_165780::FUN_00165780(float v) {
    mAngle = v * 0.01745329238474369f;
    return 1;
}


// 0x001657a0 FUN_001657a0 (18 B): matches/0x001657a0.cpp
// sym: ?FUN_001657a0@A_1657a0@owners@@QAE_NM@Z
bool owners::A_1657a0::FUN_001657a0(float v) {
    f = v * 0.017453292f;
    return true;
}


// 0x001657c0 FUN_001657c0 (4 B): matches/0x001657c0.cpp
// sym: ?FUN_001657c0@Obj_1657c0@owners@@QAEPAXXZ
void* owners::Obj_1657c0::FUN_001657c0() {
    return (void*)((char*)this + 0x10);
}

namespace fn_f5579237 {

// 0x001657f0 FUN_001657f0 (26 B): matches/0x001657f0.cpp
// sym: ?Set@Obj_1657f0@fn_f5579237@@QAE_NPAUSrc_1657f0@2@@Z
bool Obj_1657f0::Set(Src_1657f0* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}


// 0x00165830 FUN_00165830 (26 B): matches/0x00165830.cpp
// sym: ?Copy@Obj_165830@fn_f5579237@@QAE_NPAUVec3_165830@2@@Z
bool Obj_165830::Copy(Vec3_165830* src) {
    a = src->x;
    b = src->y;
    c = src->z;
    return true;
}

} // namespace fn_f5579237

// 0x00165860 FUN_00165860 (12 B): matches/0x00165860.cpp
// sym: ?FUN_00165860@Target_165860@owners@@QAEDH@Z
char owners::Target_165860::FUN_00165860(int arg) {
    *(int*)((char*)this + 0x30) = arg;
    return 1;
}


// 0x00165880 FUN_00165880 (12 B): matches/0x00165880.cpp
// sym: ?FUN_00165880@A_165880@owners@@QAEDD@Z
char owners::A_165880::FUN_00165880(char x) {
    m34 = x;
    return 1;
}


// 0x001658a0 FUN_001658a0 (12 B): matches/0x001658a0.cpp
// sym: ?FUN_001658a0@T_1658a0@owners@@QAEEE@Z
unsigned char owners::T_1658a0::FUN_001658a0(unsigned char v) {
    m35 = v;
    return 1;
}


// 0x001658c0 FUN_001658c0 (12 B): matches/0x001658c0.cpp
// sym: ?FUN_001658c0@Obj_1658c0@owners@@QAE_NH@Z
bool owners::Obj_1658c0::FUN_001658c0(int x) {
    m38 = x;
    return true;
}


// 0x001658d0 FUN_001658d0 (12 B): matches/0x001658d0.cpp
// sym: ?FUN_001658d0@T_1658d0@owners@@QAEDD@Z
char owners::T_1658d0::FUN_001658d0(char c) {
    m[12] = c;
    return 1;
}


// 0x001658e0 FUN_001658e0 (12 B): matches/0x001658e0.cpp
// sym: ?FUN_001658e0@Obj_1658e0@owners@@QAE_NH@Z
bool owners::Obj_1658e0::FUN_001658e0(int v) {
    value = v;
    return true;
}


// 0x001658f0 FUN_001658f0 (12 B): matches/0x001658f0.cpp
// sym: ?FUN_001658f0@X_1658f0@owners@@QAEDH@Z
char owners::X_1658f0::FUN_001658f0(int v) {
    *(int*)((char*)this + 0x10) = v;
    return 1;
}


// 0x00165900 FUN_00165900 (18 B): matches/0x00165900.cpp
// sym: ?FUN_00165900@Angle_165900@owners@@QAEDM@Z
char owners::Angle_165900::FUN_00165900(float x) {
    val = x * 0.017453292519943295f;
    return 1;
}


// 0x00165920 FUN_00165920 (18 B): matches/0x00165920.cpp
// sym: ?FUN_00165920@O_165920@owners@@QAE_NM@Z
bool owners::O_165920::FUN_00165920(float value) {
    float rad = value * kDegreesToRadians;
    m = rad;
    return true;
}

namespace fn_f5579237 {

// 0x00165940 FUN_00165940 (12 B): matches/0x00165940.cpp
// sym: ?SetCompare_00165940@X_165940@fn_f5579237@@QAE_NH@Z
bool X_165940::SetCompare_00165940(int v) {
    m = v;
    return true;
}


// 0x00165950 FUN_00165950 (12 B): matches/0x00165950.cpp
// sym: ?SetRageMode_00165950@A_165950@fn_f5579237@@QAE_NH@Z
bool A_165950::SetRageMode_00165950(int x) {
    value = x;
    return true;
}

} // namespace fn_f5579237

// 0x00165960 FUN_00165960 (12 B): matches/0x00165960.cpp
// sym: ?FUN_00165960@X_165960@owners@@QAEEE@Z
unsigned char owners::X_165960::FUN_00165960(unsigned char a) {
    value = a;
    return 1;
}


// 0x00165970 FUN_00165970 (12 B): matches/0x00165970.cpp
// sym: ?FUN_00165970@O_165970@owners@@QAE_NH@Z
bool owners::O_165970::FUN_00165970(int v) {
    m = v;
    return true;
}


// 0x00165980 FUN_00165980 (12 B): matches/0x00165980.cpp
// sym: ?FUN_00165980@C_165980@owners@@QAEDH@Z
char owners::C_165980::FUN_00165980(int value) {
    mValue = value;
    return 1;
}


// 0x001659a0 FUN_001659a0 (12 B): matches/0x001659a0.cpp
// sym: ?FUN_001659a0@Obj_1659a0@owners@@QAEDD@Z
char owners::Obj_1659a0::FUN_001659a0(char x) {
    mValue = x;
    return 1;
}


// 0x001659b0 FUN_001659b0 (12 B): matches/0x001659b0.cpp
// sym: ?FUN_001659b0@X_1659b0@owners@@QAE_NH@Z
bool owners::X_1659b0::FUN_001659b0(int value) {
    mValue = value;
    return true;
}


// 0x001659c0 FUN_001659c0 (12 B): matches/0x001659c0.cpp
// sym: ?FUN_001659c0@Obj_1659c0@owners@@QAEDH@Z
char owners::Obj_1659c0::FUN_001659c0(int x) {
    value = x;
    return 1;
}

namespace fn_f5579237 {

// 0x001659d0 FUN_001659d0 (12 B): matches/0x001659d0.cpp
// sym: ?SetCompare_001659d0@Obj_1659d0@fn_f5579237@@QAEDH@Z
char Obj_1659d0::SetCompare_001659d0(int v) {
    mField = v;
    return 1;
}


// 0x001659e0 FUN_001659e0 (12 B): matches/0x001659e0.cpp
// sym: ?SetHealth_001659e0@Obj_1659e0@fn_f5579237@@QAE_NH@Z
bool Obj_1659e0::SetHealth_001659e0(int x) {
    *(int*)((char*)this + 0x10) = x;
    return true;
}


// 0x001659f0 FUN_001659f0 (12 B): matches/0x001659f0.cpp
// sym: ?SetConstant_001659f0@O_1659f0@fn_f5579237@@QAE_NPAX@Z
bool O_1659f0::SetConstant_001659f0(void* p) {
    m14 = p;
    return true;
}


// 0x00165a30 FUN_00165a30 (19 B): matches/0x00165a30.cpp
// sym: ?FUN_00165a30@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165a30() {
    FUN_00234810(((char*)&DAT_004e11d8), ((char*)&DAT_004e11dc));
}

} // namespace fn_f5579237

// 0x00165a50 hulkfight::motion::ChargeCondition::vfunc_0 (16 B): matches/0x00165a50.cpp
// sym: ?vfunc_0@ChargeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::ChargeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e11d8;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165aa0 FUN_00165aa0 (19 B): matches/0x00165aa0.cpp
// sym: ?FUN_00165aa0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165aa0() {
    FUN_00234810(((char*)&DAT_004e11e0), ((char*)&DAT_004e11e4));
}

} // namespace fn_f5579237

// 0x00165ac0 hulkfight::motion::TargetMotionStateCondition::vfunc_0 (16 B): matches/0x00165ac0.cpp
// sym: ?vfunc_0@TargetMotionStateCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetMotionStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e11e0;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165b10 FUN_00165b10 (19 B): matches/0x00165b10.cpp
// sym: ?FUN_00165b10@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165b10() {
    FUN_00234810(((char*)&DAT_004e11e8), ((char*)&DAT_004e11ec));
}

} // namespace fn_f5579237

// 0x00165b30 hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_0 (16 B): matches/0x00165b30.cpp
// sym: ?vfunc_0@IntentionButtonDownAnyCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::IntentionButtonDownAnyCondition::vfunc_0(int index) {
    int* p = hulk_at_004e11e8;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165b70 FUN_00165b70 (19 B): matches/0x00165b70.cpp
// sym: ?FUN_00165b70@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165b70() {
    FUN_00234810(((char*)&DAT_004e11f0), ((char*)&DAT_004e11f4));
}

} // namespace fn_f5579237

// 0x00165b90 hulkfight::motion::VelocityCondition::vfunc_0 (16 B): matches/0x00165b90.cpp
// sym: ?vfunc_0@VelocityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityCondition::vfunc_0(int index) {
    int* p = hulk_at_004e11f0;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165be0 FUN_00165be0 (19 B): matches/0x00165be0.cpp
// sym: ?FUN_00165be0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165be0() {
    FUN_00234810(((char*)&DAT_004e11f8), ((char*)&DAT_004e11fc));
}

} // namespace fn_f5579237

// 0x00165c00 hulkfight::motion::VelocityYCondition::vfunc_0 (16 B): matches/0x00165c00.cpp
// sym: ?vfunc_0@VelocityYCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e11f8;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165c50 FUN_00165c50 (19 B): matches/0x00165c50.cpp
// sym: ?FUN_00165c50@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165c50() {
    FUN_00234810(((char*)&DAT_004e1200), ((char*)&DAT_004e1204));
}

} // namespace fn_f5579237

// 0x00165c70 hulkfight::motion::VelocityAnimatedXZCondition::vfunc_0 (16 B): matches/0x00165c70.cpp
// sym: ?vfunc_0@VelocityAnimatedXZCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityAnimatedXZCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1200;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165cc0 FUN_00165cc0 (19 B): matches/0x00165cc0.cpp
// sym: ?FUN_00165cc0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165cc0() {
    FUN_00234810(((char*)&DAT_004e1208), ((char*)&DAT_004e120c));
}

} // namespace fn_f5579237

// 0x00165ce0 hulkfight::motion::RayCastTargetCondition::vfunc_0 (16 B): matches/0x00165ce0.cpp
// sym: ?vfunc_0@RayCastTargetCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RayCastTargetCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1208;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165d30 FUN_00165d30 (25 B): matches/0x00165d30.cpp
// sym: ??1RayCastTargetCondition_165d30@fn_f5579237@@QAE@XZ
RayCastTargetCondition_165d30::~RayCastTargetCondition_165d30() {
    vptr = hulk_at_00416718;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x00165d50 FUN_00165d50 (19 B): matches/0x00165d50.cpp
// sym: ?FUN_00165d50@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165d50() {
    FUN_00234810(((char*)&DAT_004e1210), ((char*)&DAT_004e1214));
}

} // namespace fn_f5579237

// 0x00165d70 hulkfight::motion::TurningVelocityCondition::vfunc_0 (16 B): matches/0x00165d70.cpp
// sym: ?vfunc_0@TurningVelocityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TurningVelocityCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1210;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165dc0 FUN_00165dc0 (19 B): matches/0x00165dc0.cpp
// sym: ?FUN_00165dc0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165dc0() {
    FUN_00234810(((char*)&DAT_004e1218), ((char*)&DAT_004e121c));
}

} // namespace fn_f5579237

// 0x00165de0 hulkfight::motion::IntentionInputCondition::vfunc_0 (16 B): matches/0x00165de0.cpp
// sym: ?vfunc_0@IntentionInputCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::IntentionInputCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1218;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165e30 FUN_00165e30 (19 B): matches/0x00165e30.cpp
// sym: ?FUN_00165e30@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165e30() {
    FUN_00234810(((char*)&DAT_004e1220), ((char*)&DAT_004e1224));
}

} // namespace fn_f5579237

// 0x00165e50 hulkfight::motion::LocomotionMotionStateCondition::vfunc_0 (16 B): matches/0x00165e50.cpp
// sym: ?vfunc_0@LocomotionMotionStateCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::LocomotionMotionStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1220;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165ea0 FUN_00165ea0 (19 B): matches/0x00165ea0.cpp
// sym: ?FUN_00165ea0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165ea0() {
    FUN_00234810(((char*)&DAT_004e1228), ((char*)&DAT_004e122c));
}

} // namespace fn_f5579237

// 0x00165ec0 hulkfight::motion::GrappleReactionTypeCondition::vfunc_0 (16 B): matches/0x00165ec0.cpp
// sym: ?vfunc_0@GrappleReactionTypeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleReactionTypeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1228;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165f10 FUN_00165f10 (19 B): matches/0x00165f10.cpp
// sym: ?FUN_00165f10@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165f10() {
    FUN_00234810(((char*)&DAT_004e1230), ((char*)&DAT_004e1234));
}

} // namespace fn_f5579237

// 0x00165f30 hulkfight::motion::RayCastConeCondition::vfunc_0 (16 B): matches/0x00165f30.cpp
// sym: ?vfunc_0@RayCastConeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RayCastConeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1230;
    return p[index];
}

namespace fn_f5579237 {

// 0x00165f80 FUN_00165f80 (25 B): matches/0x00165f80.cpp
// sym: ??1RayCastConeCondition_165f80@fn_f5579237@@QAE@XZ
RayCastConeCondition_165f80::~RayCastConeCondition_165f80() {
    vptr = hulk_at_004167b8;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x00165fa0 FUN_00165fa0 (19 B): matches/0x00165fa0.cpp
// sym: ?FUN_00165fa0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00165fa0() {
    FUN_00234810(((char*)&DAT_004e1238), ((char*)&DAT_004e123c));
}

} // namespace fn_f5579237

// 0x00165fc0 hulkfight::motion::TargetingCondition::vfunc_0 (16 B): matches/0x00165fc0.cpp
// sym: ?vfunc_0@TargetingCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetingCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1238;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166000 FUN_00166000 (19 B): matches/0x00166000.cpp
// sym: ?FUN_00166000@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166000() {
    FUN_00234810(((char*)&DAT_004e1240), ((char*)&DAT_004e1244));
}

} // namespace fn_f5579237

// 0x00166020 hulkfight::motion::VelocityAnimatedYCondition::vfunc_0 (16 B): matches/0x00166020.cpp
// sym: ?vfunc_0@VelocityAnimatedYCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityAnimatedYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1240;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166070 FUN_00166070 (19 B): matches/0x00166070.cpp
// sym: ?FUN_00166070@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166070() {
    FUN_00234810(((char*)&DAT_004e1248), ((char*)&DAT_004e124c));
}

} // namespace fn_f5579237

// 0x00166090 hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_0 (16 B): matches/0x00166090.cpp
// sym: ?vfunc_0@TargetLocomotionMotionStateCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetLocomotionMotionStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1248;
    return p[index];
}

namespace fn_f5579237 {

// 0x001660e0 FUN_001660e0 (19 B): matches/0x001660e0.cpp
// sym: ?FUN_001660e0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001660e0() {
    FUN_00234810(((char*)&DAT_004e1250), ((char*)&DAT_004e1254));
}

} // namespace fn_f5579237

// 0x00166100 hulkfight::motion::TargetHealthPercentCondition::vfunc_0 (16 B): matches/0x00166100.cpp
// sym: ?vfunc_0@TargetHealthPercentCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetHealthPercentCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1250;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166150 FUN_00166150 (19 B): matches/0x00166150.cpp
// sym: ?FUN_00166150@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166150() {
    FUN_00234810(((char*)&DAT_004e1258), ((char*)&DAT_004e125c));
}

} // namespace fn_f5579237

// 0x00166170 hulkfight::motion::GrappleHealthCondition::vfunc_0 (16 B): matches/0x00166170.cpp
// sym: ?vfunc_0@GrappleHealthCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrappleHealthCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1258;
    return p[index];
}

namespace fn_f5579237 {

// 0x001661c0 FUN_001661c0 (19 B): matches/0x001661c0.cpp
// sym: ?FUN_001661c0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001661c0() {
    FUN_00234810(((char*)&DAT_004e1260), ((char*)&DAT_004e1264));
}

} // namespace fn_f5579237

// 0x001661e0 hulkfight::motion::TargetCharacterTemplateCondition::vfunc_0 (16 B): matches/0x001661e0.cpp
// sym: ?vfunc_0@TargetCharacterTemplateCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::TargetCharacterTemplateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1260;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166210 FUN_00166210 (29 B): matches/0x00166210.cpp
// sym: ??1TargetCharacterTemplateCondition_166210@fn_f5579237@@UAE@XZ
// Same code shape as 0x0011c270 (propagated; names are from that function)
TargetCharacterTemplateCondition_166210::~TargetCharacterTemplateCondition_166210() {
    Cleanup(d);
    FnF_002345b0();
}

} // namespace fn_f5579237

// 0x00166230 FUN_00166230 (82 B): equivalent/0x00166230.cpp
// sym: ?FUN_00166230@Thing_166230@owners@@QAE_NPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_00166230 @ 0x00166230
bool owners::Thing_166230::FUN_00166230(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return true; }
    unsigned int length = 0;
    while (source[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *out = text;
    do { *out++ = *source; } while (*source++);
    return true;
}

namespace fn_f5579237 {

// 0x00166290 FUN_00166290 (19 B): matches/0x00166290.cpp
// sym: ?FUN_00166290@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166290() {
    FUN_00234810(((char*)&DAT_004e1268), ((char*)&DAT_004e126c));
}

} // namespace fn_f5579237

// 0x001662b0 hulkfight::motion::CharacterPropStatusCondition::vfunc_0 (16 B): matches/0x001662b0.cpp
// sym: ?vfunc_0@CharacterPropStatusCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CharacterPropStatusCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1268;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166300 FUN_00166300 (19 B): matches/0x00166300.cpp
// sym: ?FUN_00166300@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166300() {
    FUN_00234810(((char*)&DAT_004e1270), ((char*)&DAT_004e1274));
}

} // namespace fn_f5579237

// 0x00166320 hulkfight::motion::VelocityXZAngleCondition::vfunc_0 (16 B): matches/0x00166320.cpp
// sym: ?vfunc_0@VelocityXZAngleCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityXZAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1270;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166370 FUN_00166370 (19 B): matches/0x00166370.cpp
// sym: ?FUN_00166370@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166370() {
    FUN_00234810(((char*)&DAT_004e1278), ((char*)&DAT_004e127c));
}

} // namespace fn_f5579237

// 0x00166390 hulkfight::motion::RayCastCondition::vfunc_0 (16 B): matches/0x00166390.cpp
// sym: ?vfunc_0@RayCastCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RayCastCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1278;
    return p[index];
}

namespace fn_f5579237 {

// 0x001663a0 FUN_001663a0 (74 B): matches/0x001663a0.cpp
// sym: ??0RayCastCondition@fn_f5579237@@QAE@XZ
RayCastCondition::RayCastCondition() {
    BaseInit_00234590(0);
    vptr = (void*)((hulk_intptr)DAT_004168d8);
    ((Sub_1663a0*)((char*)this + 0x10))->Init_0027af00();
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    b = -1.0f;
    *(volatile unsigned char*)((char*)this + 0x35) = 0;
    *(volatile float*)((char*)this + 0x30) = 1.0f;
    *(volatile unsigned char*)((char*)this + 0x34) = 1;
    *(volatile float*)((char*)this + 0x38) = 2.0f;
}


// 0x001663f0 FUN_001663f0 (25 B): matches/0x001663f0.cpp
// sym: ??1RayCastCondition_1663f0@fn_f5579237@@QAE@XZ
RayCastCondition_1663f0::~RayCastCondition_1663f0() {
    vptr = hulk_at_004168d8;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x00166410 FUN_00166410 (19 B): matches/0x00166410.cpp
// sym: ?FUN_00166410@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166410() {
    FUN_00234810(((char*)&DAT_004e1280), ((char*)&DAT_004e1284));
}

} // namespace fn_f5579237

// 0x00166430 hulkfight::motion::InLoadedRoomCondition::vfunc_0 (16 B): matches/0x00166430.cpp
// sym: ?vfunc_0@InLoadedRoomCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::InLoadedRoomCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1280;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166470 FUN_00166470 (19 B): matches/0x00166470.cpp
// sym: ?FUN_00166470@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166470() {
    FUN_00234810(((char*)&DAT_004e1288), ((char*)&DAT_004e128c));
}

} // namespace fn_f5579237

// 0x00166490 hulkfight::motion::VelocityXZCondition::vfunc_0 (16 B): matches/0x00166490.cpp
// sym: ?vfunc_0@VelocityXZCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityXZCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1288;
    return p[index];
}

namespace fn_f5579237 {

// 0x001664e0 FUN_001664e0 (19 B): matches/0x001664e0.cpp
// sym: ?FUN_001664e0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001664e0() {
    FUN_00234810(((char*)&DAT_004e1290), ((char*)&DAT_004e1294));
}

} // namespace fn_f5579237

// 0x00166500 hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_0 (16 B): matches/0x00166500.cpp
// sym: ?vfunc_0@VelocityAnimatedXZAngleCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::VelocityAnimatedXZAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1290;
    return p[index];
}

namespace fn_f5579237 {

// 0x00166550 FUN_00166550 (19 B): matches/0x00166550.cpp
// sym: ?FUN_00166550@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00166550() {
    FUN_00234810(((char*)&DAT_004e1298), ((char*)&DAT_004e129c));
}

} // namespace fn_f5579237

// 0x00166570 hulkfight::motion::RageModeStateCondition::vfunc_0 (16 B): matches/0x00166570.cpp
// sym: ?vfunc_0@RageModeStateCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::RageModeStateCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1298;
    return p[index];
}

namespace fn_f5579237 {

// 0x001665c0 FUN_001665c0 (19 B): matches/0x001665c0.cpp
// sym: ?FUN_001665c0@fn_f5579237@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001665c0() {
    FUN_00234810(((char*)&DAT_004e12a0), ((char*)&DAT_004e12a4));
}

} // namespace fn_f5579237
