// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0011b800..0x0011c310 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f18cc536 {
#define TREE_TU_END }
namespace fn_f18cc536 {} using namespace fn_f18cc536;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f18cc536 {
class Obj_11b8e0 {
  public:
    char pad[0x1d];
    unsigned char value;
    unsigned char Get();
};
class Obj_11b900 {
  public:
    char pad[0x1e];
    unsigned char value;
    unsigned char Get();
};
struct Src_11b960 {
    int a, b, c;
};
class Obj_11b960 {
  public:
    char pad[0x20];
    int x;
    int y;
    int z;
    bool Set(Src_11b960* s);
};
class X_11b9c0 {
  public:
    float Get();
    char pad[0x18];
};
class Obj_11bd30 {
  public:
    char pad[0xc];
    int m;
    char Fn(int x);
};
class Obj_11bd40 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
class Obj_11bd50 {
  public:
    char pad[0x14];
    unsigned int mVal;
    unsigned char Set(unsigned int v);
};
extern "C" const float g_deg2rad = 0.017453292f;
struct Obj_11bd60 {
    char pad[0x18];
    float value;
    bool Set(float v);
};
class Obj_11bd90 {
  public:
    char pad[0x1c];
    int m1c;
    char SetVal(int x);
};
class Obj_11bdb0 {
  public:
    virtual void V0();
    char Set(int value);
    char pad[0x1c];
    int mValue;
};
class C_11bdd0 {
  public:
    char pad[0x24];
    int mVal;
    bool Set(int x);
};
class Thing_11be00 {
  public:
    char pad[0x14];
    float value;
    float Get();
};
extern const float k_11c010 = 0.017453292f;
struct S_11c100 {
    char pad[0x40];
    char* Get() { return (char*)this + 0x40; }
};
extern int* gTable_11c210;
class CCondition_11c210 {
  public:
    virtual int vfunc_0(int);
};
class PathLocatorTestCondition {
  public:
    int a, b;
    virtual ~PathLocatorTestCondition();
    int d;
    virtual void hulk_slot_F(); void F();
};
extern "C" unsigned int __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);

} // namespace fn_f18cc536

// 0x0011b810 FUN_0011b810 (12 B): matches/0x0011b810.cpp
// sym: ?FUN_0011b810@Obj_11b810@owners@@QAEDH@Z
char owners::Obj_11b810::FUN_0011b810(int x) {
    field = x;
    return 1;
}


// 0x0011b830 FUN_0011b830 (12 B): matches/0x0011b830.cpp
// sym: ?FUN_0011b830@Obj_11b830@owners@@QAEDH@Z
char owners::Obj_11b830::FUN_0011b830(int v) {
    mVal = v;
    return 1;
}


// 0x0011b850 FUN_0011b850 (12 B): matches/0x0011b850.cpp
// sym: ?FUN_0011b850@Obj_11b850@owners@@QAEDE@Z
char owners::Obj_11b850::FUN_0011b850(unsigned char value) {
    m18 = value;
    return 1;
}


// 0x0011b870 FUN_0011b870 (12 B): matches/0x0011b870.cpp
// sym: ?FUN_0011b870@C_11b870@owners@@QAEDD@Z
char owners::C_11b870::FUN_0011b870(char c) {
    m[0x19] = c;
    return 1;
}


// 0x0011b890 FUN_0011b890 (12 B): matches/0x0011b890.cpp
// sym: ?FUN_0011b890@X_11b890@owners@@QAEDD@Z
char owners::X_11b890::FUN_0011b890(char v) {
    mValue = v;
    return 1;
}


// 0x0011b8b0 FUN_0011b8b0 (12 B): matches/0x0011b8b0.cpp
// sym: ?FUN_0011b8b0@O_11b8b0@owners@@QAEEE@Z
unsigned char owners::O_11b8b0::FUN_0011b8b0(unsigned char x) {
    p[0x1b] = x;
    return 1;
}


// 0x0011b8d0 FUN_0011b8d0 (12 B): matches/0x0011b8d0.cpp
// sym: ?FUN_0011b8d0@X_11b8d0@owners@@QAEDD@Z
char owners::X_11b8d0::FUN_0011b8d0(char c) {
    m = c;
    return 1;
}

