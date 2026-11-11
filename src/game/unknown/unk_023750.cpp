// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00023750..0x000240b0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f88922b7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f88922b7 {} using namespace fn_f88922b7;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f88922b7 {
struct Vec3 {
    float x, y, z;
    Vec3& operator-=(const Vec3& v);
};
class Obj_23830 {
  public:
    char pad[0x1ac];
    int m;
    int Set(int x);
};
typedef unsigned int U_238b0;
typedef unsigned __int64 U64_238b0;
} // namespace fn_f88922b7
extern U64_238b0 __cdecl FUN_0027b020(U_238b0);
namespace fn_f88922b7 {
class Obj_23c50 {
  public:
    char pad[0x1d40];
    unsigned char member;
    void Fn(unsigned char x);
};
typedef unsigned __int64 u64_23d30;
extern "C" u64_23d30 __cdecl FUN_0027afb0(const char* name);
struct Obj_23d30 {
    char pad[0x1b40];
    u64_23d30 value;
};
struct Sub_23e50 {
    void* Run();
};
struct Obj_23e50 {
    char pad[0x80];
    Sub_23e50 sub;
    void* Target();
};
class Obj_23e60 {
  public:
    char pad[0x80];
    void Helper();
    void Target();
};
struct Pair {
    unsigned a, b;
};
} // namespace fn_f88922b7
extern "C" Pair __cdecl FUN_002672f0(int, int, int);
namespace fn_f88922b7 {
class Obj {
  public:
    char _m_pad_0[0x118];
    __int64 value;
    int Fn(hulk_intptr);
    int Next(Pair);
    __int64 Get();
};
class Obj_24000 {
  public:
    void SetX(char c);
    char pad[0xf4];
};


// 0x00023750 FUN_00023750 (33 B): matches/0x00023750.cpp
// sym: ??ZVec3@fn_f88922b7@@QAEAAU01@ABU01@@Z
Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}


// 0x00023830 FUN_00023830 (13 B): matches/0x00023830.cpp
// sym: ?Set@Obj_23830@fn_f88922b7@@QAEHH@Z
int Obj_23830::Set(int x) {
    m = x;
    return x;
}

} // namespace fn_f88922b7

// 0x000238b0 FUN_000238b0 (29 B): matches/0x000238b0.cpp
// sym: ?FUN_000238b0@Obj_238b0@owners@@QAEHI@Z
hulk_intptr owners::Obj_238b0::FUN_000238b0(hulk_uintptr param) {
    U64_238b0 a = FUN_0027b020(((U_238b0)param));
    return Second(a);
}

namespace fn_f88922b7 {

// 0x00023c50 FUN_00023c50 (13 B): matches/0x00023c50.cpp
// sym: ?Fn@Obj_23c50@fn_f88922b7@@QAEXE@Z
void Obj_23c50::Fn(unsigned char x) {
    member = x;
}


// 0x00023c90 FUN_00023c90 (3 B): matches/0x00023c90.cpp
// sym: ?FUN_00023c90@fn_f88922b7@@YGXH@Z
void __stdcall FUN_00023c90(int x) {}


// 0x00023d30 FUN_00023d30 (32 B): matches/0x00023d30.cpp
// sym: ?target@fn_f88922b7@@YIXPAUObj_23d30@1@PAXPBD@Z
// The name's hash key (0x0027afb0) kept at +0x1b40.
void __fastcall target(Obj_23d30* self, void*, const char* name) {
    self->value = FUN_0027afb0(name);
}


// 0x00023e50 FUN_00023e50 (11 B): matches/0x00023e50.cpp
// sym: ?Target@Obj_23e50@fn_f88922b7@@QAEPAXXZ
void* Obj_23e50::Target() {
    return sub.Run();
}


// 0x00023e60 FUN_00023e60 (11 B): matches/0x00023e60.cpp
// sym: ?Target@Obj_23e60@fn_f88922b7@@QAEXXZ
void Obj_23e60::Target() {
    ((Obj_23e60*)((char*)this + 0x80))->Helper();
}


// 0x00023e80 FUN_00023e80 (33 B): matches/0x00023e80.cpp
// sym: ?Fn@Obj@fn_f88922b7@@QAEHH@Z
int Obj::Fn(hulk_intptr x) {
    Pair p = FUN_002672f0(x, 0, 0);
    return Next(p);
}


// 0x00024000 FUN_00024000 (13 B): matches/0x00024000.cpp
// sym: ?SetX@Obj_24000@fn_f88922b7@@QAEXD@Z
void Obj_24000::SetX(char c) {
    pad[0xf4] = c;
}


// 0x00024010 FUN_00024010 (13 B): matches/0x00024010.cpp
// sym: ?Get@Obj@fn_f88922b7@@QAE_JXZ
__int64 Obj::Get() {
    return value;
}

} // namespace fn_f88922b7
