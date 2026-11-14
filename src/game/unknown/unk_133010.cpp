// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00133010..0x00133980 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f90de225 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f90de225 {} using namespace fn_f90de225;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f90de225 {
class A_1330b0 {
  public:
    char pad[0xc];
    int mValue;
    bool SetTimeBegin_001330b0(int v);
};
class Obj_1330c0 {
  public:
    char pad[0x10];
    int mVal;
    char SetTimeEnd_001330c0(int v);
};
class Obj_1330e0 {
  public:
    char pad[0x14];
    int m14;
    char SetGroundFixup_001330e0(int x);
};
class Base_133160 {
  public:
    virtual void B0();
    char pad[0x18];
    Base_133160() {}
};
class Obj_133160 : public Base_133160 {
  public:
    int m1c;
    Obj_133160(int x) { m1c = x; }
    char Set(int x);
};
class Obj_133470 {
  public:
    char pad[0xc];
    int mValue;
    char Set(int value);
};
class X_133480 {
  public:
    bool Set(int v);

  private:
    char pad[0x10];
    int m;
};
class Obj_1334a0 {
  public:
    char pad[20];
    int m14;
    char Set(int v);
};
extern const float k_1334e0 = 0.017453292f;
class Obj_133550 {
  public:
    char pad[0x20];
    float mValue;
    float Get();
};
struct Vec_1335b0 {
    int x, y, z;
};
class Obj_1335b0 {
  public:
    char pad[0x28];
    int a, b, c;
    char Set(Vec_1335b0* v);
};
class A_133600 {
  public:
    virtual void V();
    char Set(void* p);
    char pad[0x34];
    void* m38;
};
class X_133670 {
  public:
    char pad[0x48];
    float m48;
    float Get();
};
struct Src_133830 {
    int a;
    int b;
    int c;
};
class T_133830 {
  public:
    char pad[0x14];
    int m14;
    int m18;
    int m1c;
    bool Set(const Src_133830* p);
};
extern const float k_1338c0 = 0.017453292f;

} // namespace fn_f90de225

// 0x00133010 FUN_00133010 (12 B): matches/0x00133010.cpp
// sym: ?FUN_00133010@Obj_133010@owners@@QAEDH@Z
char owners::Obj_133010::FUN_00133010(int v) {
    mValue = v;
    return 1;
}


// 0x00133020 FUN_00133020 (12 B): matches/0x00133020.cpp
// sym: ?FUN_00133020@Obj_133020@owners@@QAEDH@Z
char owners::Obj_133020::FUN_00133020(int v) {
    value = v;
    return 1;
}


// 0x00133040 FUN_00133040 (12 B): matches/0x00133040.cpp
// sym: ?FUN_00133040@Obj_133040@owners@@QAE_NH@Z
bool owners::Obj_133040::FUN_00133040(int v) {
    mValue = v;
    return true;
}


// 0x00133060 FUN_00133060 (12 B): matches/0x00133060.cpp
// sym: ?FUN_00133060@Obj_133060@owners@@QAE_NH@Z
bool owners::Obj_133060::FUN_00133060(int v) {
    value = v;
    return true;
}


// 0x00133080 FUN_00133080 (12 B): matches/0x00133080.cpp
// sym: ?FUN_00133080@X_133080@owners@@QAEEH@Z
unsigned char owners::X_133080::FUN_00133080(int value) {
    m1c = value;
    return 1;
}


// 0x001330a0 FUN_001330a0 (12 B): matches/0x001330a0.cpp
// sym: ?FUN_001330a0@X_1330a0@owners@@QAEDH@Z
char owners::X_1330a0::FUN_001330a0(int p) {
    mVal = p;
    return 1;
}

namespace fn_f90de225 {

// 0x001330b0 FUN_001330b0 (12 B): matches/0x001330b0.cpp
// sym: ?SetTimeBegin_001330b0@A_1330b0@fn_f90de225@@QAE_NH@Z
bool A_1330b0::SetTimeBegin_001330b0(int v) {
    mValue = v;
    return true;
}


// 0x001330c0 FUN_001330c0 (12 B): matches/0x001330c0.cpp
// sym: ?SetTimeEnd_001330c0@Obj_1330c0@fn_f90de225@@QAEDH@Z
char Obj_1330c0::SetTimeEnd_001330c0(int v) {
    mVal = v;
    return 1;
}


// 0x001330e0 FUN_001330e0 (12 B): matches/0x001330e0.cpp
// sym: ?SetGroundFixup_001330e0@Obj_1330e0@fn_f90de225@@QAEDH@Z
char Obj_1330e0::SetGroundFixup_001330e0(int x) {
    m14 = x;
    return 1;
}

} // namespace fn_f90de225

