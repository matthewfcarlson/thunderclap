// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016e720..0x0016fcd0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa642773 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa642773 {} using namespace fn_fa642773;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fa642773 {
struct V {
    int a;
    int b;
    int c;
};
class C_16e770 {
  public:
    char pad[0x20];
    bool Set(V* p);
};
struct Vec3 {
    float x, y, z;
};
class Thing {
    char pad[0x2c];
    float x, y, z;

  public:
    bool Set(const Vec3* p);
};
const float kDegToRad = 0.017453292f;
extern const float RADIANS_TO_DEGREES = 0.017453292f;
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x38];
    int x, y, z;

  public:
    bool Set(Vec const& v);
};
struct Base_16ef10 {
    virtual void f();
    char pad[32];
};
struct Obj_16ef10 : Base_16ef10 {
    char* Get();
};
struct Vec3_16ef40 {
    int x, y, z;
};
class Obj_16ef40 {
  public:
    char pad[0x28];
    int v28;
    int v2c;
    int v30;
    bool Set(const Vec3_16ef40* p);
};
struct Src_16ef80 {
    int a;
    int b;
    int c;
};
class Obj_16ef80 {
  public:
    char pad[0x34];
    int x;
    int y;
    int z;
    bool Set(Src_16ef80* s);
};
class T_16f000 {
  public:
    char pad[0x4c];
    float value;
    float Get();
};
struct Vec3_16f0f0 {
    int x, y, z;
};
class O_16f0f0 {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Fn(Vec3_16f0f0* v);
};
class A_16f160 {
  public:
    char f(int x);
    char pad[0xc];
};
class Obj_16f170 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
struct Src_16f1a0 {
    int a;
    int b;
    int c;
};
class Obj_16f1a0 {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    unsigned char Fn(Src_16f1a0* p);
};
class Obj_16f1c0 {
  public:
    char pad[0xc];
    int value;
    bool SetTimeBegin_0016f1c0(int v);
};
class Obj_16f1d0 {
  public:
    char Pad[0x10];
    int m10;
    char SetTimeEnd_0016f1d0(int x);
};
class A_16f1f0 {
  public:
    bool SetMotionState_0016f1f0(void* p);
};
class Obj_16f200 {
  public:
    char pad[0xc];
    void* mField;
    bool SetTimeBegin_0016f200(void* p);
};
class Obj_16f210 {
  public:
    virtual void V();
    char pad[12];
    char SetTimeEnd_0016f210(int value);
};
class X_16f230 {
  public:
    char pad[0x14];
    int m14;
    bool SetFinalVelocity_0016f230(int a);
};
struct Vec3_16f2a0 {
    int x, y, z;
};
class Obj_16f2a0 {
    char pad[0x20];
    int a, b, c;

  public:
    char Set(Vec3_16f2a0* p);
};
struct Data_16f2e0 {
    int a;
    int b;
    int c;
};
class Ctx_16f2e0 {
  public:
    char pad[0x2c];
    int m2c;
    int m30;
    int m34;
    char Set(Data_16f2e0* d);
};
struct Src_16f400 {
    int a;
    int b;
    int c;
};
class Obj_16f400 {
  public:
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    bool Set(Src_16f400* p);
};
struct Vec3_16f440 {
    int x, y, z;
};
struct Obj_16f440 {
    char pad[0x2c];
    int a, b, c;
    bool Set(Vec3_16f440* v);
};
extern const float RAD = 0.017453292519943295f;
class Obj_16f880 {
  public:
    virtual void V0();
    char pad[8];
    void* mPtr;
    bool Fn(void* p);
};
class Obj_16f8a0 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};
struct X_16f8b0 {
    char pad[12];
    int mVal;
};
class Obj_16f930 {
  public:
    char pad[0xc];
    int mVal;
    bool SetTimeBegin_0016f930(int v);
};
class Obj_16f960 {
  public:
    char pad[0x10];
    int a;
    int b;
    int c;
    char SetOffset_0016f960(void* p);
};
struct Data_16f9a0 {
    int a;
    int b;
    int c;
};
class Obj_16f9a0 {
  public:
    char SetMinimum_0016f9a0(Data_16f9a0* p);
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
};
class Obj_16f9d0 {
  public:
    char pad[0x28];
    int mVal;
    bool SetTraceWidth_0016f9d0(int v);
};
class Obj_16fa00 {
  public:
    char pad[0xc];
    int m;
    bool SetTimeBegin_0016fa00(int x);
};
struct Src_16fa40 {
    int a;
    int b;
    int c;
};
class Obj_16fa40 {
  public:
    char pad[0x14];
    int f14;
    int f18;
    int f1c;
    bool SetOffset_0016fa40(const Src_16fa40* other);
};
class X_16fa60 {
  public:
    char pad[12];
    int m12;
    char SetTimeBegin_0016fa60(int v);
};
class Obj_16fa70 {
  public:
    char pad[0x10];
    int mValue;
    bool SetTimeEnd_0016fa70(int v);
};
struct Obj_16fa90 {
    char pad[0x14];
    char m14;
    char SetClearOnBegin_0016fa90(char v);
};
class Obj_16fc90 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*, int, int);
};
class Thing_16fc90 {
  public:
    char pad[0x10];
    Obj_16fc90* m;
    char pad2[0x84];
    int FUN(hulk_intptr arg);
};

} // namespace fn_fa642773

// 0x0016e720 FUN_0016e720 (12 B): matches/0x0016e720.cpp
// sym: ?FUN_0016e720@Obj_16e720@owners@@QAE_NH@Z
bool owners::Obj_16e720::FUN_0016e720(int x) {
    m = x;
    return true;
}


// 0x0016e730 FUN_0016e730 (12 B): matches/0x0016e730.cpp
// sym: ?FUN_0016e730@Obj_16e730@owners@@QAE_NH@Z
bool owners::Obj_16e730::FUN_0016e730(int v) {
    mVal = v;
    return true;
}


// 0x0016e740 FUN_0016e740 (4 B): matches/0x0016e740.cpp
// sym: ?FUN_0016e740@A_16e740@owners@@QAEPAHXZ
int* owners::A_16e740::FUN_0016e740() {
    return &m18;
}

namespace fn_fa642773 {

// 0x0016e770 FUN_0016e770 (26 B): matches/0x0016e770.cpp
// sym: ?Set@C_16e770@fn_fa642773@@QAE_NPAUV@2@@Z
bool C_16e770::Set(V* p) {
    *(int*)((char*)this + 0x20) = p->a;
    *(int*)((char*)this + 0x24) = p->b;
    *(int*)((char*)this + 0x28) = p->c;
    return true;
}


// 0x0016e7b0 FUN_0016e7b0 (26 B): matches/0x0016e7b0.cpp
// sym: ?Set@Thing@fn_fa642773@@QAE_NPBUVec3@2@@Z
bool Thing::Set(const Vec3* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}

} // namespace fn_fa642773

// 0x0016e7e0 FUN_0016e7e0 (18 B): matches/0x0016e7e0.cpp
// sym: ?FUN_0016e7e0@A_16e7e0@owners@@QAEDM@Z
char owners::A_16e7e0::FUN_0016e7e0(float degrees) {
    value = degrees * 0.017453292f;
    return 1;
}


