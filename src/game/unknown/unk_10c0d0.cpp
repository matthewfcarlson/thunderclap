// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010c0d0..0x0010d080 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f15aa14c {
#define TREE_TU_END }
namespace fn_f15aa14c {} using namespace fn_f15aa14c;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f15aa14c {
class Obj_10c0d0 {
  public:
    char pad[12];
    int mVal;
    char SetCompare_0010c0d0(int v);
};
class Obj_10c0f0 {
  public:
    char pad[0x10];
    unsigned char m10;
    char SetTarget_0010c0f0(unsigned char b);
};
class X_10c110 {
  public:
    char pad[0x14];
    int m14;
    bool SetSmartPropIndex_0010c110(int a);
};
struct Inner_10c120 {
    int x;
};
struct Obj_10c120 {
    char pad[12];
    Inner_10c120& Get();
};
class Obj_10c140 {
  public:
    char pad[12];
    int value;
    bool SetCompare_0010c140(int x);
};
class Obj_10c160 {
  public:
    char pad[0x14];
    float mVal;
    float GetValue();
};
class Obj_10c170 {
  public:
    char pad[0x14];
    unsigned m14;
    unsigned char SetValue_0010c170(unsigned v);
};
class X_10c200 {
  public:
    char pad[0xc];
    int mValue;
    bool SetCompare_0010c200(int v);
};
struct Obj_10c210 {
    char pad[16];
    int value;
};
class X_10c220 {
  public:
    char pad[0x14];
    float value;
    float Get();
};
class X_10c230 {
  public:
    char pad[0x14];
    int m;
    char SetValue_0010c230(int x);
};
class Obj_10c260 {
  public:
    unsigned char Get();
    char pad[0x10];
    unsigned char m10;
};
class O_10c280 {
  public:
    char pad[0xc];
    int m;
    bool SetCompare_0010c280(int x);
};
class C_10c2b0 {
    char pad[0x14];
    int m14;

  public:
    char SetValue_0010c2b0(int x);
};
class Obj_10c2c0 {
  public:
    char pad[12];
    int field;
    bool SetCompare_0010c2c0(int x);
};
class C_10c2e0 {
  public:
    char pad[0x10];
    int m10;
    bool SetDistance_0010c2e0(int x);
};
class T_10c300 {
  public:
    char pad[0x14];
    char mVal;
    char SetNumberofAttachedProps_0010c300(char c);
};
class X_10c320 {
  public:
    char pad[0x18];
    int m18;
    char SetNumber_0010c320(int a);
};
class X_10c3d0 {
  public:
    virtual void f();
    char pad[0x14];
    void* m;
    void* Get();
};
class A_10c4d0 {
  public:
    char SetTimeBegin_0010c4d0(int x);
};
class T_10c4e0 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_0010c4e0(int x);
};
class Obj_10c4f0 {
  public:
    char pad[0x18];
    void* m18;
    void* GetText_0010c4f0();
};
class A_10c510 {
  public:
    char pad[0x20];
    int m;
    bool SetValue_0010c510(int x);
};
class C_10c520 {
  public:
    char pad[0xc];
    int m;
    char SetTimeBegin_0010c520(int x);
};
class Obj_10c530 {
  public:
    char pad[0x10];
    int mValue;
    bool SetTimeEnd_0010c530(int v);
};
class Obj_10c540 {
  public:
    char pad[0x18];
    int* GetKeyword_0010c540();
};
class Obj_10c550 {
  public:
    char pad[32];
    char m20;
    char SetRandomIntroWait_0010c550(char c);
};
class T_10c570 {
  public:
    virtual void V();
    char Set(unsigned int v);
    char pad[0x0c];
    unsigned int val;
};
class Obj_10c5c0 {
  public:
    char pad[0x1c];
    float value;
    float Get();
};
class Obj_10c600 {
  public:
    char pad[0xc];
    int mValue;
    bool SetTimeBegin_0010c600(int v);
};
class X_10c610 {
  public:
    char pad[0x10];
    int m;
    char SetTimeEnd_0010c610(int v);
};
class O_10c620 {
  public:
    char pad[0x14];
    char m14;
    char SetOnlySetAtEnd_0010c620(char c);
};
struct T_10c640 {
    char pad[12];
    int m;
    char SetTimeBegin_0010c640(int x);
};
class Obj_10c650 {
  public:
    char pad[0x10];
    int m10;
    bool SetTimeEnd_0010c650(int x);
};
class Obj_10c670 {
  public:
    char pad[0x14];
    unsigned char m14;
    unsigned char SetFloatDelayOnEnd_0010c670(unsigned char v);
};
class Obj_10c6d0 {
  public:
    char Get();
};
extern int* hulk_at_004e0ae0;
class CCondition_10c730 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0ae8;
class CCondition_10c7a0 {
  public:
    virtual int vfunc_0(int);
};
struct Member_10c7d0 {
    void Release_00234150();
};
struct Condition_10c7d0 {
    virtual void g();
    void Shutdown_002345b0();
};
struct AIFightNodeCondition_10c7d0 : Condition_10c7d0 {
    char pad[8];
    Member_10c7d0 m;
    ~AIFightNodeCondition_10c7d0();
    virtual void f();
};
extern int* hulk_at_004e0af0;
class CCondition_10c810 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0af8;
class CCondition_10c870 {
  public:
    virtual int vfunc_0(int);
};
int __cdecl FUN_0008d340(void *p);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int size);
struct Owner { char pad[0x10]; char *text; hulk_intptr SetText_0010c8d0(const char *source); };
extern int* hulk_at_004e0b00;
class CCondition_10c950 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b08;
class CCondition_10ca30 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b10;
class CCondition_10caa0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
} // namespace fn_f15aa14c
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_f15aa14c {
extern int* hulk_at_004e0b18;
class CCondition_10cb80 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b20;
class CCondition_10cbe0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" void FreeMem_0008d340(void*);
class Obj {
  public:
    char _m_pad_0[0x10];
    char* name;
    char SetText_0010cc40(const char* s);
    char SetText_0010ce60(const char* s);
};
extern int* hulk_at_004e0b28;
class CCondition_10ccc0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b30;
class CCondition_10cda0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b38;
class CCondition_10ce00 {
  public:
    virtual int vfunc_0(int);
};
extern "C" void __cdecl thunk_FUN_00267090(void*);
extern int* hulk_at_004e0b40;
class CCondition_10cee0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b48;
class CCondition_10cf50 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b50;
class CCondition_10cfc0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e0b58;
class CCondition_10d020 {
  public:
    virtual int vfunc_0(int);
};


// 0x0010c0d0 FUN_0010c0d0 (12 B): matches/0x0010c0d0.cpp
// sym: ?SetCompare_0010c0d0@Obj_10c0d0@fn_f15aa14c@@QAEDH@Z
char Obj_10c0d0::SetCompare_0010c0d0(int v) {
    mVal = v;
    return 1;
}


// 0x0010c0f0 FUN_0010c0f0 (12 B): matches/0x0010c0f0.cpp
// sym: ?SetTarget_0010c0f0@Obj_10c0f0@fn_f15aa14c@@QAEDE@Z
char Obj_10c0f0::SetTarget_0010c0f0(unsigned char b) {
    m10 = b;
    return 1;
}


// 0x0010c110 FUN_0010c110 (12 B): matches/0x0010c110.cpp
// sym: ?SetSmartPropIndex_0010c110@X_10c110@fn_f15aa14c@@QAE_NH@Z
bool X_10c110::SetSmartPropIndex_0010c110(int a) {
    m14 = a;
    return true;
}


// 0x0010c120 FUN_0010c120 (4 B): matches/0x0010c120.cpp
// sym: ?Get@Obj_10c120@fn_f15aa14c@@QAEAAUInner_10c120@2@XZ
Inner_10c120& Obj_10c120::Get() {
    return *(Inner_10c120*)((char*)this + 12);
}

} // namespace fn_f15aa14c

