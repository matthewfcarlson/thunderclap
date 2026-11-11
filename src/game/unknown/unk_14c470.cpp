// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014c470..0x0014db60 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2fc69c6 {
#define TREE_TU_END }
namespace fn_f2fc69c6 {} using namespace fn_f2fc69c6;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f2fc69c6 {
class Obj_14c490 {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0xc - 4];
    int mField;
    char Set(int x);
};
class X_14c4d0 {
  public:
    char pad[12];
    int m;
    char SetCompare_0014c4d0(int v);
};
class X_14c4e0 {
  public:
    char pad[0x10];
    int m;
    bool SetSize_0014c4e0(int v);
};
class Obj_14c4f0 {
  public:
    char pad[12];
    int mValue;
    bool SetCompare_0014c4f0(int v);
};
class Obj_14c500 {
  public:
    char SetType_0014c500(int x);
    char pad[0x10];
    int m10;
};
class X_14c550 {
  public:
    char pad[12];
    unsigned char m;
    unsigned char Fn(unsigned char b);
};
class Base_14c580 {
  public:
    virtual void F0();
    char pad[8];
};
class D : public Base_14c580 {
  public:
    virtual void F1();
    int mVal;
    bool SetCompare_0014c580(int v);
};
class Obj_14c590 {
  public:
    char pad[0x10];
    int value;
    bool SetSize_0014c590(int x);
};
class Obj_14c610 {
  public:
    int pad[3];
    int mValue;
    unsigned char SetCompare_0014c610(int v);
};
class Base_14c620 {
  public:
    char pad[0x10];
};
class A_14c620 : public Base_14c620 {
  public:
    void* GetBranch_0014c620();
};
class X_14c630 {
  public:
    char pad[0x1c];
    unsigned char m1c;
    unsigned char SetCheckAncestors_0014c630(unsigned char x);
};
class Obj_14c640 {
  public:
    char pad[0x0c];
    bool SetCompare_0014c640(unsigned int v);
};
class X_14c660 {
  public:
    char Pad[0x10];
    int mVal;
    char SetCharge_0014c660(int v);
};
class A_14c680 {
  public:
    char p[0x14];
    char value;
    char SetUseArmorValue_0014c680(char arg);
};
class Obj_14c6b0 {
  public:
    char mFlag;
    char mPad[8];
    int mValue;
    bool SetCompare_0014c6b0(int v);
};
class X_14c6d0 {
  public:
    char pad[0x10];
    int m10;
    char SetDamage_0014c6d0(int a);
};
class Obj_14c6e0 {
  public:
    char m[0x14];
    int mVal;
    char SetPercent_0014c6e0(int v);
};
class A_14c700 {
  public:
    char pad[24];
    unsigned char m18;
    unsigned char SetCompareVsHealthPercent_0014c700(unsigned char c);
};
class Obj_14c710 {
  public:
    char pad[12];
    int m1c;
    char SetCompare_0014c710(int v);
};
class Obj_14c720 {
  public:
    char pad[0x10];
    int mValue;
    bool SetType_0014c720(int x);
};
class C_14c730 {
  public:
    char pad[12];
    int m;
    unsigned char f(int x);
};
class Obj_14caa0 {
  public:
    char pad[0xc];
    int mFlag;
    bool SetTimeBegin_0014caa0(int value);
};
class Obj_14cac0 {
  public:
    char pad[0x10];
    int value;
    bool SetPauseTime_0014cac0(int v);
};
class X_14cae0 {
  public:
    char SetBlendOutTime_0014cae0(int v);
    char pad[0x14];
    int m14;
};
class O_14cce0 {
  public:
    char pad[12];
    int m;
    char SetTimeBegin_0014cce0(int a);
};
class T_14ccf0 {
  public:
    char pad[0x10];
    int m10;
    char SetTimeEnd_0014ccf0(int a);
};
class A_14cd10 {
  public:
    char p[0x14];
    int m;
    bool SetInterruptPriority_0014cd10(int v);
};
union U_14d180 {
    unsigned u;
    float f;
};
static const U_14d180 kU = {0x3c8efa35u};
extern int* gTable_14d270;
class CCondition_14d270 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d2e0;
class CCondition_14d2e0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d350;
class CCondition_14d350 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d3b0;
class CCondition_14d3b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d420;
class CCondition_14d420 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d490;
class CCondition_14d490 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d500;
class CCondition_14d500 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d560;
class CCondition_14d560 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d5c0;
class CCondition_14d5c0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d620;
class CCondition_14d620 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d690;
class CCondition_14d690 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d6f0;
class CCondition_14d6f0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d760;
class CCondition_14d760 {
  public:
    virtual int vfunc_0(int);
};
extern void* g_vftable_14d790[];
class Str_14d790 {
  public:
    void Init();
};
class Condition_14d790 {
  public:
    void* vptr;
    char pad[12];
    Str_14d790 s;
    void Fin();
};
class CollisionThrownObjectCondition_14d790 : public Condition_14d790 {
  public:
    ~CollisionThrownObjectCondition_14d790();
};
extern int* gTable_14d7d0;
class CCondition_14d7d0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d830;
class CCondition_14d830 {
  public:
    virtual int vfunc_0(int);
};
extern void* g_vt_14d870[];
struct Sub_14d870 {
    void Fin() throw();
};
class Condition_14d870 {
  public:
    void* vptr;
    ~Condition_14d870() throw();
};
class CollisionSourceNodeCondition_14d870 : public Condition_14d870 {
  public:
    char pad[0x10 - 4];
    Sub_14d870 sub;
    ~CollisionSourceNodeCondition_14d870() throw();
};
extern int* gTable_14d8b0;
class CCondition_14d8b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14d920;
class CCondition_14d920 {
  public:
    virtual int vfunc_0(int);
};
extern void* g_vftable_14d960[];
class Str_14d960 {
  public:
    void Init();
};
class Condition_14d960 {
  public:
    void* vptr;
    char pad[12];
    Str_14d960 s;
    void Fin();
};
class CollisionTargetNameCondition_14d960 : public Condition_14d960 {
  public:
    ~CollisionTargetNameCondition_14d960();
};
extern int* gTable_14d9a0;
class CCondition_14d9a0 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14da10;
class CCondition_14da10 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14da80;
class CCondition_14da80 {
  public:
    virtual int vfunc_0(int);
};
extern int* gTable_14dae0;
class CCondition_14dae0 {
  public:
    virtual int vfunc_0(int);
};
extern void* g_vftable_14db20[];
struct Sub_14db20 {
    void Fin();
};
class Condition_14db20 {
  public:
    void* vptr;
    void Fin();
};
class CollisionSourceNameCondition_14db20 : public Condition_14db20 {
  public:
    char pad[0xc];
    Sub_14db20 sub;
    void f();
};

} // namespace fn_f2fc69c6

// 0x0014c470 FUN_0014c470 (12 B): matches/0x0014c470.cpp
// sym: ?FUN_0014c470@Obj_14c470@owners@@QAE_NH@Z
bool owners::Obj_14c470::FUN_0014c470(int x) {
    value = x;
    return true;
}


// 0x0014c480 FUN_0014c480 (12 B): matches/0x0014c480.cpp
// sym: ?FUN_0014c480@Obj_14c480@owners@@QAE_NH@Z
bool owners::Obj_14c480::FUN_0014c480(int x) {
    mField = x;
    return true;
}

