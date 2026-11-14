// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017f2b0..0x00180b60 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4259b06 {
#define TREE_TU_END }
namespace fn_f4259b06 {} using namespace fn_f4259b06;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f4259b06 {
class C_17f430 {
  public:
    char pad[12];
    int mValue;
    bool SetAttachmentIndex_0017f430(int value);
};
class Obj_17f450 {
  public:
    char pad[0x10];
    hulk_intptr m10;
    bool SetCompare_0017f450(void* p);
};
class Obj_17f460 {
  public:
    char pad[0x18];
    char* GetState_0017f460();
};
class Obj_17f490 {
  public:
    char Set(int v);
    char pad[12];
};
class Obj_17f4b0 {
  public:
    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;
    char m8;
    char m9;
    char m10;
    char pad[4];
    int mValue;
    char Set(int v);
};
class Obj_17f4c0 {
  public:
    char pad[0x18];
    int mVal;
    int* Get();
};
class C_17f4e0 {
  public:
    char Set(int x);
    char pad[32];
    int m20;
};
class Obj_17f550 {
  public:
    char pad[0xc];
    void* value;
    bool SetAttachmentIndex_0017f550(void* p);
};
class C_17f570 {
  public:
    char Pad[0x10];
    int m;
    char SetCompare_0017f570(int);
};
struct T_17f580 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* GetState_0017f580();
    char pad[24];
};
class Obj_17f5a0 {
  public:
    bool SetAttachmentIndex_0017f5a0(int x);
    char pad[12];
    int m_field;
};
class X_17f5c0 {
  public:
    char pad[16];
    char SetCompare_0017f5c0(int value);
};
class C_17f5e0 {
    char pad[0x14];
    int m;

  public:
    char SetState_0017f5e0(int x);
};
class Obj_17f600 {
  public:
    char pad[12];
    int mValue;
    bool Set(int v);
};
class Obj_17f620 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};
class Obj_17f640 {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};
class Obj_17f6b0 {
  public:
    char SetTimeBegin_0017f6b0(int x);
    char m[0xc];
};
class Obj_17f6d0 {
  public:
    char pad[0x10];
    int mVal;
    char SetAttachmentIndex_0017f6d0(int v);
};
class Target_17f6f0 {
  public:
    char pad[0x14];
    bool SetSimulate_0017f6f0(unsigned char value);
};
class Obj_17f710 {
  public:
    char pad[0x15];
    char m15;
    unsigned char SetAtEnd_0017f710(unsigned char value);
};
class Obj_17f720 {
  public:
    char pad[0xc];
    int m12;
    bool Set(int v);
};
class Obj_17f740 {
  public:
    char pad[0x10];
    int mValue;
    bool Set(int value);
};
class Obj_17f750 {
  public:
    char pad[0x18];
    char* mPtr;
    char** Get();
};
struct Sub_17f800 {
    int* Get() { return (int*)((char*)this + 0x18); }
};
class Obj_17f800 {
  public:
    char pad[0x18];
    Sub_17f800* GetField();
};
class X_17f890 {
  public:
    char pad[0x0c];
    int value;
    char SetTimeBegin_0017f890(int v);
};
class Obj_17f8b0 {
  public:
    char pad[0x10];
    int value;
    bool SetAttachmentIndex_0017f8b0(int x);
};
class X_17f8d0 {
  public:
    char m[0x14];
    int mVal;
    char SetDamage_0017f8d0(int v);
};
class Obj_17f8f0 {
  public:
    char pad[0x18];
    int mVal;
    char SetDamageMax_0017f8f0(int v);
};
struct X_17f940 {
    char pad[0x18];
    unsigned char value;
    unsigned char Get();
};
struct Vec3_17f980 {
    int x, y, z;
};
class Obj_17f980 {
  public:
    char pad[0x1c];
    int a;
    int b;
    int c;
    bool Set(Vec3_17f980* v);
};
extern const float DEG_TO_RAD = 0.017453292519943295f;
class Thing_17fc00 {
  public:
    void* Get() { return ((char*)this) + 0x78; }
};
struct T_17fd40 {
    int a;
    int b;
    int c;
};
class Obj_17fd40 {
  public:
    char pad[0x2c];
    T_17fd40 m;
    bool FUN_0017fd40(const T_17fd40* p);
};
struct S_17fd80 {
    int a, b, c;
};
class C_17fd80 {
  public:
    char Pad[0x38];
    int v38;
    int v3c;
    int v40;
    char Set(S_17fd80* p);
};
struct Vec3_17fdd0 {
    int a, b, c;
};
class X_17fdd0 {
  public:
    char pad[0x50];
    Vec3_17fdd0 v;
    bool Set(Vec3_17fdd0* src);
};
struct Data_17fe20 {
    int a;
    int b;
    int c;
};
class Obj_17fe20 {
  public:
    char pad[0x68];
    Data_17fe20 d;
    bool Set(Data_17fe20* src);
};
class Thing {
  public:
    char pad[12];
    int value;
    bool SetTimeBegin_0017fe40(int v);
};
class Obj_17fe60 {
  public:
    char pad[0x10];
    int mField;
    char SetAttachmentIndex_0017fe60(int value);
};
class C_17fe80 {
  public:
    char pad[0x14];
    int m;
    bool SetState_0017fe80(int x);
};
struct Src_17fef0 {
    int a;
    int b;
    int c;
};
class Obj_17fef0 {
  public:
    char pad[0x18];
    int x;
    int y;
    int z;
    bool Set(const Src_17fef0* p);
};
struct Src_17ff30 {
    int a;
    int b;
    int c;
};
class Obj_17ff30 {
  public:
    virtual void Dummy();
    char pad[0x24 - 4];
    Src_17ff30 m;
    bool Copy(Src_17ff30* p);
};
struct Vec3_1800f0 {
    int x, y, z;
};
class Obj_1800f0 {
  public:
    char pad[0x68];
    Vec3_1800f0 v;
    bool Set(const Vec3_1800f0* p);
};
struct Field {
    int a, b, c;
};
extern const float Rad = 0.017453292f;
class Obj_180340 {
  public:
    char pad[12];
    int mValue;
    char Fn(int x);
};
class X_180360 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};
class X_180380 {
  public:
    char pad[0x14];
    char m;
    char Set(char c);
};
class T_180390 {
  public:
    virtual void V();
    char SetTimeBegin_00180390(int x);
    char pad[8];
    int mC;
};
class A_1803b0 {
  public:
    char p[0x10];
    int m;
    char SetAttachmentIndex_001803b0(int x);
};
class Obj_1803d0 {
  public:
    char pad[0x14];
    int m14;
    bool SetMissiles_001803d0(int a);
};
class Obj_1803e0 {
  public:
    char pad[12];
    int field;
    char SetTimeBegin_001803e0(int value);
};
struct X_180400 {
    virtual void V();
    char pad[12];
    int m10;
    bool SetAttachmentIndex_00180400(int a);
};
class Obj_180420 {
  public:
    char pad[0x14];
    int value;
    char SetDamage_00180420(int x);
};
class Obj_180440 {
  public:
    char pad[0x10];
    int value;
    int Get();
};
struct Vec3_180480 {
    int x, y, z;
};
class Obj_180480 {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3_180480* v);
};
struct Vec {
    float x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0x2c];
    volatile float x;
    volatile float y;
    volatile float z;
    char _m_pad_38[0x48];
    int f80;
    int f84;
    int f88;
    char Set(Field* p);
    char Set(const Vec* v);
};
struct S_180520 {
    int a, b, c;
};
class O_180520 {
    char pad[0x38];
    int x, y, z;