namespace fn_f18cc536 {

// 0x0011b8e0 FUN_0011b8e0 (4 B): matches/0x0011b8e0.cpp
// sym: ?Get@Obj_11b8e0@fn_f18cc536@@QAEEXZ
unsigned char Obj_11b8e0::Get() {
    return value;
}

} // namespace fn_f18cc536

// 0x0011b8f0 FUN_0011b8f0 (12 B): matches/0x0011b8f0.cpp
// sym: ?FUN_0011b8f0@X_11b8f0@owners@@QAEEE@Z
unsigned char owners::X_11b8f0::FUN_0011b8f0(unsigned char v) {
    m1d = v;
    return 1;
}

namespace fn_f18cc536 {

// 0x0011b900 FUN_0011b900 (4 B): matches/0x0011b900.cpp
// sym: ?Get@Obj_11b900@fn_f18cc536@@QAEEXZ
unsigned char Obj_11b900::Get() {
    return value;
}

} // namespace fn_f18cc536

// 0x0011b910 FUN_0011b910 (12 B): matches/0x0011b910.cpp
// sym: ?FUN_0011b910@X_11b910@owners@@QAEDD@Z
char owners::X_11b910::FUN_0011b910(char v) {
    m[0x1e] = v;
    return 1;
}


// 0x0011b930 FUN_0011b930 (12 B): matches/0x0011b930.cpp
// sym: ?FUN_0011b930@Obj_11b930@owners@@QAE_N_N@Z
bool owners::Obj_11b930::FUN_0011b930(bool x) {
    mFlag = x;
    return true;
}

namespace fn_f18cc536 {

// 0x0011b960 FUN_0011b960 (26 B): matches/0x0011b960.cpp
// sym: ?Set@Obj_11b960@fn_f18cc536@@QAE_NPAUSrc_11b960@2@@Z
bool Obj_11b960::Set(Src_11b960* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return true;
}

} // namespace fn_f18cc536

// 0x0011b980 FUN_0011b980 (12 B): matches/0x0011b980.cpp
// sym: ?FUN_0011b980@Obj_11b980@owners@@QAE_NH@Z
bool owners::Obj_11b980::FUN_0011b980(int v) {
    mValue = v;
    return true;
}


// 0x0011b990 FUN_0011b990 (12 B): matches/0x0011b990.cpp
// sym: ?FUN_0011b990@Obj_11b990@owners@@QAEDH@Z
char owners::Obj_11b990::FUN_0011b990(int value) {
    m10 = value;
    return 1;
}


// 0x0011b9a0 FUN_0011b9a0 (18 B): matches/0x0011b9a0.cpp
// sym: ?FUN_0011b9a0@Obj_11b9a0@owners@@QAEDM@Z
char owners::Obj_11b9a0::FUN_0011b9a0(float x) {
    angle = x * 0.017453292f;
    return 1;
}

namespace fn_f18cc536 {

// 0x0011b9c0 FUN_0011b9c0 (4 B): matches/0x0011b9c0.cpp
// sym: ?Get@X_11b9c0@fn_f18cc536@@QAEMXZ
float X_11b9c0::Get() {
    return *(float*)((char*)this + 0x18);
}

} // namespace fn_f18cc536

// 0x0011b9d0 FUN_0011b9d0 (12 B): matches/0x0011b9d0.cpp
// sym: ?FUN_0011b9d0@Obj_11b9d0@owners@@QAE_NH@Z
bool owners::Obj_11b9d0::FUN_0011b9d0(int x) {
    m18 = x;
    return true;
}


// 0x0011b9f0 FUN_0011b9f0 (12 B): matches/0x0011b9f0.cpp
// sym: ?FUN_0011b9f0@Obj_11b9f0@owners@@QAEDH@Z
char owners::Obj_11b9f0::FUN_0011b9f0(int value) {
    mValue = value;
    return 1;
}


// 0x0011ba10 FUN_0011ba10 (12 B): matches/0x0011ba10.cpp
// sym: ?FUN_0011ba10@Obj_11ba10@owners@@QAE_NH@Z
bool owners::Obj_11ba10::FUN_0011ba10(int value) {
    m20 = value;
    return true;
}


// 0x0011ba30 FUN_0011ba30 (12 B): matches/0x0011ba30.cpp
// sym: ?FUN_0011ba30@Obj_11ba30@owners@@QAE_NH@Z
bool owners::Obj_11ba30::FUN_0011ba30(int v) {
    mVal = v;
    return true;
}