namespace fn_f2fc69c6 {

// 0x0014c490 FUN_0014c490 (12 B): matches/0x0014c490.cpp
// sym: ?Set@Obj_14c490@fn_f2fc69c6@@QAEDH@Z
char Obj_14c490::Set(int x) {
    mField = x;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014c4c0 FUN_0014c4c0 (12 B): matches/0x0014c4c0.cpp
// sym: ?FUN_0014c4c0@Obj_14c4c0@owners@@QAE_NE@Z
bool owners::Obj_14c4c0::FUN_0014c4c0(unsigned char x) {
    mField = x;
    return true;
}

namespace fn_f2fc69c6 {

// 0x0014c4d0 FUN_0014c4d0 (12 B): matches/0x0014c4d0.cpp
// sym: ?SetCompare_0014c4d0@X_14c4d0@fn_f2fc69c6@@QAEDH@Z
char X_14c4d0::SetCompare_0014c4d0(int v) {
    m = v;
    return 1;
}


// 0x0014c4e0 FUN_0014c4e0 (12 B): matches/0x0014c4e0.cpp
// sym: ?SetSize_0014c4e0@X_14c4e0@fn_f2fc69c6@@QAE_NH@Z
bool X_14c4e0::SetSize_0014c4e0(int v) {
    m = v;
    return true;
}


// 0x0014c4f0 FUN_0014c4f0 (12 B): matches/0x0014c4f0.cpp
// sym: ?SetCompare_0014c4f0@Obj_14c4f0@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14c4f0::SetCompare_0014c4f0(int v) {
    mValue = v;
    return true;
}


// 0x0014c500 FUN_0014c500 (12 B): matches/0x0014c500.cpp
// sym: ?SetType_0014c500@Obj_14c500@fn_f2fc69c6@@QAEDH@Z
char Obj_14c500::SetType_0014c500(int x) {
    m10 = x;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014c510 FUN_0014c510 (12 B): matches/0x0014c510.cpp
// sym: ?FUN_0014c510@X_14c510@owners@@QAE_NH@Z
bool owners::X_14c510::FUN_0014c510(int v) {
    m = v;
    return true;
}


// 0x0014c530 FUN_0014c530 (12 B): matches/0x0014c530.cpp
// sym: ?FUN_0014c530@T_14c530@owners@@QAE_NH@Z
bool owners::T_14c530::FUN_0014c530(int x) {
    value = x;
    return true;
}


// 0x0014c540 FUN_0014c540 (12 B): matches/0x0014c540.cpp
// sym: ?FUN_0014c540@Obj_14c540@owners@@QAEDE@Z
char owners::Obj_14c540::FUN_0014c540(unsigned char c) {
    value = (char)c;
    return 1;
}

namespace fn_f2fc69c6 {

// 0x0014c550 FUN_0014c550 (12 B): matches/0x0014c550.cpp
// sym: ?Fn@X_14c550@fn_f2fc69c6@@QAEEE@Z
unsigned char X_14c550::Fn(unsigned char b) {
    m = b;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014c570 FUN_0014c570 (12 B): matches/0x0014c570.cpp
// sym: ?FUN_0014c570@X_14c570@owners@@QAEEE@Z
unsigned char owners::X_14c570::FUN_0014c570(unsigned char v) {
    mValue = v;
    return 1;
}

namespace fn_f2fc69c6 {

// 0x0014c580 FUN_0014c580 (12 B): matches/0x0014c580.cpp
// sym: ?SetCompare_0014c580@D@fn_f2fc69c6@@QAE_NH@Z
bool D::SetCompare_0014c580(int v) {
    mVal = v;
    return true;
}


// 0x0014c590 FUN_0014c590 (12 B): matches/0x0014c590.cpp
// sym: ?SetSize_0014c590@Obj_14c590@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14c590::SetSize_0014c590(int x) {
    value = x;
    return true;
}

} // namespace fn_f2fc69c6

// 0x0014c5a0 FUN_0014c5a0 (12 B): matches/0x0014c5a0.cpp
// sym: ?FUN_0014c5a0@Obj_14c5a0@owners@@QAEEE@Z
unsigned char owners::Obj_14c5a0::FUN_0014c5a0(unsigned char v) {
    mVal = v;
    return 1;
}


// 0x0014c5b0 FUN_0014c5b0 (12 B): matches/0x0014c5b0.cpp
// sym: ?FUN_0014c5b0@Obj_14c5b0@owners@@QAEDH@Z
char owners::Obj_14c5b0::FUN_0014c5b0(int x) {
    value = x;
    return 1;
}


// 0x0014c5d0 FUN_0014c5d0 (12 B): matches/0x0014c5d0.cpp
// sym: ?FUN_0014c5d0@Obj_14c5d0@owners@@QAE_NH@Z
bool owners::Obj_14c5d0::FUN_0014c5d0(int v) {
    mValue = v;
    return true;
}


// 0x0014c5e0 FUN_0014c5e0 (12 B): matches/0x0014c5e0.cpp
// sym: ?FUN_0014c5e0@Obj_14c5e0@owners@@QAEDD@Z
char owners::Obj_14c5e0::FUN_0014c5e0(char v) {
    m = v;
    return 1;
}


// 0x0014c5f0 FUN_0014c5f0 (4 B): matches/0x0014c5f0.cpp
// sym: ?FUN_0014c5f0@X_14c5f0@owners@@QAEPADXZ
char* owners::X_14c5f0::FUN_0014c5f0() {
    return (char*)((char*)this + 0x10);
}


// 0x0014c600 FUN_0014c600 (12 B): matches/0x0014c600.cpp
// sym: ?FUN_0014c600@Obj_14c600@owners@@QAEDD@Z
char owners::Obj_14c600::FUN_0014c600(char x) {
    value = x;
    return 1;
}

namespace fn_f2fc69c6 {

// 0x0014c610 FUN_0014c610 (12 B): matches/0x0014c610.cpp
// sym: ?SetCompare_0014c610@Obj_14c610@fn_f2fc69c6@@QAEEH@Z
unsigned char Obj_14c610::SetCompare_0014c610(int v) {
    mValue = v;
    return 1;
}


// 0x0014c620 FUN_0014c620 (4 B): matches/0x0014c620.cpp
// sym: ?GetBranch_0014c620@A_14c620@fn_f2fc69c6@@QAEPAXXZ
void* A_14c620::GetBranch_0014c620() {
    return (char*)this + 0x10;
}


// 0x0014c630 FUN_0014c630 (12 B): matches/0x0014c630.cpp
// sym: ?SetCheckAncestors_0014c630@X_14c630@fn_f2fc69c6@@QAEEE@Z
unsigned char X_14c630::SetCheckAncestors_0014c630(unsigned char x) {
    m1c = x;
    return 1;
}


// 0x0014c640 FUN_0014c640 (12 B): matches/0x0014c640.cpp
// sym: ?SetCompare_0014c640@Obj_14c640@fn_f2fc69c6@@QAE_NI@Z
bool Obj_14c640::SetCompare_0014c640(unsigned int v) {
    *(unsigned int*)((char*)this + 0x0c) = v;
    return true;
}


// 0x0014c660 FUN_0014c660 (12 B): matches/0x0014c660.cpp
// sym: ?SetCharge_0014c660@X_14c660@fn_f2fc69c6@@QAEDH@Z
char X_14c660::SetCharge_0014c660(int v) {
    mVal = v;
    return 1;
}


// 0x0014c680 FUN_0014c680 (12 B): matches/0x0014c680.cpp
// sym: ?SetUseArmorValue_0014c680@A_14c680@fn_f2fc69c6@@QAEDD@Z
char A_14c680::SetUseArmorValue_0014c680(char arg) {
    value = arg;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014c690 FUN_0014c690 (12 B): matches/0x0014c690.cpp
// sym: ?FUN_0014c690@Obj_14c690@owners@@QAEDH@Z
char owners::Obj_14c690::FUN_0014c690(int x) {
    value = x;
    return 1;
}


// 0x0014c6a0 FUN_0014c6a0 (4 B): matches/0x0014c6a0.cpp
// sym: ?FUN_0014c6a0@Obj_14c6a0@owners@@QAEPAHXZ
int* owners::Obj_14c6a0::FUN_0014c6a0() {
    return (int*)((char*)this + 0x10);
}

namespace fn_f2fc69c6 {

// 0x0014c6b0 FUN_0014c6b0 (12 B): matches/0x0014c6b0.cpp
// sym: ?SetCompare_0014c6b0@Obj_14c6b0@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14c6b0::SetCompare_0014c6b0(int v) {
    mValue = v;
    return true;
}


// 0x0014c6d0 FUN_0014c6d0 (12 B): matches/0x0014c6d0.cpp
// sym: ?SetDamage_0014c6d0@X_14c6d0@fn_f2fc69c6@@QAEDH@Z
char X_14c6d0::SetDamage_0014c6d0(int a) {
    m10 = a;
    return 1;
}


// 0x0014c6e0 FUN_0014c6e0 (12 B): matches/0x0014c6e0.cpp
// sym: ?SetPercent_0014c6e0@Obj_14c6e0@fn_f2fc69c6@@QAEDH@Z
char Obj_14c6e0::SetPercent_0014c6e0(int v) {
    mVal = v;
    return 1;
}


// 0x0014c700 FUN_0014c700 (12 B): matches/0x0014c700.cpp
// sym: ?SetCompareVsHealthPercent_0014c700@A_14c700@fn_f2fc69c6@@QAEEE@Z
unsigned char A_14c700::SetCompareVsHealthPercent_0014c700(unsigned char c) {
    m18 = c;
    return 1;
}


// 0x0014c710 FUN_0014c710 (12 B): matches/0x0014c710.cpp
// sym: ?SetCompare_0014c710@Obj_14c710@fn_f2fc69c6@@QAEDH@Z
char Obj_14c710::SetCompare_0014c710(int v) {
    m1c = v;
    return 1;
}


// 0x0014c720 FUN_0014c720 (12 B): matches/0x0014c720.cpp
// sym: ?SetType_0014c720@Obj_14c720@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14c720::SetType_0014c720(int x) {
    mValue = x;
    return true;
}


// 0x0014c730 FUN_0014c730 (12 B): matches/0x0014c730.cpp
// sym: ?f@C_14c730@fn_f2fc69c6@@QAEEH@Z
unsigned char C_14c730::f(int x) {
    m = x;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014c740 FUN_0014c740 (12 B): matches/0x0014c740.cpp
// sym: ?FUN_0014c740@Obj_14c740@owners@@QAE_NI@Z
bool owners::Obj_14c740::FUN_0014c740(unsigned int x) {
    value = x;
    return true;
}


// 0x0014c750 FUN_0014c750 (4 B): matches/0x0014c750.cpp
// sym: ?FUN_0014c750@Obj_14c750@owners@@QAEPAXXZ
void* owners::Obj_14c750::FUN_0014c750() {
    return &m;
}


// 0x0014c760 FUN_0014c760 (12 B): matches/0x0014c760.cpp
// sym: ?FUN_0014c760@A_14c760@owners@@QAE_NH@Z
bool owners::A_14c760::FUN_0014c760(int v) {
    m = v;
    return true;
}


// 0x0014c780 FUN_0014c780 (12 B): matches/0x0014c780.cpp
// sym: ?FUN_0014c780@Obj_14c780@owners@@QAEDH@Z
char owners::Obj_14c780::FUN_0014c780(int x) {
    value = x;
    return 1;
}


// 0x0014c790 FUN_0014c790 (12 B): matches/0x0014c790.cpp
// sym: ?FUN_0014c790@X_14c790@owners@@QAE_NH@Z
bool owners::X_14c790::FUN_0014c790(int v) {
    m12 = v;
    return true;
}


// 0x0014c7a0 FUN_0014c7a0 (12 B): matches/0x0014c7a0.cpp
// sym: ?FUN_0014c7a0@X_14c7a0@owners@@QAE_NH@Z
bool owners::X_14c7a0::FUN_0014c7a0(int v) {
    m10 = v;
    return true;
}


// 0x0014c7c0 FUN_0014c7c0 (12 B): matches/0x0014c7c0.cpp
// sym: ?FUN_0014c7c0@X_14c7c0@owners@@QAEDD@Z
char owners::X_14c7c0::FUN_0014c7c0(char value) {
    mX = value;
    return 1;
}


// 0x0014c7e0 FUN_0014c7e0 (18 B): matches/0x0014c7e0.cpp
// sym: ?FUN_0014c7e0@C_14c7e0@owners@@QAEDM@Z
char owners::C_14c7e0::FUN_0014c7e0(float x) {
    mDeg = x * 0.0174532925f;
    return 1;
}


// 0x0014c810 FUN_0014c810 (12 B): matches/0x0014c810.cpp
// sym: ?FUN_0014c810@Obj_14c810@owners@@QAEDH@Z
char owners::Obj_14c810::FUN_0014c810(int x) {
    value = x;
    return 1;
}


// 0x0014c830 FUN_0014c830 (12 B): matches/0x0014c830.cpp
// sym: ?FUN_0014c830@Obj_14c830@owners@@QAEDH@Z
char owners::Obj_14c830::FUN_0014c830(int arg) {
    Value = arg;
    return 1;
}


// 0x0014c850 FUN_0014c850 (12 B): matches/0x0014c850.cpp
// sym: ?FUN_0014c850@Obj_14c850@owners@@QAE_NH@Z
bool owners::Obj_14c850::FUN_0014c850(int x) {
    value = x;
    return true;
}


// 0x0014c870 FUN_0014c870 (12 B): matches/0x0014c870.cpp
// sym: ?FUN_0014c870@Obj_14c870@owners@@QAEDH@Z
char owners::Obj_14c870::FUN_0014c870(int v) {
    m28 = v;
    return 1;
}


// 0x0014c880 FUN_0014c880 (12 B): matches/0x0014c880.cpp
// sym: ?FUN_0014c880@Obj_14c880@owners@@QAE_NH@Z
bool owners::Obj_14c880::FUN_0014c880(int x) {
    value = x;
    return true;
}


// 0x0014c8a0 FUN_0014c8a0 (12 B): matches/0x0014c8a0.cpp
// sym: ?FUN_0014c8a0@Obj_14c8a0@owners@@QAE_NH@Z
bool owners::Obj_14c8a0::FUN_0014c8a0(int v) {
    value = v;
    return true;
}


// 0x0014c8c0 FUN_0014c8c0 (18 B): matches/0x0014c8c0.cpp
// sym: ?FUN_0014c8c0@C_14c8c0@owners@@QAE_NM@Z
bool owners::C_14c8c0::FUN_0014c8c0(float x) {
    mAngle = x * 0.0174532925f;
    return true;
}


// 0x0014c8e0 FUN_0014c8e0 (4 B): matches/0x0014c8e0.cpp
// sym: ?FUN_0014c8e0@Obj_14c8e0@owners@@QAEPAXXZ
void* owners::Obj_14c8e0::FUN_0014c8e0() {
    return (char*)this + 0x18;
}


// 0x0014c900 FUN_0014c900 (12 B): matches/0x0014c900.cpp
// sym: ?FUN_0014c900@Obj_14c900@owners@@QAE_NH@Z
bool owners::Obj_14c900::FUN_0014c900(int x) {
    field = x;
    return true;
}


// 0x0014c920 FUN_0014c920 (18 B): matches/0x0014c920.cpp
// sym: ?FUN_0014c920@C_14c920@owners@@QAE_NM@Z
bool owners::C_14c920::FUN_0014c920(float v) {
    mAngle = v * 0.017453292519943295f;
    return true;
}


// 0x0014c950 FUN_0014c950 (12 B): matches/0x0014c950.cpp
// sym: ?FUN_0014c950@X_14c950@owners@@QAE_NH@Z
bool owners::X_14c950::FUN_0014c950(int a) {
    *(int*)((char*)this + 0x28) = a;
    return true;
}


// 0x0014c970 FUN_0014c970 (12 B): matches/0x0014c970.cpp
// sym: ?FUN_0014c970@Obj_14c970@owners@@QAE_NH@Z
bool owners::Obj_14c970::FUN_0014c970(int v) {
    m2c = v;
    return true;
}


// 0x0014c990 FUN_0014c990 (12 B): matches/0x0014c990.cpp
// sym: ?FUN_0014c990@O_14c990@owners@@QAE_NH@Z
bool owners::O_14c990::FUN_0014c990(int v) {
    m30 = v;
    return true;
}


// 0x0014c9b0 FUN_0014c9b0 (12 B): matches/0x0014c9b0.cpp
// sym: ?FUN_0014c9b0@Obj_14c9b0@owners@@QAE_NH@Z
bool owners::Obj_14c9b0::FUN_0014c9b0(int value) {
    mField = value;
    return true;
}


// 0x0014c9d0 FUN_0014c9d0 (12 B): matches/0x0014c9d0.cpp
// sym: ?FUN_0014c9d0@Obj_14c9d0@owners@@QAE_NH@Z
bool owners::Obj_14c9d0::FUN_0014c9d0(int value) {
    m38 = value;
    return true;
}


// 0x0014c9f0 FUN_0014c9f0 (12 B): matches/0x0014c9f0.cpp
// sym: ?FUN_0014c9f0@Obj_14c9f0@owners@@QAEDH@Z
char owners::Obj_14c9f0::FUN_0014c9f0(int x) {
    Value = x;
    return 1;
}


// 0x0014ca10 FUN_0014ca10 (12 B): matches/0x0014ca10.cpp
// sym: ?FUN_0014ca10@Obj_14ca10@owners@@QAEDH@Z
char owners::Obj_14ca10::FUN_0014ca10(int v) {
    mVal = v;
    return 1;
}


// 0x0014ca30 FUN_0014ca30 (12 B): matches/0x0014ca30.cpp
// sym: ?FUN_0014ca30@Obj_14ca30@owners@@QAE_NH@Z
bool owners::Obj_14ca30::FUN_0014ca30(int x) {
    mVal = x;
    return true;
}


// 0x0014ca50 FUN_0014ca50 (12 B): matches/0x0014ca50.cpp
// sym: ?FUN_0014ca50@Obj_14ca50@owners@@QAE_NH@Z
bool owners::Obj_14ca50::FUN_0014ca50(int value) {
    field = value;
    return true;
}


// 0x0014ca70 FUN_0014ca70 (12 B): matches/0x0014ca70.cpp
// sym: ?FUN_0014ca70@Obj_14ca70@owners@@QAE_NH@Z
bool owners::Obj_14ca70::FUN_0014ca70(int v) {
    m4c = v;
    return true;
}


// 0x0014ca90 FUN_0014ca90 (12 B): matches/0x0014ca90.cpp
// sym: ?FUN_0014ca90@Obj_14ca90@owners@@QAEEE@Z
unsigned char owners::Obj_14ca90::FUN_0014ca90(unsigned char x) {
    m50 = x;
    return 1;
}

namespace fn_f2fc69c6 {

// 0x0014caa0 FUN_0014caa0 (12 B): matches/0x0014caa0.cpp
// sym: ?SetTimeBegin_0014caa0@Obj_14caa0@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14caa0::SetTimeBegin_0014caa0(int value) {
    mFlag = value;
    return true;
}


// 0x0014cac0 FUN_0014cac0 (12 B): matches/0x0014cac0.cpp
// sym: ?SetPauseTime_0014cac0@Obj_14cac0@fn_f2fc69c6@@QAE_NH@Z
bool Obj_14cac0::SetPauseTime_0014cac0(int v) {
    value = v;
    return true;
}


// 0x0014cae0 FUN_0014cae0 (12 B): matches/0x0014cae0.cpp
// sym: ?SetBlendOutTime_0014cae0@X_14cae0@fn_f2fc69c6@@QAEDH@Z
char X_14cae0::SetBlendOutTime_0014cae0(int v) {
    m14 = v;
    return 1;
}

} // namespace fn_f2fc69c6

// 0x0014caf0 FUN_0014caf0 (12 B): matches/0x0014caf0.cpp
// sym: ?FUN_0014caf0@O_14caf0@owners@@QAEDH@Z
char owners::O_14caf0::FUN_0014caf0(int x) {
    m1c = x;
    return 1;
}


// 0x0014cb10 FUN_0014cb10 (12 B): matches/0x0014cb10.cpp
// sym: ?FUN_0014cb10@X_14cb10@owners@@QAE_NH@Z
bool owners::X_14cb10::FUN_0014cb10(int v) {
    mValue = v;
    return true;
}


// 0x0014cb30 FUN_0014cb30 (18 B): matches/0x0014cb30.cpp
// sym: ?FUN_0014cb30@C_14cb30@owners@@QAE_NM@Z
bool owners::C_14cb30::FUN_0014cb30(float deg) {
    mAngle = deg * 0.0174532925f;
    return true;
}


// 0x0014cb50 FUN_0014cb50 (4 B): matches/0x0014cb50.cpp
// sym: ?FUN_0014cb50@Obj_14cb50@owners@@QAEPAPAHXZ
int** owners::Obj_14cb50::FUN_0014cb50() {
    return &value;
}


// 0x0014cb70 FUN_0014cb70 (12 B): matches/0x0014cb70.cpp
// sym: ?FUN_0014cb70@X_14cb70@owners@@QAEDH@Z
char owners::X_14cb70::FUN_0014cb70(int v) {
    m = v;
    return 1;
}


// 0x0014cb90 FUN_0014cb90 (12 B): matches/0x0014cb90.cpp
// sym: ?FUN_0014cb90@T_14cb90@owners@@QAE_NH@Z
bool owners::T_14cb90::FUN_0014cb90(int v) {
    mVal = v;
    return true;
}


// 0x0014cbb0 FUN_0014cbb0 (12 B): matches/0x0014cbb0.cpp
// sym: ?FUN_0014cbb0@Obj_14cbb0@owners@@QAEDD@Z
char owners::Obj_14cbb0::FUN_0014cbb0(char c) {
    m28 = c;
    return 1;
}


// 0x0014cbd0 FUN_0014cbd0 (12 B): matches/0x0014cbd0.cpp
// sym: ?FUN_0014cbd0@Obj_14cbd0@owners@@QAE_NH@Z
bool owners::Obj_14cbd0::FUN_0014cbd0(int value) {
    m_field = value;
    return true;
}


// 0x0014cbf0 FUN_0014cbf0 (18 B): matches/0x0014cbf0.cpp
// sym: ?FUN_0014cbf0@Obj_14cbf0@owners@@QAEDM@Z
char owners::Obj_14cbf0::FUN_0014cbf0(float a) {
    angle = a * 0.017453292519943295f;
    return 1;
}


// 0x0014cc20 FUN_0014cc20 (12 B): matches/0x0014cc20.cpp
// sym: ?FUN_0014cc20@Obj_14cc20@owners@@QAEDPAX@Z
char owners::Obj_14cc20::FUN_0014cc20(void* v) {
    m = v;
    return 1;
}


// 0x0014cc40 FUN_0014cc40 (12 B): matches/0x0014cc40.cpp
// sym: ?FUN_0014cc40@Obj_14cc40@owners@@QAE_NH@Z
bool owners::Obj_14cc40::FUN_0014cc40(int v) {
    m38 = v;
    return true;
}


// 0x0014cc60 FUN_0014cc60 (12 B): matches/0x0014cc60.cpp
// sym: ?FUN_0014cc60@X_14cc60@owners@@QAEDH@Z
char owners::X_14cc60::FUN_0014cc60(int v) {
    m3c = v;
    return 1;
}


// 0x0014cc80 FUN_0014cc80 (12 B): matches/0x0014cc80.cpp
// sym: ?FUN_0014cc80@C_14cc80@owners@@QAEDH@Z
char owners::C_14cc80::FUN_0014cc80(int value) {
    mValue = value;
    return 1;
}


// 0x0014cca0 FUN_0014cca0 (12 B): matches/0x0014cca0.cpp
// sym: ?FUN_0014cca0@X_14cca0@owners@@QAEDD@Z
char owners::X_14cca0::FUN_0014cca0(char v) {
    m44 = v;
    return 1;
}


// 0x0014ccb0 FUN_0014ccb0 (12 B): matches/0x0014ccb0.cpp
// sym: ?FUN_0014ccb0@X_14ccb0@owners@@QAEDH@Z
char owners::X_14ccb0::FUN_0014ccb0(int v) {
    m = v;
    return 1;
}


// 0x0014ccd0 FUN_0014ccd0 (12 B): matches/0x0014ccd0.cpp
// sym: ?FUN_0014ccd0@Obj_14ccd0@owners@@QAE_NH@Z
bool owners::Obj_14ccd0::FUN_0014ccd0(int x) {
    value = x;
    return true;
}

namespace fn_f2fc69c6 {

// 0x0014cce0 FUN_0014cce0 (12 B): matches/0x0014cce0.cpp
// sym: ?SetTimeBegin_0014cce0@O_14cce0@fn_f2fc69c6@@QAEDH@Z
char O_14cce0::SetTimeBegin_0014cce0(int a) {
    m = a;
    return 1;
}


// 0x0014ccf0 FUN_0014ccf0 (12 B): matches/0x0014ccf0.cpp
// sym: ?SetTimeEnd_0014ccf0@T_14ccf0@fn_f2fc69c6@@QAEDH@Z
char T_14ccf0::SetTimeEnd_0014ccf0(int a) {
    m10 = a;
    return 1;
}


// 0x0014cd10 FUN_0014cd10 (12 B): matches/0x0014cd10.cpp
// sym: ?SetInterruptPriority_0014cd10@A_14cd10@fn_f2fc69c6@@QAE_NH@Z
bool A_14cd10::SetInterruptPriority_0014cd10(int v) {
    m = v;
    return true;
}

} // namespace fn_f2fc69c6

// 0x0014cd20 FUN_0014cd20 (12 B): matches/0x0014cd20.cpp
// sym: ?FUN_0014cd20@X_14cd20@owners@@QAEDH@Z
char owners::X_14cd20::FUN_0014cd20(int v) {
    mField = v;
    return 1;
}


// 0x0014cd30 FUN_0014cd30 (12 B): matches/0x0014cd30.cpp
// sym: ?FUN_0014cd30@Target_14cd30@owners@@QAEDH@Z
char owners::Target_14cd30::FUN_0014cd30(int x) {
    mArg = x;
    return 1;
}


// 0x0014cd50 FUN_0014cd50 (18 B): matches/0x0014cd50.cpp
// sym: ?FUN_0014cd50@C_14cd50@owners@@QAE_NM@Z
bool owners::C_14cd50::FUN_0014cd50(float v) {
    mAngle = v * 0.01745329252f;
    return true;
}


// 0x0014cd80 FUN_0014cd80 (12 B): matches/0x0014cd80.cpp
// sym: ?FUN_0014cd80@X_14cd80@owners@@QAE_NH@Z
bool owners::X_14cd80::FUN_0014cd80(int v) {
    value = v;
    return true;
}


// 0x0014cda0 FUN_0014cda0 (12 B): matches/0x0014cda0.cpp
// sym: ?FUN_0014cda0@Obj_14cda0@owners@@QAEDH@Z
char owners::Obj_14cda0::FUN_0014cda0(int x) {
    value = x;
    return 1;
}


// 0x0014cdc0 FUN_0014cdc0 (12 B): matches/0x0014cdc0.cpp
// sym: ?FUN_0014cdc0@Obj_14cdc0@owners@@QAEDH@Z
char owners::Obj_14cdc0::FUN_0014cdc0(int v) {
    m = v;
    return 1;
}


// 0x0014cdd0 FUN_0014cdd0 (12 B): matches/0x0014cdd0.cpp
// sym: ?FUN_0014cdd0@Obj_14cdd0@owners@@QAEDH@Z
char owners::Obj_14cdd0::FUN_0014cdd0(int v) {
    field = v;
    return 1;
}


// 0x0014cde0 FUN_0014cde0 (12 B): matches/0x0014cde0.cpp
// sym: ?FUN_0014cde0@Obj_14cde0@owners@@QAEDH@Z
char owners::Obj_14cde0::FUN_0014cde0(int x) {
    m10 = x;
    return 1;
}


// 0x0014ce00 FUN_0014ce00 (12 B): matches/0x0014ce00.cpp
// sym: ?FUN_0014ce00@Obj_14ce00@owners@@QAE_NE@Z
bool owners::Obj_14ce00::FUN_0014ce00(unsigned char x) {
    m = x;
    return true;
}


// 0x0014ce20 FUN_0014ce20 (18 B): matches/0x0014ce20.cpp
// sym: ?FUN_0014ce20@C_14ce20@owners@@QAE_NM@Z
bool owners::C_14ce20::FUN_0014ce20(float deg) {
    mRadians = deg * 0.0174532925f;
    return true;
}


// 0x0014ce50 FUN_0014ce50 (12 B): matches/0x0014ce50.cpp
// sym: ?FUN_0014ce50@Obj_14ce50@owners@@QAEDH@Z
char owners::Obj_14ce50::FUN_0014ce50(int x) {
    Value = x;
    return 1;
}


// 0x0014ce70 FUN_0014ce70 (12 B): matches/0x0014ce70.cpp
// sym: ?FUN_0014ce70@T_14ce70@owners@@QAE_NH@Z
bool owners::T_14ce70::FUN_0014ce70(int v) {
    m20 = v;
    return true;
}


// 0x0014ce90 FUN_0014ce90 (12 B): matches/0x0014ce90.cpp
// sym: ?FUN_0014ce90@Obj_14ce90@owners@@QAEDH@Z
char owners::Obj_14ce90::FUN_0014ce90(int a) {
    m24 = a;
    return 1;
}


// 0x0014cea0 FUN_0014cea0 (12 B): matches/0x0014cea0.cpp
// sym: ?FUN_0014cea0@Obj_14cea0@owners@@QAE_NPAX@Z
bool owners::Obj_14cea0::FUN_0014cea0(void* arg) {
    mField = arg;
    return true;
}


// 0x0014ceb0 FUN_0014ceb0 (12 B): matches/0x0014ceb0.cpp
// sym: ?FUN_0014ceb0@Target_14ceb0@owners@@QAE_NPAX@Z
bool owners::Target_14ceb0::FUN_0014ceb0(void* p) {
    mValue = p;
    return true;
}


// 0x0014ced0 FUN_0014ced0 (12 B): matches/0x0014ced0.cpp
// sym: ?FUN_0014ced0@X_14ced0@owners@@QAEDH@Z
char owners::X_14ced0::FUN_0014ced0(int v) {
    m10 = v;
    return 1;
}


// 0x0014cee0 FUN_0014cee0 (12 B): matches/0x0014cee0.cpp
// sym: ?FUN_0014cee0@O_14cee0@owners@@QAEDH@Z
char owners::O_14cee0::FUN_0014cee0(int x) {
    m = x;
    return 1;
}


// 0x0014cf00 FUN_0014cf00 (12 B): matches/0x0014cf00.cpp
// sym: ?FUN_0014cf00@O_14cf00@owners@@QAE_NH@Z
bool owners::O_14cf00::FUN_0014cf00(int x) {
    m = x;
    return true;
}


// 0x0014cf20 FUN_0014cf20 (12 B): matches/0x0014cf20.cpp
// sym: ?FUN_0014cf20@Thing_14cf20@owners@@QAEDD@Z
char owners::Thing_14cf20::FUN_0014cf20(char v) {
    m14 = v;
    return 1;
}


// 0x0014cf40 FUN_0014cf40 (12 B): matches/0x0014cf40.cpp
// sym: ?FUN_0014cf40@X_14cf40@owners@@QAEDD@Z
char owners::X_14cf40::FUN_0014cf40(char v) {
    m = v;
    return 1;
}


// 0x0014cf60 FUN_0014cf60 (12 B): matches/0x0014cf60.cpp
// sym: ?FUN_0014cf60@X_14cf60@owners@@QAEDD@Z
char owners::X_14cf60::FUN_0014cf60(char v) {
    m16 = v;
    return 1;
}


// 0x0014cf70 FUN_0014cf70 (12 B): matches/0x0014cf70.cpp
// sym: ?FUN_0014cf70@Obj_14cf70@owners@@QAEDH@Z
char owners::Obj_14cf70::FUN_0014cf70(int x) {
    m = x;
    return 1;
}


// 0x0014cf90 FUN_0014cf90 (12 B): matches/0x0014cf90.cpp
// sym: ?FUN_0014cf90@Obj_14cf90@owners@@QAE_NH@Z
bool owners::Obj_14cf90::FUN_0014cf90(int value) {
    mValue = value;
    return true;
}


// 0x0014cfa0 FUN_0014cfa0 (12 B): matches/0x0014cfa0.cpp
// sym: ?FUN_0014cfa0@Obj_14cfa0@owners@@QAEDH@Z
char owners::Obj_14cfa0::FUN_0014cfa0(int x) {
    m = x;
    return 1;
}


// 0x0014cfb0 FUN_0014cfb0 (12 B): matches/0x0014cfb0.cpp
// sym: ?FUN_0014cfb0@Target_14cfb0@owners@@QAEDH@Z
char owners::Target_14cfb0::FUN_0014cfb0(int value) {
    mValue = value;
    return 1;
}


// 0x0014cfd0 FUN_0014cfd0 (18 B): matches/0x0014cfd0.cpp
// sym: ?FUN_0014cfd0@C_14cfd0@owners@@QAE_NM@Z
bool owners::C_14cfd0::FUN_0014cfd0(float v) {
    mAngle = v * 0.017453292519943295f;
    return true;
}


// 0x0014d000 FUN_0014d000 (12 B): matches/0x0014d000.cpp
// sym: ?FUN_0014d000@X_14d000@owners@@QAEDH@Z
char owners::X_14d000::FUN_0014d000(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}


// 0x0014d020 FUN_0014d020 (12 B): matches/0x0014d020.cpp
// sym: ?FUN_0014d020@Obj_14d020@owners@@QAE_NH@Z
bool owners::Obj_14d020::FUN_0014d020(int v) {
    m = v;
    return true;
}


// 0x0014d040 FUN_0014d040 (12 B): matches/0x0014d040.cpp
// sym: ?FUN_0014d040@X_14d040@owners@@QAEDH@Z
char owners::X_14d040::FUN_0014d040(int v) {
    m20 = v;
    return 1;
}


// 0x0014d060 FUN_0014d060 (12 B): matches/0x0014d060.cpp
// sym: ?FUN_0014d060@X_14d060@owners@@QAE_NH@Z
bool owners::X_14d060::FUN_0014d060(int x) {
    value = x;
    return true;
}


// 0x0014d080 FUN_0014d080 (12 B): matches/0x0014d080.cpp
// sym: ?FUN_0014d080@C_14d080@owners@@QAE_NH@Z
bool owners::C_14d080::FUN_0014d080(int v) {
    value = v;
    return true;
}


// 0x0014d0a0 FUN_0014d0a0 (12 B): matches/0x0014d0a0.cpp
// sym: ?FUN_0014d0a0@Obj_14d0a0@owners@@QAE_NH@Z
bool owners::Obj_14d0a0::FUN_0014d0a0(int x) {
    m2c = x;
    return true;
}


// 0x0014d0c0 FUN_0014d0c0 (12 B): matches/0x0014d0c0.cpp
// sym: ?FUN_0014d0c0@X_14d0c0@owners@@QAE_NH@Z
bool owners::X_14d0c0::FUN_0014d0c0(int v) {
    m30 = v;
    return true;
}


// 0x0014d0e0 FUN_0014d0e0 (12 B): matches/0x0014d0e0.cpp
// sym: ?FUN_0014d0e0@X_14d0e0@owners@@QAE_NH@Z
bool owners::X_14d0e0::FUN_0014d0e0(int v) {
    m34 = v;
    return true;
}


// 0x0014d0f0 FUN_0014d0f0 (12 B): matches/0x0014d0f0.cpp
// sym: ?FUN_0014d0f0@X_14d0f0@owners@@QAE_NH@Z
bool owners::X_14d0f0::FUN_0014d0f0(int v) {
    m = v;
    return true;
}


// 0x0014d100 FUN_0014d100 (12 B): matches/0x0014d100.cpp
// sym: ?FUN_0014d100@Obj_14d100@owners@@QAE_NH@Z
bool owners::Obj_14d100::FUN_0014d100(int x) {
    m = x;
    return true;
}


// 0x0014d120 FUN_0014d120 (12 B): matches/0x0014d120.cpp
// sym: ?FUN_0014d120@Obj_14d120@owners@@QAE_NH@Z
bool owners::Obj_14d120::FUN_0014d120(int v) {
    value = v;
    return true;
}


// 0x0014d140 FUN_0014d140 (12 B): matches/0x0014d140.cpp
// sym: ?FUN_0014d140@Obj_14d140@owners@@QAEDH@Z
char owners::Obj_14d140::FUN_0014d140(int x) {
    value = x;
    return 1;
}


// 0x0014d160 FUN_0014d160 (12 B): matches/0x0014d160.cpp
// sym: ?FUN_0014d160@T_14d160@owners@@QAEEE@Z
unsigned char owners::T_14d160::FUN_0014d160(unsigned char v) {
    value = v;
    return 1;
}


// 0x0014d180 FUN_0014d180 (18 B): matches/0x0014d180.cpp
// sym: ?FUN_0014d180@C_14d180@owners@@QAEDM@Z
char owners::C_14d180::FUN_0014d180(float x) {
    mAngle = x * kU.f;
    return 1;
}


// 0x0014d1b0 FUN_0014d1b0 (18 B): matches/0x0014d1b0.cpp
// sym: ?FUN_0014d1b0@C_14d1b0@owners@@QAE_NM@Z
bool owners::C_14d1b0::FUN_0014d1b0(float deg) {
    m_rad = deg * 0.01745329252f;
    return true;
}


// 0x0014d1e0 FUN_0014d1e0 (12 B): matches/0x0014d1e0.cpp
// sym: ?FUN_0014d1e0@C_14d1e0@owners@@QAE_NH@Z
bool owners::C_14d1e0::FUN_0014d1e0(int v) {
    m28 = v;
    return true;
}


// 0x0014d200 FUN_0014d200 (12 B): matches/0x0014d200.cpp
// sym: ?FUN_0014d200@Obj_14d200@owners@@QAEDH@Z
char owners::Obj_14d200::FUN_0014d200(int n) {
    m2c = n;
    return 1;
}


// 0x0014d220 FUN_0014d220 (12 B): matches/0x0014d220.cpp
// sym: ?FUN_0014d220@Obj_14d220@owners@@QAE_NH@Z
bool owners::Obj_14d220::FUN_0014d220(int a) {
    m30 = a;
    return true;
}


// 0x0014d230 FUN_0014d230 (12 B): matches/0x0014d230.cpp
// sym: ?FUN_0014d230@A_14d230@owners@@QAEDH@Z
char owners::A_14d230::FUN_0014d230(int value) {
    mField = value;
    return 1;
}


// 0x0014d240 FUN_0014d240 (12 B): matches/0x0014d240.cpp
// sym: ?FUN_0014d240@C_14d240@owners@@QAEDH@Z
char owners::C_14d240::FUN_0014d240(int a) {
    *(int*)((char*)this + 0x10) = a;
    return 1;
}

namespace fn_f2fc69c6 {

// 0x0014d250 FUN_0014d250 (19 B): matches/0x0014d250.cpp
// sym: ?FUN_0014d250@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d250() {
    FUN_00234810(((char*)&DAT_004e1028), ((char*)&DAT_004e102c));
}

} // namespace fn_f2fc69c6

// 0x0014d270 hulkfight::motion::InterruptAccumulatorCondition::vfunc_0 (16 B): matches/0x0014d270.cpp
// sym: ?vfunc_0@InterruptAccumulatorCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::InterruptAccumulatorCondition::vfunc_0(int index) {
    int* p = gTable_14d270;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d2c0 FUN_0014d2c0 (19 B): matches/0x0014d2c0.cpp
// sym: ?FUN_0014d2c0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d2c0() {
    FUN_00234810(((char*)&DAT_004e1030), ((char*)&DAT_004e1034));
}

} // namespace fn_f2fc69c6

// 0x0014d2e0 hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_0 (16 B): matches/0x0014d2e0.cpp
// sym: ?vfunc_0@CollisionSourceForceMagnitudeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_0(int index) {
    int* p = gTable_14d2e0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d330 FUN_0014d330 (19 B): matches/0x0014d330.cpp
// sym: ?FUN_0014d330@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d330() {
    FUN_00234810(((char*)&DAT_004e1038), ((char*)&DAT_004e103c));
}

} // namespace fn_f2fc69c6

