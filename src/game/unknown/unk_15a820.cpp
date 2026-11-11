// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0015a820..0x0015b780 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f68d580d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f68d580d {} using namespace fn_f68d580d;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f68d580d {
struct O_15a830 {
    char pad[0x10];
    int* member();
};
class Obj_15a840 {
  public:
    bool Set(int v);
    char pad[24];
    int mValue;
};
class Obj_15a850 {
  public:
    char pad[0x1c];
    char m1c;
    char m1d;
    char Set(char c);
};
class Obj_15a9f0 {
  public:
    char pad[0x40];
    int mVal;
};
struct Inner_15aa00 {
    int x;
};
struct X_15aa00 {
    char pad[0x48];
    Inner_15aa00 i;
    Inner_15aa00* Fn();
};
struct Obj_15aa20 {
    char pad[0x58];
    int data;
};
struct Sub_15aa50 {
    int x;
};
struct Obj_15aa50 {
    char pad[0x70];
    Sub_15aa50 sub;
    Sub_15aa50* FUN_0015aa50();
};
struct Obj_15ac70 {
    char pad[0x48];
};
struct Obj_15ac90 {
    char pad[0x58];
    int member;
};
struct O_15acf0 {
    char pad[0x88];
    int x;
};
struct Vec3_15af70 {
    int x;
    int y;
    int z;
};
struct Obj_15af70 {
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(const Vec3_15af70* v);
};
struct Vec3_15b0b0 {
    int x, y, z;
};
class Obj_15b0b0 {
  public:
    char pad[0x68];
    Vec3_15b0b0 v;
    char Set(const Vec3_15b0b0* p);
};
struct S_15b0f0 {
    int a;
    int b;
    int c;
};
class Obj_15b0f0 {
  public:
    char pad[0x74];
    int m74;
    int m78;
    int m7c;
    bool Set(S_15b0f0* p);
};
struct Tgt {
    char pad[0x80];
    int x;
    int y;
    int z;
    char Set(Src* s);
};
struct Obj_15b1f0 {
    char pad[0xa0];
};
class Obj {
  public:
    char pad[0xcc];
    int m0;
    int m1;
    int m2;
    bool Set(const V3* v);
};
class Obj_15b410 {
  public:
    virtual ~Obj_15b410() {}
    char pad[0x28];
    int value;
    int* GetValue();
};
class Obj_15b440 {
  public:
    char pad[0x40];
    char* Get() { return pad + 0x40; }
};
class Obj_15b5e0 {
  public:
    char pad[0x30];
};
struct Sub_15b5f0 {
    char pad[0x38];
    char value;
};
class Obj_15b5f0 {
  public:
    Sub_15b5f0 sub;
    char* Get();
};
struct Sub_15b600 {
    char pad[0x40];
};
class A_15b600 {
  public:
    Sub_15b600 sub;
    void* Get();
};
struct S_15b6d0 {
    char pad[0x28];
    int x;
};
class Obj_15b6e0 {
  public:
    char pad[0x30];
    void* mPtr;
};

} // namespace fn_f68d580d

// 0x0015a820 FUN_0015a820 (12 B): matches/0x0015a820.cpp
// sym: ?FUN_0015a820@Obj_15a820@owners@@QAEDD@Z
char owners::Obj_15a820::FUN_0015a820(char value) {
    pad[12] = value;
    return 1;
}

namespace fn_f68d580d {

// 0x0015a830 FUN_0015a830 (4 B): matches/0x0015a830.cpp
// sym: ?member@O_15a830@fn_f68d580d@@QAEPAHXZ
int* O_15a830::member() {
    return (int*)((char*)this + 0x10);
}


// 0x0015a840 FUN_0015a840 (12 B): matches/0x0015a840.cpp
// sym: ?Set@Obj_15a840@fn_f68d580d@@QAE_NH@Z
bool Obj_15a840::Set(int v) {
    mValue = v;
    return true;
}


// 0x0015a850 FUN_0015a850 (12 B): matches/0x0015a850.cpp
// sym: ?Set@Obj_15a850@fn_f68d580d@@QAEDD@Z
char Obj_15a850::Set(char c) {
    m1c = c;
    return 1;
}

} // namespace fn_f68d580d

// 0x0015a870 FUN_0015a870 (12 B): matches/0x0015a870.cpp
// sym: ?FUN_0015a870@A_15a870@owners@@QAE_NH@Z
bool owners::A_15a870::FUN_0015a870(int x) {
    m = x;
    return true;
}


// 0x0015a890 FUN_0015a890 (12 B): matches/0x0015a890.cpp
// sym: ?FUN_0015a890@T_15a890@owners@@QAEDPAX@Z
char owners::T_15a890::FUN_0015a890(void* p) {
    m = p;
    return 1;
}


// 0x0015a8a0 FUN_0015a8a0 (12 B): matches/0x0015a8a0.cpp
// sym: ?FUN_0015a8a0@Obj_15a8a0@owners@@QAEDH@Z
char owners::Obj_15a8a0::FUN_0015a8a0(int x) {
    mValue = x;
    return 1;
}


// 0x0015a8b0 FUN_0015a8b0 (12 B): matches/0x0015a8b0.cpp
// sym: ?FUN_0015a8b0@C_15a8b0@owners@@QAEDH@Z
char owners::C_15a8b0::FUN_0015a8b0(int x) {
    m = x;
    return 1;
}


// 0x0015a8c0 FUN_0015a8c0 (12 B): matches/0x0015a8c0.cpp
// sym: ?FUN_0015a8c0@Obj_15a8c0@owners@@QAE_NH@Z
bool owners::Obj_15a8c0::FUN_0015a8c0(int v) {
    mValue = v;
    return true;
}


