// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00011000..0x00013940 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff0a839e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff0a839e {} using namespace fn_ff0a839e;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_ff0a839e {
class A_11090 {
  public:
    A_11090();
};
struct Vec3_11110 {
    float x, y, z;
};
struct V {
  public:
    float x;
    float y;
    float z;
    void Cross(const V& a, const volatile V& b);
    hulk_freg length2();
};
struct A_11450 {
    A_11450* Get();
};
typedef void(__fastcall* Callback_11520)(void*);
class A_11550 {
  public:
    A_11550();
};
class Obj_115b0 {
  public:
    Obj_115b0* Get();
};
class Color {
  public:
    unsigned int value;
    Color(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
};
struct T {
    int a, b, c, d;
};
struct A {
    int a, b, c, d;
};
struct X {
    A v;
    X(const X& x);
};
class C_118b0 {
  public:
    int lo;
    int hi;
    __int64 Get();
};
class Obj_11920 {
  public:
    char pad[0x1c];
    float Value();
};
struct Base_11980 {
    virtual void F();
    void* GetVtable();
};
struct Base_11c10 {
    void Fn(int);
};
struct Obj_11c10 : Base_11c10 {
    char pad[0x1b50];
};
class Obj_11c90 {
  public:
    char pad[0x1e58];
    float value;
    float Get() { return value; }
};
class Obj_11cf0 {
  public:
    char pad[0x20];
    char mFlag;
    char GetFlag();
};
class A_11e80 {
  public:
    char pad[0x10];
    char* Get();
};
class Obj_11f00 {
  public:
    char pad[0x24];
    float value;
    float Get();
};
class Obj_11f30 {
  public:
    char pad[0x14];
    float value;
    float GetValue();
};
class Obj_11f90 {
  public:
    char pad[0x18];
    float value;
    float Get();
};
class Obj_11fa0 {
  public:
    char pad[0x1c];
    float value;
    float Get();
};
class Obj_12000 {
  public:
    char pad[0x2c];
    int value;
    int Get();
};
class Obj_12010 {
  public:
    char pad[0x30];
    float f;
    float Get();
};
struct Obj_12020 {
    char pad[0x34];
    float value;
};
class A_12090 {
  public:
    char pad[0x60];
    float value;
    float Get();
};
struct Obj_120b0 {
    char pad[0x64];
    float value;
    float Get();
};
class Obj_121a0 {
  public:
    char pad[0x88];
    int mValue;
    int Get();
};
class Obj_12200 {
  public:
    char pad[0x14];
    int value;
    int GetValue();
};
class X_12230 {
    char pad[0x20];

  public:
    float Value();
};
class Obj_12380 {
  public:
    char pad[0x40];
    float Value();
};
class Obj_12400 {
  public:
    char pad[0x18];
    void* Get();
};
struct Obj_12410 {
    char pad[0x14];
    float value;
    float Get();
};
class A_12440 {
  public:
    char pad[0x20];
    float mX;
    float GetX();
};
class Obj_12480 {
  public:
    char pad[0x38];
    unsigned char Get();
};
class Obj_12490 {
  public:
    char pad[0x10];
    int value;
    int Get();
};
class Obj_124b0 {
  public:
    char pad[0x28];
    unsigned int mFlag;
    int GetFlag();
};
class Obj_12500 {
    char pad[0x20];

  public:
    int Get();
};
struct Triple {
  public:
    unsigned int x;
    unsigned int y;
    unsigned int z;
};
class Target_12600 {
  public:
    char pad[0xb4];
    int value;
};
struct Object { char pad[0xb8]; Triple value; void FUN_00012610(Triple* result); };
struct Obj_12640 {
    char pad[0xc4];
    int value;
};
struct Obj_12720 {
    char pad[0x58];
    char m[1];
};
class Obj_12800 {
  public:
    char pad[0xa8];
    char mVal;
    char Get();
};
class Obj_12880 {
  public:
    char pad[0x90];
    int mVal;
    int Get();
};
class Obj_12890 {
  public:
    char pad[0x10];
    void* Get();
};
struct Sub_12940 {
    char data[0x38];
};
class Obj_12960 {
  public:
    virtual void* Get();
    char pad[0x44];
    char member;
};
struct T;
class O_12980 {
  public:
    char pad[0x58];
    T* Get();
};
class Obj_12990 {
  public:
    char pad[0x60];
};
class C_12af0 {
  public:
    char pad[0x18];
    int mValue;
    int* GetValue() { return &mValue; }
};
struct S_12be0 {
    char pad[0x44];
};
class X_12c00 {
  public:
    char pad[0x18];
    float Value();
};
class Obj_12c10 {
  public:
    char pad[0x1c];
    unsigned char value;
    unsigned char Get();
};
class Obj_12c70 {
  public:
    char pad[0x60];
    char* FUN_00012c70();
};
class X_12f30 {
  public:
    char pad[0xb8];
    float value;
    float Get();
};
struct Vec3 {
    int x, y, z;
};
struct S_12f80 {
    int a, b, c;
};
class C_12f80 {
  public:
    char pad[0xcc];
    S_12f80 s;
    S_12f80* Get(S_12f80* p);
};
struct Vec {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x98];
    Triple v;
    char _m_pad_a4[0x1c];
    Vec3 pos;
    char _m_pad_cc[0x14];
    Vec vec;
    char _m_pad_ec[0x1d5c];
    int value;
    void Set(int v);
    Triple* Get(Triple* out);
    Vec3* GetPos(Vec3* out);
    Vec* Get(Vec* out);
};
class X_13000 {
  public:
    char pad[0xec];
    int value;
    int Get();
};
class O_130f0 {
  public:
    char pad[0x38];
    int* Get() { return (int*)((char*)this + 0x38); }
};
class Mgr_13240 {
  public:
    char pad[0x30];
    float mVal;
    float Get();
};
class Obj_132d0 {
  public:
    float Get();
    char pad[0x34];
    float value;
};
typedef void (__fastcall *ItemCallback)(Item *);
class Sub_13840 {
  public:
};
class O_13840 {
  public:
    char pad[0x18];
    void Forward(int);
};
class Sub_13880 {
  public:
    void Fn(int);
};
class Obj_13880 {
  public:
    char pad[0x18];
    Sub_13880 sub;
    void Target(int);
};
class Sub_13890 {
  public:
    void G(int);
};
class Obj_13890 {
  public:
    char pad[0x18];
    void F(int);
};