// 0x0010c130 FUN_0010c130 (12 B): matches/0x0010c130.cpp
// sym: ?FUN_0010c130@Obj_10c130@owners@@QAE_ND@Z
bool owners::Obj_10c130::FUN_0010c130(char c) {
    value = c;
    return true;
}

namespace fn_f15aa14c {

// 0x0010c140 FUN_0010c140 (12 B): matches/0x0010c140.cpp
// sym: ?SetCompare_0010c140@Obj_10c140@fn_f15aa14c@@QAE_NH@Z
bool Obj_10c140::SetCompare_0010c140(int x) {
    value = x;
    return true;
}


// 0x0010c160 FUN_0010c160 (4 B): matches/0x0010c160.cpp
// sym: ?GetValue@Obj_10c160@fn_f15aa14c@@QAEMXZ
float Obj_10c160::GetValue() {
    return mVal;
}


// 0x0010c170 FUN_0010c170 (12 B): matches/0x0010c170.cpp
// sym: ?SetValue_0010c170@Obj_10c170@fn_f15aa14c@@QAEEI@Z
unsigned char Obj_10c170::SetValue_0010c170(unsigned v) {
    m14 = v;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c180 FUN_0010c180 (12 B): matches/0x0010c180.cpp
// sym: ?FUN_0010c180@A_10c180@owners@@QAEDH@Z
char owners::A_10c180::FUN_0010c180(int x) {
    mVal = x;
    return 1;
}


// 0x0010c1a0 FUN_0010c1a0 (12 B): matches/0x0010c1a0.cpp
// sym: ?FUN_0010c1a0@Obj_10c1a0@owners@@QAEDH@Z
char owners::Obj_10c1a0::FUN_0010c1a0(int v) {
    mVal = v;
    return 1;
}


// 0x0010c1c0 FUN_0010c1c0 (12 B): matches/0x0010c1c0.cpp
// sym: ?FUN_0010c1c0@O_10c1c0@owners@@QAEDH@Z
char owners::O_10c1c0::FUN_0010c1c0(int x) {
    m10 = x;
    return 1;
}


// 0x0010c1d0 FUN_0010c1d0 (12 B): matches/0x0010c1d0.cpp
// sym: ?FUN_0010c1d0@O_10c1d0@owners@@QAEDH@Z
char owners::O_10c1d0::FUN_0010c1d0(int v) {
    m = v;
    return 1;
}


// 0x0010c1f0 FUN_0010c1f0 (12 B): matches/0x0010c1f0.cpp
// sym: ?FUN_0010c1f0@Obj_10c1f0@owners@@QAEDD@Z
char owners::Obj_10c1f0::FUN_0010c1f0(char b) {
    mByte = b;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c200 FUN_0010c200 (12 B): matches/0x0010c200.cpp
// sym: ?SetCompare_0010c200@X_10c200@fn_f15aa14c@@QAE_NH@Z
bool X_10c200::SetCompare_0010c200(int v) {
    mValue = v;
    return true;
}


// 0x0010c210 FUN_0010c210 (4 B): matches/0x0010c210.cpp
// sym: ?FUN_0010c210@fn_f15aa14c@@YIHPAUObj_10c210@1@@Z
int __fastcall FUN_0010c210(Obj_10c210* self) {
    return self->value;
}


// 0x0010c220 FUN_0010c220 (4 B): matches/0x0010c220.cpp
// sym: ?Get@X_10c220@fn_f15aa14c@@QAEMXZ
float X_10c220::Get() {
    return value;
}


// 0x0010c230 FUN_0010c230 (12 B): matches/0x0010c230.cpp
// sym: ?SetValue_0010c230@X_10c230@fn_f15aa14c@@QAEDH@Z
char X_10c230::SetValue_0010c230(int x) {
    m = x;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c240 FUN_0010c240 (12 B): matches/0x0010c240.cpp
// sym: ?FUN_0010c240@O_10c240@owners@@QAEDH@Z
char owners::O_10c240::FUN_0010c240(int x) {
    *(int*)(m + 0xc) = x;
    return 1;
}


// 0x0010c250 FUN_0010c250 (12 B): matches/0x0010c250.cpp
// sym: ?FUN_0010c250@Obj_10c250@owners@@QAEDH@Z
char owners::Obj_10c250::FUN_0010c250(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c260 FUN_0010c260 (4 B): matches/0x0010c260.cpp
// sym: ?Get@Obj_10c260@fn_f15aa14c@@QAEEXZ
unsigned char Obj_10c260::Get() {
    return m10;
}

} // namespace fn_f15aa14c

// 0x0010c270 FUN_0010c270 (12 B): matches/0x0010c270.cpp
// sym: ?FUN_0010c270@X_10c270@owners@@QAEEE@Z
unsigned char owners::X_10c270::FUN_0010c270(unsigned char x) {
    mX = x;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c280 FUN_0010c280 (12 B): matches/0x0010c280.cpp
// sym: ?SetCompare_0010c280@O_10c280@fn_f15aa14c@@QAE_NH@Z
bool O_10c280::SetCompare_0010c280(int x) {
    m = x;
    return true;
}


// 0x0010c2b0 FUN_0010c2b0 (12 B): matches/0x0010c2b0.cpp
// sym: ?SetValue_0010c2b0@C_10c2b0@fn_f15aa14c@@QAEDH@Z
char C_10c2b0::SetValue_0010c2b0(int x) {
    m14 = x;
    return 1;
}


// 0x0010c2c0 FUN_0010c2c0 (12 B): matches/0x0010c2c0.cpp
// sym: ?SetCompare_0010c2c0@Obj_10c2c0@fn_f15aa14c@@QAE_NH@Z
bool Obj_10c2c0::SetCompare_0010c2c0(int x) {
    field = x;
    return true;
}


// 0x0010c2e0 FUN_0010c2e0 (12 B): matches/0x0010c2e0.cpp
// sym: ?SetDistance_0010c2e0@C_10c2e0@fn_f15aa14c@@QAE_NH@Z
bool C_10c2e0::SetDistance_0010c2e0(int x) {
    m10 = x;
    return true;
}


// 0x0010c300 FUN_0010c300 (12 B): matches/0x0010c300.cpp
// sym: ?SetNumberofAttachedProps_0010c300@T_10c300@fn_f15aa14c@@QAEDD@Z
char T_10c300::SetNumberofAttachedProps_0010c300(char c) {
    mVal = c;
    return 1;
}


// 0x0010c320 FUN_0010c320 (12 B): matches/0x0010c320.cpp
// sym: ?SetNumber_0010c320@X_10c320@fn_f15aa14c@@QAEDH@Z
char X_10c320::SetNumber_0010c320(int a) {
    m18 = a;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c330 FUN_0010c330 (12 B): matches/0x0010c330.cpp
// sym: ?FUN_0010c330@Obj_10c330@owners@@QAEDH@Z
char owners::Obj_10c330::FUN_0010c330(int x) {
    *(int*)((char*)this + 12) = x;
    return 1;
}


// 0x0010c350 FUN_0010c350 (12 B): matches/0x0010c350.cpp
// sym: ?FUN_0010c350@Obj_10c350@owners@@QAE_NH@Z
bool owners::Obj_10c350::FUN_0010c350(int x) {
    value = x;
    return true;
}


// 0x0010c370 FUN_0010c370 (12 B): matches/0x0010c370.cpp
// sym: ?FUN_0010c370@Obj_10c370@owners@@QAEDE@Z
char owners::Obj_10c370::FUN_0010c370(unsigned char x) {
    mValue = x;
    return 1;
}


// 0x0010c390 FUN_0010c390 (12 B): matches/0x0010c390.cpp
// sym: ?FUN_0010c390@Obj_10c390@owners@@QAEDE@Z
char owners::Obj_10c390::FUN_0010c390(unsigned char x) {
    v = x;
    return 1;
}


// 0x0010c3a0 FUN_0010c3a0 (12 B): matches/0x0010c3a0.cpp
// sym: ?FUN_0010c3a0@Obj_10c3a0@owners@@QAE_NH@Z
bool owners::Obj_10c3a0::FUN_0010c3a0(int v) {
    value = v;
    return true;
}


// 0x0010c3b0 FUN_0010c3b0 (12 B): matches/0x0010c3b0.cpp
// sym: ?FUN_0010c3b0@Obj_10c3b0@owners@@QAEEH@Z
unsigned char owners::Obj_10c3b0::FUN_0010c3b0(int x) {
    mVal = x;
    return 1;
}


// 0x0010c3c0 FUN_0010c3c0 (12 B): matches/0x0010c3c0.cpp
// sym: ?FUN_0010c3c0@Obj_10c3c0@owners@@QAE_NH@Z
bool owners::Obj_10c3c0::FUN_0010c3c0(int x) {
    value = x;
    return true;
}

namespace fn_f15aa14c {

// 0x0010c3d0 FUN_0010c3d0 (4 B): matches/0x0010c3d0.cpp
// sym: ?Get@X_10c3d0@fn_f15aa14c@@QAEPAXXZ
void* X_10c3d0::Get() {
    return &m;
}

} // namespace fn_f15aa14c

// 0x0010c3f0 FUN_0010c3f0 (12 B): matches/0x0010c3f0.cpp
// sym: ?FUN_0010c3f0@Obj_10c3f0@owners@@QAEDD@Z
char owners::Obj_10c3f0::FUN_0010c3f0(char x) {
    m20 = x;
    return 1;
}


// 0x0010c410 FUN_0010c410 (12 B): matches/0x0010c410.cpp
// sym: ?FUN_0010c410@Obj_10c410@owners@@QAEEE@Z
unsigned char owners::Obj_10c410::FUN_0010c410(unsigned char x) {
    m = x;
    return 1;
}


// 0x0010c420 FUN_0010c420 (12 B): matches/0x0010c420.cpp
// sym: ?FUN_0010c420@X_10c420@owners@@QAEDH@Z
char owners::X_10c420::FUN_0010c420(int v) {
    value = v;
    return 1;
}


// 0x0010c430 FUN_0010c430 (12 B): matches/0x0010c430.cpp
// sym: ?FUN_0010c430@O_10c430@owners@@QAEDH@Z
char owners::O_10c430::FUN_0010c430(int x) {
    m = x;
    return 1;
}


// 0x0010c450 FUN_0010c450 (12 B): matches/0x0010c450.cpp
// sym: ?FUN_0010c450@Obj_10c450@owners@@QAEDD@Z
char owners::Obj_10c450::FUN_0010c450(char x) {
    m14 = x;
    return 1;
}


// 0x0010c470 FUN_0010c470 (12 B): matches/0x0010c470.cpp
// sym: ?FUN_0010c470@X_10c470@owners@@QAE_NH@Z
bool owners::X_10c470::FUN_0010c470(int v) {
    m18 = v;
    return true;
}


// 0x0010c490 FUN_0010c490 (12 B): matches/0x0010c490.cpp
// sym: ?FUN_0010c490@Obj_10c490@owners@@QAEDD@Z
char owners::Obj_10c490::FUN_0010c490(char c) {
    mVal = c;
    return 1;
}


// 0x0010c4b0 FUN_0010c4b0 (12 B): matches/0x0010c4b0.cpp
// sym: ?FUN_0010c4b0@Obj_10c4b0@owners@@QAE_NE@Z
bool owners::Obj_10c4b0::FUN_0010c4b0(unsigned char x) {
    value = x;
    return true;
}


// 0x0010c4c0 FUN_0010c4c0 (12 B): matches/0x0010c4c0.cpp
// sym: ?FUN_0010c4c0@C_10c4c0@owners@@QAEDH@Z
char owners::C_10c4c0::FUN_0010c4c0(int x) {
    mValue = x;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c4d0 FUN_0010c4d0 (12 B): matches/0x0010c4d0.cpp
// sym: ?SetTimeBegin_0010c4d0@A_10c4d0@fn_f15aa14c@@QAEDH@Z
char A_10c4d0::SetTimeBegin_0010c4d0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x0010c4e0 FUN_0010c4e0 (12 B): matches/0x0010c4e0.cpp
// sym: ?SetTimeEnd_0010c4e0@T_10c4e0@fn_f15aa14c@@QAE_NH@Z
bool T_10c4e0::SetTimeEnd_0010c4e0(int x) {
    m10 = x;
    return true;
}


// 0x0010c4f0 FUN_0010c4f0 (4 B): matches/0x0010c4f0.cpp
// sym: ?GetText_0010c4f0@Obj_10c4f0@fn_f15aa14c@@QAEPAXXZ
void* Obj_10c4f0::GetText_0010c4f0() {
    return &m18;
}


// 0x0010c510 FUN_0010c510 (12 B): matches/0x0010c510.cpp
// sym: ?SetValue_0010c510@A_10c510@fn_f15aa14c@@QAE_NH@Z
bool A_10c510::SetValue_0010c510(int x) {
    m = x;
    return true;
}


// 0x0010c520 FUN_0010c520 (12 B): matches/0x0010c520.cpp
// sym: ?SetTimeBegin_0010c520@C_10c520@fn_f15aa14c@@QAEDH@Z
char C_10c520::SetTimeBegin_0010c520(int x) {
    m = x;
    return 1;
}


// 0x0010c530 FUN_0010c530 (12 B): matches/0x0010c530.cpp
// sym: ?SetTimeEnd_0010c530@Obj_10c530@fn_f15aa14c@@QAE_NH@Z
bool Obj_10c530::SetTimeEnd_0010c530(int v) {
    mValue = v;
    return true;
}


// 0x0010c540 FUN_0010c540 (4 B): matches/0x0010c540.cpp
// sym: ?GetKeyword_0010c540@Obj_10c540@fn_f15aa14c@@QAEPAHXZ
int* Obj_10c540::GetKeyword_0010c540() {
    return (int*)((char*)this + 0x18);
}


// 0x0010c550 FUN_0010c550 (12 B): matches/0x0010c550.cpp
// sym: ?SetRandomIntroWait_0010c550@Obj_10c550@fn_f15aa14c@@QAEDD@Z
char Obj_10c550::SetRandomIntroWait_0010c550(char c) {
    m20 = c;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c560 FUN_0010c560 (12 B): matches/0x0010c560.cpp
// sym: ?FUN_0010c560@O_10c560@owners@@QAE_NH@Z
bool owners::O_10c560::FUN_0010c560(int v) {
    m = v;
    return true;
}

namespace fn_f15aa14c {

// 0x0010c570 FUN_0010c570 (12 B): matches/0x0010c570.cpp
// sym: ?Set@T_10c570@fn_f15aa14c@@QAEDI@Z
char T_10c570::Set(unsigned int v) {
    val = v;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c590 FUN_0010c590 (12 B): matches/0x0010c590.cpp
// sym: ?FUN_0010c590@Obj_10c590@owners@@QAE_NH@Z
bool owners::Obj_10c590::FUN_0010c590(int x) {
    m14 = x;
    return true;
}


// 0x0010c5b0 FUN_0010c5b0 (12 B): matches/0x0010c5b0.cpp
// sym: ?FUN_0010c5b0@Obj_10c5b0@owners@@QAEDH@Z
char owners::Obj_10c5b0::FUN_0010c5b0(int x) {
    mValue = x;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c5c0 FUN_0010c5c0 (4 B): matches/0x0010c5c0.cpp
// sym: ?Get@Obj_10c5c0@fn_f15aa14c@@QAEMXZ
float Obj_10c5c0::Get() {
    return value;
}

} // namespace fn_f15aa14c

// 0x0010c5d0 FUN_0010c5d0 (12 B): matches/0x0010c5d0.cpp
// sym: ?FUN_0010c5d0@O_10c5d0@owners@@QAEDH@Z
char owners::O_10c5d0::FUN_0010c5d0(int v) {
    m1c = v;
    return 1;
}


// 0x0010c5f0 FUN_0010c5f0 (12 B): matches/0x0010c5f0.cpp
// sym: ?FUN_0010c5f0@Obj_10c5f0@owners@@QAEDH@Z
char owners::Obj_10c5f0::FUN_0010c5f0(int v) {
    value = v;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c600 FUN_0010c600 (12 B): matches/0x0010c600.cpp
// sym: ?SetTimeBegin_0010c600@Obj_10c600@fn_f15aa14c@@QAE_NH@Z
bool Obj_10c600::SetTimeBegin_0010c600(int v) {
    mValue = v;
    return true;
}


// 0x0010c610 FUN_0010c610 (12 B): matches/0x0010c610.cpp
// sym: ?SetTimeEnd_0010c610@X_10c610@fn_f15aa14c@@QAEDH@Z
char X_10c610::SetTimeEnd_0010c610(int v) {
    m = v;
    return 1;
}


// 0x0010c620 FUN_0010c620 (12 B): matches/0x0010c620.cpp
// sym: ?SetOnlySetAtEnd_0010c620@O_10c620@fn_f15aa14c@@QAEDD@Z
char O_10c620::SetOnlySetAtEnd_0010c620(char c) {
    m14 = c;
    return 1;
}


// 0x0010c630 FUN_0010c630 (4 B): matches/0x0010c630.cpp
// sym: @GetText_0010c630@4
extern "C" char* __fastcall GetText_0010c630(void* self) {
    return (char*)self + 0x18;
}


// 0x0010c640 FUN_0010c640 (12 B): matches/0x0010c640.cpp
// sym: ?SetTimeBegin_0010c640@T_10c640@fn_f15aa14c@@QAEDH@Z
char T_10c640::SetTimeBegin_0010c640(int x) {
    m = x;
    return 1;
}


// 0x0010c650 FUN_0010c650 (12 B): matches/0x0010c650.cpp
// sym: ?SetTimeEnd_0010c650@Obj_10c650@fn_f15aa14c@@QAE_NH@Z
bool Obj_10c650::SetTimeEnd_0010c650(int x) {
    m10 = x;
    return true;
}


// 0x0010c670 FUN_0010c670 (12 B): matches/0x0010c670.cpp
// sym: ?SetFloatDelayOnEnd_0010c670@Obj_10c670@fn_f15aa14c@@QAEEE@Z
unsigned char Obj_10c670::SetFloatDelayOnEnd_0010c670(unsigned char v) {
    m14 = v;
    return 1;
}

} // namespace fn_f15aa14c

// 0x0010c680 FUN_0010c680 (12 B): matches/0x0010c680.cpp
// sym: ?FUN_0010c680@T_10c680@owners@@QAE_NH@Z
bool owners::T_10c680::FUN_0010c680(int a) {
    m_c = a;
    return true;
}


// 0x0010c690 FUN_0010c690 (12 B): matches/0x0010c690.cpp
// sym: ?FUN_0010c690@Obj_10c690@owners@@QAEDH@Z
char owners::Obj_10c690::FUN_0010c690(int x) {
    value = x;
    return 1;
}


// 0x0010c6a0 FUN_0010c6a0 (4 B): matches/0x0010c6a0.cpp
// sym: ?FUN_0010c6a0@Obj_10c6a0@owners@@QAEPADXZ
char* owners::Obj_10c6a0::FUN_0010c6a0() {
    return (char*)this + 0x18;
}


// 0x0010c6c0 FUN_0010c6c0 (12 B): matches/0x0010c6c0.cpp
// sym: ?FUN_0010c6c0@Obj_10c6c0@owners@@QAE_ND@Z
bool owners::Obj_10c6c0::FUN_0010c6c0(char v) {
    m20 = v;
    return true;
}

namespace fn_f15aa14c {

// 0x0010c6d0 FUN_0010c6d0 (4 B): matches/0x0010c6d0.cpp
// sym: ?Get@Obj_10c6d0@fn_f15aa14c@@QAEDXZ
char Obj_10c6d0::Get() {
    return *(char*)((char*)this + 0x21);
}

} // namespace fn_f15aa14c

// 0x0010c6e0 FUN_0010c6e0 (12 B): matches/0x0010c6e0.cpp
// sym: ?FUN_0010c6e0@Obj_10c6e0@owners@@QAEDD@Z
char owners::Obj_10c6e0::FUN_0010c6e0(char c) {
    m21 = c;
    return 1;
}


// 0x0010c700 FUN_0010c700 (12 B): matches/0x0010c700.cpp
// sym: ?FUN_0010c700@O_10c700@owners@@QAEDH@Z
char owners::O_10c700::FUN_0010c700(int v) {
    m24 = v;
    return 1;
}

namespace fn_f15aa14c {

// 0x0010c710 FUN_0010c710 (19 B): matches/0x0010c710.cpp
// sym: ?FUN_0010c710@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010c710() {
    FUN_00234810(((char*)&DAT_004e0ae0), ((char*)&DAT_004e0ae4));
}

} // namespace fn_f15aa14c

// 0x0010c730 hulkfight::ai::OnBlockedTriangleCondition::vfunc_0 (16 B): matches/0x0010c730.cpp
// sym: ?vfunc_0@OnBlockedTriangleCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::OnBlockedTriangleCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0ae0;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010c780 FUN_0010c780 (19 B): matches/0x0010c780.cpp
// sym: ?FUN_0010c780@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010c780() {
    FUN_00234810(((char*)&DAT_004e0ae8), ((char*)&DAT_004e0aec));
}

} // namespace fn_f15aa14c

// 0x0010c7a0 hulkfight::ai::AIFightNodeCondition::vfunc_0 (16 B): matches/0x0010c7a0.cpp
// sym: ?vfunc_0@AIFightNodeCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AIFightNodeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0ae8;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010c7d0 FUN_0010c7d0 (25 B): matches/0x0010c7d0.cpp
// sym: ??1AIFightNodeCondition_10c7d0@fn_f15aa14c@@QAE@XZ
AIFightNodeCondition_10c7d0::~AIFightNodeCondition_10c7d0() {
    m.Release_00234150();
    Shutdown_002345b0();
}


// 0x0010c7f0 FUN_0010c7f0 (19 B): matches/0x0010c7f0.cpp
// sym: ?FUN_0010c7f0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010c7f0() {
    FUN_00234810(((char*)&DAT_004e0af0), ((char*)&DAT_004e0af4));
}

} // namespace fn_f15aa14c

// 0x0010c810 hulkfight::ai::DefendingCondition::vfunc_0 (16 B): matches/0x0010c810.cpp
// sym: ?vfunc_0@DefendingCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::DefendingCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0af0;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010c850 FUN_0010c850 (19 B): matches/0x0010c850.cpp
// sym: ?FUN_0010c850@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010c850() {
    FUN_00234810(((char*)&DAT_004e0af8), ((char*)&DAT_004e0afc));
}

} // namespace fn_f15aa14c

// 0x0010c870 hulkfight::ai::AIHistoryNameCondition::vfunc_0 (16 B): matches/0x0010c870.cpp
// sym: ?vfunc_0@AIHistoryNameCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::AIHistoryNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0af8;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010c8b0 FUN_0010c8b0 (29 B): matches/0x0010c8b0.cpp
// sym: ?run@CRawScript@fn_f15aa14c@@QAEXXZ
// Same code shape as 0x000f99b0 (propagated; names are from that function)
void CRawScript::run() {
    vptr = &rawVtable;
    thunk(mArg);
    finish();
}


// 0x0010c8d0 FUN_0010c8d0 (82 B): equivalent/0x0010c8d0.cpp
// sym: ?SetText_0010c8d0@Owner@fn_f15aa14c@@QAEHPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// SetText_0010c8d0 @ 0x0010c8d0
hulk_intptr Owner::SetText_0010c8d0(const char *source) {
    int freed = FUN_0008d340(text);
    if (!source) { text = 0; return (freed & ~255) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = destination;
    char *current = destination;
    do { *current++ = *source; } while (*source++);
    return ((hulk_intptr)destination & ~255) | 1;
}


// 0x0010c930 FUN_0010c930 (19 B): matches/0x0010c930.cpp
// sym: ?FUN_0010c930@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010c930() {
    FUN_00234810(((char*)&DAT_004e0b00), ((char*)&DAT_004e0b04));
}

} // namespace fn_f15aa14c

// 0x0010c950 hulkfight::ai::HulkActionLargestCondition::vfunc_0 (16 B): matches/0x0010c950.cpp
// sym: ?vfunc_0@HulkActionLargestCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HulkActionLargestCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b00;
    return p[index];
}


// 0x0010c990 FUN_0010c990 (29 B): matches/0x0010c990.cpp [wrapped: same definition as 0x0010c8b0 in this TU]
// sym: ?run@CRawScript@fn_0010c990@@QAEXXZ
namespace fn_0010c990 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_0040da04;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_002345b0();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_0040da04;
    thunk_0008d340(mArg);
    finish_002345b0();
}
} // namespace fn_0010c990