// 0x0014d350 hulkfight::motion::CollisionThrowCondition::vfunc_0 (16 B): matches/0x0014d350.cpp
// sym: ?vfunc_0@CollisionThrowCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionThrowCondition::vfunc_0(int index) {
    int* p = gTable_14d350;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d390 FUN_0014d390 (19 B): matches/0x0014d390.cpp
// sym: ?FUN_0014d390@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d390() {
    FUN_00234810(((char*)&DAT_004e1040), ((char*)&DAT_004e1044));
}

} // namespace fn_f2fc69c6

// 0x0014d3b0 hulkfight::motion::CollisionSourceSizeCondition::vfunc_0 (16 B): matches/0x0014d3b0.cpp
// sym: ?vfunc_0@CollisionSourceSizeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceSizeCondition::vfunc_0(int index) {
    int* p = gTable_14d3b0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d400 FUN_0014d400 (19 B): matches/0x0014d400.cpp
// sym: ?FUN_0014d400@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d400() {
    FUN_00234810(((char*)&DAT_004e1048), ((char*)&DAT_004e104c));
}

} // namespace fn_f2fc69c6

// 0x0014d420 hulkfight::motion::CollisionSourceTypeCondition::vfunc_0 (16 B): matches/0x0014d420.cpp
// sym: ?vfunc_0@CollisionSourceTypeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceTypeCondition::vfunc_0(int index) {
    int* p = gTable_14d420;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d470 FUN_0014d470 (19 B): matches/0x0014d470.cpp