// 0x00011000 FUN_00011000 (10 B): matches/0x00011000.cpp
// sym: ?FUN_00011000@fn_ff0a839e@@YAMM@Z
hulk_freg __cdecl FUN_00011000(float value) {
    double result = acos(value);
    return result;      // x87: the original returns __CIacos's st0 unrounded
}


// 0x00011010 FUN_00011010 (10 B): matches/0x00011010.cpp
// sym: ?FUN_00011010@fn_ff0a839e@@YAMM@Z
hulk_freg __cdecl FUN_00011010(float value) {
    double result = asin(value);
    return result;      // x87: the original returns __CIasin's st0 unrounded
}


// 0x00011030 FUN_00011030 (7 B): matches/0x00011030.cpp
// sym: ?Sqrt@fn_ff0a839e@@YAMM@Z
hulk_freg Sqrt(float x) {
    return sqrt(x);
}


// 0x00011070 FUN_00011070 (19 B): matches/0x00011070.cpp
// sym: _FUN_00011070
extern "C" int FUN_00011070(float value) {
    return _isnan((double)value);
}


// 0x00011090 FUN_00011090 (3 B): matches/0x00011090.cpp
// sym: ??0A_11090@fn_ff0a839e@@QAE@XZ
A_11090::A_11090() {}

} // namespace fn_ff0a839e

// 0x000110d0 FUN_000110d0 (31 B): matches/0x000110d0.cpp
// sym: ?FUN_000110d0@V3_110d0@owners@@QAEXPAU12@@Z
void owners::V3_110d0::FUN_000110d0(owners::V3_110d0* other) {
    x += other->x;
    y += other->y;
    z += other->z;
}


// 0x000110f0 FUN_000110f0 (31 B): matches/0x000110f0.cpp
// sym: ?FUN_000110f0@Vec3_110f0@owners@@QAEXPAU12@@Z
void owners::Vec3_110f0::FUN_000110f0(owners::Vec3_110f0* other) {
    x -= other->x;
    y -= other->y;
    z -= other->z;
}

