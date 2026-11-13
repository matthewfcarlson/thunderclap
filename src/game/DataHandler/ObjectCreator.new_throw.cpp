// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000783a0..0x000788e0 (kind game, layer game, confidence medium), dominant class DataHandler::ObjectCreator
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f141e8b9 {
#define TREE_TU_END }
namespace fn_f141e8b9 {} using namespace fn_f141e8b9;
#include "game/DataHandler.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f141e8b9 {
class CHeliDeathSpiralTrack_783a0 {
public:
    bool FUN_00077df0(int); /* (unb4) as defined; address taken only */
    bool FUN_00077e00(int); /* (unb4) as defined; address taken only */
    char FUN_00077e10(int); /* (unb4) as defined; address taken only */
    char FUN_00077e20(float); /* (unb4) as defined; address taken only */
    char FUN_00077e40(float); /* (unb4) as defined; address taken only */
    bool FUN_00077e60(int); /* (unb4) as defined; address taken only */
    bool FUN_00077e70(int); /* (unb4) as defined; address taken only */
    char FUN_00077e80(float); /* (unb4) as defined; address taken only */
    char FUN_00077ea0(int); /* (unb4) as defined; address taken only */
    bool FUN_00077eb0(int); /* (unb4) as defined; address taken only */
    bool FUN_00077ec0(int); /* (unb4) as defined; address taken only */
};
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_f141e8b9
namespace fight {
template <class T>
class ParamFloatConstRange_783a0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_783a0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamIntConstRange_783a0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_783a0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_f141e8b9 {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);


// 0x000783a0 FUN_000783a0 (613 B): equivalent/0x000783a0.cpp
// sym: _FUN_000783a0 @0d84419de1eb @wb5a1d23397b5
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/24)
// FUN_000783a0 @ 0x000783a0
extern "C" void FUN_000783a0()
{
    if (DAT_004dd034 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("timeBegin", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077df0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("timeEnd", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e00);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("weightRatio", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("minTurningVelocity", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e20);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("maxTurningVelocity", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e40);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("acceleration", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e60);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("gravity", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e70);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("tilt", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077e80);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_783a0<CHeliDeathSpiralTrack_783a0>("priority", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077ea0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("blendInTime", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077eb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_783a0<CHeliDeathSpiralTrack_783a0>("blendOutTime", (void (CHeliDeathSpiralTrack_783a0::*)())&CHeliDeathSpiralTrack_783a0::FUN_00077ec0);
        FUN_002347b0(((ParamRegistry*)&DAT_004dd030), params, 11);
    }
    DAT_004dd034++;
}

} // namespace fn_f141e8b9