// 0x001330f0 FUN_001330f0 (12 B): matches/0x001330f0.cpp
// sym: ?FUN_001330f0@Obj_1330f0@owners@@QAEDH@Z
char owners::Obj_1330f0::FUN_001330f0(int x) {
    mValue = x;
    return 1;
}


// 0x00133100 FUN_00133100 (12 B): matches/0x00133100.cpp
// sym: ?FUN_00133100@Obj_133100@owners@@QAE_NH@Z
bool owners::Obj_133100::FUN_00133100(int v) {
    mValue = v;
    return true;
}


// 0x00133120 FUN_00133120 (12 B): matches/0x00133120.cpp
// sym: ?FUN_00133120@Obj_133120@owners@@QAEDH@Z
char owners::Obj_133120::FUN_00133120(int v) {
    m14 = v;
    return 1;
}


// 0x00133140 FUN_00133140 (12 B): matches/0x00133140.cpp
// sym: ?FUN_00133140@C_133140@owners@@QAEDH@Z
char owners::C_133140::FUN_00133140(int x) {
    *(int*)((char*)this + 0x18) = x;
    return 1;
}

namespace fn_f90de225 {

// 0x00133160 FUN_00133160 (12 B): matches/0x00133160.cpp
// sym: ?Set@Obj_133160@fn_f90de225@@QAEDH@Z
char Obj_133160::Set(int x) {
    m1c = x;
    return 1;
}

} // namespace fn_f90de225

// 0x00133180 FUN_00133180 (12 B): matches/0x00133180.cpp
// sym: ?FUN_00133180@Obj_133180@owners@@QAEDH@Z
char owners::Obj_133180::FUN_00133180(int v) {
    *(int*)((char*)this + 0x20) = v;
    return 1;
}


// 0x001331a0 FUN_001331a0 (12 B): matches/0x001331a0.cpp
// sym: ?FUN_001331a0@Obj_1331a0@owners@@QAE_NH@Z
bool owners::Obj_1331a0::FUN_001331a0(int v) {
    *(int*)((char*)this + 0x24) = v;
    return true;
}


// 0x001331c0 FUN_001331c0 (12 B): matches/0x001331c0.cpp
// sym: ?FUN_001331c0@Obj_1331c0@owners@@QAEDH@Z
char owners::Obj_1331c0::FUN_001331c0(int v) {
    m28 = v;
    return 1;
}


// 0x001331e0 FUN_001331e0 (12 B): matches/0x001331e0.cpp
// sym: ?FUN_001331e0@Obj_1331e0@owners@@QAE_NH@Z
bool owners::Obj_1331e0::FUN_001331e0(int v) {
    mVal = v;
    return true;
}


// 0x001331f0 FUN_001331f0 (12 B): matches/0x001331f0.cpp
// sym: ?FUN_001331f0@Obj_1331f0@owners@@QAEDH@Z
char owners::Obj_1331f0::FUN_001331f0(int value) {
    mField = value;
    return 1;
}


// 0x00133200 FUN_00133200 (12 B): matches/0x00133200.cpp
// sym: ?FUN_00133200@Obj_133200@owners@@QAEDH@Z
char owners::Obj_133200::FUN_00133200(int v) {
    Value = v;
    return 1;
}


// 0x00133220 FUN_00133220 (12 B): matches/0x00133220.cpp
// sym: ?FUN_00133220@Obj_133220@owners@@QAE_NH@Z
bool owners::Obj_133220::FUN_00133220(int x) {
    value = x;
    return true;
}


// 0x00133240 FUN_00133240 (12 B): matches/0x00133240.cpp
// sym: ?FUN_00133240@Obj_133240@owners@@QAE_NH@Z
bool owners::Obj_133240::FUN_00133240(int x) {
    value = x;
    return true;
}