namespace fn_ff0a839e {

// 0x00011110 FUN_00011110 (35 B): matches/0x00011110.cpp
// sym: ?FUN_00011110@fn_ff0a839e@@YIXPAUVec3_11110@1@PAXPBU21@2@Z
void __fastcall FUN_00011110(Vec3_11110* out, void*, const Vec3_11110* a, const Vec3_11110* b) {
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

} // namespace fn_ff0a839e

// 0x00011140 FUN_00011140 (31 B): matches/0x00011140.cpp
// sym: ?FUN_00011140@Vec3_11140@owners@@QAEXM@Z
void owners::Vec3_11140::FUN_00011140(float value) {
    x *= value;
    y *= value;
    z *= value;
}


// 0x00011160 FUN_00011160 (43 B): matches/0x00011160.cpp
// sym: ?FUN_00011160@Vec3_11160@owners@@QAEXMPBU12@@Z
void owners::Vec3_11160::FUN_00011160(float s, const owners::Vec3_11160* v) {
    x = s * v->x + x;
    y = s * v->y + y;
    z = s * v->z + z;
}

namespace fn_ff0a839e {

// 0x000111b0 FUN_000111b0 (59 B): matches/0x000111b0.cpp
// sym: ?Cross@V@fn_ff0a839e@@QAEXABU12@ADU12@@Z
void V::Cross(const V& a, const volatile V& b) {
    float yy = b.x * a.z - b.z * a.x;
    float zz = b.y * a.x - b.x * a.y;
    float xx = b.z * a.y - b.y * a.z;
    x = xx;
    y = yy;
    z = zz;
}


// 0x000111f0 FUN_000111f0 (31 B): matches/0x000111f0.cpp
// sym: ?length2@V@fn_ff0a839e@@QAEMXZ
hulk_freg V::length2() {
    return x * x + y * y + z * z;
}

} // namespace fn_ff0a839e

// 0x00011220 FUN_00011220 (33 B): matches/0x00011220.cpp
// sym: ?FUN_00011220@Vec3_11220@owners@@QAEPAU12@PBU12@@Z
owners::Vec3_11220* owners::Vec3_11220::FUN_00011220(const owners::Vec3_11220* other) {
    x = x + other->x;
    y = y + other->y;
    z = z + other->z;
    return this;
}


// 0x00011250 FUN_00011250 (35 B): matches/0x00011250.cpp
// sym: ?FUN_00011250@Vec3_11250@owners@@QAEPAU12@PAU12@0@Z
owners::Vec3_11250* owners::Vec3_11250::FUN_00011250(owners::Vec3_11250* out, owners::Vec3_11250* rhs) {
    float dz = z - rhs->z;
    float dy = y - rhs->y;
    float dx = x - rhs->x;
    out->x = dx;
    out->y = dy;
    out->z = dz;
    return out;
}


// 0x00011330 FUN_00011330 (76 B): equivalent/0x00011330.cpp
// sym: ?FUN_00011330@Random_11330@owners@@QAEII@Z @670120e0eeee @w3c346b6935a6
// STATUS: equivalent (tools/equiv.py level 3: 2859 inputs, branch coverage 0/0)
// FUN_00011330 @ 0x00011330
unsigned int owners::Random_11330::FUN_00011330(unsigned int maximum) {
    low = (low & 0xffffU) * 0x9069U + (low >> 16);
    high = (high & 0xffffU) * 0x4650U + (high >> 16);
    return ((low << 16) + (high & 0xffffU)) % (maximum + 1U);
}


// 0x00011380 FUN_00011380 (84 B): equivalent/0x00011380.cpp
// sym: ?FUN_00011380@Random_11380@owners@@QAEHHH@Z @e1c7a73d42a5 @wcbdc6cc76e77
// STATUS: equivalent (tools/equiv.py level 3: 2824 inputs, branch coverage 0/0)
// FUN_00011380 @ 0x00011380
int owners::Random_11380::FUN_00011380(int minimum, int maximum) { low = (low & 0xffffu) * 0x9069u + (low >> 16); high = (high & 0xffffu) * 0x4650u + (high >> 16); unsigned int value = (high & 0xffffu) + (low << 16); unsigned int range = (unsigned int)(maximum - minimum + 1); return minimum + value % range; }

namespace fn_ff0a839e {

// 0x000113e0 FUN_000113e0 (94 B): matches/0x000113e0.cpp
// sym: _FUN_000113e0
extern "C" int FUN_000113e0(int low, int high) {
    uint* p = (*(uint**)&DAT_004e5acc);
    uint* q = (*(uint**)&DAT_004e5acc) + 1;
    *(*(uint**)&DAT_004e5acc) = (*(*(uint**)&DAT_004e5acc) & 65535) * 36969 + (*(*(uint**)&DAT_004e5acc) >> 16);
    uint b = *q;
    b = (b & 65535) * 18000 + (b >> 16);
    *q = b;
    return low + ((*p << 16) + (b & 65535)) % (high - low + 1);
}


// 0x00011440 FUN_00011440 (7 B): matches/0x00011440.cpp
// sym: ?FUN_00011440@fn_ff0a839e@@YAMM@Z
hulk_freg FUN_00011440(float x) {
    return cos(x);
}


// 0x00011450 FUN_00011450 (3 B): matches/0x00011450.cpp
// sym: ?Get@A_11450@fn_ff0a839e@@QAEPAU12@XZ
A_11450* A_11450::Get() {
    return this;
}


// 0x00011520 FUN_00011520 (48 B): matches/0x00011520.cpp
// sym: ?FUN_00011520@fn_ff0a839e@@YGXPAXHHP6IX0@Z@Z
void __stdcall FUN_00011520(void* base, int stride, int count, Callback_11520 fn) {
    int n = count - 1;
    if (n >= 0) {
        int m = n + 1;
        do {
            fn(base);
            base = (char*)base + stride;
        } while (--m != 0);
    }
}


// 0x00011550 FUN_00011550 (3 B): matches/0x00011550.cpp
// sym: ??0A_11550@fn_ff0a839e@@QAE@XZ
A_11550::A_11550() {}


// 0x000115b0 FUN_000115b0 (3 B): matches/0x000115b0.cpp
// sym: ?Get@Obj_115b0@fn_ff0a839e@@QAEPAV12@XZ
Obj_115b0* Obj_115b0::Get() {
    return this;
}


// 0x000115c0 FUN_000115c0 (38 B): matches/0x000115c0.cpp
// sym: ??0Color@fn_ff0a839e@@QAE@IIII@Z
Color::Color(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    value = (((d << 8) | a) << 8 | b) << 8 | c;
}

} // namespace fn_ff0a839e

// 0x00011750 FUN_00011750 (200 B): equivalent/0x00011750.cpp
// sym: ?FUN_00011750@Color_11750@owners@@QAEXIIM@Z @fc9b3ecab332 @w9a47baec0e7e
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00011750 @ 0x00011750
void owners::Color_11750::FUN_00011750(unsigned int from, unsigned int to, float amount) {
 int red = (from >> 16) & 255;
 int green = (from >> 8) & 255;
 int alpha = from >> 24;
 int blue = from & 255;
 unsigned int result = (unsigned int)(red + (int)(((int)((to >> 16) & 255) - red) * (double)amount)) << 16;
 result |= (unsigned int)(green + (int)(((int)((to >> 8) & 255) - green) * (double)amount)) << 8;
 result |= (unsigned int)(alpha + (int)(((int)(to >> 24) - alpha) * (double)amount)) << 24;
 result |= (unsigned int)(blue + (int)(((int)(to & 255) - blue) * (double)amount));
 value = result;
}

namespace fn_ff0a839e {

// 0x00011840 FUN_00011840 (32 B): matches/0x00011840.cpp
// sym: ?FUN_00011840@fn_ff0a839e@@YIPAUT@1@PAU21@PAXHHHH@Z
T* __fastcall FUN_00011840(T* self, void* p, int w, int x, int y, int z) {
    self->a = w;
    self->b = x;
    self->c = y;
    self->d = z;
    return self;
}


// 0x00011880 FUN_00011880 (35 B): matches/0x00011880.cpp
// sym: ??0X@fn_ff0a839e@@QAE@ABU01@@Z
X::X(const X& x) {
    v = x.v;
}


// 0x000118b0 FUN_000118b0 (6 B): matches/0x000118b0.cpp
// sym: ?Get@C_118b0@fn_ff0a839e@@QAE_JXZ
__int64 C_118b0::Get() {
    return *(__int64*)this;
}

} // namespace fn_ff0a839e

// 0x000118c0 FUN_000118c0 (26 B): matches/0x000118c0.cpp
// sym: ?FUN_000118c0@C_118c0@owners@@QAEXPAH@Z
void owners::C_118c0::FUN_000118c0(int* p) {
    if (p) {
        p = (int*)((char*)p + 8);
        ((owners::C_118c0*)((char*)this + 8))->Callee(p);
    }
}

namespace fn_ff0a839e {

// 0x00011920 FUN_00011920 (4 B): matches/0x00011920.cpp
// sym: ?Value@Obj_11920@fn_ff0a839e@@QAEMXZ
float Obj_11920::Value() {
    return *(float*)((char*)this + 0x1c);
}


// 0x00011980 FUN_00011980 (3 B): matches/0x00011980.cpp
// sym: ?GetVtable@Base_11980@fn_ff0a839e@@QAEPAXXZ
void* Base_11980::GetVtable() {
    return *(void**)this;
}


// 0x00011c10 FUN_00011c10 (11 B): matches/0x00011c10.cpp
// sym: ?Target@fn_ff0a839e@@YIXPAUObj_11c10@1@HH@Z
void __fastcall Target(Obj_11c10* p, int unused, int a) {
    ((Base_11c10*)((char*)p + 0x1b50))->Fn(a);
}


// 0x00011c80 FUN_00011c80 (13 B): matches/0x00011c80.cpp
// sym: ?Set@Obj@fn_ff0a839e@@QAEXH@Z
void Obj::Set(int v) {
    value = v;
}


// 0x00011c90 FUN_00011c90 (7 B): matches/0x00011c90.cpp
// sym: ?FUN_00011c90@fn_ff0a839e@@YIMPAVObj_11c90@1@@Z
float __fastcall FUN_00011c90(Obj_11c90* self) {
    return self->Get();
}


// 0x00011cc0 FUN_00011cc0 (1 B): matches/0x00011cc0.cpp
// sym: ?FUN_00011cc0@fn_ff0a839e@@YAXXZ
void FUN_00011cc0() {}

} // namespace fn_ff0a839e

// 0x00011ce0 FUN_00011ce0 (4 B): matches/0x00011ce0.cpp
// sym: ?FUN_00011ce0@A_11ce0@owners@@QAEPAXXZ
void* owners::A_11ce0::FUN_00011ce0() {
    return (char*)this + 0x18;
}

namespace fn_ff0a839e {

// 0x00011cf0 FUN_00011cf0 (4 B): matches/0x00011cf0.cpp
// sym: ?GetFlag@Obj_11cf0@fn_ff0a839e@@QAEDXZ
char Obj_11cf0::GetFlag() {
    return mFlag;
}

} // namespace fn_ff0a839e

// 0x00011d30 FUN_00011d30 (30 B): matches/0x00011d30.cpp [wrapped: conflict: X]
// sym: ?Get@X@fn_00011d30@@QAE?AUV@2@XZ
namespace fn_00011d30 {
struct V {
    int a, b, c;
};
class X {
    char pad[0x34];
    V v;