// 0x0015a8d0 FUN_0015a8d0 (12 B): matches/0x0015a8d0.cpp
// sym: ?FUN_0015a8d0@A_15a8d0@owners@@QAEDH@Z
char owners::A_15a8d0::FUN_0015a8d0(int v) {
    mVal = v;
    return 1;
}


// 0x0015a8f0 FUN_0015a8f0 (12 B): matches/0x0015a8f0.cpp
// sym: ?FUN_0015a8f0@Obj_15a8f0@owners@@QAEDH@Z
char owners::Obj_15a8f0::FUN_0015a8f0(int x) {
    value = x;
    return 1;
}


// 0x0015a910 FUN_0015a910 (12 B): matches/0x0015a910.cpp
// sym: ?FUN_0015a910@C_15a910@owners@@QAEDH@Z
char owners::C_15a910::FUN_0015a910(int v) {
    m = v;
    return 1;
}


// 0x0015a930 FUN_0015a930 (12 B): matches/0x0015a930.cpp
// sym: ?FUN_0015a930@T_15a930@owners@@QAEDH@Z
char owners::T_15a930::FUN_0015a930(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}


// 0x0015a950 FUN_0015a950 (12 B): matches/0x0015a950.cpp
// sym: ?FUN_0015a950@Obj_15a950@owners@@QAEDH@Z
char owners::Obj_15a950::FUN_0015a950(int v) {
    *((int*)((char*)this + 0x20)) = v;
    return 1;
}


// 0x0015a970 FUN_0015a970 (12 B): matches/0x0015a970.cpp
// sym: ?FUN_0015a970@Obj_15a970@owners@@QAE_NH@Z
bool owners::Obj_15a970::FUN_0015a970(int x) {
    value = x;
    return true;
}


// 0x0015a990 FUN_0015a990 (12 B): matches/0x0015a990.cpp
// sym: ?FUN_0015a990@Obj_15a990@owners@@QAE_NH@Z
bool owners::Obj_15a990::FUN_0015a990(int value) {
    mValue = value;
    return true;
}


// 0x0015a9b0 FUN_0015a9b0 (12 B): matches/0x0015a9b0.cpp
// sym: ?FUN_0015a9b0@Obj_15a9b0@owners@@QAE_NH@Z
bool owners::Obj_15a9b0::FUN_0015a9b0(int a) {
    m2c = a;
    return true;
}


// 0x0015a9d0 FUN_0015a9d0 (12 B): matches/0x0015a9d0.cpp
// sym: ?FUN_0015a9d0@X_15a9d0@owners@@QAE_NH@Z
bool owners::X_15a9d0::FUN_0015a9d0(int v) {
    m30 = v;
    return true;
}


// 0x0015a9e0 FUN_0015a9e0 (4 B): matches/0x0015a9e0.cpp
// sym: ?FUN_0015a9e0@T_15a9e0@owners@@QAEPAXXZ
void* owners::T_15a9e0::FUN_0015a9e0() {
    return (void*)((char*)this + 0x38);
}

namespace fn_f68d580d {

// 0x0015a9f0 FUN_0015a9f0 (4 B): matches/0x0015a9f0.cpp
// sym: ?FUN_0015a9f0@fn_f68d580d@@YIPAHPAVObj_15a9f0@1@@Z
int* __fastcall FUN_0015a9f0(Obj_15a9f0* self) {
    return &self->mVal;
}


// 0x0015aa00 FUN_0015aa00 (4 B): matches/0x0015aa00.cpp
// sym: ?Fn@X_15aa00@fn_f68d580d@@QAEPAUInner_15aa00@2@XZ
Inner_15aa00* X_15aa00::Fn() {
    return &i;
}

} // namespace fn_f68d580d

// 0x0015aa10 FUN_0015aa10 (4 B): matches/0x0015aa10.cpp
// sym: ?FUN_0015aa10@Obj_15aa10@owners@@QAEPADXZ
char* owners::Obj_15aa10::FUN_0015aa10() {
    return (char*)this + 0x50;
}

namespace fn_f68d580d {

// 0x0015aa20 FUN_0015aa20 (4 B): matches/0x0015aa20.cpp
// sym: ?FUN_0015aa20@fn_f68d580d@@YIPAUObj_15aa20@1@PAU21@@Z
Obj_15aa20* __fastcall FUN_0015aa20(Obj_15aa20* self) {
    return (Obj_15aa20*)((char*)self + 0x58);
}

} // namespace fn_f68d580d

// 0x0015aa30 FUN_0015aa30 (4 B): matches/0x0015aa30.cpp
// sym: ?FUN_0015aa30@Obj_15aa30@owners@@QAEPAHXZ
int* owners::Obj_15aa30::FUN_0015aa30() {
    return &m;
}


// 0x0015aa40 FUN_0015aa40 (4 B): matches/0x0015aa40.cpp
// sym: ?FUN_0015aa40@Obj_15aa40@owners@@QAEPAXXZ
void* owners::Obj_15aa40::FUN_0015aa40() {
    return (char*)this + 0x68;
}

namespace fn_f68d580d {

// 0x0015aa50 FUN_0015aa50 (4 B): matches/0x0015aa50.cpp
// sym: ?FUN_0015aa50@Obj_15aa50@fn_f68d580d@@QAEPAUSub_15aa50@2@XZ
Sub_15aa50* Obj_15aa50::FUN_0015aa50() {
    return &sub;
}

} // namespace fn_f68d580d

// 0x0015aa60 FUN_0015aa60 (4 B): matches/0x0015aa60.cpp
// sym: ?FUN_0015aa60@X_15aa60@owners@@QAEPAHXZ
int* owners::X_15aa60::FUN_0015aa60() {
    return (int*)((char*)this + 0x78);
}


