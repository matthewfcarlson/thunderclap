// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00047970..0x00048300 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f64b1530 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f64b1530 {} using namespace fn_f64b1530;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f64b1530 {
struct Triple_479e0 {
    int a, b, c;
};
class Obj_479e0 {
  public:
    char pad[0x1ad4];
    int x[6];
    void Set(Triple_479e0* a, Triple_479e0* b);
};
class Obj_47a60 {
  public:
    char pad[0x10];
    int mValue;
    unsigned char Set(int x);
};
class Obj_47a70 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int x);
};
class O_47a80 {
    char pad[0x10];
    int m;

  public:
    bool F(int x);
};
class Obj_47b30 {
  public:
    char pad[0x10];
    int mValue;
    bool SetCompareSpeed_00047b30(int v);
};
class Obj_47b40 {
  public:
    char SetSpeed_00047b40(int v);
    char pad[0x14];
    int mField;
};
class Obj_47c00 {
  public:
    char pad[0x10];
    float m;
    char SetDirection_00047c00(float v);
};
class Obj {
  public:
    char _m_pad_0[0x14];
    union { float angle; int value; };
    bool SetArc_00047c20(float x);
    char SetMinVelocity_00048240(int x);
};
class Obj_47c50 {
  public:
    virtual ~Obj_47c50() throw();
    char mPad[0x0c];
    int mFlag;
    char Set(int v);
};
class X_47c60 {
  public:
    char SetCompare_00047c60(int v);
    char pad[12];
    int m;
};
class C_47c70 {
  public:
    char pad[16];
    int mField;
    bool SetSize_00047c70(int x);
};
class A_47c80 {
  public:
    char pad[0xc];
    int m;
    bool Fn(int x);
};
class C_47c90 {
  public:
    char pad[0x10];
    int m10;
    char Fn(int x);
};
const float PiDiv180 = 0.0174532925f;
const float gHalfPi180 = 0.017453292f;
class C_47d40 {
  public:
    char pad0[12];
    char m1;
    char Set(char v);
};
class Obj_47e00 {
  public:
    char pad[0xc];
    char value;
    char Set(char c);
};
class Obj_47e10 {
  public:
    char pad[0x10];
    int m10;
    bool Set(int v);
};
class O_47e20 {
  public:
    char pad[0x14];
    int v;
    bool Set(int x);
};
class Target_47e70 {
  public:
    char SetCompare_00047e70(int value);
    char pad[0xc];
    int mValue;
};
class Obj_47e80 {
  public:
    char pad[0x10];
    int m10;
    bool SetType_00047e80(int x);
};
class Obj_47e90 {
  public:
    char pad[12];
    int mVal;
    bool SetCompare_00047e90(int arg);
};
class Obj_47ea0 {
  public:
    char pad[0x18];
    int* GetName_00047ea0();
};
class Obj_47eb0 {
  public:
    char pad[0x10];
    int mValue;
    bool SetAttachmentIndex_00047eb0(int v);
};
class Obj_47ee0 {
  public:
    char pad[0xc];
    int value;
    bool Set(int v);
};
class C_47ef0 {
  public:
    char pad[0x10];
    int m;
    bool Set(int x);
};
class Obj_47f00 {
  public:
    char pad[0x18];
    char* Get();
};
class C_47f10 {
    char pad[0x20];
    int m20, m24, m28;

  public:
    char Set(const void* p);
};
class C_47f60 {
  public:
    char pad[0xc];
    int m;
    bool Set(int v) {
        m = v;
        return true;
    }
};
class X_47f70 {
  public:
    virtual void f();
    char pad[0x0c];
    int value;
    char Set(int v);
};
class Obj_47f80 {
  public:
    char pad[12];
    int m;
    bool Set(int x);
};
class Obj_47f90 {
  public:
    char pad[0x10];
    int value;
    char Set(int x);
};
class Obj_47fb0 {
  public:
    char pad[0x10];
    int m10;
    char Set(int v);
};
class X_47fc0 {
  public:
    char pad[12];
    int m;
    bool Set(int v);
};
class Obj_47fd0 {
  public:
    char pad[0x50];
    int value;
    bool Set(int x);
};
class Obj_48040 {
  public:
    char pad[12];
    int mX;
    char SetCompare_00048040(int a);
};
class Obj_48050 {
  public:
    char pad[0x10];
    int mVal;
    char SetMotionState_00048050(int x);
};
class Target_48060 {
  public:
    char pad[12];
    int field;
    bool SetCompare_00048060(int x);
};
class Obj_48070 {
  public:
    char pad[0x10];
    int mValue;
    bool SetMotionHit_00048070(int arg);
};
class Obj_48080 {
  public:
    char m0[0xc];
    float mValue;
    char SetAngle_00048080(float degrees);
};
class Obj_480a0 {
  public:
    char pad[0x10];
    float mVal;
    bool SetArc_000480a0(float a);
};
class C_480d0 {
  public:
    char pad[0x14];
    char m14;
    char SetUseIntentionMotion_000480d0(char a);
};
class Target_480e0 {
  public:
    char pad[12];
    int value;
    bool SetCompare_000480e0(int x);
};
class Obj_480f0 {
  public:
    int pad[4];
    int m;
    bool SetStatus_000480f0(int x);
};
class Obj_48110 {
  public:
    char pad[12];
    int mValue;
    bool SetCompare_00048110(int v);
};
class Obj_48120 {
  public:
    char pad[0x10];
    int mVal;
    char SetTime_00048120(int x);
};
class X_48140 {
  public:
    char pad[0x14];
    char mVal;
    char SetUseKeyWordWait_00048140(char a);
};
class Obj_48160 {
  public:
    char m[0x18];
    char SetKeyWord_00048160(int x);
};
class Obj_48190 {
  public:
    char pad[12];
    int mValue;
    bool SetCompare_00048190(int x);
};
class Obj_481a0 {
  public:
    char pad[0x10];
    void* GetFightNode_000481a0();
};
class Obj_481b0 {
  public:
    char pad[0x1c];
    char m;
    char SetLastFrame_000481b0(char v);
};
const float rads = 0.017453292f;
class Obj_48200 {
  public:
    char SetAngle_00048200(float deg);
};
class Obj_48220 {
  public:
    char pad[0x10];
    float rad;
    unsigned char SetArc_00048220(float deg);
};
class C {
  public:
    C* Second_00059a30();
    char pad[0x330];
    int a;
    int b;
    int c;
};
class CCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(int);
    virtual int h(int);
    int vfunc_6(int, int, int);
};