  public:
    V Get();
};
V X::Get() {
    return v;
}
} // namespace fn_00011d30


// 0x00011e20 FUN_00011e20 (4 B): matches/0x00011e20.cpp
// sym: ?FUN_00011e20@Obj_11e20@owners@@QAEPAHXZ
int* owners::Obj_11e20::FUN_00011e20() {
    return (int*)((char*)this + 0x10);
}


// 0x00011e40 FUN_00011e40 (4 B): matches/0x00011e40.cpp
// sym: ?FUN_00011e40@Obj_11e40@owners@@QAEPAXXZ
void* owners::Obj_11e40::FUN_00011e40() {
    return (char*)pad + 0x60;
}

namespace fn_ff0a839e {

// 0x00011e80 FUN_00011e80 (4 B): matches/0x00011e80.cpp
// sym: ?Get@A_11e80@fn_ff0a839e@@QAEPADXZ
char* A_11e80::Get() {
    return pad + 0x10;
}


// 0x00011f00 FUN_00011f00 (4 B): matches/0x00011f00.cpp
// sym: ?Get@Obj_11f00@fn_ff0a839e@@QAEMXZ
float Obj_11f00::Get() {
    return value;
}


// 0x00011f30 FUN_00011f30 (4 B): matches/0x00011f30.cpp
// sym: ?GetValue@Obj_11f30@fn_ff0a839e@@QAEMXZ
float Obj_11f30::GetValue() {
    return value;
}


// 0x00011f90 FUN_00011f90 (4 B): matches/0x00011f90.cpp
// sym: ?Get@Obj_11f90@fn_ff0a839e@@QAEMXZ
float Obj_11f90::Get() {
    return value;
}


// 0x00011fa0 FUN_00011fa0 (4 B): matches/0x00011fa0.cpp
// sym: ?Get@Obj_11fa0@fn_ff0a839e@@QAEMXZ
float Obj_11fa0::Get() {
    return value;
}


// 0x00012000 FUN_00012000 (4 B): matches/0x00012000.cpp
// sym: ?Get@Obj_12000@fn_ff0a839e@@QAEHXZ
int Obj_12000::Get() {
    return value;
}


// 0x00012010 FUN_00012010 (4 B): matches/0x00012010.cpp
// sym: ?Get@Obj_12010@fn_ff0a839e@@QAEMXZ
float Obj_12010::Get() {
    return f;
}


// 0x00012020 FUN_00012020 (4 B): matches/0x00012020.cpp
// sym: ?FUN_00012020@fn_ff0a839e@@YIMPAUObj_12020@1@@Z
float __fastcall FUN_00012020(Obj_12020* self) {
    return self->value;
}

} // namespace fn_ff0a839e

// 0x00012080 FUN_00012080 (4 B): matches/0x00012080.cpp
// sym: ?FUN_00012080@O_12080@owners@@QAEPAXXZ
void* owners::O_12080::FUN_00012080() {
    return (char*)this + 0x20;
}

namespace fn_ff0a839e {

// 0x00012090 FUN_00012090 (4 B): matches/0x00012090.cpp
// sym: ?Get@A_12090@fn_ff0a839e@@QAEMXZ
float A_12090::Get() {
    return value;
}

} // namespace fn_ff0a839e

// 0x000120a0 FUN_000120a0 (4 B): matches/0x000120a0.cpp
// sym: ?FUN_000120a0@Obj_120a0@owners@@QAEPAXXZ
void* owners::Obj_120a0::FUN_000120a0() {
    return (char*)this + 0x28;
}

namespace fn_ff0a839e {

// 0x000120b0 FUN_000120b0 (4 B): matches/0x000120b0.cpp
// sym: ?Get@Obj_120b0@fn_ff0a839e@@QAEMXZ
float Obj_120b0::Get() {
    return value;
}

} // namespace fn_ff0a839e

// 0x000120c0 FUN_000120c0 (4 B): matches/0x000120c0.cpp
// sym: ?FUN_000120c0@Obj_120c0@owners@@QAEPAXXZ
void* owners::Obj_120c0::FUN_000120c0() {
    return (char*)this + 0x30;
}


// 0x000120e0 FUN_000120e0 (4 B): matches/0x000120e0.cpp
// sym: ?FUN_000120e0@Obj_120e0@owners@@QAEPAXXZ
void* owners::Obj_120e0::FUN_000120e0() {
    return (char*)this + 0x38;
}


// 0x00012100 FUN_00012100 (4 B): matches/0x00012100.cpp
// sym: ?FUN_00012100@C_12100@owners@@QAEPADXZ
char* owners::C_12100::FUN_00012100() {
    return (char*)this + 0x40;
}


// 0x00012120 FUN_00012120 (4 B): matches/0x00012120.cpp
// sym: ?FUN_00012120@Obj_12120@owners@@QAEPADXZ
char* owners::Obj_12120::FUN_00012120() {
    return (char*)this + 0x48;
}


// 0x00012140 FUN_00012140 (4 B): matches/0x00012140.cpp
// sym: ?FUN_00012140@Obj_12140@owners@@QAEPADXZ
char* owners::Obj_12140::FUN_00012140() {
    return (char*)((char*)mBuf + 0x50);
}


// 0x00012160 FUN_00012160 (4 B): matches/0x00012160.cpp
// sym: ?FUN_00012160@T_12160@owners@@QAEPAXXZ
void* owners::T_12160::FUN_00012160() {
    return (char*)this + 0x58;
}

namespace fn_ff0a839e {

// 0x000121a0 FUN_000121a0 (7 B): matches/0x000121a0.cpp
// sym: ?Get@Obj_121a0@fn_ff0a839e@@QAEHXZ
int Obj_121a0::Get() {
    return mValue;
}


// 0x00012200 FUN_00012200 (4 B): matches/0x00012200.cpp
// sym: ?GetValue@Obj_12200@fn_ff0a839e@@QAEHXZ
int Obj_12200::GetValue() {
    return value;
}


// 0x00012230 FUN_00012230 (4 B): matches/0x00012230.cpp
// sym: ?Value@X_12230@fn_ff0a839e@@QAEMXZ
float X_12230::Value() {
    return *(float*)((char*)this + 0x20);
}

} // namespace fn_ff0a839e

// 0x00012310 FUN_00012310 (4 B): matches/0x00012310.cpp
// sym: ?FUN_00012310@T_12310@owners@@QAEPAHXZ
int* owners::T_12310::FUN_00012310() {
    return (int*)((char*)this + 0x18);
}

namespace fn_ff0a839e {

// 0x00012380 FUN_00012380 (4 B): matches/0x00012380.cpp
// sym: ?Value@Obj_12380@fn_ff0a839e@@QAEMXZ
float Obj_12380::Value() {
    return *(float*)((char*)this + 0x40);
}


// 0x00012400 FUN_00012400 (4 B): matches/0x00012400.cpp
// sym: ?Get@Obj_12400@fn_ff0a839e@@QAEPAXXZ
void* Obj_12400::Get() {
    return (char*)this + 0x18;
}


// 0x00012410 FUN_00012410 (4 B): matches/0x00012410.cpp
// sym: ?Get@Obj_12410@fn_ff0a839e@@QAEMXZ
float Obj_12410::Get() {
    return value;
}


// 0x00012440 FUN_00012440 (4 B): matches/0x00012440.cpp
// sym: ?GetX@A_12440@fn_ff0a839e@@QAEMXZ
float A_12440::GetX() {
    return mX;
}


// 0x00012480 FUN_00012480 (4 B): matches/0x00012480.cpp
// sym: ?Get@Obj_12480@fn_ff0a839e@@QAEEXZ
unsigned char Obj_12480::Get() {
    return pad[0x38];
}


// 0x00012490 FUN_00012490 (4 B): matches/0x00012490.cpp
// sym: ?Get@Obj_12490@fn_ff0a839e@@QAEHXZ
int Obj_12490::Get() {
    return value;
}


// 0x000124b0 FUN_000124b0 (10 B): matches/0x000124b0.cpp
// sym: ?GetFlag@Obj_124b0@fn_ff0a839e@@QAEHXZ
int Obj_124b0::GetFlag() {
    return (mFlag >> 7) & 1;
}


// 0x00012500 FUN_00012500 (4 B): matches/0x00012500.cpp
// sym: ?Get@Obj_12500@fn_ff0a839e@@QAEHXZ
int Obj_12500::Get() {
    return *(int*)((char*)this + 0x20);
}

} // namespace fn_ff0a839e

// 0x00012530 FUN_00012530 (4 B): matches/0x00012530.cpp
// sym: ?FUN_00012530@Obj_12530@owners@@QAEPAHXZ
int* owners::Obj_12530::FUN_00012530() {
    return (int*)((char*)this + 0x2c);
}


// 0x00012540 FUN_00012540 (4 B): matches/0x00012540.cpp
// sym: ?FUN_00012540@X_12540@owners@@QAEPADXZ
char* owners::X_12540::FUN_00012540() {
    return (char*)this + 0x38;
}


// 0x00012550 FUN_00012550 (4 B): matches/0x00012550.cpp
// sym: ?FUN_00012550@Thing_12550@owners@@QAEPAXXZ
void* owners::Thing_12550::FUN_00012550() {
    return (char*)this + 0x48;
}

namespace fn_ff0a839e {

// 0x00012590 FUN_00012590 (33 B): matches/0x00012590.cpp
// sym: ?Get@Obj@fn_ff0a839e@@QAEPAUTriple@2@PAU32@@Z
Triple* Obj::Get(Triple* out) {
    *out = v;
    return out;
}

} // namespace fn_ff0a839e

// 0x000125c0 FUN_000125c0 (33 B): matches/0x000125c0.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_000125c0@@QAE?AUVec@2@XZ
namespace fn_000125c0 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0xa4];
    Vec v;

  public:
    Vec Get();
};
Vec Obj::Get() {
    return v;
}
} // namespace fn_000125c0

