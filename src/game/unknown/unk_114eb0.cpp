// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00114eb0..0x001158a0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f7a1ef3e {
#define TREE_TU_END }
namespace fn_f7a1ef3e {} using namespace fn_f7a1ef3e;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f7a1ef3e {
struct Vec3_1150b0 {
    int x;
    int y;
    int z;
};
class Obj_1150b0 {
  public:
    char pad[0x1c];
    int a;
    int b;
    int c;
    bool Set(Vec3_1150b0* v);
};
class Obj_1150d0 {
  public:
    char pad[0xc];
    int mVal;
    char SetTimeBegin_001150d0(int v);
};
class A_1150e0 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_001150e0(int x);
};
class T_115100 {
  public:
    char pad[0x14];
    int mX;
    bool SetSpeed_00115100(int x);
};
struct Src_1151a0 {
    int a;
    int b;
    int c;
};
struct Tgt {
    char pad[0x18];
    int m18;
    int m1c;
    int m20;
    char Set(const Src_1151a0* p);
};
struct Sub_115300 {
    int value;
};
class Obj_115300 {
  public:
    char pad[0x1c];
    Sub_115300 s;
    char Set(int x);
};
struct S_115450 {
    int a;
    int b;
    int c;
};
class T_115450 {
  public:
    char pad0[0x18];
    int m18;
    int m1c;
    int m20;
    char Fn(const S_115450* p);
};
extern int* hulk_at_004e0c24;
class CCondition_1156c0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0c2c;
class CCondition_115720 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0c34;
class CCondition_115790 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0c3c;
class CCondition_115810 {
  public:
    virtual int vfunc_0(int);
};

} // namespace fn_f7a1ef3e

// 0x00114eb0 FUN_00114eb0 (12 B): matches/0x00114eb0.cpp
// sym: ?FUN_00114eb0@Obj_114eb0@owners@@QAEDD@Z
char owners::Obj_114eb0::FUN_00114eb0(char v) {
    mVal = v;
    return 1;
}


// 0x00114ed0 FUN_00114ed0 (12 B): matches/0x00114ed0.cpp
// sym: ?FUN_00114ed0@T_114ed0@owners@@QAEDE@Z
char owners::T_114ed0::FUN_00114ed0(unsigned char x) {
    m = x;
    return 1;
}


// 0x00114ee0 FUN_00114ee0 (12 B): matches/0x00114ee0.cpp
// sym: ?FUN_00114ee0@Obj_114ee0@owners@@QAEDH@Z
char owners::Obj_114ee0::FUN_00114ee0(int x) {
    value = x;
    return 1;
}


// 0x00114ef0 FUN_00114ef0 (12 B): matches/0x00114ef0.cpp
// sym: ?FUN_00114ef0@A_114ef0@owners@@QAE_NH@Z
bool owners::A_114ef0::FUN_00114ef0(int value) {
    m10 = value;
    return true;
}


// 0x00114f10 FUN_00114f10 (12 B): matches/0x00114f10.cpp
// sym: ?FUN_00114f10@Obj_114f10@owners@@QAEDH@Z
char owners::Obj_114f10::FUN_00114f10(int v) {
    m = v;
    return 1;
}


// 0x00114f30 FUN_00114f30 (12 B): matches/0x00114f30.cpp
// sym: ?FUN_00114f30@Obj_114f30@owners@@QAE_NPAX@Z
bool owners::Obj_114f30::FUN_00114f30(void* p) {
    m = p;
    return true;
}


// 0x00114f50 FUN_00114f50 (12 B): matches/0x00114f50.cpp
// sym: ?FUN_00114f50@Obj_114f50@owners@@QAEDH@Z
char owners::Obj_114f50::FUN_00114f50(int x) {
    value = x;
    return 1;
}


// 0x00114f60 FUN_00114f60 (12 B): matches/0x00114f60.cpp
// sym: ?FUN_00114f60@Obj_114f60@owners@@QAE_NH@Z
bool owners::Obj_114f60::FUN_00114f60(int v) {
    mFlag = v;
    return true;
}


// 0x00114f80 FUN_00114f80 (12 B): matches/0x00114f80.cpp
// sym: ?FUN_00114f80@Obj_114f80@owners@@QAEEE@Z
unsigned char owners::Obj_114f80::FUN_00114f80(unsigned char x) {
    value = x;
    return 1;
}