// 0x0011ba50 FUN_0011ba50 (12 B): matches/0x0011ba50.cpp
// sym: ?FUN_0011ba50@Obj_11ba50@owners@@QAEDD@Z
char owners::Obj_11ba50::FUN_0011ba50(char a) {
    m[0x28] = a;
    return 1;
}


// 0x0011ba70 FUN_0011ba70 (12 B): matches/0x0011ba70.cpp
// sym: ?FUN_0011ba70@C_11ba70@owners@@QAEDH@Z
char owners::C_11ba70::FUN_0011ba70(int x) {
    m = x;
    return 1;
}


// 0x0011ba90 FUN_0011ba90 (12 B): matches/0x0011ba90.cpp
// sym: ?FUN_0011ba90@Obj_11ba90@owners@@QAEDH@Z
char owners::Obj_11ba90::FUN_0011ba90(int x) {
    m30 = x;
    return 1;
}


// 0x0011bab0 FUN_0011bab0 (12 B): matches/0x0011bab0.cpp
// sym: ?FUN_0011bab0@Obj_11bab0@owners@@QAE_NH@Z
bool owners::Obj_11bab0::FUN_0011bab0(int x) {
    value = x;
    char f = 1;
    return (bool)f;
}


// 0x0011bac0 FUN_0011bac0 (12 B): matches/0x0011bac0.cpp
// sym: ?FUN_0011bac0@X_11bac0@owners@@QAE_NH@Z
bool owners::X_11bac0::FUN_0011bac0(int value) {
    m38 = value;
    return true;
}


// 0x0011bad0 FUN_0011bad0 (12 B): matches/0x0011bad0.cpp
// sym: ?FUN_0011bad0@Obj_11bad0@owners@@QAEDH@Z
char owners::Obj_11bad0::FUN_0011bad0(int a) {
    value = a;
    return 1;
}


// 0x0011bae0 FUN_0011bae0 (12 B): matches/0x0011bae0.cpp
// sym: ?FUN_0011bae0@T_11bae0@owners@@QAEDH@Z
char owners::T_11bae0::FUN_0011bae0(int v) {
    m10 = v;
    return 1;
}


// 0x0011baf0 FUN_0011baf0 (12 B): matches/0x0011baf0.cpp
// sym: ?FUN_0011baf0@X_11baf0@owners@@QAE_NH@Z
bool owners::X_11baf0::FUN_0011baf0(int v) {
    m14 = v;
    return true;
}


// 0x0011bb00 FUN_0011bb00 (18 B): matches/0x0011bb00.cpp
// sym: ?FUN_0011bb00@X_11bb00@owners@@QAE_NM@Z
bool owners::X_11bb00::FUN_0011bb00(float degrees) {
    value = degrees * 0.017453292f;
    return true;
}


// 0x0011bb20 FUN_0011bb20 (12 B): matches/0x0011bb20.cpp
// sym: ?FUN_0011bb20@Obj_11bb20@owners@@QAE_NH@Z
bool owners::Obj_11bb20::FUN_0011bb20(int v) {
    mValue = v;
    return true;
}


// 0x0011bb30 FUN_0011bb30 (12 B): matches/0x0011bb30.cpp
// sym: ?FUN_0011bb30@Obj_11bb30@owners@@QAE_NH@Z
bool owners::Obj_11bb30::FUN_0011bb30(int v) {
    m20 = v;
    return true;
}


// 0x0011bb40 FUN_0011bb40 (12 B): matches/0x0011bb40.cpp
// sym: ?FUN_0011bb40@Obj_11bb40@owners@@QAE_NH@Z
bool owners::Obj_11bb40::FUN_0011bb40(int v) {
    value = v;
    return true;
}


// 0x0011bb60 FUN_0011bb60 (12 B): matches/0x0011bb60.cpp
// sym: ?FUN_0011bb60@X_11bb60@owners@@QAE_NH@Z
bool owners::X_11bb60::FUN_0011bb60(int v) {
    value = v;
    return true;
}


// 0x0011bb80 FUN_0011bb80 (12 B): matches/0x0011bb80.cpp
// sym: ?FUN_0011bb80@Obj_11bb80@owners@@QAE_NH@Z
bool owners::Obj_11bb80::FUN_0011bb80(int x) {
    value = x;
    return true;
}