namespace fn_ff0a839e {

// 0x00012600 FUN_00012600 (7 B): matches/0x00012600.cpp
// sym: ?FUN_00012600@fn_ff0a839e@@YIHPAVTarget_12600@1@@Z
int __fastcall FUN_00012600(Target_12600* self) {
    return self->value;
}


// 0x00012610 FUN_00012610 (33 B): equivalent/0x00012610.cpp
// sym: ?FUN_00012610@Object@fn_ff0a839e@@QAEXPAUTriple@2@@Z @cbf2d0676b5c @w35c55d6eb28c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00012610 @ 0x00012610
void Object::FUN_00012610(Triple* result) { result->x = value.x; result->y = value.y; result->z = value.z; }


// 0x00012640 FUN_00012640 (7 B): matches/0x00012640.cpp
// sym: ?FUN_00012640@fn_ff0a839e@@YIHPAUObj_12640@1@@Z
int __fastcall FUN_00012640(Obj_12640* self) {
    return self->value;
}


// 0x00012670 FUN_00012670 (4 B): matches/0x00012670.cpp
// sym: ?FUN_00012670@fn_ff0a839e@@YIPADPAD@Z
char* __fastcall FUN_00012670(char* obj) {
    return (char*)obj + 0x18;
}

} // namespace fn_ff0a839e