// 0x00114fa0 FUN_00114fa0 (12 B): matches/0x00114fa0.cpp
// sym: ?FUN_00114fa0@Obj_114fa0@owners@@QAEEH@Z
unsigned char owners::Obj_114fa0::FUN_00114fa0(int x) {
    value = x;
    return 1;
}


// 0x00114fb0 FUN_00114fb0 (12 B): matches/0x00114fb0.cpp
// sym: ?FUN_00114fb0@Obj_114fb0@owners@@QAEED@Z
unsigned char owners::Obj_114fb0::FUN_00114fb0(char value) {
    mValue = value;
    return 1;
}


// 0x00114fd0 FUN_00114fd0 (12 B): matches/0x00114fd0.cpp
// sym: ?FUN_00114fd0@X_114fd0@owners@@QAEDD@Z
char owners::X_114fd0::FUN_00114fd0(char arg) {
    m = arg;
    return 1;
}


// 0x00114fe0 FUN_00114fe0 (12 B): matches/0x00114fe0.cpp
// sym: ?FUN_00114fe0@X_114fe0@owners@@QAE_ND@Z
bool owners::X_114fe0::FUN_00114fe0(char c) {
    pad[0xe] = c;
    return true;
}


// 0x00115000 FUN_00115000 (12 B): matches/0x00115000.cpp
// sym: ?FUN_00115000@Obj_115000@owners@@QAEDD@Z
char owners::Obj_115000::FUN_00115000(char v) {
    m[0x0f] = v;
    return 1;
}


// 0x00115020 FUN_00115020 (12 B): matches/0x00115020.cpp
// sym: ?FUN_00115020@Obj_115020@owners@@QAEEE@Z
unsigned char owners::Obj_115020::FUN_00115020(unsigned char arg) {
    mVal = arg;
    return 1;
}


// 0x00115040 FUN_00115040 (12 B): matches/0x00115040.cpp
// sym: ?FUN_00115040@Obj_115040@owners@@QAEED@Z
unsigned char owners::Obj_115040::FUN_00115040(char v) {
    m[0x11] = v;
    return 1;
}


// 0x00115060 FUN_00115060 (12 B): matches/0x00115060.cpp
// sym: ?FUN_00115060@X_115060@owners@@QAE_NH@Z
bool owners::X_115060::FUN_00115060(int x) {
    m = x;
    return true;
}


// 0x00115080 FUN_00115080 (12 B): matches/0x00115080.cpp
// sym: ?FUN_00115080@O_115080@owners@@QAE_NH@Z
bool owners::O_115080::FUN_00115080(int a) {
    m18 = a;
    return true;
}

namespace fn_f7a1ef3e {

// 0x001150b0 FUN_001150b0 (26 B): matches/0x001150b0.cpp
// sym: ?Set@Obj_1150b0@fn_f7a1ef3e@@QAE_NPAUVec3_1150b0@2@@Z
bool Obj_1150b0::Set(Vec3_1150b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}


// 0x001150d0 FUN_001150d0 (12 B): matches/0x001150d0.cpp
// sym: ?SetTimeBegin_001150d0@Obj_1150d0@fn_f7a1ef3e@@QAEDH@Z
char Obj_1150d0::SetTimeBegin_001150d0(int v) {
    mVal = v;
    return 1;
}


// 0x001150e0 FUN_001150e0 (12 B): matches/0x001150e0.cpp
// sym: ?SetTimeEnd_001150e0@A_1150e0@fn_f7a1ef3e@@QAE_NH@Z
bool A_1150e0::SetTimeEnd_001150e0(int x) {
    m10 = x;
    return true;
}


// 0x00115100 FUN_00115100 (12 B): matches/0x00115100.cpp
// sym: ?SetSpeed_00115100@T_115100@fn_f7a1ef3e@@QAE_NH@Z
bool T_115100::SetSpeed_00115100(int x) {
    mX = x;
    return true;
}

} // namespace fn_f7a1ef3e

// 0x00115110 FUN_00115110 (12 B): matches/0x00115110.cpp
// sym: ?FUN_00115110@Body_115110@owners@@QAE_NH@Z
bool owners::Body_115110::FUN_00115110(int x) {
    mValue = x;
    return true;
}