// sym: ?FUN_0014d470@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d470() {
    FUN_00234810(((char*)&DAT_004e1050), ((char*)&DAT_004e1054));
}

} // namespace fn_f2fc69c6

// 0x0014d490 hulkfight::motion::CollisionTargetPriorityCondition::vfunc_0 (16 B): matches/0x0014d490.cpp
// sym: ?vfunc_0@CollisionTargetPriorityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionTargetPriorityCondition::vfunc_0(int index) {
    int* p = gTable_14d490;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d4e0 FUN_0014d4e0 (19 B): matches/0x0014d4e0.cpp
// sym: ?FUN_0014d4e0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d4e0() {
    FUN_00234810(((char*)&DAT_004e1058), ((char*)&DAT_004e105c));
}

} // namespace fn_f2fc69c6

// 0x0014d500 hulkfight::motion::CollisionDevastatorCondition::vfunc_0 (16 B): matches/0x0014d500.cpp
// sym: ?vfunc_0@CollisionDevastatorCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionDevastatorCondition::vfunc_0(int index) {
    int* p = gTable_14d500;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d540 FUN_0014d540 (19 B): matches/0x0014d540.cpp
// sym: ?FUN_0014d540@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d540() {
    FUN_00234810(((char*)&DAT_004e1060), ((char*)&DAT_004e1064));
}

} // namespace fn_f2fc69c6