// 0x0016e810 FUN_0016e810 (18 B): matches/0x0016e810.cpp
// sym: ?FUN_0016e810@Obj_16e810@owners@@QAE_NM@Z
bool owners::Obj_16e810::FUN_0016e810(float x) {
    angle = x * 0.017453292f;
    return true;
}


// 0x0016e840 FUN_0016e840 (18 B): matches/0x0016e840.cpp
// sym: ?FUN_0016e840@Obj_16e840@owners@@QAEDM@Z
char owners::Obj_16e840::FUN_0016e840(float v) {
    angle = v * kDegToRad;
    return 1;
}


// 0x0016e870 FUN_0016e870 (18 B): matches/0x0016e870.cpp
// sym: ?FUN_0016e870@X_16e870@owners@@QAEDM@Z
char owners::X_16e870::FUN_0016e870(float x) {
    *(float*)((char*)this + 0x44) = x * 0.0174532925f;
    return 1;
}


// 0x0016e8a0 FUN_0016e8a0 (18 B): matches/0x0016e8a0.cpp
// sym: ?FUN_0016e8a0@Obj_16e8a0@owners@@QAEDM@Z
char owners::Obj_16e8a0::FUN_0016e8a0(float x) {
    float v = x * RADIANS_TO_DEGREES;
    Value = v;
    return 1;
}


// 0x0016e8d0 FUN_0016e8d0 (12 B): matches/0x0016e8d0.cpp
// sym: ?FUN_0016e8d0@C_16e8d0@owners@@QAE_NE@Z
bool owners::C_16e8d0::FUN_0016e8d0(unsigned char v) {
    m4c = v;
    return true;
}


// 0x0016e8f0 FUN_0016e8f0 (18 B): matches/0x0016e8f0.cpp
// sym: ?FUN_0016e8f0@Target_16e8f0@owners@@QAEDM@Z
char owners::Target_16e8f0::FUN_0016e8f0(float x) {
    value = x * 0.017453292519943295f;
    return 1;
}


// 0x0016e920 FUN_0016e920 (12 B): matches/0x0016e920.cpp
// sym: ?FUN_0016e920@Obj_16e920@owners@@QAEDH@Z
char owners::Obj_16e920::FUN_0016e920(int x) {
    Value = x;
    return 1;
}


// 0x0016e940 FUN_0016e940 (12 B): matches/0x0016e940.cpp
// sym: ?FUN_0016e940@Obj_16e940@owners@@QAE_NH@Z
bool owners::Obj_16e940::FUN_0016e940(int x) {
    field = x;
    return true;
}


// 0x0016e960 FUN_0016e960 (12 B): matches/0x0016e960.cpp
// sym: ?FUN_0016e960@Obj_16e960@owners@@QAEDH@Z
char owners::Obj_16e960::FUN_0016e960(int x) {
    mVal = x;
    return 1;
}


// 0x0016e980 FUN_0016e980 (12 B): matches/0x0016e980.cpp
// sym: ?FUN_0016e980@Obj_16e980@owners@@QAE_NH@Z
bool owners::Obj_16e980::FUN_0016e980(int v) {
    m60 = v;
    return true;
}


// 0x0016e9a0 FUN_0016e9a0 (12 B): matches/0x0016e9a0.cpp
// sym: ?FUN_0016e9a0@Obj_16e9a0@owners@@QAEDH@Z
char owners::Obj_16e9a0::FUN_0016e9a0(int v) {
    m64 = v;
    return 1;
}


// 0x0016e9b0 FUN_0016e9b0 (12 B): matches/0x0016e9b0.cpp
// sym: ?FUN_0016e9b0@Obj_16e9b0@owners@@QAEDH@Z
char owners::Obj_16e9b0::FUN_0016e9b0(int v) {
    mVal = v;
    return 1;
}


// 0x0016e9c0 FUN_0016e9c0 (12 B): matches/0x0016e9c0.cpp
// sym: ?FUN_0016e9c0@Obj_16e9c0@owners@@QAEDPAH@Z
char owners::Obj_16e9c0::FUN_0016e9c0(int* p) {
    mPtr = p;
    return 1;
}


// 0x0016e9e0 FUN_0016e9e0 (12 B): matches/0x0016e9e0.cpp
// sym: ?FUN_0016e9e0@Obj_16e9e0@owners@@QAEEH@Z
unsigned char owners::Obj_16e9e0::FUN_0016e9e0(int v) {
    mVal = v;
    return 1;
}


// 0x0016ea00 FUN_0016ea00 (12 B): matches/0x0016ea00.cpp
// sym: ?FUN_0016ea00@O_16ea00@owners@@QAEDD@Z
char owners::O_16ea00::FUN_0016ea00(char v) {
    m18a = v;
    return 1;
}


// 0x0016ea20 FUN_0016ea20 (12 B): matches/0x0016ea20.cpp
// sym: ?FUN_0016ea20@O_16ea20@owners@@QAEEI@Z
unsigned char owners::O_16ea20::FUN_0016ea20(unsigned int x) {
    *(unsigned int*)(&pad[0x1c]) = x;
    return 1;
}


// 0x0016ea30 FUN_0016ea30 (12 B): matches/0x0016ea30.cpp
// sym: ?FUN_0016ea30@C_16ea30@owners@@QAE_NH@Z
bool owners::C_16ea30::FUN_0016ea30(int v) {
    mValue = v;
    return true;
}


// 0x0016ea40 FUN_0016ea40 (12 B): matches/0x0016ea40.cpp
// sym: ?FUN_0016ea40@Foo_16ea40@owners@@QAEDH@Z
char owners::Foo_16ea40::FUN_0016ea40(int v) {
    m = v;
    return 1;
}


// 0x0016ea50 FUN_0016ea50 (4 B): matches/0x0016ea50.cpp
// sym: ?FUN_0016ea50@Obj_16ea50@owners@@QAEPADXZ
char* owners::Obj_16ea50::FUN_0016ea50() {
    return (char*)this + 0x18;
}


// 0x0016ea70 FUN_0016ea70 (12 B): matches/0x0016ea70.cpp
// sym: ?FUN_0016ea70@O_16ea70@owners@@QAEDH@Z
char owners::O_16ea70::FUN_0016ea70(int x) {
    m20 = x;
    return 1;
}


// 0x0016ea90 FUN_0016ea90 (12 B): matches/0x0016ea90.cpp
// sym: ?FUN_0016ea90@X_16ea90@owners@@QAEDH@Z
char owners::X_16ea90::FUN_0016ea90(int v) {
    m24 = v;
    return 1;
}


// 0x0016eab0 FUN_0016eab0 (12 B): matches/0x0016eab0.cpp
// sym: ?FUN_0016eab0@Obj_16eab0@owners@@QAE_NH@Z
bool owners::Obj_16eab0::FUN_0016eab0(int v) {
    m28 = v;
    return true;
}


// 0x0016eac0 FUN_0016eac0 (12 B): matches/0x0016eac0.cpp
// sym: ?FUN_0016eac0@C_16eac0@owners@@QAEDI@Z
char owners::C_16eac0::FUN_0016eac0(unsigned int x) {
    m = x;
    return 1;
}


// 0x0016ead0 FUN_0016ead0 (12 B): matches/0x0016ead0.cpp
// sym: ?FUN_0016ead0@Obj_16ead0@owners@@QAEDH@Z
char owners::Obj_16ead0::FUN_0016ead0(int x) {
    value = x;
    return 1;
}