// 0x0015aa70 FUN_0015aa70 (7 B): matches/0x0015aa70.cpp
// sym: ?FUN_0015aa70@Obj_15aa70@owners@@QAEPADXZ
char* owners::Obj_15aa70::FUN_0015aa70() {
    return (char*)((char*)this + 0x80);
}


// 0x0015aa80 FUN_0015aa80 (7 B): matches/0x0015aa80.cpp
// sym: ?FUN_0015aa80@Obj_15aa80@owners@@QAEPAU12@XZ
owners::Obj_15aa80* owners::Obj_15aa80::FUN_0015aa80() {
    return (owners::Obj_15aa80*)((char*)this + 0x88);
}


// 0x0015aaa0 FUN_0015aaa0 (15 B): matches/0x0015aaa0.cpp
// sym: ?FUN_0015aaa0@Target_15aaa0@owners@@QAEEH@Z
unsigned char owners::Target_15aaa0::FUN_0015aaa0(int x) {
    value = x;
    return 1;
}


// 0x0015aac0 FUN_0015aac0 (15 B): matches/0x0015aac0.cpp
// sym: ?FUN_0015aac0@Obj_15aac0@owners@@QAEDH@Z
char owners::Obj_15aac0::FUN_0015aac0(int value) {
    m94 = value;
    return 1;
}


// 0x0015aae0 FUN_0015aae0 (15 B): matches/0x0015aae0.cpp
// sym: ?FUN_0015aae0@Obj_15aae0@owners@@QAEDH@Z
char owners::Obj_15aae0::FUN_0015aae0(int x) {
    m98 = x;
    return 1;
}


// 0x0015aaf0 FUN_0015aaf0 (12 B): matches/0x0015aaf0.cpp
// sym: ?FUN_0015aaf0@Obj_15aaf0@owners@@QAE_NH@Z
bool owners::Obj_15aaf0::FUN_0015aaf0(int v) {
    mValue = v;
    return true;
}


// 0x0015ab00 FUN_0015ab00 (12 B): matches/0x0015ab00.cpp
// sym: ?FUN_0015ab00@Target_15ab00@owners@@QAEDH@Z
char owners::Target_15ab00::FUN_0015ab00(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}


// 0x0015ab20 FUN_0015ab20 (12 B): matches/0x0015ab20.cpp
// sym: ?FUN_0015ab20@O_15ab20@owners@@QAEDH@Z
char owners::O_15ab20::FUN_0015ab20(int x) {
    mField = x;
    return 1;
}


// 0x0015ab40 FUN_0015ab40 (18 B): matches/0x0015ab40.cpp
// sym: ?FUN_0015ab40@C_15ab40@owners@@QAE_NM@Z
bool owners::C_15ab40::FUN_0015ab40(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}


// 0x0015ab70 FUN_0015ab70 (12 B): matches/0x0015ab70.cpp
// sym: ?FUN_0015ab70@Obj_15ab70@owners@@QAEDD@Z
char owners::Obj_15ab70::FUN_0015ab70(char c) {
    m[0x1c] = c;
    return 1;
}


// 0x0015ab90 FUN_0015ab90 (12 B): matches/0x0015ab90.cpp
// sym: ?FUN_0015ab90@O_15ab90@owners@@QAEDH@Z
char owners::O_15ab90::FUN_0015ab90(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}


// 0x0015abb0 FUN_0015abb0 (12 B): matches/0x0015abb0.cpp
// sym: ?FUN_0015abb0@Obj_15abb0@owners@@QAE_NH@Z
bool owners::Obj_15abb0::FUN_0015abb0(int v) {
    mVal = v;
    return true;
}


// 0x0015abd0 FUN_0015abd0 (12 B): matches/0x0015abd0.cpp
// sym: ?FUN_0015abd0@Obj_15abd0@owners@@QAE_NH@Z
bool owners::Obj_15abd0::FUN_0015abd0(int v) {
    m28 = v;
    return true;
}


// 0x0015abf0 FUN_0015abf0 (12 B): matches/0x0015abf0.cpp
// sym: ?FUN_0015abf0@Obj_15abf0@owners@@QAE_NH@Z
bool owners::Obj_15abf0::FUN_0015abf0(int x) {
    m2c = x;
    return true;
}


// 0x0015ac10 FUN_0015ac10 (12 B): matches/0x0015ac10.cpp
// sym: ?FUN_0015ac10@C_15ac10@owners@@QAE_NH@Z
bool owners::C_15ac10::FUN_0015ac10(int x) {
    flag = x;
    return true;
}


// 0x0015ac30 FUN_0015ac30 (12 B): matches/0x0015ac30.cpp
// sym: ?FUN_0015ac30@X_15ac30@owners@@QAE_NH@Z
bool owners::X_15ac30::FUN_0015ac30(int v) {
    value = v;
    return true;
}


// 0x0015ac50 FUN_0015ac50 (12 B): matches/0x0015ac50.cpp
// sym: ?FUN_0015ac50@O_15ac50@owners@@QAE_NH@Z
bool owners::O_15ac50::FUN_0015ac50(int x) {
    *(int*)(p + 0x38) = x;
    return true;
}


// 0x0015ac60 FUN_0015ac60 (4 B): matches/0x0015ac60.cpp
// sym: ?FUN_0015ac60@Obj_15ac60@owners@@QAEPAXXZ
void* owners::Obj_15ac60::FUN_0015ac60() {
    return (char*)this + 0x40;
}

namespace fn_f68d580d {

// 0x0015ac70 FUN_0015ac70 (4 B): matches/0x0015ac70.cpp
// sym: ?FUN_0015ac70@fn_f68d580d@@YIPAUObj_15ac70@1@PAU21@@Z
Obj_15ac70* __fastcall FUN_0015ac70(Obj_15ac70* self) {
    return (Obj_15ac70*)((char*)self + 0x48);
}

} // namespace fn_f68d580d