// 0x0014d560 hulkfight::motion::HitPushbackCondition::vfunc_0 (16 B): matches/0x0014d560.cpp
// sym: ?vfunc_0@HitPushbackCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPushbackCondition::vfunc_0(int index) {
    int* p = gTable_14d560;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d5a0 FUN_0014d5a0 (19 B): matches/0x0014d5a0.cpp
// sym: ?FUN_0014d5a0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d5a0() {
    FUN_00234810(((char*)&DAT_004e1068), ((char*)&DAT_004e106c));
}

} // namespace fn_f2fc69c6

// 0x0014d5c0 hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_0 (16 B): matches/0x0014d5c0.cpp
// sym: ?vfunc_0@CollisionTargetIsTargetCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionTargetIsTargetCondition::vfunc_0(int index) {
    int* p = gTable_14d5c0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d600 FUN_0014d600 (19 B): matches/0x0014d600.cpp
// sym: ?FUN_0014d600@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d600() {
    FUN_00234810(((char*)&DAT_004e1070), ((char*)&DAT_004e1074));
}

} // namespace fn_f2fc69c6

// 0x0014d620 hulkfight::motion::CollisionTargetSizeCondition::vfunc_0 (16 B): matches/0x0014d620.cpp
// sym: ?vfunc_0@CollisionTargetSizeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionTargetSizeCondition::vfunc_0(int index) {
    int* p = gTable_14d620;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d670 FUN_0014d670 (19 B): matches/0x0014d670.cpp