// 0x0016eae0 FUN_0016eae0 (12 B): matches/0x0016eae0.cpp
// sym: ?FUN_0016eae0@Obj_16eae0@owners@@QAE_NH@Z
bool owners::Obj_16eae0::FUN_0016eae0(int x) {
    value = x;
    return true;
}


// 0x0016eaf0 FUN_0016eaf0 (4 B): matches/0x0016eaf0.cpp
// sym: ?FUN_0016eaf0@Obj_16eaf0@owners@@QAEPADXZ
char* owners::Obj_16eaf0::FUN_0016eaf0() {
    return (char*)((char*)this + 0x18);
}


// 0x0016eb10 FUN_0016eb10 (12 B): matches/0x0016eb10.cpp
// sym: ?FUN_0016eb10@Obj_16eb10@owners@@QAEDD@Z
char owners::Obj_16eb10::FUN_0016eb10(char v) {
    m20 = v;
    return 1;
}


// 0x0016eb30 FUN_0016eb30 (12 B): matches/0x0016eb30.cpp
// sym: ?FUN_0016eb30@Obj_16eb30@owners@@QAEEE@Z
unsigned char owners::Obj_16eb30::FUN_0016eb30(unsigned char c) {
    value = c;
    return 1;
}


// 0x0016eb60 FUN_0016eb60 (26 B): matches/0x0016eb60.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4C_16eb60@fn_0016eb60@@QAE_NPAUS_16eb60@1@@Z
namespace fn_0016eb60 {
struct S_16eb60 {
    int a;
    int b;
    int c;
};
class C_16eb60 {
  public:
    char pad[0x24];
    int x;
    int y;
    int z;
    bool operator=(S_16eb60* p_16eb60);
};
bool C_16eb60::operator=(S_16eb60* p_16eb60) {
    x = p_16eb60->a;
    y = p_16eb60->b;
    z = p_16eb60->c;
    return true;
}
} // namespace fn_0016eb60


// 0x0016eb90 FUN_0016eb90 (12 B): matches/0x0016eb90.cpp
// sym: ?FUN_0016eb90@Obj_16eb90@owners@@QAEDD@Z
char owners::Obj_16eb90::FUN_0016eb90(char x) {
    Value = x;
    return 1;
}


// 0x0016ebc0 FUN_0016ebc0 (60 B): matches/0x0016ebc0.cpp
// sym: ?FUN_0016ebc0@Obj_16ebc0@owners@@QAEEPDM@Z
unsigned char owners::Obj_16ebc0::FUN_0016ebc0(const volatile float* p) {
    float a = p[0] * (*(float*)&DAT_003f32b8);
    float b = p[1] * (*(float*)&DAT_003f32b8);
    volatile float c[3];
    c[2] = p[2] * (*(float*)&DAT_003f32b8);
    z = c[2];
    x = a;
    y = b;
    return 1;
}


// 0x0016ec10 FUN_0016ec10 (12 B): matches/0x0016ec10.cpp
// sym: ?FUN_0016ec10@Obj_16ec10@owners@@QAEEH@Z
unsigned char owners::Obj_16ec10::FUN_0016ec10(int x) {
    value = x;
    return 1;
}


// 0x0016ec30 FUN_0016ec30 (12 B): matches/0x0016ec30.cpp
// sym: ?FUN_0016ec30@X_16ec30@owners@@QAEDH@Z
char owners::X_16ec30::FUN_0016ec30(int a) {
    m44 = a;
    return 1;
}


// 0x0016ec50 FUN_0016ec50 (12 B): matches/0x0016ec50.cpp
// sym: ?FUN_0016ec50@Obj_16ec50@owners@@QAE_NH@Z
bool owners::Obj_16ec50::FUN_0016ec50(int x) {
    value = x;
    return true;
}


// 0x0016ec60 FUN_0016ec60 (12 B): matches/0x0016ec60.cpp
// sym: ?FUN_0016ec60@Obj_16ec60@owners@@QAEDH@Z
char owners::Obj_16ec60::FUN_0016ec60(int v) {
    mVal = v;
    return 1;
}


// 0x0016ec70 FUN_0016ec70 (12 B): matches/0x0016ec70.cpp
// sym: ?FUN_0016ec70@Obj_16ec70@owners@@QAE_NH@Z
bool owners::Obj_16ec70::FUN_0016ec70(int v) {
    mValue = v;
    return true;
}


// 0x0016ec90 FUN_0016ec90 (12 B): matches/0x0016ec90.cpp
// sym: ?FUN_0016ec90@Obj_16ec90@owners@@QAE_NH@Z
bool owners::Obj_16ec90::FUN_0016ec90(int value) {
    field = value;
    return true;
}


// 0x0016ecb0 FUN_0016ecb0 (12 B): matches/0x0016ecb0.cpp
// sym: ?FUN_0016ecb0@Obj_16ecb0@owners@@QAE_NH@Z
bool owners::Obj_16ecb0::FUN_0016ecb0(int v) {
    mValue = v;
    return true;
}


// 0x0016ecc0 FUN_0016ecc0 (4 B): matches/0x0016ecc0.cpp
// sym: ?FUN_0016ecc0@Obj_16ecc0@owners@@QAEPAHXZ
int* owners::Obj_16ecc0::FUN_0016ecc0() {
    return &m;
}


// 0x0016ed00 FUN_0016ed00 (12 B): matches/0x0016ed00.cpp
// sym: ?FUN_0016ed00@Obj_16ed00@owners@@QAE_NH@Z
bool owners::Obj_16ed00::FUN_0016ed00(int v) {
    m30 = v;
    return true;
}


// 0x0016ed20 FUN_0016ed20 (18 B): matches/0x0016ed20.cpp
// sym: ?FUN_0016ed20@Obj_16ed20@owners@@QAEDM@Z
char owners::Obj_16ed20::FUN_0016ed20(float v) {
    m = v * 0.017453292519943295f;
    return 1;
}

namespace fn_fa642773 {

// 0x0016ed60 FUN_0016ed60 (26 B): matches/0x0016ed60.cpp
// sym: ?Set@Obj@fn_fa642773@@QAE_NABUVec@2@@Z
bool Obj::Set(Vec const& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return true;
}

} // namespace fn_fa642773

// 0x0016ed90 FUN_0016ed90 (12 B): matches/0x0016ed90.cpp
// sym: ?FUN_0016ed90@Obj_16ed90@owners@@QAEDH@Z
char owners::Obj_16ed90::FUN_0016ed90(int x) {
    mVal = x;
    return 1;
}


// 0x0016edb0 FUN_0016edb0 (12 B): matches/0x0016edb0.cpp
// sym: ?FUN_0016edb0@X_16edb0@owners@@QAEDH@Z
char owners::X_16edb0::FUN_0016edb0(int value) {
    m48 = value;
    return 1;
}


// 0x0016edd0 FUN_0016edd0 (12 B): matches/0x0016edd0.cpp
// sym: ?FUN_0016edd0@Obj_16edd0@owners@@QAEDH@Z
char owners::Obj_16edd0::FUN_0016edd0(int v) {
    mValue = v;
    return 1;
}