  public:
    bool Set(S_180520* p);
};
struct T_180560 {
    int a;
    int b;
    int c;
};
class O_180560 {
  public:
    char pad[0x44];
    int m44;
    int m48;
    int m4c;
    bool Set(T_180560* p);
};
extern int* hulk_at_004e1400;
class CCondition_1805d0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1408;
class CCondition_180630 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1410;
class CCondition_1806b0 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_1806f0 {
    void Init_0027af50();
};
struct GrapplePropStateByNameCondition_1806f0 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_0041916c;
extern int* hulk_at_004e1418;
class CCondition_180730 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1420;
class CCondition_180790 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_1807e0 {
    void Init_0027af50();
};
struct PropMassCondition_1807e0 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_004191ac;
extern int* hulk_at_004e1428;
class CCondition_180820 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1430;
class CCondition_180880 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1438;
class CCondition_1808e0 {
  public:
    virtual int vfunc_0(int);
};
struct Tail_180920 {
    void Init_0027af50();
};
struct PropStateByNameCondition_180920 {
    void* vptr;
    char pad[0x14];
    void Finish_002345b0();
    void Run();
};
extern void* hulk_at_0041920c;
extern int* hulk_at_004e1440;
class CCondition_180960 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1448;
class CCondition_1809d0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1450;
class CCondition_180a40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1458;
class CCondition_180aa0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1460;
class CCondition_180b00 {
  public:
    virtual int vfunc_0(int);
};
class Condition_180b30 {
  public:
    virtual ~Condition_180b30() throw();
};
class CSMPropIsCharacterCondition : public Condition_180b30 {
  public:
    virtual ~CSMPropIsCharacterCondition() throw();
};

} // namespace fn_f4259b06

// 0x0017f2b0 FUN_0017f2b0 (12 B): matches/0x0017f2b0.cpp
// sym: ?FUN_0017f2b0@Obj_17f2b0@owners@@QAEDH@Z
char owners::Obj_17f2b0::FUN_0017f2b0(int v) {
    value = v;
    return 1;
}


// 0x0017f2d0 FUN_0017f2d0 (12 B): matches/0x0017f2d0.cpp
// sym: ?FUN_0017f2d0@O_17f2d0@owners@@QAEED@Z
unsigned char owners::O_17f2d0::FUN_0017f2d0(char x) {
    v = x;
    return 1;
}


// 0x0017f2f0 FUN_0017f2f0 (12 B): matches/0x0017f2f0.cpp
// sym: ?FUN_0017f2f0@Obj_17f2f0@owners@@QAEDD@Z
char owners::Obj_17f2f0::FUN_0017f2f0(char c) {
    m_val = c;
    return 1;
}


// 0x0017f310 FUN_0017f310 (12 B): matches/0x0017f310.cpp
// sym: ?FUN_0017f310@Obj_17f310@owners@@QAEDH@Z
char owners::Obj_17f310::FUN_0017f310(int v) {
    mVal = v;
    return 1;
}


// 0x0017f330 FUN_0017f330 (12 B): matches/0x0017f330.cpp
// sym: ?FUN_0017f330@Obj_17f330@owners@@QAEDD@Z
char owners::Obj_17f330::FUN_0017f330(char x) {
    m14 = x;
    return 1;
}


// 0x0017f350 FUN_0017f350 (12 B): matches/0x0017f350.cpp
// sym: ?FUN_0017f350@X_17f350@owners@@QAEDE@Z
char owners::X_17f350::FUN_0017f350(unsigned char b) {
    value = b;
    return 1;
}


// 0x0017f370 FUN_0017f370 (12 B): matches/0x0017f370.cpp
// sym: ?FUN_0017f370@X_17f370@owners@@QAEDD@Z
char owners::X_17f370::FUN_0017f370(char c) {
    m = c;
    return 1;
}


// 0x0017f390 FUN_0017f390 (12 B): matches/0x0017f390.cpp
// sym: ?FUN_0017f390@Obj_17f390@owners@@QAE_NH@Z
bool owners::Obj_17f390::FUN_0017f390(int value) {
    mValue = value;
    return true;
}


// 0x0017f3b0 FUN_0017f3b0 (12 B): matches/0x0017f3b0.cpp
// sym: ?FUN_0017f3b0@Obj_17f3b0@owners@@QAEDD@Z
char owners::Obj_17f3b0::FUN_0017f3b0(char a) {
    v = a;
    return 1;
}


// 0x0017f3d0 FUN_0017f3d0 (12 B): matches/0x0017f3d0.cpp
// sym: ?FUN_0017f3d0@Obj_17f3d0@owners@@QAE_NH@Z
bool owners::Obj_17f3d0::FUN_0017f3d0(int value) {
    m20 = value;
    return true;
}


// 0x0017f3f0 FUN_0017f3f0 (12 B): matches/0x0017f3f0.cpp
// sym: ?FUN_0017f3f0@Obj_17f3f0@owners@@QAEEE@Z
unsigned char owners::Obj_17f3f0::FUN_0017f3f0(unsigned char a) {
    val = a;
    return 1;
}


// 0x0017f410 FUN_0017f410 (12 B): matches/0x0017f410.cpp
// sym: ?FUN_0017f410@Obj_17f410@owners@@QAE_NH@Z
bool owners::Obj_17f410::FUN_0017f410(int x) {
    value = x;
    return true;
}

namespace fn_f4259b06 {

// 0x0017f430 FUN_0017f430 (12 B): matches/0x0017f430.cpp
// sym: ?SetAttachmentIndex_0017f430@C_17f430@fn_f4259b06@@QAE_NH@Z
bool C_17f430::SetAttachmentIndex_0017f430(int value) {
    mValue = value;
    return true;
}


// 0x0017f450 FUN_0017f450 (12 B): matches/0x0017f450.cpp
// sym: ?SetCompare_0017f450@Obj_17f450@fn_f4259b06@@QAE_NPAX@Z
bool Obj_17f450::SetCompare_0017f450(void* p) {
    m10 = (hulk_intptr)p;
    return true;
}


// 0x0017f460 FUN_0017f460 (4 B): matches/0x0017f460.cpp
// sym: ?GetState_0017f460@Obj_17f460@fn_f4259b06@@QAEPADXZ
char* Obj_17f460::GetState_0017f460() {
    return (char*)((hulk_intptr)this + 0x18);
}

} // namespace fn_f4259b06

// 0x0017f470 FUN_0017f470 (12 B): matches/0x0017f470.cpp
// sym: ?FUN_0017f470@X_17f470@owners@@QAEEE@Z
unsigned char owners::X_17f470::FUN_0017f470(unsigned char v) {
    m = v;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017f490 FUN_0017f490 (12 B): matches/0x0017f490.cpp
// sym: ?Set@Obj_17f490@fn_f4259b06@@QAEDH@Z
char Obj_17f490::Set(int v) {
    *(int*)((char*)this + 0xc) = v;
    return 1;
}


// 0x0017f4b0 FUN_0017f4b0 (12 B): matches/0x0017f4b0.cpp
// sym: ?Set@Obj_17f4b0@fn_f4259b06@@QAEDH@Z
char Obj_17f4b0::Set(int v) {
    mValue = v;
    return 1;
}


// 0x0017f4c0 FUN_0017f4c0 (4 B): matches/0x0017f4c0.cpp
// sym: ?Get@Obj_17f4c0@fn_f4259b06@@QAEPAHXZ
int* Obj_17f4c0::Get() {
    return &mVal;
}


// 0x0017f4e0 FUN_0017f4e0 (12 B): matches/0x0017f4e0.cpp
// sym: ?Set@C_17f4e0@fn_f4259b06@@QAEDH@Z
char C_17f4e0::Set(int x) {
    m20 = x;
    return 1;
}

} // namespace fn_f4259b06

// 0x0017f500 FUN_0017f500 (12 B): matches/0x0017f500.cpp
// sym: ?FUN_0017f500@A_17f500@owners@@QAEDD@Z
char owners::A_17f500::FUN_0017f500(char p) {
    mField = p;
    return 1;
}


// 0x0017f520 FUN_0017f520 (12 B): matches/0x0017f520.cpp
// sym: ?FUN_0017f520@Obj_17f520@owners@@QAE_NH@Z
bool owners::Obj_17f520::FUN_0017f520(int value) {
    mField = value;
    return true;
}