// sym: ?FUN_0014d670@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d670() {
    FUN_00234810(((char*)&DAT_004e1078), ((char*)&DAT_004e107c));
}

} // namespace fn_f2fc69c6

// 0x0014d690 hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_0 (16 B): matches/0x0014d690.cpp
// sym: ?vfunc_0@CollisionSourceIsMissileCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceIsMissileCondition::vfunc_0(int index) {
    int* p = gTable_14d690;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d6d0 FUN_0014d6d0 (19 B): matches/0x0014d6d0.cpp
// sym: ?FUN_0014d6d0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d6d0() {
    FUN_00234810(((char*)&DAT_004e1080), ((char*)&DAT_004e1084));
}

} // namespace fn_f2fc69c6

// 0x0014d6f0 hulkfight::motion::HitPushbackVelocityCondition::vfunc_0 (16 B): matches/0x0014d6f0.cpp
// sym: ?vfunc_0@HitPushbackVelocityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::HitPushbackVelocityCondition::vfunc_0(int index) {
    int* p = gTable_14d6f0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d740 FUN_0014d740 (19 B): matches/0x0014d740.cpp
// sym: ?FUN_0014d740@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d740() {
    FUN_00234810(((char*)&DAT_004e1088), ((char*)&DAT_004e108c));
}

} // namespace fn_f2fc69c6

