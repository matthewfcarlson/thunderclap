// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ac610..0x000acda0 (kind game, layer game, confidence high), dominant class CScriptCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f42ec421 {
#define TREE_TU_END }
namespace fn_f42ec421 {} using namespace fn_f42ec421;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif
namespace fn_f42ec421 {
extern const float one;
extern const float pi;
extern const float halfpi;
extern const float half;
class Curve_ac6a0 {
  public:
    char p[16];
    float scale;
    char q[20];
    float cubic;
    float quad;
    float linear;
    float constant;
    hulk_freg Evaluate(float x);
};
class CScriptCamera_aca40 {
  public:
    char pad[0x2c0];
    float a;
    float b;
    float c;
    bool Check();
    bool Target(int arg);
};
extern void* CGameCamera_acd10_vftable[];
class CGameCamera_acd10 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CScriptCamera_acd10 : public CGameCamera_acd10 {
  public:
    CScriptCamera_acd10* vfunc_5(signed char flags);
};

} // namespace fn_f42ec421

// 0x000ac610 FUN_000ac610 (67 B): matches/0x000ac610.cpp
// sym: ?FUN_000ac610@Thing_ac610@owners@@QAEXXZ
void owners::Thing_ac610::FUN_000ac610() {
    copy1 = *(int*)&c;
    copy2 = *(int*)&a;
    out1 = (a + a) - (b + b) + d + c;
    out2 = (b * 3.0f - a * 3.0f) - (c + c) - d;
}

namespace fn_f42ec421 {

// 0x000ac6a0 FUN_000ac6a0 (78 B): matches/0x000ac6a0.cpp
// sym: ?Evaluate@Curve_ac6a0@fn_f42ec421@@QAEMM@Z
hulk_freg Curve_ac6a0::Evaluate(float x) {
    hulk_freg t = ((one - x) * pi + halfpi);
    t = (hulk_freg)(sin((double)t) + one) * half - x;
    t = t * scale + x;
    hulk_freg a = t * t;
    hulk_freg b = a * t;
    hulk_freg c = b * cubic;
    hulk_freg d = a * quad;
    hulk_freg e = t * linear;
    return c + d + e + constant;  // the listing's order (MSVC 7.1 reassociates; clang does not)
}

} // namespace fn_f42ec421

// 0x000ac780 FUN_000ac780 (14 B): matches/0x000ac780.cpp
// sym: ?FUN_000ac780@Target_ac780@owners@@QAEXH@Z
void owners::Target_ac780::FUN_000ac780(int x) {
    value = x;
    flag = 1;
}


// 0x000ac790 FUN_000ac790 (14 B): matches/0x000ac790.cpp
// sym: ?FUN_000ac790@Target_ac790@owners@@QAEXH@Z
void owners::Target_ac790::FUN_000ac790(int x) {
    value = x;
    flag = 1;
}


// 0x000ac7a0 FUN_000ac7a0 (45 B): matches/0x000ac7a0.cpp
// sym: ?FUN_000ac7a0@Thing_ac7a0@owners@@QAEXMM@Z
void owners::Thing_ac7a0::FUN_000ac7a0(float a, float b) {
    flag = 1;
    hulk_freg d = mB - mA;
    x = (one - a) * d;
    y = (one - b) * d;
}


// 0x000ac7d0 FUN_000ac7d0 (462 B): equivalent/0x000ac7d0.cpp [wrapped: conflict: CScriptCamera]
// sym: ??0CScriptCamera@fn_000ac7d0@@QAE@XZ
namespace fn_000ac7d0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000ac7d0 @ 0x000ac7d0

struct ResourceName_ac7d0 {
    int word;
    void FUN_0027b040(const char *name);
};

class CScriptCamera;

class __declspec(novtable) CGameCamera_ac7d0 {
public:
    virtual void v0();
    char pad04[4];
    ResourceName_ac7d0 name;      // 0x08
    char pad0c[0xd0 - 0xc];
    int mode;               // 0xd0
    char padd4[0x170 - 0xd4];
    CGameCamera_ac7d0 *FUN_000a9400();
    CGameCamera_ac7d0() { FUN_000a9400(); }
};


class CScriptCamera : public CGameCamera_ac7d0 {
public:
    virtual void v0();
    unsigned char f170;
    char pad171[0x3];
    int f174;
    int f178;
    float f17c;
    int f180;
    int f184;
    int f188;
    unsigned char f18c;
    char pad18d[0x3];
    int f190;
    int f194;
    char pad198[0x10];
    unsigned char f1a8;
    char pad1a9[0x3];
    int f1ac;
    int f1b0;
    float f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    unsigned char f1c4;
    char pad1c5[0x3];
    int f1c8;
    int f1cc;
    char pad1d0[0x10];
    unsigned char f1e0;
    char pad1e1[0x3];
    int f1e4;
    int f1e8;
    float f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    unsigned char f1fc;
    char pad1fd[0x3];
    int f200;
    int f204;
    char pad208[0x10];
    unsigned char f218;
    char pad219[0x3];
    int f21c;
    int f220;
    float f224;
    int f228;
    int f22c;
    int f230;
    unsigned char f234;
    char pad235[0x3];
    int f238;
    int f23c;
    char pad240[0x10];
    unsigned char f250;
    char pad251[0x3];
    int f254;
    int f258;
    float f25c;
    int f260;
    int f264;
    int f268;
    unsigned char f26c;
    char pad26d[0x3];
    int f270;
    int f274;
    char pad278[0x10];
    int f288;
    int f28c;
    int f290;
    int f294;
    int f298;
    int f29c;
    char pad2a0[0xc];
    unsigned char f2ac;
    char pad2ad[0x3];
    int f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    int f2c0;
    float f2c4;
    float f2c8;
    unsigned char f2cc;
    unsigned char f2cd;
    CScriptCamera();
};

