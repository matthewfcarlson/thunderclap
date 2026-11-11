// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010de60..0x0010df90 (kind game, layer game, confidence high), dominant class hulkfight::ai::TokenSupressAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3421e5e {
#define TREE_TU_END }
namespace fn_f3421e5e {} using namespace fn_f3421e5e;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f3421e5e {
struct Param_10de60 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_10de60 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
struct Stats_10de70 {
    char pad0[0x18];
    float value;
};
struct Singleton_10de70 {
    char pad0[0x368];
    int f368;
    void FUN_000661f0();
};
void* __fastcall FUN_000592a0(void* p);
extern "C" void* __fastcall FUN_00059a30(void* p);
Singleton_10de70* FUN_000678d0();
struct Obj_10dee0 {
    char pad[0x14];
    u8 flag;
};
struct H {
    void f2_00059a30();
    H* f3();
    void f4_000661f0();
};
H* Fng_000678d0();

} // namespace fn_f3421e5e

// 0x0010de60 hulkfight::ai::TokenSupressTrack::vfunc_7 (7 B): matches/0x0010de60.cpp
// sym: ?vfunc_7@TokenSupressTrack@ai@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::ai::TokenSupressTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0010de70 hulkfight::ai::TokenSupressAction::vfunc_3 (104 B): equivalent/0x0010de70.cpp
// sym: ?vfunc_3@TokenSupressAction@ai@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// hulkfight::ai::TokenSupressAction::vfunc_3 @ 0x0010de70
bool hulkfight::ai::TokenSupressAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if ((*(void * *)&this->f_20) == 0)
        return false;
    FUN_00059a30(FUN_000592a0((*(void * *)&this->f_20)));
    this->f_24 = FUN_000678d0()->f368;
    if ((*(Stats_10de70 * *)&this->f_1c)->value >= 0.0f) {
        int bits = *(int*)&(*(Stats_10de70 * *)&this->f_1c)->value;
        FUN_000678d0()->f368 = bits;
    }
    FUN_000678d0()->FUN_000661f0();
    return true;
}


// 0x0010dee0 hulkfight::ai::TokenSupressAction::vfunc_5 (56 B): matches/0x0010dee0.cpp
// sym: ?vfunc_5@TokenSupressAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::TokenSupressAction::vfunc_5(hulk_intptr a, int b) {
    if (!(*(H * *)&this->f_20))
        return false;
    ((H *)((owners::Object_592a0 *)((*(H * *)&this->f_20)))->FUN_000592a0())->f2_00059a30();
    if ((*(Obj_10dee0 * *)&this->f_1c)->flag)
        Fng_000678d0()->f4_000661f0();
    return true;
}


// 0x0010df20 hulkfight::ai::TokenSupressAction::vfunc_4 (100 B): equivalent/0x0010df20.cpp [wrapped: conflict: FUN_000678d0]
// sym: ?vfunc_4@TokenSupressAction@fn_0010df20@@UAEXXZ
namespace fn_0010df20 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// hulkfight::ai::TokenSupressAction::vfunc_4 @ 0x0010df20
struct Ctx_10df20 {
    void *FUN_00059a30();
};

class Owner_10df20 {
public:
};

struct Player_10df20 {
    char pad0[0x368];
    int f368;
};

struct Tracker_10df20 {
    char pad0[0x18];
    float f18;
    char b1c;
    char b1d;
};

Player_10df20 *FUN_000678d0();

class TokenSupressAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad4[0x18];
    Tracker_10df20 *f1c;
    Owner_10df20 *f20;
    int f24;
};

void TokenSupressAction::vfunc_4()
{
    if (f20 != 0) {
        ((Ctx_10df20 *)((owners::Object_592a0 *)f20)->FUN_000592a0())->FUN_00059a30();
        if (f1c->f18 >= 0.0f && f1c->b1c == 0) {
            int v = f24;
            FUN_000678d0()->f368 = v;
        }
        if (f1c->b1d != 0) {
            ((owners::Target_65aa0 *)(FUN_000678d0()))->FUN_00065aa0();
        }
    }
}
} // namespace fn_0010df20