// 0x00133260 FUN_00133260 (12 B): matches/0x00133260.cpp
// sym: ?FUN_00133260@X_133260@owners@@QAEDH@Z
char owners::X_133260::FUN_00133260(int value) {
    mValue = value;
    return 1;
}


// 0x00133280 FUN_00133280 (12 B): matches/0x00133280.cpp
// sym: ?FUN_00133280@Obj_133280@owners@@QAE_NH@Z
bool owners::Obj_133280::FUN_00133280(int x) {
    mVal = x;
    return true;
}


// 0x001332a0 FUN_001332a0 (18 B): matches/0x001332a0.cpp
// sym: ?FUN_001332a0@Thing_1332a0@owners@@QAEDM@Z
char owners::Thing_1332a0::FUN_001332a0(float a) {
    mAngle = a * 0.017453292519943295f;
    return 1;
}


// 0x001332d0 FUN_001332d0 (12 B): matches/0x001332d0.cpp
// sym: ?FUN_001332d0@Obj_1332d0@owners@@QAEDH@Z
char owners::Obj_1332d0::FUN_001332d0(int v) {
    mVal = v;
    return 1;
}


// 0x001332f0 FUN_001332f0 (12 B): matches/0x001332f0.cpp
// sym: ?FUN_001332f0@Obj_1332f0@owners@@QAE_NH@Z
bool owners::Obj_1332f0::FUN_001332f0(int v) {
    value = v;
    return true;
}


// 0x00133310 FUN_00133310 (12 B): matches/0x00133310.cpp
// sym: ?FUN_00133310@X_133310@owners@@QAEDH@Z
char owners::X_133310::FUN_00133310(int v) {
    m30 = v;
    return 1;
}


// 0x00133320 FUN_00133320 (12 B): matches/0x00133320.cpp
// sym: ?FUN_00133320@Obj_133320@owners@@QAEDH@Z
char owners::Obj_133320::FUN_00133320(int v) {
    value = v;
    return true;
}


// 0x00133330 FUN_00133330 (12 B): matches/0x00133330.cpp
// sym: ?FUN_00133330@Obj_133330@owners@@QAEDH@Z
char owners::Obj_133330::FUN_00133330(int v) {
    m = v;
    return 1;
}


// 0x00133350 FUN_00133350 (12 B): matches/0x00133350.cpp
// sym: ?FUN_00133350@X_133350@owners@@QAEEH@Z
unsigned char owners::X_133350::FUN_00133350(int x) {
    m14 = x;
    return 1;
}


// 0x00133370 FUN_00133370 (12 B): matches/0x00133370.cpp
// sym: ?FUN_00133370@Obj_133370@owners@@QAE_NH@Z
bool owners::Obj_133370::FUN_00133370(int x) {
    value = x;
    return true;
}


// 0x00133390 FUN_00133390 (12 B): matches/0x00133390.cpp
// sym: ?FUN_00133390@Obj_133390@owners@@QAEEH@Z
unsigned char owners::Obj_133390::FUN_00133390(int x) {
    value = x;
    return 1;
}


// 0x001333b0 FUN_001333b0 (12 B): matches/0x001333b0.cpp
// sym: ?FUN_001333b0@Obj_1333b0@owners@@QAE_NH@Z
bool owners::Obj_1333b0::FUN_001333b0(int x) {
    mValue = x;
    return true;
}


// 0x001333d0 FUN_001333d0 (18 B): matches/0x001333d0.cpp
// sym: ?FUN_001333d0@Obj_1333d0@owners@@QAE_NM@Z
bool owners::Obj_1333d0::FUN_001333d0(float x) {
    angle = x * 0.017453292f;
    return true;
}


// 0x00133400 FUN_00133400 (12 B): matches/0x00133400.cpp
// sym: ?FUN_00133400@X_133400@owners@@QAE_NH@Z
bool owners::X_133400::FUN_00133400(int v) {
    m = v;
    return true;
}


// 0x00133420 FUN_00133420 (12 B): matches/0x00133420.cpp
// sym: ?FUN_00133420@Obj_133420@owners@@QAE_NH@Z
bool owners::Obj_133420::FUN_00133420(int x) {
    mFlag = x;
    return true;
}


