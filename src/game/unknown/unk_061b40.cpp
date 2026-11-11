// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061b40..0x00061e30 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa748c45 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa748c45 {} using namespace fn_fa748c45;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fa748c45 {
struct S {
    int a;
    int b;
    int c;
};
class A {
  public:
    char pad[0x98];
    int m1;
    int m2;
    int m3;
    bool Set(const S* p);
};
struct Vec3 {
  public:
    union { unsigned a; int x; };
    union { unsigned b; int y; };
    union { unsigned c; int z; };
};
class Obj {
  public:
    char _m_pad_0[0xa4];
    int m1;
    int m2;
    union { unsigned a; int m3; };
    unsigned b;
    unsigned c;
    bool Set(Src* s);
    bool Set(const Vec3* o);
};
class Thing {
  public:
    char pad[0xb8];
    Vec3 v;
    bool Fn(Vec3* p);
};
struct V {
    int a;
    int b;
    int c;
};
class T_61cf0 {
  public:
    char f(V* v);
    char pad[0x2c];
    int x2c;
    int x30;
    int x34;
};
struct V3_61d30 {
    int x, y, z;
};
class Obj_61d30 {
  public:
    char pad[0x4c];
    V3_61d30 v;
    bool Set(const V3_61d30* p);
};
struct T_61d90 {
    int a;
    int b;
    int c;
};
struct S_61d90 {
    char pad[0x2c];
    int x;
    int y;
    int z;
    bool Set(const T_61d90* p);
};

} // namespace fn_fa748c45

// 0x00061b40 FUN_00061b40 (12 B): matches/0x00061b40.cpp
// sym: ?FUN_00061b40@X_61b40@owners@@QAEDH@Z
char owners::X_61b40::FUN_00061b40(int a) {
    m = a;
    return 1;
}


// 0x00061b50 FUN_00061b50 (12 B): matches/0x00061b50.cpp
// sym: ?FUN_00061b50@C_61b50@owners@@QAE_NH@Z
bool owners::C_61b50::FUN_00061b50(int a) {
    m10 = a;
    return true;
}


// 0x00061b60 FUN_00061b60 (12 B): matches/0x00061b60.cpp
// sym: ?FUN_00061b60@Obj_61b60@owners@@QAE_NH@Z
bool owners::Obj_61b60::FUN_00061b60(int x) {
    m14 = x;
    return true;
}


// 0x00061b70 FUN_00061b70 (12 B): matches/0x00061b70.cpp
// sym: ?FUN_00061b70@Obj_61b70@owners@@QAE_NI@Z
bool owners::Obj_61b70::FUN_00061b70(unsigned int x) {
    mValue = x;
    return true;
}


// 0x00061b80 FUN_00061b80 (12 B): matches/0x00061b80.cpp
// sym: ?FUN_00061b80@X_61b80@owners@@QAEDH@Z
char owners::X_61b80::FUN_00061b80(int a) {
    m1c = a;
    return 1;
}


// 0x00061b90 FUN_00061b90 (12 B): matches/0x00061b90.cpp
// sym: ?FUN_00061b90@Obj_61b90@owners@@QAEDH@Z
char owners::Obj_61b90::FUN_00061b90(int x) {
    m20 = x;
    return 1;
}


// 0x00061ba0 FUN_00061ba0 (12 B): matches/0x00061ba0.cpp
// sym: ?FUN_00061ba0@Obj_61ba0@owners@@QAEDD@Z
char owners::Obj_61ba0::FUN_00061ba0(char v) {
    mFlag = v;
    return 1;
}


// 0x00061bb0 FUN_00061bb0 (12 B): matches/0x00061bb0.cpp
// sym: ?FUN_00061bb0@X_61bb0@owners@@QAEDH@Z
char owners::X_61bb0::FUN_00061bb0(int v) {
    m = v;
    return 1;
}


// 0x00061bc0 FUN_00061bc0 (15 B): matches/0x00061bc0.cpp
// sym: ?FUN_00061bc0@C_61bc0@owners@@QAE_NH@Z
bool owners::C_61bc0::FUN_00061bc0(int x) {
    m90 = x;
    return true;
}