// 0x0017f530 FUN_0017f530 (12 B): matches/0x0017f530.cpp
// sym: ?FUN_0017f530@Obj_17f530@owners@@QAEEE@Z
unsigned char owners::Obj_17f530::FUN_0017f530(unsigned char x) {
    value = x;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017f550 FUN_0017f550 (12 B): matches/0x0017f550.cpp
// sym: ?SetAttachmentIndex_0017f550@Obj_17f550@fn_f4259b06@@QAE_NPAX@Z
bool Obj_17f550::SetAttachmentIndex_0017f550(void* p) {
    value = p;
    return true;
}


// 0x0017f570 FUN_0017f570 (12 B): matches/0x0017f570.cpp
// sym: ?SetCompare_0017f570@C_17f570@fn_f4259b06@@QAEDH@Z
char C_17f570::SetCompare_0017f570(int x) {
    m = x;
    return 1;
}


// 0x0017f580 FUN_0017f580 (4 B): matches/0x0017f580.cpp
// sym: ?GetState_0017f580@T_17f580@fn_f4259b06@@UAEPADXZ
char* T_17f580::GetState_0017f580() {
    return (char*)this + 0x18;
}


// 0x0017f5a0 FUN_0017f5a0 (12 B): matches/0x0017f5a0.cpp
// sym: ?SetAttachmentIndex_0017f5a0@Obj_17f5a0@fn_f4259b06@@QAE_NH@Z
bool Obj_17f5a0::SetAttachmentIndex_0017f5a0(int x) {
    m_field = x;
    return true;
}


// 0x0017f5c0 FUN_0017f5c0 (12 B): matches/0x0017f5c0.cpp
// sym: ?SetCompare_0017f5c0@X_17f5c0@fn_f4259b06@@QAEDH@Z
char X_17f5c0::SetCompare_0017f5c0(int value) {
    *(int*)((char*)this + 0x10) = value;
    return 1;
}


// 0x0017f5e0 FUN_0017f5e0 (12 B): matches/0x0017f5e0.cpp
// sym: ?SetState_0017f5e0@C_17f5e0@fn_f4259b06@@QAEDH@Z
char C_17f5e0::SetState_0017f5e0(int x) {
    m = x;
    return 1;
}


// 0x0017f600 FUN_0017f600 (12 B): matches/0x0017f600.cpp
// sym: ?Set@Obj_17f600@fn_f4259b06@@QAE_NH@Z
bool Obj_17f600::Set(int v) {
    mValue = v;
    return true;
}


// 0x0017f620 FUN_0017f620 (12 B): matches/0x0017f620.cpp
// sym: ?Set@Obj_17f620@fn_f4259b06@@QAE_NH@Z
bool Obj_17f620::Set(int x) {
    m10 = x;
    return true;
}


// 0x0017f640 FUN_0017f640 (12 B): matches/0x0017f640.cpp
// sym: ?Set@Obj_17f640@fn_f4259b06@@QAE_NH@Z
bool Obj_17f640::Set(int x) {
    m = x;
    return true;
}

} // namespace fn_f4259b06

// 0x0017f660 FUN_0017f660 (12 B): matches/0x0017f660.cpp
// sym: ?FUN_0017f660@Obj_17f660@owners@@QAE_NH@Z
bool owners::Obj_17f660::FUN_0017f660(int v) {
    *((int*)pad + 3) = v;
    return true;
}


// 0x0017f670 FUN_0017f670 (12 B): matches/0x0017f670.cpp
// sym: ?FUN_0017f670@Obj_17f670@owners@@QAE_ND@Z
bool owners::Obj_17f670::FUN_0017f670(char c) {
    value = c;
    return true;
}


// 0x0017f690 FUN_0017f690 (12 B): matches/0x0017f690.cpp
// sym: ?FUN_0017f690@Target_17f690@owners@@QAE_NH@Z
bool owners::Target_17f690::FUN_0017f690(int value) {
    mValue = value;
    return true;
}


// 0x0017f6a0 FUN_0017f6a0 (12 B): matches/0x0017f6a0.cpp
// sym: ?FUN_0017f6a0@C_17f6a0@owners@@QAE_NE@Z
bool owners::C_17f6a0::FUN_0017f6a0(unsigned char x) {
    mValue = x;
    return true;
}

namespace fn_f4259b06 {

// 0x0017f6b0 FUN_0017f6b0 (12 B): matches/0x0017f6b0.cpp
// sym: ?SetTimeBegin_0017f6b0@Obj_17f6b0@fn_f4259b06@@QAEDH@Z
char Obj_17f6b0::SetTimeBegin_0017f6b0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x0017f6d0 FUN_0017f6d0 (12 B): matches/0x0017f6d0.cpp
// sym: ?SetAttachmentIndex_0017f6d0@Obj_17f6d0@fn_f4259b06@@QAEDH@Z
char Obj_17f6d0::SetAttachmentIndex_0017f6d0(int v) {
    mVal = v;
    return 1;
}


// 0x0017f6f0 FUN_0017f6f0 (12 B): matches/0x0017f6f0.cpp
// sym: ?SetSimulate_0017f6f0@Target_17f6f0@fn_f4259b06@@QAE_NE@Z
bool Target_17f6f0::SetSimulate_0017f6f0(unsigned char value) {
    *((unsigned char*)pad + 0x14) = value;
    return true;
}


// 0x0017f710 FUN_0017f710 (12 B): matches/0x0017f710.cpp
// sym: ?SetAtEnd_0017f710@Obj_17f710@fn_f4259b06@@QAEEE@Z
unsigned char Obj_17f710::SetAtEnd_0017f710(unsigned char value) {
    m15 = value;
    return 1;
}


// 0x0017f720 FUN_0017f720 (12 B): matches/0x0017f720.cpp
// sym: ?Set@Obj_17f720@fn_f4259b06@@QAE_NH@Z
bool Obj_17f720::Set(int v) {
    m12 = v;
    return true;
}


// 0x0017f740 FUN_0017f740 (12 B): matches/0x0017f740.cpp
// sym: ?Set@Obj_17f740@fn_f4259b06@@QAE_NH@Z
bool Obj_17f740::Set(int value) {
    mValue = value;
    return true;
}


// 0x0017f750 FUN_0017f750 (4 B): matches/0x0017f750.cpp
// sym: ?Get@Obj_17f750@fn_f4259b06@@QAEPAPADXZ
char** Obj_17f750::Get() {
    return &mPtr;
}

} // namespace fn_f4259b06

// 0x0017f760 FUN_0017f760 (12 B): matches/0x0017f760.cpp
// sym: ?FUN_0017f760@Obj_17f760@owners@@QAEDH@Z
char owners::Obj_17f760::FUN_0017f760(int v) {
    mValue = v;
    return 1;
}


// 0x0017f780 FUN_0017f780 (12 B): matches/0x0017f780.cpp
// sym: ?FUN_0017f780@X_17f780@owners@@QAE_ND@Z
bool owners::X_17f780::FUN_0017f780(char c) {
    m[0x10] = c;
    return true;
}


// 0x0017f790 FUN_0017f790 (12 B): matches/0x0017f790.cpp
// sym: ?FUN_0017f790@Obj_17f790@owners@@QAEDH@Z
char owners::Obj_17f790::FUN_0017f790(int arg) {
    mValue = arg;
    return 1;
}


// 0x0017f7b0 FUN_0017f7b0 (12 B): matches/0x0017f7b0.cpp
// sym: ?FUN_0017f7b0@Obj_17f7b0@owners@@QAEDH@Z
char owners::Obj_17f7b0::FUN_0017f7b0(int x) {
    value = x;
    return 1;
}


// 0x0017f7c0 FUN_0017f7c0 (12 B): matches/0x0017f7c0.cpp
// sym: ?FUN_0017f7c0@X_17f7c0@owners@@QAE_NH@Z
bool owners::X_17f7c0::FUN_0017f7c0(int x) {
    value = x;
    return true;
}


