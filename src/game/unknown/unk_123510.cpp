// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00123510..0x00124090 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f239bcb5 {
#define TREE_TU_END }
namespace fn_f239bcb5 {} using namespace fn_f239bcb5;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f239bcb5 {
const float RAD_CONST = 0.017453292f;
struct Data_1235c0 {
    int a;
    int b;
    int c;
};
class Obj_1235c0 {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Data_1235c0* d);
};
class Obj_123600 {
  public:
    virtual void v();
    char pad[8];
    int mVal;
    char SetCompare_00123600(int x);
};
class Obj_123610 {
  public:
    char SetType_00123610(int x);
};
class C_123620 {
  public:
    char pad[12];
    int mValue;
    bool SetCompare_00123620(int v);
};
class Obj_123630 {
  public:
    char pad[0x10];
    int mValue;
    bool SetDistance_00123630(int value);
};
class Obj_123650 {
  public:
    char m[0x14];
    bool SetUseHulk_00123650(unsigned char x);
};
class C_123670 {
  public:
    char pad[0x15];
    char field;
    unsigned char SetUseGroundPoint_00123670(unsigned char x);
};
class O_123780 {
  public:
    char pad[12];
    int mValue;
    char SetCompare_00123780(int v);
};
class Obj_123790 {
  public:
    char pad[0x10];
    int mValue;
    char SetDistance_00123790(int x);
};
class Obj_1237b0 {
  public:
    char m[0x14];
    char SetOnlyRespondtoEvil_001237b0(char v);
};
class Obj_1237d0 {
  public:
    char m[0x15];
    unsigned char SetOnlyRespondtoProps_001237d0(unsigned char a);
};
class X_123830 {
  public:
    char pad[12];
    int m;
    unsigned char SetCompare_00123830(int v);
};
class Obj_123840 {
  public:
    char pad[0x10];
    int m10;
    bool SetDistance_00123840(int v);
};
class Obj_123860 {
  public:
    char pad[0x14];
    char value;
    char SetUseHulk_00123860(char v);
};
struct Obj_123880 {
    char pad[0x15];
    char m15;
    char SetUseGroundPoint_00123880(unsigned char v);
};
class X_123890 {
  public:
    unsigned char F(float a);
};
class X_1238b0 {
  public:
    char Pad[0x10];
    int m10;
    char F(int a);
};
class Obj_1238c0 {
  public:
    char m0[0x14];
    char Set(char v);
};
extern const float kRadian = 0.017453292f;
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[32];
    int x, y, z;

  public:
    char Set(const Vec* p);
};
class O_123a60 {
  public:
    char SetTimeBegin_00123a60(void* p);
    char pad[0x0c];
    void* m;
};
class Obj_123a70 {
  public:
    char pad[0x10];
    int mVal;
    bool SetTimeEnd_00123a70(int v);
};
class Obj_123a90 {
  public:
    char pad[0x14];
    char m;
    char SetClearEveryFrame_00123a90(char x);
};
extern int* hulk_at_004e0d64;
class CCondition_123ad0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d6c;
class CCondition_123b40 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_123b90 {
    void Init_0027af50();
};
struct TargetArcCondition_123b90 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_0040fd34;
extern int* hulk_at_004e0d74;
class CCondition_123bd0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d7c;
class CCondition_123c40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d84;
class CCondition_123cb0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d8c;
class CCondition_123d20 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d94;
class CCondition_123d90 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0d9c;
class CCondition_123e00 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0da4;
class CCondition_123e70 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dac;
class CCondition_123ee0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0db4;
class CCondition_123f40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dbc;
class CCondition_123fb0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0dc4;
class CCondition_124020 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f239bcb5

// 0x00123510 FUN_00123510 (12 B): matches/0x00123510.cpp
// sym: ?FUN_00123510@T_123510@owners@@QAEEPAX@Z
unsigned char owners::T_123510::FUN_00123510(void* p) {
    *(void**)((char*)this + 0xc) = p;
    return 1;
}


// 0x00123520 FUN_00123520 (12 B): matches/0x00123520.cpp
// sym: ?FUN_00123520@X_123520@owners@@QAEDH@Z
char owners::X_123520::FUN_00123520(int a) {
    m_10 = a;
    return 1;
}