// 0x0016ede0 FUN_0016ede0 (12 B): matches/0x0016ede0.cpp
// sym: ?FUN_0016ede0@X_16ede0@owners@@QAEDH@Z
char owners::X_16ede0::FUN_0016ede0(int v) {
    mValue = v;
    return 1;
}


// 0x0016edf0 FUN_0016edf0 (12 B): matches/0x0016edf0.cpp
// sym: ?FUN_0016edf0@Obj_16edf0@owners@@QAEDH@Z
char owners::Obj_16edf0::FUN_0016edf0(int x) {
    mValue = x;
    return 1;
}


// 0x0016ee10 FUN_0016ee10 (12 B): matches/0x0016ee10.cpp
// sym: ?FUN_0016ee10@X_16ee10@owners@@QAEDH@Z
char owners::X_16ee10::FUN_0016ee10(int v) {
    value = v;
    return 1;
}


// 0x0016ee30 FUN_0016ee30 (12 B): matches/0x0016ee30.cpp
// sym: ?FUN_0016ee30@Obj_16ee30@owners@@QAEDH@Z
char owners::Obj_16ee30::FUN_0016ee30(int v) {
    mValue = v;
    return 1;
}


// 0x0016ee50 FUN_0016ee50 (12 B): matches/0x0016ee50.cpp
// sym: ?FUN_0016ee50@O_16ee50@owners@@QAE_NH@Z
bool owners::O_16ee50::FUN_0016ee50(int x) {
    m1c = x;
    return true;
}


// 0x0016ee70 FUN_0016ee70 (12 B): matches/0x0016ee70.cpp
// sym: ?FUN_0016ee70@Obj_16ee70@owners@@QAEDH@Z
char owners::Obj_16ee70::FUN_0016ee70(int x) {
    value = x;
    return 1;
}


// 0x0016ee80 FUN_0016ee80 (12 B): matches/0x0016ee80.cpp
// sym: ?FUN_0016ee80@X_16ee80@owners@@QAE_NH@Z
bool owners::X_16ee80::FUN_0016ee80(int a) {
    value = a;
    return true;
}


// 0x0016eea0 FUN_0016eea0 (12 B): matches/0x0016eea0.cpp
// sym: ?FUN_0016eea0@C_16eea0@owners@@QAEDH@Z
char owners::C_16eea0::FUN_0016eea0(int a) {
    m10 = a;
    return 1;
}


// 0x0016eeb0 FUN_0016eeb0 (12 B): matches/0x0016eeb0.cpp
// sym: ?FUN_0016eeb0@X_16eeb0@owners@@QAE_NH@Z
bool owners::X_16eeb0::FUN_0016eeb0(int v) {
    mVal = v;
    return true;
}


// 0x0016eed0 FUN_0016eed0 (12 B): matches/0x0016eed0.cpp
// sym: ?FUN_0016eed0@C_16eed0@owners@@QAE_NH@Z
bool owners::C_16eed0::FUN_0016eed0(int value) {
    mValue = value;
    return true;
}


// 0x0016eef0 FUN_0016eef0 (12 B): matches/0x0016eef0.cpp
// sym: ?FUN_0016eef0@X_16eef0@owners@@QAE_NH@Z
bool owners::X_16eef0::FUN_0016eef0(int v) {
    m = v;
    return true;
}


// 0x0016ef00 FUN_0016ef00 (4 B): matches/0x0016ef00.cpp
// sym: ?FUN_0016ef00@Obj_16ef00@owners@@QAEPAXXZ
void* owners::Obj_16ef00::FUN_0016ef00() {
    void* p = (char*)this + 0x18;
    return p;
}

namespace fn_fa642773 {

// 0x0016ef10 FUN_0016ef10 (4 B): matches/0x0016ef10.cpp
// sym: ?Get@Obj_16ef10@fn_fa642773@@QAEPADXZ
char* Obj_16ef10::Get() {
    return (char*)((char*)this + 0x20);
}


// 0x0016ef40 FUN_0016ef40 (26 B): matches/0x0016ef40.cpp
// sym: ?Set@Obj_16ef40@fn_fa642773@@QAE_NPBUVec3_16ef40@2@@Z
bool Obj_16ef40::Set(const Vec3_16ef40* p) {
    v28 = p->x;
    v2c = p->y;
    v30 = p->z;
    return true;
}


// 0x0016ef80 FUN_0016ef80 (26 B): matches/0x0016ef80.cpp
// sym: ?Set@Obj_16ef80@fn_fa642773@@QAE_NPAUSrc_16ef80@2@@Z
bool Obj_16ef80::Set(Src_16ef80* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}

} // namespace fn_fa642773

// 0x0016efb0 FUN_0016efb0 (12 B): matches/0x0016efb0.cpp
// sym: ?FUN_0016efb0@Obj_16efb0@owners@@QAEDPAX@Z
char owners::Obj_16efb0::FUN_0016efb0(void* x) {
    field = x;
    return 1;
}


// 0x0016efd0 FUN_0016efd0 (12 B): matches/0x0016efd0.cpp
// sym: ?FUN_0016efd0@Thing_16efd0@owners@@QAE_NH@Z
bool owners::Thing_16efd0::FUN_0016efd0(int x) {
    mValue = x;
    return true;
}


// 0x0016eff0 FUN_0016eff0 (12 B): matches/0x0016eff0.cpp
// sym: ?FUN_0016eff0@Obj_16eff0@owners@@QAEDH@Z
char owners::Obj_16eff0::FUN_0016eff0(int v) {
    *(int*)((char*)this + 0x48) = v;
    return 1;
}

namespace fn_fa642773 {

// 0x0016f000 FUN_0016f000 (4 B): matches/0x0016f000.cpp
// sym: ?Get@T_16f000@fn_fa642773@@QAEMXZ
float T_16f000::Get() {
    return value;
}

} // namespace fn_fa642773

// 0x0016f010 FUN_0016f010 (12 B): matches/0x0016f010.cpp
// sym: ?FUN_0016f010@X_16f010@owners@@QAEDH@Z
char owners::X_16f010::FUN_0016f010(int x) {
    mValue = x;
    return 1;
}


// 0x0016f030 FUN_0016f030 (12 B): matches/0x0016f030.cpp
// sym: ?FUN_0016f030@X_16f030@owners@@QAE_NH@Z
bool owners::X_16f030::FUN_0016f030(int value) {
    mValue = value;
    return true;
}


// 0x0016f050 FUN_0016f050 (12 B): matches/0x0016f050.cpp
// sym: ?FUN_0016f050@X_16f050@owners@@QAEDD@Z
char owners::X_16f050::FUN_0016f050(char b) {
    m54 = b;
    return 1;
}


// 0x0016f060 FUN_0016f060 (12 B): matches/0x0016f060.cpp
// sym: ?FUN_0016f060@X_16f060@owners@@QAEDH@Z
char owners::X_16f060::FUN_0016f060(int value) {
    this->value = value;
    return 1;
}


// 0x0016f070 FUN_0016f070 (12 B): matches/0x0016f070.cpp
// sym: ?FUN_0016f070@Obj_16f070@owners@@QAE_NH@Z
bool owners::Obj_16f070::FUN_0016f070(int value) {
    mFlag = value;
    return true;
}