namespace fn_f15aa14c {

// 0x0010ca10 FUN_0010ca10 (19 B): matches/0x0010ca10.cpp
// sym: ?FUN_0010ca10@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010ca10() {
    FUN_00234810(((char*)&DAT_004e0b08), ((char*)&DAT_004e0b0c));
}

} // namespace fn_f15aa14c

// 0x0010ca30 hulkfight::ai::PropsToChuckCondition::vfunc_0 (16 B): matches/0x0010ca30.cpp
// sym: ?vfunc_0@PropsToChuckCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::PropsToChuckCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b08;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010ca80 FUN_0010ca80 (19 B): matches/0x0010ca80.cpp
// sym: ?FUN_0010ca80@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010ca80() {
    FUN_00234810(((char*)&DAT_004e0b10), ((char*)&DAT_004e0b14));
}

} // namespace fn_f15aa14c

// 0x0010caa0 hulkfight::ai::HulkActionRecentCondition::vfunc_0 (16 B): matches/0x0010caa0.cpp
// sym: ?vfunc_0@HulkActionRecentCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HulkActionRecentCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b10;
    return p[index];
}


// 0x0010cae0 FUN_0010cae0 (29 B): matches/0x0010cae0.cpp [wrapped: same definition as 0x0010c8b0 in this TU]
// sym: ?run@CRawScript@fn_0010cae0@@QAEXXZ
namespace fn_0010cae0 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_0040da44;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_002345b0();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_0040da44;
    thunk_0008d340(mArg);
    finish_002345b0();
}
} // namespace fn_0010cae0