// 0x00123530 FUN_00123530 (18 B): matches/0x00123530.cpp
// sym: ?FUN_00123530@O_123530@owners@@QAEDM@Z
char owners::O_123530::FUN_00123530(float v) {
    mValue = v * 0.0174532925f;
    return 1;
}


// 0x00123550 FUN_00123550 (18 B): matches/0x00123550.cpp
// sym: ?FUN_00123550@Obj_123550@owners@@QAEDM@Z
char owners::Obj_123550::FUN_00123550(float deg) {
    mAngle = deg * RAD_CONST;
    return 1;
}


// 0x00123580 FUN_00123580 (12 B): matches/0x00123580.cpp
// sym: ?FUN_00123580@Obj_123580@owners@@QAEDD@Z
char owners::Obj_123580::FUN_00123580(char value) {
    mValue = value;
    return 1;
}


// 0x00123590 FUN_00123590 (4 B): matches/0x00123590.cpp
// sym: ?FUN_00123590@X_123590@owners@@QAEPAXXZ
void* owners::X_123590::FUN_00123590() {
    return (char*)this + 0x18;
}

namespace fn_f239bcb5 {

// 0x001235c0 FUN_001235c0 (26 B): matches/0x001235c0.cpp
// sym: ?Set@Obj_1235c0@fn_f239bcb5@@QAE_NPAUData_1235c0@2@@Z
bool Obj_1235c0::Set(Data_1235c0* d) {
    m20 = d->a;
    m24 = d->b;
    m28 = d->c;
    return true;
}

} // namespace fn_f239bcb5

// 0x001235f0 FUN_001235f0 (12 B): matches/0x001235f0.cpp
// sym: ?FUN_001235f0@X_1235f0@owners@@QAEEE@Z
unsigned char owners::X_1235f0::FUN_001235f0(unsigned char v) {
    m2c = v;
    return 1;
}

namespace fn_f239bcb5 {

// 0x00123600 FUN_00123600 (12 B): matches/0x00123600.cpp
// sym: ?SetCompare_00123600@Obj_123600@fn_f239bcb5@@QAEDH@Z
char Obj_123600::SetCompare_00123600(int x) {
    mVal = x;
    return 1;
}


// 0x00123610 FUN_00123610 (12 B): matches/0x00123610.cpp
// sym: ?SetType_00123610@Obj_123610@fn_f239bcb5@@QAEDH@Z
char Obj_123610::SetType_00123610(int x) {
    *(int*)((char*)this + 0x10) = x;
    return 1;
}


// 0x00123620 FUN_00123620 (12 B): matches/0x00123620.cpp
// sym: ?SetCompare_00123620@C_123620@fn_f239bcb5@@QAE_NH@Z
bool C_123620::SetCompare_00123620(int v) {
    mValue = v;
    return true;
}


// 0x00123630 FUN_00123630 (12 B): matches/0x00123630.cpp
// sym: ?SetDistance_00123630@Obj_123630@fn_f239bcb5@@QAE_NH@Z
bool Obj_123630::SetDistance_00123630(int value) {
    mValue = value;
    return true;
}


// 0x00123650 FUN_00123650 (12 B): matches/0x00123650.cpp
// sym: ?SetUseHulk_00123650@Obj_123650@fn_f239bcb5@@QAE_NE@Z
bool Obj_123650::SetUseHulk_00123650(unsigned char x) {
    m[0x14] = x;
    return true;
}


// 0x00123670 FUN_00123670 (12 B): matches/0x00123670.cpp
// sym: ?SetUseGroundPoint_00123670@C_123670@fn_f239bcb5@@QAEEE@Z
unsigned char C_123670::SetUseGroundPoint_00123670(unsigned char x) {
    field = x;
    return 1;
}

} // namespace fn_f239bcb5

// 0x00123680 FUN_00123680 (12 B): matches/0x00123680.cpp
// sym: ?FUN_00123680@C_123680@owners@@QAEDH@Z
char owners::C_123680::FUN_00123680(int a) {
    m12 = a;
    return 1;
}