// 0x00012680 FUN_00012680 (4 B): matches/0x00012680.cpp
// sym: ?FUN_00012680@Obj_12680@owners@@QAEPAXXZ
void* owners::Obj_12680::FUN_00012680() {
    return &member;
}

namespace fn_ff0a839e {

// 0x00012720 FUN_00012720 (4 B): matches/0x00012720.cpp
// sym: ?FUN_00012720@fn_ff0a839e@@YIPAXPAUObj_12720@1@@Z
void* __fastcall FUN_00012720(Obj_12720* self) {
    return self->m;
}

} // namespace fn_ff0a839e

// 0x00012740 FUN_00012740 (4 B): matches/0x00012740.cpp
// sym: ?FUN_00012740@Obj_12740@owners@@QAEPADXZ
char* owners::Obj_12740::FUN_00012740() {
    return (char*)this + 0x18;
}


// 0x00012750 FUN_00012750 (4 B): matches/0x00012750.cpp
// sym: ?FUN_00012750@Obj_12750@owners@@QAEPAHXZ
int* owners::Obj_12750::FUN_00012750() {
    return (int*)((char*)this + 0x20);
}


// 0x000127d0 FUN_000127d0 (7 B): matches/0x000127d0.cpp
// sym: ?FUN_000127d0@X_127d0@owners@@QAEPADXZ
char* owners::X_127d0::FUN_000127d0(void) {
    return (char*)((char*)this + 0xc8);
}


// 0x000127e0 FUN_000127e0 (7 B): matches/0x000127e0.cpp
// sym: ?FUN_000127e0@Obj_127e0@owners@@QAEPADXZ
char* owners::Obj_127e0::FUN_000127e0() {
    return (char*)((char*)this + 0x98);
}


// 0x000127f0 FUN_000127f0 (7 B): matches/0x000127f0.cpp
// sym: ?FUN_000127f0@Obj_127f0@owners@@QAEPAXXZ
void* owners::Obj_127f0::FUN_000127f0() {
    return (void*)((char*)this + 0xa0);
}

namespace fn_ff0a839e {

// 0x00012800 FUN_00012800 (7 B): matches/0x00012800.cpp
// sym: ?Get@Obj_12800@fn_ff0a839e@@QAEDXZ
char Obj_12800::Get() {
    return mVal;
}


// 0x00012880 FUN_00012880 (7 B): matches/0x00012880.cpp
// sym: ?Get@Obj_12880@fn_ff0a839e@@QAEHXZ
int Obj_12880::Get() {
    return mVal;
}


// 0x00012890 FUN_00012890 (4 B): matches/0x00012890.cpp
// sym: ?Get@Obj_12890@fn_ff0a839e@@QAEPAXXZ
void* Obj_12890::Get() {
    return *(void**)((char*)this + 0x10);
}

} // namespace fn_ff0a839e

// 0x000128b0 FUN_000128b0 (30 B): matches/0x000128b0.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_000128b0@@QAE?AUVec@2@XZ
namespace fn_000128b0 {
struct Vec {
    int x, y, z;
};
class Obj {
    char pad[16];
    Vec v;

  public:
    Vec Get();
};
Vec Obj::Get() {
    return v;
}
} // namespace fn_000128b0


// 0x00012900 FUN_00012900 (4 B): matches/0x00012900.cpp
// sym: ?FUN_00012900@Obj_12900@owners@@QAEPADXZ
char* owners::Obj_12900::FUN_00012900() {
    return (char*)this + 0x18;
}


// 0x00012910 FUN_00012910 (4 B): matches/0x00012910.cpp
// sym: ?FUN_00012910@Obj_12910@owners@@QAEPAXXZ
void* owners::Obj_12910::FUN_00012910() {
    return (char*)this + 0x20;
}


// 0x00012920 FUN_00012920 (4 B): matches/0x00012920.cpp
// sym: ?FUN_00012920@X_12920@owners@@QAEPAXXZ
void* owners::X_12920::FUN_00012920() {
    return (char*)this + 0x28;
}


// 0x00012930 FUN_00012930 (4 B): matches/0x00012930.cpp
// sym: ?FUN_00012930@X_12930@owners@@QAEPAHXZ
int* owners::X_12930::FUN_00012930() {
    return (int*)((char*)this + 0x30);
}


// 0x00012940 FUN_00012940 (4 B): matches/0x00012940.cpp
// sym: ?FUN_00012940@Obj_12940@owners@@QAEPAXXZ
void* owners::Obj_12940::FUN_00012940() {
    return (void*)((char*)this + 0x38);
}


// 0x00012950 FUN_00012950 (4 B): matches/0x00012950.cpp
// sym: ?FUN_00012950@C_12950@owners@@QAEPAXXZ
void* owners::C_12950::FUN_00012950() {
    return (char*)this + 0x40;
}

namespace fn_ff0a839e {

// 0x00012960 FUN_00012960 (4 B): matches/0x00012960.cpp
// sym: ?Get@Obj_12960@fn_ff0a839e@@UAEPAXXZ
void* Obj_12960::Get() {
    return &member;
}


// 0x00012970 FUN_00012970 (4 B): matches/0x00012970.cpp
// sym: ?FUN_00012970@fn_ff0a839e@@YIPAXPAX@Z
void* __fastcall FUN_00012970(void* self) {
    return (char*)self + 0x50;
}


// 0x00012980 FUN_00012980 (4 B): matches/0x00012980.cpp
// sym: ?Get@O_12980@fn_ff0a839e@@QAEPAUT@2@XZ
T* O_12980::Get() {
    return (T*)((char*)this + 0x58);
}


// 0x00012990 FUN_00012990 (4 B): matches/0x00012990.cpp
// sym: ?FUN_00012990@fn_ff0a839e@@YIPAXPAVObj_12990@1@@Z
void* __fastcall FUN_00012990(Obj_12990* self) {
    return (char*)self + 0x60;
}

} // namespace fn_ff0a839e