// 0x0010cb00 FUN_0010cb00 (82 B): matches/0x0010cb00.cpp
// sym: ?FUN_0010cb00@Obj_10cb00@owners@@QAEDPBD@Z
char owners::Obj_10cb00::FUN_0010cb00(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)Alloc(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}

namespace fn_f15aa14c {

// 0x0010cb60 FUN_0010cb60 (19 B): matches/0x0010cb60.cpp
// sym: ?FUN_0010cb60@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cb60() {
    FUN_00234810(((char*)&DAT_004e0b18), ((char*)&DAT_004e0b1c));
}

} // namespace fn_f15aa14c

// 0x0010cb80 hulkfight::ai::LeashedCondition::vfunc_0 (16 B): matches/0x0010cb80.cpp
// sym: ?vfunc_0@LeashedCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::LeashedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b18;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010cbc0 FUN_0010cbc0 (19 B): matches/0x0010cbc0.cpp
// sym: ?FUN_0010cbc0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cbc0() {
    FUN_00234810(((char*)&DAT_004e0b20), ((char*)&DAT_004e0b24));
}

} // namespace fn_f15aa14c

// 0x0010cbe0 hulkfight::ai::KeyWordWaitCondition::vfunc_0 (16 B): matches/0x0010cbe0.cpp
// sym: ?vfunc_0@KeyWordWaitCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::KeyWordWaitCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b20;
    return p[index];
}


