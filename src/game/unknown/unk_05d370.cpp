// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005d370..0x0005d850 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f133b0a3 {
#define TREE_TU_END }
namespace fn_f133b0a3 {} using namespace fn_f133b0a3;
#include "game/unknown.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f133b0a3 {
extern "C" void* FUN_0008d690(unsigned int size);
class CHapticTrack_5d370 {
public:
    void FUN_0005d120(float);
    void FUN_0005d130(float);
    void FUN_0005d140(float);
    void FUN_0005d150(float);
    void FUN_0005d160(bool);
};
class __declspec(novtable) ParamFloatBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)(float)) : ParamFloatBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)(float);
    int unused14;
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)(bool)) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)(bool);
    int unused14;
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
struct Vec3_5d4e0 {
    int x, y, z;
};
class Obj_5d4e0 {
  public:
    char pad[0x20];
    Vec3_5d4e0 mVec;
    char Set(const Vec3_5d4e0* v);
};
struct Vec3 {
    float x, y, z;
};
struct Point {
    int x, y, z;
};
class Obj {
  public:
    char _m_pad_0[0xcc];
    Vec3 v;
    char _m_pad_d8[0x8];
    int a;
    int b;
    int c;
    bool Set(Vec3 const* p);
    bool Set(Point* p);
};
struct Src_5d6c0 {
    int a, b, c;
};
class Owner_5d6c0 {
  public:
    char pad[0x20];
    Src_5d6c0 data;
    bool Set(Src_5d6c0* p);
};