// 0x0017f7d0 FUN_0017f7d0 (12 B): matches/0x0017f7d0.cpp
// sym: ?FUN_0017f7d0@C_17f7d0@owners@@QAE_NH@Z
bool owners::C_17f7d0::FUN_0017f7d0(int v) {
    m = v;
    return true;
}


// 0x0017f7f0 FUN_0017f7f0 (12 B): matches/0x0017f7f0.cpp
// sym: ?FUN_0017f7f0@Obj_17f7f0@owners@@QAEEH@Z
unsigned char owners::Obj_17f7f0::FUN_0017f7f0(int x) {
    value = x;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017f800 FUN_0017f800 (4 B): matches/0x0017f800.cpp
// sym: ?GetField@Obj_17f800@fn_f4259b06@@QAEPAUSub_17f800@2@XZ
Sub_17f800* Obj_17f800::GetField() {
    return (Sub_17f800*)((char*)this + 0x18);
}

} // namespace fn_f4259b06

// 0x0017f820 FUN_0017f820 (12 B): matches/0x0017f820.cpp
// sym: ?FUN_0017f820@Obj_17f820@owners@@QAE_NH@Z
bool owners::Obj_17f820::FUN_0017f820(int a) {
    m = a;
    return true;
}


// 0x0017f840 FUN_0017f840 (12 B): matches/0x0017f840.cpp
// sym: ?FUN_0017f840@Obj_17f840@owners@@QAE_NH@Z
bool owners::Obj_17f840::FUN_0017f840(int v) {
    mValue = v;
    return true;
}


// 0x0017f860 FUN_0017f860 (12 B): matches/0x0017f860.cpp
// sym: ?FUN_0017f860@Obj_17f860@owners@@QAEDH@Z
char owners::Obj_17f860::FUN_0017f860(int v) {
    m = v;
    return 1;
}


// 0x0017f880 FUN_0017f880 (12 B): matches/0x0017f880.cpp
// sym: ?FUN_0017f880@Obj_17f880@owners@@QAEDH@Z
char owners::Obj_17f880::FUN_0017f880(int v) {
    value = v;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017f890 FUN_0017f890 (12 B): matches/0x0017f890.cpp
// sym: ?SetTimeBegin_0017f890@X_17f890@fn_f4259b06@@QAEDH@Z
char X_17f890::SetTimeBegin_0017f890(int v) {
    value = v;
    return 1;
}


// 0x0017f8b0 FUN_0017f8b0 (12 B): matches/0x0017f8b0.cpp
// sym: ?SetAttachmentIndex_0017f8b0@Obj_17f8b0@fn_f4259b06@@QAE_NH@Z
bool Obj_17f8b0::SetAttachmentIndex_0017f8b0(int x) {
    value = x;
    return true;
}


// 0x0017f8d0 FUN_0017f8d0 (12 B): matches/0x0017f8d0.cpp
// sym: ?SetDamage_0017f8d0@X_17f8d0@fn_f4259b06@@QAEDH@Z
char X_17f8d0::SetDamage_0017f8d0(int v) {
    mVal = v;
    return 1;
}


// 0x0017f8f0 FUN_0017f8f0 (12 B): matches/0x0017f8f0.cpp
// sym: ?SetDamageMax_0017f8f0@Obj_17f8f0@fn_f4259b06@@QAEDH@Z
char Obj_17f8f0::SetDamageMax_0017f8f0(int v) {
    mVal = v;
    return 1;
}

} // namespace fn_f4259b06

// 0x0017f900 FUN_0017f900 (12 B): matches/0x0017f900.cpp
// sym: ?FUN_0017f900@X_17f900@owners@@QAEDH@Z
char owners::X_17f900::FUN_0017f900(int v) {
    mValue = v;
    return 1;
}


// 0x0017f910 FUN_0017f910 (12 B): matches/0x0017f910.cpp
// sym: ?FUN_0017f910@Obj_17f910@owners@@QAE_NH@Z
bool owners::Obj_17f910::FUN_0017f910(int value) {
    m10 = value;
    return true;
}


// 0x0017f930 FUN_0017f930 (12 B): matches/0x0017f930.cpp
// sym: ?FUN_0017f930@Obj_17f930@owners@@QAE_NH@Z
bool owners::Obj_17f930::FUN_0017f930(int v) {
    mValue = v;
    return true;
}

namespace fn_f4259b06 {

// 0x0017f940 FUN_0017f940 (4 B): matches/0x0017f940.cpp
// sym: ?Get@X_17f940@fn_f4259b06@@QAEEXZ
unsigned char X_17f940::Get() {
    return value;
}

} // namespace fn_f4259b06

// 0x0017f950 FUN_0017f950 (12 B): matches/0x0017f950.cpp
// sym: ?FUN_0017f950@Obj_17f950@owners@@QAEEE@Z
unsigned char owners::Obj_17f950::FUN_0017f950(unsigned char b) {
    m18 = b;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017f980 FUN_0017f980 (26 B): matches/0x0017f980.cpp
// sym: ?Set@Obj_17f980@fn_f4259b06@@QAE_NPAUVec3_17f980@2@@Z
bool Obj_17f980::Set(Vec3_17f980* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}

} // namespace fn_f4259b06

// 0x0017f9b0 FUN_0017f9b0 (12 B): matches/0x0017f9b0.cpp
// sym: ?FUN_0017f9b0@Obj_17f9b0@owners@@QAE_NH@Z
bool owners::Obj_17f9b0::FUN_0017f9b0(int v) {
    m28 = v;
    return true;
}


// 0x0017f9d0 FUN_0017f9d0 (12 B): matches/0x0017f9d0.cpp
// sym: ?FUN_0017f9d0@C_17f9d0@owners@@QAE_NH@Z
bool owners::C_17f9d0::FUN_0017f9d0(int value) {
    mValue = value;
    return true;
}


// 0x0017f9f0 FUN_0017f9f0 (12 B): matches/0x0017f9f0.cpp
// sym: ?FUN_0017f9f0@Obj_17f9f0@owners@@QAE_NH@Z
bool owners::Obj_17f9f0::FUN_0017f9f0(int x) {
    value = x;
    return true;
}


// 0x0017fa10 FUN_0017fa10 (12 B): matches/0x0017fa10.cpp
// sym: ?FUN_0017fa10@X_17fa10@owners@@QAE_NH@Z
bool owners::X_17fa10::FUN_0017fa10(int v) {
    value = v;
    return true;
}


// 0x0017fa30 FUN_0017fa30 (18 B): matches/0x0017fa30.cpp
// sym: ?FUN_0017fa30@Obj_17fa30@owners@@QAEDM@Z
char owners::Obj_17fa30::FUN_0017fa30(float x) {
    angle = x * 0.017453292f;
    return 1;
}


// 0x0017fa60 FUN_0017fa60 (18 B): matches/0x0017fa60.cpp
// sym: ?FUN_0017fa60@X_17fa60@owners@@QAEDM@Z
char owners::X_17fa60::FUN_0017fa60(float v) {
    mVal = v * DEG_TO_RAD;
    return 1;
}


// 0x0017fa90 FUN_0017fa90 (18 B): matches/0x0017fa90.cpp
// sym: ?FUN_0017fa90@Obj_17fa90@owners@@QAE_NM@Z
bool owners::Obj_17fa90::FUN_0017fa90(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}


// 0x0017fac0 FUN_0017fac0 (18 B): matches/0x0017fac0.cpp
// sym: ?FUN_0017fac0@Thing_17fac0@owners@@QAEEM@Z
unsigned char owners::Thing_17fac0::FUN_0017fac0(float angle) {
    value = angle * 0.0174532925f;
    return 1;
}


// 0x0017faf0 FUN_0017faf0 (12 B): matches/0x0017faf0.cpp
// sym: ?FUN_0017faf0@Obj_17faf0@owners@@QAE_NH@Z
bool owners::Obj_17faf0::FUN_0017faf0(int value) {
    mValue = value;
    return true;
}