// 0x0014d760 hulkfight::motion::CollisionThrownObjectCondition::vfunc_0 (16 B): matches/0x0014d760.cpp
// sym: ?vfunc_0@CollisionThrownObjectCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionThrownObjectCondition::vfunc_0(int index) {
    int* p = gTable_14d760;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d790 FUN_0014d790 (25 B): matches/0x0014d790.cpp
// sym: ??1CollisionThrownObjectCondition_14d790@fn_f2fc69c6@@QAE@XZ
CollisionThrownObjectCondition_14d790::~CollisionThrownObjectCondition_14d790() {
    vptr = g_vftable_14d790;
    s.Init();
    Fin();
}


// 0x0014d7b0 FUN_0014d7b0 (19 B): matches/0x0014d7b0.cpp
// sym: ?FUN_0014d7b0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d7b0() {
    FUN_00234810(((char*)&DAT_004e1090), ((char*)&DAT_004e1094));
}

} // namespace fn_f2fc69c6

// 0x0014d7d0 hulkfight::motion::CollisionExplosionCondition::vfunc_0 (16 B): matches/0x0014d7d0.cpp
// sym: ?vfunc_0@CollisionExplosionCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionExplosionCondition::vfunc_0(int index) {
    int* p = gTable_14d7d0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d810 FUN_0014d810 (19 B): matches/0x0014d810.cpp