// 0x0016f080 FUN_0016f080 (12 B): matches/0x0016f080.cpp
// sym: ?FUN_0016f080@Obj_16f080@owners@@QAE_NH@Z
bool owners::Obj_16f080::FUN_0016f080(int v) {
    mValue = v;
    return true;
}


// 0x0016f090 FUN_0016f090 (12 B): matches/0x0016f090.cpp
// sym: ?FUN_0016f090@X_16f090@owners@@QAE_NH@Z
bool owners::X_16f090::FUN_0016f090(int x) {
    mX = x;
    return true;
}


// 0x0016f0a0 FUN_0016f0a0 (12 B): matches/0x0016f0a0.cpp
// sym: ?FUN_0016f0a0@Obj_16f0a0@owners@@QAEDH@Z
char owners::Obj_16f0a0::FUN_0016f0a0(int v) {
    Value = v;
    return 1;
}


// 0x0016f0c0 FUN_0016f0c0 (12 B): matches/0x0016f0c0.cpp
// sym: ?FUN_0016f0c0@C_16f0c0@owners@@QAEDD@Z
char owners::C_16f0c0::FUN_0016f0c0(char x) {
    *(char*)((char*)this + 0x14) = x;
    return 1;
}

namespace fn_fa642773 {

// 0x0016f0f0 FUN_0016f0f0 (26 B): matches/0x0016f0f0.cpp
// sym: ?Fn@O_16f0f0@fn_fa642773@@QAE_NPAUVec3_16f0f0@2@@Z
bool O_16f0f0::Fn(Vec3_16f0f0* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}

} // namespace fn_fa642773

// 0x0016f120 FUN_0016f120 (12 B): matches/0x0016f120.cpp
// sym: ?FUN_0016f120@Obj_16f120@owners@@QAEEE@Z
unsigned char owners::Obj_16f120::FUN_0016f120(unsigned char x) {
    m24 = x;
    return 1;
}


// 0x0016f140 FUN_0016f140 (12 B): matches/0x0016f140.cpp
// sym: ?FUN_0016f140@X_16f140@owners@@QAE_ND@Z
bool owners::X_16f140::FUN_0016f140(char c) {
    m = c;
    return true;
}

namespace fn_fa642773 {

// 0x0016f160 FUN_0016f160 (12 B): matches/0x0016f160.cpp
// sym: ?f@A_16f160@fn_fa642773@@QAEDH@Z
char A_16f160::f(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x0016f170 FUN_0016f170 (12 B): matches/0x0016f170.cpp
// sym: ?Set@Obj_16f170@fn_fa642773@@QAEDH@Z
char Obj_16f170::Set(int x) {
    value = x;
    return 1;
}


// 0x0016f1a0 FUN_0016f1a0 (26 B): matches/0x0016f1a0.cpp
// sym: ?Fn@Obj_16f1a0@fn_fa642773@@QAEEPAUSrc_16f1a0@2@@Z
unsigned char Obj_16f1a0::Fn(Src_16f1a0* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}


// 0x0016f1c0 FUN_0016f1c0 (12 B): matches/0x0016f1c0.cpp
// sym: ?SetTimeBegin_0016f1c0@Obj_16f1c0@fn_fa642773@@QAE_NH@Z
bool Obj_16f1c0::SetTimeBegin_0016f1c0(int v) {
    value = v;
    return true;
}


// 0x0016f1d0 FUN_0016f1d0 (12 B): matches/0x0016f1d0.cpp
// sym: ?SetTimeEnd_0016f1d0@Obj_16f1d0@fn_fa642773@@QAEDH@Z
char Obj_16f1d0::SetTimeEnd_0016f1d0(int x) {
    m10 = x;
    return 1;
}


// 0x0016f1f0 FUN_0016f1f0 (12 B): matches/0x0016f1f0.cpp
// sym: ?SetMotionState_0016f1f0@A_16f1f0@fn_fa642773@@QAE_NPAX@Z
bool A_16f1f0::SetMotionState_0016f1f0(void* p) {
    *(void**)((char*)this + 0x14) = p;
    return true;
}


// 0x0016f200 FUN_0016f200 (12 B): matches/0x0016f200.cpp
// sym: ?SetTimeBegin_0016f200@Obj_16f200@fn_fa642773@@QAE_NPAX@Z
bool Obj_16f200::SetTimeBegin_0016f200(void* p) {
    mField = p;
    return true;
}


// 0x0016f210 FUN_0016f210 (12 B): matches/0x0016f210.cpp
// sym: ?SetTimeEnd_0016f210@Obj_16f210@fn_fa642773@@QAEDH@Z
char Obj_16f210::SetTimeEnd_0016f210(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}


// 0x0016f230 FUN_0016f230 (12 B): matches/0x0016f230.cpp
// sym: ?SetFinalVelocity_0016f230@X_16f230@fn_fa642773@@QAE_NH@Z
bool X_16f230::SetFinalVelocity_0016f230(int a) {
    m14 = a;
    return true;
}

} // namespace fn_fa642773

// 0x0016f240 FUN_0016f240 (12 B): matches/0x0016f240.cpp
// sym: ?FUN_0016f240@X_16f240@owners@@QAE_NH@Z
bool owners::X_16f240::FUN_0016f240(int v) {
    mVal = v;
    return true;
}


// 0x0016f250 FUN_0016f250 (12 B): matches/0x0016f250.cpp
// sym: ?FUN_0016f250@Obj_16f250@owners@@QAEDH@Z
char owners::Obj_16f250::FUN_0016f250(int x) {
    mC = x;
    return 1;
}


// 0x0016f260 FUN_0016f260 (12 B): matches/0x0016f260.cpp
// sym: ?FUN_0016f260@X_16f260@owners@@QAEDH@Z
char owners::X_16f260::FUN_0016f260(int v) {
    mValue = v;
    return 1;
}


// 0x0016f270 FUN_0016f270 (4 B): matches/0x0016f270.cpp
// sym: ?FUN_0016f270@Obj_16f270@owners@@QAEPAXXZ
void* owners::Obj_16f270::FUN_0016f270() {
    return (char*)this + 0x18;
}

namespace fn_fa642773 {

// 0x0016f2a0 FUN_0016f2a0 (26 B): matches/0x0016f2a0.cpp
// sym: ?Set@Obj_16f2a0@fn_fa642773@@QAEDPAUVec3_16f2a0@2@@Z
char Obj_16f2a0::Set(Vec3_16f2a0* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return 1;
}


// 0x0016f2e0 FUN_0016f2e0 (26 B): matches/0x0016f2e0.cpp
// sym: ?Set@Ctx_16f2e0@fn_fa642773@@QAEDPAUData_16f2e0@2@@Z
char Ctx_16f2e0::Set(Data_16f2e0* d) {
    m2c = d->a;
    m30 = d->b;
    m34 = d->c;
    return 1;
}

} // namespace fn_fa642773

// 0x0016f310 FUN_0016f310 (12 B): matches/0x0016f310.cpp
// sym: ?FUN_0016f310@X_16f310@owners@@QAEDH@Z
char owners::X_16f310::FUN_0016f310(int v) {
    m38 = v;
    return 1;
}


// 0x0016f330 FUN_0016f330 (12 B): matches/0x0016f330.cpp
// sym: ?FUN_0016f330@Thing_16f330@owners@@QAEDH@Z
char owners::Thing_16f330::FUN_0016f330(int x) {
    value = x;
    return 1;
}


// 0x0016f350 FUN_0016f350 (12 B): matches/0x0016f350.cpp
// sym: ?FUN_0016f350@X_16f350@owners@@QAEDD@Z
char owners::X_16f350::FUN_0016f350(char c) {
    m40 = c;
    return 1;
}


// 0x0016f360 FUN_0016f360 (12 B): matches/0x0016f360.cpp
// sym: ?FUN_0016f360@Obj_16f360@owners@@QAEDH@Z
char owners::Obj_16f360::FUN_0016f360(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}


// 0x0016f390 FUN_0016f390 (26 B): matches/0x0016f390.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_0016f390@@QAEDPBUVec@2@@Z
namespace fn_0016f390 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[16];
    int x, y, z;