// 0x0010cc20 FUN_0010cc20 (29 B): matches/0x0010cc20.cpp [wrapped: same definition as 0x0010c8b0 in this TU]
// sym: ?run@CRawScript@fn_0010cc20@@QAEXXZ
namespace fn_0010cc20 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_0040da84;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_002345b0();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_0040da84;
    thunk_0008d340(mArg);
    finish_002345b0();
}
} // namespace fn_0010cc20

namespace fn_f15aa14c {

// 0x0010cc40 FUN_0010cc40 (82 B): matches/0x0010cc40.cpp
// sym: ?SetText_0010cc40@Obj@fn_f15aa14c@@QAEDPBD@Z
char Obj::SetText_0010cc40(const char* s) {
    FreeMem_0008d340(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)AllocMem(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}


// 0x0010cca0 FUN_0010cca0 (19 B): matches/0x0010cca0.cpp
// sym: ?FUN_0010cca0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cca0() {
    FUN_00234810(((char*)&DAT_004e0b28), ((char*)&DAT_004e0b2c));
}

} // namespace fn_f15aa14c

// 0x0010ccc0 hulkfight::ai::FormationReadyCondition::vfunc_0 (16 B): matches/0x0010ccc0.cpp
// sym: ?vfunc_0@FormationReadyCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::FormationReadyCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b28;
    return p[index];
}