// 0x00061bd0 FUN_00061bd0 (15 B): matches/0x00061bd0.cpp
// sym: ?FUN_00061bd0@Obj_61bd0@owners@@QAE_NH@Z
bool owners::Obj_61bd0::FUN_00061bd0(int x) {
    value = x;
    return true;
}

namespace fn_fa748c45 {

// 0x00061be0 FUN_00061be0 (35 B): matches/0x00061be0.cpp
// sym: ?Set@A@fn_fa748c45@@QAE_NPBUS@2@@Z
bool A::Set(const S* p) {
    m1 = p->a;
    m2 = p->b;
    m3 = p->c;
    return true;
}


// 0x00061c10 FUN_00061c10 (35 B): matches/0x00061c10.cpp
// sym: ?Set@Obj@fn_fa748c45@@QAE_NPAUSrc@2@@Z
bool Obj::Set(Src* s) {
    m1 = s->a;
    m2 = s->b;
    m3 = s->c;
    return true;
}

} // namespace fn_fa748c45

// 0x00061c40 FUN_00061c40 (15 B): matches/0x00061c40.cpp
// sym: ?FUN_00061c40@T_61c40@owners@@QAE_NH@Z
bool owners::T_61c40::FUN_00061c40(int v) {
    value = v;
    return true;
}


// 0x00061c50 FUN_00061c50 (15 B): matches/0x00061c50.cpp
// sym: ?FUN_00061c50@Obj_61c50@owners@@QAEDH@Z
char owners::Obj_61c50::FUN_00061c50(int v) {
    Value = v;
    return 1;
}

namespace fn_fa748c45 {

// 0x00061c60 FUN_00061c60 (35 B): matches/0x00061c60.cpp
// sym: ?Fn@Thing@fn_fa748c45@@QAE_NPAUVec3@2@@Z
bool Thing::Fn(Vec3* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}

} // namespace fn_fa748c45

// 0x00061c90 FUN_00061c90 (15 B): matches/0x00061c90.cpp
// sym: ?FUN_00061c90@Obj_61c90@owners@@QAE_NH@Z
bool owners::Obj_61c90::FUN_00061c90(int x) {
    m1c4 = x;
    return true;
}


// 0x00061ca0 FUN_00061ca0 (15 B): matches/0x00061ca0.cpp
// sym: ?FUN_00061ca0@X_61ca0@owners@@QAEDH@Z
char owners::X_61ca0::FUN_00061ca0(int v) {
    value = v;
    return 1;
}


// 0x00061cb0 FUN_00061cb0 (12 B): matches/0x00061cb0.cpp
// sym: ?FUN_00061cb0@Obj_61cb0@owners@@QAE_NPAX@Z
bool owners::Obj_61cb0::FUN_00061cb0(void* p) {
    mPtr = p;
    return true;
}


// 0x00061cc0 FUN_00061cc0 (12 B): matches/0x00061cc0.cpp
// sym: ?FUN_00061cc0@Obj_61cc0@owners@@QAE_NH@Z
bool owners::Obj_61cc0::FUN_00061cc0(int v) {
    value = v;
    return true;
}


// 0x00061cd0 FUN_00061cd0 (12 B): matches/0x00061cd0.cpp
// sym: ?FUN_00061cd0@C_61cd0@owners@@QAEDH@Z
char owners::C_61cd0::FUN_00061cd0(int x) {
    m = x;
    return 1;
}


// 0x00061ce0 FUN_00061ce0 (12 B): matches/0x00061ce0.cpp
// sym: ?FUN_00061ce0@Obj_61ce0@owners@@QAEDD@Z
char owners::Obj_61ce0::FUN_00061ce0(char v) {
    m28 = v;
    return 1;
}

namespace fn_fa748c45 {

// 0x00061cf0 FUN_00061cf0 (26 B): matches/0x00061cf0.cpp
// sym: ?f@T_61cf0@fn_fa748c45@@QAEDPAUV@2@@Z
char T_61cf0::f(V* v) {
    x2c = v->a;
    x30 = v->b;
    x34 = v->c;
    return 1;
}

} // namespace fn_fa748c45