// 0x00115120 FUN_00115120 (12 B): matches/0x00115120.cpp
// sym: ?FUN_00115120@Obj_115120@owners@@QAE_NH@Z
bool owners::Obj_115120::FUN_00115120(int value) {
    mValue = value;
    return true;
}


// 0x00115130 FUN_00115130 (12 B): matches/0x00115130.cpp
// sym: ?FUN_00115130@Obj_115130@owners@@QAEDH@Z
char owners::Obj_115130::FUN_00115130(int x) {
    value = x;
    return 1;
}


// 0x00115140 FUN_00115140 (12 B): matches/0x00115140.cpp
// sym: ?FUN_00115140@X_115140@owners@@QAE_NH@Z
bool owners::X_115140::FUN_00115140(int x) {
    value = x;
    return true;
}


// 0x00115160 FUN_00115160 (18 B): matches/0x00115160.cpp
// sym: ?FUN_00115160@Obj_115160@owners@@QAEDM@Z
char owners::Obj_115160::FUN_00115160(float x) {
    value = x * 0.0174532925f;
    return 1;
}

namespace fn_f7a1ef3e {

// 0x001151a0 FUN_001151a0 (26 B): matches/0x001151a0.cpp
// sym: ?Set@Tgt@fn_f7a1ef3e@@QAEDPBUSrc_1151a0@2@@Z
char Tgt::Set(const Src_1151a0* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}

} // namespace fn_f7a1ef3e

// 0x001151d0 FUN_001151d0 (12 B): matches/0x001151d0.cpp
// sym: ?FUN_001151d0@O_1151d0@owners@@QAEDH@Z
char owners::O_1151d0::FUN_001151d0(int v) {
    m24 = v;
    return 1;
}


// 0x001151e0 FUN_001151e0 (12 B): matches/0x001151e0.cpp
// sym: ?FUN_001151e0@Obj_1151e0@owners@@QAE_NH@Z
bool owners::Obj_1151e0::FUN_001151e0(int x) {
    m = x;
    return true;
}


// 0x001151f0 FUN_001151f0 (12 B): matches/0x001151f0.cpp
// sym: ?FUN_001151f0@Obj_1151f0@owners@@QAE_NH@Z
bool owners::Obj_1151f0::FUN_001151f0(int x) {
    value = x;
    return true;
}


// 0x00115210 FUN_00115210 (12 B): matches/0x00115210.cpp
// sym: ?FUN_00115210@Obj_115210@owners@@QAE_NH@Z
bool owners::Obj_115210::FUN_00115210(int x) {
    value = x;
    return true;
}


// 0x00115230 FUN_00115230 (12 B): matches/0x00115230.cpp
// sym: ?FUN_00115230@Obj_115230@owners@@QAE_NH@Z
bool owners::Obj_115230::FUN_00115230(int v) {
    mVal = v;
    return true;
}


// 0x00115240 FUN_00115240 (12 B): matches/0x00115240.cpp
// sym: ?FUN_00115240@X_115240@owners@@QAEDH@Z
char owners::X_115240::FUN_00115240(int x) {
    m1c = x;
    return 1;
}


// 0x00115250 FUN_00115250 (12 B): matches/0x00115250.cpp
// sym: ?FUN_00115250@Obj_115250@owners@@QAE_NH@Z
bool owners::Obj_115250::FUN_00115250(int x) {
    m20 = x;
    return true;
}


// 0x00115270 FUN_00115270 (12 B): matches/0x00115270.cpp
// sym: ?FUN_00115270@Target_115270@owners@@QAE_NH@Z
bool owners::Target_115270::FUN_00115270(int x) {
    mValue = x;
    return true;
}


// 0x00115280 FUN_00115280 (12 B): matches/0x00115280.cpp
// sym: ?FUN_00115280@C_115280@owners@@QAE_NH@Z
bool owners::C_115280::FUN_00115280(int x) {
    m28 = x;
    return true;
}


// 0x00115290 FUN_00115290 (12 B): matches/0x00115290.cpp
// sym: ?FUN_00115290@Obj_115290@owners@@QAE_NH@Z
bool owners::Obj_115290::FUN_00115290(int x) {
    mVal = x;
    return true;
}