  public:
    char Set(const Vec* p);
};
char Obj::Set(const Vec* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return 1;
}
} // namespace fn_0016f390


// 0x0016f3b0 FUN_0016f3b0 (12 B): matches/0x0016f3b0.cpp
// sym: ?FUN_0016f3b0@Obj_16f3b0@owners@@QAEDH@Z
char owners::Obj_16f3b0::FUN_0016f3b0(int x) {
    mValue = x;
    return 1;
}


// 0x0016f3c0 FUN_0016f3c0 (12 B): matches/0x0016f3c0.cpp
// sym: ?FUN_0016f3c0@Obj_16f3c0@owners@@QAE_NH@Z
bool owners::Obj_16f3c0::FUN_0016f3c0(int v) {
    mVal = v;
    return true;
}


// 0x0016f3d0 FUN_0016f3d0 (4 B): matches/0x0016f3d0.cpp
// sym: ?FUN_0016f3d0@O_16f3d0@owners@@QAEPAXXZ
void* owners::O_16f3d0::FUN_0016f3d0() {
    return (char*)this + 0x18;
}

namespace fn_fa642773 {

// 0x0016f400 FUN_0016f400 (26 B): matches/0x0016f400.cpp
// sym: ?Set@Obj_16f400@fn_fa642773@@QAE_NPAUSrc_16f400@2@@Z
bool Obj_16f400::Set(Src_16f400* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}


// 0x0016f440 FUN_0016f440 (26 B): matches/0x0016f440.cpp
// sym: ?Set@Obj_16f440@fn_fa642773@@QAE_NPAUVec3_16f440@2@@Z
bool Obj_16f440::Set(Vec3_16f440* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fa642773

// 0x0016f470 FUN_0016f470 (18 B): matches/0x0016f470.cpp
// sym: ?FUN_0016f470@Obj_16f470@owners@@QAEDM@Z
char owners::Obj_16f470::FUN_0016f470(float x) {
    Value = x * 0.017453292519943295f;
    return 1;
}


// 0x0016f4a0 FUN_0016f4a0 (18 B): matches/0x0016f4a0.cpp
// sym: ?FUN_0016f4a0@Obj_16f4a0@owners@@QAE_NM@Z
bool owners::Obj_16f4a0::FUN_0016f4a0(float a) {
    float r = a * RAD;
    *(float*)((char*)this + 0x3c) = r;
    return true;
}


// 0x0016f4d0 FUN_0016f4d0 (18 B): matches/0x0016f4d0.cpp
// sym: ?FUN_0016f4d0@Obj_16f4d0@owners@@QAE_NM@Z
bool owners::Obj_16f4d0::FUN_0016f4d0(float angle) {
    m_angle = angle * 0.0174532925f;
    return true;
}


// 0x0016f500 FUN_0016f500 (12 B): matches/0x0016f500.cpp
// sym: ?FUN_0016f500@Obj_16f500@owners@@QAEEE@Z
unsigned char owners::Obj_16f500::FUN_0016f500(unsigned char a) {
    m = a;
    return 1;
}


// 0x0016f520 FUN_0016f520 (18 B): matches/0x0016f520.cpp
// sym: ?FUN_0016f520@Obj_16f520@owners@@QAEDM@Z
char owners::Obj_16f520::FUN_0016f520(float v) {
    angle = v * 0.017453292519943295f;
    return 1;
}


// 0x0016f550 FUN_0016f550 (12 B): matches/0x0016f550.cpp
// sym: ?FUN_0016f550@Obj_16f550@owners@@QAEDH@Z
char owners::Obj_16f550::FUN_0016f550(int x) {
    m4c = x;
    return 1;
}


// 0x0016f570 FUN_0016f570 (12 B): matches/0x0016f570.cpp
// sym: ?FUN_0016f570@Obj_16f570@owners@@QAEDH@Z
char owners::Obj_16f570::FUN_0016f570(int v) {
    value = v;
    return 1;
}


// 0x0016f590 FUN_0016f590 (12 B): matches/0x0016f590.cpp
// sym: ?FUN_0016f590@X_16f590@owners@@QAE_NH@Z
bool owners::X_16f590::FUN_0016f590(int v) {
    m = v;
    return true;
}


// 0x0016f5b0 FUN_0016f5b0 (12 B): matches/0x0016f5b0.cpp
// sym: ?FUN_0016f5b0@X_16f5b0@owners@@QAE_NH@Z
bool owners::X_16f5b0::FUN_0016f5b0(int v) {
    m58 = v;
    return true;
}


// 0x0016f5d0 FUN_0016f5d0 (12 B): matches/0x0016f5d0.cpp
// sym: ?FUN_0016f5d0@X_16f5d0@owners@@QAEDH@Z
char owners::X_16f5d0::FUN_0016f5d0(int v) {
    mVal = v;
    return 1;
}


// 0x0016f5e0 FUN_0016f5e0 (12 B): matches/0x0016f5e0.cpp
// sym: ?FUN_0016f5e0@Obj_16f5e0@owners@@QAE_NH@Z
bool owners::Obj_16f5e0::FUN_0016f5e0(int x) {
    value = x;
    return true;
}


// 0x0016f5f0 FUN_0016f5f0 (12 B): matches/0x0016f5f0.cpp
// sym: ?FUN_0016f5f0@Obj_16f5f0@owners@@QAE_NH@Z
bool owners::Obj_16f5f0::FUN_0016f5f0(int value) {
    *(int*)((char*)this + 0x10) = value;
    return true;
}


// 0x0016f610 FUN_0016f610 (12 B): matches/0x0016f610.cpp
// sym: ?FUN_0016f610@Obj_16f610@owners@@QAE_NH@Z
bool owners::Obj_16f610::FUN_0016f610(int x) {
    m14 = x;
    return true;
}


// 0x0016f630 FUN_0016f630 (12 B): matches/0x0016f630.cpp
// sym: ?FUN_0016f630@Obj_16f630@owners@@QAE_NH@Z
bool owners::Obj_16f630::FUN_0016f630(int v) {
    m18 = v;
    return true;
}


// 0x0016f650 FUN_0016f650 (12 B): matches/0x0016f650.cpp
// sym: ?FUN_0016f650@Target_16f650@owners@@QAEDH@Z
char owners::Target_16f650::FUN_0016f650(int value) {
    m1c = value;
    return 1;
}


// 0x0016f670 FUN_0016f670 (12 B): matches/0x0016f670.cpp
// sym: ?FUN_0016f670@O_16f670@owners@@QAE_NH@Z
bool owners::O_16f670::FUN_0016f670(int x) {
    m20 = x;
    return true;
}


// 0x0016f690 FUN_0016f690 (18 B): matches/0x0016f690.cpp
// sym: ?FUN_0016f690@Thing_16f690@owners@@QAE_NM@Z
bool owners::Thing_16f690::FUN_0016f690(float v) {
    angle = v * 0.0174532925f;
    return true;
}


// 0x0016f6f0 FUN_0016f6f0 (18 B): matches/0x0016f6f0.cpp
// sym: ?FUN_0016f6f0@Obj_16f6f0@owners@@QAEDM@Z
char owners::Obj_16f6f0::FUN_0016f6f0(float f) {
    m = f * 0.017453292f;
    return 1;
}


// 0x0016f720 FUN_0016f720 (18 B): matches/0x0016f720.cpp
// sym: ?FUN_0016f720@Obj_16f720@owners@@QAEDM@Z
char owners::Obj_16f720::FUN_0016f720(float x) {
    value = x * 0.017453292f;
    return 1;
}


// 0x0016f750 FUN_0016f750 (18 B): matches/0x0016f750.cpp
// sym: ?FUN_0016f750@Obj_16f750@owners@@QAEDM@Z
char owners::Obj_16f750::FUN_0016f750(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}


// 0x0016f780 FUN_0016f780 (18 B): matches/0x0016f780.cpp
// sym: ?FUN_0016f780@Obj_16f780@owners@@QAEDM@Z
char owners::Obj_16f780::FUN_0016f780(float v) {
    angle = v * 0.017453292f;
    return 1;
}


// 0x0016f7b0 FUN_0016f7b0 (12 B): matches/0x0016f7b0.cpp
// sym: ?FUN_0016f7b0@O_16f7b0@owners@@QAEDH@Z
char owners::O_16f7b0::FUN_0016f7b0(int v) {
    m3c = v;
    return 1;
}


// 0x0016f7d0 FUN_0016f7d0 (12 B): matches/0x0016f7d0.cpp
// sym: ?FUN_0016f7d0@Obj_16f7d0@owners@@QAEDH@Z
char owners::Obj_16f7d0::FUN_0016f7d0(int v) {
    mValue = v;
    return 1;
}


// 0x0016f7f0 FUN_0016f7f0 (12 B): matches/0x0016f7f0.cpp
// sym: ?FUN_0016f7f0@Obj_16f7f0@owners@@QAEDH@Z
char owners::Obj_16f7f0::FUN_0016f7f0(int x) {
    value = x;
    return 1;
}


// 0x0016f800 FUN_0016f800 (12 B): matches/0x0016f800.cpp
// sym: ?FUN_0016f800@Obj_16f800@owners@@QAE_NH@Z
bool owners::Obj_16f800::FUN_0016f800(int v) {
    mVal = v;
    return true;
}


// 0x0016f810 FUN_0016f810 (12 B): matches/0x0016f810.cpp
// sym: ?FUN_0016f810@Obj_16f810@owners@@QAE_NH@Z
bool owners::Obj_16f810::FUN_0016f810(int v) {
    mValue = v;
    return true;
}


// 0x0016f830 FUN_0016f830 (12 B): matches/0x0016f830.cpp
// sym: ?FUN_0016f830@Obj_16f830@owners@@QAE_NH@Z
bool owners::Obj_16f830::FUN_0016f830(int arg) {
    m14 = arg;
    return true;
}


// 0x0016f850 FUN_0016f850 (12 B): matches/0x0016f850.cpp
// sym: ?FUN_0016f850@Obj_16f850@owners@@QAEDH@Z
char owners::Obj_16f850::FUN_0016f850(int v) {
    mValue = v;
    return 1;
}


// 0x0016f870 FUN_0016f870 (12 B): matches/0x0016f870.cpp
// sym: ?FUN_0016f870@X_16f870@owners@@QAE_NH@Z
bool owners::X_16f870::FUN_0016f870(int value) {
    mField = value;
    return true;
}

namespace fn_fa642773 {

// 0x0016f880 FUN_0016f880 (12 B): matches/0x0016f880.cpp
// sym: ?Fn@Obj_16f880@fn_fa642773@@QAE_NPAX@Z
bool Obj_16f880::Fn(void* p) {
    mPtr = p;
    return true;
}


// 0x0016f8a0 FUN_0016f8a0 (12 B): matches/0x0016f8a0.cpp
// sym: ?Set@Obj_16f8a0@fn_fa642773@@QAE_NH@Z
bool Obj_16f8a0::Set(int x) {
    m10 = x;
    return true;
}

} // namespace fn_fa642773

// 0x0016f8b0 FUN_0016f8b0 (12 B): matches/0x0016f8b0.cpp
// sym: ?FUN_0016f8b0@Obj_16f8b0@owners@@QAEDH@Z
char owners::Obj_16f8b0::FUN_0016f8b0(int v) {
    *(int*)((char*)this + 12) = v;
    return 1;
}


// 0x0016f8c0 FUN_0016f8c0 (12 B): matches/0x0016f8c0.cpp
// sym: ?FUN_0016f8c0@Obj_16f8c0@owners@@QAE_NH@Z
bool owners::Obj_16f8c0::FUN_0016f8c0(int x) {
    m10 = x;
    return true;
}


// 0x0016f8e0 FUN_0016f8e0 (12 B): matches/0x0016f8e0.cpp
// sym: ?FUN_0016f8e0@X_16f8e0@owners@@QAE_NH@Z
bool owners::X_16f8e0::FUN_0016f8e0(int x) {
    m = x;
    return true;
}


// 0x0016f920 FUN_0016f920 (12 B): matches/0x0016f920.cpp
// sym: ?FUN_0016f920@C_16f920@owners@@QAEDH@Z
char owners::C_16f920::FUN_0016f920(int v) {
    m = v;
    return 1;
}

namespace fn_fa642773 {

// 0x0016f930 FUN_0016f930 (12 B): matches/0x0016f930.cpp
// sym: ?SetTimeBegin_0016f930@Obj_16f930@fn_fa642773@@QAE_NH@Z
bool Obj_16f930::SetTimeBegin_0016f930(int v) {
    mVal = v;
    return true;
}


// 0x0016f960 FUN_0016f960 (26 B): matches/0x0016f960.cpp
// sym: ?SetOffset_0016f960@Obj_16f960@fn_fa642773@@QAEDPAX@Z
char Obj_16f960::SetOffset_0016f960(void* p) {
    int* q = (int*)p;
    a = q[0];
    b = q[1];
    c = q[2];
    return 1;
}


// 0x0016f9a0 FUN_0016f9a0 (26 B): matches/0x0016f9a0.cpp
// sym: ?SetMinimum_0016f9a0@Obj_16f9a0@fn_fa642773@@QAEDPAUData_16f9a0@2@@Z
char Obj_16f9a0::SetMinimum_0016f9a0(Data_16f9a0* p) {
    m1c = p->a;
    m20 = p->b;
    m24 = p->c;
    return 1;
}


// 0x0016f9d0 FUN_0016f9d0 (12 B): matches/0x0016f9d0.cpp
// sym: ?SetTraceWidth_0016f9d0@Obj_16f9d0@fn_fa642773@@QAE_NH@Z
bool Obj_16f9d0::SetTraceWidth_0016f9d0(int v) {
    mVal = v;
    return true;
}

} // namespace fn_fa642773

// 0x0016f9e0 FUN_0016f9e0 (12 B): matches/0x0016f9e0.cpp
// sym: ?FUN_0016f9e0@X_16f9e0@owners@@QAE_NH@Z
bool owners::X_16f9e0::FUN_0016f9e0(int v) {
    mValue = v;
    return true;
}


// 0x0016f9f0 FUN_0016f9f0 (12 B): matches/0x0016f9f0.cpp
// sym: ?FUN_0016f9f0@Obj_16f9f0@owners@@QAEDH@Z
char owners::Obj_16f9f0::FUN_0016f9f0(int x) throw() {
    m10 = x;
    return 1;
}

namespace fn_fa642773 {

// 0x0016fa00 FUN_0016fa00 (12 B): matches/0x0016fa00.cpp
// sym: ?SetTimeBegin_0016fa00@Obj_16fa00@fn_fa642773@@QAE_NH@Z
bool Obj_16fa00::SetTimeBegin_0016fa00(int x) {
    m = x;
    return true;
}


// 0x0016fa40 FUN_0016fa40 (26 B): matches/0x0016fa40.cpp
// sym: ?SetOffset_0016fa40@Obj_16fa40@fn_fa642773@@QAE_NPBUSrc_16fa40@2@@Z
bool Obj_16fa40::SetOffset_0016fa40(const Src_16fa40* other) {
    f14 = other->a;
    f18 = other->b;
    f1c = other->c;
    return true;
}


// 0x0016fa60 FUN_0016fa60 (12 B): matches/0x0016fa60.cpp
// sym: ?SetTimeBegin_0016fa60@X_16fa60@fn_fa642773@@QAEDH@Z
char X_16fa60::SetTimeBegin_0016fa60(int v) {
    m12 = v;
    return 1;
}


// 0x0016fa70 FUN_0016fa70 (12 B): matches/0x0016fa70.cpp
// sym: ?SetTimeEnd_0016fa70@Obj_16fa70@fn_fa642773@@QAE_NH@Z
bool Obj_16fa70::SetTimeEnd_0016fa70(int v) {
    mValue = v;
    return true;
}


// 0x0016fa90 FUN_0016fa90 (12 B): matches/0x0016fa90.cpp
// sym: ?SetClearOnBegin_0016fa90@Obj_16fa90@fn_fa642773@@QAEDD@Z
char Obj_16fa90::SetClearOnBegin_0016fa90(char v) {
    m14 = v;
    return 1;
}

} // namespace fn_fa642773

// 0x0016faa0 FUN_0016faa0 (12 B): matches/0x0016faa0.cpp
// sym: ?FUN_0016faa0@Obj_16faa0@owners@@QAEDH@Z
char owners::Obj_16faa0::FUN_0016faa0(int v) {
    int x = v;
    m = x;
    return 1;
}


// 0x0016fac0 FUN_0016fac0 (12 B): matches/0x0016fac0.cpp
// sym: ?FUN_0016fac0@Obj_16fac0@owners@@QAEDD@Z
char owners::Obj_16fac0::FUN_0016fac0(char v) {
    value = v;
    return 1;
}


// 0x0016fad0 FUN_0016fad0 (12 B): matches/0x0016fad0.cpp
// sym: ?FUN_0016fad0@C_16fad0@owners@@QAEDH@Z
char owners::C_16fad0::FUN_0016fad0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x0016fae0 FUN_0016fae0 (12 B): matches/0x0016fae0.cpp
// sym: ?FUN_0016fae0@Obj_16fae0@owners@@QAEDH@Z
char owners::Obj_16fae0::FUN_0016fae0(int x) {
    m = x;
    return 1;
}


// 0x0016faf0 FUN_0016faf0 (4 B): matches/0x0016faf0.cpp
// sym: ?FUN_0016faf0@X_16faf0@owners@@QAEPAXXZ
void* owners::X_16faf0::FUN_0016faf0() {
    return (char*)this + 0x18;
}


// 0x0016fb20 FUN_0016fb20 (26 B): matches/0x0016fb20.cpp
// sym: ?FUN_0016fb20@A_16fb20@owners@@QAE_NPAH@Z
bool owners::A_16fb20::FUN_0016fb20(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}


// 0x0016fb50 FUN_0016fb50 (18 B): matches/0x0016fb50.cpp
// sym: ?FUN_0016fb50@X_16fb50@owners@@QAEEM@Z
unsigned char owners::X_16fb50::FUN_0016fb50(float angle) {
    value = angle * 0.017453292f;
    return 1;
}


// 0x0016fb80 FUN_0016fb80 (18 B): matches/0x0016fb80.cpp
// sym: ?FUN_0016fb80@Obj_16fb80@owners@@QAEDM@Z
char owners::Obj_16fb80::FUN_0016fb80(float deg) {
    float rad = deg * 0.0174532925f;
    angle = rad;
    return 1;
}


// 0x0016fbb0 FUN_0016fbb0 (12 B): matches/0x0016fbb0.cpp
// sym: ?FUN_0016fbb0@C_16fbb0@owners@@QAE_ND@Z
bool owners::C_16fbb0::FUN_0016fbb0(char c) {
    m34 = c;
    return true;
}


// 0x0016fbd0 FUN_0016fbd0 (12 B): matches/0x0016fbd0.cpp
// sym: ?FUN_0016fbd0@Obj_16fbd0@owners@@QAEDH@Z
char owners::Obj_16fbd0::FUN_0016fbd0(int a) {
    m38 = a;
    return 1;
}


// 0x0016fbf0 FUN_0016fbf0 (12 B): matches/0x0016fbf0.cpp
// sym: ?FUN_0016fbf0@X_16fbf0@owners@@QAEDH@Z
char owners::X_16fbf0::FUN_0016fbf0(int v) {
    *(int*)((char*)this + 0x3c) = v;
    return 1;
}


// 0x0016fc10 FUN_0016fc10 (12 B): matches/0x0016fc10.cpp
// sym: ?FUN_0016fc10@Obj_16fc10@owners@@QAE_NH@Z
bool owners::Obj_16fc10::FUN_0016fc10(int v) {
    m40 = v;
    return true;
}


// 0x0016fc60 FUN_0016fc60 (33 B): matches/0x0016fc60.cpp
// sym: ?FUN_0016fc60@Thing_16fc60@owners@@QAEXPAH@Z
void owners::Thing_16fc60::FUN_0016fc60(int* out) {
    out[0] = a;
    out[1] = b;
    out[2] = c;
}

namespace fn_fa642773 {

// 0x0016fc90 FUN_0016fc90 (30 B): matches/0x0016fc90.cpp
// sym: ?FUN@Thing_16fc90@fn_fa642773@@QAEHH@Z
int Thing_16fc90::FUN(hulk_intptr arg) {
    m->v8((char*)this + 0x98, arg, -1);
    return arg;
}


// 0x0016fcb0 FUN_0016fcb0 (19 B): matches/0x0016fcb0.cpp
// sym: ?FUN_0016fcb0@fn_fa642773@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0016fcb0() {
    FUN_00234810(((char*)&DAT_004e12e8), ((char*)&DAT_004e12ec));
}

} // namespace fn_fa642773