// 0x0017fb10 FUN_0017fb10 (12 B): matches/0x0017fb10.cpp
// sym: ?FUN_0017fb10@Target_17fb10@owners@@QAE_NH@Z
bool owners::Target_17fb10::FUN_0017fb10(int x) {
    value = x;
    return true;
}


// 0x0017fb30 FUN_0017fb30 (18 B): matches/0x0017fb30.cpp
// sym: ?FUN_0017fb30@Thing_17fb30@owners@@QAE_NM@Z
bool owners::Thing_17fb30::FUN_0017fb30(float a) {
    angle = a * 0.0174532925f;
    return true;
}


// 0x0017fb60 FUN_0017fb60 (12 B): matches/0x0017fb60.cpp
// sym: ?FUN_0017fb60@Obj_17fb60@owners@@QAE_NH@Z
bool owners::Obj_17fb60::FUN_0017fb60(int x) {
    value = x;
    return true;
}


// 0x0017fb80 FUN_0017fb80 (12 B): matches/0x0017fb80.cpp
// sym: ?FUN_0017fb80@C_17fb80@owners@@QAE_NH@Z
bool owners::C_17fb80::FUN_0017fb80(int x) {
    mVal = x;
    return true;
}


// 0x0017fba0 FUN_0017fba0 (12 B): matches/0x0017fba0.cpp
// sym: ?FUN_0017fba0@Obj_17fba0@owners@@QAE_NH@Z
bool owners::Obj_17fba0::FUN_0017fba0(int x) {
    mValue = x;
    return true;
}


// 0x0017fbc0 FUN_0017fbc0 (12 B): matches/0x0017fbc0.cpp
// sym: ?FUN_0017fbc0@Obj_17fbc0@owners@@QAE_NH@Z
bool owners::Obj_17fbc0::FUN_0017fbc0(int x) {
    m60 = x;
    return true;
}


// 0x0017fbe0 FUN_0017fbe0 (12 B): matches/0x0017fbe0.cpp
// sym: ?FUN_0017fbe0@Target_17fbe0@owners@@QAEEH@Z
unsigned char owners::Target_17fbe0::FUN_0017fbe0(int value) {
    mField = value;
    return 1;
}


// 0x0017fbf0 FUN_0017fbf0 (4 B): matches/0x0017fbf0.cpp
// sym: ?FUN_0017fbf0@Base_17fbf0@owners@@QAEPADXZ
char* owners::Base_17fbf0::FUN_0017fbf0() {
    return pad + 0x68;
}

namespace fn_f4259b06 {

// 0x0017fc00 FUN_0017fc00 (4 B): matches/0x0017fc00.cpp
// sym: ?Get@Thing_17fc00@fn_f4259b06@@QAEPAXXZ
void* FUN_0017fc00(Thing_17fc00* p) {
    return p->Get();
}

} // namespace fn_f4259b06

// 0x0017fc20 FUN_0017fc20 (15 B): matches/0x0017fc20.cpp
// sym: ?FUN_0017fc20@Obj_17fc20@owners@@QAEDD@Z
char owners::Obj_17fc20::FUN_0017fc20(char x) {
    m80 = x;
    return 1;
}


// 0x0017fc30 FUN_0017fc30 (12 B): matches/0x0017fc30.cpp
// sym: ?FUN_0017fc30@Obj_17fc30@owners@@QAE_NH@Z
bool owners::Obj_17fc30::FUN_0017fc30(int v) {
    mValue = v;
    return true;
}


// 0x0017fc40 FUN_0017fc40 (12 B): matches/0x0017fc40.cpp
// sym: ?FUN_0017fc40@T_17fc40@owners@@QAE_NH@Z
bool owners::T_17fc40::FUN_0017fc40(int x) {
    value = x;
    return true;
}


// 0x0017fc60 FUN_0017fc60 (12 B): matches/0x0017fc60.cpp
// sym: ?FUN_0017fc60@Obj_17fc60@owners@@QAEDH@Z
char owners::Obj_17fc60::FUN_0017fc60(int value) {
    Member = value;
    return 1;
}


// 0x0017fc80 FUN_0017fc80 (12 B): matches/0x0017fc80.cpp
// sym: ?FUN_0017fc80@Obj_17fc80@owners@@QAE_NPAX@Z
bool owners::Obj_17fc80::FUN_0017fc80(void* x) {
    m18 = x;
    return true;
}


// 0x0017fca0 FUN_0017fca0 (12 B): matches/0x0017fca0.cpp
// sym: ?FUN_0017fca0@Obj_17fca0@owners@@QAEDH@Z
char owners::Obj_17fca0::FUN_0017fca0(int v) {
    Value = v;
    return 1;
}


// 0x0017fcc0 FUN_0017fcc0 (18 B): matches/0x0017fcc0.cpp
// sym: ?FUN_0017fcc0@Obj_17fcc0@owners@@QAEDM@Z
char owners::Obj_17fcc0::FUN_0017fcc0(float a) {
    Angle = a * 0.017453292519943295f;
    return 1;
}


// 0x0017fcf0 FUN_0017fcf0 (12 B): matches/0x0017fcf0.cpp
// sym: ?FUN_0017fcf0@Obj_17fcf0@owners@@QAE_NH@Z
bool owners::Obj_17fcf0::FUN_0017fcf0(int x) {
    value = x;
    return true;
}


// 0x0017fd10 FUN_0017fd10 (12 B): matches/0x0017fd10.cpp
// sym: ?FUN_0017fd10@Obj_17fd10@owners@@QAEDH@Z
char owners::Obj_17fd10::FUN_0017fd10(int v) {
    m = v;
    return 1;
}

namespace fn_f4259b06 {

// 0x0017fd40 FUN_0017fd40 (26 B): matches/0x0017fd40.cpp
// sym: ?FUN_0017fd40@Obj_17fd40@fn_f4259b06@@QAE_NPBUT_17fd40@2@@Z
bool Obj_17fd40::FUN_0017fd40(const T_17fd40* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}


// 0x0017fd80 FUN_0017fd80 (26 B): matches/0x0017fd80.cpp
// sym: ?Set@C_17fd80@fn_f4259b06@@QAEDPAUS_17fd80@2@@Z
char C_17fd80::Set(S_17fd80* p) {
    S_17fd80* q = p;
    v38 = q->a;
    v3c = q->b;
    v40 = q->c;
    return 1;
}

} // namespace fn_f4259b06

// 0x0017fda0 FUN_0017fda0 (4 B): matches/0x0017fda0.cpp
// sym: ?FUN_0017fda0@Obj_17fda0@owners@@QAEPAHXZ
int* owners::Obj_17fda0::FUN_0017fda0() {
    return (int*)((char*)this + 0x48);
}

namespace fn_f4259b06 {

// 0x0017fdd0 FUN_0017fdd0 (26 B): matches/0x0017fdd0.cpp
// sym: ?Set@X_17fdd0@fn_f4259b06@@QAE_NPAUVec3_17fdd0@2@@Z
bool X_17fdd0::Set(Vec3_17fdd0* src) {
    v.a = src->a;
    v.b = src->b;
    v.c = src->c;
    return true;
}

} // namespace fn_f4259b06

// 0x0017fdf0 FUN_0017fdf0 (4 B): matches/0x0017fdf0.cpp
// sym: ?FUN_0017fdf0@T_17fdf0@owners@@QAEPAXXZ
void* owners::T_17fdf0::FUN_0017fdf0() {
    return (char*)this + 0x60;
}

