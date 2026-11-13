// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00192030..0x00193bc0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa51549e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa51549e {} using namespace fn_fa51549e;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_fa51549e {
class Obj_192030 {
  public:
    char pad[0xd0];
    int mValue;
    void Set(int value);
};
struct Sub_1921b0 {
    char data[0x18];
};
struct Obj_1921b0 {
    char pad[0x18];
    Sub_1921b0* Get();
};
struct Src_1921e0 {
    int a, b, c;
};
class Obj_1921e0 {
  public:
    char pad[0x20];
    int m20, m24, m28;
    bool Set(Src_1921e0* p);
};
struct Vec3_192270 {
    int x, y, z;
};
class Obj_192270 {
  public:
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(Vec3_192270* v);
};
} // namespace fn_fa51549e
extern "C" const float __real_3c8efa35 = 0.017453292f;
namespace fn_fa51549e {
struct Vec3 {
  public:
    int x;
    int y;
    int z;
};
struct Inner_1924f0 {
    char m[0x9c];
};
struct Obj_1924f0 {
    Inner_1924f0* Get();
};
struct Src_1925c0 {
    int a, b, c;
};
class Obj_1925c0 {
  public:
    char Set(Src_1925c0* p);
    char pad[18];
    int m14, m18, m1c;
};
class X_1925f0 {
  public:
    virtual void V();
    char pad[0x1c];
    int m20;
    char Set(int a);
};
struct Obj_192770 {
    char pad[12];
    int mValue;
    bool SetTimeBegin_00192770(int value);
};
class Obj_192780 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_00192780(int value);
};
const float gRad = 0.017453292f;
class Obj_1927a0 {
  public:
    char SetArc_001927a0(float f);
    char pad[0x14];
    float mAngle;
};
class Obj_1927c0 {
  public:
    char m[24];
    char* GetGiverBranch_001927c0();
};
class X_1927e0 {
  public:
    char pad[0x10];
    int value;
    bool SetTimeEnd_001927e0(int v);
};
class Obj_192800 {
  public:
    char pad[0x14];
    int m14;
    char SetDecay_00192800(int x);
};
class Obj_192820 {
  public:
    char Pad[0x18];
    int value;
    char SetDecayScaler_00192820(int x);
};
struct Vec {
    int x, y, z;
};
struct Src_1928d0 {
    int a;
    int b;
    int c;
};
class Obj_1928d0 {
  public:
    char p38[0x38];
    int m38;
    int m3c;
    int m40;
    char Set(Src_1928d0* p);
};
struct S_192910 {
    int a;
    int b;
    int c;
};
class T_192910 {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    char Fn(S_192910* p);
};
extern "C" const float k_1929b0 = 0.017453292f;
struct Data_192a60 {
    int a;
    int b;
    int c;
};
class Owner_192a60 {
  public:
    char pad[0x78];
    int m78;
    int m7c;
    int m80;
    bool Set(Data_192a60* d);
};
struct Sub_192b90 {
    char x[176];
};
struct Target_192b90 {
    char pad[0xb0];
    Sub_192b90 sub;
    Sub_192b90* Get();
};
struct V {
    int x, y, z;
};
class C {
    char pad[0xe0];
    V v;

  public:
    V Get();
};
struct Src {
  public:
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char _m_pad_0[0xc];
    int value;
    char _m_pad_10[0x10];
    int x;
    int y;
    int z;
    char _m_pad_2c[0x64];
    int v[3];
    char _m_pad_9c[0x2c];
    Vec3 mVec;
    char _m_pad_d4[0x38];
    int m10c;
    int m110;
    int m114;
    char Set(Vec3* p);
    char SetTimeBegin_001927d0(int v);
    char Set(const Vec& p);
    bool Set(const Vec3* v);
    bool Set(Src* s);
};
class Tgt {
  public:
    char pad[0x11c];
    int x;
    int y;
    int z;
    bool Copy(Src* s);
};
struct Triple {
    int a;
    int b;
    int c;
};
class Owner_192fe0 {
  public:
    char pad[0x28];
    int m28;
    int m2c;
    int m30;
    bool Assign(Triple* p);
};
struct Vec3_193050 {
    int x;
    int y;
    int z;
};
class Obj_193050 {
  public:
    char pad[0x40];
    int m40;
    int m44;
    int m48;
    bool Set(const Vec3_193050* v);
};
struct Src_193090 {
    int a;
    int b;
    int c;
};
class Obj_193090 {
  public:
    char pad[0x4c];
    int x;
    int y;
    int z;
    bool Set(Src_193090* s);
};
class Base_1932b0 {
  public:
    virtual void F0();
    char pad[0x80];
    float mAngle;
    bool SetRadians(float r);
};
class X_193370 {
  public:
    char pad[0x96];
    unsigned char GetValue();
};
struct Item_1936e0 {
    void* f();
};
class Obj_1936e0 {
  public:
    char pad[0x128];
    Item_1936e0 item;
    void* Get() { return item.f(); }
};
struct T {
    int a;
    int b;
    int c;
};
class O {
  public:
    char pad[0x130];
    int x;
    int y;
    int z;
    bool Set(T* p);
};
struct Src_193820;
class Obj_193820 {
  public:
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
    bool Set(const struct Src_193820* s);
};
struct Src_193820 {
    int a;
    int b;
    int c;
};
struct Vec3_193930 {
    int x, y, z;
};
class Obj_193930 {
  public:
    char pad[0x48];
    Vec3_193930 mVec;
    bool Set(const Vec3_193930* v);
};
class Target {
  public:
    char pad[0x80];
    int m80;
    int m84;
    int m88;
    char Fn(Src* p);
};
struct Inner_193b90 {
    char c;
};
class Obj_193b90 {
  public:
    char pad[0xa8];
    Inner_193b90 m;
    Inner_193b90* GetBody();
};


// 0x00192030 FUN_00192030 (13 B): matches/0x00192030.cpp
// sym: ?Set@Obj_192030@fn_fa51549e@@QAEXH@Z
void Obj_192030::Set(int value) {
    mValue = value;
}

} // namespace fn_fa51549e

// 0x00192160 FUN_00192160 (12 B): matches/0x00192160.cpp
// sym: ?FUN_00192160@X_192160@owners@@QAEDD@Z
char owners::X_192160::FUN_00192160(char c) {
    m = c;
    return 1;
}


// 0x00192170 FUN_00192170 (12 B): matches/0x00192170.cpp
// sym: ?FUN_00192170@X_192170@owners@@QAEDH@Z
char owners::X_192170::FUN_00192170(int a) {
    mField = a;
    return 1;
}


// 0x00192180 FUN_00192180 (12 B): matches/0x00192180.cpp
// sym: ?FUN_00192180@O_192180@owners@@QAEDD@Z
char owners::O_192180::FUN_00192180(char c) {
    m = c;
    return 1;
}


// 0x00192190 FUN_00192190 (12 B): matches/0x00192190.cpp
// sym: ?FUN_00192190@X_192190@owners@@QAE_NH@Z
bool owners::X_192190::FUN_00192190(int v) {
    value = v;
    return true;
}


// 0x001921a0 FUN_001921a0 (12 B): matches/0x001921a0.cpp
// sym: ?FUN_001921a0@C_1921a0@owners@@QAE_NH@Z
bool owners::C_1921a0::FUN_001921a0(int x) {
    m = x;
    return true;
}