// 0x00123690 FUN_00123690 (18 B): matches/0x00123690.cpp
// sym: ?FUN_00123690@Thing_123690@owners@@QAEDM@Z
char owners::Thing_123690::FUN_00123690(float a) {
    radians = a * 0.017453292519943295f;
    return 1;
}


// 0x001236b0 FUN_001236b0 (12 B): matches/0x001236b0.cpp
// sym: ?FUN_001236b0@Obj_1236b0@owners@@QAEEH@Z
unsigned char owners::Obj_1236b0::FUN_001236b0(int x) {
    m = x;
    return 1;
}


// 0x001236c0 FUN_001236c0 (12 B): matches/0x001236c0.cpp
// sym: ?FUN_001236c0@Obj_1236c0@owners@@QAE_NH@Z
bool owners::Obj_1236c0::FUN_001236c0(int x) {
    value = x;
    return true;
}


// 0x001236d0 FUN_001236d0 (12 B): matches/0x001236d0.cpp
// sym: ?FUN_001236d0@O_1236d0@owners@@QAE_NH@Z
bool owners::O_1236d0::FUN_001236d0(int x) {
    m1c = x;
    return true;
}


// 0x001236e0 FUN_001236e0 (12 B): matches/0x001236e0.cpp
// sym: ?FUN_001236e0@Obj_1236e0@owners@@QAE_NH@Z
bool owners::Obj_1236e0::FUN_001236e0(int a) {
    value = a;
    return true;
}


// 0x001236f0 FUN_001236f0 (12 B): matches/0x001236f0.cpp
// sym: ?FUN_001236f0@Obj_1236f0@owners@@QAEEE@Z
unsigned char owners::Obj_1236f0::FUN_001236f0(unsigned char a) {
    m14 = a;
    return 1;
}


// 0x00123710 FUN_00123710 (12 B): matches/0x00123710.cpp
// sym: ?FUN_00123710@Obj_123710@owners@@QAEDE@Z
char owners::Obj_123710::FUN_00123710(unsigned char value) {
    m15 = value;
    return 1;
}


// 0x00123730 FUN_00123730 (12 B): matches/0x00123730.cpp
// sym: ?FUN_00123730@X_123730@owners@@QAEDD@Z
char owners::X_123730::FUN_00123730(char c) {
    ((char*)this)[0x16] = c;
    return 1;
}


// 0x00123740 FUN_00123740 (18 B): matches/0x00123740.cpp
// sym: ?FUN_00123740@Obj_123740@owners@@QAEDM@Z
char owners::Obj_123740::FUN_00123740(float x) {
    *(float*)((char*)this + 0xc) = x * 0.017453292f;
    return 1;
}


// 0x00123760 FUN_00123760 (18 B): matches/0x00123760.cpp
// sym: ?FUN_00123760@X_123760@owners@@QAEDM@Z
char owners::X_123760::FUN_00123760(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}

namespace fn_f239bcb5 {

// 0x00123780 FUN_00123780 (12 B): matches/0x00123780.cpp
// sym: ?SetCompare_00123780@O_123780@fn_f239bcb5@@QAEDH@Z
char O_123780::SetCompare_00123780(int v) {
    mValue = v;
    return 1;
}


// 0x00123790 FUN_00123790 (12 B): matches/0x00123790.cpp
// sym: ?SetDistance_00123790@Obj_123790@fn_f239bcb5@@QAEDH@Z
char Obj_123790::SetDistance_00123790(int x) {
    mValue = x;
    return 1;
}


// 0x001237b0 FUN_001237b0 (12 B): matches/0x001237b0.cpp
// sym: ?SetOnlyRespondtoEvil_001237b0@Obj_1237b0@fn_f239bcb5@@QAEDD@Z
char Obj_1237b0::SetOnlyRespondtoEvil_001237b0(char v) {
    m[0x14] = v;
    return 1;
}


// 0x001237d0 FUN_001237d0 (12 B): matches/0x001237d0.cpp
// sym: ?SetOnlyRespondtoProps_001237d0@Obj_1237d0@fn_f239bcb5@@QAEEE@Z
unsigned char Obj_1237d0::SetOnlyRespondtoProps_001237d0(unsigned char a) {
    m[0x15] = a;
    return 1;
}

} // namespace fn_f239bcb5