// 0x0005d370 FUN_0005d370 (307 B): equivalent/0x0005d370.cpp
// sym: _FUN_0005d370
// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 12/12)
// FUN_0005d370 @ 0x0005d370
extern "C" void FUN_0005d370()
{
    if (DAT_004dc5cc == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("timeBegin", &CHapticTrack_5d370::FUN_0005d120);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("timeEnd", &CHapticTrack_5d370::FUN_0005d130);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("rumbleStrengthBig", &CHapticTrack_5d370::FUN_0005d140);
        mem = FUN_0008d690((int)sizeof(ParamFloatConstRange<CHapticTrack_5d370>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<CHapticTrack_5d370>("rumbleStrengthSmall", &CHapticTrack_5d370::FUN_0005d150);
        mem = FUN_0008d690((int)sizeof(ParamBool<CHapticTrack_5d370>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<CHapticTrack_5d370>("abortWhenInterrupted", &CHapticTrack_5d370::FUN_0005d160);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc5c8), params, 5);
    }
    DAT_004dc5cc++;
}

} // namespace fn_f133b0a3

// 0x0005d4b0 FUN_0005d4b0 (12 B): matches/0x0005d4b0.cpp
// sym: ?FUN_0005d4b0@T_5d4b0@owners@@QAE_NH@Z
bool owners::T_5d4b0::FUN_0005d4b0(int a) {
    m = a;
    return true;
}


// 0x0005d4c0 FUN_0005d4c0 (12 B): matches/0x0005d4c0.cpp
// sym: ?FUN_0005d4c0@X_5d4c0@owners@@QAEDH@Z
char owners::X_5d4c0::FUN_0005d4c0(int x) {
    mValue = x;
    return 1;
}


// 0x0005d4d0 FUN_0005d4d0 (4 B): matches/0x0005d4d0.cpp
// sym: ?FUN_0005d4d0@X_5d4d0@owners@@QAEPADXZ
char* owners::X_5d4d0::FUN_0005d4d0() {
    return (char*)this + 0x18;
}

namespace fn_f133b0a3 {

// 0x0005d4e0 FUN_0005d4e0 (26 B): matches/0x0005d4e0.cpp
// sym: ?Set@Obj_5d4e0@fn_f133b0a3@@QAEDPBUVec3_5d4e0@2@@Z
char Obj_5d4e0::Set(const Vec3_5d4e0* v) {
    mVec.x = v->x;
    mVec.y = v->y;
    mVec.z = v->z;
    return 1;
}

} // namespace fn_f133b0a3

// 0x0005d500 FUN_0005d500 (12 B): matches/0x0005d500.cpp
// sym: ?FUN_0005d500@Obj_5d500@owners@@QAE_NH@Z
bool owners::Obj_5d500::FUN_0005d500(int x) {
    mVal = x;
    return true;
}


// 0x0005d510 FUN_0005d510 (12 B): matches/0x0005d510.cpp
// sym: ?FUN_0005d510@O_5d510@owners@@QAE_NH@Z
bool owners::O_5d510::FUN_0005d510(int v) {
    value = v;
    return true;
}


// 0x0005d520 FUN_0005d520 (12 B): matches/0x0005d520.cpp
// sym: ?FUN_0005d520@X_5d520@owners@@QAE_NH@Z
bool owners::X_5d520::FUN_0005d520(int v) {
    value = v;
    return true;
}


// 0x0005d530 FUN_0005d530 (12 B): matches/0x0005d530.cpp
// sym: ?FUN_0005d530@Obj_5d530@owners@@QAEDD@Z
char owners::Obj_5d530::FUN_0005d530(char c) {
    mState = c;
    return 1;
}


// 0x0005d540 FUN_0005d540 (12 B): matches/0x0005d540.cpp
// sym: ?FUN_0005d540@Obj_5d540@owners@@QAEDD@Z
char owners::Obj_5d540::FUN_0005d540(char c) {
    m39 = c;
    return 1;
}


// 0x0005d550 FUN_0005d550 (12 B): matches/0x0005d550.cpp
// sym: ?FUN_0005d550@Obj_5d550@owners@@QAEDD@Z
char owners::Obj_5d550::FUN_0005d550(char c) {
    mVal = c;
    return 1;
}


// 0x0005d560 FUN_0005d560 (12 B): matches/0x0005d560.cpp
// sym: ?FUN_0005d560@X_5d560@owners@@QAEDD@Z
char owners::X_5d560::FUN_0005d560(char v) {
    m3b = v;
    return 1;
}


// 0x0005d570 FUN_0005d570 (12 B): matches/0x0005d570.cpp
// sym: ?FUN_0005d570@C_5d570@owners@@QAEDD@Z
char owners::C_5d570::FUN_0005d570(char arg) {
    m3c = arg;
    return 1;
}


// 0x0005d580 FUN_0005d580 (12 B): matches/0x0005d580.cpp
// sym: ?FUN_0005d580@C_5d580@owners@@QAE_NH@Z
bool owners::C_5d580::FUN_0005d580(int x) {
    m40 = x;
    return true;
}


// 0x0005d590 FUN_0005d590 (12 B): matches/0x0005d590.cpp
// sym: ?FUN_0005d590@X_5d590@owners@@QAE_NH@Z
bool owners::X_5d590::FUN_0005d590(int v) {
    *((int*)((char*)this + 0x44)) = v;
    return true;
}


// 0x0005d5a0 FUN_0005d5a0 (12 B): matches/0x0005d5a0.cpp
// sym: ?FUN_0005d5a0@C_5d5a0@owners@@QAEDH@Z
char owners::C_5d5a0::FUN_0005d5a0(int v) {
    m = v;
    return 1;
}


// 0x0005d5b0 FUN_0005d5b0 (15 B): matches/0x0005d5b0.cpp
// sym: ?FUN_0005d5b0@Obj_5d5b0@owners@@QAE_NH@Z
bool owners::Obj_5d5b0::FUN_0005d5b0(int value) {
    mValue = value;
    return true;
}


// 0x0005d5c0 FUN_0005d5c0 (15 B): matches/0x0005d5c0.cpp
// sym: ?FUN_0005d5c0@C_5d5c0@owners@@QAE_NH@Z
bool owners::C_5d5c0::FUN_0005d5c0(int x) {
    mValue = x;
    return true;
}


// 0x0005d5d0 FUN_0005d5d0 (35 B): matches/0x0005d5d0.cpp
// sym: ?FUN_0005d5d0@Obj_5d5d0@owners@@QAE_NPAH@Z
bool owners::Obj_5d5d0::FUN_0005d5d0(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    return true;
}

namespace fn_f133b0a3 {

// 0x0005d600 FUN_0005d600 (35 B): matches/0x0005d600.cpp
// sym: ?Set@Obj@fn_f133b0a3@@QAE_NPBUVec3@2@@Z
bool Obj::Set(Vec3 const* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}

} // namespace fn_f133b0a3

// 0x0005d630 FUN_0005d630 (15 B): matches/0x0005d630.cpp
// sym: ?FUN_0005d630@Obj_5d630@owners@@QAEDH@Z
char owners::Obj_5d630::FUN_0005d630(int x) {
    value = x;
    return 1;
}


// 0x0005d640 FUN_0005d640 (15 B): matches/0x0005d640.cpp
// sym: ?FUN_0005d640@O_5d640@owners@@QAE_NH@Z
bool owners::O_5d640::FUN_0005d640(int x) {
    m = x;
    return true;
}

namespace fn_f133b0a3 {

// 0x0005d650 FUN_0005d650 (35 B): matches/0x0005d650.cpp
// sym: ?Set@Obj@fn_f133b0a3@@QAE_NPAUPoint@2@@Z
bool Obj::Set(Point* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return true;
}

} // namespace fn_f133b0a3

// 0x0005d680 FUN_0005d680 (15 B): matches/0x0005d680.cpp
// sym: ?FUN_0005d680@Obj_5d680@owners@@QAEDH@Z
char owners::Obj_5d680::FUN_0005d680(int x) {
    mField = x;
    return 1;
}


// 0x0005d690 FUN_0005d690 (12 B): matches/0x0005d690.cpp
// sym: ?FUN_0005d690@Obj_5d690@owners@@QAE_NH@Z
bool owners::Obj_5d690::FUN_0005d690(int x) {
    mX = x;
    return true;
}


// 0x0005d6a0 FUN_0005d6a0 (12 B): matches/0x0005d6a0.cpp
// sym: ?FUN_0005d6a0@A_5d6a0@owners@@QAEDH@Z
char owners::A_5d6a0::FUN_0005d6a0(int value) {
    mValue = value;
    return 1;
}


// 0x0005d6b0 FUN_0005d6b0 (4 B): matches/0x0005d6b0.cpp
// sym: ?FUN_0005d6b0@Obj_5d6b0@owners@@QAEPAHXZ
int* owners::Obj_5d6b0::FUN_0005d6b0() {
    return (int*)((char*)this + 0x18);
}

namespace fn_f133b0a3 {

// 0x0005d6c0 FUN_0005d6c0 (26 B): matches/0x0005d6c0.cpp
// sym: ?Set@Owner_5d6c0@fn_f133b0a3@@QAE_NPAUSrc_5d6c0@2@@Z
bool Owner_5d6c0::Set(Src_5d6c0* p) {
    data.a = p->a;
    data.b = p->b;
    data.c = p->c;
    return true;
}

} // namespace fn_f133b0a3

// 0x0005d6e0 FUN_0005d6e0 (12 B): matches/0x0005d6e0.cpp
// sym: ?FUN_0005d6e0@C_5d6e0@owners@@QAE_NH@Z
bool owners::C_5d6e0::FUN_0005d6e0(int x) {
    m2c = x;
    return true;
}


// 0x0005d6f0 FUN_0005d6f0 (12 B): matches/0x0005d6f0.cpp
// sym: ?FUN_0005d6f0@A_5d6f0@owners@@QAE_NH@Z
bool owners::A_5d6f0::FUN_0005d6f0(int v) {
    m30 = v;
    return true;
}


// 0x0005d700 FUN_0005d700 (12 B): matches/0x0005d700.cpp
// sym: ?FUN_0005d700@Obj_5d700@owners@@QAE_NH@Z
bool owners::Obj_5d700::FUN_0005d700(int x) {
    m = x;
    return true;
}


// 0x0005d710 FUN_0005d710 (12 B): matches/0x0005d710.cpp
// sym: ?FUN_0005d710@Obj_5d710@owners@@QAE_NH@Z
bool owners::Obj_5d710::FUN_0005d710(int x) {
    value = x;
    return true;
}


// 0x0005d720 FUN_0005d720 (12 B): matches/0x0005d720.cpp
// sym: ?FUN_0005d720@Obj_5d720@owners@@QAEDH@Z
char owners::Obj_5d720::FUN_0005d720(int x) {
    value = x;
    return 1;
}


// 0x0005d730 FUN_0005d730 (12 B): matches/0x0005d730.cpp
// sym: ?FUN_0005d730@Obj_5d730@owners@@QAE_NH@Z
bool owners::Obj_5d730::FUN_0005d730(int v) {
    m20 = v;
    return true;
}


// 0x0005d740 FUN_0005d740 (12 B): matches/0x0005d740.cpp
// sym: ?FUN_0005d740@Obj_5d740@owners@@QAEDH@Z
char owners::Obj_5d740::FUN_0005d740(int x) {
    m24 = x;
    return 1;
}


// 0x0005d750 FUN_0005d750 (12 B): matches/0x0005d750.cpp
// sym: ?FUN_0005d750@A_5d750@owners@@QAEDH@Z
char owners::A_5d750::FUN_0005d750(int v) {
    m28 = v;
    return 1;
}


// 0x0005d760 FUN_0005d760 (12 B): matches/0x0005d760.cpp
// sym: ?FUN_0005d760@Obj_5d760@owners@@QAEDH@Z
char owners::Obj_5d760::FUN_0005d760(int x) {
    Value = x;
    return 1;
}


// 0x0005d770 FUN_0005d770 (12 B): matches/0x0005d770.cpp
// sym: ?FUN_0005d770@T_5d770@owners@@QAEDH@Z
char owners::T_5d770::FUN_0005d770(int a) {
    m = a;
    return 1;
}


// 0x0005d780 FUN_0005d780 (12 B): matches/0x0005d780.cpp
// sym: ?FUN_0005d780@Obj_5d780@owners@@QAEDH@Z
char owners::Obj_5d780::FUN_0005d780(int v) {
    m40 = v;
    return 1;
}


// 0x0005d790 FUN_0005d790 (12 B): matches/0x0005d790.cpp
// sym: ?FUN_0005d790@Obj_5d790@owners@@QAE_NH@Z
bool owners::Obj_5d790::FUN_0005d790(int v) {
    m44 = v;
    return true;
}


// 0x0005d7a0 FUN_0005d7a0 (12 B): matches/0x0005d7a0.cpp
// sym: ?FUN_0005d7a0@Obj_5d7a0@owners@@QAE_NH@Z
bool owners::Obj_5d7a0::FUN_0005d7a0(int v) {
    value = v;
    return true;
}


// 0x0005d7b0 FUN_0005d7b0 (12 B): matches/0x0005d7b0.cpp
// sym: ?FUN_0005d7b0@Thing_5d7b0@owners@@QAEEE@Z
unsigned char owners::Thing_5d7b0::FUN_0005d7b0(unsigned char v) {
    mField[0x4c] = v;
    return 1;
}


// 0x0005d7c0 FUN_0005d7c0 (12 B): matches/0x0005d7c0.cpp
// sym: ?FUN_0005d7c0@X_5d7c0@owners@@QAE_NH@Z
bool owners::X_5d7c0::FUN_0005d7c0(int x) {
    m = x;
    return true;
}


// 0x0005d7d0 FUN_0005d7d0 (12 B): matches/0x0005d7d0.cpp
// sym: ?FUN_0005d7d0@Obj_5d7d0@owners@@QAEDH@Z
char owners::Obj_5d7d0::FUN_0005d7d0(int v) {
    mVal = v;
    return 1;
}


// 0x0005d7e0 FUN_0005d7e0 (12 B): matches/0x0005d7e0.cpp
// sym: ?FUN_0005d7e0@Obj_5d7e0@owners@@QAE_NH@Z
bool owners::Obj_5d7e0::FUN_0005d7e0(int value) {
    m1c = value;
    return true;
}


// 0x0005d7f0 FUN_0005d7f0 (12 B): matches/0x0005d7f0.cpp
// sym: ?FUN_0005d7f0@C_5d7f0@owners@@QAE_NH@Z
bool owners::C_5d7f0::FUN_0005d7f0(int x) {
    mValue = x;
    return true;
}


// 0x0005d800 FUN_0005d800 (12 B): matches/0x0005d800.cpp
// sym: ?FUN_0005d800@Obj_5d800@owners@@QAE_NH@Z
bool owners::Obj_5d800::FUN_0005d800(int x) {
    value = x;
    return true;
}


// 0x0005d810 FUN_0005d810 (12 B): matches/0x0005d810.cpp
// sym: ?FUN_0005d810@Obj_5d810@owners@@QAE_NH@Z
bool owners::Obj_5d810::FUN_0005d810(int v) {
    value = v;
    return true;
}


// 0x0005d820 FUN_0005d820 (12 B): matches/0x0005d820.cpp
// sym: ?FUN_0005d820@Obj_5d820@owners@@QAE_NH@Z
bool owners::Obj_5d820::FUN_0005d820(int value) {
    mField = value;
    return true;
}


// 0x0005d830 FUN_0005d830 (12 B): matches/0x0005d830.cpp
// sym: ?FUN_0005d830@C_5d830@owners@@QAEDH@Z
char owners::C_5d830::FUN_0005d830(int x) {
    value = x;
    return 1;
}


// 0x0005d840 FUN_0005d840 (12 B): matches/0x0005d840.cpp
// sym: ?FUN_0005d840@Obj_5d840@owners@@QAE_NH@Z
bool owners::Obj_5d840::FUN_0005d840(int v) {
    member = v;
    return true;
}