// 0x0015ac80 FUN_0015ac80 (4 B): matches/0x0015ac80.cpp
// sym: ?FUN_0015ac80@Obj_15ac80@owners@@QAEPAU12@XZ
owners::Obj_15ac80* owners::Obj_15ac80::FUN_0015ac80() {
    return (owners::Obj_15ac80*)((char*)this + 0x50);
}

namespace fn_f68d580d {

// 0x0015ac90 FUN_0015ac90 (4 B): matches/0x0015ac90.cpp
// sym: ?FUN_0015ac90@fn_f68d580d@@YIPAHPAUObj_15ac90@1@@Z
int* __fastcall FUN_0015ac90(Obj_15ac90* self) {
    return (int*)((char*)self + 0x58);
}

} // namespace fn_f68d580d

// 0x0015aca0 FUN_0015aca0 (4 B): matches/0x0015aca0.cpp
// sym: ?FUN_0015aca0@X_15aca0@owners@@QAEPAXXZ
void* owners::X_15aca0::FUN_0015aca0() {
    return (char*)this + 0x60;
}


// 0x0015acb0 FUN_0015acb0 (4 B): matches/0x0015acb0.cpp
// sym: ?FUN_0015acb0@A_15acb0@owners@@QAEPAHXZ
int* owners::A_15acb0::FUN_0015acb0() {
    return (int*)((char*)this + 0x68);
}


// 0x0015acc0 FUN_0015acc0 (4 B): matches/0x0015acc0.cpp
// sym: ?FUN_0015acc0@C_15acc0@owners@@QAEPADXZ
char* owners::C_15acc0::FUN_0015acc0() {
    return &m;
}


// 0x0015acd0 FUN_0015acd0 (4 B): matches/0x0015acd0.cpp
// sym: ?FUN_0015acd0@Obj_15acd0@owners@@QAEPAXXZ
void* owners::Obj_15acd0::FUN_0015acd0() {
    return (char*)this + 0x78;
}


// 0x0015ace0 FUN_0015ace0 (7 B): matches/0x0015ace0.cpp
// sym: ?FUN_0015ace0@A_15ace0@owners@@QAEPAHXZ
int* owners::A_15ace0::FUN_0015ace0() {
    return (int*)((char*)this + 0x80);
}

namespace fn_f68d580d {

// 0x0015acf0 FUN_0015acf0 (7 B): matches/0x0015acf0.cpp
// sym: ?FUN_0015acf0@fn_f68d580d@@YIPAHPAUO_15acf0@1@@Z
int* __fastcall FUN_0015acf0(O_15acf0* self) {
    return &self->x;
}

} // namespace fn_f68d580d

// 0x0015ad00 FUN_0015ad00 (7 B): matches/0x0015ad00.cpp
// sym: ?FUN_0015ad00@Obj_15ad00@owners@@QAEPAXXZ
void* owners::Obj_15ad00::FUN_0015ad00() {
    return (char*)this + 0x90;
}


// 0x0015ad20 FUN_0015ad20 (15 B): matches/0x0015ad20.cpp
// sym: ?FUN_0015ad20@C_15ad20@owners@@QAEDH@Z
char owners::C_15ad20::FUN_0015ad20(int x) {
    m = x;
    return 1;
}


// 0x0015ad40 FUN_0015ad40 (15 B): matches/0x0015ad40.cpp
// sym: ?FUN_0015ad40@Obj_15ad40@owners@@QAE_NH@Z
bool owners::Obj_15ad40::FUN_0015ad40(int x) {
    m9c = x;
    return true;
}


// 0x0015ad60 FUN_0015ad60 (15 B): matches/0x0015ad60.cpp
// sym: ?FUN_0015ad60@O_15ad60@owners@@QAEDH@Z
char owners::O_15ad60::FUN_0015ad60(int x) {
    value = x;
    return 1;
}


// 0x0015ad70 FUN_0015ad70 (12 B): matches/0x0015ad70.cpp
// sym: ?FUN_0015ad70@O_15ad70@owners@@QAE_NH@Z
bool owners::O_15ad70::FUN_0015ad70(int x) {
    m = x;
    return true;
}


// 0x0015ad80 FUN_0015ad80 (12 B): matches/0x0015ad80.cpp
// sym: ?FUN_0015ad80@Obj_15ad80@owners@@QAEDH@Z
char owners::Obj_15ad80::FUN_0015ad80(int value) {
    m10 = value;
    return 1;
}


// 0x0015ada0 FUN_0015ada0 (12 B): matches/0x0015ada0.cpp
// sym: ?FUN_0015ada0@C_15ada0@owners@@QAEDH@Z
char owners::C_15ada0::FUN_0015ada0(int x) {
    m14 = x;
    return 1;
}


// 0x0015adc0 FUN_0015adc0 (12 B): matches/0x0015adc0.cpp
// sym: ?FUN_0015adc0@Obj_15adc0@owners@@QAEDH@Z
char owners::Obj_15adc0::FUN_0015adc0(int x) {
    mField = x;
    return 1;
}


// 0x0015ade0 FUN_0015ade0 (18 B): matches/0x0015ade0.cpp
// sym: ?FUN_0015ade0@C_15ade0@owners@@QAEDM@Z
char owners::C_15ade0::FUN_0015ade0(float x) {
    mAngle = x * 0.0174532925f;
    return 1;
}


// 0x0015ae10 FUN_0015ae10 (18 B): matches/0x0015ae10.cpp
// sym: ?FUN_0015ae10@C_15ae10@owners@@QAEDM@Z
char owners::C_15ae10::FUN_0015ae10(float a) {
    mAngle = a * 0.017453292f;
    return 1;
}


// 0x0015ae40 FUN_0015ae40 (18 B): matches/0x0015ae40.cpp
// sym: ?FUN_0015ae40@C_15ae40@owners@@QAEDM@Z
char owners::C_15ae40::FUN_0015ae40(float x) {
    mVal = x * 0.0174532925f;
    return 1;
}