namespace fn_f4259b06 {

// 0x0017fe20 FUN_0017fe20 (26 B): matches/0x0017fe20.cpp
// sym: ?Set@Obj_17fe20@fn_f4259b06@@QAE_NPAUData_17fe20@2@@Z
bool Obj_17fe20::Set(Data_17fe20* src) {
    d.a = src->a;
    d.b = src->b;
    d.c = src->c;
    return true;
}


// 0x0017fe40 FUN_0017fe40 (12 B): matches/0x0017fe40.cpp
// sym: ?SetTimeBegin_0017fe40@Thing@fn_f4259b06@@QAE_NH@Z
bool Thing::SetTimeBegin_0017fe40(int v) {
    value = v;
    return true;
}


// 0x0017fe60 FUN_0017fe60 (12 B): matches/0x0017fe60.cpp
// sym: ?SetAttachmentIndex_0017fe60@Obj_17fe60@fn_f4259b06@@QAEDH@Z
char Obj_17fe60::SetAttachmentIndex_0017fe60(int value) {
    mField = value;
    return 1;
}


// 0x0017fe80 FUN_0017fe80 (12 B): matches/0x0017fe80.cpp
// sym: ?SetState_0017fe80@C_17fe80@fn_f4259b06@@QAE_NH@Z
bool C_17fe80::SetState_0017fe80(int x) {
    m = x;
    return true;
}

} // namespace fn_f4259b06

// 0x0017fe90 FUN_0017fe90 (12 B): matches/0x0017fe90.cpp
// sym: ?FUN_0017fe90@Obj_17fe90@owners@@QAE_NH@Z
bool owners::Obj_17fe90::FUN_0017fe90(int v) {
    m1c = v;
    return true;
}


// 0x0017fea0 FUN_0017fea0 (12 B): matches/0x0017fea0.cpp
// sym: ?FUN_0017fea0@Obj_17fea0@owners@@QAE_NH@Z
bool owners::Obj_17fea0::FUN_0017fea0(int v) {
    value = v;
    return true;
}


// 0x0017fec0 FUN_0017fec0 (12 B): matches/0x0017fec0.cpp
// sym: ?FUN_0017fec0@Obj_17fec0@owners@@QAE_NH@Z
bool owners::Obj_17fec0::FUN_0017fec0(int x) {
    mValue = x;
    return true;
}

namespace fn_f4259b06 {

// 0x0017fef0 FUN_0017fef0 (26 B): matches/0x0017fef0.cpp
// sym: ?Set@Obj_17fef0@fn_f4259b06@@QAE_NPBUSrc_17fef0@2@@Z
bool Obj_17fef0::Set(const Src_17fef0* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}


// 0x0017ff30 FUN_0017ff30 (26 B): matches/0x0017ff30.cpp
// sym: ?Copy@Obj_17ff30@fn_f4259b06@@QAE_NPAUSrc_17ff30@2@@Z
bool Obj_17ff30::Copy(Src_17ff30* p) {
    m.a = p->a;
    m.b = p->b;
    m.c = p->c;
    return true;
}

} // namespace fn_f4259b06

// 0x0017ffa0 FUN_0017ffa0 (12 B): matches/0x0017ffa0.cpp
// sym: ?FUN_0017ffa0@Obj_17ffa0@owners@@QAE_NH@Z
bool owners::Obj_17ffa0::FUN_0017ffa0(int x) {
    value = x;
    return true;
}


// 0x0017ffc0 FUN_0017ffc0 (12 B): matches/0x0017ffc0.cpp
// sym: ?FUN_0017ffc0@Obj_17ffc0@owners@@QAE_NH@Z
bool owners::Obj_17ffc0::FUN_0017ffc0(int value) {
    mValue = value;
    return true;
}


// 0x0017ffe0 FUN_0017ffe0 (12 B): matches/0x0017ffe0.cpp
// sym: ?FUN_0017ffe0@X_17ffe0@owners@@QAEDH@Z
char owners::X_17ffe0::FUN_0017ffe0(int value) {
    mValue = value;
    return 1;
}


// 0x00180000 FUN_00180000 (12 B): matches/0x00180000.cpp
// sym: ?FUN_00180000@T_180000@owners@@QAE_NH@Z
bool owners::T_180000::FUN_00180000(int a) {
    m48 = a;
    return true;
}


// 0x00180020 FUN_00180020 (18 B): matches/0x00180020.cpp
// sym: ?FUN_00180020@X_180020@owners@@QAEDM@Z
char owners::X_180020::FUN_00180020(float arg) {
    value = arg * 0.017453292f;
    return 1;
}


// 0x00180050 FUN_00180050 (18 B): matches/0x00180050.cpp
// sym: ?FUN_00180050@Obj_180050@owners@@QAE_NM@Z
bool owners::Obj_180050::FUN_00180050(float x) {
    angle = x * 0.017453292519943295f;
    return true;
}


// 0x00180080 FUN_00180080 (18 B): matches/0x00180080.cpp
// sym: ?FUN_00180080@Obj_180080@owners@@QAEDM@Z
char owners::Obj_180080::FUN_00180080(float degrees) {
    angle = degrees * 0.017453292f;
    return 1;
}


// 0x001800b0 FUN_001800b0 (12 B): matches/0x001800b0.cpp
// sym: ?FUN_001800b0@Obj_1800b0@owners@@QAE_NH@Z
bool owners::Obj_1800b0::FUN_001800b0(int value) {
    mValue = value;
    return true;
}


// 0x001800c0 FUN_001800c0 (4 B): matches/0x001800c0.cpp
// sym: ?FUN_001800c0@Obj_1800c0@owners@@QAEPAXXZ
void* owners::Obj_1800c0::FUN_001800c0() {
    return (char*)this + 0x60;
}

namespace fn_f4259b06 {

// 0x001800f0 FUN_001800f0 (26 B): matches/0x001800f0.cpp
// sym: ?Set@Obj_1800f0@fn_f4259b06@@QAE_NPBUVec3_1800f0@2@@Z
bool Obj_1800f0::Set(const Vec3_1800f0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}

} // namespace fn_f4259b06

// 0x00180110 FUN_00180110 (4 B): matches/0x00180110.cpp
// sym: ?FUN_00180110@Obj_180110@owners@@QAEPAXXZ
void* owners::Obj_180110::FUN_00180110() throw() {
    return (void*)((char*)this + 0x78);
}

namespace fn_f4259b06 {

// 0x00180150 FUN_00180150 (35 B): matches/0x00180150.cpp
// sym: ?Set@Obj@fn_f4259b06@@QAEDPAUField@2@@Z
char Obj::Set(Field* p) {
    f80 = p->a;
    f84 = p->b;
    f88 = p->c;
    return 1;
}

} // namespace fn_f4259b06

// 0x00180190 FUN_00180190 (15 B): matches/0x00180190.cpp
// sym: ?FUN_00180190@Obj_180190@owners@@QAE_NH@Z
bool owners::Obj_180190::FUN_00180190(int value) {
    m8c = value;
    return true;
}


// 0x001801b0 FUN_001801b0 (15 B): matches/0x001801b0.cpp
// sym: ?FUN_001801b0@C_1801b0@owners@@QAE_NI@Z
bool owners::C_1801b0::FUN_001801b0(unsigned int x) {
    m = x;
    return true;
}


// 0x001801c0 FUN_001801c0 (12 B): matches/0x001801c0.cpp
// sym: ?FUN_001801c0@O_1801c0@owners@@QAEDH@Z
char owners::O_1801c0::FUN_001801c0(int x) {
    mField = x;
    return 1;
}


// 0x001801d0 FUN_001801d0 (12 B): matches/0x001801d0.cpp
// sym: ?FUN_001801d0@Obj_1801d0@owners@@QAEDH@Z
char owners::Obj_1801d0::FUN_001801d0(int value) {
    m10 = value;
    return 1;
}


// 0x001801f0 FUN_001801f0 (12 B): matches/0x001801f0.cpp
// sym: ?FUN_001801f0@X_1801f0@owners@@QAEDH@Z
char owners::X_1801f0::FUN_001801f0(int v) {
    m14 = v;
    return 1;
}


// 0x00180210 FUN_00180210 (12 B): matches/0x00180210.cpp
// sym: ?FUN_00180210@Obj_180210@owners@@QAEDH@Z
char owners::Obj_180210::FUN_00180210(int x) {
    value = x;
    return 1;
}