// 0x00133440 FUN_00133440 (12 B): matches/0x00133440.cpp
// sym: ?FUN_00133440@Obj_133440@owners@@QAEDH@Z
char owners::Obj_133440::FUN_00133440(int v) {
    m30 = v;
    return 1;
}


// 0x00133460 FUN_00133460 (12 B): matches/0x00133460.cpp
// sym: ?FUN_00133460@Obj_133460@owners@@QAE_NH@Z
bool owners::Obj_133460::FUN_00133460(int x) {
    value = x;
    return true;
}

namespace fn_f90de225 {

// 0x00133470 FUN_00133470 (12 B): matches/0x00133470.cpp
// sym: ?Set@Obj_133470@fn_f90de225@@QAEDH@Z
char Obj_133470::Set(int value) {
    mValue = value;
    return 1;
}


// 0x00133480 FUN_00133480 (12 B): matches/0x00133480.cpp
// sym: ?Set@X_133480@fn_f90de225@@QAE_NH@Z
bool X_133480::Set(int v) {
    m = v;
    return true;
}


// 0x001334a0 FUN_001334a0 (12 B): matches/0x001334a0.cpp
// sym: ?Set@Obj_1334a0@fn_f90de225@@QAEDH@Z
char Obj_1334a0::Set(int v) {
    m14 = v;
    return 1;
}

} // namespace fn_f90de225

// 0x001334b0 FUN_001334b0 (12 B): matches/0x001334b0.cpp
// sym: ?FUN_001334b0@Obj_1334b0@owners@@QAE_NH@Z
bool owners::Obj_1334b0::FUN_001334b0(int value) {
    mValue = value;
    return true;
}


// 0x001334c0 FUN_001334c0 (12 B): matches/0x001334c0.cpp
// sym: ?FUN_001334c0@Obj_1334c0@owners@@QAEDH@Z
char owners::Obj_1334c0::FUN_001334c0(int a) {
    value = a;
    return 1;
}


// 0x001334e0 FUN_001334e0 (18 B): matches/0x001334e0.cpp
// sym: ?FUN_001334e0@Obj_1334e0@owners@@QAEDM@Z
char owners::Obj_1334e0::FUN_001334e0(float x) {
    *(float*)((char*)this + 0x14) = x * k_1334e0;
    return 1;
}


// 0x00133510 FUN_00133510 (12 B): matches/0x00133510.cpp
// sym: ?FUN_00133510@Obj_133510@owners@@QAEDH@Z
char owners::Obj_133510::FUN_00133510(int v) {
    m18 = v;
    return 1;
}


// 0x00133530 FUN_00133530 (18 B): matches/0x00133530.cpp
// sym: ?FUN_00133530@Obj_133530@owners@@QAEDM@Z
char owners::Obj_133530::FUN_00133530(float x) {
    f = x * 0.017453292519943295f;
    return 1;
}

namespace fn_f90de225 {

// 0x00133550 FUN_00133550 (4 B): matches/0x00133550.cpp
// sym: ?Get@Obj_133550@fn_f90de225@@QAEMXZ
float Obj_133550::Get() {
    return mValue;
}

} // namespace fn_f90de225

// 0x00133560 FUN_00133560 (12 B): matches/0x00133560.cpp
// sym: ?FUN_00133560@Obj_133560@owners@@QAEDH@Z
char owners::Obj_133560::FUN_00133560(int v) {
    m20 = v;
    return 1;
}


// 0x00133580 FUN_00133580 (12 B): matches/0x00133580.cpp
// sym: ?FUN_00133580@Obj_133580@owners@@QAEDE@Z
char owners::Obj_133580::FUN_00133580(unsigned char v) {
    m24 = v;
    return 1;
}

namespace fn_f90de225 {

// 0x001335b0 FUN_001335b0 (26 B): matches/0x001335b0.cpp
// sym: ?Set@Obj_1335b0@fn_f90de225@@QAEDPAUVec_1335b0@2@@Z
char Obj_1335b0::Set(Vec_1335b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}

} // namespace fn_f90de225