// 0x001152a0 FUN_001152a0 (12 B): matches/0x001152a0.cpp
// sym: ?FUN_001152a0@Obj_1152a0@owners@@QAE_NH@Z
bool owners::Obj_1152a0::FUN_001152a0(int x) {
    m10 = x;
    return true;
}


// 0x001152c0 FUN_001152c0 (12 B): matches/0x001152c0.cpp
// sym: ?FUN_001152c0@C_1152c0@owners@@QAEDH@Z
char owners::C_1152c0::FUN_001152c0(int x) {
    m14 = x;
    return 1;
}


// 0x001152e0 FUN_001152e0 (12 B): matches/0x001152e0.cpp
// sym: ?FUN_001152e0@O_1152e0@owners@@QAEEH@Z
unsigned char owners::O_1152e0::FUN_001152e0(int x) {
    m18 = x;
    return 1;
}

namespace fn_f7a1ef3e {

// 0x00115300 FUN_00115300 (12 B): matches/0x00115300.cpp
// sym: ?Set@Obj_115300@fn_f7a1ef3e@@QAEDH@Z
char Obj_115300::Set(int x) {
    s.value = x;
    return 1;
}

} // namespace fn_f7a1ef3e

// 0x00115320 FUN_00115320 (12 B): matches/0x00115320.cpp
// sym: ?FUN_00115320@Obj_115320@owners@@QAEDH@Z
char owners::Obj_115320::FUN_00115320(int v) {
    m20 = v;
    return 1;
}


// 0x00115340 FUN_00115340 (12 B): matches/0x00115340.cpp
// sym: ?FUN_00115340@Obj_115340@owners@@QAE_NH@Z
bool owners::Obj_115340::FUN_00115340(int v) {
    value = v;
    return true;
}


// 0x00115360 FUN_00115360 (12 B): matches/0x00115360.cpp
// sym: ?FUN_00115360@X_115360@owners@@QAE_ND@Z
bool owners::X_115360::FUN_00115360(char c) {
    m = c;
    return true;
}


// 0x00115380 FUN_00115380 (12 B): matches/0x00115380.cpp
// sym: ?FUN_00115380@X_115380@owners@@QAEDH@Z
char owners::X_115380::FUN_00115380(int a) {
    m29 = (char)a;
    return 1;
}


// 0x001153a0 FUN_001153a0 (12 B): matches/0x001153a0.cpp
// sym: ?FUN_001153a0@X_1153a0@owners@@QAEDD@Z
char owners::X_1153a0::FUN_001153a0(char v) {
    m2a = v;
    return 1;
}


// 0x001153c0 FUN_001153c0 (12 B): matches/0x001153c0.cpp
// sym: ?FUN_001153c0@Obj_1153c0@owners@@QAEDE@Z
char owners::Obj_1153c0::FUN_001153c0(unsigned char value) {
    m[0x2b] = value;
    return 1;
}


// 0x001153d0 FUN_001153d0 (4 B): matches/0x001153d0.cpp
// sym: ?FUN_001153d0@Obj_1153d0@owners@@QAEPADXZ
char* owners::Obj_1153d0::FUN_001153d0() {
    return (char*)pad + 0x30;
}


// 0x001153e0 FUN_001153e0 (12 B): matches/0x001153e0.cpp
// sym: ?FUN_001153e0@X_1153e0@owners@@QAE_NH@Z
bool owners::X_1153e0::FUN_001153e0(int a) {
    m1c = a;
    return true;
}


// 0x001153f0 FUN_001153f0 (12 B): matches/0x001153f0.cpp
// sym: ?FUN_001153f0@X_1153f0@owners@@QAEDH@Z
char owners::X_1153f0::FUN_001153f0(int v) {
    mValue = v;
    return 1;
}


// 0x00115410 FUN_00115410 (18 B): matches/0x00115410.cpp
// sym: ?FUN_00115410@X_115410@owners@@QAEDM@Z
char owners::X_115410::FUN_00115410(float degrees) {
    radians = degrees * 0.017453292f;
    return 1;
}

namespace fn_f7a1ef3e {

// 0x00115450 FUN_00115450 (26 B): matches/0x00115450.cpp
// sym: ?Fn@T_115450@fn_f7a1ef3e@@QAEDPBUS_115450@2@@Z
char T_115450::Fn(const S_115450* p) {
    m18 = p->a;
    m1c = p->b;
    m20 = p->c;
    return 1;
}

} // namespace fn_f7a1ef3e