// 0x00047970 FUN_00047970 (19 B): matches/0x00047970.cpp
// sym: _FUN_00047970
// Same code shape as 0x00011070 (propagated; names are from that function)
extern "C" double FUN_00047970(float value) {
    return floor((double)value);
}


// 0x000479e0 FUN_000479e0 (63 B): matches/0x000479e0.cpp
// sym: ?Set@Obj_479e0@fn_f64b1530@@QAEXPAUTriple_479e0@2@0@Z
void Obj_479e0::Set(Triple_479e0* a, Triple_479e0* b) {
    x[0] = a->a;
    x[1] = a->b;
    x[2] = a->c;
    x[3] = b->a;
    x[4] = b->b;
    x[5] = b->c;
}


// 0x00047a60 FUN_00047a60 (12 B): matches/0x00047a60.cpp
// sym: ?Set@Obj_47a60@fn_f64b1530@@QAEEH@Z
unsigned char Obj_47a60::Set(int x) {
    mValue = x;
    return 1;
}


// 0x00047a70 FUN_00047a70 (12 B): matches/0x00047a70.cpp
// sym: ?Set@Obj_47a70@fn_f64b1530@@QAE_NH@Z
bool Obj_47a70::Set(int x) {
    m14 = x;
    return true;
}


// 0x00047a80 FUN_00047a80 (12 B): matches/0x00047a80.cpp
// sym: ?F@O_47a80@fn_f64b1530@@QAE_NH@Z
bool O_47a80::F(int x) {
    m = x;
    return true;
}

} // namespace fn_f64b1530

// 0x00047a90 FUN_00047a90 (12 B): matches/0x00047a90.cpp
// sym: ?FUN_00047a90@X_47a90@owners@@QAEDH@Z
char owners::X_47a90::FUN_00047a90(int v) {
    mVal = v;
    return 1;
}


// 0x00047aa0 FUN_00047aa0 (12 B): matches/0x00047aa0.cpp
// sym: ?FUN_00047aa0@Obj_47aa0@owners@@QAE_NH@Z
bool owners::Obj_47aa0::FUN_00047aa0(int v) {
    value = v;
    return true;
}