// 0x0011bba0 FUN_0011bba0 (12 B): matches/0x0011bba0.cpp
// sym: ?FUN_0011bba0@Target_11bba0@owners@@QAE_NH@Z
bool owners::Target_11bba0::FUN_0011bba0(int value) {
    m30 = value;
    return true;
}


// 0x0011bbc0 FUN_0011bbc0 (12 B): matches/0x0011bbc0.cpp
// sym: ?FUN_0011bbc0@X_11bbc0@owners@@QAE_NH@Z
bool owners::X_11bbc0::FUN_0011bbc0(int arg) {
    m = arg;
    return true;
}


// 0x0011bbd0 FUN_0011bbd0 (12 B): matches/0x0011bbd0.cpp
// sym: ?FUN_0011bbd0@Obj_11bbd0@owners@@QAE_NH@Z
bool owners::Obj_11bbd0::FUN_0011bbd0(int v) {
    m10 = v;
    return true;
}


// 0x0011bbf0 FUN_0011bbf0 (12 B): matches/0x0011bbf0.cpp
// sym: ?FUN_0011bbf0@Obj_11bbf0@owners@@QAEDH@Z
char owners::Obj_11bbf0::FUN_0011bbf0(int v) {
    mVal = v;
    return 1;
}


// 0x0011bc10 FUN_0011bc10 (18 B): matches/0x0011bc10.cpp
// sym: ?FUN_0011bc10@Obj_11bc10@owners@@QAEDM@Z
char owners::Obj_11bc10::FUN_0011bc10(float v) {
    mValue = v * 0.01745329252f;
    return 1;
}


// 0x0011bc40 FUN_0011bc40 (12 B): matches/0x0011bc40.cpp
// sym: ?FUN_0011bc40@Obj_11bc40@owners@@QAEDH@Z
char owners::Obj_11bc40::FUN_0011bc40(int x) {
    m1c = x;
    return 1;
}


// 0x0011bc60 FUN_0011bc60 (12 B): matches/0x0011bc60.cpp
// sym: ?FUN_0011bc60@X_11bc60@owners@@QAEDH@Z
char owners::X_11bc60::FUN_0011bc60(int v) {
    m = v;
    return 1;
}


// 0x0011bc80 FUN_0011bc80 (12 B): matches/0x0011bc80.cpp
// sym: ?FUN_0011bc80@Obj_11bc80@owners@@QAEDH@Z
char owners::Obj_11bc80::FUN_0011bc80(int v) {
    mValue = v;
    return 1;
}


// 0x0011bca0 FUN_0011bca0 (12 B): matches/0x0011bca0.cpp
// sym: ?FUN_0011bca0@Obj_11bca0@owners@@QAEDH@Z
char owners::Obj_11bca0::FUN_0011bca0(int v) {
    m28 = v;
    return 1;
}


// 0x0011bcc0 FUN_0011bcc0 (12 B): matches/0x0011bcc0.cpp
// sym: ?FUN_0011bcc0@Obj_11bcc0@owners@@QAEEE@Z
unsigned char owners::Obj_11bcc0::FUN_0011bcc0(unsigned char x) {
    value = x;
    return 1;
}


// 0x0011bce0 FUN_0011bce0 (12 B): matches/0x0011bce0.cpp
// sym: ?FUN_0011bce0@Obj_11bce0@owners@@QAEDD@Z
char owners::Obj_11bce0::FUN_0011bce0(char v) {
    m2d = v;
    return 1;
}


// 0x0011bd00 FUN_0011bd00 (12 B): matches/0x0011bd00.cpp
// sym: ?FUN_0011bd00@Obj_11bd00@owners@@QAE_NH@Z
bool owners::Obj_11bd00::FUN_0011bd00(int arg) {
    m30 = arg;
    return true;
}


// 0x0011bd20 FUN_0011bd20 (12 B): matches/0x0011bd20.cpp
// sym: ?FUN_0011bd20@A_11bd20@owners@@QAEDH@Z
char owners::A_11bd20::FUN_0011bd20(int v) {
    m34 = v;
    return 1;
}