// 0x001335e0 FUN_001335e0 (12 B): matches/0x001335e0.cpp
// sym: ?FUN_001335e0@Obj_1335e0@owners@@QAEDH@Z
char owners::Obj_1335e0::FUN_001335e0(int value) {
    m34 = value;
    return 1;
}

namespace fn_f90de225 {

// 0x00133600 FUN_00133600 (12 B): matches/0x00133600.cpp
// sym: ?Set@A_133600@fn_f90de225@@QAEDPAX@Z
char A_133600::Set(void* p) {
    m38 = p;
    return 1;
}

} // namespace fn_f90de225

// 0x00133620 FUN_00133620 (12 B): matches/0x00133620.cpp
// sym: ?FUN_00133620@T_133620@owners@@QAEDD@Z
char owners::T_133620::FUN_00133620(char c) {
    m3c = c;
    return 1;
}


// 0x00133640 FUN_00133640 (12 B): matches/0x00133640.cpp
// sym: ?FUN_00133640@Obj_133640@owners@@QAE_NH@Z
bool owners::Obj_133640::FUN_00133640(int v) {
    mValue = v;
    return true;
}


// 0x00133660 FUN_00133660 (12 B): matches/0x00133660.cpp
// sym: ?FUN_00133660@Obj_133660@owners@@QAEDH@Z
char owners::Obj_133660::FUN_00133660(int a) {
    *(int*)((char*)this + 0x44) = a;
    return 1;
}

namespace fn_f90de225 {

// 0x00133670 FUN_00133670 (4 B): matches/0x00133670.cpp
// sym: ?Get@X_133670@fn_f90de225@@QAEMXZ
float X_133670::Get() {
    return m48;
}

} // namespace fn_f90de225

// 0x00133680 FUN_00133680 (12 B): matches/0x00133680.cpp
// sym: ?FUN_00133680@O_133680@owners@@QAE_NH@Z
bool owners::O_133680::FUN_00133680(int x) {
    m = x;
    return true;
}


// 0x00133690 FUN_00133690 (12 B): matches/0x00133690.cpp
// sym: ?FUN_00133690@X_133690@owners@@QAE_NPAX@Z
bool owners::X_133690::FUN_00133690(void* p) {
    m1c = p;
    return true;
}


// 0x001336a0 FUN_001336a0 (12 B): matches/0x001336a0.cpp
// sym: ?FUN_001336a0@O_1336a0@owners@@QAE_NH@Z
bool owners::O_1336a0::FUN_001336a0(int a) {
    mField = a;
    return true;
}


// 0x001336c0 FUN_001336c0 (18 B): matches/0x001336c0.cpp
// sym: ?FUN_001336c0@Obj_1336c0@owners@@QAE_NM@Z
bool owners::Obj_1336c0::FUN_001336c0(float v) {
    mAngle = v * 0.017453292f;
    return true;
}


// 0x00133700 FUN_00133700 (26 B): matches/0x00133700.cpp
// sym: ?FUN_00133700@Obj_133700@owners@@QAE_NPAH@Z
bool owners::Obj_133700::FUN_00133700(int* x) {
    a = x[0];
    b = x[1];
    c = x[2];
    return true;
}


// 0x00133730 FUN_00133730 (12 B): matches/0x00133730.cpp
// sym: ?FUN_00133730@X_133730@owners@@QAEDH@Z
char owners::X_133730::FUN_00133730(int a) {
    m24 = a;
    return 1;
}


// 0x00133750 FUN_00133750 (18 B): matches/0x00133750.cpp
// sym: ?FUN_00133750@Obj_133750@owners@@QAEDM@Z
char owners::Obj_133750::FUN_00133750(float a) {
    angle = a * 0.0174532925f;
    return 1;
}


// 0x00133780 FUN_00133780 (12 B): matches/0x00133780.cpp
// sym: ?FUN_00133780@X_133780@owners@@QAE_NH@Z
bool owners::X_133780::FUN_00133780(int v) {
    mVal = v;
    return true;
}


// 0x001337a0 FUN_001337a0 (12 B): matches/0x001337a0.cpp
// sym: ?FUN_001337a0@C_1337a0@owners@@QAEDH@Z
char owners::C_1337a0::FUN_001337a0(int x) {
    *((int*)((char*)this + 0x30)) = x;
    return 1;
}