// 0x00047ab0 FUN_00047ab0 (12 B): matches/0x00047ab0.cpp
// sym: ?FUN_00047ab0@Obj_47ab0@owners@@QAEDH@Z
char owners::Obj_47ab0::FUN_00047ab0(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x00047ac0 FUN_00047ac0 (12 B): matches/0x00047ac0.cpp
// sym: ?FUN_00047ac0@Obj_47ac0@owners@@QAEDH@Z
char owners::Obj_47ac0::FUN_00047ac0(int v) {
    mVal = v;
    return 1;
}


// 0x00047ad0 FUN_00047ad0 (12 B): matches/0x00047ad0.cpp
// sym: ?FUN_00047ad0@C_47ad0@owners@@QAEDH@Z
char owners::C_47ad0::FUN_00047ad0(int v) {
    m14 = v;
    return 1;
}


// 0x00047ae0 FUN_00047ae0 (12 B): matches/0x00047ae0.cpp
// sym: ?FUN_00047ae0@O_47ae0@owners@@QAE_NH@Z
bool owners::O_47ae0::FUN_00047ae0(int x) {
    mValue = x;
    return true;
}


// 0x00047af0 FUN_00047af0 (12 B): matches/0x00047af0.cpp
// sym: ?FUN_00047af0@C_47af0@owners@@QAE_NH@Z
bool owners::C_47af0::FUN_00047af0(int x) {
    m1c = x;
    return true;
}


// 0x00047b00 FUN_00047b00 (12 B): matches/0x00047b00.cpp
// sym: ?FUN_00047b00@C_47b00@owners@@QAE_NH@Z
bool owners::C_47b00::FUN_00047b00(int x) {
    mValue = x;
    return true;
}


// 0x00047b10 FUN_00047b10 (12 B): matches/0x00047b10.cpp
// sym: ?FUN_00047b10@Target_47b10@owners@@QAE_NH@Z
bool owners::Target_47b10::FUN_00047b10(int v) {
    value = v;
    return true;
}


// 0x00047b20 FUN_00047b20 (12 B): matches/0x00047b20.cpp
// sym: ?FUN_00047b20@A_47b20@owners@@QAE_NH@Z
bool owners::A_47b20::FUN_00047b20(int v) {
    m14 = v;
    return true;
}

namespace fn_f64b1530 {

// 0x00047b30 FUN_00047b30 (12 B): matches/0x00047b30.cpp
// sym: ?SetCompareSpeed_00047b30@Obj_47b30@fn_f64b1530@@QAE_NH@Z
bool Obj_47b30::SetCompareSpeed_00047b30(int v) {
    mValue = v;
    return true;
}


// 0x00047b40 FUN_00047b40 (12 B): matches/0x00047b40.cpp
// sym: ?SetSpeed_00047b40@Obj_47b40@fn_f64b1530@@QAEDH@Z
char Obj_47b40::SetSpeed_00047b40(int v) {
    mField = v;
    return 1;
}

} // namespace fn_f64b1530

// 0x00047b50 FUN_00047b50 (12 B): matches/0x00047b50.cpp
// sym: ?FUN_00047b50@C_47b50@owners@@QAEDH@Z
char owners::C_47b50::FUN_00047b50(int v) {
    mValue = v;
    return 1;
}


// 0x00047b60 FUN_00047b60 (12 B): matches/0x00047b60.cpp
// sym: ?FUN_00047b60@Obj_47b60@owners@@QAEDH@Z
char owners::Obj_47b60::FUN_00047b60(int x) {
    mVal = x;
    return 1;
}


// 0x00047b70 FUN_00047b70 (12 B): matches/0x00047b70.cpp
// sym: ?FUN_00047b70@C_47b70@owners@@QAE_NH@Z
bool owners::C_47b70::FUN_00047b70(int x) {
    m18 = x;
    return true;
}


// 0x00047b80 FUN_00047b80 (18 B): matches/0x00047b80.cpp
// sym: ?FUN_00047b80@O_47b80@owners@@QAEDM@Z
char owners::O_47b80::FUN_00047b80(float angle) {
    m = angle * 0.017453292519943295f;
    return 1;
}


// 0x00047ba0 FUN_00047ba0 (12 B): matches/0x00047ba0.cpp
// sym: ?FUN_00047ba0@Obj_47ba0@owners@@QAE_NH@Z
bool owners::Obj_47ba0::FUN_00047ba0(int v) {
    m10 = v;
    return true;
}


// 0x00047bb0 FUN_00047bb0 (18 B): matches/0x00047bb0.cpp
// sym: ?FUN_00047bb0@O_47bb0@owners@@QAE_NM@Z
bool owners::O_47bb0::FUN_00047bb0(float a) {
    mAngle = a * 0.017453292519943295f;
    return true;
}


// 0x00047bd0 FUN_00047bd0 (12 B): matches/0x00047bd0.cpp
// sym: ?FUN_00047bd0@X_47bd0@owners@@QAEDH@Z
char owners::X_47bd0::FUN_00047bd0(int v) {
    m = v;
    return 1;
}


// 0x00047be0 FUN_00047be0 (12 B): matches/0x00047be0.cpp
// sym: ?FUN_00047be0@Obj_47be0@owners@@QAEDH@Z
char owners::Obj_47be0::FUN_00047be0(int value) {
    m = value;
    return 1;
}


// 0x00047bf0 FUN_00047bf0 (12 B): matches/0x00047bf0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?SetAxis_00047bf0@Obj_47bf0@fn_00047bf0@@QAE_NH@Z
namespace fn_00047bf0 {
class Obj_47bf0 {
  public:
    virtual void Vfn0();
    virtual void Vfn1();
    char pad[8];
    int mValue;
    Obj_47bf0(int v);
    bool SetAxis_00047bf0(int v);
};

Obj_47bf0::Obj_47bf0(int v) : mValue(v) {}
bool Obj_47bf0::SetAxis_00047bf0(int v) {
    mValue = v;
    return true;
}
} // namespace fn_00047bf0

namespace fn_f64b1530 {

// 0x00047c00 FUN_00047c00 (18 B): matches/0x00047c00.cpp
// sym: ?SetDirection_00047c00@Obj_47c00@fn_f64b1530@@QAEDM@Z
char Obj_47c00::SetDirection_00047c00(float v) {
    m = v * 0.0174532923f;
    return 1;
}


// 0x00047c20 FUN_00047c20 (18 B): matches/0x00047c20.cpp
// sym: ?SetArc_00047c20@Obj@fn_f64b1530@@QAE_NM@Z
bool Obj::SetArc_00047c20(float x) {
    angle = x * 0.017453292f;
    return true;
}

} // namespace fn_f64b1530

// 0x00047c40 FUN_00047c40 (12 B): matches/0x00047c40.cpp
// sym: ?FUN_00047c40@Obj_47c40@owners@@QAE_NH@Z
bool owners::Obj_47c40::FUN_00047c40(int value) {
    mField = value;
    return true;
}

namespace fn_f64b1530 {

// 0x00047c50 FUN_00047c50 (12 B): matches/0x00047c50.cpp
// sym: ?Set@Obj_47c50@fn_f64b1530@@QAEDH@Z
char Obj_47c50::Set(int v) {
    mFlag = v;
    return 1;
}


// 0x00047c60 FUN_00047c60 (12 B): matches/0x00047c60.cpp
// sym: ?SetCompare_00047c60@X_47c60@fn_f64b1530@@QAEDH@Z
char X_47c60::SetCompare_00047c60(int v) {
    m = v;
    return 1;
}


// 0x00047c70 FUN_00047c70 (12 B): matches/0x00047c70.cpp
// sym: ?SetSize_00047c70@C_47c70@fn_f64b1530@@QAE_NH@Z
bool C_47c70::SetSize_00047c70(int x) {
    mField = x;
    return true;
}


// 0x00047c80 FUN_00047c80 (12 B): matches/0x00047c80.cpp
// sym: ?Fn@A_47c80@fn_f64b1530@@QAE_NH@Z
bool A_47c80::Fn(int x) {
    m = x;
    return true;
}


// 0x00047c90 FUN_00047c90 (12 B): matches/0x00047c90.cpp
// sym: ?Fn@C_47c90@fn_f64b1530@@QAEDH@Z
char C_47c90::Fn(int x) {
    m10 = x;
    return 1;
}

} // namespace fn_f64b1530

// 0x00047ca0 FUN_00047ca0 (18 B): matches/0x00047ca0.cpp
// sym: ?FUN_00047ca0@Obj_47ca0@owners@@QAEDM@Z
char owners::Obj_47ca0::FUN_00047ca0(float x) {
    v = x * PiDiv180;
    return 1;
}


// 0x00047cc0 FUN_00047cc0 (18 B): matches/0x00047cc0.cpp
// sym: ?FUN_00047cc0@Obj_47cc0@owners@@QAEEM@Z
unsigned char owners::Obj_47cc0::FUN_00047cc0(float x) {
    mVal = x * 0.017453292f;
    return 1;
}


// 0x00047ce0 FUN_00047ce0 (18 B): matches/0x00047ce0.cpp
// sym: ?FUN_00047ce0@Obj_47ce0@owners@@QAEDM@Z
char owners::Obj_47ce0::FUN_00047ce0(float x) {
    mVal = x * gHalfPi180;
    return 1;
}


// 0x00047d00 FUN_00047d00 (18 B): matches/0x00047d00.cpp
// sym: ?FUN_00047d00@V_47d00@owners@@QAEDM@Z
char owners::V_47d00::FUN_00047d00(float x) {
    v = x * 0.017453292f;
    return 1;
}


// 0x00047d20 FUN_00047d20 (12 B): matches/0x00047d20.cpp
// sym: ?FUN_00047d20@Obj_47d20@owners@@QAEDH@Z
char owners::Obj_47d20::FUN_00047d20(int value) {
    mValue = value;
    return 1;
}


// 0x00047d30 FUN_00047d30 (4 B): matches/0x00047d30.cpp
// sym: ?FUN_00047d30@Obj_47d30@owners@@QAEPAXXZ
void* owners::Obj_47d30::FUN_00047d30() {
    return (char*)this + 16;
}

namespace fn_f64b1530 {

// 0x00047d40 FUN_00047d40 (12 B): matches/0x00047d40.cpp
// sym: ?Set@C_47d40@fn_f64b1530@@QAEDD@Z
char C_47d40::Set(char v) {
    m1 = v;
    return 1;
}

} // namespace fn_f64b1530

// 0x00047d50 FUN_00047d50 (12 B): matches/0x00047d50.cpp
// sym: ?FUN_00047d50@Obj_47d50@owners@@QAE_NH@Z
bool owners::Obj_47d50::FUN_00047d50(int x) {
    value = x;
    return true;
}


// 0x00047d60 FUN_00047d60 (12 B): matches/0x00047d60.cpp
// sym: ?FUN_00047d60@Obj_47d60@owners@@QAEDH@Z
char owners::Obj_47d60::FUN_00047d60(int v) {
    mValue = v;
    return 1;
}


// 0x00047d70 FUN_00047d70 (12 B): matches/0x00047d70.cpp
// sym: ?FUN_00047d70@A_47d70@owners@@QAE_NH@Z
bool owners::A_47d70::FUN_00047d70(int x) {
    m = x;
    return true;
}


// 0x00047d80 FUN_00047d80 (12 B): matches/0x00047d80.cpp
// sym: ?FUN_00047d80@X_47d80@owners@@QAE_NH@Z
bool owners::X_47d80::FUN_00047d80(int v) {
    m = v;
    return true;
}


// 0x00047d90 FUN_00047d90 (12 B): matches/0x00047d90.cpp
// sym: ?FUN_00047d90@Obj_47d90@owners@@QAEDH@Z
char owners::Obj_47d90::FUN_00047d90(int x) {
    *(int*)((char*)this + 0xc) = x;
    return 1;
}


// 0x00047da0 FUN_00047da0 (12 B): matches/0x00047da0.cpp
// sym: ?FUN_00047da0@Obj_47da0@owners@@QAEDH@Z
char owners::Obj_47da0::FUN_00047da0(int v) {
    mVal = v;
    return 1;
}


// 0x00047db0 FUN_00047db0 (12 B): matches/0x00047db0.cpp
// sym: ?FUN_00047db0@Obj_47db0@owners@@QAE_NH@Z
bool owners::Obj_47db0::FUN_00047db0(int v) {
    mValue = v;
    return true;
}


// 0x00047dc0 FUN_00047dc0 (18 B): matches/0x00047dc0.cpp
// sym: ?FUN_00047dc0@Obj_47dc0@owners@@QAE_NM@Z
bool owners::Obj_47dc0::FUN_00047dc0(float x) {
    angle = x * 0.017453292f;
    return true;
}


// 0x00047de0 FUN_00047de0 (12 B): matches/0x00047de0.cpp
// sym: ?FUN_00047de0@O_47de0@owners@@QAE_NH@Z
bool owners::O_47de0::FUN_00047de0(int x) {
    m = x;
    return true;
}


// 0x00047df0 FUN_00047df0 (12 B): matches/0x00047df0.cpp
// sym: ?FUN_00047df0@X_47df0@owners@@QAEDH@Z
char owners::X_47df0::FUN_00047df0(int a) {
    m10 = a;
    return 1;
}

namespace fn_f64b1530 {

// 0x00047e00 FUN_00047e00 (12 B): matches/0x00047e00.cpp
// sym: ?Set@Obj_47e00@fn_f64b1530@@QAEDD@Z
char Obj_47e00::Set(char c) {
    value = c;
    return 1;
}


// 0x00047e10 FUN_00047e10 (12 B): matches/0x00047e10.cpp
// sym: ?Set@Obj_47e10@fn_f64b1530@@QAE_NH@Z
bool Obj_47e10::Set(int v) {
    m10 = v;
    return true;
}


// 0x00047e20 FUN_00047e20 (12 B): matches/0x00047e20.cpp
// sym: ?Set@O_47e20@fn_f64b1530@@QAE_NH@Z
bool O_47e20::Set(int x) {
    v = x;
    return true;
}

} // namespace fn_f64b1530

// 0x00047e30 FUN_00047e30 (12 B): matches/0x00047e30.cpp
// sym: ?FUN_00047e30@X_47e30@owners@@QAEDH@Z
char owners::X_47e30::FUN_00047e30(int arg) {
    Value = arg;
    return 1;
}


// 0x00047e40 FUN_00047e40 (12 B): matches/0x00047e40.cpp
// sym: ?FUN_00047e40@Obj_47e40@owners@@QAE_NH@Z
bool owners::Obj_47e40::FUN_00047e40(int v) {
    mVal = v;
    return true;
}


// 0x00047e50 FUN_00047e50 (12 B): matches/0x00047e50.cpp
// sym: ?FUN_00047e50@Target_47e50@owners@@QAE_NH@Z
bool owners::Target_47e50::FUN_00047e50(int value) {
    mField = value;
    return true;
}


// 0x00047e60 FUN_00047e60 (12 B): matches/0x00047e60.cpp
// sym: ?FUN_00047e60@Obj_47e60@owners@@QAE_NH@Z
bool owners::Obj_47e60::FUN_00047e60(int v) {
    mVal = v;
    return true;
}

namespace fn_f64b1530 {

// 0x00047e70 FUN_00047e70 (12 B): matches/0x00047e70.cpp
// sym: ?SetCompare_00047e70@Target_47e70@fn_f64b1530@@QAEDH@Z
char Target_47e70::SetCompare_00047e70(int value) {
    mValue = value;
    return 1;
}


// 0x00047e80 FUN_00047e80 (12 B): matches/0x00047e80.cpp
// sym: ?SetType_00047e80@Obj_47e80@fn_f64b1530@@QAE_NH@Z
bool Obj_47e80::SetType_00047e80(int x) {
    m10 = x;
    return true;
}


// 0x00047e90 FUN_00047e90 (12 B): matches/0x00047e90.cpp
// sym: ?SetCompare_00047e90@Obj_47e90@fn_f64b1530@@QAE_NH@Z
bool Obj_47e90::SetCompare_00047e90(int arg) {
    mVal = arg;
    return true;
}


// 0x00047ea0 FUN_00047ea0 (4 B): matches/0x00047ea0.cpp
// sym: ?GetName_00047ea0@Obj_47ea0@fn_f64b1530@@QAEPAHXZ
int* Obj_47ea0::GetName_00047ea0() {
    return (int*)((char*)this + 0x18);
}


// 0x00047eb0 FUN_00047eb0 (12 B): matches/0x00047eb0.cpp
// sym: ?SetAttachmentIndex_00047eb0@Obj_47eb0@fn_f64b1530@@QAE_NH@Z
bool Obj_47eb0::SetAttachmentIndex_00047eb0(int v) {
    mValue = v;
    return true;
}

} // namespace fn_f64b1530

// 0x00047ec0 FUN_00047ec0 (18 B): matches/0x00047ec0.cpp
// sym: ?FUN_00047ec0@Obj_47ec0@owners@@QAEDM@Z
char owners::Obj_47ec0::FUN_00047ec0(float x) {
    mAngle = x * 0.017453292519943295f;
    return 1;
}

namespace fn_f64b1530 {

// 0x00047ee0 FUN_00047ee0 (12 B): matches/0x00047ee0.cpp
// sym: ?Set@Obj_47ee0@fn_f64b1530@@QAE_NH@Z
bool Obj_47ee0::Set(int v) {
    value = v;
    return true;
}


// 0x00047ef0 FUN_00047ef0 (12 B): matches/0x00047ef0.cpp
// sym: ?Set@C_47ef0@fn_f64b1530@@QAE_NH@Z
bool C_47ef0::Set(int x) {
    m = x;
    return true;
}


// 0x00047f00 FUN_00047f00 (4 B): matches/0x00047f00.cpp
// sym: ?Get@Obj_47f00@fn_f64b1530@@QAEPADXZ
char* Obj_47f00::Get() {
    return (char*)this + 0x18;
}


// 0x00047f10 FUN_00047f10 (26 B): matches/0x00047f10.cpp
// sym: ?Set@C_47f10@fn_f64b1530@@QAEDPBX@Z
char C_47f10::Set(const void* p) {
    const int* q = (const int*)p;
    m20 = q[0];
    m24 = q[1];
    m28 = q[2];
    return 1;
}

} // namespace fn_f64b1530

// 0x00047f30 FUN_00047f30 (12 B): matches/0x00047f30.cpp
// sym: ?FUN_00047f30@X_47f30@owners@@QAEDH@Z
char owners::X_47f30::FUN_00047f30(int v) {
    mField = v;
    return 1;
}


// 0x00047f40 FUN_00047f40 (4 B): matches/0x00047f40.cpp
// sym: ?FUN_00047f40@Obj_47f40@owners@@QAEPADXZ
char* owners::Obj_47f40::FUN_00047f40() {
    return (char*)((char*)this + 0x10);
}


// 0x00047f50 FUN_00047f50 (12 B): matches/0x00047f50.cpp
// sym: ?FUN_00047f50@Obj_47f50@owners@@QAE_NPAX@Z
bool owners::Obj_47f50::FUN_00047f50(void* p) {
    mPointer = p;
    return true;
}

namespace fn_f64b1530 {

// 0x00047f60 FUN_00047f60 (12 B): matches/0x00047f60.cpp
// sym: ?Target@fn_f64b1530@@YI_NPAVC_47f60@1@PAXH@Z
bool __fastcall Target(C_47f60* self, void* eax, int v) {
    self->m = v;
    return true;
}


// 0x00047f70 FUN_00047f70 (12 B): matches/0x00047f70.cpp
// sym: ?Set@X_47f70@fn_f64b1530@@QAEDH@Z
char X_47f70::Set(int v) {
    value = v;
    return 1;
}


// 0x00047f80 FUN_00047f80 (12 B): matches/0x00047f80.cpp
// sym: ?Set@Obj_47f80@fn_f64b1530@@QAE_NH@Z
bool Obj_47f80::Set(int x) {
    m = x;
    return true;
}


// 0x00047f90 FUN_00047f90 (12 B): matches/0x00047f90.cpp
// sym: ?Set@Obj_47f90@fn_f64b1530@@QAEDH@Z
char Obj_47f90::Set(int x) {
    value = x;
    return 1;
}

} // namespace fn_f64b1530

// 0x00047fa0 FUN_00047fa0 (12 B): matches/0x00047fa0.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4O_47fa0@fn_00047fa0@@QAE_NH@Z
namespace fn_00047fa0 {
class O_47fa0 {
  public:
    char pad[0xc];
    int m;
    bool operator=(int x_47fa0);
};
bool O_47fa0::operator=(int x_47fa0) {
    m = x_47fa0;
    return true;
}
} // namespace fn_00047fa0

namespace fn_f64b1530 {

// 0x00047fb0 FUN_00047fb0 (12 B): matches/0x00047fb0.cpp
// sym: ?Set@Obj_47fb0@fn_f64b1530@@QAEDH@Z
char Obj_47fb0::Set(int v) {
    m10 = v;
    return 1;
}


// 0x00047fc0 FUN_00047fc0 (12 B): matches/0x00047fc0.cpp
// sym: ?Set@X_47fc0@fn_f64b1530@@QAE_NH@Z
bool X_47fc0::Set(int v) {
    m = v;
    return true;
}


// 0x00047fd0 FUN_00047fd0 (12 B): matches/0x00047fd0.cpp
// sym: ?Set@Obj_47fd0@fn_f64b1530@@QAE_NH@Z
bool Obj_47fd0::Set(int x) {
    value = x;
    return true;
}

} // namespace fn_f64b1530

// 0x00047fe0 FUN_00047fe0 (12 B): matches/0x00047fe0.cpp
// sym: ?FUN_00047fe0@Obj_47fe0@owners@@QAE_NH@Z
bool owners::Obj_47fe0::FUN_00047fe0(int x) {
    mValue = x;
    return true;
}


// 0x00047ff0 FUN_00047ff0 (4 B): matches/0x00047ff0.cpp
// sym: ?FUN_00047ff0@Obj_47ff0@owners@@QAEPAXXZ
void* owners::Obj_47ff0::FUN_00047ff0() {
    char* p = (char*)this + 0x10;
    return p;
}


// 0x00048000 FUN_00048000 (12 B): matches/0x00048000.cpp
// sym: ?FUN_00048000@A_48000@owners@@QAE_NH@Z
bool owners::A_48000::FUN_00048000(int x) {
    mValue = x;
    return true;
}


// 0x00048010 FUN_00048010 (4 B): matches/0x00048010.cpp
// sym: ?FUN_00048010@Obj_48010@owners@@QAEPAXXZ
void* owners::Obj_48010::FUN_00048010() {
    return (char*)this + 16;
}


// 0x00048020 FUN_00048020 (12 B): matches/0x00048020.cpp
// sym: ?FUN_00048020@X_48020@owners@@QAEDH@Z
char owners::X_48020::FUN_00048020(int v) {
    m = v;
    return 1;
}


// 0x00048030 FUN_00048030 (4 B): matches/0x00048030.cpp
// sym: ?FUN_00048030@Obj_48030@owners@@QAEPAHXZ
int* owners::Obj_48030::FUN_00048030() {
    return (int*)((char*)this + 0x10);
}

namespace fn_f64b1530 {

// 0x00048040 FUN_00048040 (12 B): matches/0x00048040.cpp
// sym: ?SetCompare_00048040@Obj_48040@fn_f64b1530@@QAEDH@Z
char Obj_48040::SetCompare_00048040(int a) {
    mX = a;
    return 1;
}


// 0x00048050 FUN_00048050 (12 B): matches/0x00048050.cpp
// sym: ?SetMotionState_00048050@Obj_48050@fn_f64b1530@@QAEDH@Z
char Obj_48050::SetMotionState_00048050(int x) {
    mVal = x;
    return 1;
}


// 0x00048060 FUN_00048060 (12 B): matches/0x00048060.cpp
// sym: ?SetCompare_00048060@Target_48060@fn_f64b1530@@QAE_NH@Z
bool Target_48060::SetCompare_00048060(int x) {
    field = x;
    return true;
}


// 0x00048070 FUN_00048070 (12 B): matches/0x00048070.cpp
// sym: ?SetMotionHit_00048070@Obj_48070@fn_f64b1530@@QAE_NH@Z
bool Obj_48070::SetMotionHit_00048070(int arg) {
    mValue = arg;
    return true;
}


// 0x00048080 FUN_00048080 (18 B): matches/0x00048080.cpp
// sym: ?SetAngle_00048080@Obj_48080@fn_f64b1530@@QAEDM@Z
char Obj_48080::SetAngle_00048080(float degrees) {
    mValue = degrees * 0.017453293f;
    return 1;
}


// 0x000480a0 FUN_000480a0 (18 B): matches/0x000480a0.cpp
// sym: ?SetArc_000480a0@Obj_480a0@fn_f64b1530@@QAE_NM@Z
bool Obj_480a0::SetArc_000480a0(float a) {
    mVal = a * 0.017453292522f;
    return true;
}


// 0x000480d0 FUN_000480d0 (12 B): matches/0x000480d0.cpp
// sym: ?SetUseIntentionMotion_000480d0@C_480d0@fn_f64b1530@@QAEDD@Z
char C_480d0::SetUseIntentionMotion_000480d0(char a) {
    m14 = a;
    return 1;
}


// 0x000480e0 FUN_000480e0 (12 B): matches/0x000480e0.cpp
// sym: ?SetCompare_000480e0@Target_480e0@fn_f64b1530@@QAE_NH@Z
bool Target_480e0::SetCompare_000480e0(int x) {
    value = x;
    return true;
}


// 0x000480f0 FUN_000480f0 (12 B): matches/0x000480f0.cpp
// sym: ?SetStatus_000480f0@Obj_480f0@fn_f64b1530@@QAE_NH@Z
bool Obj_480f0::SetStatus_000480f0(int x) {
    m = x;
    return true;
}

} // namespace fn_f64b1530

// 0x00048100 FUN_00048100 (12 B): matches/0x00048100.cpp
// sym: ?FUN_00048100@Obj_48100@owners@@QAEEE@Z
unsigned char owners::Obj_48100::FUN_00048100(unsigned char x) {
    value = x;
    return 1;
}

namespace fn_f64b1530 {

// 0x00048110 FUN_00048110 (12 B): matches/0x00048110.cpp
// sym: ?SetCompare_00048110@Obj_48110@fn_f64b1530@@QAE_NH@Z
bool Obj_48110::SetCompare_00048110(int v) {
    mValue = v;
    return true;
}


// 0x00048120 FUN_00048120 (12 B): matches/0x00048120.cpp
// sym: ?SetTime_00048120@Obj_48120@fn_f64b1530@@QAEDH@Z
char Obj_48120::SetTime_00048120(int x) {
    mVal = x;
    return 1;
}


// 0x00048140 FUN_00048140 (12 B): matches/0x00048140.cpp
// sym: ?SetUseKeyWordWait_00048140@X_48140@fn_f64b1530@@QAEDD@Z
char X_48140::SetUseKeyWordWait_00048140(char a) {
    mVal = a;
    return 1;
}


// 0x00048160 FUN_00048160 (12 B): matches/0x00048160.cpp
// sym: ?SetKeyWord_00048160@Obj_48160@fn_f64b1530@@QAEDH@Z
char Obj_48160::SetKeyWord_00048160(int x) {
    *(int*)((char*)m + 0x18) = x;
    return 1;
}

} // namespace fn_f64b1530

// 0x00048170 FUN_00048170 (12 B): matches/0x00048170.cpp
// sym: ?FUN_00048170@Obj_48170@owners@@QAE_NH@Z
bool owners::Obj_48170::FUN_00048170(int value) {
    mField = value;
    return true;
}


// 0x00048180 FUN_00048180 (12 B): matches/0x00048180.cpp
// sym: ?FUN_00048180@Obj_48180@owners@@QAE_NH@Z
bool owners::Obj_48180::FUN_00048180(int x) {
    value = x;
    return true;
}

namespace fn_f64b1530 {

// 0x00048190 FUN_00048190 (12 B): matches/0x00048190.cpp
// sym: ?SetCompare_00048190@Obj_48190@fn_f64b1530@@QAE_NH@Z
bool Obj_48190::SetCompare_00048190(int x) {
    mValue = x;
    return true;
}


// 0x000481a0 FUN_000481a0 (4 B): matches/0x000481a0.cpp
// sym: ?GetFightNode_000481a0@Obj_481a0@fn_f64b1530@@QAEPAXXZ
void* Obj_481a0::GetFightNode_000481a0() {
    return (char*)this + 0x10;
}


// 0x000481b0 FUN_000481b0 (12 B): matches/0x000481b0.cpp
// sym: ?SetLastFrame_000481b0@Obj_481b0@fn_f64b1530@@QAEDD@Z
char Obj_481b0::SetLastFrame_000481b0(char v) {
    m = v;
    return 1;
}

} // namespace fn_f64b1530

// 0x000481c0 FUN_000481c0 (12 B): matches/0x000481c0.cpp
// sym: ?FUN_000481c0@Obj_481c0@owners@@QAE_NPAX@Z
bool owners::Obj_481c0::FUN_000481c0(void* p) {
    mObj = p;
    return true;
}


// 0x000481d0 FUN_000481d0 (12 B): matches/0x000481d0.cpp
// sym: ?FUN_000481d0@Obj_481d0@owners@@QAEDH@Z
char owners::Obj_481d0::FUN_000481d0(int x) {
    value = x;
    return 1;
}


// 0x000481e0 FUN_000481e0 (12 B): matches/0x000481e0.cpp
// sym: ?FUN_000481e0@Obj_481e0@owners@@QAEDPAX@Z
char owners::Obj_481e0::FUN_000481e0(void* p) {
    mP = p;
    return 1;
}


// 0x000481f0 FUN_000481f0 (12 B): matches/0x000481f0.cpp
// sym: ?FUN_000481f0@X_481f0@owners@@QAEDD@Z
char owners::X_481f0::FUN_000481f0(char b) {
    m10 = b;
    return 1;
}

namespace fn_f64b1530 {

// 0x00048200 FUN_00048200 (18 B): matches/0x00048200.cpp
// sym: ?SetAngle_00048200@Obj_48200@fn_f64b1530@@QAEDM@Z
char Obj_48200::SetAngle_00048200(float deg) {
    *(float*)((char*)this + 0x0c) = deg * rads;
    return 1;
}


// 0x00048220 FUN_00048220 (18 B): matches/0x00048220.cpp
// sym: ?SetArc_00048220@Obj_48220@fn_f64b1530@@QAEEM@Z
unsigned char Obj_48220::SetArc_00048220(float deg) {
    rad = deg * 0.017453292f;
    return 1;
}


// 0x00048240 FUN_00048240 (12 B): matches/0x00048240.cpp
// sym: ?SetMinVelocity_00048240@Obj@fn_f64b1530@@QAEDH@Z
char Obj::SetMinVelocity_00048240(int x) {
    value = x;
    return 1;
}


// 0x00048260 FUN_00048260 (52 B): matches/0x00048260.cpp
// sym: _FUN_00048260
extern "C" int FUN_00048260(C* p) {
    if (!p)
        return 0;
    C* q = ((C *)((owners::Object_592a0 *)p)->FUN_000592a0())->Second_00059a30();
    int r = q->b;
    if (!r)
        r = q->a;
    if (!r)
        r = q->c;
    return r;
}


// 0x000482d0 CCondition::vfunc_6 (13 B): matches/0x000482d0.cpp
// sym: ?vfunc_6@CCondition@fn_f64b1530@@QAEHHHH@Z
int CCondition::vfunc_6(int x, int y, int z) {
    return h(y);
}


// 0x000482e0 FUN_000482e0 (19 B): matches/0x000482e0.cpp
// sym: ?FUN_000482e0@fn_f64b1530@@YAXPAX@Z
void FUN_000482e0(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004dc3f8), ((char*)&DAT_004dc3fc));
}

} // namespace fn_f64b1530