// 0x000129a0 FUN_000129a0 (4 B): matches/0x000129a0.cpp
// sym: ?FUN_000129a0@Obj_129a0@owners@@QAEPADXZ
char* owners::Obj_129a0::FUN_000129a0() {
    return (char*)this + 0x68;
}


// 0x000129e0 FUN_000129e0 (4 B): matches/0x000129e0.cpp
// sym: ?FUN_000129e0@A_129e0@owners@@QAEPAHXZ
int* owners::A_129e0::FUN_000129e0() {
    return (int*)((char*)this + 0x10);
}


// 0x000129f0 FUN_000129f0 (4 B): matches/0x000129f0.cpp
// sym: ?FUN_000129f0@Obj_129f0@owners@@QAEPAXXZ
void* owners::Obj_129f0::FUN_000129f0() {
    return (char*)this + 0x18;
}


// 0x00012a60 FUN_00012a60 (4 B): matches/0x00012a60.cpp
// sym: ?FUN_00012a60@Obj_12a60@owners@@QAEPADXZ
char* owners::Obj_12a60::FUN_00012a60() {
    return (char*)pad + 0x40;
}


// 0x00012ae0 FUN_00012ae0 (4 B): matches/0x00012ae0.cpp
// sym: ?FUN_00012ae0@Obj_12ae0@owners@@QAEPADXZ
char* owners::Obj_12ae0::FUN_00012ae0() {
    return (char*)this + 0x10;
}

namespace fn_ff0a839e {

// 0x00012af0 FUN_00012af0 (4 B): matches/0x00012af0.cpp
// sym: ?FUN_00012af0@fn_ff0a839e@@YIPAHPAVC_12af0@1@@Z
int* __fastcall FUN_00012af0(C_12af0* self) {
    return self->GetValue();
}

} // namespace fn_ff0a839e

// 0x00012bd0 FUN_00012bd0 (4 B): matches/0x00012bd0.cpp
// sym: ?FUN_00012bd0@O_12bd0@owners@@QAEPAXXZ
void* owners::O_12bd0::FUN_00012bd0() {
    return (char*)this + 0x38;
}

namespace fn_ff0a839e {

// 0x00012be0 FUN_00012be0 (4 B): matches/0x00012be0.cpp
// sym: ?FUN_00012be0@fn_ff0a839e@@YIPAUS_12be0@1@PAU21@@Z
S_12be0* __fastcall FUN_00012be0(S_12be0* self) {
    return (S_12be0*)((char*)self + 0x44);
}


// 0x00012c00 FUN_00012c00 (4 B): matches/0x00012c00.cpp
// sym: ?Value@X_12c00@fn_ff0a839e@@QAEMXZ
float X_12c00::Value() {
    return *(float*)((char*)this + 0x18);
}


// 0x00012c10 FUN_00012c10 (4 B): matches/0x00012c10.cpp
// sym: ?Get@Obj_12c10@fn_ff0a839e@@QAEEXZ
unsigned char Obj_12c10::Get() {
    return value;
}

} // namespace fn_ff0a839e

// 0x00012c40 FUN_00012c40 (4 B): matches/0x00012c40.cpp
// sym: ?FUN_00012c40@Body_12c40@owners@@QAEPAU12@XZ
owners::Body_12c40* owners::Body_12c40::FUN_00012c40() {
    return (owners::Body_12c40*)((char*)this + 0x20);
}

namespace fn_ff0a839e {

// 0x00012c70 FUN_00012c70 (4 B): matches/0x00012c70.cpp
// sym: ?FUN_00012c70@Obj_12c70@fn_ff0a839e@@QAEPADXZ
char* Obj_12c70::FUN_00012c70() {
    return (char*)this + 0x60;
}

} // namespace fn_ff0a839e

// 0x00012c80 FUN_00012c80 (7 B): matches/0x00012c80.cpp
// sym: ?FUN_00012c80@Obj_12c80@owners@@QAEPAXXZ
void* owners::Obj_12c80::FUN_00012c80() {
    return (char*)this + 0xa8;
}


// 0x00012c90 FUN_00012c90 (33 B): matches/0x00012c90.cpp [wrapped: conflict: Obj]
// sym: ?Get@Obj@fn_00012c90@@QAEPAUVec@2@PAU32@@Z
namespace fn_00012c90 {
struct Vec {
    int a, b, c;
};
class Obj {
    char pad[0xb0];
    Vec v;

  public:
    Vec* Get(Vec* out);
};
Vec* Obj::Get(Vec* out) {
    *out = v;
    return out;
}
} // namespace fn_00012c90


// 0x00012d80 FUN_00012d80 (4 B): matches/0x00012d80.cpp
// sym: ?FUN_00012d80@C_12d80@owners@@QAEPAXXZ
void* owners::C_12d80::FUN_00012d80() {
    return (char*)this + 0x28;
}


// 0x00012da0 FUN_00012da0 (4 B): matches/0x00012da0.cpp
// sym: ?FUN_00012da0@Obj_12da0@owners@@QAEPADXZ
char* owners::Obj_12da0::FUN_00012da0() {
    return &data;
}


// 0x00012db0 FUN_00012db0 (4 B): matches/0x00012db0.cpp
// sym: ?FUN_00012db0@X_12db0@owners@@QAEPAXXZ
void* owners::X_12db0::FUN_00012db0() {
    return (char*)this + 0x18;
}


// 0x00012ee0 FUN_00012ee0 (4 B): matches/0x00012ee0.cpp
// sym: ?FUN_00012ee0@Obj_12ee0@owners@@QAEPAHXZ
int* owners::Obj_12ee0::FUN_00012ee0() {
    return (int*)((char*)this + 0x4c);
}


// 0x00012ef0 FUN_00012ef0 (4 B): matches/0x00012ef0.cpp
// sym: ?FUN_00012ef0@Obj_12ef0@owners@@QAEPADXZ
char* owners::Obj_12ef0::FUN_00012ef0() {
    return (char*)this + 0x58;
}