// sym: ?FUN_0014d810@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d810() {
    FUN_00234810(((char*)&DAT_004e1098), ((char*)&DAT_004e109c));
}

} // namespace fn_f2fc69c6

// 0x0014d830 hulkfight::motion::CollisionSourceNodeCondition::vfunc_0 (16 B): matches/0x0014d830.cpp
// sym: ?vfunc_0@CollisionSourceNodeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceNodeCondition::vfunc_0(int index) {
    int* p = gTable_14d830;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d870 FUN_0014d870 (25 B): matches/0x0014d870.cpp
// sym: ??1CollisionSourceNodeCondition_14d870@fn_f2fc69c6@@QAE@XZ
CollisionSourceNodeCondition_14d870::~CollisionSourceNodeCondition_14d870() throw() {
    vptr = g_vt_14d870;
    sub.Fin();
}


// 0x0014d890 FUN_0014d890 (19 B): matches/0x0014d890.cpp
// sym: ?FUN_0014d890@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d890() {
    FUN_00234810(((char*)&DAT_004e10a0), ((char*)&DAT_004e10a4));
}

} // namespace fn_f2fc69c6

// 0x0014d8b0 hulkfight::motion::CollisionChargeCondition::vfunc_0 (16 B): matches/0x0014d8b0.cpp
// sym: ?vfunc_0@CollisionChargeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionChargeCondition::vfunc_0(int index) {
    int* p = gTable_14d8b0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d900 FUN_0014d900 (19 B): matches/0x0014d900.cpp
// sym: ?FUN_0014d900@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d900() {
    FUN_00234810(((char*)&DAT_004e10a8), ((char*)&DAT_004e10ac));
}

} // namespace fn_f2fc69c6

// 0x0014d920 hulkfight::motion::CollisionTargetNameCondition::vfunc_0 (16 B): matches/0x0014d920.cpp
// sym: ?vfunc_0@CollisionTargetNameCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionTargetNameCondition::vfunc_0(int index) {
    int* p = gTable_14d920;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d960 FUN_0014d960 (25 B): matches/0x0014d960.cpp
// sym: ??1CollisionTargetNameCondition_14d960@fn_f2fc69c6@@QAE@XZ
CollisionTargetNameCondition_14d960::~CollisionTargetNameCondition_14d960() {
    vptr = g_vftable_14d960;
    s.Init();
    Fin();
}


// 0x0014d980 FUN_0014d980 (19 B): matches/0x0014d980.cpp
// sym: ?FUN_0014d980@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d980() {
    FUN_00234810(((char*)&DAT_004e10b0), ((char*)&DAT_004e10b4));
}

} // namespace fn_f2fc69c6

// 0x0014d9a0 hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_0 (16 B): matches/0x0014d9a0.cpp
// sym: ?vfunc_0@CollisionDamageHealthCompareCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionDamageHealthCompareCondition::vfunc_0(int index) {
    int* p = gTable_14d9a0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014d9f0 FUN_0014d9f0 (19 B): matches/0x0014d9f0.cpp
// sym: ?FUN_0014d9f0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014d9f0() {
    FUN_00234810(((char*)&DAT_004e10b8), ((char*)&DAT_004e10bc));
}

} // namespace fn_f2fc69c6

// 0x0014da10 hulkfight::motion::CollisionTargetTypeCondition::vfunc_0 (16 B): matches/0x0014da10.cpp
// sym: ?vfunc_0@CollisionTargetTypeCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionTargetTypeCondition::vfunc_0(int index) {
    int* p = gTable_14da10;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014da60 FUN_0014da60 (19 B): matches/0x0014da60.cpp
// sym: ?FUN_0014da60@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014da60() {
    FUN_00234810(((char*)&DAT_004e10c0), ((char*)&DAT_004e10c4));
}

} // namespace fn_f2fc69c6

// 0x0014da80 hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_0 (16 B): matches/0x0014da80.cpp
// sym: ?vfunc_0@CollisionInterruptPriorityCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionInterruptPriorityCondition::vfunc_0(int index) {
    int* p = gTable_14da80;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014dac0 FUN_0014dac0 (19 B): matches/0x0014dac0.cpp
// sym: ?FUN_0014dac0@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014dac0() {
    FUN_00234810(((char*)&DAT_004e10c8), ((char*)&DAT_004e10cc));
}

} // namespace fn_f2fc69c6

// 0x0014dae0 hulkfight::motion::CollisionSourceNameCondition::vfunc_0 (16 B): matches/0x0014dae0.cpp
// sym: ?vfunc_0@CollisionSourceNameCondition@motion@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::motion::CollisionSourceNameCondition::vfunc_0(int index) {
    int* p = gTable_14dae0;
    return p[index];
}

namespace fn_f2fc69c6 {

// 0x0014db20 FUN_0014db20 (25 B): matches/0x0014db20.cpp
// sym: ?f@CollisionSourceNameCondition_14db20@fn_f2fc69c6@@QAEXXZ
void CollisionSourceNameCondition_14db20::f() {
    vptr = g_vftable_14db20;
    sub.Fin();
    Fin();
}


// 0x0014db40 FUN_0014db40 (19 B): matches/0x0014db40.cpp
// sym: ?FUN_0014db40@fn_f2fc69c6@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0014db40() {
    FUN_00234810(((char*)&DAT_004e10d0), ((char*)&DAT_004e10d4));
}

} // namespace fn_f2fc69c6