// 0x00180230 FUN_00180230 (12 B): matches/0x00180230.cpp
// sym: ?FUN_00180230@X_180230@owners@@QAE_NH@Z
bool owners::X_180230::FUN_00180230(int value) {
    mValue = value;
    return true;
}


// 0x00180250 FUN_00180250 (18 B): matches/0x00180250.cpp
// sym: ?FUN_00180250@Obj_180250@owners@@QAEDM@Z
char owners::Obj_180250::FUN_00180250(float v) {
    mAngle = v * Rad;
    return 1;
}


// 0x00180280 FUN_00180280 (18 B): matches/0x00180280.cpp
// sym: ?FUN_00180280@Obj_180280@owners@@QAE_NM@Z
bool owners::Obj_180280::FUN_00180280(float x) {
    angle = x * 0.017453292f;
    return true;
}


// 0x001802c0 FUN_001802c0 (60 B): equivalent/0x001802c0.cpp
// sym: ?FUN_001802c0@Angles_1802c0@owners@@QAEEPBM@Z @103b33451d70 @w51e4361259fd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001802c0 @ 0x001802c0
unsigned char owners::Angles_1802c0::FUN_001802c0(const float *v) {
    x = v[0] * DAT_003f32b8;
    y = v[1] * DAT_003f32b8;
    z = v[2] * DAT_003f32b8;
    return 1;
}


// 0x00180300 FUN_00180300 (12 B): matches/0x00180300.cpp
// sym: ?FUN_00180300@X_180300@owners@@QAE_NH@Z
bool owners::X_180300::FUN_00180300(int v) {
    mVal = v;
    return true;
}


// 0x00180320 FUN_00180320 (18 B): matches/0x00180320.cpp
// sym: ?FUN_00180320@Thing_180320@owners@@QAE_NM@Z
bool owners::Thing_180320::FUN_00180320(float a) {
    angle = a * 0.017453292f;
    return true;
}

namespace fn_f4259b06 {

// 0x00180340 FUN_00180340 (12 B): matches/0x00180340.cpp
// sym: ?Fn@Obj_180340@fn_f4259b06@@QAEDH@Z
char Obj_180340::Fn(int x) {
    mValue = x;
    return 1;
}


// 0x00180360 FUN_00180360 (12 B): matches/0x00180360.cpp
// sym: ?Set@X_180360@fn_f4259b06@@QAE_NH@Z
bool X_180360::Set(int v) {
    value = v;
    return true;
}


// 0x00180380 FUN_00180380 (12 B): matches/0x00180380.cpp
// sym: ?Set@X_180380@fn_f4259b06@@QAEDD@Z
char X_180380::Set(char c) {
    m = c;
    return 1;
}


// 0x00180390 FUN_00180390 (12 B): matches/0x00180390.cpp
// sym: ?SetTimeBegin_00180390@T_180390@fn_f4259b06@@QAEDH@Z
char T_180390::SetTimeBegin_00180390(int x) {
    mC = x;
    return 1;
}


// 0x001803b0 FUN_001803b0 (12 B): matches/0x001803b0.cpp
// sym: ?SetAttachmentIndex_001803b0@A_1803b0@fn_f4259b06@@QAEDH@Z
char A_1803b0::SetAttachmentIndex_001803b0(int x) {
    m = x;
    return 1;
}


// 0x001803d0 FUN_001803d0 (12 B): matches/0x001803d0.cpp
// sym: ?SetMissiles_001803d0@Obj_1803d0@fn_f4259b06@@QAE_NH@Z
bool Obj_1803d0::SetMissiles_001803d0(int a) {
    m14 = a;
    return true;
}


// 0x001803e0 FUN_001803e0 (12 B): matches/0x001803e0.cpp
// sym: ?SetTimeBegin_001803e0@Obj_1803e0@fn_f4259b06@@QAEDH@Z
char Obj_1803e0::SetTimeBegin_001803e0(int value) {
    field = value;
    return 1;
}


// 0x00180400 FUN_00180400 (12 B): matches/0x00180400.cpp
// sym: ?SetAttachmentIndex_00180400@X_180400@fn_f4259b06@@QAE_NH@Z
bool X_180400::SetAttachmentIndex_00180400(int a) {
    m10 = a;
    return true;
}


// 0x00180420 FUN_00180420 (12 B): matches/0x00180420.cpp
// sym: ?SetDamage_00180420@Obj_180420@fn_f4259b06@@QAEDH@Z
char Obj_180420::SetDamage_00180420(int x) {
    value = x;
    return 1;
}

} // namespace fn_f4259b06

// 0x00180430 FUN_00180430 (12 B): matches/0x00180430.cpp
// sym: ?FUN_00180430@C_180430@owners@@QAE_NH@Z
bool owners::C_180430::FUN_00180430(int value) {
    mValue = value;
    return true;
}

namespace fn_f4259b06 {

// 0x00180440 FUN_00180440 (4 B): matches/0x00180440.cpp
// sym: ?Get@Obj_180440@fn_f4259b06@@QAEHXZ
int Obj_180440::Get() {
    return value;
}

} // namespace fn_f4259b06

// 0x00180450 FUN_00180450 (4 B): matches/0x00180450.cpp
// sym: ?FUN_00180450@A_180450@owners@@QAEPAU12@XZ
owners::A_180450* owners::A_180450::FUN_00180450() {
    return (owners::A_180450*)((char*)this + 0x18);
}

namespace fn_f4259b06 {

// 0x00180480 FUN_00180480 (26 B): matches/0x00180480.cpp
// sym: ?Set@Obj_180480@fn_f4259b06@@QAE_NPBUVec3_180480@2@@Z
bool Obj_180480::Set(const Vec3_180480* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}


// 0x001804c0 FUN_001804c0 (60 B): matches/0x001804c0.cpp
// sym: ?Set@Obj@fn_f4259b06@@QAEDPBUVec@2@@Z
char Obj::Set(const Vec* v) {
    float a = v->x * 0.017453292f;
    float b = v->y * 0.017453292f;
    volatile float c[3];
    c[2] = v->z * 0.017453292f;
    z = c[2];
    x = a;
    y = b;
    return 1;
}


// 0x00180520 FUN_00180520 (26 B): matches/0x00180520.cpp
// sym: ?Set@O_180520@fn_f4259b06@@QAE_NPAUS_180520@2@@Z
bool O_180520::Set(S_180520* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}


// 0x00180560 FUN_00180560 (26 B): matches/0x00180560.cpp
// sym: ?Set@O_180560@fn_f4259b06@@QAE_NPAUT_180560@2@@Z
bool O_180560::Set(T_180560* p) {
    m44 = p->a;
    m48 = p->b;
    m4c = p->c;
    return true;
}

} // namespace fn_f4259b06

// 0x00180580 FUN_00180580 (12 B): matches/0x00180580.cpp
// sym: ?FUN_00180580@X_180580@owners@@QAEDH@Z
char owners::X_180580::FUN_00180580(int v) {
    mField = v;
    return true;
}


// 0x001805a0 FUN_001805a0 (12 B): matches/0x001805a0.cpp
// sym: ?FUN_001805a0@Obj_1805a0@owners@@QAE_NH@Z
bool owners::Obj_1805a0::FUN_001805a0(int v) {
    m10 = v;
    return true;
}

namespace fn_f4259b06 {

// 0x001805b0 FUN_001805b0 (19 B): matches/0x001805b0.cpp
// sym: ?FUN_001805b0@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001805b0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1400), ((char*)&DAT_004e1404));
}

} // namespace fn_f4259b06

// 0x001805d0 hulkfight::motion::PropMissionCriticalCondition::vfunc_0 (16 B): matches/0x001805d0.cpp
// sym: ?vfunc_0@PropMissionCriticalCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropMissionCriticalCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1400;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180610 FUN_00180610 (19 B): matches/0x00180610.cpp
// sym: ?FUN_00180610@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180610(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1408), ((char*)&DAT_004e140c));
}

} // namespace fn_f4259b06