// 0x001237e0 FUN_001237e0 (12 B): matches/0x001237e0.cpp
// sym: ?FUN_001237e0@Obj_1237e0@owners@@QAE_ND@Z
bool owners::Obj_1237e0::FUN_001237e0(char v) {
    mValue = v;
    return true;
}


// 0x001237f0 FUN_001237f0 (12 B): matches/0x001237f0.cpp
// sym: ?FUN_001237f0@X_1237f0@owners@@QAE_NH@Z
bool owners::X_1237f0::FUN_001237f0(int a) {
    *(int*)((char*)this + 0xc) = a;
    return true;
}


// 0x00123800 FUN_00123800 (12 B): matches/0x00123800.cpp
// sym: ?FUN_00123800@Obj_123800@owners@@QAEDH@Z
char owners::Obj_123800::FUN_00123800(int v) {
    value = v;
    return 1;
}


// 0x00123810 FUN_00123810 (12 B): matches/0x00123810.cpp
// sym: ?FUN_00123810@Obj_123810@owners@@QAEDH@Z
char owners::Obj_123810::FUN_00123810(int v) {
    mValue = v;
    return 1;
}


// 0x00123820 FUN_00123820 (12 B): matches/0x00123820.cpp
// sym: ?FUN_00123820@X_123820@owners@@QAE_NH@Z
bool owners::X_123820::FUN_00123820(int v) {
    mValue = v;
    return true;
}

namespace fn_f239bcb5 {

// 0x00123830 FUN_00123830 (12 B): matches/0x00123830.cpp
// sym: ?SetCompare_00123830@X_123830@fn_f239bcb5@@QAEEH@Z
unsigned char X_123830::SetCompare_00123830(int v) {
    m = v;
    return 1;
}


// 0x00123840 FUN_00123840 (12 B): matches/0x00123840.cpp
// sym: ?SetDistance_00123840@Obj_123840@fn_f239bcb5@@QAE_NH@Z
bool Obj_123840::SetDistance_00123840(int v) {
    m10 = v;
    return true;
}


// 0x00123860 FUN_00123860 (12 B): matches/0x00123860.cpp
// sym: ?SetUseHulk_00123860@Obj_123860@fn_f239bcb5@@QAEDD@Z
char Obj_123860::SetUseHulk_00123860(char v) {
    value = v;
    return 1;
}


// 0x00123880 FUN_00123880 (12 B): matches/0x00123880.cpp
// sym: ?SetUseGroundPoint_00123880@Obj_123880@fn_f239bcb5@@QAEDE@Z
char Obj_123880::SetUseGroundPoint_00123880(unsigned char v) {
    m15 = v;
    return 1;
}


// 0x00123890 FUN_00123890 (18 B): matches/0x00123890.cpp
// sym: ?F@X_123890@fn_f239bcb5@@QAEEM@Z
unsigned char X_123890::F(float a) {
    float c = 0.0174532925199433f;
    *(float*)((char*)this + 0xc) = a * c;
    return 1;
}


// 0x001238b0 FUN_001238b0 (12 B): matches/0x001238b0.cpp
// sym: ?F@X_1238b0@fn_f239bcb5@@QAEDH@Z
char X_1238b0::F(int a) {
    m10 = a;
    return 1;
}


// 0x001238c0 FUN_001238c0 (12 B): matches/0x001238c0.cpp
// sym: ?Set@Obj_1238c0@fn_f239bcb5@@QAEDD@Z
char Obj_1238c0::Set(char v) {
    m0[0x14] = v;
    return 1;
}

} // namespace fn_f239bcb5

// 0x001238d0 FUN_001238d0 (12 B): matches/0x001238d0.cpp
// sym: ?FUN_001238d0@Obj_1238d0@owners@@QAE_NI@Z
bool owners::Obj_1238d0::FUN_001238d0(unsigned int v) {
    value = v;
    return true;
}