// 0x001337c0 FUN_001337c0 (12 B): matches/0x001337c0.cpp
// sym: ?FUN_001337c0@Obj_1337c0@owners@@QAE_NH@Z
bool owners::Obj_1337c0::FUN_001337c0(int x) {
    m34 = x;
    return true;
}


// 0x001337e0 FUN_001337e0 (12 B): matches/0x001337e0.cpp
// sym: ?FUN_001337e0@Obj_1337e0@owners@@QAEDH@Z
char owners::Obj_1337e0::FUN_001337e0(int x) {
    m38 = x;
    return 1;
}


// 0x001337f0 FUN_001337f0 (12 B): matches/0x001337f0.cpp
// sym: ?FUN_001337f0@Obj_1337f0@owners@@QAE_NH@Z
bool owners::Obj_1337f0::FUN_001337f0(int v) {
    mVal = v;
    return true;
}


// 0x00133800 FUN_00133800 (12 B): matches/0x00133800.cpp
// sym: ?FUN_00133800@X_133800@owners@@QAEDH@Z
char owners::X_133800::FUN_00133800(int v) {
    mValue = v;
    return 1;
}

namespace fn_f90de225 {

// 0x00133830 FUN_00133830 (26 B): matches/0x00133830.cpp
// sym: ?Set@T_133830@fn_f90de225@@QAE_NPBUSrc_133830@2@@Z
bool T_133830::Set(const Src_133830* p) {
    m14 = p->a;
    m18 = p->b;
    m1c = p->c;
    return true;
}

} // namespace fn_f90de225

// 0x00133860 FUN_00133860 (12 B): matches/0x00133860.cpp
// sym: ?FUN_00133860@Obj_133860@owners@@QAEDH@Z
char owners::Obj_133860::FUN_00133860(int v) {
    Value = v;
    return 1;
}


// 0x00133880 FUN_00133880 (12 B): matches/0x00133880.cpp
// sym: ?FUN_00133880@Obj_133880@owners@@QAEDH@Z
char owners::Obj_133880::FUN_00133880(int x) {
    mValue = x;
    return 1;
}


// 0x001338a0 FUN_001338a0 (12 B): matches/0x001338a0.cpp
// sym: ?FUN_001338a0@Obj_1338a0@owners@@QAEDH@Z
char owners::Obj_1338a0::FUN_001338a0(int x) {
    m28 = x;
    return 1;
}


// 0x001338c0 FUN_001338c0 (18 B): matches/0x001338c0.cpp
// sym: ?FUN_001338c0@O_1338c0@owners@@QAEDM@Z
char owners::O_1338c0::FUN_001338c0(float f) {
    value = f * k_1338c0;
    return 1;
}


// 0x001338f0 FUN_001338f0 (12 B): matches/0x001338f0.cpp
// sym: ?FUN_001338f0@X_1338f0@owners@@QAEED@Z
unsigned char owners::X_1338f0::FUN_001338f0(char b) {
    m30 = b;
    return 1;
}


// 0x00133910 FUN_00133910 (12 B): matches/0x00133910.cpp
// sym: ?FUN_00133910@X_133910@owners@@QAE_NH@Z
bool owners::X_133910::FUN_00133910(int v) {
    m34 = v;
    return true;
}


// 0x00133930 FUN_00133930 (12 B): matches/0x00133930.cpp
// sym: ?FUN_00133930@Obj_133930@owners@@QAEDH@Z
char owners::Obj_133930::FUN_00133930(int a) {
    m38 = a;
    return 1;
}


// 0x00133950 FUN_00133950 (12 B): matches/0x00133950.cpp
// sym: ?FUN_00133950@O_133950@owners@@QAEDH@Z
char owners::O_133950::FUN_00133950(int v) {
    char r = 1;
    int* q = &mVal;
    *q = v;
    return r;
}

namespace fn_f90de225 {

// 0x00133960 FUN_00133960 (19 B): matches/0x00133960.cpp
// sym: ?FUN_00133960@fn_f90de225@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00133960() {
    FUN_00234810(((char*)&DAT_004e0ec0), ((char*)&DAT_004e0ec4));
}

} // namespace fn_f90de225