namespace fn_f18cc536 {

// 0x0011bd30 FUN_0011bd30 (12 B): matches/0x0011bd30.cpp
// sym: ?Fn@Obj_11bd30@fn_f18cc536@@QAEDH@Z
char Obj_11bd30::Fn(int x) {
    m = x;
    return 1;
}


// 0x0011bd40 FUN_0011bd40 (12 B): matches/0x0011bd40.cpp
// sym: ?Set@Obj_11bd40@fn_f18cc536@@QAEDH@Z
char Obj_11bd40::Set(int x) {
    value = x;
    return 1;
}


// 0x0011bd50 FUN_0011bd50 (12 B): matches/0x0011bd50.cpp
// sym: ?Set@Obj_11bd50@fn_f18cc536@@QAEEI@Z
unsigned char Obj_11bd50::Set(unsigned int v) {
    mVal = v;
    return 1;
}


// 0x0011bd60 FUN_0011bd60 (18 B): matches/0x0011bd60.cpp
// sym: ?Set@Obj_11bd60@fn_f18cc536@@QAE_NM@Z
bool Obj_11bd60::Set(float v) {
    value = v * g_deg2rad;
    return true;
}


// 0x0011bd90 FUN_0011bd90 (12 B): matches/0x0011bd90.cpp
// sym: ?SetVal@Obj_11bd90@fn_f18cc536@@QAEDH@Z
char Obj_11bd90::SetVal(int x) {
    m1c = x;
    return 1;
}


// 0x0011bdb0 FUN_0011bdb0 (12 B): matches/0x0011bdb0.cpp
// sym: ?Set@Obj_11bdb0@fn_f18cc536@@QAEDH@Z
char Obj_11bdb0::Set(int value) {
    mValue = value;
    return 1;
}


// 0x0011bdd0 FUN_0011bdd0 (12 B): matches/0x0011bdd0.cpp
// sym: ?Set@C_11bdd0@fn_f18cc536@@QAE_NH@Z
bool C_11bdd0::Set(int x) {
    mVal = x;
    return true;
}

} // namespace fn_f18cc536

// 0x0011bde0 FUN_0011bde0 (12 B): matches/0x0011bde0.cpp
// sym: ?FUN_0011bde0@Obj_11bde0@owners@@QAE_NH@Z
bool owners::Obj_11bde0::FUN_0011bde0(int v) {
    m = v;
    return true;
}


// 0x0011bdf0 FUN_0011bdf0 (12 B): matches/0x0011bdf0.cpp
// sym: ?FUN_0011bdf0@Obj_11bdf0@owners@@QAE_NH@Z
bool owners::Obj_11bdf0::FUN_0011bdf0(int v) {
    mValue = v;
    return true;
}

namespace fn_f18cc536 {

// 0x0011be00 FUN_0011be00 (4 B): matches/0x0011be00.cpp
// sym: ?Get@Thing_11be00@fn_f18cc536@@QAEMXZ
float Thing_11be00::Get() {
    return value;
}

} // namespace fn_f18cc536

// 0x0011be10 FUN_0011be10 (12 B): matches/0x0011be10.cpp
// sym: ?FUN_0011be10@Obj_11be10@owners@@QAEDH@Z
char owners::Obj_11be10::FUN_0011be10(int x) {
    mValue = x;
    return 1;
}


// 0x0011be30 FUN_0011be30 (12 B): matches/0x0011be30.cpp
// sym: ?FUN_0011be30@Obj_11be30@owners@@QAE_NH@Z
bool owners::Obj_11be30::FUN_0011be30(int x) {
    value = x;
    return true;
}


// 0x0011be50 FUN_0011be50 (12 B): matches/0x0011be50.cpp
// sym: ?FUN_0011be50@Obj_11be50@owners@@QAEDH@Z
char owners::Obj_11be50::FUN_0011be50(int value) {
    mValue = value;
    return 1;
}


// 0x0011be70 FUN_0011be70 (12 B): matches/0x0011be70.cpp
// sym: ?FUN_0011be70@Obj_11be70@owners@@QAE_NH@Z
bool owners::Obj_11be70::FUN_0011be70(int x) {
    m20 = x;
    return true;
}


// 0x0011be90 FUN_0011be90 (12 B): matches/0x0011be90.cpp
// sym: ?FUN_0011be90@X_11be90@owners@@QAEDH@Z
char owners::X_11be90::FUN_0011be90(int a) {
    *(int*)((char*)this + 0x24) = a;
    return 1;
}