// 0x00115480 FUN_00115480 (12 B): matches/0x00115480.cpp
// sym: ?FUN_00115480@Obj_115480@owners@@QAE_NH@Z
bool owners::Obj_115480::FUN_00115480(int x) {
    mVal = x;
    return true;
}


// 0x00115490 FUN_00115490 (12 B): matches/0x00115490.cpp
// sym: ?FUN_00115490@X_115490@owners@@QAEDH@Z
char owners::X_115490::FUN_00115490(int x) {
    m = x;
    return 1;
}


// 0x001154a0 FUN_001154a0 (12 B): matches/0x001154a0.cpp
// sym: ?FUN_001154a0@A_1154a0@owners@@QAE_NH@Z
bool owners::A_1154a0::FUN_001154a0(int x) {
    m = x;
    return true;
}


// 0x001154c0 FUN_001154c0 (12 B): matches/0x001154c0.cpp
// sym: ?FUN_001154c0@X_1154c0@owners@@QAE_NH@Z
bool owners::X_1154c0::FUN_001154c0(int x) {
    member = x;
    return true;
}


// 0x001154e0 FUN_001154e0 (12 B): matches/0x001154e0.cpp
// sym: ?FUN_001154e0@C_1154e0@owners@@QAE_NPAX@Z
bool owners::C_1154e0::FUN_001154e0(void* p) {
    mPtr = p;
    return true;
}


// 0x00115500 FUN_00115500 (12 B): matches/0x00115500.cpp
// sym: ?FUN_00115500@Obj_115500@owners@@QAE_NH@Z
bool owners::Obj_115500::FUN_00115500(int v) {
    mValue = v;
    return true;
}


// 0x00115520 FUN_00115520 (12 B): matches/0x00115520.cpp
// sym: ?FUN_00115520@Obj_115520@owners@@QAE_NH@Z
bool owners::Obj_115520::FUN_00115520(int value) {
    mValue = value;
    return true;
}


// 0x00115540 FUN_00115540 (12 B): matches/0x00115540.cpp
// sym: ?FUN_00115540@Obj_115540@owners@@QAE_NH@Z
bool owners::Obj_115540::FUN_00115540(int v) {
    mVal = v;
    return true;
}


// 0x00115550 FUN_00115550 (12 B): matches/0x00115550.cpp
// sym: ?FUN_00115550@X_115550@owners@@QAEDH@Z
char owners::X_115550::FUN_00115550(int v) {
    m28 = v;
    return 1;
}


// 0x00115560 FUN_00115560 (12 B): matches/0x00115560.cpp
// sym: ?FUN_00115560@X_115560@owners@@QAE_NH@Z
bool owners::X_115560::FUN_00115560(int v) {
    m = v;
    return true;
}


// 0x00115570 FUN_00115570 (12 B): matches/0x00115570.cpp
// sym: ?FUN_00115570@Obj_115570@owners@@QAEDH@Z
char owners::Obj_115570::FUN_00115570(int a) {
    value = a;
    return 1;
}


// 0x00115590 FUN_00115590 (12 B): matches/0x00115590.cpp
// sym: ?FUN_00115590@C_115590@owners@@QAE_NH@Z
bool owners::C_115590::FUN_00115590(int x) {
    m14 = x;
    return true;
}


// 0x001155b0 FUN_001155b0 (12 B): matches/0x001155b0.cpp
// sym: ?FUN_001155b0@X_1155b0@owners@@QAEDH@Z
char owners::X_1155b0::FUN_001155b0(int arg) {
    m18 = arg;
    return 1;
}


// 0x001155d0 FUN_001155d0 (12 B): matches/0x001155d0.cpp
// sym: ?FUN_001155d0@Obj_1155d0@owners@@QAE_NH@Z
bool owners::Obj_1155d0::FUN_001155d0(int v) {
    field = v;
    return true;
}


// 0x001155f0 FUN_001155f0 (12 B): matches/0x001155f0.cpp
// sym: ?FUN_001155f0@Obj_1155f0@owners@@QAE_NH@Z
bool owners::Obj_1155f0::FUN_001155f0(int v) {
    value = v;
    return true;
}