// 0x00012f00 FUN_00012f00 (4 B): matches/0x00012f00.cpp
// sym: ?FUN_00012f00@Obj_12f00@owners@@QAEPADXZ
char* owners::Obj_12f00::FUN_00012f00() {
    return (char*)this + 0x68;
}


// 0x00012f10 FUN_00012f10 (4 B): matches/0x00012f10.cpp
// sym: ?FUN_00012f10@Obj_12f10@owners@@QAEPAHXZ
int* owners::Obj_12f10::FUN_00012f10() {
    return &m70;
}

namespace fn_ff0a839e {

// 0x00012f30 FUN_00012f30 (7 B): matches/0x00012f30.cpp
// sym: ?Get@X_12f30@fn_ff0a839e@@QAEMXZ
float X_12f30::Get() {
    return value;
}


// 0x00012f50 FUN_00012f50 (33 B): matches/0x00012f50.cpp
// sym: ?GetPos@Obj@fn_ff0a839e@@QAEPAUVec3@2@PAU32@@Z
Vec3* Obj::GetPos(Vec3* out) {
    *out = pos;
    return out;
}


// 0x00012f80 FUN_00012f80 (33 B): matches/0x00012f80.cpp
// sym: ?Get@C_12f80@fn_ff0a839e@@QAEPAUS_12f80@2@PAU32@@Z
S_12f80* C_12f80::Get(S_12f80* p) {
    *p = s;
    return p;
}


// 0x00012fd0 FUN_00012fd0 (33 B): matches/0x00012fd0.cpp
// sym: ?Get@Obj@fn_ff0a839e@@QAEPAUVec@2@PAU32@@Z
Vec* Obj::Get(Vec* out) {
    *out = vec;
    return out;
}


// 0x00013000 FUN_00013000 (7 B): matches/0x00013000.cpp
// sym: ?Get@X_13000@fn_ff0a839e@@QAEHXZ
int X_13000::Get() {
    return value;
}

} // namespace fn_ff0a839e

// 0x00013050 FUN_00013050 (4 B): matches/0x00013050.cpp
// sym: ?FUN_00013050@A_13050@owners@@QAEPAHXZ
int* owners::A_13050::FUN_00013050() {
    return (int*)((char*)this + 0x34);
}


// 0x00013060 FUN_00013060 (4 B): matches/0x00013060.cpp
// sym: ?FUN_00013060@Obj_13060@owners@@QAEPAXXZ
void* owners::Obj_13060::FUN_00013060() {
    return (char*)this + 0x40;
}


// 0x00013090 FUN_00013090 (4 B): matches/0x00013090.cpp
// sym: ?FUN_00013090@Obj_13090@owners@@QAEPAXXZ
void* owners::Obj_13090::FUN_00013090() {
    return (char*)this + 0x18;
}

namespace fn_ff0a839e {

// 0x000130f0 FUN_000130f0 (4 B): matches/0x000130f0.cpp
// sym: ?Get@O_130f0@fn_ff0a839e@@QAEPAHXZ
int* FUN_000130f0(O_130f0* p) {
    return p->Get();
}

} // namespace fn_ff0a839e

// 0x00013140 FUN_00013140 (4 B): matches/0x00013140.cpp
// sym: ?FUN_00013140@X_13140@owners@@QAEPADXZ
char* owners::X_13140::FUN_00013140() {
    return (char*)this + 0x10;
}


// 0x000131a0 FUN_000131a0 (4 B): matches/0x000131a0.cpp
// sym: ?FUN_000131a0@Obj_131a0@owners@@QAEPADXZ
char* owners::Obj_131a0::FUN_000131a0() {
    return (char*)this + 0x30;
}

namespace fn_ff0a839e {

// 0x00013240 FUN_00013240 (4 B): matches/0x00013240.cpp
// sym: ?Get@Mgr_13240@fn_ff0a839e@@QAEMXZ
float Mgr_13240::Get() {
    return mVal;
}


// 0x000132d0 FUN_000132d0 (4 B): matches/0x000132d0.cpp
// sym: ?Get@Obj_132d0@fn_ff0a839e@@QAEMXZ
float Obj_132d0::Get() {
    return value;
}


// 0x00013420 FUN_00013420 (49 B): equivalent/0x00013420.cpp
// sym: ?FUN_00013420@fn_ff0a839e@@YGXPAUItem@1@HHP6IX0@Z@Z @d901ab808a2f @wbc6c5b736b8f
// STATUS: equivalent (tools/equiv.py level 3: 2642 inputs, branch coverage 4/4)
// FUN_00013420 @ 0x00013420
void __stdcall FUN_00013420(Item *items, int stride, int count, ItemCallback callback)
{
    char *end = (char *)items + stride * count;
    for (int i = 0; i < count; ++i) {
        end -= stride;
        callback((Item *)end);
    }
}

} // namespace fn_ff0a839e

// 0x000134e0 FUN_000134e0 (25 B): matches/0x000134e0.cpp
// sym: ?FUN_000134e0@C_134e0@owners@@QAEHXZ
int owners::C_134e0::FUN_000134e0() {
    return value == 2 || value == 3;
}

namespace fn_ff0a839e {

// 0x00013840 FUN_00013840 (8 B): matches/0x00013840.cpp
// sym: ?Forward@O_13840@fn_ff0a839e@@QAEXH@Z
void O_13840::Forward(int a0) {
    ((owners::Target_22be40 *)(((Sub_13840*)((char*)this + 0x18))))->FUN_0022be40((const int *)(hulk_uintptr)(int)a0);
}


// 0x00013880 FUN_00013880 (8 B): matches/0x00013880.cpp
// sym: ?Target@Obj_13880@fn_ff0a839e@@QAEXH@Z
void Obj_13880::Target(int a0) {
    sub.Fn(a0);
}


// 0x00013890 FUN_00013890 (8 B): matches/0x00013890.cpp
// sym: ?F@Obj_13890@fn_ff0a839e@@QAEXH@Z
void Obj_13890::F(int a0) {
    ((Sub_13890*)((char*)this + 0x18))->G(a0);
}

} // namespace fn_ff0a839e