// 0x0010cd00 FUN_0010cd00 (29 B): matches/0x0010cd00.cpp [wrapped: same definition as 0x0010c8b0 in this TU]
// sym: ?run@CRawScript@fn_0010cd00@@QAEXXZ
namespace fn_0010cd00 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_0040daa4;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_002345b0();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_0040daa4;
    thunk_0008d340(mArg);
    finish_002345b0();
}
} // namespace fn_0010cd00

namespace fn_f15aa14c {

// 0x0010cd80 FUN_0010cd80 (19 B): matches/0x0010cd80.cpp
// sym: ?FUN_0010cd80@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cd80() {
    FUN_00234810(((char*)&DAT_004e0b30), ((char*)&DAT_004e0b34));
}

} // namespace fn_f15aa14c

// 0x0010cda0 hulkfight::ai::InActiveCondition::vfunc_0 (16 B): matches/0x0010cda0.cpp
// sym: ?vfunc_0@InActiveCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::InActiveCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b30;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010cde0 FUN_0010cde0 (19 B): matches/0x0010cde0.cpp
// sym: ?FUN_0010cde0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cde0() {
    FUN_00234810(((char*)&DAT_004e0b38), ((char*)&DAT_004e0b3c));
}

} // namespace fn_f15aa14c

// 0x0010ce00 hulkfight::ai::HulkActionCountCondition::vfunc_0 (16 B): matches/0x0010ce00.cpp
// sym: ?vfunc_0@HulkActionCountCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::HulkActionCountCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b38;
    return p[index];
}