// 0x00115610 FUN_00115610 (12 B): matches/0x00115610.cpp
// sym: ?FUN_00115610@Obj_115610@owners@@QAE_NH@Z
bool owners::Obj_115610::FUN_00115610(int v) {
    m24 = v;
    return true;
}


// 0x00115630 FUN_00115630 (12 B): matches/0x00115630.cpp
// sym: ?FUN_00115630@C_115630@owners@@QAEEE@Z
unsigned char owners::C_115630::FUN_00115630(unsigned char x) {
    m = x;
    return 1;
}


// 0x00115650 FUN_00115650 (12 B): matches/0x00115650.cpp
// sym: ?FUN_00115650@Obj_115650@owners@@QAEDD@Z
char owners::Obj_115650::FUN_00115650(char a) {
    m[0x29] = a;
    return 1;
}


// 0x00115670 FUN_00115670 (12 B): matches/0x00115670.cpp
// sym: ?FUN_00115670@Obj_115670@owners@@QAE_NH@Z
bool owners::Obj_115670::FUN_00115670(int value) {
    mValue = value;
    return true;
}


// 0x00115690 FUN_00115690 (12 B): matches/0x00115690.cpp
// sym: ?FUN_00115690@Obj_115690@owners@@QAE_NH@Z
bool owners::Obj_115690::FUN_00115690(int x) {
    m = x;
    return true;
}

namespace fn_f7a1ef3e {

// 0x001156a0 FUN_001156a0 (19 B): matches/0x001156a0.cpp
// sym: ?FUN_001156a0@fn_f7a1ef3e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001156a0() {
    FUN_00234810(((char*)&DAT_004e0c24), ((char*)&DAT_004e0c28));
}

} // namespace fn_f7a1ef3e

// 0x001156c0 hulkfight::ai::HasGroundPointCondition::vfunc_0 (16 B): matches/0x001156c0.cpp
// sym: ?vfunc_0@HasGroundPointCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HasGroundPointCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0c24;
    return p[index];
}

namespace fn_f7a1ef3e {

// 0x00115700 FUN_00115700 (19 B): matches/0x00115700.cpp
// sym: ?FUN_00115700@fn_f7a1ef3e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115700() {
    FUN_00234810(((char*)&DAT_004e0c2c), ((char*)&DAT_004e0c30));
}

} // namespace fn_f7a1ef3e

// 0x00115720 hulkfight::ai::LocatorDistanceCondition::vfunc_0 (16 B): matches/0x00115720.cpp
// sym: ?vfunc_0@LocatorDistanceCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::LocatorDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0c2c;
    return p[index];
}

namespace fn_f7a1ef3e {

// 0x00115770 FUN_00115770 (19 B): matches/0x00115770.cpp
// sym: ?FUN_00115770@fn_f7a1ef3e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115770() {
    FUN_00234810(((char*)&DAT_004e0c34), ((char*)&DAT_004e0c38));
}

} // namespace fn_f7a1ef3e

// 0x00115790 hulkfight::ai::ComputeDropZoneCondition::vfunc_0 (16 B): matches/0x00115790.cpp
// sym: ?vfunc_0@ComputeDropZoneCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::ComputeDropZoneCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0c34;
    return p[index];
}

namespace fn_f7a1ef3e {

// 0x001157f0 FUN_001157f0 (19 B): matches/0x001157f0.cpp
// sym: ?FUN_001157f0@fn_f7a1ef3e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001157f0() {
    FUN_00234810(((char*)&DAT_004e0c3c), ((char*)&DAT_004e0c40));
}

} // namespace fn_f7a1ef3e

// 0x00115810 hulkfight::ai::HasGroundPointExtendedCondition::vfunc_0 (16 B): matches/0x00115810.cpp
// sym: ?vfunc_0@HasGroundPointExtendedCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HasGroundPointExtendedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0c3c;
    return p[index];
}

namespace fn_f7a1ef3e {

// 0x00115880 FUN_00115880 (19 B): matches/0x00115880.cpp
// sym: ?FUN_00115880@fn_f7a1ef3e@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00115880() {
    FUN_00234810(((char*)&DAT_004e0c44), ((char*)&DAT_004e0c48));
}

} // namespace fn_f7a1ef3e