// 0x00061d10 FUN_00061d10 (12 B): matches/0x00061d10.cpp
// sym: ?FUN_00061d10@Obj_61d10@owners@@QAE_ND@Z
bool owners::Obj_61d10::FUN_00061d10(char v) {
    flag = v;
    return true;
}


// 0x00061d20 FUN_00061d20 (12 B): matches/0x00061d20.cpp
// sym: ?FUN_00061d20@C_61d20@owners@@QAE_NH@Z
bool owners::C_61d20::FUN_00061d20(int v) {
    m44 = v;
    return true;
}

namespace fn_fa748c45 {

// 0x00061d30 FUN_00061d30 (26 B): matches/0x00061d30.cpp
// sym: ?Set@Obj_61d30@fn_fa748c45@@QAE_NPBUV3_61d30@2@@Z
bool Obj_61d30::Set(const V3_61d30* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}

} // namespace fn_fa748c45

// 0x00061d50 FUN_00061d50 (12 B): matches/0x00061d50.cpp
// sym: ?FUN_00061d50@Obj_61d50@owners@@QAE_NH@Z
bool owners::Obj_61d50::FUN_00061d50(int value) {
    mValue = value;
    return true;
}


// 0x00061d60 FUN_00061d60 (12 B): matches/0x00061d60.cpp
// sym: ?FUN_00061d60@Obj_61d60@owners@@QAE_NH@Z
bool owners::Obj_61d60::FUN_00061d60(int v) {
    m = v;
    return true;
}


// 0x00061d70 FUN_00061d70 (12 B): matches/0x00061d70.cpp
// sym: ?FUN_00061d70@C_61d70@owners@@QAE_NH@Z
bool owners::C_61d70::FUN_00061d70(int x) {
    m = x;
    return true;
}


// 0x00061d80 FUN_00061d80 (12 B): matches/0x00061d80.cpp
// sym: ?FUN_00061d80@Obj_61d80@owners@@QAEEE@Z
unsigned char owners::Obj_61d80::FUN_00061d80(unsigned char b) {
    mFlag = b;
    return 1;
}

namespace fn_fa748c45 {

// 0x00061d90 FUN_00061d90 (26 B): matches/0x00061d90.cpp
// sym: ?Set@S_61d90@fn_fa748c45@@QAE_NPBUT_61d90@2@@Z
bool S_61d90::Set(const T_61d90* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}

} // namespace fn_fa748c45

// 0x00061db0 FUN_00061db0 (12 B): matches/0x00061db0.cpp
// sym: ?FUN_00061db0@X_61db0@owners@@QAEDH@Z
char owners::X_61db0::FUN_00061db0(int arg) {
    m = arg;
    return 1;
}


// 0x00061dc0 FUN_00061dc0 (12 B): matches/0x00061dc0.cpp
// sym: ?FUN_00061dc0@O_61dc0@owners@@QAEDH@Z
char owners::O_61dc0::FUN_00061dc0(int a) {
    mC = a;
    return 1;
}


// 0x00061dd0 FUN_00061dd0 (15 B): matches/0x00061dd0.cpp
// sym: ?FUN_00061dd0@T_61dd0@owners@@QAEDD@Z
char owners::T_61dd0::FUN_00061dd0(char x) {
    Value = x;
    return 1;
}

namespace fn_fa748c45 {

// 0x00061de0 FUN_00061de0 (35 B): matches/0x00061de0.cpp
// sym: ?Set@Obj@fn_fa748c45@@QAE_NPBUVec3@2@@Z
bool Obj::Set(const Vec3* o) {
    a = o->a;
    b = o->b;
    c = o->c;
    return 1;
}

} // namespace fn_fa748c45

// 0x00061e10 FUN_00061e10 (15 B): matches/0x00061e10.cpp
// sym: ?FUN_00061e10@Obj_61e10@owners@@QAE_NH@Z
bool owners::Obj_61e10::FUN_00061e10(int x) {
    m = x;
    return true;
}


// 0x00061e20 FUN_00061e20 (15 B): matches/0x00061e20.cpp
// sym: ?FUN_00061e20@Obj_61e20@owners@@QAE_NH@Z
bool owners::Obj_61e20::FUN_00061e20(int x) {
    value = x;
    return true;
}