// 0x0010ce40 FUN_0010ce40 (29 B): matches/0x0010ce40.cpp [wrapped: same definition as 0x0010c8b0 in this TU]
// sym: ?run@CRawScript@fn_0010ce40@@QAEXXZ
namespace fn_0010ce40 {
// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int hulk_at_0040dae4;
class CRawScript {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish_002345b0();
    void run();
};
extern void __cdecl thunk_0008d340(int);
void CRawScript::run() {
    vptr = &hulk_at_0040dae4;
    thunk_0008d340(mArg);
    finish_002345b0();
}
} // namespace fn_0010ce40

namespace fn_f15aa14c {

// 0x0010ce60 FUN_0010ce60 (82 B): matches/0x0010ce60.cpp
// sym: ?SetText_0010ce60@Obj@fn_f15aa14c@@QAEDPBD@Z
char Obj::SetText_0010ce60(const char* s) {
    thunk_FUN_00267090(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}


// 0x0010cec0 FUN_0010cec0 (19 B): matches/0x0010cec0.cpp
// sym: ?FUN_0010cec0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cec0() {
    FUN_00234810(((char*)&DAT_004e0b40), ((char*)&DAT_004e0b44));
}

} // namespace fn_f15aa14c

// 0x0010cee0 hulkfight::ai::PropsToSuckCondition::vfunc_0 (16 B): matches/0x0010cee0.cpp
// sym: ?vfunc_0@PropsToSuckCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::PropsToSuckCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b40;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010cf30 FUN_0010cf30 (19 B): matches/0x0010cf30.cpp
// sym: ?FUN_0010cf30@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cf30() {
    FUN_00234810(((char*)&DAT_004e0b48), ((char*)&DAT_004e0b4c));
}

} // namespace fn_f15aa14c