// 0x00180630 hulkfight::motion::SmartPropGrabbableCondition::vfunc_0 (16 B): matches/0x00180630.cpp
// sym: ?vfunc_0@SmartPropGrabbableCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SmartPropGrabbableCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1408;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180690 FUN_00180690 (19 B): matches/0x00180690.cpp
// sym: ?FUN_00180690@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180690(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1410), ((char*)&DAT_004e1414));
}

} // namespace fn_f4259b06

// 0x001806b0 hulkfight::motion::GrapplePropStateByNameCondition::vfunc_0 (16 B): matches/0x001806b0.cpp
// sym: ?vfunc_0@GrapplePropStateByNameCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::GrapplePropStateByNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1410;
    return p[index];
}

namespace fn_f4259b06 {

// 0x001806f0 FUN_001806f0 (25 B): matches/0x001806f0.cpp
// sym: ?Run@GrapplePropStateByNameCondition_1806f0@fn_f4259b06@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void GrapplePropStateByNameCondition_1806f0::Run() {
    vptr = &hulk_at_0041916c;
    ((Tail_1806f0*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x00180710 FUN_00180710 (19 B): matches/0x00180710.cpp
// sym: ?FUN_00180710@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180710(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1418), ((char*)&DAT_004e141c));
}

} // namespace fn_f4259b06

// 0x00180730 hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_0 (16 B): matches/0x00180730.cpp
// sym: ?vfunc_0@PropGrabbableIsThrownCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1418;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180770 FUN_00180770 (19 B): matches/0x00180770.cpp
// sym: ?FUN_00180770@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180770(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1420), ((char*)&DAT_004e1424));
}

} // namespace fn_f4259b06

// 0x00180790 hulkfight::motion::PropMassCondition::vfunc_0 (16 B): matches/0x00180790.cpp
// sym: ?vfunc_0@PropMassCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropMassCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1420;
    return p[index];
}

namespace fn_f4259b06 {

// 0x001807e0 FUN_001807e0 (25 B): matches/0x001807e0.cpp
// sym: ?Run@PropMassCondition_1807e0@fn_f4259b06@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void PropMassCondition_1807e0::Run() {
    vptr = &hulk_at_004191ac;
    ((Tail_1807e0*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x00180800 FUN_00180800 (19 B): matches/0x00180800.cpp
// sym: ?FUN_00180800@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180800(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1428), ((char*)&DAT_004e142c));
}

} // namespace fn_f4259b06

// 0x00180820 hulkfight::motion::PropAtRestCondition::vfunc_0 (16 B): matches/0x00180820.cpp
// sym: ?vfunc_0@PropAtRestCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropAtRestCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1428;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180860 FUN_00180860 (19 B): matches/0x00180860.cpp
// sym: ?FUN_00180860@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180860(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1430), ((char*)&DAT_004e1434));
}

} // namespace fn_f4259b06

// 0x00180880 hulkfight::motion::PropIsAttachedCondition::vfunc_0 (16 B): matches/0x00180880.cpp
// sym: ?vfunc_0@PropIsAttachedCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropIsAttachedCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1430;
    return p[index];
}

namespace fn_f4259b06 {

// 0x001808c0 FUN_001808c0 (19 B): matches/0x001808c0.cpp
// sym: ?FUN_001808c0@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001808c0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1438), ((char*)&DAT_004e143c));
}

} // namespace fn_f4259b06

// 0x001808e0 hulkfight::motion::PropStateByNameCondition::vfunc_0 (16 B): matches/0x001808e0.cpp
// sym: ?vfunc_0@PropStateByNameCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropStateByNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1438;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180920 FUN_00180920 (25 B): matches/0x00180920.cpp
// sym: ?Run@PropStateByNameCondition_180920@fn_f4259b06@@QAEXXZ
// Same code shape as 0x0010d0f0 (propagated; names are from that function)
void PropStateByNameCondition_180920::Run() {
    vptr = &hulk_at_0041920c;
    ((Tail_180920*)((char*)this + 0x18))->Init_0027af50();
    Finish_002345b0();
}


// 0x00180940 FUN_00180940 (19 B): matches/0x00180940.cpp
// sym: ?FUN_00180940@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180940(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1440), ((char*)&DAT_004e1444));
}

} // namespace fn_f4259b06

// 0x00180960 hulkfight::motion::PropStateByIndexCondition::vfunc_0 (16 B): matches/0x00180960.cpp
// sym: ?vfunc_0@PropStateByIndexCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropStateByIndexCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1440;
    return p[index];
}

namespace fn_f4259b06 {

// 0x001809b0 FUN_001809b0 (19 B): matches/0x001809b0.cpp
// sym: ?FUN_001809b0@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001809b0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1448), ((char*)&DAT_004e144c));
}

} // namespace fn_f4259b06

// 0x001809d0 hulkfight::motion::PropMissileCountCondition::vfunc_0 (16 B): matches/0x001809d0.cpp
// sym: ?vfunc_0@PropMissileCountCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropMissileCountCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1448;
    return p[index];
}


// 0x001809e0 FUN_001809e0 (41 B): matches/0x001809e0.cpp [wrapped: conflict: hulkfight::motion::PropMissileCountCondition]
// sym: ??0PropMissileCountCondition@motion@hulkfight@fn_001809e0@@QAE@XZ
namespace fn_001809e0 {
class Condition_1809e0 {
  public:
    Condition_1809e0(int);
    virtual void f();
    char pad[8];
};
namespace hulkfight {
namespace motion {
class PropMissileCountCondition : public ::hulkfight::motion::PropMissileCountCondition {
  public:
    PropMissileCountCondition();
};
} // namespace motion
} // namespace hulkfight
hulkfight::motion::PropMissileCountCondition::PropMissileCountCondition() : ::hulkfight::motion::PropMissileCountCondition(0) {
    f_0c = 0;
    f_10 = 0;
    f_14 = 0;}
} // namespace fn_001809e0

namespace fn_f4259b06 {

// 0x00180a20 FUN_00180a20 (19 B): matches/0x00180a20.cpp
// sym: ?FUN_00180a20@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180a20(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1450), ((char*)&DAT_004e1454));
}

} // namespace fn_f4259b06

// 0x00180a40 hulkfight::motion::PropCollidedWithWorldCondition::vfunc_0 (16 B): matches/0x00180a40.cpp
// sym: ?vfunc_0@PropCollidedWithWorldCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::PropCollidedWithWorldCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1450;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180a80 FUN_00180a80 (19 B): matches/0x00180a80.cpp
// sym: ?FUN_00180a80@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180a80(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1458), ((char*)&DAT_004e145c));
}

} // namespace fn_f4259b06

// 0x00180aa0 hulkfight::motion::SmartPropIsCargoCondition::vfunc_0 (16 B): matches/0x00180aa0.cpp
// sym: ?vfunc_0@SmartPropIsCargoCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::SmartPropIsCargoCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1458;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180ae0 FUN_00180ae0 (19 B): matches/0x00180ae0.cpp
// sym: ?FUN_00180ae0@fn_f4259b06@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180ae0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e1460), ((char*)&DAT_004e1464));
}

} // namespace fn_f4259b06

// 0x00180b00 hulkfight::motion::CSMPropIsCharacterCondition::vfunc_0 (16 B): matches/0x00180b00.cpp
// sym: ?vfunc_0@CSMPropIsCharacterCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CSMPropIsCharacterCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1460;
    return p[index];
}

namespace fn_f4259b06 {

// 0x00180b30 FUN_00180b30 (11 B): matches/0x00180b30.cpp
// sym: ??1CSMPropIsCharacterCondition@fn_f4259b06@@UAE@XZ
CSMPropIsCharacterCondition::~CSMPropIsCharacterCondition() throw() {}


// 0x00180b40 FUN_00180b40 (19 B): matches/0x00180b40.cpp
// sym: ?FUN_00180b40@fn_f4259b06@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00180b40() {
    FUN_00234810(((char*)&DAT_004e1468), ((char*)&DAT_004e146c));
}

} // namespace fn_f4259b06