CScriptCamera::CScriptCamera()
{
    f170 = 0;
    f174 = 0;
    f178 = 0;
    f17c = -1.0f;
    f180 = 0;
    f184 = 0;
    f188 = 0;
    f18c = 0;
    f190 = 0;
    f194 = 0;
    f1a8 = 0;
    f1ac = 0;
    f1b0 = 0;
    f1b4 = -1.0f;
    f1b8 = 0;
    f1bc = 0;
    f1c0 = 0;
    f1c4 = 0;
    f1c8 = 0;
    f1cc = 0;
    f1e0 = 0;
    f1e4 = 0;
    f1e8 = 0;
    f1ec = -1.0f;
    f1f0 = 0;
    f1f4 = 0;
    f1f8 = 0;
    f1fc = 0;
    f200 = 0;
    f204 = 0;
    f218 = 0;
    f21c = 0;
    f220 = 0;
    f224 = -1.0f;
    f228 = 0;
    f22c = 0;
    f230 = 0;
    f234 = 0;
    f238 = 0;
    f23c = 0;
    f250 = 0;
    f254 = 0;
    f258 = 0;
    f25c = -1.0f;
    f260 = 0;
    f264 = 0;
    f268 = 0;
    f26c = 0;
    f270 = 0;
    f274 = 0;
    f288 = 0;
    f28c = 0;
    f290 = 0;
    f294 = 0;
    f298 = 0;
    f29c = 0;
    f2ac = 0;
    f2b0 = 0;
    f2b4 = 3.0f;
    f2b8 = 0.25f;
    f2bc = 20.0f;
    f2c0 = 0;
    f2c4 = 1.5f;
    f2c8 = 3.0f;
    f2cc = 0;
    f2cd = 0;
    mode = 4;
    name.FUN_0027b040((*(const char**)&DAT_0049ee00));
}
} // namespace fn_000ac7d0

namespace fn_f42ec421 {

// 0x000ac9a0 CScriptCamera::vfunc_28 (1 B): matches/0x000ac9a0.cpp
// sym: ?FUN_000ac9a0@fn_f42ec421@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ac9a0() {}


// 0x000ac9b0 CScriptCamera::vfunc_29 (1 B): matches/0x000ac9b0.cpp
// sym: ?FUN_000ac9b0@fn_f42ec421@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ac9b0() {}

} // namespace fn_f42ec421

// 0x000ac9c0 FUN_000ac9c0 (73 B): matches/0x000ac9c0.cpp
// sym: ?FUN_000ac9c0@Obj_ac9c0@owners@@QAEXEEEEEE@Z
void owners::Obj_ac9c0::FUN_000ac9c0(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4, unsigned char p5,
            unsigned char p6) {
    v2ac = p2;
    v170 = p1;
    v1a8 = p3;
    v1e0 = p4;
    v2c0 = 0;
    v250 = p5;
    v218 = p6;
}


// 0x000aca10 CScriptCamera::vfunc_27 (33 B): matches/0x000aca10.cpp [wrapped: conflict: CScriptCamera]
// sym: ?vfunc_27@CScriptCamera@fn_000aca10@@QAE?AUVec@2@XZ
namespace fn_000aca10 {
struct Vec {
    int x, y, z;
};
class CScriptCamera {
  public:
    char pad[0x2a0];
    Vec pos;
    Vec vfunc_27();
};
Vec CScriptCamera::vfunc_27() {
    return pos;
}
} // namespace fn_000aca10

namespace fn_f42ec421 {

// 0x000aca40 FUN_000aca40 (84 B): matches/0x000aca40.cpp
// sym: ?Target@CScriptCamera_aca40@fn_f42ec421@@QAE_NH@Z
bool CScriptCamera_aca40::Target(int arg) {
    if (a >= c)
        return true;
    if (arg && b >= 0.0f && a > b && Check())
        return true;
    return false;
}

} // namespace fn_f42ec421

// 0x000acaa0 CScriptCamera::vfunc_31 (29 B): matches/0x000acaa0.cpp
// sym: ?vfunc_31@CScriptCamera@@UAEXH@Z
void CScriptCamera::vfunc_31(int __p0) { unsigned int x = (unsigned int)__p0;

    vfunc_7(0x3dcccccd);
    vfunc_9(0x453b8000);
}

namespace fn_f42ec421 {

// 0x000acd10 CScriptCamera::vfunc_2 (36 B): matches/0x000acd10.cpp
// sym: ?vfunc_5@CScriptCamera_acd10@fn_f42ec421@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CScriptCamera_acd10* CScriptCamera_acd10::vfunc_5(signed char flags) {
    *(void***)this = CGameCamera_acd10_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f42ec421