// 0x0015ae70 FUN_0015ae70 (18 B): matches/0x0015ae70.cpp
// sym: ?FUN_0015ae70@Foo_15ae70@owners@@QAE_NM@Z
bool owners::Foo_15ae70::FUN_0015ae70(float deg) {
    mRadians = deg * 0.017453292f;
    return true;
}


// 0x0015aea0 FUN_0015aea0 (18 B): matches/0x0015aea0.cpp
// sym: ?FUN_0015aea0@C_15aea0@owners@@QAE_NM@Z
bool owners::C_15aea0::FUN_0015aea0(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}


// 0x0015aed0 FUN_0015aed0 (18 B): matches/0x0015aed0.cpp
// sym: ?FUN_0015aed0@C_15aed0@owners@@QAE_NM@Z
bool owners::C_15aed0::FUN_0015aed0(float deg) {
    m = deg * 0.0174532925f;
    return true;
}


// 0x0015af00 FUN_0015af00 (12 B): matches/0x0015af00.cpp
// sym: ?FUN_0015af00@Obj_15af00@owners@@QAE_NH@Z
bool owners::Obj_15af00::FUN_0015af00(int value) {
    m34 = value;
    return true;
}


// 0x0015af20 FUN_0015af20 (12 B): matches/0x0015af20.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4Obj_15af20@fn_0015af20@@QAE_NH@Z
namespace fn_0015af20 {
class Obj_15af20 {
  public:
    char pad[0x38];
    int m38;
    bool operator=(int v_15af20);
};

bool Obj_15af20::operator=(int v_15af20) {
    m38 = v_15af20;
    return true;
}
} // namespace fn_0015af20


// 0x0015af40 FUN_0015af40 (12 B): matches/0x0015af40.cpp
// sym: ?FUN_0015af40@C_15af40@owners@@QAE_NH@Z
bool owners::C_15af40::FUN_0015af40(int x) {
    m3c = x;
    return true;
}