// 0x001238e0 FUN_001238e0 (12 B): matches/0x001238e0.cpp
// sym: ?FUN_001238e0@Obj_1238e0@owners@@QAE_NH@Z
bool owners::Obj_1238e0::FUN_001238e0(int v) {
    mValue = v;
    return true;
}


// 0x001238f0 FUN_001238f0 (12 B): matches/0x001238f0.cpp
// sym: ?FUN_001238f0@Obj_1238f0@owners@@QAE_NH@Z
bool owners::Obj_1238f0::FUN_001238f0(int v) {
    mVal = v;
    return true;
}


// 0x00123900 FUN_00123900 (12 B): matches/0x00123900.cpp
// sym: ?FUN_00123900@X_123900@owners@@QAE_NH@Z
bool owners::X_123900::FUN_00123900(int value) {
    m10 = value;
    return true;
}


// 0x00123910 FUN_00123910 (12 B): matches/0x00123910.cpp
// sym: ?FUN_00123910@Obj_123910@owners@@QAEEE@Z
unsigned char owners::Obj_123910::FUN_00123910(unsigned char x) {
    m = x;
    return 1;
}


// 0x00123920 FUN_00123920 (12 B): matches/0x00123920.cpp
// sym: ?FUN_00123920@Thing_123920@owners@@QAEDD@Z
char owners::Thing_123920::FUN_00123920(char c) {
    mVal = c;
    return 1;
}


// 0x00123930 FUN_00123930 (12 B): matches/0x00123930.cpp
// sym: ?FUN_00123930@Obj_123930@owners@@QAEDE@Z
char owners::Obj_123930::FUN_00123930(unsigned char v) {
    value = v;
    return 1;
}


// 0x00123950 FUN_00123950 (12 B): matches/0x00123950.cpp
// sym: ?FUN_00123950@O_123950@owners@@QAE_NE@Z
bool owners::O_123950::FUN_00123950(unsigned char b) {
    m = b;
    return true;
}


// 0x00123960 FUN_00123960 (12 B): matches/0x00123960.cpp
// sym: ?FUN_00123960@Obj_123960@owners@@QAEDH@Z
char owners::Obj_123960::FUN_00123960(int x) {
    value = x;
    return 1;
}


// 0x00123980 FUN_00123980 (12 B): matches/0x00123980.cpp
// sym: ?FUN_00123980@Obj_123980@owners@@QAEEE@Z
unsigned char owners::Obj_123980::FUN_00123980(unsigned char x) {
    m = x;
    return 1;
}


// 0x00123990 FUN_00123990 (12 B): matches/0x00123990.cpp
// sym: ?FUN_00123990@Obj_123990@owners@@QAEDH@Z
char owners::Obj_123990::FUN_00123990(int x) {
    mValue = x;
    return 1;
}


// 0x001239a0 FUN_001239a0 (12 B): matches/0x001239a0.cpp
// sym: ?FUN_001239a0@O_1239a0@owners@@QAE_NH@Z
bool owners::O_1239a0::FUN_001239a0(int a) {
    m = a;
    return true;
}


// 0x001239c0 FUN_001239c0 (18 B): matches/0x001239c0.cpp
// sym: ?FUN_001239c0@Obj_1239c0@owners@@QAEDM@Z
char owners::Obj_1239c0::FUN_001239c0(float value) {
    mAngle = value * kRadian;
    return 1;
}


// 0x001239f0 FUN_001239f0 (12 B): matches/0x001239f0.cpp
// sym: ?FUN_001239f0@Obj_1239f0@owners@@QAE_NH@Z
bool owners::Obj_1239f0::FUN_001239f0(int x) {
    mVal = x;
    return true;
}


// 0x00123a10 FUN_00123a10 (12 B): matches/0x00123a10.cpp
// sym: ?FUN_00123a10@Obj_123a10@owners@@QAEEE@Z
unsigned char owners::Obj_123a10::FUN_00123a10(unsigned char v) {
    m1c = v;
    return 1;
}