namespace fn_fa51549e {

// 0x001921b0 FUN_001921b0 (4 B): matches/0x001921b0.cpp
// sym: ?Get@Obj_1921b0@fn_fa51549e@@QAEPAUSub_1921b0@2@XZ
Sub_1921b0* Obj_1921b0::Get() {
    return (Sub_1921b0*)((char*)this + 0x18);
}


// 0x001921e0 FUN_001921e0 (26 B): matches/0x001921e0.cpp
// sym: ?Set@Obj_1921e0@fn_fa51549e@@QAE_NPAUSrc_1921e0@2@@Z
bool Obj_1921e0::Set(Src_1921e0* p) {
    m20 = p->a;
    m24 = p->b;
    m28 = p->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00192210 FUN_00192210 (12 B): matches/0x00192210.cpp
// sym: ?FUN_00192210@Obj_192210@owners@@QAE_NH@Z
bool owners::Obj_192210::FUN_00192210(int value) {
    m2c = value;
    return true;
}


// 0x00192230 FUN_00192230 (12 B): matches/0x00192230.cpp
// sym: ?FUN_00192230@Obj_192230@owners@@QAE_NH@Z
bool owners::Obj_192230::FUN_00192230(int v) {
    m30 = v;
    return true;
}


// 0x00192240 FUN_00192240 (4 B): matches/0x00192240.cpp
// sym: ?FUN_00192240@X_192240@owners@@QAEPAXXZ
void* owners::X_192240::FUN_00192240() {
    return (char*)this + 0x38;
}

namespace fn_fa51549e {

// 0x00192270 FUN_00192270 (26 B): matches/0x00192270.cpp
// sym: ?Set@Obj_192270@fn_fa51549e@@QAE_NPAUVec3_192270@2@@Z
bool Obj_192270::Set(Vec3_192270* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_fa51549e

// 0x001922b0 FUN_001922b0 (26 B): matches/0x001922b0.cpp
// sym: ?FUN_001922b0@Obj_1922b0@owners@@QAEEPAH@Z
unsigned char owners::Obj_1922b0::FUN_001922b0(int* src) {
    a = src[0];
    b = src[1];
    c = src[2];
    return 1;
}


// 0x001922e0 FUN_001922e0 (18 B): matches/0x001922e0.cpp
// sym: ?FUN_001922e0@Target_1922e0@owners@@QAE_NM@Z
bool owners::Target_1922e0::FUN_001922e0(float degrees) {
    value = degrees * 0.017453292519943295f;
    return true;
}


// 0x00192310 FUN_00192310 (12 B): matches/0x00192310.cpp
// sym: ?FUN_00192310@X_192310@owners@@QAE_NH@Z
bool owners::X_192310::FUN_00192310(int v) {
    value = v;
    return true;
}


// 0x00192330 FUN_00192330 (12 B): matches/0x00192330.cpp
// sym: ?FUN_00192330@Obj_192330@owners@@QAEDH@Z
char owners::Obj_192330::FUN_00192330(int v) {
    m = v;
    return 1;
}


// 0x00192350 FUN_00192350 (12 B): matches/0x00192350.cpp
// sym: ?FUN_00192350@Obj_192350@owners@@QAE_NH@Z
bool owners::Obj_192350::FUN_00192350(int x) {
    m = x;
    return true;
}


// 0x00192370 FUN_00192370 (18 B): matches/0x00192370.cpp
// sym: ?FUN_00192370@Obj_192370@owners@@QAE_NM@Z
bool owners::Obj_192370::FUN_00192370(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}


// 0x001923a0 FUN_001923a0 (12 B): matches/0x001923a0.cpp
// sym: ?FUN_001923a0@X_1923a0@owners@@QAEDH@Z
char owners::X_1923a0::FUN_001923a0(int a) {
    m = a;
    return 1;
}


// 0x001923c0 FUN_001923c0 (18 B): matches/0x001923c0.cpp
// sym: ?FUN_001923c0@X_1923c0@owners@@QAEDM@Z
char owners::X_1923c0::FUN_001923c0(float x) {
    Value = x * __real_3c8efa35;
    return 1;
}


// 0x001923f0 FUN_001923f0 (12 B): matches/0x001923f0.cpp
// sym: ?FUN_001923f0@Obj_1923f0@owners@@QAEDD@Z
char owners::Obj_1923f0::FUN_001923f0(char value) {
    m74 = value;
    return 1;
}


// 0x00192400 FUN_00192400 (12 B): matches/0x00192400.cpp
// sym: ?FUN_00192400@Obj_192400@owners@@QAEDD@Z
char owners::Obj_192400::FUN_00192400(char x) {
    m = x;
    return 1;
}


// 0x00192410 FUN_00192410 (12 B): matches/0x00192410.cpp
// sym: ?FUN_00192410@Obj_192410@owners@@QAEDD@Z
char owners::Obj_192410::FUN_00192410(char value) {
    mVal = value;
    return 1;
}


// 0x00192430 FUN_00192430 (12 B): matches/0x00192430.cpp
// sym: ?FUN_00192430@X_192430@owners@@QAE_NPAX@Z
bool owners::X_192430::FUN_00192430(void* p) {
    m78 = p;
    return true;
}


// 0x00192450 FUN_00192450 (12 B): matches/0x00192450.cpp
// sym: ?FUN_00192450@Obj_192450@owners@@QAEDH@Z
char owners::Obj_192450::FUN_00192450(int arg) {
    value = arg;
    return 1;
}


// 0x00192470 FUN_00192470 (15 B): matches/0x00192470.cpp
// sym: ?FUN_00192470@X_192470@owners@@QAEDH@Z
char owners::X_192470::FUN_00192470(int a) {
    *(int*)((char*)this + 0x80) = a;
    return 1;
}


// 0x00192480 FUN_00192480 (7 B): matches/0x00192480.cpp
// sym: ?FUN_00192480@Obj_192480@owners@@QAEPADXZ
char* owners::Obj_192480::FUN_00192480() {
    return (char*)((char*)this + 0x88);
}

namespace fn_fa51549e {

// 0x001924c0 FUN_001924c0 (35 B): matches/0x001924c0.cpp
// sym: ?Set@Obj@fn_fa51549e@@QAEDPAUVec3@2@@Z
char Obj::Set(Vec3* p) {
    v[0] = p->x;
    v[1] = p->y;
    v[2] = p->z;
    return 1;
}


// 0x001924f0 FUN_001924f0 (7 B): matches/0x001924f0.cpp
// sym: ?Get@Obj_1924f0@fn_fa51549e@@QAEPAUInner_1924f0@2@XZ
Inner_1924f0* Obj_1924f0::Get() {
    return (Inner_1924f0*)((char*)this + 0x9c);
}

} // namespace fn_fa51549e

// 0x00192500 FUN_00192500 (7 B): matches/0x00192500.cpp
// sym: ?FUN_00192500@Obj_192500@owners@@QAEPAHXZ
int* owners::Obj_192500::FUN_00192500() {
    return &value;
}


// 0x00192520 FUN_00192520 (15 B): matches/0x00192520.cpp
// sym: ?FUN_00192520@Obj_192520@owners@@QAEDH@Z
char owners::Obj_192520::FUN_00192520(int val) {
    mVal = val;
    return 1;
}


// 0x00192540 FUN_00192540 (15 B): matches/0x00192540.cpp
// sym: ?FUN_00192540@A_192540@owners@@QAE_NH@Z
bool owners::A_192540::FUN_00192540(int v) {
    m = v;
    return true;
}


// 0x00192560 FUN_00192560 (15 B): matches/0x00192560.cpp
// sym: ?FUN_00192560@C_192560@owners@@QAE_NH@Z
bool owners::C_192560::FUN_00192560(int value) {
    mField = value;
    return true;
}


// 0x00192570 FUN_00192570 (12 B): matches/0x00192570.cpp
// sym: ?FUN_00192570@Obj_192570@owners@@QAE_NH@Z
bool owners::Obj_192570::FUN_00192570(int v) {
    mVal = v;
    return true;
}


// 0x00192590 FUN_00192590 (12 B): matches/0x00192590.cpp
// sym: ?FUN_00192590@C_192590@owners@@QAE_NH@Z
bool owners::C_192590::FUN_00192590(int x) {
    m = x;
    return true;
}

namespace fn_fa51549e {

// 0x001925c0 FUN_001925c0 (26 B): matches/0x001925c0.cpp
// sym: ?Set@Obj_1925c0@fn_fa51549e@@QAEDPAUSrc_1925c0@2@@Z
char Obj_1925c0::Set(Src_1925c0* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return 1;
}


// 0x001925f0 FUN_001925f0 (12 B): matches/0x001925f0.cpp
// sym: ?Set@X_1925f0@fn_fa51549e@@QAEDH@Z
char X_1925f0::Set(int a) {
    m20 = a;
    return 1;
}

} // namespace fn_fa51549e

// 0x00192610 FUN_00192610 (12 B): matches/0x00192610.cpp
// sym: ?FUN_00192610@Obj_192610@owners@@QAE_NH@Z
bool owners::Obj_192610::FUN_00192610(int value) {
    mValue = value;
    return true;
}


// 0x00192630 FUN_00192630 (12 B): matches/0x00192630.cpp
// sym: ?FUN_00192630@Obj_192630@owners@@QAEDH@Z
char owners::Obj_192630::FUN_00192630(int v) {
    value = v;
    return 1;
}


// 0x00192650 FUN_00192650 (12 B): matches/0x00192650.cpp
// sym: ?FUN_00192650@Obj_192650@owners@@QAEDH@Z
char owners::Obj_192650::FUN_00192650(int x) {
    value = x;
    return 1;
}


// 0x00192670 FUN_00192670 (18 B): matches/0x00192670.cpp
// sym: ?FUN_00192670@Obj_192670@owners@@QAEDM@Z
char owners::Obj_192670::FUN_00192670(float v) {
    value = v * 0.017453292f;
    return 1;
}


// 0x001926a0 FUN_001926a0 (18 B): matches/0x001926a0.cpp
// sym: ?FUN_001926a0@Obj_1926a0@owners@@QAEDM@Z
char owners::Obj_1926a0::FUN_001926a0(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x001926d0 FUN_001926d0 (18 B): matches/0x001926d0.cpp
// sym: ?FUN_001926d0@Obj_1926d0@owners@@QAEDM@Z
char owners::Obj_1926d0::FUN_001926d0(float degrees) {
    angle = degrees * 0.017453292f;
    return 1;
}


// 0x00192700 FUN_00192700 (18 B): matches/0x00192700.cpp
// sym: ?FUN_00192700@O_192700@owners@@QAEDM@Z
char owners::O_192700::FUN_00192700(float x) {
    *(float*)((char*)this + 0x3c) = x * 0.017453292f;
    return 1;
}


// 0x00192730 FUN_00192730 (18 B): matches/0x00192730.cpp
// sym: ?FUN_00192730@Obj_192730@owners@@QAE_NM@Z
bool owners::Obj_192730::FUN_00192730(float angle) {
    mAngle = angle * 0.0174532925f;
    return true;
}


// 0x00192760 FUN_00192760 (12 B): matches/0x00192760.cpp
// sym: ?FUN_00192760@Target_192760@owners@@QAE_NH@Z
bool owners::Target_192760::FUN_00192760(int value) {
    m44 = value;
    return true;
}

namespace fn_fa51549e {

// 0x00192770 FUN_00192770 (12 B): matches/0x00192770.cpp
// sym: ?SetTimeBegin_00192770@Obj_192770@fn_fa51549e@@QAE_NH@Z
bool Obj_192770::SetTimeBegin_00192770(int value) {
    mValue = value;
    return true;
}


// 0x00192780 FUN_00192780 (12 B): matches/0x00192780.cpp
// sym: ?SetTimeEnd_00192780@Obj_192780@fn_fa51549e@@QAE_NH@Z
bool Obj_192780::SetTimeEnd_00192780(int value) {
    m10 = value;
    return true;
}


// 0x001927a0 FUN_001927a0 (18 B): matches/0x001927a0.cpp
// sym: ?SetArc_001927a0@Obj_1927a0@fn_fa51549e@@QAEDM@Z
char Obj_1927a0::SetArc_001927a0(float f) {
    mAngle = f * gRad;
    return 1;
}


// 0x001927c0 FUN_001927c0 (4 B): matches/0x001927c0.cpp
// sym: ?GetGiverBranch_001927c0@Obj_1927c0@fn_fa51549e@@QAEPADXZ
char* Obj_1927c0::GetGiverBranch_001927c0() {
    return m + 0x18;
}


// 0x001927d0 FUN_001927d0 (12 B): matches/0x001927d0.cpp
// sym: ?SetTimeBegin_001927d0@Obj@fn_fa51549e@@QAEDH@Z
char Obj::SetTimeBegin_001927d0(int v) {
    value = v;
    return 1;
}


// 0x001927e0 FUN_001927e0 (12 B): matches/0x001927e0.cpp
// sym: ?SetTimeEnd_001927e0@X_1927e0@fn_fa51549e@@QAE_NH@Z
bool X_1927e0::SetTimeEnd_001927e0(int v) {
    value = v;
    return true;
}


// 0x00192800 FUN_00192800 (12 B): matches/0x00192800.cpp
// sym: ?SetDecay_00192800@Obj_192800@fn_fa51549e@@QAEDH@Z
char Obj_192800::SetDecay_00192800(int x) {
    m14 = x;
    return 1;
}


// 0x00192820 FUN_00192820 (12 B): matches/0x00192820.cpp
// sym: ?SetDecayScaler_00192820@Obj_192820@fn_fa51549e@@QAEDH@Z
char Obj_192820::SetDecayScaler_00192820(int x) {
    value = x;
    return 1;
}

} // namespace fn_fa51549e

// 0x00192830 FUN_00192830 (12 B): matches/0x00192830.cpp
// sym: ?FUN_00192830@Obj_192830@owners@@QAE_NH@Z
bool owners::Obj_192830::FUN_00192830(int x) {
    m10 = x;
    return true;
}


// 0x00192840 FUN_00192840 (12 B): matches/0x00192840.cpp
// sym: ?FUN_00192840@Obj_192840@owners@@QAE_NH@Z
bool owners::Obj_192840::FUN_00192840(int v) {
    value = v;
    return true;
}


// 0x00192850 FUN_00192850 (4 B): matches/0x00192850.cpp
// sym: ?FUN_00192850@Obj_192850@owners@@QAEPAU12@XZ
owners::Obj_192850* owners::Obj_192850::FUN_00192850() {
    return (owners::Obj_192850*)((char*)this + 0x18);
}

namespace fn_fa51549e {

// 0x00192860 FUN_00192860 (26 B): matches/0x00192860.cpp
// sym: ?Set@Obj@fn_fa51549e@@QAEDABUVec@2@@Z
char Obj::Set(const Vec& p) {
    x = p.x;
    y = p.y;
    z = p.z;
    return 1;
}

} // namespace fn_fa51549e

// 0x00192890 FUN_00192890 (12 B): matches/0x00192890.cpp
// sym: ?FUN_00192890@Obj_192890@owners@@QAE_NH@Z
bool owners::Obj_192890::FUN_00192890(int v) {
    value = v;
    return true;
}


// 0x001928a0 FUN_001928a0 (4 B): matches/0x001928a0.cpp
// sym: ?FUN_001928a0@Obj_1928a0@owners@@QAEPAXXZ
void* owners::Obj_1928a0::FUN_001928a0() {
    return (void*)((char*)this + 0x30);
}


// 0x001928b0 FUN_001928b0 (30 B): matches/0x001928b0.cpp [wrapped: conflict: Obj]
// sym: ?get@Obj@fn_001928b0@@QAEPAUV@2@PAU32@@Z
namespace fn_001928b0 {
struct V {
    int a, b, c;
};
class Obj {
    char pad[0x38];
    V v;

  public:
    V* get(V* out);
};
V* Obj::get(V* out) {
    *out = v;
    return out;
}
} // namespace fn_001928b0

namespace fn_fa51549e {

// 0x001928d0 FUN_001928d0 (26 B): matches/0x001928d0.cpp
// sym: ?Set@Obj_1928d0@fn_fa51549e@@QAEDPAUSrc_1928d0@2@@Z
char Obj_1928d0::Set(Src_1928d0* p) {
    m38 = p->a;
    m3c = p->b;
    m40 = p->c;
    return 1;
}


// 0x00192910 FUN_00192910 (26 B): matches/0x00192910.cpp
// sym: ?Fn@T_192910@fn_fa51549e@@QAEDPAUS_192910@2@@Z
char T_192910::Fn(S_192910* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return 1;
}

} // namespace fn_fa51549e

// 0x00192940 FUN_00192940 (12 B): matches/0x00192940.cpp
// sym: ?FUN_00192940@Thing_192940@owners@@QAEDH@Z
char owners::Thing_192940::FUN_00192940(int v) {
    value = v;
    return 1;
}


// 0x00192960 FUN_00192960 (18 B): matches/0x00192960.cpp
// sym: ?FUN_00192960@Obj_192960@owners@@QAEDM@Z
char owners::Obj_192960::FUN_00192960(float deg) {
    rads = deg * 0.017453293f;
    return 1;
}


// 0x00192990 FUN_00192990 (12 B): matches/0x00192990.cpp
// sym: ?FUN_00192990@Obj_192990@owners@@QAE_NH@Z
bool owners::Obj_192990::FUN_00192990(int v) {
    m58 = v;
    return true;
}


// 0x001929b0 FUN_001929b0 (18 B): matches/0x001929b0.cpp
// sym: ?FUN_001929b0@Obj_1929b0@owners@@QAEDM@Z
char owners::Obj_1929b0::FUN_001929b0(float v) {
    value = v * k_1929b0;
    int r = 1;
    return (char)r;
}


// 0x001929e0 FUN_001929e0 (12 B): matches/0x001929e0.cpp
// sym: ?FUN_001929e0@X_1929e0@owners@@QAE_NE@Z
bool owners::X_1929e0::FUN_001929e0(unsigned char v) {
    m = v;
    return true;
}


// 0x00192a00 FUN_00192a00 (12 B): matches/0x00192a00.cpp
// sym: ?FUN_00192a00@Obj_192a00@owners@@QAE_NH@Z
bool owners::Obj_192a00::FUN_00192a00(int x) {
    m64 = x;
    return true;
}


// 0x00192a20 FUN_00192a20 (12 B): matches/0x00192a20.cpp
// sym: ?FUN_00192a20@Obj_192a20@owners@@QAE_NH@Z
bool owners::Obj_192a20::FUN_00192a20(int v) {
    m68 = v;
    return true;
}


// 0x00192a30 FUN_00192a30 (4 B): matches/0x00192a30.cpp
// sym: ?FUN_00192a30@Thing_192a30@owners@@QAEPAXXZ
void* owners::Thing_192a30::FUN_00192a30() {
    return &field;
}

namespace fn_fa51549e {

// 0x00192a60 FUN_00192a60 (29 B): matches/0x00192a60.cpp
// sym: ?Set@Owner_192a60@fn_fa51549e@@QAE_NPAUData_192a60@2@@Z
bool Owner_192a60::Set(Data_192a60* d) {
    m78 = d->a;
    m7c = d->b;
    m80 = d->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00192a80 FUN_00192a80 (7 B): matches/0x00192a80.cpp
// sym: ?FUN_00192a80@Obj_192a80@owners@@QAEPADXZ
char* owners::Obj_192a80::FUN_00192a80() {
    return (char*)this + 0x84;
}


// 0x00192aa0 FUN_00192aa0 (15 B): matches/0x00192aa0.cpp
// sym: ?FUN_00192aa0@C_192aa0@owners@@QAEDH@Z
char owners::C_192aa0::FUN_00192aa0(int x) {
    m90 = x;
    return 1;
}


// 0x00192ac0 FUN_00192ac0 (15 B): matches/0x00192ac0.cpp
// sym: ?FUN_00192ac0@Obj_192ac0@owners@@QAE_NH@Z
bool owners::Obj_192ac0::FUN_00192ac0(int x) {
    value = x;
    return true;
}


// 0x00192ae0 FUN_00192ae0 (15 B): matches/0x00192ae0.cpp
// sym: ?FUN_00192ae0@Obj_192ae0@owners@@QAE_NH@Z
bool owners::Obj_192ae0::FUN_00192ae0(int x) {
    m98 = x;
    return true;
}


// 0x00192b00 FUN_00192b00 (15 B): matches/0x00192b00.cpp
// sym: ?FUN_00192b00@Obj_192b00@owners@@QAEEE@Z
unsigned char owners::Obj_192b00::FUN_00192b00(unsigned char x) {
    value = x;
    return 1;
}


// 0x00192b20 FUN_00192b20 (15 B): matches/0x00192b20.cpp
// sym: ?FUN_00192b20@X_192b20@owners@@QAEDH@Z
char owners::X_192b20::FUN_00192b20(int v) {
    *(int*)((char*)this + 0xa0) = v;
    return 1;
}


// 0x00192b40 FUN_00192b40 (15 B): matches/0x00192b40.cpp
// sym: ?FUN_00192b40@Obj_192b40@owners@@QAEDH@Z
char owners::Obj_192b40::FUN_00192b40(int v) {
    mValue = v;
    return 1;
}


// 0x00192b60 FUN_00192b60 (15 B): matches/0x00192b60.cpp
// sym: ?FUN_00192b60@C_192b60@owners@@QAEDH@Z
char owners::C_192b60::FUN_00192b60(int v) {
    mValue = v;
    return 1;
}


// 0x00192b80 FUN_00192b80 (15 B): matches/0x00192b80.cpp
// sym: ?FUN_00192b80@O_192b80@owners@@QAEDD@Z
char owners::O_192b80::FUN_00192b80(char b) {
    mB1 = b;
    return 1;
}

namespace fn_fa51549e {

// 0x00192b90 FUN_00192b90 (7 B): matches/0x00192b90.cpp
// sym: ?Get@Target_192b90@fn_fa51549e@@QAEPAUSub_192b90@2@XZ
Sub_192b90* Target_192b90::Get() {
    return &sub;
}

} // namespace fn_fa51549e

// 0x00192ba0 FUN_00192ba0 (7 B): matches/0x00192ba0.cpp
// sym: ?FUN_00192ba0@Obj_192ba0@owners@@QAEPAXXZ
void* owners::Obj_192ba0::FUN_00192ba0() {
    return (char*)this + 0xc0;
}


// 0x00192bb0 FUN_00192bb0 (33 B): matches/0x00192bb0.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_00192bb0@@QAEPAUTriple@2@PAU32@@Z
namespace fn_00192bb0 {
struct Triple {
    int a, b, c;
};
class Obj {
    char pad[0xc8];
    Triple value;

  public:
    Triple* Get(Triple* out);
};
Triple* Obj::Get(Triple* out) {
    *out = value;
    return out;
}
} // namespace fn_00192bb0

namespace fn_fa51549e {

// 0x00192be0 FUN_00192be0 (35 B): matches/0x00192be0.cpp
// sym: ?Set@Obj@fn_fa51549e@@QAE_NPBUVec3@2@@Z
bool Obj::Set(const Vec3* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return true;
}

} // namespace fn_fa51549e

// 0x00192c40 FUN_00192c40 (35 B): matches/0x00192c40.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00192c40@@QAE_NPAUIn@2@@Z
namespace fn_00192c40 {
struct In {
    int a;
    int b;
    int c;
};
class Obj {
  public:
    char pad[0xd4];
    int x;
    int y;
    int z;
    bool Set(In* p);
};
bool Obj::Set(In* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
} // namespace fn_00192c40

namespace fn_fa51549e {

// 0x00192c70 FUN_00192c70 (33 B): matches/0x00192c70.cpp
// sym: ?Get@C@fn_fa51549e@@QAE?AUV@2@XZ
V C::Get() {
    return v;
}

} // namespace fn_fa51549e

// 0x00192ca0 FUN_00192ca0 (35 B): matches/0x00192ca0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00192ca0@@QAE_NPBUVec3@2@@Z
namespace fn_00192ca0 {
struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0xe0];
    int x, y, z;
    bool Set(const Vec3* v);
};
bool Obj::Set(const Vec3* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    return true;
}
} // namespace fn_00192ca0


// 0x00192ce0 FUN_00192ce0 (15 B): matches/0x00192ce0.cpp
// sym: ?FUN_00192ce0@Obj_192ce0@owners@@QAE_NH@Z
bool owners::Obj_192ce0::FUN_00192ce0(int v) {
    value = v;
    return true;
}


// 0x00192d00 FUN_00192d00 (15 B): matches/0x00192d00.cpp
// sym: ?FUN_00192d00@X_192d00@owners@@QAEDD@Z
char owners::X_192d00::FUN_00192d00(char v) {
    m[0xf0] = v;
    return 1;
}


// 0x00192d20 FUN_00192d20 (21 B): matches/0x00192d20.cpp
// sym: ?FUN_00192d20@Obj_192d20@owners@@QAE_NM@Z
bool owners::Obj_192d20::FUN_00192d20(float angle) {
    value = angle * 0.017453292519943f;
    return true;
}


// 0x00192d50 FUN_00192d50 (15 B): matches/0x00192d50.cpp
// sym: ?FUN_00192d50@X_192d50@owners@@QAEDH@Z
char owners::X_192d50::FUN_00192d50(int v) {
    m = v;
    return 1;
}


// 0x00192d70 FUN_00192d70 (15 B): matches/0x00192d70.cpp
// sym: ?FUN_00192d70@Obj_192d70@owners@@QAEEE@Z
unsigned char owners::Obj_192d70::FUN_00192d70(unsigned char v) {
    m1 = v;
    return 1;
}


// 0x00192d90 FUN_00192d90 (15 B): matches/0x00192d90.cpp
// sym: ?FUN_00192d90@Obj_192d90@owners@@QAEEE@Z
unsigned char owners::Obj_192d90::FUN_00192d90(unsigned char v) {
    value = v;
    return 1;
}


// 0x00192db0 FUN_00192db0 (15 B): matches/0x00192db0.cpp
// sym: ?FUN_00192db0@X_192db0@owners@@QAEDD@Z
char owners::X_192db0::FUN_00192db0(char b) {
    m0fe = b;
    return 1;
}


// 0x00192df0 FUN_00192df0 (35 B): matches/0x00192df0.cpp
// sym: ?FUN_00192df0@C_192df0@owners@@QAEDPBX@Z
char owners::C_192df0::FUN_00192df0(const void* p) {
    const unsigned int* q = (const unsigned int*)p;
    *(unsigned int*)m100 = q[0];
    *(unsigned int*)m104 = q[1];
    *(unsigned int*)m108 = q[2];
    return 1;
}

namespace fn_fa51549e {

// 0x00192e50 FUN_00192e50 (35 B): matches/0x00192e50.cpp
// sym: ?Set@Obj@fn_fa51549e@@QAE_NPAUSrc@2@@Z
bool Obj::Set(Src* s) {
    m10c = s->a;
    m110 = s->b;
    m114 = s->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00192e90 FUN_00192e90 (15 B): matches/0x00192e90.cpp
// sym: ?FUN_00192e90@Obj_192e90@owners@@QAE_NH@Z
bool owners::Obj_192e90::FUN_00192e90(int value) {
    mValue = value;
    return true;
}


// 0x00192ea0 FUN_00192ea0 (33 B): matches/0x00192ea0.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_00192ea0@@QAEPAUV@2@PAU32@@Z
namespace fn_00192ea0 {
struct V {
    int x, y, z;
};
class Obj {
    char pad[0x11c];
    V v;

  public:
    V* Get(V* out);
};
V* Obj::Get(V* out) {
    *out = v;
    return out;
}
} // namespace fn_00192ea0

namespace fn_fa51549e {

// 0x00192ed0 FUN_00192ed0 (35 B): matches/0x00192ed0.cpp
// sym: ?Copy@Tgt@fn_fa51549e@@QAE_NPAUSrc@2@@Z
bool Tgt::Copy(Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00192f10 FUN_00192f10 (15 B): matches/0x00192f10.cpp
// sym: ?FUN_00192f10@Obj_192f10@owners@@QAEDH@Z
char owners::Obj_192f10::FUN_00192f10(int v) {
    mValue = v;
    return 1;
}


// 0x00192f30 FUN_00192f30 (15 B): matches/0x00192f30.cpp
// sym: ?FUN_00192f30@Obj_192f30@owners@@QAEDD@Z
char owners::Obj_192f30::FUN_00192f30(char c) {
    m[0x12c] = c;
    return 1;
}


// 0x00192f50 FUN_00192f50 (15 B): matches/0x00192f50.cpp
// sym: ?FUN_00192f50@Target_192f50@owners@@QAE_NH@Z
bool owners::Target_192f50::FUN_00192f50(int value) {
    field = value;
    return true;
}


// 0x00192f70 FUN_00192f70 (15 B): matches/0x00192f70.cpp
// sym: ?FUN_00192f70@Obj_192f70@owners@@QAE_NH@Z
bool owners::Obj_192f70::FUN_00192f70(int x) {
    m134 = x;
    return true;
}


// 0x00192f80 FUN_00192f80 (12 B): matches/0x00192f80.cpp
// sym: ?FUN_00192f80@Obj_192f80@owners@@QAE_NH@Z
bool owners::Obj_192f80::FUN_00192f80(int value) {
    mValue = value;
    return true;
}


// 0x00192f90 FUN_00192f90 (4 B): matches/0x00192f90.cpp
// sym: ?FUN_00192f90@Obj_192f90@owners@@QAEPAHXZ
int* owners::Obj_192f90::FUN_00192f90() {
    return (int*)((char*)this + 16);
}


// 0x00192fa0 FUN_00192fa0 (4 B): matches/0x00192fa0.cpp
// sym: ?FUN_00192fa0@Obj_192fa0@owners@@QAEPADXZ
char* owners::Obj_192fa0::FUN_00192fa0() {
    return (char*)((hulk_intptr)this + 0x18);
}


// 0x00192fb0 FUN_00192fb0 (4 B): matches/0x00192fb0.cpp
// sym: ?FUN_00192fb0@Obj_192fb0@owners@@QAEPADXZ
char* owners::Obj_192fb0::FUN_00192fb0() {
    return (char*)this + 0x20;
}

namespace fn_fa51549e {

// 0x00192fe0 FUN_00192fe0 (26 B): matches/0x00192fe0.cpp
// sym: ?Assign@Owner_192fe0@fn_fa51549e@@QAE_NPAUTriple@2@@Z
bool Owner_192fe0::Assign(Triple* p) {
    m28 = p->a;
    m2c = p->b;
    m30 = p->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00193010 FUN_00193010 (12 B): matches/0x00193010.cpp
// sym: ?FUN_00193010@Obj_193010@owners@@QAEDH@Z
char owners::Obj_193010::FUN_00193010(int v) {
    m34 = v;
    return 1;
}


// 0x00193020 FUN_00193020 (4 B): matches/0x00193020.cpp
// sym: ?FUN_00193020@Obj_193020@owners@@QAEPAXXZ
void* owners::Obj_193020::FUN_00193020() {
    return (char*)this + 0x38;
}

namespace fn_fa51549e {

// 0x00193050 FUN_00193050 (26 B): matches/0x00193050.cpp
// sym: ?Set@Obj_193050@fn_fa51549e@@QAE_NPBUVec3_193050@2@@Z
bool Obj_193050::Set(const Vec3_193050* v) {
    m40 = v->x;
    m44 = v->y;
    m48 = v->z;
    return true;
}


// 0x00193090 FUN_00193090 (26 B): matches/0x00193090.cpp
// sym: ?Set@Obj_193090@fn_fa51549e@@QAE_NPAUSrc_193090@2@@Z
bool Obj_193090::Set(Src_193090* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}

} // namespace fn_fa51549e

// 0x001930c0 FUN_001930c0 (12 B): matches/0x001930c0.cpp
// sym: ?FUN_001930c0@Obj_1930c0@owners@@QAEEE@Z
unsigned char owners::Obj_1930c0::FUN_001930c0(unsigned char x) {
    field = x;
    return 1;
}


// 0x001930e0 FUN_001930e0 (12 B): matches/0x001930e0.cpp
// sym: ?FUN_001930e0@Obj_1930e0@owners@@QAE_NH@Z
bool owners::Obj_1930e0::FUN_001930e0(int v) {
    value = v;
    return true;
}


// 0x00193100 FUN_00193100 (12 B): matches/0x00193100.cpp
// sym: ?FUN_00193100@Obj_193100@owners@@QAEEH@Z
unsigned char owners::Obj_193100::FUN_00193100(int v) {
    m60 = v;
    return 1;
}


// 0x00193120 FUN_00193120 (12 B): matches/0x00193120.cpp
// sym: ?FUN_00193120@Obj_193120@owners@@QAEDH@Z
char owners::Obj_193120::FUN_00193120(int x) {
    m64 = x;
    return 1;
}


// 0x00193140 FUN_00193140 (18 B): matches/0x00193140.cpp
// sym: ?FUN_00193140@Obj_193140@owners@@QAEDM@Z
char owners::Obj_193140::FUN_00193140(float v) {
    angle = v * 0.017453292f;
    return 1;
}


// 0x00193170 FUN_00193170 (12 B): matches/0x00193170.cpp
// sym: ?FUN_00193170@Obj_193170@owners@@QAE_NH@Z
bool owners::Obj_193170::FUN_00193170(int v) {
    m6c = v;
    return true;
}


// 0x00193190 FUN_00193190 (18 B): matches/0x00193190.cpp
// sym: ?FUN_00193190@Thing_193190@owners@@QAEDM@Z
char owners::Thing_193190::FUN_00193190(float x) {
    value = x * 0.017453292519943295f;
    return 1;
}


// 0x001931c0 FUN_001931c0 (12 B): matches/0x001931c0.cpp
// sym: ?FUN_001931c0@X_1931c0@owners@@QAEDD@Z
char owners::X_1931c0::FUN_001931c0(char c) {
    f = c;
    return 1;
}


// 0x001931e0 FUN_001931e0 (12 B): matches/0x001931e0.cpp
// sym: ?FUN_001931e0@Sub_1931e0@owners@@QAEDD@Z
char owners::Sub_1931e0::FUN_001931e0(char v) {
    m75 = v;
    return 1;
}


// 0x00193200 FUN_00193200 (12 B): matches/0x00193200.cpp
// sym: ?FUN_00193200@Obj_193200@owners@@QAE_ND@Z
bool owners::Obj_193200::FUN_00193200(char b) {
    mField = b;
    return true;
}


// 0x00193220 FUN_00193220 (12 B): matches/0x00193220.cpp
// sym: ?FUN_00193220@Obj_193220@owners@@QAEEE@Z
unsigned char owners::Obj_193220::FUN_00193220(unsigned char v) {
    flag = v;
    return 1;
}


// 0x00193240 FUN_00193240 (12 B): matches/0x00193240.cpp
// sym: ?FUN_00193240@X_193240@owners@@QAEDH@Z
char owners::X_193240::FUN_00193240(int v) {
    *(int*)&m78 = v;
    return 1;
}


// 0x00193260 FUN_00193260 (12 B): matches/0x00193260.cpp
// sym: ?FUN_00193260@Obj_193260@owners@@QAE_NH@Z
bool owners::Obj_193260::FUN_00193260(int x) {
    m7c = x;
    return true;
}


// 0x00193280 FUN_00193280 (21 B): matches/0x00193280.cpp
// sym: ?FUN_00193280@Obj_193280@owners@@QAEDM@Z
char owners::Obj_193280::FUN_00193280(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}

namespace fn_fa51549e {

// 0x001932b0 FUN_001932b0 (21 B): matches/0x001932b0.cpp
// sym: ?SetRadians@Base_1932b0@fn_fa51549e@@QAE_NM@Z
bool Base_1932b0::SetRadians(float r) {
    float k = 0.017453292f;
    float t = r * k;
    mAngle = t;
    return true;
}

} // namespace fn_fa51549e

// 0x001932e0 FUN_001932e0 (15 B): matches/0x001932e0.cpp
// sym: ?FUN_001932e0@Obj_1932e0@owners@@QAE_NH@Z
bool owners::Obj_1932e0::FUN_001932e0(int v) {
    mVal = v;
    return true;
}


// 0x00193300 FUN_00193300 (15 B): matches/0x00193300.cpp
// sym: ?FUN_00193300@Obj_193300@owners@@QAE_NH@Z
bool owners::Obj_193300::FUN_00193300(int x) {
    mValue = x;
    return true;
}


// 0x00193320 FUN_00193320 (15 B): matches/0x00193320.cpp
// sym: ?FUN_00193320@Obj_193320@owners@@QAE_NH@Z
bool owners::Obj_193320::FUN_00193320(int x) {
    value = x;
    return true;
}


// 0x00193340 FUN_00193340 (15 B): matches/0x00193340.cpp
// sym: ?FUN_00193340@X_193340@owners@@QAEDD@Z
char owners::X_193340::FUN_00193340(char value) {
    field[0x94] = value;
    return 1;
}


// 0x00193360 FUN_00193360 (15 B): matches/0x00193360.cpp
// sym: ?FUN_00193360@T_193360@owners@@QAE_NE@Z
bool owners::T_193360::FUN_00193360(unsigned char x) {
    value = x;
    return true;
}

namespace fn_fa51549e {

// 0x00193370 FUN_00193370 (7 B): matches/0x00193370.cpp
// sym: ?GetValue@X_193370@fn_fa51549e@@QAEEXZ
unsigned char X_193370::GetValue() {
    return pad[0x96];
}

} // namespace fn_fa51549e

// 0x00193380 FUN_00193380 (15 B): matches/0x00193380.cpp
// sym: ?FUN_00193380@Obj_193380@owners@@QAEDD@Z
char owners::Obj_193380::FUN_00193380(char x) {
    m96 = x;
    return 1;
}


// 0x001933a0 FUN_001933a0 (15 B): matches/0x001933a0.cpp
// sym: ?FUN_001933a0@Obj_1933a0@owners@@QAE_NH@Z
bool owners::Obj_1933a0::FUN_001933a0(int x) {
    value = x;
    return true;
}


// 0x001933c0 FUN_001933c0 (21 B): matches/0x001933c0.cpp
// sym: ?FUN_001933c0@Obj_1933c0@owners@@QAEEM@Z
unsigned char owners::Obj_1933c0::FUN_001933c0(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}


// 0x001933f0 FUN_001933f0 (15 B): matches/0x001933f0.cpp
// sym: ?FUN_001933f0@X_1933f0@owners@@QAEDH@Z
char owners::X_1933f0::FUN_001933f0(int value) {
    mValue = value;
    return 1;
}


// 0x00193410 FUN_00193410 (21 B): matches/0x00193410.cpp
// sym: ?FUN_00193410@Obj_193410@owners@@QAEDM@Z
char owners::Obj_193410::FUN_00193410(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}


// 0x00193430 FUN_00193430 (15 B): matches/0x00193430.cpp
// sym: ?FUN_00193430@T_193430@owners@@QAEDH@Z
char owners::T_193430::FUN_00193430(int value) {
    int v = value;
    *(int*)((char*)this + 0xa8) = v;
    return 1;
}


// 0x00193450 FUN_00193450 (21 B): matches/0x00193450.cpp
// sym: ?FUN_00193450@Obj_193450@owners@@QAE_NM@Z
bool owners::Obj_193450::FUN_00193450(float a) {
    mAngle = a * 0.0174532925f;
    return true;
}


// 0x00193480 FUN_00193480 (15 B): matches/0x00193480.cpp
// sym: ?FUN_00193480@Obj_193480@owners@@QAE_NH@Z
bool owners::Obj_193480::FUN_00193480(int v) {
    value = v;
    return true;
}


// 0x001934a0 FUN_001934a0 (15 B): matches/0x001934a0.cpp
// sym: ?FUN_001934a0@Obj_1934a0@owners@@QAEDH@Z
char owners::Obj_1934a0::FUN_001934a0(int x) {
    Value = x;
    return 1;
}


// 0x001934c0 FUN_001934c0 (15 B): matches/0x001934c0.cpp
// sym: ?FUN_001934c0@Obj_1934c0@owners@@QAEDH@Z
char owners::Obj_1934c0::FUN_001934c0(int x) {
    mB8 = x;
    return 1;
}


// 0x001934d0 FUN_001934d0 (7 B): matches/0x001934d0.cpp
// sym: ?FUN_001934d0@Obj_1934d0@owners@@QAEPAHXZ
int* owners::Obj_1934d0::FUN_001934d0() {
    return (int*)((char*)this + 0xbc);
}


// 0x001934e0 FUN_001934e0 (7 B): matches/0x001934e0.cpp
// sym: ?FUN_001934e0@X_1934e0@owners@@QAEPAXXZ
void* owners::X_1934e0::FUN_001934e0() {
    return (char*)this + 0xc8;
}


// 0x00193500 FUN_00193500 (15 B): matches/0x00193500.cpp
// sym: ?FUN_00193500@X_193500@owners@@QAE_NH@Z
bool owners::X_193500::FUN_00193500(int a) {
    mValue = a;
    return true;
}


// 0x00193520 FUN_00193520 (15 B): matches/0x00193520.cpp
// sym: ?FUN_00193520@Obj_193520@owners@@QAEDH@Z
char owners::Obj_193520::FUN_00193520(int x) {
    *(int*)(m + 0xd8) = x;
    return 1;
}


// 0x00193550 FUN_00193550 (15 B): matches/0x00193550.cpp
// sym: ?FUN_00193550@Target_193550@owners@@QAEDH@Z
char owners::Target_193550::FUN_00193550(int x) {
    value = x;
    return 1;
}


// 0x00193560 FUN_00193560 (7 B): matches/0x00193560.cpp
// sym: ?FUN_00193560@Obj_193560@owners@@QAEPADXZ
char* owners::Obj_193560::FUN_00193560() {
    return (char*)this + 0xe8;
}


// 0x001935a0 FUN_001935a0 (35 B): matches/0x001935a0.cpp
// sym: ?FUN_001935a0@Obj_1935a0@owners@@QAEDPAH@Z
char owners::Obj_1935a0::FUN_001935a0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return 1;
}


// 0x001935e0 FUN_001935e0 (15 B): matches/0x001935e0.cpp
// sym: ?FUN_001935e0@X_1935e0@owners@@QAE_NH@Z
bool owners::X_1935e0::FUN_001935e0(int a) {
    m1fc = a;
    return true;
}


// 0x001935f0 FUN_001935f0 (7 B): matches/0x001935f0.cpp
// sym: ?FUN_001935f0@T_1935f0@owners@@QAEPADXZ
char* owners::T_1935f0::FUN_001935f0() {
    return pad + 0x100;
}


// 0x00193610 FUN_00193610 (15 B): matches/0x00193610.cpp
// sym: ?FUN_00193610@Obj_193610@owners@@QAE_NH@Z
bool owners::Obj_193610::FUN_00193610(int x) {
    mValue = x;
    return true;
}


// 0x00193630 FUN_00193630 (15 B): matches/0x00193630.cpp
// sym: ?FUN_00193630@Obj_193630@owners@@QAE_NH@Z
bool owners::Obj_193630::FUN_00193630(int x) {
    value = x;
    return true;
}


// 0x00193650 FUN_00193650 (15 B): matches/0x00193650.cpp
// sym: ?FUN_00193650@C_193650@owners@@QAEDH@Z
char owners::C_193650::FUN_00193650(int x) {
    value = x;
    return 1;
}


// 0x00193660 FUN_00193660 (33 B): matches/0x00193660.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_00193660@@QAEPAUVec@2@PAU32@@Z
namespace fn_00193660 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x118];
    Vec v;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = v;
    return out;
}
} // namespace fn_00193660


// 0x00193690 FUN_00193690 (35 B): matches/0x00193690.cpp [wrapped: conflict: Obj; Obj::Set; Vec3]
// sym: ?Set@Obj@fn_00193690@@QAE_NPAUVec3@2@@Z
namespace fn_00193690 {
struct Vec3 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

class Obj {
  public:
    char pad[0x118];
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool Set(Vec3* v);
};

bool Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
} // namespace fn_00193690


// 0x001936d0 FUN_001936d0 (15 B): matches/0x001936d0.cpp
// sym: ?FUN_001936d0@Obj_1936d0@owners@@QAEDH@Z
char owners::Obj_1936d0::FUN_001936d0(int v) {
    value = v;
    return 1;
}

namespace fn_fa51549e {

// 0x001936e0 FUN_001936e0 (7 B): matches/0x001936e0.cpp
// sym: ?f@Item_1936e0@fn_fa51549e@@QAEPAXXZ
void* Item_1936e0::f() {
    return (void*)((char*)this + 0x128);
}

} // namespace fn_fa51549e

// 0x001936f0 FUN_001936f0 (33 B): matches/0x001936f0.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_001936f0@@QAEPAUVec@2@PAU32@@Z
namespace fn_001936f0 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x130];
    Vec v;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = v;
    return out;
}
} // namespace fn_001936f0

namespace fn_fa51549e {

// 0x00193720 FUN_00193720 (35 B): matches/0x00193720.cpp
// sym: ?Set@O@fn_fa51549e@@QAE_NPAUT@2@@Z
bool O::Set(T* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00193760 FUN_00193760 (15 B): matches/0x00193760.cpp
// sym: ?FUN_00193760@Obj_193760@owners@@QAE_NH@Z
bool owners::Obj_193760::FUN_00193760(int value) {
    mValue = value;
    return true;
}


// 0x00193780 FUN_00193780 (15 B): matches/0x00193780.cpp
// sym: ?FUN_00193780@C_193780@owners@@QAE_NH@Z
bool owners::C_193780::FUN_00193780(int x) {
    m = x;
    return true;
}


// 0x001937a0 FUN_001937a0 (15 B): matches/0x001937a0.cpp
// sym: ?FUN_001937a0@Obj_1937a0@owners@@QAEDH@Z
char owners::Obj_1937a0::FUN_001937a0(int x) {
    mVal = x;
    return 1;
}


// 0x001937b0 FUN_001937b0 (12 B): matches/0x001937b0.cpp
// sym: ?FUN_001937b0@Obj_1937b0@owners@@QAEDH@Z
char owners::Obj_1937b0::FUN_001937b0(int x) {
    mField = x;
    return 1;
}


// 0x001937e0 FUN_001937e0 (26 B): matches/0x001937e0.cpp [wrapped: conflict: Obj; Obj::Set]
// sym: ?Set@Obj@fn_001937e0@@QAE_NABUVec@2@@Z
namespace fn_001937e0 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[16];
    Vec v;

  public:
    bool Set(const Vec& a);
};
bool Obj::Set(const Vec& a) {
    v.x = a.x;
    v.y = a.y;
    v.z = a.z;
    return true;
}
} // namespace fn_001937e0

namespace fn_fa51549e {

// 0x00193820 FUN_00193820 (26 B): matches/0x00193820.cpp
// sym: ?Set@Obj_193820@fn_fa51549e@@QAE_NPBUSrc_193820@2@@Z
bool Obj_193820::Set(const struct Src_193820* s) {
    m1c = s->a;
    m20 = s->b;
    m24 = s->c;
    return true;
}

} // namespace fn_fa51549e

// 0x00193850 FUN_00193850 (12 B): matches/0x00193850.cpp
// sym: ?FUN_00193850@Obj_193850@owners@@QAEDH@Z
char owners::Obj_193850::FUN_00193850(int x) {
    mValue = x;
    return 1;
}


// 0x00193870 FUN_00193870 (12 B): matches/0x00193870.cpp
// sym: ?FUN_00193870@Obj_193870@owners@@QAE_NH@Z
bool owners::Obj_193870::FUN_00193870(int x) {
    value = x;
    return true;
}


// 0x00193890 FUN_00193890 (12 B): matches/0x00193890.cpp
// sym: ?FUN_00193890@Obj_193890@owners@@QAE_NH@Z
bool owners::Obj_193890::FUN_00193890(int v) {
    mField = v;
    return true;
}


// 0x001938b0 FUN_001938b0 (12 B): matches/0x001938b0.cpp
// sym: ?FUN_001938b0@C_1938b0@owners@@QAEEH@Z
unsigned char owners::C_1938b0::FUN_001938b0(int x) {
    value = x;
    return 1;
}


// 0x001938d0 FUN_001938d0 (12 B): matches/0x001938d0.cpp
// sym: ?FUN_001938d0@Obj_1938d0@owners@@QAE_NH@Z
bool owners::Obj_1938d0::FUN_001938d0(int value) {
    m38 = value;
    return true;
}


// 0x001938f0 FUN_001938f0 (12 B): matches/0x001938f0.cpp
// sym: ?FUN_001938f0@Obj_1938f0@owners@@QAEDH@Z
char owners::Obj_1938f0::FUN_001938f0(int value) {
    *((int*)((char*)this + 0x3c)) = value;
    return 1;
}


// 0x00193900 FUN_00193900 (4 B): matches/0x00193900.cpp
// sym: ?FUN_00193900@Obj_193900@owners@@QAEPADXZ
char* owners::Obj_193900::FUN_00193900() {
    return (char*)((char*)this + 0x40);
}

namespace fn_fa51549e {

// 0x00193930 FUN_00193930 (26 B): matches/0x00193930.cpp
// sym: ?Set@Obj_193930@fn_fa51549e@@QAE_NPBUVec3_193930@2@@Z
bool Obj_193930::Set(const Vec3_193930* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return true;
}

} // namespace fn_fa51549e

// 0x00193960 FUN_00193960 (12 B): matches/0x00193960.cpp
// sym: ?FUN_00193960@Obj_193960@owners@@QAE_NH@Z
bool owners::Obj_193960::FUN_00193960(int value) {
    mValue = value;
    return true;
}


// 0x00193980 FUN_00193980 (12 B): matches/0x00193980.cpp
// sym: ?FUN_00193980@Obj_193980@owners@@QAE_NH@Z
bool owners::Obj_193980::FUN_00193980(int v) {
    value = v;
    return true;
}


// 0x001939a0 FUN_001939a0 (12 B): matches/0x001939a0.cpp
// sym: ?FUN_001939a0@Obj_1939a0@owners@@QAE_NH@Z
bool owners::Obj_1939a0::FUN_001939a0(int x) {
    mVal = x;
    return true;
}


// 0x001939c0 FUN_001939c0 (12 B): matches/0x001939c0.cpp
// sym: ?FUN_001939c0@C_1939c0@owners@@QAE_NH@Z
bool owners::C_1939c0::FUN_001939c0(int v) {
    m60 = v;
    return true;
}


// 0x001939e0 FUN_001939e0 (12 B): matches/0x001939e0.cpp
// sym: ?FUN_001939e0@Thing_1939e0@owners@@QAE_NH@Z
bool owners::Thing_1939e0::FUN_001939e0(int x) {
    value = x;
    return true;
}


// 0x00193a00 FUN_00193a00 (18 B): matches/0x00193a00.cpp
// sym: ?FUN_00193a00@O_193a00@owners@@QAE_NM@Z
bool owners::O_193a00::FUN_00193a00(float angle) {
    value = angle * 0.017453292f;
    return true;
}


// 0x00193a30 FUN_00193a30 (12 B): matches/0x00193a30.cpp
// sym: ?FUN_00193a30@O_193a30@owners@@QAE_NH@Z
bool owners::O_193a30::FUN_00193a30(int x) {
    m = x;
    return true;
}


// 0x00193a50 FUN_00193a50 (12 B): matches/0x00193a50.cpp
// sym: ?FUN_00193a50@Obj_193a50@owners@@QAE_NH@Z
bool owners::Obj_193a50::FUN_00193a50(int x) {
    value = x;
    return true;
}


// 0x00193a70 FUN_00193a70 (12 B): matches/0x00193a70.cpp
// sym: ?FUN_00193a70@Obj_193a70@owners@@QAE_NH@Z
bool owners::Obj_193a70::FUN_00193a70(int v) {
    value = v;
    return true;
}


// 0x00193a90 FUN_00193a90 (12 B): matches/0x00193a90.cpp
// sym: ?FUN_00193a90@Obj_193a90@owners@@QAEDH@Z
char owners::Obj_193a90::FUN_00193a90(int v) {
    m78 = v;
    return 1;
}


// 0x00193ab0 FUN_00193ab0 (12 B): matches/0x00193ab0.cpp
// sym: ?FUN_00193ab0@X_193ab0@owners@@QAE_NH@Z
bool owners::X_193ab0::FUN_00193ab0(int v) {
    m7c = v;
    return true;
}

namespace fn_fa51549e {

// 0x00193af0 FUN_00193af0 (35 B): matches/0x00193af0.cpp
// sym: ?Fn@Target@fn_fa51549e@@QAEDPAUSrc@2@@Z
char Target::Fn(Src* p) {
    m80 = p->a;
    m84 = p->b;
    m88 = p->c;
    return 1;
}

} // namespace fn_fa51549e

// 0x00193b50 FUN_00193b50 (35 B): matches/0x00193b50.cpp [wrapped: conflict: Obj; Obj::Set]
// sym: ?Set@Obj@fn_00193b50@@QAEEPAUSrc@2@@Z
namespace fn_00193b50 {
struct Src {
    int a, b, c;
};
class Obj {
  public:
    char pad[0x8c];
    int m8c;
    int m90;
    int m94;
    unsigned char Set(Src* s);
};
unsigned char Obj::Set(Src* s) {
    m8c = s->a;
    m90 = s->b;
    m94 = s->c;
    return 1;
}
} // namespace fn_00193b50


// 0x00193b80 FUN_00193b80 (7 B): matches/0x00193b80.cpp
// sym: ?FUN_00193b80@Obj_193b80@owners@@QAEPAXXZ
void* owners::Obj_193b80::FUN_00193b80() {
    return (char*)this + 0x98;
}

namespace fn_fa51549e {

// 0x00193b90 FUN_00193b90 (7 B): matches/0x00193b90.cpp
// sym: ?GetBody@Obj_193b90@fn_fa51549e@@QAEPAUInner_193b90@2@XZ
Inner_193b90* Obj_193b90::GetBody() {
    return &m;
}


// 0x00193ba0 FUN_00193ba0 (19 B): matches/0x00193ba0.cpp
// sym: ?FUN_00193ba0@fn_fa51549e@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00193ba0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1548), ((char*)&DAT_004e154c));
}

} // namespace fn_fa51549e