// 0x0011bea0 FUN_0011bea0 (12 B): matches/0x0011bea0.cpp
// sym: ?FUN_0011bea0@Obj_11bea0@owners@@QAEDH@Z
char owners::Obj_11bea0::FUN_0011bea0(int x) {
    mValue = x;
    return 1;
}


// 0x0011beb0 FUN_0011beb0 (12 B): matches/0x0011beb0.cpp
// sym: ?FUN_0011beb0@Obj_11beb0@owners@@QAE_NH@Z
bool owners::Obj_11beb0::FUN_0011beb0(int v) {
    m10 = v;
    return true;
}


// 0x0011bed0 FUN_0011bed0 (12 B): matches/0x0011bed0.cpp
// sym: ?FUN_0011bed0@X_11bed0@owners@@QAEDH@Z
char owners::X_11bed0::FUN_0011bed0(int a) {
    m14 = a;
    return 1;
}


// 0x0011bef0 FUN_0011bef0 (12 B): matches/0x0011bef0.cpp
// sym: ?FUN_0011bef0@Obj_11bef0@owners@@QAE_NH@Z
bool owners::Obj_11bef0::FUN_0011bef0(int x) {
    value = x;
    return true;
}


// 0x0011bf10 FUN_0011bf10 (12 B): matches/0x0011bf10.cpp
// sym: ?FUN_0011bf10@Obj_11bf10@owners@@QAEDH@Z
char owners::Obj_11bf10::FUN_0011bf10(int v) {
    m1c = v;
    return 1;
}


// 0x0011bf30 FUN_0011bf30 (12 B): matches/0x0011bf30.cpp
// sym: ?FUN_0011bf30@Obj_11bf30@owners@@QAEDH@Z
char owners::Obj_11bf30::FUN_0011bf30(int v) {
    mX = v;
    return 1;
}


// 0x0011bf50 FUN_0011bf50 (12 B): matches/0x0011bf50.cpp
// sym: ?FUN_0011bf50@Obj_11bf50@owners@@QAE_NH@Z
bool owners::Obj_11bf50::FUN_0011bf50(int x) {
    mX = x;
    return true;
}


// 0x0011bf70 FUN_0011bf70 (12 B): matches/0x0011bf70.cpp
// sym: ?FUN_0011bf70@Obj_11bf70@owners@@QAE_NH@Z
bool owners::Obj_11bf70::FUN_0011bf70(int x) {
    value = x;
    return true;
}


// 0x0011bf90 FUN_0011bf90 (12 B): matches/0x0011bf90.cpp
// sym: ?FUN_0011bf90@Obj_11bf90@owners@@QAEDD@Z
char owners::Obj_11bf90::FUN_0011bf90(char value) {
    mFlag = value;
    return 1;
}


// 0x0011bfb0 FUN_0011bfb0 (12 B): matches/0x0011bfb0.cpp
// sym: ?FUN_0011bfb0@Obj_11bfb0@owners@@QAEEH@Z
unsigned char owners::Obj_11bfb0::FUN_0011bfb0(int x) {
    value = x;
    return 1;
}


// 0x0011bfc0 FUN_0011bfc0 (12 B): matches/0x0011bfc0.cpp
// sym: ?FUN_0011bfc0@Obj_11bfc0@owners@@QAEDD@Z
char owners::Obj_11bfc0::FUN_0011bfc0(char c) {
    m34 = c;
    return 1;
}


// 0x0011bfd0 FUN_0011bfd0 (12 B): matches/0x0011bfd0.cpp
// sym: ?FUN_0011bfd0@X_11bfd0@owners@@QAEDH@Z
char owners::X_11bfd0::FUN_0011bfd0(int a) {
    m = a;
    return 1;
}


// 0x0011bfe0 FUN_0011bfe0 (12 B): matches/0x0011bfe0.cpp
// sym: ?FUN_0011bfe0@Obj_11bfe0@owners@@QAEDH@Z
char owners::Obj_11bfe0::FUN_0011bfe0(int x) {
    mVal = x;
    return 1;
}