namespace fn_f68d580d {

// 0x0015af70 FUN_0015af70 (26 B): matches/0x0015af70.cpp
// sym: ?Set@Obj_15af70@fn_f68d580d@@QAE_NPBUVec3_15af70@2@@Z
bool Obj_15af70::Set(const Vec3_15af70* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_f68d580d

// 0x0015afa0 FUN_0015afa0 (18 B): matches/0x0015afa0.cpp
// sym: ?FUN_0015afa0@C_15afa0@owners@@QAE_NM@Z
bool owners::C_15afa0::FUN_0015afa0(float deg) {
    mRad = deg * 0.0174532925f;
    return true;
}


// 0x0015afd0 FUN_0015afd0 (18 B): matches/0x0015afd0.cpp
// sym: ?FUN_0015afd0@Foo_15afd0@owners@@QAE_NM@Z
bool owners::Foo_15afd0::FUN_0015afd0(float deg) {
    m_rad = deg * 0.0174532925f;
    return true;
}


// 0x0015b000 FUN_0015b000 (18 B): matches/0x0015b000.cpp
// sym: ?FUN_0015b000@C_15b000@owners@@QAE_NM@Z
bool owners::C_15b000::FUN_0015b000(float v) {
    mAngle = v * 0.017453292f;
    return true;
}


// 0x0015b030 FUN_0015b030 (18 B): matches/0x0015b030.cpp
// sym: ?FUN_0015b030@C_15b030@owners@@QAE_NM@Z
bool owners::C_15b030::FUN_0015b030(float x) {
    mDeg = x * 0.017453292f;
    return true;
}


// 0x0015b060 FUN_0015b060 (12 B): matches/0x0015b060.cpp
// sym: ?FUN_0015b060@C_15b060@owners@@QAE_NH@Z
bool owners::C_15b060::FUN_0015b060(int x) {
    value = x;
    return true;
}


// 0x0015b080 FUN_0015b080 (12 B): matches/0x0015b080.cpp
// sym: ?FUN_0015b080@Obj_15b080@owners@@QAE_NH@Z
bool owners::Obj_15b080::FUN_0015b080(int x) {
    value = x;
    return true;
}


// 0x0015b0a0 FUN_0015b0a0 (12 B): matches/0x0015b0a0.cpp
// sym: ?FUN_0015b0a0@Obj_15b0a0@owners@@QAE_NH@Z
bool owners::Obj_15b0a0::FUN_0015b0a0(int x) {
    value = x;
    return true;
}

namespace fn_f68d580d {

// 0x0015b0b0 FUN_0015b0b0 (26 B): matches/0x0015b0b0.cpp
// sym: ?Set@Obj_15b0b0@fn_f68d580d@@QAEDPBUVec3_15b0b0@2@@Z
char Obj_15b0b0::Set(const Vec3_15b0b0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return 1;
}


// 0x0015b0f0 FUN_0015b0f0 (26 B): matches/0x0015b0f0.cpp
// sym: ?Set@Obj_15b0f0@fn_f68d580d@@QAE_NPAUS_15b0f0@2@@Z
bool Obj_15b0f0::Set(S_15b0f0* p) {
    m74 = p->a;
    m78 = p->b;
    m7c = p->c;
    return true;
}


// 0x0015b140 FUN_0015b140 (35 B): matches/0x0015b140.cpp
// sym: ?Set@Tgt@fn_f68d580d@@QAEDPAUSrc@2@@Z
char Tgt::Set(Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return 1;
}

} // namespace fn_f68d580d

// 0x0015b180 FUN_0015b180 (15 B): matches/0x0015b180.cpp
// sym: ?FUN_0015b180@Obj_15b180@owners@@QAE_NH@Z
bool owners::Obj_15b180::FUN_0015b180(int value) {
    mValue = value;
    return true;
}


// 0x0015b1a0 FUN_0015b1a0 (15 B): matches/0x0015b1a0.cpp
// sym: ?FUN_0015b1a0@Obj_15b1a0@owners@@QAE_NH@Z
bool owners::Obj_15b1a0::FUN_0015b1a0(int x) {
    m90 = x;
    return true;
}


// 0x0015b1c0 FUN_0015b1c0 (15 B): matches/0x0015b1c0.cpp
// sym: ?FUN_0015b1c0@Obj_15b1c0@owners@@QAE_NH@Z
bool owners::Obj_15b1c0::FUN_0015b1c0(int v) {
    value = v;
    return true;
}


// 0x0015b1e0 FUN_0015b1e0 (15 B): matches/0x0015b1e0.cpp
// sym: ?FUN_0015b1e0@Obj_15b1e0@owners@@QAEDH@Z
char owners::Obj_15b1e0::FUN_0015b1e0(int x) {
    *(int*)((char*)this + 0x98) = x;
    return 1;
}

namespace fn_f68d580d {

// 0x0015b1f0 FUN_0015b1f0 (7 B): matches/0x0015b1f0.cpp
// sym: ?FUN_0015b1f0@fn_f68d580d@@YIPAUObj_15b1f0@1@PAU21@@Z
Obj_15b1f0* __fastcall FUN_0015b1f0(Obj_15b1f0* self) {
    return (Obj_15b1f0*)((char*)self + 0xa0);
}

} // namespace fn_f68d580d

// 0x0015b210 FUN_0015b210 (15 B): matches/0x0015b210.cpp
// sym: ?FUN_0015b210@Obj_15b210@owners@@QAE_NH@Z
bool owners::Obj_15b210::FUN_0015b210(int v) {
    mValue = v;
    return true;
}


// 0x0015b220 FUN_0015b220 (35 B): matches/0x0015b220.cpp
// sym: ?FUN_0015b220@Obj_15b220@owners@@QAE_NPAH@Z
bool owners::Obj_15b220::FUN_0015b220(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}


// 0x0015b250 FUN_0015b250 (15 B): matches/0x0015b250.cpp
// sym: ?FUN_0015b250@Obj_15b250@owners@@QAEDH@Z
char owners::Obj_15b250::FUN_0015b250(int value) {
    *(int*)((char*)this + 0xb8) = value;
    return 1;
}


// 0x0015b270 FUN_0015b270 (15 B): matches/0x0015b270.cpp
// sym: ?FUN_0015b270@Obj_15b270@owners@@QAE_NH@Z
bool owners::Obj_15b270::FUN_0015b270(int value) {
    mField = value;
    return true;
}


// 0x0015b290 FUN_0015b290 (15 B): matches/0x0015b290.cpp
// sym: ?FUN_0015b290@Obj_15b290@owners@@QAEDH@Z
char owners::Obj_15b290::FUN_0015b290(int value) {
    mValue = value;
    return 1;
}


// 0x0015b2b0 FUN_0015b2b0 (15 B): matches/0x0015b2b0.cpp
// sym: ?FUN_0015b2b0@Obj_15b2b0@owners@@QAE_NH@Z
bool owners::Obj_15b2b0::FUN_0015b2b0(int v) {
    value = v;
    return true;
}


// 0x0015b2d0 FUN_0015b2d0 (15 B): matches/0x0015b2d0.cpp
// sym: ?FUN_0015b2d0@Obj_15b2d0@owners@@QAEDH@Z
char owners::Obj_15b2d0::FUN_0015b2d0(int value) {
    mValue = value;
    return 1;
}

namespace fn_f68d580d {

// 0x0015b310 FUN_0015b310 (35 B): matches/0x0015b310.cpp
// sym: ?Set@Obj@fn_f68d580d@@QAE_NPBUV3@2@@Z
bool Obj::Set(const V3* v) {
    m0 = v->x;
    m1 = v->y;
    m2 = v->z;
    return true;
}

} // namespace fn_f68d580d

// 0x0015b340 FUN_0015b340 (12 B): matches/0x0015b340.cpp
// sym: ?FUN_0015b340@Obj_15b340@owners@@QAEDH@Z
char owners::Obj_15b340::FUN_0015b340(int v) {
    mVal = v;
    return 1;
}


// 0x0015b350 FUN_0015b350 (12 B): matches/0x0015b350.cpp
// sym: ?FUN_0015b350@C_15b350@owners@@QAE_NH@Z
bool owners::C_15b350::FUN_0015b350(int v) {
    mValue = v;
    return true;
}


// 0x0015b370 FUN_0015b370 (12 B): matches/0x0015b370.cpp
// sym: ?FUN_0015b370@X_15b370@owners@@QAE_NH@Z
bool owners::X_15b370::FUN_0015b370(int v) {
    m = v;
    return true;
}


// 0x0015b390 FUN_0015b390 (18 B): matches/0x0015b390.cpp
// sym: ?FUN_0015b390@Thing_15b390@owners@@QAEDM@Z
char owners::Thing_15b390::FUN_0015b390(float value) {
    angle = value * 0.017453292519943295f;
    return 1;
}


// 0x0015b3c0 FUN_0015b3c0 (12 B): matches/0x0015b3c0.cpp
// sym: ?FUN_0015b3c0@Obj_15b3c0@owners@@QAE_NH@Z
bool owners::Obj_15b3c0::FUN_0015b3c0(int v) {
    mX = v;
    return true;
}


// 0x0015b3e0 FUN_0015b3e0 (12 B): matches/0x0015b3e0.cpp
// sym: ?FUN_0015b3e0@O_15b3e0@owners@@QAEDH@Z
char owners::O_15b3e0::FUN_0015b3e0(int x) {
    m = x;
    return 1;
}


// 0x0015b400 FUN_0015b400 (12 B): matches/0x0015b400.cpp
// sym: ?FUN_0015b400@Obj_15b400@owners@@QAE_NH@Z
bool owners::Obj_15b400::FUN_0015b400(int x) {
    mVal = x;
    return true;
}

namespace fn_f68d580d {

// 0x0015b410 FUN_0015b410 (4 B): matches/0x0015b410.cpp
// sym: ?GetValue@Obj_15b410@fn_f68d580d@@QAEPAHXZ
int* Obj_15b410::GetValue() {
    return (int*)((char*)this + 0x28);
}

} // namespace fn_f68d580d

// 0x0015b420 FUN_0015b420 (4 B): matches/0x0015b420.cpp
// sym: ?FUN_0015b420@Obj_15b420@owners@@QAEPADXZ
char* owners::Obj_15b420::FUN_0015b420() {
    return (char*)this + 0x30;
}


// 0x0015b430 FUN_0015b430 (4 B): matches/0x0015b430.cpp
// sym: ?FUN_0015b430@O_15b430@owners@@QAEPADXZ
char* owners::O_15b430::FUN_0015b430() {
    return (char*)this + 0x38;
}

namespace fn_f68d580d {

// 0x0015b440 FUN_0015b440 (4 B): matches/0x0015b440.cpp
// sym: ?Get@Obj_15b440@fn_f68d580d@@QAEPADXZ
char* FUN_0015b440(Obj_15b440* self) {
    return self->Get();
}

} // namespace fn_f68d580d

// 0x0015b460 FUN_0015b460 (12 B): matches/0x0015b460.cpp
// sym: ?FUN_0015b460@Obj_15b460@owners@@QAEDD@Z
char owners::Obj_15b460::FUN_0015b460(char c) {
    f48 = c;
    return 1;
}


// 0x0015b470 FUN_0015b470 (4 B): matches/0x0015b470.cpp
// sym: ?FUN_0015b470@Obj_15b470@owners@@QAEPADXZ
char* owners::Obj_15b470::FUN_0015b470() {
    return (char*)((char*)this + 0x50);
}


// 0x0015b490 FUN_0015b490 (12 B): matches/0x0015b490.cpp
// sym: ?FUN_0015b490@X_15b490@owners@@QAEDH@Z
char owners::X_15b490::FUN_0015b490(int v) {
    m58 = v;
    return 1;
}


// 0x0015b4b0 FUN_0015b4b0 (12 B): matches/0x0015b4b0.cpp
// sym: ?FUN_0015b4b0@Obj_15b4b0@owners@@QAE_NH@Z
bool owners::Obj_15b4b0::FUN_0015b4b0(int v) {
    mVal = v;
    return true;
}


// 0x0015b4d0 FUN_0015b4d0 (12 B): matches/0x0015b4d0.cpp
// sym: ?FUN_0015b4d0@Obj_15b4d0@owners@@QAE_NH@Z
bool owners::Obj_15b4d0::FUN_0015b4d0(int param) {
    mValue = param;
    return true;
}


// 0x0015b4e0 FUN_0015b4e0 (12 B): matches/0x0015b4e0.cpp
// sym: ?FUN_0015b4e0@Obj_15b4e0@owners@@QAEDH@Z
char owners::Obj_15b4e0::FUN_0015b4e0(int value) {
    mValue = value;
    return 1;
}


// 0x0015b4f0 FUN_0015b4f0 (12 B): matches/0x0015b4f0.cpp
// sym: ?FUN_0015b4f0@Obj_15b4f0@owners@@QAE_NH@Z
bool owners::Obj_15b4f0::FUN_0015b4f0(int v) {
    value = v;
    return true;
}


// 0x0015b510 FUN_0015b510 (12 B): matches/0x0015b510.cpp
// sym: ?FUN_0015b510@X_15b510@owners@@QAEDH@Z
char owners::X_15b510::FUN_0015b510(int v) {
    m14 = v;
    return 1;
}


// 0x0015b530 FUN_0015b530 (18 B): matches/0x0015b530.cpp
// sym: ?FUN_0015b530@Angle_15b530@owners@@QAE_NM@Z
bool owners::Angle_15b530::FUN_0015b530(float x) {
    angle = x * 0.017453292f;
    return true;
}


// 0x0015b560 FUN_0015b560 (18 B): matches/0x0015b560.cpp
// sym: ?FUN_0015b560@Angle_15b560@owners@@QAEDM@Z
char owners::Angle_15b560::FUN_0015b560(float angle) {
    value = angle * 0.0174532925f;
    return 1;
}


// 0x0015b590 FUN_0015b590 (12 B): matches/0x0015b590.cpp
// sym: ?FUN_0015b590@X_15b590@owners@@QAE_NH@Z
bool owners::X_15b590::FUN_0015b590(int v) {
    m20 = v;
    return true;
}


// 0x0015b5b0 FUN_0015b5b0 (12 B): matches/0x0015b5b0.cpp
// sym: ?FUN_0015b5b0@Obj_15b5b0@owners@@QAEDH@Z
char owners::Obj_15b5b0::FUN_0015b5b0(int value) {
    *(int*)((char*)this + 0x24) = value;
    return 1;
}


// 0x0015b5d0 FUN_0015b5d0 (12 B): matches/0x0015b5d0.cpp
// sym: ?FUN_0015b5d0@A_15b5d0@owners@@QAE_NPAX@Z
bool owners::A_15b5d0::FUN_0015b5d0(void* p) {
    mThing = p;
    return true;
}

namespace fn_f68d580d {

// 0x0015b5e0 FUN_0015b5e0 (4 B): matches/0x0015b5e0.cpp
// sym: ?FUN_0015b5e0@fn_f68d580d@@YIPAVObj_15b5e0@1@PAV21@@Z
Obj_15b5e0* __fastcall FUN_0015b5e0(Obj_15b5e0* self) {
    return (Obj_15b5e0*)((char*)self + 0x30);
}


// 0x0015b5f0 FUN_0015b5f0 (4 B): matches/0x0015b5f0.cpp
// sym: ?Get@Obj_15b5f0@fn_f68d580d@@QAEPADXZ
char* Obj_15b5f0::Get() {
    return &sub.value;
}


// 0x0015b600 FUN_0015b600 (4 B): matches/0x0015b600.cpp
// sym: ?Get@A_15b600@fn_f68d580d@@QAEPAXXZ
void* A_15b600::Get() {
    return (char*)&sub + 0x40;
}

} // namespace fn_f68d580d

// 0x0015b610 FUN_0015b610 (4 B): matches/0x0015b610.cpp
// sym: ?FUN_0015b610@Obj_15b610@owners@@QAEPADXZ
char* owners::Obj_15b610::FUN_0015b610() {
    return (char*)this + 0x48;
}


// 0x0015b620 FUN_0015b620 (4 B): matches/0x0015b620.cpp
// sym: ?FUN_0015b620@Obj_15b620@owners@@QAEPAXXZ
void* owners::Obj_15b620::FUN_0015b620() {
    return (void*)((char*)this + 0x50);
}


// 0x0015b640 FUN_0015b640 (12 B): matches/0x0015b640.cpp
// sym: ?FUN_0015b640@Obj_15b640@owners@@QAE_NH@Z
bool owners::Obj_15b640::FUN_0015b640(int x) {
    value = x;
    return true;
}


// 0x0015b660 FUN_0015b660 (12 B): matches/0x0015b660.cpp
// sym: ?FUN_0015b660@X_15b660@owners@@QAE_NH@Z
bool owners::X_15b660::FUN_0015b660(int v) {
    m5c = v;
    return true;
}


// 0x0015b680 FUN_0015b680 (12 B): matches/0x0015b680.cpp
// sym: ?FUN_0015b680@Obj_15b680@owners@@QAE_NH@Z
bool owners::Obj_15b680::FUN_0015b680(int x) {
    value = x;
    return true;
}


// 0x0015b690 FUN_0015b690 (12 B): matches/0x0015b690.cpp
// sym: ?FUN_0015b690@Obj_15b690@owners@@QAEDH@Z
char owners::Obj_15b690::FUN_0015b690(int x) {
    value = x;
    return 1;
}


// 0x0015b6a0 FUN_0015b6a0 (12 B): matches/0x0015b6a0.cpp
// sym: ?FUN_0015b6a0@Obj_15b6a0@owners@@QAE_NH@Z
bool owners::Obj_15b6a0::FUN_0015b6a0(int v) {
    mVal = v;
    return true;
}


// 0x0015b6b0 FUN_0015b6b0 (4 B): matches/0x0015b6b0.cpp
// sym: ?FUN_0015b6b0@Obj_15b6b0@owners@@QAEPAXXZ
void* owners::Obj_15b6b0::FUN_0015b6b0() {
    return (void*)((char*)this + 0x18);
}


// 0x0015b6c0 FUN_0015b6c0 (4 B): matches/0x0015b6c0.cpp
// sym: ?FUN_0015b6c0@Obj_15b6c0@owners@@QAEPAXXZ
void* owners::Obj_15b6c0::FUN_0015b6c0() {
    return (char*)this + 0x20;
}

namespace fn_f68d580d {

// 0x0015b6d0 FUN_0015b6d0 (4 B): matches/0x0015b6d0.cpp
// sym: ?FUN_0015b6d0@fn_f68d580d@@YIPADPAUS_15b6d0@1@@Z
char* __fastcall FUN_0015b6d0(S_15b6d0* self) {
    return (char*)&self->x;
}


// 0x0015b6e0 FUN_0015b6e0 (4 B): matches/0x0015b6e0.cpp
// sym: ?FUN_0015b6e0@fn_f68d580d@@YIPAXPAVObj_15b6e0@1@@Z
void* __fastcall FUN_0015b6e0(Obj_15b6e0* self) {
    return (char*)self + 0x30;
}

} // namespace fn_f68d580d

// 0x0015b6f0 FUN_0015b6f0 (4 B): matches/0x0015b6f0.cpp
// sym: ?FUN_0015b6f0@Obj_15b6f0@owners@@QAEPAXXZ
void* owners::Obj_15b6f0::FUN_0015b6f0() {
    return (void*)((char*)this + 0x38);
}


// 0x0015b710 FUN_0015b710 (12 B): matches/0x0015b710.cpp
// sym: ?FUN_0015b710@Obj_15b710@owners@@QAE_NH@Z
bool owners::Obj_15b710::FUN_0015b710(int v) {
    mValue = v;
    return true;
}


// 0x0015b730 FUN_0015b730 (12 B): matches/0x0015b730.cpp
// sym: ?FUN_0015b730@Obj_15b730@owners@@QAE_NH@Z
bool owners::Obj_15b730::FUN_0015b730(int v) {
    mVal = v;
    return true;
}


// 0x0015b750 FUN_0015b750 (12 B): matches/0x0015b750.cpp
// sym: ?FUN_0015b750@Obj_15b750@owners@@QAEDH@Z
char owners::Obj_15b750::FUN_0015b750(int a) {
    *(int*)((char*)this + 0x48) = a;
    return 1;
}

namespace fn_f68d580d {

// 0x0015b760 FUN_0015b760 (19 B): matches/0x0015b760.cpp
// sym: ?FUN_0015b760@fn_f68d580d@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0015b760() {
    FUN_00234810(((char*)&DAT_004e1158), ((char*)&DAT_004e115c));
}

} // namespace fn_f68d580d