namespace fn_f239bcb5 {

// 0x00123a40 FUN_00123a40 (26 B): matches/0x00123a40.cpp
// sym: ?Set@Obj@fn_f239bcb5@@QAEDPBUVec@2@@Z
char Obj::Set(const Vec* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return 1;
}


// 0x00123a60 FUN_00123a60 (12 B): matches/0x00123a60.cpp
// sym: ?SetTimeBegin_00123a60@O_123a60@fn_f239bcb5@@QAEDPAX@Z
char O_123a60::SetTimeBegin_00123a60(void* p) {
    m = p;
    return 1;
}


// 0x00123a70 FUN_00123a70 (12 B): matches/0x00123a70.cpp
// sym: ?SetTimeEnd_00123a70@Obj_123a70@fn_f239bcb5@@QAE_NH@Z
bool Obj_123a70::SetTimeEnd_00123a70(int v) {
    mVal = v;
    return true;
}


// 0x00123a90 FUN_00123a90 (12 B): matches/0x00123a90.cpp
// sym: ?SetClearEveryFrame_00123a90@Obj_123a90@fn_f239bcb5@@QAEDD@Z
char Obj_123a90::SetClearEveryFrame_00123a90(char x) {
    m = x;
    return 1;
}


// 0x00123ab0 FUN_00123ab0 (19 B): matches/0x00123ab0.cpp
// sym: ?FUN_00123ab0@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123ab0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d64), ((char*)&DAT_004e0d68));
}

} // namespace fn_f239bcb5

// 0x00123ad0 hulkfight::ai::TargetDirectionYCondition::vfunc_0 (16 B): matches/0x00123ad0.cpp
// sym: ?vfunc_0@TargetDirectionYCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDirectionYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d64;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123b20 FUN_00123b20 (19 B): matches/0x00123b20.cpp
// sym: ?FUN_00123b20@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123b20(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d6c), ((char*)&DAT_004e0d70));
}

} // namespace fn_f239bcb5

// 0x00123b40 hulkfight::ai::TargetArcCondition::vfunc_0 (16 B): matches/0x00123b40.cpp
// sym: ?vfunc_0@TargetArcCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetArcCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d6c;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123b90 FUN_00123b90 (25 B): matches/0x00123b90.cpp
// sym: ?Run@TargetArcCondition_123b90@fn_f239bcb5@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void TargetArcCondition_123b90::Run() {
    vptr = &hulk_at_0040fd34;
    ((Tail_123b90*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x00123bb0 FUN_00123bb0 (19 B): matches/0x00123bb0.cpp
// sym: ?FUN_00123bb0@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123bb0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d74), ((char*)&DAT_004e0d78));
}

} // namespace fn_f239bcb5

// 0x00123bd0 hulkfight::ai::TargetTypeCondition::vfunc_0 (16 B): matches/0x00123bd0.cpp
// sym: ?vfunc_0@TargetTypeCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetTypeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d74;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123c20 FUN_00123c20 (19 B): matches/0x00123c20.cpp
// sym: ?FUN_00123c20@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123c20(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d7c), ((char*)&DAT_004e0d80));
}

} // namespace fn_f239bcb5

// 0x00123c40 hulkfight::ai::TargetDistanceCondition::vfunc_0 (16 B): matches/0x00123c40.cpp
// sym: ?vfunc_0@TargetDistanceCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d7c;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123c90 FUN_00123c90 (19 B): matches/0x00123c90.cpp
// sym: ?FUN_00123c90@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123c90(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d84), ((char*)&DAT_004e0d88));
}

} // namespace fn_f239bcb5

// 0x00123cb0 hulkfight::ai::TargetAngleYCondition::vfunc_0 (16 B): matches/0x00123cb0.cpp
// sym: ?vfunc_0@TargetAngleYCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetAngleYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d84;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123d00 FUN_00123d00 (19 B): matches/0x00123d00.cpp
// sym: ?FUN_00123d00@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123d00(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d8c), ((char*)&DAT_004e0d90));
}

} // namespace fn_f239bcb5

// 0x00123d20 hulkfight::ai::TargetDirectionCondition::vfunc_0 (16 B): matches/0x00123d20.cpp
// sym: ?vfunc_0@TargetDirectionCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDirectionCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d8c;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123d70 FUN_00123d70 (19 B): matches/0x00123d70.cpp
// sym: ?FUN_00123d70@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123d70(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d94), ((char*)&DAT_004e0d98));
}

} // namespace fn_f239bcb5