// 0x0011c000 FUN_0011c000 (12 B): matches/0x0011c000.cpp
// sym: ?FUN_0011c000@Obj_11c000@owners@@QAEDH@Z
char owners::Obj_11c000::FUN_0011c000(int v) {
    m14 = v;
    return 1;
}


// 0x0011c010 FUN_0011c010 (18 B): matches/0x0011c010.cpp
// sym: ?FUN_0011c010@Obj_11c010@owners@@QAEDM@Z
char owners::Obj_11c010::FUN_0011c010(float f) {
    mValue = f * k_11c010;
    return 1;
}


// 0x0011c030 FUN_0011c030 (12 B): matches/0x0011c030.cpp
// sym: ?FUN_0011c030@X_11c030@owners@@QAE_NH@Z
bool owners::X_11c030::FUN_0011c030(int v) {
    value = v;
    return true;
}


// 0x0011c040 FUN_0011c040 (12 B): matches/0x0011c040.cpp
// sym: ?FUN_0011c040@Obj_11c040@owners@@QAEDH@Z
char owners::Obj_11c040::FUN_0011c040(int value) {
    *(int*)((char*)this + 0x20) = value;
    return 1;
}


// 0x0011c050 FUN_0011c050 (12 B): matches/0x0011c050.cpp
// sym: ?FUN_0011c050@Obj_11c050@owners@@QAEDH@Z
char owners::Obj_11c050::FUN_0011c050(int value) {
    m24 = value;
    return 1;
}


// 0x0011c060 FUN_0011c060 (12 B): matches/0x0011c060.cpp
// sym: ?FUN_0011c060@Obj_11c060@owners@@QAE_NPAX@Z
bool owners::Obj_11c060::FUN_0011c060(void* v) {
    mVal = v;
    return 1;
}


// 0x0011c070 FUN_0011c070 (12 B): matches/0x0011c070.cpp
// sym: ?FUN_0011c070@Obj_11c070@owners@@QAE_NH@Z
bool owners::Obj_11c070::FUN_0011c070(int x) {
    value = x;
    return true;
}


// 0x0011c080 FUN_0011c080 (12 B): matches/0x0011c080.cpp
// sym: ?FUN_0011c080@Obj_11c080@owners@@QAE_NH@Z
bool owners::Obj_11c080::FUN_0011c080(int x) {
    m30 = x;
    return true;
}


// 0x0011c0a0 FUN_0011c0a0 (12 B): matches/0x0011c0a0.cpp
// sym: ?FUN_0011c0a0@Obj_11c0a0@owners@@QAEDH@Z
char owners::Obj_11c0a0::FUN_0011c0a0(int v) {
    mVal = v;
    return 1;
}


// 0x0011c0f0 FUN_0011c0f0 (12 B): matches/0x0011c0f0.cpp
// sym: ?FUN_0011c0f0@X_11c0f0@owners@@QAEDH@Z
char owners::X_11c0f0::FUN_0011c0f0(int v) {
    field = (char)v;
    return 1;
}

namespace fn_f18cc536 {

// 0x0011c100 FUN_0011c100 (4 B): matches/0x0011c100.cpp
// sym: ?FUN_0011c100@fn_f18cc536@@YIPADPAUS_11c100@1@@Z
char* __fastcall FUN_0011c100(S_11c100* self) {
    return self->Get();
}

} // namespace fn_f18cc536

// 0x0011c120 FUN_0011c120 (12 B): matches/0x0011c120.cpp
// sym: ?FUN_0011c120@Obj_11c120@owners@@QAEEE@Z
unsigned char owners::Obj_11c120::FUN_0011c120(unsigned char value) {
    field = value;
    return 1;
}


// 0x0011c140 FUN_0011c140 (12 B): matches/0x0011c140.cpp
// sym: ?FUN_0011c140@O_11c140@owners@@QAEDD@Z
char owners::O_11c140::FUN_0011c140(char v) {
    value = v;
    return 1;
}


// 0x0011c160 FUN_0011c160 (12 B): matches/0x0011c160.cpp
// sym: ?FUN_0011c160@Obj_11c160@owners@@QAE_NH@Z
bool owners::Obj_11c160::FUN_0011c160(int x) {
    value = x;
    return true;
}


// 0x0011c180 FUN_0011c180 (12 B): matches/0x0011c180.cpp
// sym: ?FUN_0011c180@A_11c180@owners@@QAE_NH@Z
bool owners::A_11c180::FUN_0011c180(int v) throw() {
    mValue = v;
    return true;
}