// 0x0010cf50 hulkfight::ai::RandomKeyWordWaitCondition::vfunc_0 (16 B): matches/0x0010cf50.cpp
// sym: ?vfunc_0@RandomKeyWordWaitCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::RandomKeyWordWaitCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b48;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010cfa0 FUN_0010cfa0 (19 B): matches/0x0010cfa0.cpp
// sym: ?FUN_0010cfa0@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010cfa0() {
    FUN_00234810(((char*)&DAT_004e0b50), ((char*)&DAT_004e0b54));
}

} // namespace fn_f15aa14c

// 0x0010cfc0 hulkfight::ai::TokenCondition::vfunc_0 (16 B): matches/0x0010cfc0.cpp
// sym: ?vfunc_0@TokenCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::TokenCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b50;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010d000 FUN_0010d000 (19 B): matches/0x0010d000.cpp
// sym: ?FUN_0010d000@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d000() {
    FUN_00234810(((char*)&DAT_004e0b58), ((char*)&DAT_004e0b5c));
}

} // namespace fn_f15aa14c

// 0x0010d020 hulkfight::ai::FightingOtherNPCCondition::vfunc_0 (16 B): matches/0x0010d020.cpp
// sym: ?vfunc_0@FightingOtherNPCCondition@ai@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::ai::FightingOtherNPCCondition::vfunc_0(int index) {
    int* p = hulk_at_004e0b58;
    return p[index];
}

namespace fn_f15aa14c {

// 0x0010d060 FUN_0010d060 (19 B): matches/0x0010d060.cpp
// sym: ?FUN_0010d060@fn_f15aa14c@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0010d060() {
    FUN_00234810(((char*)&DAT_004e0b60), ((char*)&DAT_004e0b64));
}

} // namespace fn_f15aa14c