// 0x00123d90 hulkfight::ai::TargetDistanceYCondition::vfunc_0 (16 B): matches/0x00123d90.cpp
// sym: ?vfunc_0@TargetDistanceYCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDistanceYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d94;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123de0 FUN_00123de0 (19 B): matches/0x00123de0.cpp
// sym: ?FUN_00123de0@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123de0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0d9c), ((char*)&DAT_004e0da0));
}

} // namespace fn_f239bcb5

// 0x00123e00 hulkfight::ai::TargetOrientationCondition::vfunc_0 (16 B): matches/0x00123e00.cpp
// sym: ?vfunc_0@TargetOrientationCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetOrientationCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0d9c;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123e50 FUN_00123e50 (19 B): matches/0x00123e50.cpp
// sym: ?FUN_00123e50@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123e50(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0da4), ((char*)&DAT_004e0da8));
}

} // namespace fn_f239bcb5

// 0x00123e70 hulkfight::ai::ProjectileDistanceCondition::vfunc_0 (16 B): matches/0x00123e70.cpp
// sym: ?vfunc_0@ProjectileDistanceCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ProjectileDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0da4;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123ec0 FUN_00123ec0 (19 B): matches/0x00123ec0.cpp
// sym: ?FUN_00123ec0@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123ec0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dac), ((char*)&DAT_004e0db0));
}

} // namespace fn_f239bcb5

// 0x00123ee0 hulkfight::ai::HasTargetCondition::vfunc_0 (16 B): matches/0x00123ee0.cpp
// sym: ?vfunc_0@HasTargetCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HasTargetCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dac;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123f20 FUN_00123f20 (19 B): matches/0x00123f20.cpp
// sym: ?FUN_00123f20@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123f20(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0db4), ((char*)&DAT_004e0db8));
}

} // namespace fn_f239bcb5

// 0x00123f40 hulkfight::ai::TargetVelocityYCondition::vfunc_0 (16 B): matches/0x00123f40.cpp
// sym: ?vfunc_0@TargetVelocityYCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetVelocityYCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0db4;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00123f90 FUN_00123f90 (19 B): matches/0x00123f90.cpp
// sym: ?FUN_00123f90@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00123f90(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dbc), ((char*)&DAT_004e0dc0));
}

} // namespace fn_f239bcb5

// 0x00123fb0 hulkfight::ai::TargetVelocityCondition::vfunc_0 (16 B): matches/0x00123fb0.cpp
// sym: ?vfunc_0@TargetVelocityCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetVelocityCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dbc;
    return p[index];
}

namespace fn_f239bcb5 {

// 0x00124000 FUN_00124000 (19 B): matches/0x00124000.cpp
// sym: ?FUN_00124000@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124000(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dc4), ((char*)&DAT_004e0dc8));
}

} // namespace fn_f239bcb5

// 0x00124020 hulkfight::ai::TargetDistanceXZCondition::vfunc_0 (16 B): matches/0x00124020.cpp
// sym: ?vfunc_0@TargetDistanceXZCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TargetDistanceXZCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0dc4;
    return p[index];
}


// 0x00124060 FUN_00124060 (11 B): matches/0x00124060.cpp [wrapped: conflict: hulkfight::ai::TargetDistanceXZCondition]
// sym: ??1TargetDistanceXZCondition@ai@hulkfight@fn_00124060@@UAE@XZ
namespace fn_00124060 {
namespace hulkfight {
namespace ai {
class TargetCondition {
  public:
    virtual ~TargetCondition() throw();
};
class TargetDistanceXZCondition : public TargetCondition {
  public:
    virtual ~TargetDistanceXZCondition() throw();
};
TargetDistanceXZCondition::~TargetDistanceXZCondition() throw() {}
} // namespace ai
} // namespace hulkfight
} // namespace fn_00124060

namespace fn_f239bcb5 {

// 0x00124070 FUN_00124070 (19 B): matches/0x00124070.cpp
// sym: ?FUN_00124070@fn_f239bcb5@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00124070(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e0dcc), ((char*)&DAT_004e0dd0));
}

} // namespace fn_f239bcb5