// 0x0011c1a0 FUN_0011c1a0 (12 B): matches/0x0011c1a0.cpp
// sym: ?FUN_0011c1a0@Obj_11c1a0@owners@@QAEDH@Z
char owners::Obj_11c1a0::FUN_0011c1a0(int v) {
    int* q = &field;
    *q = v;
    return 1;
}


// 0x0011c1c0 FUN_0011c1c0 (12 B): matches/0x0011c1c0.cpp
// sym: ?FUN_0011c1c0@Obj_11c1c0@owners@@QAE_NH@Z
bool owners::Obj_11c1c0::FUN_0011c1c0(int v) {
    value = v;
    return true;
}


// 0x0011c1e0 FUN_0011c1e0 (12 B): matches/0x0011c1e0.cpp
// sym: ?FUN_0011c1e0@X_11c1e0@owners@@QAE_NH@Z
bool owners::X_11c1e0::FUN_0011c1e0(int v) {
    *(int*)((char*)this + 0x5c) = v;
    return true;
}

namespace fn_f18cc536 {

// 0x0011c1f0 FUN_0011c1f0 (19 B): matches/0x0011c1f0.cpp
// sym: ?FUN_0011c1f0@fn_f18cc536@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c1f0() {
    FUN_00234810(((char*)&DAT_004e0ca8), ((char*)&DAT_004e0cac));
}

} // namespace fn_f18cc536

// 0x0011c210 hulkfight::ai::PathLocatorTestCondition::vfunc_0 (16 B): matches/0x0011c210.cpp
// sym: ?vfunc_0@PathLocatorTestCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::PathLocatorTestCondition::vfunc_0(int index) {
    int* p = gTable_11c210;
    return p[index];
}


// 0x0011c220 FUN_0011c220 (74 B): equivalent/0x0011c220.cpp [wrapped: conflict: hulkfight::ai::PathLocatorTestCondition]
// sym: ??0PathLocatorTestCondition@ai@hulkfight@fn_0011c220@@QAE@XZ
namespace fn_0011c220 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0011c220 @ 0x0011c220
namespace hulkfight { namespace ai {
struct FUN_00234590 {
    FUN_00234590(int);
    virtual void virtualMethod();
    char padding[8];
};
struct PathLocatorTestCondition : FUN_00234590 {
    int first;
    int second;
    int third;
    unsigned char flags[8];
    float radius;
    float height;
    float distance;
    PathLocatorTestCondition();
};
PathLocatorTestCondition::PathLocatorTestCondition() : FUN_00234590(0) {
    first = 0;
    second = 0;
    third = 0;
    for (int i = 0; i < 8; ++i) flags[i] = 0;
    radius = 50.0f;
    height = 4.0f;
    distance = 50.0f;
}
} }
} // namespace fn_0011c220

namespace fn_f18cc536 {

// 0x0011c270 FUN_0011c270 (29 B): matches/0x0011c270.cpp
// sym: ??1PathLocatorTestCondition@fn_f18cc536@@UAE@XZ
PathLocatorTestCondition::~PathLocatorTestCondition() {
    Cleanup(d);
    F();
}

} // namespace fn_f18cc536

// 0x0011c290 FUN_0011c290 (82 B): equivalent/0x0011c290.cpp
// sym: ?FUN_0011c290@Object_11c290@owners@@QAEHPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_0011c290 @ 0x0011c290
int owners::Object_11c290::FUN_0011c290(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & ~255U) | 1; }
    unsigned int length = 0;
    do { ++length; } while (source[length - 1]);
    char *allocated = (char *)FUN_0008d6d0(length);
    text = allocated;
    char *dest = allocated;
    do { *dest++ = *source; } while (*source++);
    return ((hulk_uintptr)allocated & ~255U) | 1;
}

namespace fn_f18cc536 {

// 0x0011c2f0 FUN_0011c2f0 (19 B): matches/0x0011c2f0.cpp
// sym: ?FUN_0011c2f0@fn_f18cc536@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0011c2f0() {
    FUN_00234810(((char*)&DAT_004e0cb0), ((char*)&DAT_004e0cb4));
}

} // namespace fn_f18cc536
